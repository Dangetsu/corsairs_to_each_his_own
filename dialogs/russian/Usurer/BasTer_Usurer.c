// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������?"), "������ ������� �� �������� ������ ��� ������...", "�-��, ��������� ������... ����� ������ �������������?",
                          "����������, � ��������� ��������, � �� �� ������� �������...", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� "+ GetSexPhrase("���������","����������") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� �������, ��������...", "� �������...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			// Addon-2016 Jason ���-���������
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "continue")
            {
                link.l1 = "� - ������� "+GetFullName(pchar)+". ��� ������� �������� ���� � ����� � �������, ��� �� ������� ���� ������. ������ ��� �����������.";
                link.l1.go = "FMQG";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "sucsess")
            {
                link.l1 = "��� ����� �, ����� "+GetFullName(npchar)+". � ������ �������� �������. �� � ���� � �����.";
                link.l1.go = "FMQG_14";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "letter")
            {
                link.l1 = "��� ����� �, ����� "+GetFullName(npchar)+". ������� ���������.";
                link.l1.go = "FMQG_17";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG") && pchar.questTemp.FMQG == "killers")
            {
                link.l1 = "��� ����� �, ����� "+GetFullName(npchar)+". ������� ���������.";
                link.l1.go = "FMQG_17";
            }
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter"))
            {
                link.l1 = "��� ����� �, ����� "+GetFullName(npchar)+". ��, ������, ��� � �� ����� ���� �������.";
                link.l1.go = "FMQG_23";
            }
		break;
		
		// Addon-2016 Jason ���-���������
		case "FMQG":
			dialog.text = "�-�, ������� "+GetFullName(pchar)+"! ����� ��� ��� ������. ������ ��������, ��� � ����������� �����... ������. � ���� � ��� ����� ����: ��������� ����� ����� � ��� � ����� �������� ������� �� ����� ������� ������ � ����� ��������� �� ���� ������ �����. ����� ������������� �� ��� ��������, � ��������� ������. ���� � ����?";
			link.l1 = "��, ���������� ������ ���������. �� ������������� ��������� �� ��� � ����� ������ ��� �����.";
			link.l1.go = "FMQG_1";
		break;
		
		case "FMQG_1":
			Log_Info("�� �������� ������� ������");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "purse3");
			dialog.text = "������ ���� �����? �������, �� ���� ����� �������, ���� �������� ��� ����������� ����� ����. � ����� � �� ��������. ��� - ���� ���� ������� ������� ������ ������ ���. ������� � ��������� ��� ���, ��� �������� �������� �������.";
			link.l1 = "������. ����� ������ ����������� ��� ����� ��� ����, ����� � �������� ��� � ���� ��� ������ � ��������� �� ��������� ����, � ������ - � ����� ��������, ��� � �����-�����. � �������� ��� ����� � ������� �������� � ��� ��������� � ��������� �����, ��� ��� �������� ��� ������� � ���� � �������.";
			link.l1.go = "FMQG_2";
		break;
		
		case "FMQG_2":
			dialog.text = "����. � ����� ������ �� �������, ���� �� ������ ������� �����������? � ��� �� �������� ���� � ����?";
			link.l1 = "�� ������ ����� �������, ��� ���������� � ������. � ������ � ���� ���� ���������� ����������: ��� ������� - ���� �������, ������ - �������. �� �� ����, ��� �� ���������, �� ��� ������� �� �� ��, ����� � ������� �� �������.";
			link.l1.go = "FMQG_3";
		break;
		
		case "FMQG_3":
			dialog.text = "��������� ������? � �����������? �! ��� ��� ��! �� �� ����� ������! ������ ��������� ��� �������� ����! ��� � ��� ������� �������, � ��������� ������! � ������, ��������...";
			link.l1 = "��. ��� ���, ��� � ���� � �������� �������. ���-������ ���, �����, ��� � ���� �����������?";
			link.l1.go = "FMQG_4";
		break;
		
		case "FMQG_4":
			dialog.text = "��������, �������. � ���� � ��� ����� ������� �����������. �� �� �� ������ ���������� ������� �����? �� ������� ��������� ��� ������� ��������� ��� �������� ������������ ����� �������. ��� �������� ����, ������� � ���� ��� ��������.";
			link.l1 = "��, ������� ���������.";
			link.l1.go = "FMQG_5";
		break;
		
		case "FMQG_5":
			dialog.text = "����� ������� ������ �������� � ����� ������� ���� ��� �����, � ������ ������� ������� �������� � ���������� ��������. ����� ������ - �� ��������� ����� ������ ���� �... �������. ��� ��������� �����, ������� ��� � �������� � ����� �������, ��� �������, �� ������������� � ���������� � ��������� ������ �����, �� �������� � �������������, ��� � ������. �� �������������� ���� � ���� � ����� ������� ��� ����� ���������, �� ������ ������������� �����, � ���� � � ����������\n� ���, ��������� �� ������ ������������ � ����� �������, �� ���� � ���� ��������� ������ ���... ����� ��������. ������ ���� ������ �������� ����� �� ���, ��� � ������� ��� �����. �� ��������� ������ ������, � ����������� ��������� ��������, �� � � ������� ���. ��� ��������� - ���. ����� ������ ������, � ���������� ����, ��������, �� ����������.";
			link.l1 = "� ��� ������ �����, ������� �� ��� ������, ��������� ����������������?";
			link.l1.go = "FMQG_6";
		break;
		
		case "FMQG_6":
			dialog.text = "������. �������� ��� ��������� ����� ����, �� ������ ���������. ������ ��� ����� � ������� ��������, ������ �������� �� ��� ��������� ����.";
			link.l1 = "���... ��� ���� �������� ������������� �� ������, ������� ���, � ����� ���� �������� ����� � �������.";
			link.l1.go = "FMQG_7";
		break;
		
		case "FMQG_7":
			dialog.text = "������ ���, �������. ������� � �� ����� �������� ��� ������: �������� ����� ������� � �������� �� ��� � ���-���. � ��� �� �� � ������������ � ����������� ��������, ��� ��������� ��� �������������. �� ������ ��� � ����, �� ��� �������� - � ��� ������ ������ ����� ����� �������, ��� � ����-���� ���. �, �������, �������� �� ��� ����� ����������������� �������� �� ��������, �� ��� �������, ��� ���� ������ ����� ��������� �����������.";
			link.l1 = "� ��� ������ �������?";
			link.l1.go = "FMQG_8";
		break;
		
		case "FMQG_8":
			dialog.text = "� ��� ��� �� �������� ������ �������� � ���������, ��� ��������� ����.";
			link.l1 = "��� �������, ��� �� ������ �, �� ����, ��������� ��������, �� ��� � ��������� ������, ������� ���-�� ��������.";
			link.l1.go = "FMQG_9";
		break;
		
		case "FMQG_9":
			dialog.text = "�������, � �������, ��� ����� ������ �� �������� � �������... ����� ��������, ��� �� ��� ����� ������ ������������ �������. � ���� ��� �������, ��� ��� �������������� ���������. ��, ����������, ������ ����������, ��... � ���� �������� ��� ��� ���-���, � �� ��������� �������� ���� ������.";
			link.l1 = "� ��� �� ��� ����� ����?";
			link.l1.go = "FMQG_10";
		break;
		
		case "FMQG_10":
			dialog.text = "�� ���� ���� �� ����, ��� ������ ������ � ���������, �� ��������� ����� ���-��� ������ �������������, ��������� �����, ������, ��� ������ �� ������. ���� ����� ���� �������� ��������� ������������� ������������ �������, ���������� ������� ������... �������, � ������ ����������� ������� � ����������� �������: ��� ����� �� ����� ������� �� ��������� ������ � ����� ��������� ��������?";
			link.l1 = "��... � ����� � ���� � ����� ���� ���������? � ������ ����� ���������� �� �����...";
			link.l1.go = "FMQG_11";
		break;
		
		case "FMQG_11":
			dialog.text = "��, �������! ����� � ���� ��� �������� � ���, ��� �� �� ��������� ������� � ����������� ������ ���� �� �������. �� ���� ��� ����������, � ���������, � ����������� ���������� ������ ����� ��������� �����. ��� ��� ������� - ���������, � ��� ��������... ����� ��������. ���� �������� - �� ����� �� ���� �������, ��������� � �����-�� �������� �����, ������� ��� � �������... � ����, �������?";
			link.l1 = "��� ��� �������. �� ���� ������������. ��� � � ��� �����...";
			link.l1.go = "FMQG_12";
		break;
		
		case "FMQG_12":
			dialog.text = "��� ��, �������! ����� ������! � ����� ���� ����� ��� ������ ���, � ��������� ������� ������ �� ��� ������. ������ ��� ������� - ������� ����� ������� � ��������� � ���-���. � ���� �����. �����, ���� ������� ��� ������ ����� ���������� ��� ����������� � ������ � �����.";
			link.l1 = "�� �� �������� ��� ������. ������ � �� �����, ��� ����� ������ ������� ��� �������� ������������ ����� ���� ��������� ���������. �� ��������, �����.";
			link.l1.go = "FMQG_13";
		break;
		
		case "FMQG_13":
			DialogExit();
			LocatorReloadEnterDisable("Baster_town", "reload1_back", false);
			LocatorReloadEnterDisable("Baster_town", "reload2_back", false);
			LocatorReloadEnterDisable("Baster_town", "gate_back", false);//������� ������ �� ������
			pchar.questTemp.FMQG = "headhunter_panama";
			ReOpenQuestHeader("FMQ_Guadeloupe");
			AddQuestRecord("FMQ_Guadeloupe", "7");
			SetFunctionTimerCondition("FMQG_UsurerTimeOut", 0, 0, 61, false);
		break;
		
		case "FMQG_14":
			dialog.text = "���������� �������, ������� "+GetFullName(pchar)+"! � ������ �� �������� ����� ��������� �� ��� �������. ������ ��� ������ �� ���� ������ �� ������... ��, � �� ��������� ���� �������������� - ��������. ��� ��� ������. � ���, ����� �� �������� �� ���� ���������, ��������� ������� - ������.";
			link.l1 = "���������. �������, ���� �������� �� ���� ������� ����� ������ � ��������������?";
			link.l1.go = "FMQG_15";
		break;
		
		case "FMQG_15":
			Log_Info("�� �������� �������� � ���������");
			Log_Info("�� �������� ������ '�����'");
			PlaySound("interface\important_item.wav");
			GiveItem2Character(pchar, "chest");
			GiveItem2Character(pchar, "obereg_7");
			dialog.text = "� ����� �������, �������? � ���-�� �� ���������� ������� �������, ��������� � ����. ���� ��� ������ ��� ����� ���� ��������. �� � ��������... �� �� ������ - ��� ��� ������.";
			link.l1 = "������ ���� ������ ������, �����. � ��� ���� ������ ������. ����� �������!";
			link.l1.go = "FMQG_16";
		break;
		
		case "FMQG_16":
			DialogExit();
			pchar.quest.FMQG_UsurerTimeOut.over = "yes";
			ref sld = characterFromId("FMQG_pass_1");
			RemovePassenger(pchar, sld);
			sld.lifeday = 0;
			pchar.questTemp.FMQG = "end";
			FMQ_Count();
			AddQuestRecord("FMQ_Guadeloupe", "23");
			CloseQuestHeader("FMQ_Guadeloupe");
			ChangeCharacterNationReputation(pchar, FRANCE, 5);
			ChangeCharacterComplexReputation(pchar, "nobility", 5);
			ChangeCharacterComplexReputation(pchar, "authority", 3);
			AddCharacterExpToSkill(pchar, "Leadership", 400);
			AddCharacterExpToSkill(pchar, "Sailing", 200);
		break;
		
		case "FMQG_17":
			dialog.text = "�������. ������� ������, �������, � ��� �� �������?";
			link.l1 = "���. ���� � ���� ���� ���-��� ������ ��� ���. �������� � �������� ���.";
			link.l1.go = "FMQG_18";
		break;
		
		case "FMQG_18":
			RemoveItems(pchar, "letter_baker", 1);
			dialog.text = "��� ���?";
			link.l1 = "�������, �������, �����. ����� ���������.";
			link.l1.go = "FMQG_19";
		break;
		
		case "FMQG_19":
			LAi_Fade("", "");
			dialog.text = "(������) ���... ��� ��� �� ���� ������������� ��������?";
			link.l1 = "�� ��������? �� �����, � ������ ���� '����' ����� ����� ������� �� �����. �����, ��� ����� ������ ��������� ������, ��� ���� �������� ����������� ������������ ����� '������' � ������ �������. ��� �� ��� ����������?";
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter")) link.l1.go = "FMQG_24";
			else link.l1.go = "FMQG_20";
		break;
		
		case "FMQG_20":
			dialog.text = "������, �� ���-���� ����� �������...";
			link.l1 = "��. ��� ��� � ��������� ��� ������: �� ��������� ��� ������� �� �������, ���� ���� � ������ ���, � � ������� ��� ���������� ����� ������.";
			link.l1.go = "FMQG_21";
		break;
		
		case "FMQG_21":
			dialog.text = "������, �������... � ��������.";
			link.l1 = "��� � ������. �������, �� �� ������� �� ���� ��� - ��� �������, ��� �� � �������. ����� �������.";
			link.l1.go = "FMQG_22";
		break;
		
		case "FMQG_22":
			DialogExit();
			pchar.quest.FMQG_UsurerTimeOut.over = "yes";
			pchar.questTemp.FMQG = "cave";
			bQuestDisableMapEnter = true;//������� �����
			pchar.GenQuest.MapClosedNoBattle = true;
			pchar.quest.FMQG_cave.win_condition.l1 = "location";
			pchar.quest.FMQG_cave.win_condition.l1.location = "Guadeloupe_Cave";
			pchar.quest.FMQG_cave.function = "FMQG_InCave";
			// �������� ������
			pchar.GenQuestBox.Guadeloupe_Cave = true;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse1 = 5;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse2 = 2;
			pchar.GenQuestBox.Guadeloupe_Cave.box3.items.purse3 = 1;
			SetFunctionTimerCondition("FMQG_ClearBox", 0, 0, 3, false);
			if (CheckAttribute(pchar, "questTemp.FMQG.Letter"))
			{
				SetFunctionTimerCondition("FMQG_RemoveHunterScore", 0, 0, 1, false);
				AddQuestRecord("FMQ_Guadeloupe", "29");
				DeleteAttribute(pchar, "questTemp.FMQG.Letter");
			}
			else AddQuestRecord("FMQ_Guadeloupe", "25");
		break;
		
		case "FMQG_23":
			dialog.text = "���-���... �� �����, �������...";
			link.l1 = "� ���� ��� ��� ���-��� ���������. �������� � �������� ���.";
			link.l1.go = "FMQG_18";
		break;
		
		case "FMQG_24":
			dialog.text = "������, �� ���-���� ����� �������...";
			link.l1 = "��. ��� ��� � ��������� ��� ������: �� ���������������� ��� ������ ��� ����� ������������ ��������, � ����������, � � ������� ��� ���������� ����� ������.";
			link.l1.go = "FMQG_25";
		break;
		
		case "FMQG_25":
			dialog.text = "��...";
			link.l1 = "���� �� �������, ��� �� ��� �������. ���� ������ �� ������������� �� �����������, � ����� ������ ��������� ����� ����� ������� �� ����� � ���, � ��� �� ������ ������ ��� ������.";
			link.l1.go = "FMQG_21";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}



