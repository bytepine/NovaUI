// Copyright Byteyang Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "NovaUISettings.generated.h"

UCLASS(Config=NovaUI, DefaultConfig, meta=(DisplayName="NovaUI"))
class UNovaUISettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	static const UNovaUISettings* Get() { return GetDefault<UNovaUISettings>(); }
	
	virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
	
	UPROPERTY(Config, EditDefaultsOnly, meta = (AllowedClasses="/Script/Engine.DataTable", RequiredAssetDataTags="RowStructure=/Script/NovaUI.NovaUITableRow"))
	TArray<FSoftObjectPath> UITableArray;
};