AbandonedShip_Deck_MapScripts:: @ 823799A
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_Deck_OnTransition
	.byte 0

AbandonedShip_Deck_OnTransition: @ 82379A0
	setflag FLAG_LANDMARK_ABANDONED_SHIP
	end
	
AS_CheckLana::
	lock
	goto_if_unset FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER, ryu_end
	clearflag FLAG_HIDE_ABN_SHIP_LANA
	setvar VAR_RYU_DS_LANA_STAGE, 21
	release
	end
	
AS_Dev_skip::
	lock
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_ne ryu_end
	setflag FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_4_SCANNER
	release
	end

