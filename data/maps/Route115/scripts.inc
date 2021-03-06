Route115_MapScripts:: @ 81F2920
	map_script MAP_SCRIPT_ON_LOAD , Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad: @ 81F2930
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute115West
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition: @ 81F2947
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame: @ 81F2969
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman:: @ 81F2973
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro:: @ 81F297C
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign:: @ 81F2985
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy:: @ 81F298E
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchTimothy
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterTimothy:: @ 81F29BA
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
	@nop Trainer_TIMOTHY_1
	release
	end

Route115_EventScript_RematchTimothy:: @ 81F29D9
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Koichi:: @ 81F29F0
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob:: @ 81F2A07
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_RegisterNob
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchNob
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterNob:: @ 81F2A33
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
	@nop Trainer_NOB_1
	release
	end

Route115_EventScript_RematchNob:: @ 81F2A52
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Cyndy:: @ 81F2A69
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route115_EventScript_RematchCyndy
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterCyndy:: @ 81F2A95
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
	@nop Trainer_CYNDY_1
	release
	end

Route115_EventScript_RematchCyndy:: @ 81F2AB4
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Hector:: @ 81F2ACB
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra:: @ 81F2AE2
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden:: @ 81F2AF9
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix:: @ 81F2B10
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene:: @ 81F2B27
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene:: @ 81F2B3E
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear: @ 81F2B55
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild Pokémon will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro: @ 81F2BC9
	.string "Route 115\n"
	.string "{DOWN_ARROW} Rustboro City$"

Route115_Text_MeteorFallsSign: @ 81F2BE3
	.string "Meteor Falls\n"
	.string "Fallarbor Town through here$"
	
@==================================================================================================Devon Scene

r115_StartDevon::
	lock
	msgbox r115_ISeeThemThere
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, r115_toMsIto
	waitmovement OBJ_EVENT_ID_PLAYER
	goto R115_DevonScene

R115_DevonScene::
	lock
	applymovement 26, Common_Movement_FaceDown
	applymovement 25, Common_Movement_FaceDown
	waitmovement 25
	msgbox r115_IPresume
	closemessage
	savebgm 419
	fadenewbgm 419
	playse SE_PIN
	applymovement 26, Common_Movement_ExclamationMark
	waitmovement 26
	msgbox r115_WhatThe
	closemessage
	applymovement 25, Common_Movement_FaceRight
	waitmovement 25
	msgbox r115_DoYouKnow
	closemessage
	playse SE_PIN
	applymovement 25, Common_Movement_ExclamationMark
	waitmovement 25
	msgbox r115_HoldOn
	closemessage
	applymovement 26, Common_Movement_StepDown
	waitmovement 26
	applymovement 26, Common_Movement_FaceLeft
	waitmovement 26
	cleartrainerflag TRAINER_GRUNT_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	trainerbattle_single TRAINER_GRUNT_2, r115_GruntIntro, r115_LostAgain, r115_scenePart2

	
	
r115_scenePart2::
	msgbox r115_CaseClosed
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox r115_YourBestInterest
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox r115_BackThen
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox r115_HowMeetUp
	closemessage
	applymovement 25, Common_Movement_StepRight
	waitmovement 25
	applymovement 25, Common_Movement_FaceLeft
	waitmovement 25
	savebgm 375
	fadenewbgm 375
	msgbox r115_ITakeBreasOutHere
	closemessage
	applymovement 25, Common_Movement_FaceDown
	waitmovement 25
	msgbox r115_WasntExpecting
	closemessage
	applymovement 26, Common_Movement_FaceUp
	waitmovement 26
	msgbox r115_SomethingINeeded
	closemessage
	playse SE_PIN
	applymovement 25, Common_Movement_ExclamationMark
	waitmovement 25
	msgbox r115_Proposal1
	closemessage
	applymovement 26, r115_Kneel
	waitmovement 26
	msgbox r115_Proposal2
	playse SE_PIN
	applymovement 25, Common_Movement_ExclamationMark
	waitmovement 25
	msgbox r115_OfCourse
	closemessage
	applymovement 26, Common_Movement_FaceLeft
	waitmovement 26
	goto r115_scenePart3
	
	
