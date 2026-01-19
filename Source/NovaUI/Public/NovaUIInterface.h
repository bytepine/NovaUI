// Copyright Byteyang Games, Inc. All Rights Reserved.

#pragma once

#include "UObject/Interface.h"
#include "NovaUISubsystem.h"
#include "NovaUIInterface.generated.h"

UINTERFACE()
class NOVAUI_API UNovaUIInterface : public UInterface
{
	GENERATED_BODY()

};

class NOVAUI_API INovaUIInterface
{
	GENERATED_BODY()
	
protected:
	friend UNovaUISubsystem;
	
	UFUNCTION(BlueprintNativeEvent)
	void OnOpen();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnUpdate();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnClose();
};