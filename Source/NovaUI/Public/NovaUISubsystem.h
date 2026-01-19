// Copyright Byteyang Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "NovaUISubsystem.generated.h"

/**
 * 
 */
UCLASS()
class NOVAUI_API UNovaUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize() override;

private:
	void OnPostWorldInitialization(UWorld *World, const UWorld::InitializationValues IVS);
};
