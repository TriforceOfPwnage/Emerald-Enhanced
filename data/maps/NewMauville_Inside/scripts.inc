NewMauville_Inside_MapScripts:: @ 82373D7
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD , NewMauville_Inside_OnLoad
	.byte 0

NewMauville_Inside_OnResume: @ 82373E7
	compare VAR_TEMP_1, 1
	call_if_eq NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	compare VAR_TEMP_2, 1
	call_if_eq NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveVoltorb
	end

NMV_Ampharosite::
	finditem ITEM_AMPHAROSITE
	setflag FLAG_ITEM_BALL_AMPHAROSITE
	removeobject 11
	release
	end

NewMauville_Inside_EventScript_TryRemoveVoltorb:: @ 8237407
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NewMauville_Inside_OnTransition: @ 823741B
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	call_if_unset FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb1
	call_if_unset FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb2
	call_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb3
	end

NewMauville_Inside_EventScript_ShowVoltorb1:: @ 8237441
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1
	return

NewMauville_Inside_EventScript_ShowVoltorb2:: @ 8237445
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2
	return

NewMauville_Inside_EventScript_ShowVoltorb3:: @ 8237449
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3
	return

NewMauville_Inside_OnLoad: @ 823744D
	compare VAR_NEW_MAUVILLE_STATE, 2
	call_if_eq NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	end

NewMauville_Inside_EventScript_BlueButton:: @ 8237459
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_GreenButton:: @ 8237471
	lockall
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_SetBarrierStateBlueButton:: @ 8237489
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, 1
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, 1
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, 1
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, 1
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, 1
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, 1
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, 1
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, 1
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, 1
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, 1
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, 1
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, 1
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, 1
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, 1
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, 1
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, 1
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, 0
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, 0
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, 0
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, 0
	return

NewMauville_Inside_EventScript_SetBarrierStateGreenButton:: @ 82375D7
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, 1
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, 1
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, 1
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, 1
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, 1
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, 1
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, 1
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, 1
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, 1
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, 1
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, 1
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, 1
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, 0
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, 0
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, 0
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, 0
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, 0
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, 0
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, 0
	return

NewMauville_Inside_EventScript_RedButton:: @ 8237725
	lockall
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	setvar VAR_NEW_MAUVILLE_STATE, 2
	compare VAR_RYU_DS_LANA_STAGE, 17
	call_if_eq NM_Leaf_Event
	releaseall
	end

NewMauville_Inside_EventScript_SetGeneratorOffMetatiles:: @ 823773A
	setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, 0
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, 1
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, 1
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, 1
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, 1
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, 1
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, 1
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, 1
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, 1
	special DrawWholeMapView
	return

NewMauville_Inside_EventScript_Generator:: @ 823778F
	lockall
	compare VAR_NEW_MAUVILLE_STATE, 2
	goto_if_eq NewMauville_Inside_EventScript_GeneratorOff
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_GeneratorOff:: @ 82377A5
	msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_Voltorb1:: @ 82377AF
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25, ITEM_NONE
	waitse
	playmoncry SPECIES_VOLTORB, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb1
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb1:: @ 82377F3
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb2:: @ 82377FC
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25, ITEM_NONE
	waitse
	playmoncry SPECIES_VOLTORB, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb2
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb2:: @ 8237840
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb3:: @ 8237849
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25, ITEM_NONE
	waitse
	playmoncry SPECIES_VOLTORB, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NewMauville_Inside_EventScript_DefeatedVoltorb3
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb3:: @ 823788D
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_Text_GeneratorRadiatingHeat: @ 8237896
	.string "The generator is radiating heat that\n"
	.string "can be felt even at a distance.\p"
	.string "It looks like it should be turned off\n"
	.string "as soon as possible.$"

NewMauville_Inside_Text_GeneratorQuietedDown: @ 8237916
	.string "The generator quieted down.$"

NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped: @ 8237932
	.string "{PLAYER} stepped on the switch.\p"
	.string "Click…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "The generator appears to have\n"
	.string "stopped…$"
	
@==================================================================================================LANA EVENTS

NM_SpecCheck::
	lock
	addobject 10
	release
	end

NM_DevShortcut::
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	warpsilent MAP_NEW_MAUVILLE_INSIDE, 255, 21, 4
	release
	end

NM_DevUp:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

NM_Leaf_Trigger::
	lock
	compare VAR_RYU_DS_LANA_STAGE, 15
	goto_if_ne ryu_end
	clearflag FLAG_HIDE_NM_LANA
	setvar VAR_RYU_DS_LANA_STAGE, 17
	release
	end

NM_Leaf_Event_PostWattson::
	goto_if_set FLAG_GOT_TM24_FROM_WATTSON, NM_Leaf_Event
	msgbox lanadoesntlookatyou
	release
	end
	
NM_Leaf_Event::
	lock
	drawheadshot HEAD_LANA
	msgbox NM_LanaElipsis MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	fadescreen 1
	playse SE_TK_WARPOUT
	waitse
	removeobject 10
	fadescreen 0
	msgbox NM_LanaLeft MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	msgbox NM_ScavengerHuntClue MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox NM_ScavengerHuntClue2 MSGBOX_DEFAULT
	setflag FLAG_HIDE_NM_LANA
	setvar VAR_RYU_DS_LANA_STAGE, 20
	return
	
NM_LeafNoGenerator:
    faceplayer
	msgbox NM_LanaElipsis2 MSGBOX_DEFAULT
	closemessage
	removecutscenesprites
	release
	end

lanadoesntlookatyou:
	.string "Lana is staring inquisitively\nat the generator.$"
	
NM_LanaElipsis:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lana: ... ... ... ... ... ...\p{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Lana used an Escape Rope!$"
	
NM_LanaElipsis2:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lana: ... ... ... ... ... ...$"
	
NM_LanaLeft:
	.string "Not even a word...$"
	
NM_ScavengerHuntClue:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(A note seems to have been left\n behind...)\p {COLOR DARK_GREY}{SHADOW LIGHT_GREY}(This vessel of the sea was\n originally called the S.S. Cactus,\p used to carry both passengers and\n"
	.string " cargo when it was in operation.)$"
	
NM_ScavengerHuntClue2:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(There seems to be something else\nwritten on the note...)\p{COLOR LIGHT_RED}{SHADOW RED}Why...this place is clearly\ndifferent, and yet...feels the\lsame...I can get through this...\lI need to...$"
	
NM_Warp1::
	lock
	warpteleport MAP_NEW_MAUVILLE_INSIDE, 255, 43, 38
	release
	end
	
NM_Warp2::
	lock
	warpteleport MAP_NEW_MAUVILLE_INSIDE, 255, 39, 5
	release
	end


@==================================================================================================End Lana Events

NewMauville_Zapdos::
	goto_if_set FLAG_RYU_ZAPDOS, RyuLegendary_Stoneisdull
	msgbox NewMauville_Zapdos_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox NewMauville_Zapdos_TouchedStone
	playmoncry SPECIES_ZAPDOS, 0
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	closemessage
	waitmoncry
	setwildbattle SPECIES_ZAPDOS, VAR_RESULT, ITEM_SHARP_BEAK
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_ZAPDOS
	release
	end

NewMauville_Zapdos_TouchedStone:
	.string "{PLAYER} touched the stone.\p"
	.string "{COLOR RED}OUCH! {COLOR DARK_GREY}{PLAYER} got shocked!$"

NewMauville_Zapdos_TouchQuery:
	.string "This stone looks funny, as if\n"
	.string "it was charged up!\p"
	.string "Touch the stone?$"