r115_scenePart3::
	msgbox r115_itsAllGood
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox r115_ThatRemindsMe
	closemessage
	savebgm 432
	fadenewbgm 432
	applymovement 25, Common_Movement_QuestionMark
	waitmovement 25
	msgbox r115_stationedAtFrontDesk
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox r115_FiguredSomethingOut
	closemessage
	setvar VAR_RYU_DEVON_MAIN_QUEST_VAR, 22
	setflag FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE
	setflag FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE2
	clearflag FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE3
	setflag FLAG_RYU_DEVON_CORPORATE_HIDE_MSITO
	clearflag FLAG_RYU_DEVON_CORPORATE_HIDE_MRSTONE4
	fadescreen 1
	warpsilent MAP_RUSTBORO_CITY_DEVON_CORP_3F, 255, 13, 5
	release
	end
	
r115_IPresume:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Ms. Ito, I presume?\p{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Ms. Ito: Yes, who might you be?$"

r115_WhatThe:
	.string "What the-! You!$"

r115_DoYouKnow:
	.string "Ms. Ito: Do you know this person?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}We've been acquainted with one\n"
	.string "another, yes...since I recovered\l"
	.string "the package he stole.$"

r115_HoldOn:
	.string "Ms. Ito: Hold on a sec, that's not-$"
	
r115_GruntIntro:
	.string "Grunt: I got into trouble for\n"
	.string "failing that mission, ya know! Now\l"
	.string "it's payback time!$"

r115_LostAgain:
	.string "Tch, lost again...$"

r115_CaseClosed:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}And that's a case...closed.$"

r115_YourBestInterest:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Ms. Ito, I feel that it's in your\n"
	.string "best interests to come clean.\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Listen, I haven't the faintest\n"
	.string "idea what you're talking about,\l"
	.string "but you've got it all wrong.\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Do I? Information has been leaking\n"
	.string "out of Devon Corporation, and it's\p"
	.string "suspected that the source is from\n"
	.string "within...\p"
	.string "Coupled with the fact that you've\n"
	.string "been M.I.A. for over an hour now, \p"
	.string "and is found actively associating\n"
	.string "with an Aqua member, the very same\l"
	.string "one who stole the Devon Goods...\p"
	.string "Face facts, Ms. Ito...no matter\n"
	.string "how you slice it, this setup is\l"
	.string "very unbecoming of you.\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Grunt: Leave her out of this.$"

r115_BackThen:
	.string "What I did back then was just an\n"
	.string "assignment from Boss, nothing more\p"
	.string "and nothing less. We didn't even\n"
	.string "know each other until that day,\p"
	.string "much less be able to communicate\n"
	.string "with each other. I hadn't set foot\l"
	.string "in Rustboro since!$"

r115_HowMeetUp:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Then, how did you two meet up?$"

r115_ITakeBreasOutHere:
	.string "I usually take my breaks out here,\n"
	.string " away from city life, and just\p"
	.string "stare at the ocean. One day, he\n"
	.string "approached me, noticing how\l"
	.string "frustrated I was at that time.\p"
	.string "Granted, I was afraid at first\n"
	.string "but as we began talking and\p"
	.string "venting, we opened up to each\n"
	.string "other. And ever since then, we've\p"
	.string "promised to meet right here. It's\n"
	.string "through faith and trust in each\p"
	.string "other that we continue to meet\n"
	.string "like this.$"

r115_WasntExpecting:
	.string "Although, I really wasn't\n"
	.string "expecting to see you within the\l"
	.string "city, considering...$"

