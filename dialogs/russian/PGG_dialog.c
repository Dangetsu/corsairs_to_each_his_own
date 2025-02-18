#include "DIALOGS\russian\Common_Duel.c"

#define MAX_PGG_STORIES 		9
#define MAX_PGG_QUEST_STORIES 	3
#define MAX_PGG_MEET_REP 		5

string PGG_Stories[MAX_PGG_STORIES] = {
"... ������ � � ������ ����� ��� �����, � ���������, ��� ��������� � �����, ������� ���� ���!..\n",
"... � ������� �������: '� �� ��� �� ���� ������, � �� ���� �� ��������� �� �� ����'.\n",
"... ������� � ����, ������ ������� ������, �� ���������: '������� ����� ������ ������� ���� ���� �� � ���������, ��� ������ ��������'.\n",
"... � ��� ����������� �������, ������� ��������� � ���� ������ ��������� � ����������. ��� ���-�� �� ��������� ������� �� ����� � �������� ��������. � �� ����, � ������� ��� ��� � ����-������� ���� �� ���, ��� ��������� ��� ���� ���������. ��� ������, ��� ������ � �� ��� ���. � ��� ������ �� ����������� �������, ��� �������� ��� ���� �� ���� ������! ��-��-��-��...\n",
"... ���, �����������, ��� �� ��������� � ��� �������, ������� � ��������������� ��� �� ������ ���������, � � ��������� ���� � ��������. ����������� ���-�� � ������� ����������� ���������� �� ����, ��� �������� ����������� ������ ������� '�������', � ��������� ��� �� ����� ������� ������������ ��� ������� ����! ������� ��� �������, ������ ��� ������� �������, � ������ ������� �� �������� ������������� �� ��������. �� ����� � ���������� ��� ������ �������, ��� ������ ��� ���������!!! ��-��-��-��...\n",
"... ������ �� ���� ������� � ������� ���������. �� ���, �� ����-���� �� ���� �������� ������ ���, ����� ����, �� ����������� �� ��� ������ �� ����� ����������. � ������� �� ������� ����������� ��� ���������� ��� ����� ��������, �� ��� ��� �������� ������ � ������� ���������. � ������ ������ �� ��������, �� ������ ������. ������ �� ���� ���� ���������, ����� �� ����� �� ��������� �� ������ ����!.. � � ����� � 1700 �������� ��������� ����!.. ��� ��� � ������� ������! � ��� ������� ��������! ��-��-��..\n",
"... �� �� � ������� ������, �����������, ��� ��� ��� ��������� � ������� ��������� �� ����� ��� ������� ������� ��������� ��������, ������� � ������ ������ �� ��������� ������ ������ ������������ ������ � ������ ��������� �� ����������� �������, � � ������ ����������� ������� � ������������ ���������...\n",
"... ����� ���� ��� ������ ��� ������ ����� ��-�����, ����� ���� ������ ���������?.. ���� ������� ����������� � �� ����, � ���������� � ������ ���. � ��������� ��� ������ ��������� ���� ������������. ���, � ������ ������� ���� �� ��� �����... ��, ����� �, � ��������� � ����������: '� ����� �� �� ����� �������, ��� ���? � ����� �� �������� �������?' � '���-���', � �������. � �� �� ���������: '� ����� �� �� �� ���������?'. ��� � � ������: '�����, � �� ���� �� ���������� ������!'. ��-��-��-��...\n",
"... ��-��-��!.. � ��� � ���������� ��� ������ �� ����� ���������. � ������ '��������!' ������ ��� ������ �������� � �������� �������� ������ ���������� � ���! ��� � ����! � � ������ ��� ������. ������ ���������, �� ��������� ����� ������� �� ���� � ����� �������� �������� ����� �� ������. ������� ��� �������� � ���� � ������� �������: - ����� �������� ��������, ������� ����� '��-��������!'. ��-��-�� ..." 
};

string PGG_QuestStories[MAX_PGG_QUEST_STORIES] = {
"...���-�� �������� �� �� ������� - ���������� �����. ����� � ������� ����������� ������ ����, ���������� ��� ���������� � �������. � ������ ��� �����, �, ������, �������� ����� �� ����� ��� ���������, ��� ��������� �� ������ ����. ��� ����������� - ����� ����� ����� � ��������� � ���� ������, �� ��� ����, ��� ������ � ��������! ����� ���� �������, ���� ��� �������� ������ �� ��������� � ���� ������� ������� �� ����������. ��� ��� ���� �������� � ���� �� �� ��� ���� ���!..\n� ��� � ������ ����� ��������� ������� ������. �� �� ��������� ����� � ������� ������ ������. ��� � �� ����? ����� ���� �������, ��-��-��!..",
"...�� �� ����, ��� ��� '������� ���������', �� ������� � ���������� � ����� ������ �������, ��� ������ ���� ���, �����������!.. ������ ������, ������ ��� ����, ������� �� ������ � ����� �� ������� ��� ������� ��������! ����������, � ������� ��������, �� �� ���������� ����� ������ � ������ ������������� ���� ���� ��������, ��� �� �����, ��� �� ��������, ��� � ��������! �� ����� �� ������ ������ �����! � ���� �������� ����� ����������� �� ������ - '��������'... � ������� ���� ���� - �� ������ � ������ ���� �������� ���� ����� ����� ���������...\n��� ����� ��� �����������... � ��� �� �� ��������? ����� �� ��������� ��� ����� ��� ������� ������? ��-��-��!.. ���� ����!",
"...� �� ��� � ������� �� � �������: '�����, ���, ������. ������, ��� ��������� � �������, ���� �� ��������� ��� �� ������, ��� ������'. � ����� ��� ��������� ����� ���� �� � �� �������� � �������: '������� ��������, �������� �� �� ��� � ��������!' ��-��-��... ��� ������ ���, ��� ����� ������ �� ���� �������, � ���� �� ��� ����� ������, �����������, �� �������� ��� ���� �������� ����� ������� ���� �� ������ � ����. ������ ������� ��� ����... �� ������ � � ��� ��� �� �������� ����� � ���, ����� ��� ��� ��� ����������!\n��, �������������� ���������� ��������, ������� ��������� �� ����� ������ �������� � ���� ������! ��-��-��-��..."
}

string PGG_Meet_GoodRep[MAX_PGG_MEET_REP] = {
"����� ��������� ����������� �������� � ���� �����.",
"������������ �� � ���� � ���� �����.",
"� ��� � ������� �������, �� ���� ���, ����������! ��-��!",
"�����������, � ������ ������� ��������� �������, ������� ����� ��� �� � ����� ����������. � ��� ���������, ���������?",
"� ��� � ��� ���� ������� ������, ������� �� ������ ������ ����� �����...", 
};

string PGG_Meet_BadRep[MAX_PGG_MEET_REP] = {
"� ��� � ��� ���� �����!",
"�����������, � ������ ����� ���������� �����, � �������.",
"������� ������� � ������, ���������� ������ �� �����!",
"�-� �����������, � ��� � ������� ������, � �������� ��������� ���� ��� ������������ � ������� �������� �� ������� ����... �� ������� ��������������?",
"��������, ������� ������� �����������, � ��� ������������� ��� ���� ������� ������, �������� �� ��������� ����� ��� ������������ �� ��������. ��-��-��",
};

