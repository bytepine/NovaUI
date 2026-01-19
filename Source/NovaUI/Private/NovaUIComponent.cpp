// Copyright Byteyang Games, Inc. All Rights Reserved.


#include "NovaUIComponent.h"

#include "NovaUISubsystem.h"


// Sets default values for this component's properties
UNovaUIComponent::UNovaUIComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UNovaUIComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(GetOuter()))
	{
		if (PlayerController->IsLocalController())
		{
			if (UNovaUISubsystem* NovaUISubsystem = UNovaUISubsystem::Get(this))
			{
				NovaUISubsystem->BeginPlay(GetWorld()->GetFName(), PlayerController);
			}
		}
	}
}

void UNovaUIComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	if (const APlayerController* PlayerController = Cast<APlayerController>(GetOuter()))
	{
		if (PlayerController->IsLocalController())
		{
			if (UNovaUISubsystem* NovaUISubsystem = UNovaUISubsystem::Get(this))
			{
				NovaUISubsystem->EndPlay(GetWorld()->GetFName(), EndPlayReason);
			}
		}
	}
}

