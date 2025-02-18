#include "DIALOGS\russian\Rumours\Common_rumours.c" //Jason
void ProcessDialogEvent()
{
 	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	// ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\ItemTrader\" + NPChar.City + "_ItemTrader.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
	ProcessCommonDialogRumors(NPChar, Link, NextDiag);
// ============================================================================
// ============================= ���� angry ==========>>>>>>>>>>>>>>>>>>>>>>>>>
    if (CheckAttribute(npchar, "angry") && !CheckAttribute(npchar, "angry.ok"))
    {
        npchar.angry.ok = 1;
        if (!CheckAttribute(npchar, "angry.first")) //������� ������� ������������
        {
            NextDiag.TempNode = NextDiag.CurrentNode;
            Dialog.CurrentNode = "AngryExitAgain";
            npchar.angry.first = 1;
        }
        else
        {
			
        }
    }
// <<<<<<<<<<<<<<<<<<<<<<======= ���� angry ===================================
// ============================================================================	   
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------������ ������ - ������ �������
  		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
		break;

  		case "First time":
			dialog.text = NPCharSexPhrase(npchar, "������ ��������� ���������� ��� ���� ��� ����� ��������, �������? ����� �� ���������� �� ������!", "��, �������, � ��� � �����, ��� �� ��������� ������ �� ���!.. ���� ���������� ���������� ��� ��� � ����� ��������, � ����� ��������� ������ ����������� �����.");
			link.l1 = "������, ��� ��� � ���� ����.";
			link.l1.go = "Trade_exit";
			
   			link.l2 = "� �� ������� ����.";
			link.l2.go = "quests";
			if (CheckCharacterItem(pchar, "cannabis7") && CheckAttribute(pchar, "questTemp.Mangarosa") && pchar.questTemp.Mangarosa == "find" && npchar.Merchant.type == "potion" && !CheckAttribute(npchar, "quest.mangarosa"))
			{
				link.l4 = "��������, � ��� ����� ���� ���������� ��������. �� ����������, ������������� �� ��� ��� ������������� �����-������ �����, ��� �������? �� ������ ����������. ������ ���������?";
				link.l4.go = "mangarosa";
			}
			link.l3 = "�������, �� ����������.";
			link.l3.go = "exit";

			//Jason --> ����-����� ���������� �����
			if (CheckAttribute(pchar, "questTemp.Wine.bottle") && NPChar.location == pchar.questTemp.Wine.City + "_town" && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
   				link.l4 = "�����, � ���� ����� ���������� ��������� �������� ������������ ����?";
				link.l4.go = "Wine_ItemTrader";
			}
			if (CheckAttribute(pchar, "questTemp.Wine.bottles") && NPChar.location == pchar.questTemp.Wine.City + "_town" && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
   				link.l4 = "��������, � ����, ��� �� �������� ����������� �����. ��� ����� ���������� ���������� �������.";
				link.l4.go = "Wine_Bottles";
			}
			if (CheckAttribute(pchar, "questTemp.Wine.Repeat1") && NPChar.location == pchar.questTemp.Wine.City + "_town" && npchar.id == pchar.questTemp.Wine.ItemTraderID && !CheckAttribute(pchar, "questTemp.Wine.fail"))
			{
   				link.l4 = "��� ����� �. ��� �� ��� ��������, �?";
				link.l4.go = "Wine_Repeat1";
			}
			// <-- ����-����� ���������� �����
			
			//Jason --> ��������� ����������� ���
			if (CheckAttribute(pchar, "GenQuest.Device.Shipyarder") && NPChar.location == pchar.GenQuest.Device.Shipyarder.City + "_town" && pchar.GenQuest.Device.Shipyarder == "begin" && !CheckAttribute(npchar, "quest.Device"))
			{
   				link.l5 = "��������, �� ��� �������� ������ ��������... ���� ����� ��� �������, ����� �� ��������� ������ "+pchar.GenQuest.Device.Shipyarder.Type+"?";
				link.l5.go = "Device_ItemTrader";
			}
			//<-- ��������� ����������� ���

			NextDiag.TempNode = "First time";
		break;

		case "Trade_exit":
            if (CheckNPCQuestDate(npchar, "Item_date"))
			{
				SetNPCQuestDate(npchar, "Item_date");
				GiveItemToTrader(npchar);
			}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(npchar, 0);
		break;
		
		//Jason --> ����-����� ���������� �����
		case "Wine_ItemTrader":
			dialog.text = "����. ������� ���� �� �������.";
			if (makeint(Pchar.money) >= 700)
			{
				link.l1 = "�������. ����� �� ����.";
				link.l1.go = "Wine_ItemTrader_1";
			}
			link.l2 = "����� ������! ��� ������� ��������� - �������.";
			link.l2.go = "exit";
		break;
		
		case "Wine_ItemTrader_1":
			dialog.text = "����������, ��������.";
			link.l1 = "�������������!";
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, -700);
			TakeNItems(pchar, "potionwine", 1);
			PlaySound("interface\important_item.wav");
			DeleteAttribute(pchar, "questTemp.Wine.bottle");
		break;
		
		case "Wine_Bottles":
			dialog.text = "��� ������! � ���� ����� �� ������� ����, � ��������� �����! � ������� ������� ������� ��������� ���� - ������ ��, ����� ������ � �������, �� ������� �� �������. ��� � ���� ������ ����������.";
			link.l1 = "�����, ��� ��� ���. �� ��-�� ������ ��� ������? �����, �������� ������ ���������� - � � ���� � ����� ��. ��� �� ���"+ NPCharSexPhrase(npchar, "","�") +" �� ������ ������?";
			link.l1.go = "Wine_Bottles_1";
		break;
		
		case "Wine_Bottles_1":
			dialog.text = "���, ���"+ NPCharSexPhrase(npchar, "","�") +" �� ����. ���� �����. �� ������ ��� � ���� ������ ���������� �� ������. � ��� �� �������� ����... �������, �����.";
			if (makeint(Pchar.money) >= 1000)
            {
				link.l1 = "������. ����� ���� ������ � ������, � ���� �������������.";
				link.l1.go = "Wine_Bottles_2";
			}
			link.l2 = "�� ������ ������"+ NPCharSexPhrase(npchar, "�","��") +" ���������! � ����� ���� �� �����? �������� � ��� ������ ����������.";
			link.l2.go = "Wine_Bottles_fail";
		break;
		
		case "Wine_Bottles_2":
    		AddMoneyToCharacter(pchar, -1000);
			pchar.questTemp.Wine.TraderID = pchar.questTemp.Wine.City +"_trader";
			sld = characterFromId(pchar.questTemp.Wine.TraderID);
			pchar.questTemp.Wine.Name = GetFullName(sld);
			pchar.questTemp.Wine.ItemTraderID = npchar.id;
			dialog.text = "����� ���������� ���� ����� "+pchar.questTemp.Wine.Name+", �� ������ �������� ��������.";
			link.l1 = "��� �����. �������!";
			link.l1.go = "exit";
			pchar.questTemp.Wine.Trader = "true";
			DeleteAttribute(pchar, "questTemp.Wine.bottles");
			AddQuestRecord("Wine", "3");
			AddQuestUserData("Wine", "sName", pchar.questTemp.Wine.Name);
		break;
		
		case "Wine_Bottles_fail":
			dialog.text = "��� ������, �������. ����� �������.";
			link.l1 = "�����.";
			link.l1.go = "exit";
			DeleteAttribute(pchar, "questTemp.Wine.bottles");
			AddQuestRecord("Wine", "4");
		break;
		
		case "Wine_Repeat1":
			DeleteAttribute(pchar, "questTemp.Wine.Repeat1");
			dialog.text = "��� ��������? ��������� ������, ����������.";
			link.l1 = "�� �������"+ NPCharSexPhrase(npchar, "","�") +" ����, �������"+ NPCharSexPhrase(npchar, "��","��") +" ������"+ NPCharSexPhrase(npchar, "��","��") +"! � ������ ��� ��� � ��������, "+pchar.questTemp.Wine.Name+" ������� ����� �� �������� - �� ��� ��� ��� ������! ���� ����� ��� ������!";
			link.l1.go = "Wine_Repeat1_fail";
			link.l2 = "��� ������ �����-�� �����... ������� � � �������, � "+pchar.questTemp.Wine.Name+" ��������, ��� ������� ����� �� ��������. ��� �� ��������� ���?";
			link.l2.go = "Wine_Repeat1_1";
		break;
		
		case "Wine_Repeat1_1":
			dialog.text = "���! �� ������� �����, ������ ���. ��� ������ ������� ���������� �� ��� ����, ��� � ��������� ������ ������, �� �������. � ������� �� ��� �������... ���� ������, ����� �� ������ ��� ���� - � ���� �������� ������� - ���� �� �����, ��� ������ ����, ��� ��� �������� ��, ������� ��� ����, ��� �� � ������. �������, ��� ������ � ���� ������� ���� �� ����������.";
			link.l1 = "��� ��� �����! �� �� �� ������ ��� ����� � ���� ������!";
			link.l1.go = "Wine_Repeat1_2";
		break;
		
		case "Wine_Repeat1_2":
			dialog.text = "������ � � ��� ����"+ NPCharSexPhrase(npchar, "","�") +" �� ����������. � �� ������ ��� ���� ��������� �������� - ��� ������ ����, � ����� �� ������.";
			if (makeint(Pchar.money) >= 2000)
			{
				link.l1 = "��... �� �� ���� �� ��, ������"+ NPCharSexPhrase(npchar, "�","��") +", ������. ������� ���, �����, �� �����. ������� ���� ������ � ������ �������.";
				link.l1.go = "Wine_Bottles_3";
			}
			link.l2 = "�� ��� ��� �� � ����� ������ �� �����. �� � ����� ����� ���� ���� ����������, �� �� ����� ��������� ���"+ NPCharSexPhrase(npchar, "���","��") +" ����"+ NPCharSexPhrase(npchar, "���","��") +" ������. � ���� � ���� ���. ��������.";
			link.l2.go = "Wine_Repeat1_goaway";
		break;
		
		case "Wine_Bottles_3":
			AddMoneyToCharacter(pchar, -2000);
			dialog.text = "�� �������� �������, �������! � �������, �������, ��� ����� ��������� � ��� �� ������� ������ ��������, �� �� ����� �� � ���� ������ ������. �� ������ ������� � ������ ��������� ������ ���� ��� ���� �������� �������, �� ������� ����, � �������� ������� �����. ��� ��� ������� �� ����� ������ ������������ ���� ����� - ��� ������ ������ ��������� ������ ��\n���...(�����)... ���, �������� ��� ������ - ������ "+pchar.questTemp.Wine.Name+" ������� ��� ���� ��� ������ ������ ��������.";
			link.l1 = "���� �� ��� ��������... ���� ��� - � �������! �� ��������!";
			link.l1.go = "Wine_Bottles_4";
		break;
		
		case "Wine_Bottles_4":
			pchar.questTemp.Wine.Repeat2 = "true";
			TakeNItems(pchar, "letter_1", 1);
			ChangeItemDescribe("letter_1", "itmdescr_letter_1");
			PlaySound("interface\important_item.wav");
			AddQuestRecord("Wine", "6");
			DialogExit();
		break;
		
		case "Wine_Repeat1_goaway":
			dialog.text = "��� ������, �������. ��������.";
			link.l1 = "...";
			link.l1.go = "exit";
			AddQuestRecord("Wine", "4");
		break;
		
		case "Wine_Repeat1_fail":
			dialog.text = "��, �� ������ � �������� ��� ��� ��������? � ������ ������ ������! ����-���!! ����!";
			link.l1 = "�� �������� ��! �����, � �����! ���� �� �������"+ NPCharSexPhrase(npchar, "","�") +", ��������, ���� ���� �� ���� �����!";
			link.l1.go = "exit";
			AddQuestRecord("Wine", "7");
		break;
		// <-- ����-����� ���������� �����
		
		//Jason --> ��������� ����������� ���
		case "Device_ItemTrader":
			dialog.text = "��, "+pchar.GenQuest.Device.Shipyarder.Type+"? ������� �����... ���� ��� ��� �� ���� ����� - ������� ���� �� �����, ������ ��������� � ����� �� �����"+ NPCharSexPhrase(npchar, "","�") +".";
			link.l1 = "��, ��� ���������������� ����������, "+pchar.GenQuest.Device.Shipyarder.Describe+". ����� ������ ��������� ���� �� ���������?";
			link.l1.go = "Device_ItemTrader_1";
			npchar.quest.Device = "true";
		break;
		
		case "Device_ItemTrader_1":
			if (sti(pchar.GenQuest.Device.Shipyarder.Chance1) > 0 && sti(pchar.GenQuest.Device.Shipyarder.Chance1) < 4 && npchar.location.group == "merchant" && npchar.location.locator == "merchant"+sti(pchar.GenQuest.Device.Shipyarder.Chance1))
			{
				dialog.text = "��... ��, �������� ��� ����� ���� ���� �������� ���. ������ �� �� ����� �� ������, � ������ ������� ��� �������. �� ������ ����� ��� ���, ���� � ���� �� ����, ��� ���� ��� �����? ��� � �� ����� ������� �����? � �����, �������"+ NPCharSexPhrase(npchar, "","�") +" � ���, � �� ����.";
				link.l1 = "� ��� �������� ���� ������� � ���� �����? ��� ����� ����� ���� ����������.";
				link.l1.go = "Device_Common";
			}
			else
			{
				dialog.text = "���, ����� �� ��������. ��� ��� ������ ����� �� ����. ����������� ��� � ����.";
				link.l1 = "����. ����� ����������!";
				link.l1.go = "exit";
			}
		break;
		// <-- ��������� ����������� ���
		
		// ���������
		case "mangarosa":
			// ��� �������� �������
			if (sti(pchar.questTemp.Mangarosa.m_count) == 5 || GetSummonSkillFromName(pchar, SKILL_FORTUNE) > 10+drand(30)+drand(40))
			{
				dialog.text = "��������... ��, �������� ����������. �, ��� ������� - �����, ����� ������. ��� �������� ���������. ��� ���� ��� ���������� - � �� ����, �� � ��� ������ ���� ���������� ����...";
				link.l1 = "��� �� ������ � ����?";
				link.l1.go = "mangarosa_1";
			}
			else
			{
				dialog.text = LinkRandPhrase("��������... ��, �������� ����������. �� ���������� ��� ������ ������������� �� ����. ������� ��� ����������, ���� ������� � ����, ��� ��������.","������� ���������... ��. ������ �� �������������, �� ��� ��� ���������. ��� ��� ����� �� ���� ������.","��� ���? ���-���... ���, �� ����������� ��� ����� �������. �� ��� ����� ��������, �� ��� ���� ��� ����� ������������ - �� �����������...");
				link.l1 = "����. ���� ���������� ���. ������...";
				link.l1.go = "mangarosa_exit";
			}
		break;
		
		case "mangarosa_exit":
			DialogExit();
			pchar.questTemp.Mangarosa.m_count = sti(pchar.questTemp.Mangarosa.m_count)+1;
			npchar.quest.mangarosa = "true";
		break;
		
		case "mangarosa_1":
			dialog.text = "���� ��������� ������������ �������� ������� � ������. ��� ���������� ������, ��� ������� �������� ����� ��������� ������� ����� �� ���� ��� ����� �������. ����� ��� �� ����� - � �� ����.";
			link.l1 = "���-���... ��, ��� ���-��! �� ������� ����, � ����, � ���� ������ ������������. ������� ��������!";
			link.l1.go = "mangarosa_2";
		break;
		
		case "mangarosa_2":
			DialogExit();
			npchar.quest.mangarosa = "true";
			DeleteAttribute(pchar, "questTemp.Mangarosa.m_count");
			pchar.questTemp.Mangarosa = "gipsy";
			AddQuestRecord("Mangarosa", "2");
		break;
		
// ======================== ���� ��� angry ===============>>>>>>>>>>>>>>>

////////////////////////////////////////////////////////////////////////////////////////////////
		case "AngryExitAgain":
            DialogExit();
            DeleteAttribute(npchar, "angry.ok")
		break;

// <<<<<<<<<<<<============= ���� ��� angry =============================
	}
}