void ProcessDialogEvent()
{
	int i, n;
	int iRnd = -1;
	int iAns;
	bool bOk;
   	float locx, locy, locz;
	string sTmp, sLoc;
	ref NPChar, sld;
	aref link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    ProcessDuelDialog(NPChar, link, NextDiag);

	if (Dialog.CurrentNode == "First time" && CheckAttribute(NPChar, "meeting")) Dialog.CurrentNode = "Second time";
	switch(Dialog.CurrentNode)
	{
//	Dialog.Text = "�� ������ ���... �������� � ��� ��, ��� Navy.";
//	link.l1 = "�����������!";
//	link.l1.go = "exit.";
	case "First time":
		if (CheckAttribute(NPChar, "PGGAi.location.town.back") && CheckAttribute(pchar, "questTemp.PGGContra.Know"))
		{
			Dialog.text = "������, ���������� ������! ������� ������, � � ����� ���� ������!";
			link.l1 = RandPhraseSimple("�� ������ ��� ��������, ������?", "�� ���������� ������ �������, �������!");
			link.l1.go = "Exit_Smugglers_Fight";
			link.l2 = "�� �����, � ����, ��� ����� ������. �� �������.";
			link.l2.go = "Exit";
			break;
		}
//		Dialog.Text = "������ ����, ���� ����� " + GetFullName(NPChar) + ", � ���?";
		if(rand(10) == 3)
		{
			iRnd = rand(MAX_PGG_QUEST_STORIES - 1);
			Dialog.Text = PGG_QuestStories[iRnd];
		}
		else
		{
			iRnd = rand(MAX_PGG_STORIES - 1);
			iAns = rand(MAX_PGG_MEET_REP - 1);
			Dialog.Text = PGG_Stories[iRnd] + PCharRepPhrase(PGG_Meet_GoodRep[iAns], PGG_Meet_BadRep[iAns]);
		}		 
//		link.l1 = "� ���� " + GetFullName(pchar) + ".";
		link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("���� ������! � ������� " + GetFullName(pchar) + ".", 
					"� ������� �������� '" + PChar.Ship.Name + "' � ���� ����� ��������� ������! ��-��! ��� ��� " + GetFullName(pchar) + "."), 
				RandPhraseSimple("��������� �������������, �����������. � ������� " + GetFullName(pchar) + ".", 
					"�� ���� ����� ���� ��� ������������"+ GetSexPhrase("��","��") +". � ������� ������� '" + PChar.Ship.Name + "' ��� ������ " + NationNameGenitive(sti(PChar.nation)) + ". ��� ��� " + GetFullName(pchar) + "."));
		link.l1.go = "Meeting";
		break;

	case "Meeting":
		Dialog.Text = "��, � ���� ����� ��� �����! � " + GetFullName(NPChar) + ". ������� �������������, ��� ���� ���� �������?";
		link.l1 = RandPhraseSimple("���� ���� ������!", "� ���� � ���� ��������...");
		link.l1.go = "quest";
		if (sti(pchar.Ship.Type) != SHIP_NOTUSED && sti(NPChar.Ship.Type) != SHIP_NOTUSED)
		{
			sld = GetRealShip(sti(NPChar.Ship.Type));
			
			Dialog.Text = "��, � ���� ����� ��� �����! � - " + GetFullName(NPChar) + ", ������� " + xiStr(sld.BaseName + "Acc") + " " + NPChar.Ship.Name + ".";
			link.l2 = "� ��� �������"+ GetSexPhrase("","�") +", �� ������ �� ��� ��������������? � ����� ��������� �� ������ ������� ���� ����������.";
			link.l2.go = "companion";
		}
		if (sti(NPChar.Ship.Type) == SHIP_NOTUSED)
		{
			link.l3 = RandPhraseSimple("�� ������ ����� �������� �� ��� �� �������?", "�������, ����� ������ ��� ��, ��� �� �� �������. ��� �������?");
			link.l3.go = "officer";
		}
		if (bBettaTestMode)
		{
			link.l7 = "(�����-����) ������.";
			link.l7.go = "BT_Quest";
			link.l8 = "(�����-����) �����.";
			link.l8.go = "outraged";
		}
		link.l9 = "������.";
		link.l9.go = "exit";
		NextDiag.TempNode = "Second time";
		NPChar.meeting = true;
		break;

	case "Second time":
		if (CheckAttribute(NPChar, "PGGAi.location.town.back") && CheckAttribute(pchar, "questTemp.PGGContra.Know"))
		{
			Dialog.text = "������, ���������� ������! ������� ������, � � ����� ���� ������!";
			link.l1 = RandPhraseSimple("�� ������ ��� ��������, ������?", "�� ���������� ������ �������, �������!");
			link.l1.go = "Exit_Smugglers_Fight";
			link.l2 = "�� �����, � ����, ��� ����� ������. �� �������.";
			link.l2.go = "Exit";
			break;
		}

		if (CheckAttribute(NPChar, "QuestTalk") && GetNpcQuestPastDayParam(NPChar, "QuestTalk") < 1)
		{
			Dialog.Text = "� ���� ��� ��� ������ �� �������!";
			link.l1 = "�� ��...";
			link.l1.go = "exit";
			break;
		}

		Dialog.text = RandPhraseSimple("��� ���� ���� " + GetFullName(pchar) + "?", "��� ���? �, ��... ����������, � �� � ����������...");
		link.l1 = RandPhraseSimple("��� �� ���� ������?", "� ���� � ���� ��������...");
		link.l1.go = "quest";

		if (PGG_ChangeRelation2MainCharacter(NPChar, 0) > 49)
		{
//			Dialog.Text = RandPhraseSimple("���� � ����?!! �� ��� �� " + GetFullName(pchar) + ". ��� ����������?", "��� ���������? ���� � ���� ���-������ �������?");
			if(rand(10) == 3)
			{
				iRnd = rand(MAX_PGG_QUEST_STORIES - 1);
				Dialog.Text = PGG_QuestStories[iRnd] + PCharRepPhrase(" ����� �����?", " ��� ������ �������� �� ����������?");
			}
			else
			{
				iRnd = rand(MAX_PGG_STORIES - 1);
				iAns = rand(MAX_PGG_MEET_REP - 1);
				Dialog.Text = PGG_Stories[iRnd] + PCharRepPhrase(PGG_Meet_GoodRep[iAns] + " ����� �����?", PGG_Meet_BadRep[iAns] + " ��� ������ �������� �� ����������?");
			}		
			if (sti(pchar.Ship.Type) != SHIP_NOTUSED && sti(NPChar.Ship.Type) != SHIP_NOTUSED)
			{
				link.l2 = RandPhraseSimple("� ��� �������"+ GetSexPhrase("","�") +", �� ������ �� ��� ��������������? � ����� ��������� �� ������ ������� ���� ����������.", "������, �� ��������� ������� ���������. �� ������ ������� ��� ���� �������?");
				link.l2.go = "companion";
			}
			if (sti(NPChar.Ship.Type) == SHIP_NOTUSED)
			{
				Dialog.Text = RandPhraseSimple("��, ���� ���, ����... ������� ��� �� ���!", "���� � ����?! ����� ������ ������� � ���� ����? � � ��� ��� ������� �������...");
				link.l3 = RandPhraseSimple("����... ��, ����� ������ ������� ������.", "��� ��� ����... ��, ��� ����, ������.");
				link.l3.go = "exit";
				if (FindFreeRandomOfficer() > 0)
				{
					link.l3 = RandPhraseSimple("�� ������ ����� �������� �� ��� �� �������?", "�������, ����� ������, ��� ��, ��� �� �� �������. ��� �������?");
					link.l3.go = "officer";
				}
			}
//			link.l4 = "��� ������ ������?";
//			link.l4.go = "rumours_capitan";
		}
		if (PGG_ChangeRelation2MainCharacter(NPChar, 0) < 20 || bBettaTestMode)
		{
			link.l8 = PCharRepPhrase("��� ��� ����. ��� � ������� �� �����������.", "�... ��� �������� ���������. �� ������� �� ���� ������ ����� � �����?");
			link.l8.go = "outraged";
		}
		link.l9 = "������.";
		link.l9.go = "exit";
		NextDiag.TempNode = "Second time";
		break;

	case "no_ship":
		break;

//==================================================
// Officer 
//==================================================
	case "officer":
		//��� � ����.
		if (CheckAttribute(NPChar, "Officer_Talk") && GetNpcQuestPastDayParam(NPChar, "Officer_Talk") < 1 && !bPGGLogShow)
		{
			Dialog.Text = RandPhraseSimple("� ���� ��� �������, ��� ��� �� ���������.", "��� ��������, �� ��� ��������.");
			link.l1 = RandPhraseSimple("��� � ���"+ GetSexPhrase("","��") +" ������?!", "� ������. ��, �����.");
			link.l1.go = "exit";
			break;
		}
		//���� ��� ��� ��������, �� �������� �����.
		if (CheckAttribute(NPChar, "PGGAi.Officer"))
		{
			Dialog.Text = RandPhraseSimple("��... �������, ���. ������ ��� ��� �������.", "� �� �������, � ����� �� ��� ������ ������?!!");
			link.l1 = RandPhraseSimple("�� ��� ������...", "��� �, ��������� ����������.");
			link.l1.go = "exit";
			break;
		}
		//���� ��������� ���� 70, �� � 70% ������� �������...
		if (PGG_ChangeRelation2MainCharacter(NPChar, 0) < 70 && rand(100) < 70)
		{
			Dialog.Text = RandPhraseSimple("��.. �������, ���...", "���, � �������, � �� ���� ���� ��������.");
			link.l1 = RandPhraseSimple("��, ��� ������...", "��� �, ��������� ����������.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Officer_Talk");
			break;
		}
		//�������� �� �������, �� ����! :) //navy 04.04.07
		if (FindFreeRandomOfficer() < 1)
		{
			Dialog.Text = RandPhraseSimple("�� � ���� � ��� ������ ��������.", "�� �����, ��� �� �����"+ GetSexPhrase("","�") +" ����������� ����.");
			link.l1 = RandPhraseSimple("����...", "������ �� ������.");
			link.l1.go = "exit";
			break;
		}
		if (!CheckAttribute(NPChar, "Quest.Officer.Price"))
		{
			NPChar.Quest.Officer.Price = 10000 + sti(NPChar.rank)*500*MOD_SKILL_ENEMY_RATE - MakeInt(GetSummonSkillFromNameToOld(pchar, SKILL_COMMERCE)*1000);
		}
		Dialog.Text = NPCharRepPhrase(NPChar, RandSwear() + 
				RandPhraseSimple("��� - ��, ��� �����! ���� ������ �������� ��������� �����! ���� ���������, ��� ����� " + NPChar.Quest.Officer.Price + " ����, ����� ������������ � �������.", 
								"�� ��������� �������"+ GetSexPhrase("�� ������� ������","�� ������� ��������") +". � ���� �� �����"+ GetSexPhrase("","�") +" ��������� " + NPChar.Quest.Officer.Price + " ����, ��, �������, �� �����������."), 
				LinkRandPhrase("���� ����������� ������ ������ ��� ����. � �������� �� ������ ��������� ����� � ������� " + NPChar.Quest.Officer.Price + " ����.", 
							"��... �� ��������� �����"+ GetSexPhrase("��","��") +" ����"+ GetSexPhrase("���","����") +". ��������, ��� ����� ������� �����������, ���� �� �������� ��������� ��� " + NPChar.Quest.Officer.Price + " ����.", 
							"�����, �� ����������� �������. ����� " + NPChar.Quest.Officer.Price + " ���� � �� ������ �� �����."));

		MakeRandomLinkOrderTwo(link, PCharRepPhrase(RandSwear() + RandPhraseSimple("���� ��� ����������. ��, �������, �� �� ������ ���� ������ ��������� �������.", "��� ��������� ������, ��, �����, �� ���� ������."), 
				LinkRandPhrase("� ������"+ GetSexPhrase("��","��") +". ������ ���� ����������� � �������.", "��... �������, � �����"+ GetSexPhrase("","�") +" ���������� � ���� ������.", "������, �� ������ ���� �����. �����!")), "officer_hired",
									PCharRepPhrase(RandSwear() + RandPhraseSimple("�� �� ������ �������. �����...", "��� ��������� ������, � �� �����"+ GetSexPhrase("","�") +" ���������� ������� �����."), 
				LinkRandPhrase("��... �������� �� �����...", "�� �� �������� ���� ����? �� ����� ������ � ���� ������ ������� �����, ��� ��.", "��� ������... ��� � ������ ���� ����� �����?")), "exit");
		link.l3 = "��... � ��� �� ������������� �� ����?";
		link.l3.go = "Exit_ShowParam";
		break;

	case "officer_hired":
		if (sti(pchar.money) < sti(NPChar.Quest.Officer.Price))
		{
			Dialog.Text = "������, � ��� �������� � �����������, �������.";
			link.l1 = "��... �������������.";
			link.l1.go = "exit";
			break;
		}
		pchar.questTemp.HiringOfficerIDX = NPChar.index;
		AddMoneyToCharacter(pchar, -(makeint(NPChar.Quest.Officer.Price)));
		AddDialogExitQuestFunction("PGG_BecomeHiredOfficer");
		NPChar.loyality = MakeInt(PGG_ChangeRelation2MainCharacter(NPChar, 0)*0.3)

		DeleteAttribute(NPChar, "Quest.Officer");
		DeleteAttribute(NPChar, "PGGAi.Task");
		DeleteAttribute(NPChar, "PGGAi.LockService");

		Dialog.Text = RandPhraseSimple("��� � �������!", "� �� ���������� � ���, �������.");
		link.l1 = "�� ��������� � ��������.";
		link.l1.go = "exit";
		break;

//==================================================
// Companion 
//==================================================
	case "companion":
		Dialog.Text = "���� �� ������� ���, ������, �� ������� ��� ;) �������� �� ���� Navy, ��������, ��� �� ��� ������� :)";
		link.l1 = "�����������!!!!";
		link.l1.go = "exit";
		//��� � ����.
		if (CheckAttribute(NPChar, "Companion_Talk") && GetNpcQuestPastDayParam(NPChar, "Companion_Talk") < 1 && !bPGGLogShow)
		{
			Dialog.Text = RandPhraseSimple("� ���� ��� �������, ��� ��� �����������.", "��� ��������, �� ��� ��������.");
			link.l1 = RandPhraseSimple("��� � ���"+ GetSexPhrase("","��") +" ������?!", "� ������. ��, �����.");
			link.l1.go = "exit";
			break;
		}
		//������� � ���� �����.. ����� ��������
		if (GetCharacterShipClass(NPChar) < GetCharacterShipClass(PChar)-1)
		{
			Dialog.Text = RandPhraseSimple("������� � �����!?? �������� �������!", "�� �����, ��� ��� ��� ���������!");
			link.l1 = RandPhraseSimple("��, ��� ������...", "��� �, ��������� ����������.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
			break;
		}
		//���� ��������� ���� 70, �� � 70% ������� �������...
		if (PGG_ChangeRelation2MainCharacter(NPChar, 0) < 70 && rand(100) < 70)
		{
			Dialog.Text = RandPhraseSimple("��.. �������, ���...", "���, �������. �� ����� ������� ��� ����-�� �������.");
			link.l1 = RandPhraseSimple("��, ��� ������...", "��� �, ��������� ����������.");
			link.l1.go = "exit";
			SaveCurrentNpcQuestDateParam(NPChar, "Companion_Talk");
			break;
		}
		//���� �� ����� ��� ����������.
		if (SetCompanionIndex(pchar, -1, sti(NPChar.index)) != -1)
		{
			Dialog.Text = NPCharRepPhrase(NPChar, RandSwear() + 
					RandPhraseSimple("�� ��� ���������! �� �����! � ��� ����� ���� ���� � ����� ��������!", "� �� "+ GetSexPhrase("������","�����") +" �� ������... �����, �� �����������!"), 
					LinkRandPhrase("���� ����������� ��� ��������. � ��������.", 
					"��� ���������. � ���� �����, ��� ������ �� ������ ������!", "�������, ��� ����� �������. �� �����."));
			link.l1 = RandPhraseSimple("�������, ��� ���� � ����!", "�� �����! �� ����� �������� ��������.");
			link.l1.go = "exit";
			NPChar.PGGAi.IsPGG = false;
			NPChar.PGGAi.location.town = "none";
			NPChar.Dialog.TempNode = "hired";
			NPChar.Dialog.FileName = "Enc_Officer_dialog.c";
            NPChar.Payment = true;
            NPChar.Money   = 0;
            
            SetBaseShipData(NPChar);
            DeleteAttribute(NPChar,"ship.sails");
			DeleteAttribute(NPChar,"ship.masts");
			DeleteAttribute(NPChar,"ship.blots");
			DeleteAttribute(NPChar,"ship.hulls");
			
			Fantom_SetCannons(NPChar, "pirate");
			Fantom_SetBalls(NPChar, "pirate");
    
			DeleteAttribute(NPChar, "PGGAi.Task");
			DeleteAttribute(NPChar, "PGGAi.LockService");
			SetCharacterRemovable(NPChar, true);
			SaveCurrentNpcQuestDateParam(NPChar, "Companion.CheckRelation");
		}
		else
		{
			Dialog.Text = RandPhraseSimple("������, ���� ��� ���������� �����������.", "� ���� � ��� ����� ��������. ����� ���� ��� ����?");
			link.l1 = "��... ����� �� � ����.";
			link.l1.go = "exit";
		}
		break;

	case "companion_leave":
		Dialog.Text = RandSwear() + " " + NPCharRepPhrase(NPChar,
					RandPhraseSimple("�� ��� ������"+ GetSexPhrase("","�") +"!!! � ������ �� ������� �������!", "��� �������� �������! � ���������."), 
					RandPhraseSimple("� ����� �� ����� �������, '�������'... ��������� �����������.", "������ � ���� ������ ������������. � ������ �� ������� �������."));
		link.l1 = PCharRepPhrase(RandPhraseSimple("�� � ���������� �� ��������.", "������ �������� �� ���� ������."),
					RandPhraseSimple("��� �, ������� �� ����.", "�������� ����. ��������� ����� � ������."));
		link.l1.go = "Exit_Companion_Leave";
		link.l2 = PCharRepPhrase(RandPhraseSimple("�... ��� �� ���� ��������� ������?", "��������!!! �����, ����������? � �����"+ GetSexPhrase("","�") +" ���� ��������� ������ ����� �������!"),
					RandPhraseSimple("���� ������������... �����, ��������� �������������� ����� ���� �����������?", "��� �� ���� �������� � ���������?"));
		link.l2.go = "companion_stay";
		break;

	case "companion_stay":
		if (CheckAttribute(NPChar, "Quest.Companion"))
		{
			Dialog.Text = RandPhraseSimple("������ � ���� ������ ����. ������ � �� ���� � ���� ��������!", "�������� �������� ���� �� ����������. ��� ������� ������������!");
			link.l1 = RandPhraseSimple("�� ��� ��, ����� ���� ����.", "����� ����������, � ����� � ���� ������ �� �����"+ GetSexPhrase("","�") +"!");
			link.l1.go = "Exit_Companion_Leave";
			break;
		}
		NPChar.Quest.Companion.Price = 2*GetSalaryForShip(NPChar);
		Dialog.Text = RandSwear() + " " + NPCharRepPhrase(NPChar,
					RandPhraseSimple("������? �������! ����� � " + NPChar.Quest.Companion.Price + " ����, ���� �������.", 
						"�������, ���� �� ��������� ���� ������� " + NPChar.Quest.Companion.Price + " ����, � ������� �� ��������."), 
					RandPhraseSimple("������! � ����� �������� �� �������� ������ � ������� " + NPChar.Quest.Companion.Price + " ����!",
						NPChar.Quest.Companion.Price + " ���� ������� �� ��������� ����� ���� � ��� �������."));
		link.l1 = PCharRepPhrase(RandPhraseSimple("�� �� �������� ���� ����! ���������� �� ���� ������.", "��... �� � ����� ������� ��� ������ �� ���-�� ����� ��������!"),
					RandPhraseSimple("�� �� ���. � �� ��������� �����"+ GetSexPhrase("","�") +"!", "������. � �� ����� ������� ��� �����."));
		link.l1.go = "Exit_Companion_Leave";
		if (sti(pchar.money) >= sti(NPChar.Quest.Companion.Price))
		{
			link.l2 = PCharRepPhrase(RandPhraseSimple("��� � �������! ����� �����������!", "� �� ��������"+ GetSexPhrase("��","���") +", ��� ���� ������ � �������!"),
					RandPhraseSimple("���������! � ���"+ GetSexPhrase("","�") +", ��� �� ���������!", "��� ��������� ������. � ������ �� ����� ������."));
			link.l2.go = "Exit_Companion_Stay";
		}
		break;

	case "Exit_Companion_Leave":
		chrDisableReloadToLocation = false;
		RemoveCharacterCompanion(pchar, NPChar);

		NPChar.PGGAi.IsPGG = true;
		NPChar.RebirthPhantom = true;
		NPChar.PGGAi.location.town = GetCurrentTown();

		LAi_SetWarriorTypeNoGroup(NPChar);
		NextDiag.CurrentNode = "Second Time";
		DialogExit();
		break;

	case "Exit_Companion_Stay":
        GetCharacterPos(NPChar, &locx, &locy, &locz);
        sTmp = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
		LAi_ActorGoToLocation(NPChar, "reload", sTmp, "none", "", "", "", 5.0);

		AddMoneyToCharacter(pchar, -(makeint(NPChar.Quest.Companion.Price)));
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		break;

//==================================================
// Quests
//==================================================
//==== BETTA_TEST ====
	case "BT_Quest":
		Dialog.Text = "�������� ������!";
		link.l1 = "����� 1 ������ - �������.";
		link.l1.go = "BT_Quest_1";
		link.l2 = "����� 1 ������ - ����������.";
		link.l2.go = "BT_Quest_2";
		break;

	case "BT_Quest_1":
		NPChar.PGGAi.ActiveQuest.QstNumber = 0;
		NPChar.PGGAi.ActiveQuest.QstNumber.Template = 1;
		Dialog.Text = "������! ����� 1 ������ - �������.";
		link.l1 = "�� ��...";
		link.l1.go = "quest";
		break;
	case "BT_Quest_2":
		NPChar.PGGAi.ActiveQuest.QstNumber = 0;
		NPChar.PGGAi.ActiveQuest.QstNumber.Template = 0;
		Dialog.Text = "������! ����� 1 ������ - ����������.";
		link.l1 = "�� ��...";
		link.l1.go = "quest";
		break;
//==== BETTA_TEST ====

	case "quest":
		chrDisableReloadToLocation = false;
		if (CheckAttribute(NPChar, "QuestTalk") && GetNpcQuestPastDayParam(NPChar, "QuestTalk") < 1)
		{
			Dialog.Text = "� ���� ��� ��� ������!";
			link.l1 = "�� ��...";
			link.l1.go = "exit";
			break;
		}
		Dialog.Text = RandPhraseSimple("����� ����?.. ��... �� ������ �� � �������� ��������!.. ��..",
									"�... ������� ��� �������!");
		link.l1 = "�������...";
		link.l1.go = "exit";
		if (!PGG_IsQuestAvaible()) break; //����� ������ �����.
		//if (!CheckAttribute(NPChar, "PGGAi.ActiveQuest") && !bBettaTestMode) break; //��� ������ �������� ���� ����� �������. ���� �����������, �� �� ��� ����� ���������� ����
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest.QstNumber")) iRnd = sti(NPChar.PGGAi.ActiveQuest.QstNumber); //��� ������, ������� ����� �� ��� ���
		if (iRnd == -1 && !CheckAttribute(pchar, "GenQuest.PGG_Quest")) iRnd = rand(1); // ����� � �� ����
		switch (iRnd)
		{
		case 0:
			if (sti(NPChar.Ship.Type) != SHIP_NOTUSED && sti(PChar.Ship.Type) != SHIP_NOTUSED && GetCharacterShipClass(PChar) <= 4 && GetCompanionQuantity(PChar) < COMPANION_MAX)
			{
				//����� �� ���
				/*if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
				{ */
				if (!CheckAttribute(pchar, "GenQuest.PGG_Quest"))
				{  // �� ����� ������� �������� ���
					Dialog.Text = "��� �� ��������? ���� �� �������. ���� ��� ������ - ��� �� ��������!";
					link.l1 = "��. �� � ���?";
					link.l1.go = "Quest_1_Work";
					NPChar.PGGAi.ActiveQuest = 1; // ���� ������� �� ������ �����
					PChar.GenQuest.PGG_Quest = 1; // ���� �� ��������� ������ ���
				}
				/* }
				//����� �� ��
				else
				{
					if ()
					{
						Log_TestInfo("����� �������� ����������� ������ ��");

						Dialog.Text = LinkRandPhrase("... ������ � � ������ ����� ��� ����� � ���������, ��� ��������� � �����, ������� ���� ���!...", 
							 "... � ������� �������: '� �� ��� �� ���� ������, � �� ���� �� ��������� �� �� ����'", 
							 "... ������� � ����, ������ ������� ������, �� ���������: '������� ����� ������ ������� ���� ���� �� � ���������, ��� ������ ��������'.") + 
							 PCharRepPhrase(LinkRandPhrase("� ��� � ��� ���� �����!",
									"�����������, � ������ ����� ���������� �����, � �������.",
									"������� ������� � ������, ���������� ������ �� �����!"), 
								LinkRandPhrase("����� ��������� ����������� �������� � ���� �����.",
									"������������ �� � ���� � ���� �����.",
									"� ��� � ������� �������, �� ���� ���, ����������! ��-��!"));
						link.l1 = "� �� ���, � ������ - ���� ����! ����������!";
						link.l1.go = "Quest_1_Work";
					}
				}  /**/
			}
			break;
		}
		SaveCurrentNpcQuestDateParam(NPChar, "QuestTalk");
		break;

	case "quest_onStay": // ��� ��� ��������
		chrDisableReloadToLocation = false;
		Dialog.Text = "������������!!! ��! �� � ���� ����, �� " + GetFullName(PChar) + ". ��������, ��������.";
		if (!CheckAttribute(NPChar, "meeting") || !sti(NPChar.meeting))
		{
			link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("� ������� " + GetFullName(pchar) + ".", 
						"� ������� �������� '" + PChar.Ship.Name + "' � ���� ����� ��������� ������! ��-��! ��� ��� " + GetFullName(pchar) + ".") + " � ���� � ���-�� �� �����.", 
					RandPhraseSimple("��������� �������������, �����������. � ������� " + GetFullName(pchar) + ".", 
						"�� ���� ����� ���� ��� ������������"+ GetSexPhrase("��","��") +". � ������� ������� '" + PChar.Ship.Name + "' ��� ������ " + NationNameGenitive(sti(PChar.nation)) + ". ��� ��� " + GetFullName(pchar) + ".") + " � ��� � ���-�� �� �����.");
//			link.l1 = "��... � �� ���, ���-�� � ���� �� �����.";
			link.l1.go = "Quest_1_Meeting";
		}
		else
		{
			link.l1 = "������, " + GetFullName(NPChar) + ". ��� ����?";
			link.l1.go = "Quest_1_Work";
		}
		SaveCurrentNpcQuestDateParam(NPChar, "QuestTalk");
		break;

	//=========== ������ ����� ==========
	case "Quest_1_Meeting":
		sld = GetRealShip(sti(NPChar.Ship.Type));
		Dialog.Text = "� - " + GetFullName(NPChar) + ", ������� " + xiStr(sld.BaseName + "Acc") + " " + NPChar.Ship.Name + NPCharRepPhrase(NPChar, ". ����� ��������� ������ ����� ���������� �����.", ". ������� �����.");
		link.l1 = "��, ������ � ���� �������.";
		link.l1.go = "Quest_1_Work";
		NPChar.meeting = true;
		break;

	case "Quest_1_Work":
		iRnd = rand(3);
		PChar.GenQuest.PGG_Quest.Template = rand(1);
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest.QstNumber.Template"))
		{
			PChar.GenQuest.PGG_Quest.Template = NPChar.PGGAi.ActiveQuest.QstNumber.Template;
		}
		PChar.GenQuest.PGG_Quest.Parts = GetCompanionQuantity(PChar)+1;
		PChar.GenQuest.PGG_Quest.Nation = iRnd;
		PChar.GenQuest.PGG_Quest.Island = GetRandomIslandId();
		while(PChar.GenQuest.PGG_Quest.Island == Islands[GetCharacterCurrentIsland(pchar)].id)
		{
			PChar.GenQuest.PGG_Quest.Island = GetRandomIslandId();
		}
		PChar.GenQuest.PGG_Quest.Island.Shore = GetIslandRandomShoreId(PChar.GenQuest.PGG_Quest.Island);
		while(PChar.GenQuest.PGG_Quest.Island.Shore == "")
		{
			PChar.GenQuest.PGG_Quest.Island = GetRandomIslandId();
			PChar.GenQuest.PGG_Quest.Island.Shore = GetIslandRandomShoreId(PChar.GenQuest.PGG_Quest.Island);
			if (sti(PChar.GenQuest.PGG_Quest.Template)) 
			{
				if (!isLocationFreeForQuests(PChar.GenQuest.PGG_Quest.Island)) PChar.GenQuest.PGG_Quest.Island.Shore = "";
			}
			else
			{
				if (!isLocationFreeForQuests(PChar.GenQuest.PGG_Quest.Island.Shore)) PChar.GenQuest.PGG_Quest.Island.Shore = "";
			}
		}
		PChar.GenQuest.PGG_Quest.Island.Town = FindTownOnIsland(PChar.GenQuest.PGG_Quest.Island);
		PChar.GenQuest.PGG_Quest.Days = 3 + GetMaxDaysFromIsland2Island(Islands[GetCharacterCurrentIsland(pchar)].id, PChar.GenQuest.PGG_Quest.Island);
		PChar.GenQuest.PGG_Quest.Goods = GOOD_SLAVES + rand(2);
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
//			Dialog.Text = "���� � ���� � ����, "+ GetSexPhrase("��������","�������") +". ����, ����� ���� ����������, �� � ������� ��������� �� ��������, ���� ����� ������. ��� ���� � ���� �� �����. �������, ��� �������� ������� '" + NPChar.Ship.Name + "'.";
//			link.l1 = "���������� ������, ������� ��� �� ������ �����������.";
			Dialog.Text = PCharRepPhrase(RandPhraseSimple("� ���� ���� ���������� ������ ��� ��� � ����� �����������.", 
								"��������� ���� �  �� ������ ����� �������� ���! ��, �������, �������� ���-���� �����. ��-��."), 
							RandPhraseSimple("� ���� ���� � ��� ������� �����������, �������.", 
							"�������, ���� ��������� ������ �������� �, �������, � ���� ��� ���������� ������� � ����� ���������� ����. ")) + 
						RandPhraseSimple("������ ����� ����. �������-��, ������� ��� � ���� � ����-�������� �� '" + NPChar.Ship.Name + "' �� �������� ��������� ���. �������.", "����� �������� �� ���� �� �����, ��������� � ���� �� ����� '" + NPChar.Ship.Name + "' � ������ �� � �����������. �� �����������.");
			link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("� ����� ����������! ������� ���� ����� ������, � ������ ��� �������!", 
								"������� �����������! � ������� ���� �������, ��� � �������!"), 
							RandPhraseSimple("������ �� �� �������� ���� ����������� ����� ������, � ������� �������?", 
								"�����, � ���� ��� ������� �������� ���� �����. ���� ��� ���-�� �����, ������������ �����!"));
		}
		else
		{
			PChar.GenQuest.PGG_Quest.Nation = FindEnemyNation2NationWithoutPirates(sti(PChar.Nation));
			Dialog.Text = "��-�-�... � ������� ��������� ���� �� �����, ���� ����� ������. ��� ���� �� ���� ������� '" + NPChar.Ship.Name + "'. ��� � ���������.";
			link.l1 = "������� ���, �� � ������ � �� �����.";
		}
		link.l1.go = "Quest_1_Work_1";
		link.l2 = PCharRepPhrase(RandPhraseSimple("� �����! ��, ���� �� ������� ��������� ��� �����, � ����� ���� ����!", 
					RandSwear() + "���, �������, ���� �������. � �� ������� ������ �� ����!"), 
				RandPhraseSimple("� � ������������� �������� ���� �����������, �������.", 
					"�� ���� �������������. ����������, � �����."));
		link.l2.go = "Exit_Quest_1_AfterTavernTalk";
		break;

	case "Quest_1_Work_1":
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("�� ����, ������, �� ����� ������! ���, ����� ���� ������ � ������!!!", 
					"���, "+ GetSexPhrase("��������","�������") +", � ����� �������"+ GetSexPhrase("","�") +" �� ������?!! ����! �� ��� �� ����."), 
				RandPhraseSimple("��� - ��� ���. �������� �� ����, ������, ����������� ���� ������.", 
					"��� ���, ��� �����. ���� ������. �� ������ ����� ���������."));
		link.l1 = PCharRepPhrase(RandPhraseSimple("��! � �� � ��������! � �� �������... �����!", 
					"������ �������� �� �����, �������. ���."), 
				RandPhraseSimple("������, � ������"+ GetSexPhrase("��","��") +".", 
					"�� ����� �����������. � �����"+ GetSexPhrase("","�") +" �������� ���� �� ����� �����."));
		link.l1.go = "Exit_Quest_1_AfterTavernTalk";
		link.l2 = PCharRepPhrase(RandPhraseSimple("��! ����� �������� ���� �� ���� ������� � �����? �� ������!", 
					"����� ���� �� ����� � �����! �� � ���� ��� � ����� ���� �����!"), 
				RandPhraseSimple("������������ �����������. � ��������"+ GetSexPhrase("","�") +" ����������.", 
					"������� ���� �������������, ������� " + GetFullName(NPChar) + ". ��������."));
		link.l2.go = "Quest_1_NotWork";
		break;

	case "Quest_1_NotWork":
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("���� ���! � �� �������� � ���� ����!", 
					"�� ��� ��� ��������, �� ��� ��?"), 
				RandPhraseSimple("����� ����� �������, � �����.", 
					"�������, � ��� � ���� ��� ����� ���."));
		link.l1 = RandSwear();
		link.l1.go = "exit_2";
		break;

	case "Quest_1_Work_2":
		Dialog.Text = "� �� ������, ��� ��� ��� �� �������!";
		link.l1 = "�... �������...";
		link.l1.go = "exit";
		NextDiag.TempNode = "Quest_1_Work_2";
		break;

	case "Exit_Quest_1_AfterTavernTalk":
		PChar.GenQuest.PGG_Quest = 1;
		PChar.GenQuest.PGG_Quest.Stage = 0;
		PChar.GenQuest.PGG_Quest.PGGid = NPChar.id;

		Group_AddCharacter("PGGQuest", NPChar.id);
		Group_SetGroupCommander("PGGQuest", NPChar.id);
		Group_SetAddress("PGGQuest", Islands[GetCharacterCurrentIsland(PChar)].id, "Quest_Ships", "Quest_Ship_1");
		Group_SetTaskNone("PGGQuest");

		SetTimerConditionParam("PGGQuest1_RemoveShip_Timer", "PGGQuest1_RemoveShip_Timer", 0, 0, 0, MakeInt(GetHour() + 6), false);
		PChar.Quest.PGGQuest1_RemoveShip_Timer.function = "PGG_Q1RemoveShip";

		NPChar.Ship.Mode = "Pirate";
		NPChar.DeckDialogNode = "Quest_1_Ship";
		NPChar.Nation.Bak = NPChar.Nation;
		NPChar.Nation = GetCityNation(GetCurrentTown());
		NPChar.AlwaysFriend = true;
		NPChar.Abordage.Enable = false; //������ ����� �� �������
		SetCharacterRelationBoth(sti(PChar.index), sti(NPChar.index), RELATION_FRIEND);

		ReOpenQuestHeader("Gen_PGGQuest1");
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Tavern");
		}
		else
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Tavern_1");
			AddQuestUserData("Gen_PGGQuest1", "sSex", GetSexPhrase("","�"));
		}
		AddQuestUserData("Gen_PGGQuest1", "sShipName", NPChar.Ship.Name);

		NextDiag.CurrentNode = "Quest_1_Work_2";
		DialogExit();
		if (NPChar.Chr_Ai.Type == "actor") LAi_SetWarriorTypeNoGroup(NPChar);
		break;

	case "Quest_1_Ship":
		PChar.Quest.PGGQuest1_RemoveShip_Timer.Over = "yes";
		if (GetCompanionQuantity(PChar) == COMPANION_MAX)
		{
			Dialog.Text = RandPhraseSimple("�, ���... ��� ���� �� ������... �� ����� �� ���� ��������, "+ GetSexPhrase("��������","�������") +"?", 
					"��! � ����� ������� �������� ������� �� ��������! ����������.");
			link.l1 = RandPhraseSimple("��, ��� ������!", 
					"��� �, �� �����-�� � ��������.");
			link.l1.go = "Exit";
			PChar.Quest.PGGQuest1_RemoveEnd.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_RemoveEnd.win_condition.l1.Location = PChar.location;
			PChar.Quest.PGGQuest1_RemoveEnd.function = "PGG_Q1RemoveShip";
			break;
		}
		PChar.GenQuest.PGG_Quest.Stage = 1;
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
//			Dialog.Text = "��, ��� � ������, ������ � ������ - ������ ���� ���, ��� ������� ��� � �����. ����������� ����� - ����� ������� ���������� �����!";
//			link.l1 = "� ��� ��� ��������? � ������ �� �������� ���� �� ����?";
			Dialog.Text = RandPhraseSimple("����� ���������� �� ����, �������!", 
					"��, ��� � ������, ������ � ������ - ������ ���� ���, ��� ������� ��� � �����.") + 
					" ����������� ����� � ����� ������� ���������� �����.";
			link.l1 = RandPhraseSimple("� ��� ��� ��������? � ������ �� �������� ���� �� ����?", 
					"- ����������? �� ��, ��������, ������!");
		}
		else
		{
			Dialog.Text = "��, ��� � ������, ������ � ������ - ������ ���� ���, �����������!";
			link.l1 = "����������� ����� - ����� ������� ���������� �����";
		}
		link.l1.go = "Quest_1_Ship_1";
		break;

	case "Quest_1_Ship_1":
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			Dialog.Text = RandPhraseSimple("��, ���� ����, ������� ������� ��� �����, � ����� ������� �� � ��������.", 
					"�� �������, �������� ���-���� �����. �� ���� �� ���� ���� �� ������?!");
			link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("����� � ����!", 
					"��� ��� ������ ������� ������! ��� ���?"), 
				RandPhraseSimple("�������� �� ������ ����������� ������ �����������.", 
					"��� ��������� �� ������ ��� ����������?"));
			link.l1.go = "Quest_1_Ship_Detail";
			link.l2 = PCharRepPhrase(RandPhraseSimple("���-�� �� �������. �� ���� � � ����� � ��� �����������!", 
					"�������� ������, �� � ���� �� ����! ������ ������ ������ ��� ���������? � �� ������"+ GetSexPhrase("��","��") +"!"), 
				RandPhraseSimple("����������� ����������, �� ��������"+ GetSexPhrase("","�") +" ����������.", 
					"���, ����� � � ������� �� ����, �����������, ��� �� ������. � ���."));
			link.l2.go = "Quest_1_Ship_Refuse";
		}
		else
		{
			Dialog.Text = "� ��� ��� ��������? � ������ �� �������� ���� �� ����?";
			link.l1 = "��, ���� ����, ������� ������� ��� �����, � ����� ������� �� � ��������.";
			link.l1.go = "Quest_1_Ship_Detail";
		}
		break;

	case "Quest_1_Ship_Detail":
		sTmp = "�������, ������������� " + NationNameGenitive(sti(PChar.GenQuest.PGG_Quest.Nation)) + ", ����������� ";
		if (sti(PChar.GenQuest.PGG_Quest.Goods) == GOOD_SLAVES)
		{
			sTmp += "�����";
			PChar.GenQuest.PGG_Quest.Goods.Text = "�����";
		}
		else
		{
			sTmp += XI_ConvertString(Goods[sti(PChar.GenQuest.PGG_Quest.Goods)].Name);
			PChar.GenQuest.PGG_Quest.Goods.Text = XI_ConvertString(Goods[sti(PChar.GenQuest.PGG_Quest.Goods)].Name);
		}

		if (PChar.GenQuest.PGG_Quest.Island.Town == "" || PChar.GenQuest.PGG_Quest.Island.Town == "Caiman" ||
			PChar.GenQuest.PGG_Quest.Island.Town == "Terks" || PChar.GenQuest.PGG_Quest.Island.Town == "Dominica")
		{
			sLoc = GetConvertStr(PChar.GenQuest.PGG_Quest.Island, "LocLables.txt") + "");
		}
		else
		{
			sLoc = XI_ConvertString("Colony" + PChar.GenQuest.PGG_Quest.Island.Town + "Gen");
		}
		
		if (sti(PChar.GenQuest.PGG_Quest.Template)) 
		{
			sTmp +=	", ����������� �������� �� " + sLoc + " � ����� " + GetConvertStr(PChar.GenQuest.PGG_Quest.Island.Shore, "LocLables.txt") + " ��� ���������� ��������.";
		}
		else
		{
			sTmp += ", ����� � ����� �������� �� " + sLoc + " � ����� �� ���. �� ��� ������ ������ ����� ����� � ���������� � ����� " + GetConvertStr(PChar.GenQuest.PGG_Quest.Island.Shore, "LocLables.txt") + 
				" ������ ��� ���� ������� ����� �������.";
		}
		
		Dialog.Text = sTmp;
		link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("�� ����, ���������� ��� �������!", 
					"� � ���� �� ����"+ GetSexPhrase("��","����") +", ��� �� ��� ������?"), 
				RandPhraseSimple("����� ���������, �����������!", 
					"� �"+ GetSexPhrase("���","��") +" ��������!"));
		link.l1.go = "Quest_1_Ship_Detail_1";

		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			link.l2 = PCharRepPhrase(RandPhraseSimple("������ ��������, �� ��������. �� ����� ��� � " + NationNameAblative(sti(PChar.GenQuest.PGG_Quest.Nation)) + " ��������.", 
					"�������? ���������? �� ��� ������ ������ ��� ���! �� �������. � �����."), 
				RandPhraseSimple("���, � " + NationNameAblative(sti(PChar.GenQuest.PGG_Quest.Nation)) + " � �� ����, �� ���������.", 
					"��� ����� � ���! � �� ��������� ������� ��������� � " + NationNameAblative(sti(PChar.GenQuest.PGG_Quest.Nation)) + "!"));
			link.l2.go = NPCharRepPhrase(NPChar, "Quest_1_Ship_BadWay", "Quest_1_Ship_Refuse");
		}
		else
		{
			Dialog.Text = "��... ��� ��� ������ ������� ������. ������?";
			link.l1 = sTmp;
		}
		if (sti(PChar.GenQuest.PGG_Quest.Template)) 
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Detail_A");
		}
		else
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Detail_B");
		}
		AddQuestUserData("Gen_PGGQuest1", "sNation", NationNameGenitive(sti(PChar.GenQuest.PGG_Quest.Nation)));
		AddQuestUserData("Gen_PGGQuest1", "sGoods", PChar.GenQuest.PGG_Quest.Goods.Text));
		AddQuestUserData("Gen_PGGQuest1", "sColony", sLoc);
		AddQuestUserData("Gen_PGGQuest1", "sShore", GetConvertStr(PChar.GenQuest.PGG_Quest.Island.Shore, "LocLables.txt"));
		break;

	case "Quest_1_Ship_Detail_1":
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
//			Dialog.Text = "� ��� ���� ������ " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " ��� ����, ����� ����������� ��.";
			Dialog.Text = PCharRepPhrase(RandPhraseSimple("����� " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " ������� ����� � ��� �� ��� �� �������.", 
						"� ��� ���� ����� " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " ����, ����� ������ �� �������� � ������� ������!"), 
					RandPhraseSimple("� ����� ������������ " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " ���� �� ��� ��������.", 
						"��� ����� ������������, " + PChar.Name + ". � ��� � ������ ����� " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + "."));
			link.l1 = RandPhraseSimple("�� ������! ��������� ������� ��.", "�� ����� �������. ��������� ��������� ������� ��.");
			link.l1.go = "Exit_Quest_1_Accept";
			AddQuestRecord("Gen_PGGQuest1", "q1_Accept");
		}
		else
		{
			Dialog.Text = "����� ���������, ���������.";
			link.l1 = "� ��� ���� ������ " + FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)) + " ��� ����, ����� ����������� ��.";
			link.l1.go = "Quest_1_Ship_Accept";
			AddQuestRecord("Gen_PGGQuest1", "q1_Accept_1");
		}
		AddQuestUserData("Gen_PGGQuest1", "nDays", FindRussianDaysString(sti(PChar.GenQuest.PGG_Quest.Days)));
		break;

	case "Quest_1_Ship_Accept":
		Dialog.Text = "�� ����� �������! � ����!";
		link.l1 = "� ����!";
		link.l1.go = "Exit_Quest_1_Accept";
		break;

	case "Exit_Quest_1_Accept":
		if (sti(PChar.GenQuest.PGG_Quest.Stage) < 2)
		{
			PChar.GenQuest.PGG_Quest.Stage = 2;
			PGG_Q1RemoveShip("");

			if (sti(PChar.GenQuest.PGG_Quest.Template)) 
			{
				PGG_Q1PlaceShipsNearIsland();
			}
			else
			{
				Locations[FindLocation(PChar.GenQuest.PGG_Quest.Island.Shore)].DisableEncounters = true;

				PChar.Quest.PGGQuest1_CheckStartState.win_condition.l1 = "Location";
				PChar.Quest.PGGQuest1_CheckStartState.win_condition.l1.Location = PChar.GenQuest.PGG_Quest.Island.Shore;
				PChar.Quest.PGGQuest1_CheckStartState.function = "PGG_Q1CheckStartState";
			}
			PChar.Quest.PGGQuest1_PGGDead.win_condition.l1 = "NPC_Death";
			PChar.Quest.PGGQuest1_PGGDead.win_condition.l1.Character = PChar.GenQuest.PGG_Quest.PGGid;
			PChar.Quest.PGGQuest1_PGGDead.function = "PGG_Q1PGGDead";

			SetTimerCondition("PGGQuest1_Time2Late", 0, 0, sti(PChar.GenQuest.PGG_Quest.Days), false);
			PChar.Quest.PGGQuest1_Time2Late.function = "PGG_Q1Time2Late";

			NPChar.PGGAi.IsPGG = false;
			NPChar.PGGAi.location.town = "none";
			DeleteAttribute(NPChar, "PGGAi.Task");
			DeleteAttribute(NPChar, "PGGAi.LockService");
			DeleteAttribute(NPChar, "AlwaysFriend");

			SetCompanionIndex(PChar, -1, sti(NPChar.index));
			SetCharacterRemovable(NPChar, false);
			
			SetBaseShipData(NPChar);
            DeleteAttribute(NPChar,"ship.sails");
			DeleteAttribute(NPChar,"ship.masts");
			DeleteAttribute(NPChar,"ship.blots");
			DeleteAttribute(NPChar,"ship.hulls");
			
			Fantom_SetCannons(NPChar, "pirate");
			Fantom_SetBalls(NPChar, "pirate");
		}
		NextDiag.CurrentNode = "Quest_1_Ship_Accept";
		DialogExit();
		break;

	case "Quest_1_Ship_Refuse":
		Dialog.Text = RandSwear() + "�� ���� ������������, �������. � �� ������, ��� � ��� �������� �� "+ RandPhraseSimple("���������� �����?!!", "������� ��������!??"));
		link.l1 = PCharRepPhrase(RandPhraseSimple("��� ���� ����. � ������ ���.", 
					"�� ���� �������� �� �������� ��-�� ���� ����."), 
				RandPhraseSimple("��� ������� �������������, �������.", 
					"��� �� � ��� ������ ��������."));
		link.l1.go = "Exit_Quest_1_Refuse";
		break;

	case "Exit_Quest_1_Refuse":
		if (sti(PChar.GenQuest.PGG_Quest.Stage) != -1)
		{
			PChar.GenQuest.PGG_Quest.Stage = -1;
			PChar.Quest.PGGQuest1_RemoveShip.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_RemoveShip.win_condition.l1.Location = PChar.location;
			PChar.Quest.PGGQuest1_RemoveShip.function = "PGG_Q1RemoveShip";

			AddQuestRecord("Gen_PGGQuest1", "q1_Close");
			AddQuestUserData("Gen_PGGQuest1", "sSex", GetSexPhrase("��","���"));
			CloseQuestHeader("Gen_PGGQuest1");
			DeleteAttribute(NPChar, "AlwaysFriend");
		}
		NPChar.Dialog.CurrentNode = "Quest_1_Ship_Refuse";
		NPChar.DeckDialogNode = "Quest_1_Ship_Refuse";
		DialogExit();
		break;

	case "Quest_1_Ship_BadWay":
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("�� �����, ��� ������� ��� �� ����� � ����� �� ������. �� ���� �������.", 
					"�����"+ GetSexPhrase("","�") +" ��� � ���"+ GetSexPhrase("","�") +" ������ ������ ����������? �� ������!"), 
				RandPhraseSimple("���� ��� �� ������������, �������? �� �� � ������� ��?", 
					"������ ������ ������ � ������ ����� � ������, ��� ������� �������� ��������� ������."));
		link.l1 = PCharRepPhrase(RandSwear() + RandPhraseSimple("�������� � �������� �������! � ������� " + GetFullName(PChar) + " � �� ��� �� ����! � �����!", 
					"������� ��������, �� ���� �������� �� ����!"), 
				RandPhraseSimple("���� ����������� ��� �����������, � �������� ��� ����� �� � ���. ��������.", 
					"�������, ��� �� � ��� ����� ��������. ���� ���� ����."));
		link.l1.go = "Quest_1_Ship_BadWay_1";
		break;

	case "Quest_1_Ship_BadWay_1":
		Dialog.Text = RandSwear() + PCharRepPhrase(RandPhraseSimple("�������� �"+ GetSexPhrase("��","�") +"! ��������� �"+ GetSexPhrase("��","�") +" � �����! ���������, ������ ����� � ��"+ GetSexPhrase("��","�") +" �����!!!", 
					"��, ������! ���������! �������� ������"+ GetSexPhrase("��","��") +"! �� �������� �"+ GetSexPhrase("��","�") +" � ������!!!"), 
				RandPhraseSimple("����, �������! �������, � ����� ����� ���� ����� �����. ��, � ����� �����, ��� � ����� ������.", 
					"����� ���� ����� �� �����, �������, ��� ��� �������: ��� ����� ���������� ��� ������ �� �������, ��� �� ������� ����� ��������� � ������������."));
		link.l1 = PCharRepPhrase(RandPhraseSimple("� �������� ���� ����� ���� ������� ������������, " + GetFullName(NPChar) + "!!!", 
					"� �� ����� � ������! ��������! ������� �����, ��� ������ �����!"), 
				RandPhraseSimple("���� ����������� �����������... � ������ ��������������!!!", 
					"� �� �� ����� ������������... � ������!!!"));
		link.l1.go = "Exit_Quest_1_DeckFight";
		break;

	case "Exit_Quest_1_DeckFight":
        GetCharacterPos(NPChar, &locx, &locy, &locz);
		DeleteAttribute(NPChar, "AlwaysFriend");
        sTmp = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
		LAi_SetImmortal(NPChar, true);
		LAi_SetActorType(NPChar);
		LAi_ActorRunToLocation(NPChar, "reload", sTmp, "none", "", "", "", 5.0);

		LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
		//������ ����� ���� ������, � �������� �� ������� � ��� ���... :(
		if (!CheckAttribute(pchar, "questTemp.PGGContra.Know"))
		{
			sTmp = "PGGTmp";
		}
		else
		{
			sTmp = "PGGQst";
		}
		PChar.GenQuest.PGG_Quest.GrpID = sTmp;

		for (i=1; i<5; i++)
		{
			sld = CharacterFromID("saylor_0" + i);
			LAi_group_MoveCharacter(sld, sTmp);
		}
		LAi_group_FightGroups(LAI_GROUP_PLAYER, sTmp, true);
		LAi_group_SetCheck(sTmp, "PGG_Q1AfterDeckFight");
		chrDisableReloadToLocation = true;

		PGG_ChangeRelation2MainCharacter(NPChar, -20);
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		LAi_SetFightMode(pchar, true);
		break;

	case "Quest_1_Time2Late":
		chrDisableReloadToLocation = false;

		//������� ����.. �.�. ����� ����� ����� (��� �����.)
		PChar.Quest.PGGQuest1_PGGDead.Over = "Yes";
		PChar.Quest.PGGQuest1_GroupDead.Over = "Yes";
		PChar.Quest.PGGQuest1_CheckStartState.Over = "Yes";

