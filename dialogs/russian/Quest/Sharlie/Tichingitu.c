// ��������� - ������-������
void ProcessDialogEvent()
{
	ref NPChar, sld, rItm, rItem;
	aref Link, NextDiag, rType;
	int i;
	string 	sAttr, sGun, sBullet, attrL;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	sAttr = Dialog.CurrentNode;
	if (findsubstr(sAttr, "SetGunBullets1_" , 0) != -1)
 	{
        i = findsubstr(sAttr, "_" , 0);
	 	NPChar.SetGunBullets = strcut(sAttr, i + 1, strlen(sAttr) - 1); // ������ � �����
 	    Dialog.CurrentNode = "SetGunBullets2";
 	}
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� ���-�� ������?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "Tichingitu":
			dialog.text = "��� �� ������, �����������? � ��������� ��� ��� ���� ����.";
			link.l1 = "���� ����� ���������? ��. ��������, ����, � ������ �� ��� ����, ����� ������ �� ���� �����, � ����� ��������: ����� �� ����� � ��� � ����� ��������?";
			link.l1.go = "Tichingitu_1";
		break;
		
		case "Tichingitu_1":
			dialog.text = "";
			link.l1 = "�������? �����. ���� ������� �� ��������� � ����� ���. ��������, ����� �� �������� ���� �������� - ���� �����, � ����� ���� ������.";
			link.l1.go = "Tichingitu_2";
		break;
		
		case "Tichingitu_2":
			dialog.text = "��������� ������ � ����� ����������� ����� �����-����� �����, ����� ������� ����, �� ������ ������� ����� � �����. ��������� ������ � ������ ����. ��������� ������� �� �����. ����� �� ������ ������ ���������, ������� - ���, ����������� ������. ������ �������� ������� ������, ��� ��������� ���. ��������� ������ ����.";
			link.l1 = "���� ������, �� ����� �� ����� ������ � ��� ��������� ��... ������ ����?";
			link.l1.go = "Tichingitu_3";
		break;
		
		case "Tichingitu_3":
			dialog.text = "��������� ������� �� ��� ������ �����. ��������� ��������� ����� �����, ����� ������� �����, ����� ���������� ��������� - ��������� ���� �����, �����-����� �� ������ ���������. ��������� ��� ����, ��� ������, ��� ������.";
			link.l1 = "��, ��, �� ������� ����. �� � ����� �� ���������� �� ������ ������?";
			link.l1.go = "Tichingitu_4";
		break;
		
		case "Tichingitu_4":
			dialog.text = "����� ���� ����� - ���� �������. �� ������� - ��� ���� ��������� ���� ���, ���� ������ �������. ��� ���� ������ ������, ��� �� ���������. � ������ ����, ����� ����� ����. ��������� ������ ������ �����, ��� ������ ������ ���������, ��������� �������.";
			link.l1 = "�� ������� ������ ����? ��-�� ����� ���� ������� �� �������?";
			link.l1.go = "Tichingitu_5";
		break;
		
		case "Tichingitu_5":
			dialog.text = "���, �����������. � ��������� �� ���� ����� - ��� �������, ��� ������� �����...";
			link.l1 = "��� ��������... ��-�� �����-�� ���������� ������ ����� �� ����� ��� ������ ��������... ���������, � �������� ������ ����. � ���� ����� - ���� ���������, � ��� �������� �� �����. �����, ��� �������� ���-�� �������... � ������ �������� � �����������.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Tichingitu_wait";
			pchar.questTemp.Sharlie.Tichingitu = "commandante";
		break;
		
		case "Tichingitu_wait":
			dialog.text = "��������� �����. ������ �� ������� ������. ����� ��������� ��������� - ��������� ������ �������.";
			link.l1 = "��� �� ��� ��������. � ������� ������...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Tichingitu_wait";
		break;
		
		case "Tichingitu_6":
			dialog.text = "��������� �����. ������ �� ������� ������. ����� ��������� ��������� - ��������� ������ �������.";
			link.l1 = "�� ���� ����� �����������. ���� ��������� ��������. � ������� ������ ������������.";
			link.l1.go = "Tichingitu_7";
		break;
		
		case "Tichingitu_7":
			dialog.text = "����������� ������? ��������� ��������?";
			link.l1 = "������� �����. ������ ������� ���� ������ � �������� ����. ������ �� ����, � ������ ���� �� ������.";
			link.l1.go = "Tichingitu_8";
		break;
		
		case "Tichingitu_8":
			DialogExit();
			chrDisableReloadToLocation = false;//������� �������
			DoQuestReloadToLocation("BasTer_exittown", "rld", "aloc9", "TichingituFree"); // 170712
			pchar.quest.FreeTichingituOver.over = "yes"; //����� ������
		break;
		
		case "Tichingitu_9":
			dialog.text = "";
			link.l1 = "��� �� � ����� �� �������. �����, ���������, ������, �� ����� � �� ��������� ������! ����� ����� �����-������ ��������� ������� � ���� �� ������ - �� �����, ��� ��� ��������� ������� ����.";
			link.l1.go = "Tichingitu_10";
		break;
		
		case "Tichingitu_10":
			dialog.text = "��������� �� ����. �������� ������ ����� ���������. ��������� ����������. ����� ��������� ����������� ���������.";
			link.l1 = "����? �� ��� � ��� ������? ����� ��������, ����� �����? �� ����� �� ����� - �� ��������! ������!";
			link.l1.go = "Tichingitu_11";
		break;
		
		case "Tichingitu_11":
			dialog.text = "������ � �����, ����� ��������. ��������� ������� ���� ����� � �������. ��������� ����� ���������. ��������� ������� � ��� �� ���� ��������. �� ����������.";
			link.l1 = "���� ��, ����... �� ����� � ���� ��������, ���������? � ����� ���� �� ��� ����, ����� ���������� ���� � ����.";
			link.l1.go = "Tichingitu_12";
		break;
		
		case "Tichingitu_12":
			dialog.text = "��������� �� ���, ����� ��������. ��������� - ��������� ������. ��������� ������ ������� � ����. ������ ����� ���������, ����� ��� �������, ������ ��� ������� � ��������. ��������� ����� ������� � �������� ������. ��������� ����� �������� �� ������.";
			link.l1 = "����... �� ������, ���������, ��� �������� ����. ��� ����� ������ ����, � �� ��� �������� �������� ���������. � �� ������� �������� ������. �� � ��� �� ������ ������ ����? ����� ���������� �� �����, ����� �� ����� �������... ������, ���������. �� ����: ��������� ����� �� ���� �� �����.";
			link.l1.go = "Tichingitu_13";
			link.l2 = "���, ��������. ������ � �����, ����������� ����. �� ������ ���� ���� ����!";
			link.l2.go = "Tichingitu_exit";
		break;
		
		case "Tichingitu_exit":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorRunToLocation(npchar, "reload", "reload2_back", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "questTemp.Sharlie.Tichingitu");
		break;
		
		case "Tichingitu_13":
			dialog.text = "��������� �� ������� ������, ����� ��������. ��������� ����� ��� ������� ����. ��������� ����� ����� ������� �� ��������� �����.";
			link.l1 = "������. ����� ���������� � �������, ���������!";
			link.l1.go = "Tichingitu_hire";
		break;
		
		case "Tichingitu_hire":
			DialogExit();
			DeleteAttribute(npchar, "LifeDay");
			LAi_SetImmortal(npchar, false);
			npchar.quest.OfficerPrice = sti(pchar.rank)*20;
			npchar.OfficerWantToGo.DontGo = true;
			npchar.CompanionDisable = true;
			npchar.loyality = MAX_LOYALITY;
			AddPassenger(pchar, npchar, false);
			SetCharacterRemovable(npchar, true);
			npchar.Payment = true;
			npchar.CanTakeMushket = true;
			LAi_SetOfficerType(npchar);
			NextDiag.CurrentNode = "Tichingitu_officer";
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			SaveCurrentNpcQuestDateParam(npchar, "HiredDate");
			DeleteAttribute(pchar, "questTemp.Sharlie.Tichingitu");
		break;
		
	//--> ----------------------------------- ���������� ���� ------------------------------------------
		case "Tichingitu_officer":
			dialog.text = "��������� ������� ���, ������� "+pchar.name+"!";
			if (CheckAttribute(pchar, "questTemp.Dolly_Tieyasal") && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				Link.l4 = "���������, � ��������� ����������� � ������ ��������� ����� ��������. �� ���� ��������: ��� ������ ������� �����������, � ����� ���� - ���������: ����� ���������������� �������. ��... ������� �� ����?";
				Link.l4.go = "tieyasal";
			}
			Link.l1 = "������ ��� ������!";
            Link.l1.go = "stay_follow";
			link.l2 = "���� ������. ������!";
			link.l2.go = "exit";
			NextDiag.TempNode = "Tichingitu_officer";
		break;
		
		case "stay_follow":
            dialog.Text = "����� ���� ����������?";
			if (CheckAttribute(npchar, "IsMushketer"))
			{
				Link.l4 = "� ����, ����� �� �������� �� ������������ ���������� �� ����.";
				Link.l4.go = "TargetDistance";
			}
            Link.l1 = "���� �����!";
            Link.l1.go = "Boal_Stay";
            Link.l2 = "������ �� ���� � �� ��������!";
            Link.l2.go = "Boal_Follow";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			if(sGun != "")
			{
				rItm = ItemsFromID(sGun);
				if(CheckAttribute(NPChar, "chr_ai.bulletNum") && sti(NPChar.chr_ai.bulletNum) > 1)
				{
					Link.l3 = "����� �������� ��� ���������� ��� ������ �������������� ������.";
					Link.l3.go = "SetGunBullets";
				}	
			}		
		break;
		
		case "SetGunBullets":
			Dialog.Text = "����� ���� ����������:";
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			makearef(rType, rItm.type);	
			for (i = 0; i < sti(NPChar.chr_ai.bulletNum); i++)
			{
				sAttr = GetAttributeName(GetAttributeN(rType, i));
				sBullet = rItm.type.(sAttr).bullet;
				rItem = ItemsFromID(sBullet);								
				attrL = "l" + i;
				Link.(attrL) = GetConvertStr(rItem.name, "ItemsDescribe.txt");
				Link.(attrL).go = "SetGunBullets1_" + i;
			}
		break;	

		case "SetGunBullets2":
			i = sti(NPChar.SetGunBullets) + 1; 
			sGun = GetCharacterEquipByGroup(NPChar, GUN_ITEM_TYPE);
			rItm = ItemsFromID(sGun);
			sAttr = "t" + i;
			sBullet = rItm.type.(sAttr).bullet;
			LAi_SetCharacterUseBullet(NPChar, sBullet);
			LAi_GunSetUnload(NPChar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DeleteAttribute(NPChar,"SetGunBullets");
			DialogExit();
		break;		
		
        case "Boal_Stay":
            Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
            AddDialogExitQuestFunction("LandEnc_OfficerStay");
            dialog.Text = "���� �������� ����������!";
            Link.l1 = "������.";
            Link.l1.go = "Exit";
            Npchar.chr_ai.tmpl = LAI_TMPL_STAY;
        break;
        
        case "Boal_Follow":
            SetCharacterTask_FollowCharacter(Npchar, PChar);
            dialog.Text = "���� �������� ����������!";
            Link.l1 = "������.";
            Link.l1.go = "Exit";
        break;
		
		//--> ������ ��������� ��������
		case "TargetDistance":
			dialog.text = "�� ����� ������, �������? ������� ��������� � �����, �� �� ������, ��� ��������.";
			link.l1 = "";
			Link.l1.edit = 3;
			link.l1.go = "TargetDistance_1";			
		break;
		
		case "TargetDistance_1":
			iTemp = sti(dialogEditStrings[3]);
			if (iTemp < 0)
			{
				dialog.text = "�������, �������� ���������, �� � ��� �� ��������.";
				link.l1 = "������, �������� �����...";
				link.l1.go = "exit";
				break;
			}
			if (iTemp == 0)
			{
				dialog.text = "��������� ���� ������ �� �����, ������ �� ���������. �� ��� ������, �������?";
				link.l1 = "��, ������ ��� �� ���� � ���������.";
				link.l1.go = "exit";
				npchar.MusketerDistance = 0;
				break;
			}
			if (iTemp > 20)
			{
				dialog.text = "��������� �� ����� ������ �� ���� ������ �������� �����. ����� �� ������������.";
				link.l1 = "������, ����� ������� �� ���������� � �������� �����.";
				link.l1.go = "exit";
				npchar.MusketerDistance = 20.0;
				break;
			}
			dialog.text = "��������� ��� ������. ��������� �������� ������� �� ��������� ����������.";
			link.l1 = "������.";
			link.l1.go = "exit";
			npchar.MusketerDistance = iTemp;
		break;
		//<-- ������ ��������� ��������
	//<-- ----------------------------------- ���������� ���� ----------------------------------------
	
	// �� ��������
		case "tieyasal":
			dialog.text = "����� ��������� ����� ����� ������ ����� �������. ������ �� ��������, ��� ������� ������� ��� ���������. ��������� ���� �� ���, ���� ������� �������, ��� ����� � ���������.";
			link.l1 = "�������, ���� ���������! � ���, ��� �� ������ � ����.";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "����� �� ������������?";
			link.l1 = "������� �����. � ���� �� ������������ � ������.";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			DialogExit();
			AddQuestRecord("Tieyasal", "21");
			npchar.quest.Tieyasal = "teleport";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}