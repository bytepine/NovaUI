// Copyright Byteyang Games, Inc. All Rights Reserved.


#include "NovaUISubsystem.h"

#include "NovaUIDefine.h"
#include "NovaUIInterface.h"
#include "NovaUISettings.h"
#include "NovaUITable.h"
#include "Blueprint/UserWidget.h"

UNovaUISubsystem* UNovaUISubsystem::Get(const UObject* WorldContext)
{
	if (IsValid(WorldContext))
	{
		return WorldContext->GetWorld()->GetGameInstance()->GetSubsystem<UNovaUISubsystem>();
	}
	return nullptr;
}

void UNovaUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (const UNovaUISettings* Settings = UNovaUISettings::Get())
	{
		for (const FSoftObjectPath& UITable : Settings->UITableArray)
		{
			UDataTable* DataTable = Cast<UDataTable>(UITable.TryLoad());
			UITableArray.Add(DataTable);
		}
	}
}

void UNovaUISubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UNovaUISubsystem::BeginPlay(const FName LevelName, APlayerController* PlayerController)
{
	OpenUI(LevelName, PlayerController);
}

void UNovaUISubsystem::EndPlay(const FName LevelName, const EEndPlayReason::Type EndPlayReason)
{
	CloseAll();
}

void UNovaUISubsystem::OpenUI(const FName UIName, APlayerController* PlayerController)
{
	if (IsOpening(UIName))
	{
		if (UUserWidget* UserWidget = UIMap[UIName])
		{
			if (INovaUIInterface* Interface = Cast<INovaUIInterface>(UserWidget))
			{
				Interface->OnUpdate();
			}
		}
	}
	else
	{
		const FNovaUITableRow* Row = nullptr;
		for (const UDataTable* DataTable : UITableArray)
		{
			const FString Context;
			Row = DataTable->FindRow<FNovaUITableRow>(UIName, Context);
			if (Row) break;
		}

		if (Row)
		{
			if (UClass* Class = Row->UIClass.LoadSynchronous())
			{
				UUserWidget* UserWidget = CreateWidget(PlayerController, Class);
				if (INovaUIInterface* Interface = Cast<INovaUIInterface>(UserWidget))
				{
					Interface->OnOpen();
				}
				UserWidget->AddToPlayerScreen(Row->ZOrder);
				UIMap.Add(UIName, UserWidget);
			}
		}
	}
}

void UNovaUISubsystem::CloseUI(const FName UIName)
{
	if (UIMap.Contains(UIName))
	{
		if (UUserWidget* UserWidget = UIMap[UIName])
		{
			if (INovaUIInterface* Interface = Cast<INovaUIInterface>(UserWidget))
			{
				Interface->OnUpdate();
			}
			UserWidget->RemoveFromParent();
		}
		UIMap.Remove(UIName);
	}
}

void UNovaUISubsystem::CloseAll()
{
	for (const TTuple<FName, UUserWidget*>& Tuple : UIMap)
	{
		CloseUI(Tuple.Key);
	}
}

bool UNovaUISubsystem::IsOpening(const FName UIName) const
{
	return UIMap.Contains(UIName);
}