//		Dialog.Text = "���, " + GetFullName(PChar) + ", ���-�� ��� � � ����� ��������, ������ ������ ������ ������ ��� ����. ������!";
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("���� � ������! �� ��������! � ��� ��-�� ���, ������� �����! ������ ��� � ����� ������ ������, " + GetFullName(PChar) + ". ������� ��������! ������� ���� ������! ", 
					"���, " + GetFullName(PChar) + ", ���-�� ��� � � ����� ��������, ������ ������ ������ ������ ��� ����. ������!"), 
				RandPhraseSimple("��� �������! ����� ����� ���� ���������������! ��� � ���� �� �� ���� " + GetFullName(PChar) + ".", 
					"������� �� �� �������, ����� ������ �����. ��� � � ���� ��������! ��������."))
		link.l1 = PCharRepPhrase(RandPhraseSimple("�� � ���� � ���� ���������! ����� ������� ������ �� ����, � ����� ��������!", 
					"����� � ����, ��� �� �����! ���� ��������� ������� ���������, �������, ���� �� ������� �� �������!"), 
				RandPhraseSimple("�������������, ����, ��� ����� ��������� �������� ����������� ������ ������! ��������!", 
					"������� ������������, � ��� �����������... ��������!"));
		link.l1.go = "Exit_Quest_1_2Late";

		AddQuestRecord("Gen_PGGQuest1", "q1_Time2Late");
		CloseQuestHeader("Gen_PGGQuest1");
		break;

	case "Exit_Quest_1_2Late":
        LAi_SetPlayerType(PChar);
		if (sti(PChar.GenQuest.PGG_Quest.Stage) != -1)
		{
			PChar.GenQuest.PGG_Quest.Stage = -1;
			RemoveCharacterCompanion(pchar, NPChar);

			NPChar.PGGAi.IsPGG = true;
			NPChar.RebirthPhantom = true;

			LAi_SetWarriorTypeNoGroup(NPChar);
			LAi_group_MoveCharacter(NPChar, "GroupDeck");

			PChar.Quest.PGGQuest1_Clear.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_Clear.win_condition.l1.Location = PChar.location;
			if (PChar.location == "Ship_deck")
			{
/*				PChar.Quest.PGGQuest1_RemoveShip.win_condition.l1 = "ExitFromSea";
				PChar.Quest.PGGQuest1_RemoveShip.function = "PGG_Q1RemoveShip";
				PChar.Quest.PGGQuest1_Clear.win_condition.l1 = "ExitFromSea";
*/				PChar.quest.Munity = "Deads";
			}
			PChar.Quest.PGGQuest1_Clear.function = "PGG_Q1EndClear";
		}
		NextDiag.CurrentNode = "Quest_1_Failed";
		DialogExit();
		break;

	case "Quest_1_CheckResult":
		if (PChar.location == PChar.GenQuest.PGG_Quest.Island.Shore)
		{
			Locations[FindLocation(PChar.GenQuest.PGG_Quest.Island.Shore)].DisableEncounters = false;
		}
		else
		{
			PChar.quest.Munity = "Deads";
		}
		chrDisableReloadToLocation = false;

		//�� ����� ����...
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			PChar.GenQuest.PGG_Quest.FailedPaySum = sti(PChar.GenQuest.PGG_Quest.Days)*10000;
//			Dialog.Text = "�-��, �������� � � �����. ��� �������. �� ������ ��� ������ ��������� � ������� " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + ".";
			Dialog.Text = PCharRepPhrase(RandPhraseSimple("���������"+ GetSexPhrase("�� �������","�� �����") +"! ��� ���� �� ��� � �������� �������! " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + " ���� �� �����, � � ������ ���� ������ �� �����!", 
						"�� ���� ��������� ��������� ���������"+ GetSexPhrase("","�") +"? �������"+ GetSexPhrase("","�") +" ��� ������, "+ GetSexPhrase("�����","����") +"! ������ ��� " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + " ���� � ����������!"), 
					RandPhraseSimple("�� ����� ����� ������ ��������! ��� ���������� ������ �� �������! �������, �� ��� �������, ���� �� �������� ��� " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + " ���� ", 
						"���� ������ ����������� � ������ ���� �����! �� ��������� ��� ����! ���������� �������� ���� ���� � ������� " + FindRussianMoneyString(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)) + " ���� � ������������� �� ��� ������ �������! "));
			link.l1 = PCharRepPhrase(RandPhraseSimple("���� �� �� �, �� �� ������ ������ ������, ������ ��������!", 
						"����� ���� ��������� �������� ����� �� ������� ���� ������, ����� �� �� ��� �������� �� ��� � �� �������� ������! "), 
					RandPhraseSimple("���� ���������� ���������, � ������ �������������!", 
						"�������� � ��������� �� ����, ����� ����, � ������� � �� ����!"));
			link.l1.go = "Quest_1_NotPay";
			if (sti(pchar.money) >= sti(PChar.GenQuest.PGG_Quest.FailedPaySum))
			{
				link.l2 = PCharRepPhrase(RandPhraseSimple("� �� ���� ���� ���� ������ ���, � �� ��� ������! �������� ������ �������! ���!", 
								"�����!!! ��� ��, ������� ������ �� �� ���� �������. � ������"+ GetSexPhrase("��","��") +"."), 
							RandPhraseSimple("���� ���������� �������������, �� ������ � ����, ������, ���.", 
								"���� �������� ���������, �� � ��������"+ GetSexPhrase("","�") +" �����������!"));
				link.l2.go = "Exit_Quest_1_Failed";
			}
		}
		else
		{
			PChar.GenQuest.PGG_Quest.Stage = -1;
			Dialog.Text = "�-��, �������� � � �����. ��� �������"+ GetSexPhrase("","�") +". �� ������ -  �� ������, � ������ �� ��������.";
			link.l1 = "�� ��! ��� �� �����, �� ����������.";
			link.l1.go = "Exit_Quest_1_Failed";
		}

		//������� ����� ���� ����, �� ���!
		if (sti(PChar.GenQuest.PGG_Quest.Goods.Taken) > MakeInt(sti(PChar.GenQuest.PGG_Quest.Goods.Qty)/3))
		{
			PChar.GenQuest.PGG_Quest.Ok = 1;
//			Dialog.Text = "����, ������ ��������� " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ". ����� ������. ";
			Dialog.Text = PCharRepPhrase("������ ������! ������ ��������� " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ".", 
					"������� ���������, �������! ������ ��������� " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ".");
			i = sti(PChar.GenQuest.PGG_Quest.Parts);
			PChar.GenQuest.PGG_Quest.Goods.Part = MakeInt(sti(PChar.GenQuest.PGG_Quest.Goods.Taken) / i);
			if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
			{
				Dialog.Text = Dialog.Text + PCharRepPhrase(" ��� ���� ", " ����, ������������ �� ��� ����� - ");
			}
			else
			{
				Dialog.Text = Dialog.Text + " ���� ���� ";
			}
			Dialog.Text = Dialog.Text + PChar.GenQuest.PGG_Quest.Goods.Part + ".";
			link.l1 = PCharRepPhrase(RandPhraseSimple("�����������! ��� ������ ������!", "��, ��� �����... ������ ������ �����."), 
					RandPhraseSimple("���� ������� ���������. � ������"+ GetSexPhrase("��","��") +".", "� ������ �� ����������."));
			link.l1.go = "Exit_Quest_1_End";
			link.l2 = PCharRepPhrase(RandPhraseSimple("� �� ��� �������� ���� ����? �� ���� ���� ��������� �� ��� � �� �������!", 
						"����? ����� ������ ��� �� ����, � ���� ���� ������ �� ���������, �� ��� ���� ��������!"), 
					RandPhraseSimple("�� �����, ��� �� �� ���-�� ������ ������������.", 
						"��� ����� � ���! � �� ��������� �������� � ������� ������������!"));
			link.l2.go = "Quest_1_NotPay";
		}
		else
		{
			AddQuestRecord("Gen_PGGQuest1", "q1_Fail");
		}
		break;

	case "Quest_1_NotPay":
		Dialog.Text = PCharRepPhrase(RandPhraseSimple("���, ��� ���! ������� �� ����! ������!", 
					"�� ����� ��������� ����� � ���������� �������! � ������ ��� ������� ������!"), 
				RandPhraseSimple("��� ��, ��������, �������, � �� � ��� ���������, ����� ����������...", 
					"����������� ����� ������� � ������ �� ��������� ��� ���������� �� ������������ ������� �������. ������� ��� �� ����� �������, �������!"));
		link.l1 = PCharRepPhrase(RandPhraseSimple("��������� �����!", "���� ����� ��� �����!"), 
				RandPhraseSimple("��������! �������, ������ ������� ������ ������ ��� �� ������!", 
					"�������, ��� ���� ������� �� ������� ��� �������� ��� ����� ���������, ��������!"));
		link.l1.go = "Exit_Quest_1_Failed";
		PChar.GenQuest.PGG_Quest.Stage = -1;

		bOk = makeint(NPChar.reputation) < 41 && PGG_ChangeRelation2MainCharacter(NPChar, 0) < 75;
		if (bOk || CheckAttribute(PChar, "GenQuest.PGG_Quest.Ok"))
		{
			PChar.GenQuest.PGG_Quest.Stage = 4;
			Dialog.Text = PCharRepPhrase(RandPhraseSimple("�� �� �����"+ GetSexPhrase("","�") +"! ���� �� ���"+ GetSexPhrase("","��") +" �� ������ ���� �����! �������� "+ GetSexPhrase("�������","��������") +"!", 
						"��, ��������, �������, ��� � ����� �����? ��������� ���� ��� �����, � ����� ������� �����������!"), 
					RandPhraseSimple("�������� ������������ ���� �����, �������! �� ������ ��-��������, ������������� �� ������ ��������!", 
						"�� �� ���������� ��� ������, " + GetFullName(PChar) + "! � ������ ����, ������ �� ���� ��� ���!"));
			link.l1 = PCharRepPhrase(RandPhraseSimple("������� ��������, �� �� ��� ���������!!!", 
						"���-��! ��� � ������ ����, �������� " + GetFullName(PChar) + "! "), 
					RandPhraseSimple("������ ����� �������� � �������! ", 
						"�� ������ ����� ������� ��� ������� ����������?"));
			link.l1.go = "Exit_Quest_1_FailedFight";
		}
		break;

	case "Exit_Quest_1_Failed":
		if (sti(PChar.GenQuest.PGG_Quest.Stage) != -1)
		{
			AddMoneyToCharacter(PChar, -(sti(PChar.GenQuest.PGG_Quest.FailedPaySum)));
			AddQuestRecord("Gen_PGGQuest1", "q1_FailPay");
		AddQuestUserData("Gen_PGGQuest1", "sSex", GetSexPhrase("","�"));
		AddQuestUserData("Gen_PGGQuest1", "sSex1", GetSexPhrase("��","��"));
		}
		CloseQuestHeader("Gen_PGGQuest1");
		RemoveCharacterCompanion(pchar, NPChar);

		if (PChar.Location == "Ship_deck")
		{
			PChar.Quest.PGGQuest1_FailedExitSea.win_condition.l1 = "ExitFromSea";
			PChar.Quest.PGGQuest1_FailedExitSea.function = "PGG_Q1EndClear";
		}
		else
		{
			PChar.Quest.PGGQuest1_FailedExitLoc.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_FailedExitLoc.win_condition.l1.Location = PChar.location;
			PChar.Quest.PGGQuest1_FailedExitLoc.function = "PGG_Q1EndClear";
		}
		PGG_ChangeRelation2MainCharacter(NPChar, -5);

		LAi_SetImmortal(NPChar, true);
		//��� � �� ���� �������������.
		for (i = 1; i < sti(PChar.GenQuest.PGG_Quest.GrpID.Qty); i++)
		{
			sld = CharacterFromID("pirate_" + i);
			LAi_SetImmortal(sld, true);
		}

		NextDiag.CurrentNode = "Quest_1_Failed";
		DialogExit();
		if (NPChar.Chr_Ai.Type == "actor") LAi_SetWarriorTypeNoGroup(NPChar);
		break;

	case "Quest_1_Failed":
		Dialog.Text = "�� ���� ������ ����� � ����� ���!";
		link.l1 = "�� � �� �����.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "Quest_1_Failed";
		break;

	case "Quest_1_End":
		Dialog.Text = "������� ����� � ����� ����! �����.";
		link.l1 = "� ����.";
		link.l1.go = "Exit";
		NextDiag.TempNode = "Quest_1_End";
		break;

	case "Exit_Quest_1_FailedFight":
		RemoveCharacterCompanion(pchar, NPChar);

		LAi_LockFightMode(pchar, false);
		LAi_LocationFightDisable(&Locations[FindLocation(PChar.location)], false);
		LAi_group_SetRelation("PGGTmp", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);	
		LAi_group_FightGroups(LAI_GROUP_PLAYER, "PGGTmp", true);
		LAi_group_SetCheck("PGGTmp", "PGG_Q1AfterDeckFight");
	
		PChar.GenQuest.PGG_Quest.GrpID = "PGGTmp";
		chrDisableReloadToLocation = true;

		Group_AddCharacter("PGGQuest", NPChar.id);
		Group_SetGroupCommander("PGGQuest", NPChar.id);
		Group_SetAddress("PGGQuest", PChar.GenQuest.PGG_Quest.GrpLocation, "Quest_Ships", PChar.GenQuest.PGG_Quest.GrpLoc);
		Group_SetTaskNone("PGGQuest");

		PGG_ChangeRelation2MainCharacter(NPChar, -15);

		GetCharacterPos(NPChar, &locx, &locy, &locz);
        sTmp = LAi_FindNearestFreeLocator("reload", locx, locy, locz);
		NextDiag.CurrentNode = "Second Time";
		DialogExit();

		Log_TestInfo("go to loc " + sTmp + " " + NPChar.location);
		NPChar.location = PChar.location;
		if (PChar.location != "Ship_Deck") sTmp = "reload1_back";

		PChar.questTemp.Chr2Remove = NPChar.id;
		LAi_ActorRunToLocator(NPChar, "reload", sTmp, "RemoveCharacterFromLocation", 5.0);

		LAi_SetImmortal(NPChar, true);
		LAi_SetFightMode(pchar, true);
		break;

	case "Exit_Quest_1_End":
		RemoveCharacterCompanion(PChar, NPChar);

		i = sti(PChar.GenQuest.PGG_Quest.Goods.Part);
