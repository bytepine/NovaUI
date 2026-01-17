// Copyright Byteyang Games, Inc. All Rights Reserved.


#include "NovaUISubsystem.h"

#include "NovaUIDefine.h"

void UNovaUISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	UE_LOG(LogNovaUI, Log, TEXT("UNovaUISubsystem::Initialize"));
	
	FWorldDelegates::OnPostWorldInitialization.AddUObject(this, &UNovaUISubsystem::OnPostWorldInitialization);
}

void UNovaUISubsystem::Deinitialize()
{
	Super::Deinitialize();
	
	UE_LOG(LogNovaUI, Log, TEXT("UNovaUISubsystem::Deinitialize"));
}

void UNovaUISubsystem::OnPostWorldInitialization(UWorld* World, const UWorld::InitializationValues IVS)
{
	UE_LOG(LogNovaUI, Log, TEXT("UNovaSubsystem::OnPostWorldInitialization: %s"), *World->GetName());
}
