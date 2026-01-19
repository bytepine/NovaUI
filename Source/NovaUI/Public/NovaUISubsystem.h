// Copyright Byteyang Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "NovaUISubsystem.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class NOVAUI_API UNovaUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	static UNovaUISubsystem* Get(const UObject* WorldContext);
	
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;
	
	void BeginPlay(const FName LevelName, APlayerController* PlayerController);
	
	void EndPlay(const FName LevelName, const EEndPlayReason::Type EndPlayReason);
	
	UFUNCTION(BlueprintCallable)
	void OpenUI(const FName UIName, APlayerController* PlayerController);
	
	UFUNCTION(BlueprintCallable)
	void CloseUI(const FName UIName);
	
	UFUNCTION(BlueprintCallable)
	void CloseAll();
	
	UFUNCTION(BlueprintPure)
	bool IsOpening(const FName UIName) const;
	
protected:
	UPROPERTY(BlueprintReadOnly)
	TArray<UDataTable*> UITableArray;
	
	UPROPERTY(Transient)
	TMap<FName, UUserWidget*> UIMap;
};
