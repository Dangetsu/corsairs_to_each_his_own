// ������ ������� - ���������� �������
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if (CheckAttribute(pchar, "questTemp.HWIC.Eng"))
			{
				if (pchar.questTemp.HWIC.Eng == "Start_main")
				{
					dialog.text = "������������, �������. �� ��������� �������� �� ��� ������� ��� - � � �������, ������, ����� ������ �� ����. ��������� ������������� - ������� ������ �������.";
					link.l1 = "������ ����. � � - ������� " + GetFullName(pchar) + ".";
					link.l1.go = "First_Task";
					break;
				}
				if (pchar.questTemp.HWIC.Eng == "GotoPortoffice")
				{
					if (sti(Pchar.Ship.Type) != SHIP_NOTUSED)
					{
						dialog.text = "� �������� ��� ����� ���� ������� �� ��������. ��� �� ��������?";
						link.l1 = "��-��, � �����, ��� ���.";
						link.l1.go = "exit";
					}
					else
					{
						dialog.text = "����, ��� �� ����� �����. ���������� ������������ '����������' - ��� ������� ��� ������������� ��� ���� - � ������������� � ���������. �������� ���� �������� � ���� ������ ��� � ���������� �����, � ������� �� � ���� ��������. ����� ������ ������ � ����� ����� �������. �� ������� ����� � �� ���������� ������� - ����� �� ���������� ������� � �������� �� ��������\n��� ������� �� ������ ����������� ����� ��������� � �������� � ����-�����, � ����� ����� ������� ������ ������ - ������ ����� �� ������ �������� �������������� ������������ � ����� ������ ����������. � ������ - �� ����������. �����, �������.";
						link.l1 = "�������! ���� ����������� �������� ������ �����.";
						link.l1.go = "First_Task_3";
					}
					break;
				}
				if (pchar.questTemp.HWIC.Eng == "MirageTake")//� ��� ������ ���������� ������� ��������
				{
					pchar.quest.ToAntiguaMirageOver.over = "yes"; //����� ������
					int iMir = 0;
					int iVal = 0;
					for(i = 0; i < COMPANION_MAX; i++)
					{
						iTemp = GetCompanionIndex(PChar, i);
						if(iTemp > 0)
						{
							sld = GetCharacter(iTemp);
							pchar.questTemp.HWIC.Eng.CompanionIndex = sld.Index;
							if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_MIRAGE)
							{
							iMir = 1;
							RealShips[sti(sld.Ship.Type)].ship.upgrades.hull = 1;//������ ������
							SetShipSailsFromFile(sld, "ships/parus_silk.tga");
							SetSailsColor(sld, 0);//����� ��������� �����
							DeleteAttribute(sld, "ship.sails");//�������� ������
							DeleteAttribute(sld, "ship.masts");//������� �����
							}
							if(sti(RealShips[sti(sld.ship.type)].basetype) == SHIP_VALCIRIA) iVal = 1;
						}
					}//���������� ������� ������� �������� � �������.
					if (iMir == 1 && iVal == 0)//�������� ���������
					{
						dialog.text = "��� �� � ���������, �������... � ��� ��� ���� � ����� �����������.";
						link.l1 = "��� ���? ����� ��� �������� ��������, ���...";
						link.l1.go = "Fleetwood_lostVal";
						break;
					}
					if (iMir == 0 && iVal == 1)//�������� �����
					{
						dialog.text = "��� �� � ���������, �������... � ��� ��� ���� � ����� �����������.";
						link.l1 = "��� ���? ����� ��� �������� ��������, ���...";
						link.l1.go = "Fleetwood_lostMir";
						break;
					}
					if (iMir == 0 && iVal == 0)//� ��� ������ �����
					{
						dialog.text = "��� �� � ���������, �������... � ��� ��� ���� � ����� �����������.";
						link.l1 = "��� ���? ����� ��� �������� ��������, ���...";
						link.l1.go = "Fleetwood_lostFull";
						break;
					}
					dialog.text = "��� �� � ���������, �������... � ��� ��� ���� � ����� �����������.";
					link.l1 = "��� ���? ����� ��� �������� ��������, ���...";
					link.l1.go = "Fleetwood_complete";
					break;
				}
				if (pchar.questTemp.HWIC.Eng == "toAntigua")
				{
					dialog.text = "������������, ��� ����! ��� ��� ������! �������� � ��� �� �������?";
					link.l1 = "� ���������, ���, ������. ��� ���������� ����������� �� ����, �������� ��� ���, ��� �� ������ ����� ������ ������ ��� �� ����, ����������� ��� ����������. � ������ ������ ��� �������� - ��������� ������ �������� - � ���������� �� ������ �������...";
					link.l1.go = "Fleetwood_LastTask";
					break;
				}
				dialog.text = "� ��� ��� �����-�� �������, �������?";
				link.l1 = "���. � ��� �����.";
				link.l1.go = "exit";		
				NextDiag.TempNode = "First time";
			}
			dialog.text = "� ��� ��� �����-�� �������, �������?";
			link.l1 = "���. � ��� �����.";
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Fleetwood_abordage":
			PlaySound("VOICE\Russian\hambit\Richard Flitwood-03.wav");
			dialog.text = "��������� �����! �� ������� ������ � ���������� �������, �� � ��� ����� ������� ���� ����. � ������� ����� � �����-������, � �������� ����� ������� �� ���� �������, ��� ��� ����� ������� �� ������, ��������� � ����� � ���� '�������'. ���� ������ �� �������� ������ ���������� �������. � ���� � ������!";
			link.l1 = "�� ����� ���� �� ����������, �������. ������� �� ������� ��� ��� - � ����������� �� ���� ������ ����. � ����� ��� ��, � ������� ���� �������� �������� ���������. �� �������� ���� - ���� ��� ������ ������ ���� � ������ �� ����� �������� �������!";
			link.l1.go = "Fleetwood_abordage_1";
		break;
		
		case "Fleetwood_abordage_1":
			LAi_SetCurHPMax(NPChar);
			LAi_GetCharacterMaxEnergy(NPChar);			
			QuestAboardCabinDialogExitWithBattle("PrepareToBoom"); 
			DialogExit();	
			AddDialogExitQuest("MainHeroFightModeOn");
			pchar.questTemp.HWIC.Holl = "FleetwoodCapture";
			pchar.GenQuest.Detonation = true; // patch-4
		break;
		
		case "First_Task":
			dialog.text = "����� ��� � ��� ���������. � ��� � ����� ������� � ��������� ���������� ��������� ��������. � ��� ������� � ���� - ����� �������� �������� ����� ������. ������ � �� ����� ���������� � ���� �� ����� ����� ������ ����, ������� � ���� �������� ������ ���.";
			link.l1 = "������ ��� �����������, ������ �������.";
			link.l1.go = "First_Task_1";			
		break;
		
		case "First_Task_1":
			dialog.text = "�� ���������� ������������ �����. �� ������ ���� �� ����������� �������-�������, '������� ���������', �� � ������, ��� �� ���� � ���������, �� ����� �� �������. � ���� ��� ��������� ��������, ��� ��� ������ ����-��������� ����������� ����-������� �������� ������ ����������\n��������� �������� ������ ������ ��������� �������� ����� - ���� '�������-�������' ���������� ������ ���������� �������, ������ ��� ���������� ������, � ������� �����. �������� ����� �������� ���� ������� �� ����������, �� ��� ������������ �������� �����, ������� � ����������� ����� �������� ������\n� ����� ���� ����� �� ���� �������-�������, �� ��� ��� ����� ��������� ����������� - ��������� ����� ������ ������� �����, � ��� ����� ������������ � ����������. �� �� ��� ��� ������ �����, ���� ������� ������ ���� '���������', � � �� ��� ������� ���\n�� ��� ���������� ����� ������ � �������� ��������������, ����� ��� ������� ���������, � �������� ��������� �� ���� ������ ���������� ������. ��� ��� �� �������� ��� �����, �������?";
			link.l1 = "�� �����. � ����� ������ ��� � �������� � ����������� ����� ��������. ���� �� ��� ����������� ��� ����������?";
			link.l1.go = "First_Task_2";	
		break;
		
		case "First_Task_2":
			dialog.text = "�� ���������� �����. ������ �������� � ������������ ����. ��� ���� ���������� �����, ��� � ��� ������, � ���� �������, '���������', ������. ������ �� ��������� ����������� ���� ���������. �� ������ ����� �����, ������� � �������� � ���� ����, ���� � ���� ������� ����� ������ � ����������� ��� �������� �����\n����� �������, ������������ ���������, �� ������ ������� �� ��������, � ���������, � ���������� � ���� �����: � ������ � ��� ����� ������, � � �������� - �����, � ��� �� ��������� �� ��� �� ����. � �����, ������� ���� ������� � ����������, �� �������� ����������\n���������� � ����� �������� �������� ���������� ������ ��������� ������ �� ����������, ��� � ��� �������, �� ��� �� ����... ��� ����������� ��������� ��� - ������� �� �������� ����� � ���������� ������������, ���� � ��������� ��� ����� �� ������� ������. ��� ���������� ������� �� ������� ������������ '����������', � ���� ������� ��������� �������� � �����������\n�� ������ �� ������ ����� ��� ���� ������� �� ������� � �������� ����������. � ����������� � ����������� ����� - ������� ��� ������ �������� ����� ������ ����� 10 000 ����\n��� ������ ������� - ������������� �� ���, � ����� ����������� ������������ � '���������' �������� ��� ���� ������. ��, �������, �� �������� ����� ���� ���� �� ������ ����������� �������� � ������ ����� �� ������� - ������ ����� � ������.";
			link.l1 = "� ��� �����, ������ �������. ����������� � �������� ����������.";
			link.l1.go = "exit";	
			pchar.questTemp.HWIC.Eng = "GotoPortoffice";
			bDisableFastReload = false;//������� ������� �������
			DeleteAttribute(pchar, "questTemp.HWIC.CanTake");//���� �������� ����� ����������
		break;
		
		case "First_Task_3":
			DialogExit();
			pchar.questTemp.HWIC.TakeQuestShip = "true";//��� �� ���������� ��� ������� �� ����, ����� ������� ������ �������
			pchar.questTemp.HWIC.EngEquip = "true"; //����� ������
			pchar.questTemp.HWIC.Eng = "GotoBridgetown";
			GetValckiriaToCharacter(pchar);
			pchar.quest.Knippel_Officer.win_condition.l1 = "location";
			pchar.quest.Knippel_Officer.win_condition.l1.location = "SentJons_houseSP3";
			pchar.quest.Knippel_Officer.function = "KnippelToOfficer";
			pchar.questTemp.HWIC.Eng.BridgeCounter = 0;//������� ��������� ������� ���������� �� ������
			AddQuestRecord("Holl_Gambit", "2-5");
		break;
		
		//������� �������
		case "Fleetwood_lostMir":
			dialog.text = "��, ��� ��������, ��� �� ��������� ����, �� ����� ��������� ��������� �����. ���� ��� ���� ����� ������. '���������' � � ��� �������. � ������ ������ ����. ����� ���� ������ ��� �� �����.";
			link.l1 = "��� ����� ����, ��� ��� ����������. ����� �������, ������ �������.";
			link.l1.go = "Fleetwood_RemoveShip";
			pchar.questTemp.HWIC.Eng.ShipType = SHIP_VALCIRIA;
		break;
		
		case "Fleetwood_lostVal":
			dialog.text = "��, ��� ��������, ��� �� �������� '���������'. ��� ���� ���������� �����������... � ������ � ��� ����������� ��������� �������. � ������ ������ ����. ����� ���� ������ ��� �� �����.";
			link.l1 = "��� ����� ����, ��� ��� ����������. ����� �������, ������ �������.";
			link.l1.go = "Fleetwood_RemoveShip";
			pchar.questTemp.HWIC.Eng.ShipType = SHIP_MIRAGE;
		break;
		
		case "Fleetwood_lostFull":
			dialog.text = "��, ��� ��������, ��� �� ���������� ������� � �������. �� �� ������� � ���� ��������� �����, �� ��� � '���������' ��������. � � ��� ������� �����������. ���������� ����� � ���� ����!";
			link.l1 = "��� ����� ����, ��� ��� ����������. ��������, ������ �������.";
			link.l1.go = "exit";
			Pchar.questTemp.FiringOfficerIDX = GetCharacterIndex("Knippel");
			AddDialogExitQuestFunction("LandEnc_OfficerFired");//�������� �� ��������
			sld = characterFromId("Knippel");
			ChangeCharacterAddressGroup(sld, "SentJons_houseH1", "goto", "goto1");//�������� �����
			pchar.questTemp.HWIC.Eng = "end";
			CloseQuestHeader("Holl_Gambit");
			DeleteAttribute(pchar, "questTemp.HWIC.TakeQuestShip");//�� �������
			DeleteAttribute(pchar, "questTemp.HWIC.EngEquip");
			pchar.questTemp.HWIC.Detector = "eng_fail";
			AddSimpleRumourCity("�������, ��� �� ��������� ����� ��������� ��������� ������� ��������. ��, ������ �� ������� ��� ����� ������ ������...", "SentJons", 20, 3, "");
		break;
		
		case "Fleetwood_RemoveShip":
			DialogExit();
			AddDialogExitQuestFunction("Fleetwood_RemoveShip");
			pchar.questTemp.HWIC.Eng = "end";
			CloseQuestHeader("Holl_Gambit");
			DeleteAttribute(pchar, "questTemp.HWIC.TakeQuestShip");//�� �������
			DeleteAttribute(pchar, "questTemp.HWIC.EngEquip");
			pchar.questTemp.HWIC.Detector = "eng_fail";
			AddSimpleRumourCity("�������, ��� �� ��������� ����� ��������� ��������� ������� ��������. ��, ������ �� ������� ��� ����� ������ ������...", "SentJons", 20, 3, "");
		break;
		
		case "Fleetwood_complete":
			pchar.questTemp.HWIC.Eng.ShipType = SHIP_VALCIRIA;
			AddDialogExitQuestFunction("Fleetwood_RemoveShip");	
			if (CheckCharacterItem(pchar, "JacobJournal"))//��������� ������
			{
				dialog.text = "��, ��� ��������, ��� �� ����������� ��������� ���������� ���� ����. �� ����������� �������� ������ � ��������� ��� �����. ���, ������, ��� ����������?";
				link.l1 = "'�����'.";
				link.l1.go = "Abigile";
			}
			else//��� ������� - ��� ����������� ������
			{
				dialog.text = "��, ��� ��������, ��� �� ����������� ��������� ���������� ���� ����. �� ����������� �������� ������ � ��������� ��� �����. '���������' � � ��� �������, � ��������� ������� �������� ���� � �������� �����... � � �����-�� ���� ����������� - �� ����� ������ ���������� � ����� ��������� �����, � ���� ����� ������� �����. � �������, " + pchar.name + "... �������, ��� '�������-�������' �������� ��������� �������\n� ��� ������������, ����� �� ����� ����� ������� � ������� ������ ������ ������ ����� - ��������� �� ���������� � ������ ����������� �����. ����� ��� �������� �������� ������ ��������� ������� ������ ���� �������\n����� ����, ������� �������� �������������� - 100 000 ���� � ��� ���� ������������� ������. � ����� �����, ��� ������ ��� ���������� ������... �� ������� ������ ����, � � ������� ����������� � ����! ��, � ������ �� ������ ���������� - ��� ���� �� ������� ��������, � �� ��� �� ���� ������� � ������. ����� ��� �������, �������!";
				link.l1 = "� ��� ���� ����, ������!";
				link.l1.go = "exit";
				LocatorReloadEnterDisable("SentJons_houseSP3", "reload2", true);//������� �������� � ������� � ����� ��� �����
				pchar.questTemp.HWIC.Eng = "end";
				pchar.questTemp.HWIC.Detector = "eng_win_half";
				CloseQuestHeader("Holl_Gambit");
			}
			AddMoneyToCharacter(pchar, 100000);
			GiveItem2Character(pchar, "bussol");
			DeleteAttribute(pchar, "questTemp.HWIC.TakeQuestShip");//�� �������
			DeleteAttribute(pchar, "questTemp.HWIC.EngEquip");
			AddSimpleRumourCity("�������, ��� �� � �������� ��������� ���������� ������� ��������, � ���������� ������� �� ����� ���������� ����������� ������, ���������� ���� �������� ����. �� ��������� �����, �������!", "SentJons", 20, 3, "");
		break;
		
		case "Abigile":
			dialog.text = "'�����'? ������ ���������� ���, ���� ��������... '���������' � � ��� �������, � '�����' �������� ���� � �������� �����... � � �����-�� ���� ����������� - �� ����� ������ ���������� � ����� ��������� �����, � ���� ����� ������� �����. � �������, " + pchar.name + "... �������, ��� '�������-�������' �������� ��������� �������\n� ��� ������������, ����� �� ����� ����� ������� � ������� ������ ������ ������ ����� - ��������� �� ���������� � ������ ����������� �����. ����� ��� �������� �������� ������ ��������� ������� ������ ���� �������\n����� ����, ������� �������� �������������� - 100 000 ����, � ��� ���� ������������� ������. � ����� �����, ��� ������ ��� ���������� ������. �� ������� ������ ����, � � ������� ����������� � ����! ������� ������ ����� ������� � ���?";
			link.l1 = "��, �������. ��� ��, ��������. � ����� ��� ��� ��������: ��� �� � ��������� ������ ����������... ������?";
			link.l1.go = "Abigile_1";			
		break;
		
		case "Abigile_1":
			RemoveItems(PChar, "JacobJournal", 1);
			dialog.text = "����. ������ �������, ������� ��� ������� ����� �������. �� ������ �� ���� � ������� ������? ������� � � �����...(������) ���-���. ��� � � �����������, �� ���� ���� ����� ����� ���������! ��, �� �����, ��� ��� �� ���� ������... ������ ���� ��������� ��������� �������� ��� �������-����������. ������� ���������� �������� ������ ���������!";
			link.l1 = "��. ���������, � ��� �������-���������� ������ ����� '��������' ����������� ���������?";
			link.l1.go = "Abigile_2";			
		break;
		
		case "Abigile_2":
			dialog.text = "������ ������������� �������� ������ ����, ���� ���... ��������� �������� ��������, ��� ��� ������ ��� ��������� �������� ����� ������ ������. �� ��� ��� ���� �� ������� � ������ ��� �� ���������� - �������, ��� �� ��� ��� �������� � ������� �������. ����� ������� ���������, ��� ���, �� �� ������ ������, �� ��� ������� ����� ������� ������� ����\n�������, ��� ��� �� ���� � ���� ����, �������. �� ���� ������ ��������� � ������� �� ������. ������� � ���� ���� � ��� ��� ���� ����� ������������� � ���������� ���������.";
			link.l1 = "������ ��� �����������, ������. ������ ����� ���������� ������ ����� ���������� � ���� ���?";
			link.l1.go = "Abigile_3";			
		break;
		
		case "Abigile_3":
			dialog.text = "���, � ���� ��� � ���� ��������� ��� �� ������ �������� ������� � ������� ���������. ��������� � ��� �������� �������� �������, �������, ������, �������� ������ ��� ������ '������'.";
			link.l1 = "� ���� ��������.";
			link.l1.go = "Abigile_4";			
		break;
		
		case "Abigile_4":
			dialog.text = "�������� �� ����� �� ����� � ���� �������, � ��� � ��������� ����� �� ������� '�������-��������'. � ��� �� ��������� �� �� �� ������� 64 ��. 41', ����� ��������� ������� ����� ��������. �� ��������� ����, ��� ��� ���. �� ����� � ��� ���� ��� ������� ����, � ������ ��������� �����, ������ ��� �� �������� ����. ���������� ����� ��� �������� ��������-��������� � �������� ��������, � ������� ������-�� ���������� ��������, ������� ���� �� ��������� �� ������\n� �������� � ������ �� �������, �� �� �� ������ ��� � �������. ������, ��� ����� � �� ���� ��� �� ����������� ���, � ����� ��������� � ���������� ������� �� ������ - ��������, ���-���� �� ������� ������������ ������� ���� ��������� �� ������. � �� ��������\n�� ������� � ��������� ���� �������, ���������� ���� ������������ ������ - ��������� ��������, ���� � ����. ������� ����� ��������. ��� ��� ���������! ��� ������ ����... � ���� �� �� ���� � ���������� ������� �� �������, ������, ���� ��������, �������, ������� �� ��� � ������� ����������\n��� � �����, �� ������ ���� �� ������, ����������� ����� - ������ �� ����������� � ��������, � ��� ���� �������� � ������ ����� �� '�����'. �� ����� ����������� �� � �������� ����������� �, �� ������� ������� ����� - �������� ���� �����. ��� ����� �������\n� ������� � �����, ��� �� ���� �������� ����� ����������� ���� �������� ��������� - ��������� ������! � ��������� ������� �� �� �������, ��� ������ ���� ������� � ���������� ���������� �� ���� - ������� ������� �� ���� ������� ��� ���� ���������� - �� � ��� � �� ���� �������� ���� ��������� ������. ������ ����� ��� ������\n��������� �������� ��� ��� �� ��������� ����� � ����, � ����� ��� - ������������� � ����������, ������� �������� � ��������� �� � ����-�����. ������������� �� �� ���� - ��� ������ ����� ��� �������� � ����������� �� ����.";
			link.l1 = "�� ���� ������� ���������� � ���� ����. � ���� �������� ���� ����� ������.";
			link.l1.go = "Abigile_5";			
		break;
		
		case "Abigile_5":
			PlaySound("VOICE\Russian\hambit\Richard Flitwood-02.wav");
			dialog.text = "������������! � ���, ��� �� ��� ����� ����������, " + pchar.name + ". ���� ������ ����� �������� ��������, ������ � ���� �� �����������.";
			link.l1 = "� �� �������� ��� ����� �����. �� ������ �������, ������!";
			link.l1.go = "Abigile_6";			
		break;
		
		case "Abigile_6":
			DialogExit();
			npchar.greeting = "fleetwood_2";
			LocatorReloadEnterDisable("Villemstad_town", "houseSP2", false);//������� ��� ���
			LocatorReloadEnterDisable("Villemstad_houseSp2", "reload2", true);//������� ������� ���
			AddQuestRecord("Holl_Gambit", "2-16");
			pchar.questTemp.HWIC.Eng = "toAbigile";
			sld = characterFromId("Bridgetown_tavernkeeper");
			sld.model = "barmen_3";
			sld.name = "�����";
			sld.lastname = "�������";//���������� ������� ����������
			sld.greeting = "barmen_1";
			sld = characterFromId("Solomon");
			sld.greeting = "solomon_2";
		break;
		
		case "Fleetwood_LastTask":
			dialog.text = "" + pchar.name + ", �� � ������ ����������� �� ������ �������? � �������� ����� �������������. ��� ������� ����� ���?";
			link.l1 = "��, �������. ��, � ���������, �� ���� ������� ������� �������������. � ��� ���� �� ����� ���������� ����� �����... ��� ������� - �� ��� ��� ����� � ������� ���������...";
			link.l1.go = "Fleetwood_LastTask_1";
		break;
		
		case "Fleetwood_LastTask_1":
			dialog.text = "�� ��� �� ��� ����� ���������? �������������, ���� ���, �� ������!";
			link.l1 = "� ������ �� ������ � ���������� � ����, � �������, ���� �� �����, � ������� ���� ������ �������. ������ ������������� ��� � �����. ������ �� ����� � ������� ������, ��� �����-�� ���� ���������� ���� � ������, ����� � ������� ���� ������ � ���� �������� �� ����� � ������� ����� �� �������...";
			link.l1.go = "Fleetwood_LastTask_2";
		break;
		
		case "Fleetwood_LastTask_2":
			dialog.text = "����������!";
			link.l1 = "� ����� ������, ���� � ������� ����������� �����������. ���� � �������� � ����, ���� �� �����, ������ ���� ����� ����������� ����� ������� ����, ��������� �����-�� ������ �����, � ����� �� ����� ������� ��������� �����... �, �������, �� �� ������ ��� ��������!";
			link.l1.go = "Fleetwood_LastTask_3";
		break;
		
		case "Fleetwood_LastTask_3":
			dialog.text = "" + pchar.name + "...";
			link.l1 = "������, � �� �����������. ��� ������������� ����, ���� � � ��� ���� � ��� � ������. ��� ��� ���������� �������� ������������ ���� ������� � ����� ������ �� ������. ���� ������ ���-�� �������, ����� �������� �������� ��������� ������ � ����� �� ����!";
			link.l1.go = "Fleetwood_LastTask_4";
		break;
		
		case "Fleetwood_LastTask_4":
			dialog.text = "";
			link.l1 = "��������� ����... � �� ��� ������ �� ���� ������, ��� ��� ������� ������� ��� �����... ���������� �� ������ ������� ��, ����� ��������� �� ��� ���� � ������� �������, � ��� ��� ������ �� �����... ����������� ����� ���, � ���-���� ������ ���� ����������� ������, �� ����� ��� �� ����. ���� ��� ������ ��� ���. ���������, ����������� ������!";
			link.l1.go = "Fleetwood_LastTask_5";
		break;
		
		case "Fleetwood_LastTask_5":
			RemoveItems(PChar, "GastonHead", 1);
			dialog.text = "�-�-�... ����... " + pchar.name + ", ��������... �����! ��� ������ �������, ������� ������� ���� �����, ������� ������!";
			link.l1 = "������, ��� ���? ��� ������ ��������, ������ ���������� � �� ���������������� �������� ��� �����, �������� �������-��������. � ����� ����� ��������. ��� ������ ���������, ��� ��� ����, � ����� ������� ��� ���������� ������ ��������� � ������� �������� �� �������, � ������� ����� �� �����!";
			link.l1.go = "Fleetwood_LastTask_6";
		break;
		
		case "Fleetwood_LastTask_6":
			dialog.text = "�������������, ������ �����-�� ������ � ���������� �������. �������...";
			link.l1 = "��� �����. ��, � ��������� ����� � ������� �� ����, �� � ������������ � �������� � ������� ������ ��� �� ����� ������. ��� � � �������� ����, ����� �������� ��� ��� ���� ������������. �����, ��, ������, ���-������ ������� � ���� ��������...";
			link.l1.go = "Fleetwood_LastTask_7";
		break;
		
		case "Fleetwood_LastTask_7":
			dialog.text = "�? � ������� �� ���� ������������ �� ������ ���... �� ���� ���� ������� - �� ��� ��� ����� �� ��������... " + pchar.name + ", ������� �������� ���. �� ������ ����������� � ��������� � ���������, ��� ����... ������ ������������� ������, ����� �� �� ����� �� ������� �����. �����, �� �������, ��� ����� �������� ����, ������ �� ������������ �����, � ����� ��� ������� � ������ ������ �� �������. ��� ��� ����� ����� ����� ��������. � ������ ������ ��� ���� ��������, � ������� ����������� �� ���������. � ������� ������ �����, � �� �������� �� ��������, �������� �������� � ��������� �� �� �������. �� ���� ���, ��� �� ���������, ��� ������� ����������� �� �����. �������������, ��� ����!";
			link.l1 = "������, ������. � ���������� ������ � ����.";
			link.l1.go = "Fleetwood_LastTask_8";
		break;
		
		case "Fleetwood_LastTask_8":
			DialogExit();
			pchar.questTemp.HWIC.Eng = "toBarbados";
			AddQuestRecord("Holl_Gambit", "2-21");
			SetFunctionTimerCondition("HWICEng_toBarbadosOver", 0, 0, 20, false);//����� �� ������
			AddSimpleRumourCity("�, �������, � ������, ��� ������ ������� ���������� ����. ��������, ��� ������� �������� �����. ��, ��������, ������ ������������ �������...", "SentJons", 20, 3, "");
		break;
		
