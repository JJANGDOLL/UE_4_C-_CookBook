// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UE_CPP_SandboxEditorTarget : TargetRules
{
	public UE_CPP_SandboxEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "UE_CPP_Sandbox" } );
	}
}
