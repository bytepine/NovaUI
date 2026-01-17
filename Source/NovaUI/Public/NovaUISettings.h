// Copyright Byteyang Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Developersettings.h"
#include "NovaUISettings.generated.h"

UCLASS(config = NovaUI, defaultconfig, meta=(DisplayName="NovaUI"))
class UNovaUISettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	virtual FName GetCategoryName() const override { return TEXT("Plugins"); }
	
	UPROPERTY(EditDefaultsOnly, meta = (RequiredAssetDataTags="RowStructure=FNovaUITableRow"))
	UDataTable* UITable;
	
	UPROPERTY(EditDefaultsOnly, meta = (RequiredAssetDataTags="RowStructure=FNovaUIDefaultTableRow"))
	UDataTable* DefaultUITable;
};