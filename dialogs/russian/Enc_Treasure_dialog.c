//navy
#include "DIALOGS\russian\Common_Duel.c" 
// boal 29.05.04 ���� ����� �����
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	aref   item;
	bool   ok;
	
	if (!CheckAttribute(npchar, "quest.trade_date"))
    {
        npchar.quest.trade_date = "";
    }

	ProcessDuelDialog(NPChar, link, Diag); //navy

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

        case "Map_NotBuy":
            dialog.Text = "������������, ������� � � ��������, � � �������� �������.";
			Link.l1 = "���� ���, � �����!";
			Link.l1.go = "exit";
		break;
		
		case "First time":
			Diag.TempNode = "First time";

			dialog.Text = "���... ������ ����. � ���� ���� ���-��� ��� ����...";
			Link.l1 = "�� ��� ���?";
			Link.l1.go = "map_treasure_1";
		break;
		
		case "map_treasure_1":
            ok = (GetCharacterItem(Pchar, "map_part1")>0)  && (GetCharacterItem(Pchar, "map_part2")>0);
            if (GetCharacterItem(Pchar, "map_full") > 0 || ok)
            {
                dialog.Text = "��� �������!! �-��... ����� �� ����!";
    			Link.l1 = "�� �� ����. � "+ GetSexPhrase("�����","������") +", �� ��������.";
    			Link.l1.go = "exit";
            }
            else
            {
                dialog.Text = "���� � ���� ���� ������ ���������� ��� ���� �� ������� ����.";
    			Link.l1 = "� ��� �� ���?";
    			Link.l1.go = "map_treasure_2";
    			Link.l2 = "�� �� ����. ������� ���.";
    			Link.l2.go = "exit";
			}
		break;
		
		case "map_treasure_2":
            dialog.Text = "��� �������� �����. ����� � �������� �� �����. �� ��� �������, ��� ������ ���������! ��� � ���� �� ��������, �� ����� ����� ���������. �������.";
			Link.l1 = "����� ���������. ������� �������?";
			Link.l1.go = "map_treasure_3";
			Link.l2 = "�� �� ����. ������� ���.";
			Link.l2.go = "exit";
		break;
		
		case "map_treasure_3":
		    if (npchar.quest.trade_date != lastspeak_date)
		    {
                npchar.quest.trade_date      = lastspeak_date;
            }
            dialog.Text = "����� ����� "+FindRussianDublonString(sti(Pchar.GenQuest.TreasureMoney))+"."; // Addon-2016 Jason
			Link.l1 = "�����, ������� � �������� ��������.";
			if (GetCharacterItem(pchar, "gold_dublon") >= sti(Pchar.GenQuest.TreasureMoney)) // Addon-2016 Jason
			{
			   Link.l1.go = "map_treasure_buy";
			}
			else
			{
			   Link.l1.go = "Map_NotBuy";
			}
			Link.l2 = "������ �����. �� �����.";
			Link.l2.go = "exit";
		break;
		
		case "map_treasure_buy":
            dialog.Text = "�������. ������ �� ����������� ������������!";
			Link.l1 = "�������!";
			Link.l1.go = "exit";
			RemoveItems(pchar, "gold_dublon", sti(Pchar.GenQuest.TreasureMoney)); // Addon-2016 Jason
			GiveItem2Character(pchar, "map_full");
			Diag.TempNode = "Temp_treasure";
			npchar.LifeDay = 0; // ������ � ������, ���� �����, �� ��������� � ���� �����
		break;
		
		case "Temp_treasure":
            dialog.Text = "����� ������? �-��... ������� ��� ���!";
			Link.l1 = "�������!";
			Link.l1.go = "exit";
			ok = (GetCharacterItem(Pchar, "map_part1")>0)  || (GetCharacterItem(Pchar, "map_part2")>0);
            if (GetCharacterItem(Pchar, "map_full") == 0 && !ok)
            {
				Achievment_SetStat(pchar, 68, 1); // ugeen 2016
    			Link.l2 = "�� ������ ��� ���������!!";
    			Link.l2.go = "Temp_treasure_1";
			}
			Diag.TempNode = "Temp_treasure";
		break;
		
		case "Temp_treasure_1":
            dialog.Text = "� �� ���? �-��... � �� �� ���� � ��� �� ���� �����.";
			Link.l1 = "�� � �� ����!";
			Link.l1.go = "exit";
			Link.l2 = "�� �� ��� ������ ��� ��������!!! � ���� ����...";
			Link.l2.go = "outraged"; //navy -- �����!!!
			Diag.TempNode = "let_s_duel";
			npchar.LifeDay = 1; // ���� �� ������ �� ������
			SaveCurrentNpcQuestDateParam(npchar, "LifeTimeCreate");
		break;
		
		case "tavern_keeper":
            Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("tavern_keeper");
		break;
	}
}