/*		i *= (sti(PChar.GenQuest.PGG_Quest.Parts)-1);
		i += sti(PChar.GenQuest.PGG_Quest.StartGoods);
		n = GetCompanionQuantity(PChar);
		SetCharacterGoods(PChar, sti(PChar.GenQuest.PGG_Quest.Goods), i);
		for (i = 1; i < n; i++)
		{
			iRnd = GetCompanionIndex(PChar, i);
			if (iRnd != -1)
			{
				sld = GetCharacter(iRnd);
				if (GetRemovable(sld))
				{
					Log_TestInfo("" + sld.id);
					SetCharacterGoods(sld, sti(PChar.GenQuest.PGG_Quest.Goods), 0);
				}
			}
		}
*/
		RemoveCharacterGoods(PChar, sti(PChar.GenQuest.PGG_Quest.Goods), i);
/*		if (PChar.Location == "Ship_deck")
		{
			PChar.Quest.PGGQuest1_EndExitSea.win_condition.l1 = "ExitFromSea";
			PChar.Quest.PGGQuest1_EndExitSea.function = "PGG_Q1EndClear";
		}
		else
		{*/
			PChar.Quest.PGGQuest1_EndExitLoc.win_condition.l1 = "ExitFromLocation";
			PChar.Quest.PGGQuest1_EndExitLoc.win_condition.l1.Location = PChar.location;
			PChar.Quest.PGGQuest1_EndExitLoc.function = "PGG_Q1EndClear";
		//}
		AddQuestRecord("Gen_PGGQuest1", "q1_OkShare");
		CloseQuestHeader("Gen_PGGQuest1");

		//��� � �� ���� �������������.
		for (i = 1; i < sti(PChar.GenQuest.PGG_Quest.GrpID.Qty); i++)
		{
			sld = CharacterFromID("pirate_" + i);
			LAi_SetImmortal(sld, true);
		}

		LAi_SetImmortal(NPChar, true);
		NextDiag.CurrentNode = "Quest_1_End";
		DialogExit();
  		LAi_SetWarriorType(NPChar); // ����� ������ ��
		LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
		break;

	case "Quest_1_SharePrise":
		chrDisableReloadToLocation = false;
		Dialog.Text = PCharRepPhrase("��������� �������, ����, ����� � ���� �� ����! ������ ��������� " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ".", "�������, �������! ������ ��������� " + PChar.GenQuest.PGG_Quest.Goods.Taken + " " + PChar.GenQuest.PGG_Quest.Goods.Text + ".");

		i = sti(PChar.GenQuest.PGG_Quest.Parts);
		PChar.GenQuest.PGG_Quest.Goods.Part = MakeInt(sti(PChar.GenQuest.PGG_Quest.Goods.Taken) / i);
        SetCharacterGoods(PChar, sti(PChar.GenQuest.PGG_Quest.Goods), sti(PChar.GenQuest.PGG_Quest.Goods.Taken) + GetCargoGoods(PChar, sti(PChar.GenQuest.PGG_Quest.Goods)));
		if (CheckAttribute(NPChar, "PGGAi.ActiveQuest"))
		{
			Dialog.Text = Dialog.Text + " ��� ���� ";
		}
		else
		{
			Dialog.Text = Dialog.Text + " ���� ���� ";
		}
		Dialog.Text = Dialog.Text + PChar.GenQuest.PGG_Quest.Goods.Part + ".";
		link.l1 = PCharRepPhrase(RandPhraseSimple("�����������, ������� ���� ����!", "��, ��� �����, ������� ���� ����!"), 
			RandPhraseSimple("���� ������� ���������. � ������"+ GetSexPhrase("��","��") +".", "� ������ �� ����������."));
		link.l1.go = "Exit_Quest_1_End";
		break;
//===================================
//              Exits 
//===================================
	case "Exit":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		if (NPChar.Chr_Ai.Type == "actor") LAi_SetWarriorTypeNoGroup(NPChar);
		break;
		
	case "Exit_2":
		if (CheckAttribute(pchar, "GenQuest.PGG_Quest")) DeleteAttribute(pchar, "GenQuest.PGG_Quest"); //fix
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		if (NPChar.Chr_Ai.Type == "actor") LAi_SetWarriorTypeNoGroup(NPChar);
		break;		

	case "Exit_Smugglers_Fight":
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();

		LAi_group_FightGroups(LAI_GROUP_PLAYER, "PGGTmp", true);
		LAi_SetFightMode(pchar, true);
		break;

	case "Exit_ShowParam":
		NextDiag.CurrentNode = "Second Time";
//		NPChar.quest.meeting = true;
		DialogExit();

		PChar.SystemInfo.OnlyShowCharacter = true;
		LaunchCharacter(NPChar);
		break;
	}
}
/* TEMPLATE
		Dialog.Text = "";
		link.l1 = "";
		link.l1.go = "";
		link.l2 = "";
		link.l2.go = "";
		link.l3 = "";
		link.l3.go = "";
*/