//---------------------------------------------������ ����-----------------------------------------------
		
		case "InTerksShore":
			pchar.quest.Fleetwood_ShoreOver.over = "yes";//����� ������
			dialog.text = "� ��� �������, ��� �� � ���� ��� �������, ���������� ��� ��������. ���� �� ����, ��� ����� ��� � �� ��������, �����, � ����� ���� ��������� ���� ������ ��.";
			link.l1 = "�� �����, ������ �������. ��� �. ����� ����� ��� ����� � ������� � ��������, ��������� �������� � ���� ������. �� ����� � ����... �� �������� ������?";
			link.l1.go = "InTerksShore_1";
		break;
		
		case "InTerksShore_1":
			dialog.text = "����������. �� ������ ��� �� �� ��������, � ���� ������� ��������. � ������ �����, ��� ��� ���� � � ��� ��� � �������, ��� ���������� �� ����� �������� � �� �������.";
			link.l1 = "��� �� �������, ������, ��� �� ������� �� � ��� ���������, ����� ��������� ��� �������?";
			link.l1.go = "InTerksShore_2";
		break;
		
		case "InTerksShore_2":
			dialog.text = "� ��� �������, �� � �� �����. ���� � �� ����� �������� - �� � ����� ������� ���� �� ������. ��? � ���.";
			link.l1 = "������. �������, ������ ����� ������� �����, ������� �������. � ����������� ����� ���� ������� ����� �� ��-�� �����. ������, �������, ��� ���� �� ��������, �� � ������ ������� ��� ����� ��.";
			link.l1.go = "InTerksShore_3";
		break;
		
		case "InTerksShore_3":
			dialog.text = "�? ���������� ���������... �������, � ������� ��������, ��� ����� ����������. ������� ��� - �������� ����? ��� ����, ��� �� ����� ��, ��������?";
			link.l1 = "�������, � ������� ��� � ��������� �� ������ �� ������. ����� ���� - �� ����� ���. ���� ���� ��� ������� - �� �����, � ���� �����. ������ - ����� �����, ��� ������ ������... ����� ��� �� � ���� �������� ���� �� ���� �� �������� �����? ��-��-��!";
			link.l1.go = "InTerksShore_4";
		break;
		
		case "InTerksShore_4":
			dialog.text = "���� ���������, �������. � ����������� �� ����������� ������ ������� ��� ��� �� ���� �������, � ��� ����������, ��� � ���� � �����! ��� ��� ���������� - ��� ��� ��������� ������ ���������� ��� - � ������ ��������, � � ������ �����... � �������� �� ���!";
			link.l1 = "� ��� ���� �����! ������ ����� ��������� ��� ��������, ������. ������������� � ����������� � ��, ��� � ��� ��� ������ ������.";
			link.l1.go = "InTerksShore_5";
		break;
		
		case "InTerksShore_5"://�������� ����� �� ����������� �������
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);//�������� �������
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			for (i=1; i<=3; i++)//������� ��������
			{
				sld = characterFromId("FlOfficer_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			for (i=1; i<=7; i++)//������ ��������
			{
				sld = GetCharacter(NPC_GenerateCharacter("EnemySailor_"+i, "sold_eng_"+i, "man", "man", 18, ENGLAND, -1, false, "soldier"));
				FantomMakeCoolFighter(sld, 18, 30, 30, "blade_19", "pistol2", "bullet", 40);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
				if (i >= 1 && i < 3) ChangeCharacterAddressGroup(sld, "Shore56", "goto", "goto2");
				else ChangeCharacterAddressGroup(sld, "Shore56", "goto", "goto9");
			}
			for (i=1; i<=7; i++)//���� - � ���!
			{
				sld = characterFromId("OwrSailor_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
            LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
            LAi_group_SetCheck("EnemyFight", "FleetwoodDiedInShore");
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
	}
}