r115_SomethingINeeded:
	.string "Grunt: Yeah... there's something I\n"
	.string "needed to get before we met up...\p"
	.string "and come to think of it, I guess\n"
	.string "this is as good a time as any...\p"
	.string "... ... ...$"

r115_Proposal1:
	.string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(The Aqua Grunt pulls from his\n"
	.string " pocket a small, decorative box,\p"
	.string " opening it, and kneeling in front\n"
	.string " of her.)$"
	
r115_Proposal2:
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Will you, uh...marry me?$"

r115_OfCourse:
	.string "Of course I will!\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Congratulations to you both!\p"
	.string "And I apologize for misjudging the\n"
	.string "situation...plus I feel like I\l"
	.string "ruined the moment.$"

r115_itsAllGood:
	.string "It's all good. She said yes,\n"
	.string "nothing else matters now.\p"
	.string "Ms. Ito: I surely\n"
	.string "wasn't expecting any of this to\p"
	.string "happen!$"

r115_ThatRemindsMe:
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}That reminds me! Ms. Ito, the\n"
	.string "other employees are having a hard\p"
	.string "time dealing with the news media\n"
	.string "entering in. I came to find you.$"

r115_stationedAtFrontDesk:
	.string "Really? Wasn't there anyone\n"
	.string "stationed at the Front Desk?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Not that I saw, no...\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}That's not right...someone was\n"
	.string "scheduled to take my post.\n"
	.string "I always made sure that was so\l"
	.string "before I left.\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}Is that so?\p"
	.string " (Interesting...and it's been\n"
	.string " nearly half-an-hour since, so 30\l"
	.string " minutes gap...)$"

r115_FiguredSomethingOut:
	.string "Figured something out?\p"
	.string "{COLOR LIGHT_BLUE}{SHADOW BLUE}A question for you, Mr. Aqua...\p"
	.string "When you went to steal the Goods,\n"
	.string "how'd you make it out of there so\l"
	.string "fast?\p"
	.string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}Heh, it was a stroke of luck to be\n"
	.string "honest. I was certain I'd be up\p"
	.string "against some form of resistance\n"
	.string "once I went in, but surprisingly\l"
	.string "enough, it was a swift job.\p"
	.string "To think, it was just sitting\n"
	.string "there on the desk just waiting to\l"
	.string "be snatched up...\p"
	.string " {COLOR LIGHT_BLUE}{SHADOW BLUE}(Hmm...if it really was that quick\n"
	.string " a job, then...)\p"
	.string "Alright then, I think I get the\n"
	.string "picture. Thanks.\p"
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}(Time to head back to Devon.)$"
	
r115_ISeeThemThere:
	.string " {COLOR LIGHT_BLUE}{SHADOW BLUE}(I see them over there at \n the beach.)$"

r115_Kneel:
	walk_in_place_slow_up
	step_end
	
r115_toMsIto:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


@end devon scene
	
r115_DevPhase::
	applymovement OBJ_EVENT_ID_PLAYER, r115_StepLeft
	release
	end
	
r115_StepLeft:
	walk_left
	walk_left
	step_end


R115_Raikou::
	goto_if_set FLAG_RYU_RAIKOU, RyuLegendary_Stoneisdull
	msgbox R115_Raikou_TouchQuery, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_ne RyuLegendary_LeftStoneAlone
	msgbox R115_Raikou_TouchedStone
	playmoncry SPECIES_RAIKOU, 0
	closemessage
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	waitmoncry
	setwildbattle SPECIES_RAIKOU, VAR_RESULT, ITEM_ELECTRIC_SEED
	special BattleSetup_StartLegendaryBattle
	waitstate
	call RyuLegendary_CheckCaught
	setflag FLAG_RYU_RAIKOU
	release
	end

R115_Raikou_TouchedStone:
	.string "{PLAYER} touched the stone.\p"
	.string "A thunderous cry is heard...$"

R115_Raikou_TouchQuery:
	.string "This stone looks funny.\p"
	.string "Small electric bolts are coursing\n"
	.string "all over it.$"
