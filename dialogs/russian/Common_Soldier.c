// boal 25/04/04 ����� ������ ������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;	

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    // ����� ������� �� ������� -->
    NPChar.FileDialog2 = "DIALOGS\" + LanguageGetLanguage() + "\Soldier\" + NPChar.City + "_Soldier.c";
    if (LoadSegment(NPChar.FileDialog2))
	{
        ProcessCommonDialog(NPChar, Link, NextDiag);
		UnloadSegment(NPChar.FileDialog2);
	}
    // ����� ������� �� ������� <--
    int iTest, iTemp;
	string sTemp;
    iTest = FindColony(NPChar.City); // �����
    ref rColony;
	if (iTest != -1)
	{
		rColony = GetColonyByIndex(iTest);
	}
	switch(Dialog.CurrentNode)
	{
		case "Exit":
			sTemp = npchar.location;
			if (findsubstr(sTemp, "_townhall" , 0) != -1) AddDialogExitQuest("MainHeroFightModeOff");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");
		break;
		
		case "First time":			
            NextDiag.TempNode = "First time";
			if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
			{
				// �������� �� ������
				if (sti(pchar.nation) == PIRATE)
				{
    				dialog.text = RandPhraseSimple("������ � ������?! �� ����... ������ �"+ GetSexPhrase("��","�") +"!!", "��� �����!! ����� �"+ GetSexPhrase("��","�") +"!!!");
					link.l1 = RandPhraseSimple("�����, �� � ���?..", "���, ���������� ��������.");
					link.l1.go = "fight"; 
					break;
				} 
				dialog.text = RandPhraseSimple("�����? ����� ������!! ��������� �� ����!", "��������� �����!! ���������� �������� �"+ GetSexPhrase("��","�") +"!");
				link.l1 = RandPhraseSimple("��������, �����������!", "��� �� �� ���!");
				link.l1.go = "fight"; 
			}
			else
			{
				// eddy. ���������, �� ������� ��. -->
				if (GetNationRelation(sti(NPChar.nation), GetBaseHeroNation()) == RELATION_ENEMY && sti(NPChar.nation) != PIRATE)
				{
					// ������� ��������
					if(CheckAttribute(pchar, "questTemp.Guardoftruth") && CheckCharacterItem(pchar, "VerifyPaper") && npchar.city == "santiago")
					{
						dialog.text = RandPhraseSimple("��� �� � ��� ���� ����� �����?", "����! ��� ��? �� ����� ��������� ��������� ����� � �����?");
						link.l1 = "������ ��� ��� ������, ������. � ����� � ���������� �����������, ���� ��������.";
						link.l1.go = "vincento"; 
						break;
					}
					if(CheckAttribute(pchar, "questTemp.Guardoftruth.Trinidad") && CheckCharacterItem(pchar, "VerifyPaper") && npchar.city == "portspein")
					{
						dialog.text = RandPhraseSimple("��� �� � ��� ���� ����� �����?", "����! ��� ��? �� ����� ��������� ��������� ����� � �����?");
						link.l1 = "������ ��� ��� ������, ������. � ����� � ���������� �����������, ���� ��������.";
						link.l1.go = "vincento"; 
						break;
					}
					dialog.text = RandPhraseSimple("��� �� � ��� ���� ����� �����?", "����! ��� ��? �� ����� ��������� ��������� ����� � �����?");
					//==> �� ��������
					if (CheckNationLicence(HOLLAND))
					{
						link.l1 = "������, � ���� ������� " + GetRusNameNationLicence(HOLLAND) + ", ��� ���, � �������� ����� �� �������� ����������. ����� ������������...";
						link.l1.go = "LicenceOk";
						if (findsubstr(pchar.location.from_sea, "_town" , 0) != -1) //���� �������� � ������
						{
							link.l2 = "�� ���, �� ������, ��� �� ���� ������� ����������� ���� " + NationNameGenitive(sti(pchar.nation)) + "?!";
						}
						else //���� �������� �� � ������
						{
							link.l2 = "� ������"+ GetSexPhrase("","�") +" ����� � " + XI_ConvertString(GetIslandByCityName(npchar.city)+"Gen") + " ��� ������ " + NationNameGenitive(sti(pchar.nation)) + ". ��� ���� ��� �� ����?";
						}
						if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < (10+rand(50)+rand(50)))
						{
							link.l2.go = "PegYou";
						}
						else
						{
							link.l2.go = "NotPegYou";
						}
					}
					else
					{
						//==> �� �����
						// �������� �� ������
						if (sti(pchar.nation) == PIRATE)
						{
    						dialog.text = RandPhraseSimple("������ � ������?! �� ����... ������ ���!!", "��� �����!! ����� ���!!!");
							link.l1 = RandPhraseSimple("��, �����, �� � ���?..", "���, ���������� ��������...");
							link.l1.go = "fight"; 
							break;
						}
						if (findsubstr(pchar.location.from_sea, "_town" , 0) != -1) //���� �������� � ������
						{
							link.l1 = "�� ���, �� ������, ��� �� ���� ������� ����������� ���� " + NationNameGenitive(sti(pchar.nation)) + "?!";
						}
						else //���� �������� �� � ������
						{
							link.l1 = "� ������"+ GetSexPhrase("","�") +" ����� � " + XI_ConvertString(GetIslandByCityName(npchar.city)+"Gen") + " ��� ������ " + NationNameGenitive(sti(pchar.nation)) + ". ��� ���� ��� �� ����?";
						}
						if (GetSummonSkillFromName(pchar, SKILL_SNEAK) < (10+rand(50)+rand(50)))
						{
							link.l1.go = "PegYou";
						}
						else
						{
							link.l1.go = "NotPegYou";
						}
					}
				}
				// <-- eddy. ���������, �� ������� ��.
				else
				{
					if (sti(NPChar.nation) == PIRATE)
					{
						if (sti(rColony.HeroOwn) == true) // ��� ���������
						{
			         		switch (rand(10))
							{
								case 0:
									dialog.text = "��, �������, ��� ������ ���� � ���� � ����! ������� �������� �� �������� ��� ����� ��������! � ���...";
									link.l1 = "� ���, ���� ���, ����� ���� ��������� �������� �������������� �������, ������� � ���� �� ������.";
									link.l1.go = "exit";
								break;

								case 1:
									dialog.text = "�������, �� ��� ����� ���������?! �� ���� �� ���������� �����!";
									link.l1 = "��������, �����! �� �� ������ � �������� �����, ��� ��� �� �����.";
									link.l1.go = "exit";
								break;

								case 2:
									dialog.text = "��� ��� � ����, �������? �� �����-������ ����� ������ ���?";
									link.l1 = "�������, ������! ��������� � �������, ������� �� ���� � ������������� ����� ������� ������.";
									link.l1.go = "exit";
								break;

								case 3:
									dialog.text = "����� ������������, �������: �� ��� ��������� ����� � ����. ��� ������ �� ���� ������ ������� ����� �����!";
									link.l1 = "� �����"+ GetSexPhrase("","�") +" �� ����� �����! ������� ��� ������� � �� �����! ����� ���, ��� ���� �������� �������! � �� ���-���� �������� ��������� ��� �������.";
									link.l1.go = "exit";
								break;

								case 4:
									dialog.text = "����� ��� �� �������, �������, ����� ���������� - ��������� � ���������. �� ���, �������, �� ��� ����...";
									link.l1 = "�� ����, ������: ���� ���� - ������ �� ����� � ������� �� ��������. ��, � ��������� ����������� �� ���-��� - ��� ��� ������� ��� ����. �������!";
									link.l1.go = "exit";
								break;

								case 5:
									dialog.text = "�������, ��� �� ��������� � ��� �������! �� �� ��� � � ����� � � ����!";
									link.l1 = "���� � ���, �����������! ������ ������ ������. ������� � ������� �������, � ������. �� ������ ���������.";
									link.l1.go = "exit";
								break;

								case 6:
									dialog.text = "��, �������! ��� ����� �� �� ���� � �������� �����! ��, ����� �� �������� ����?!";
									link.l1 = "�� ������������, ������! ��������� ������ ����� ������ ����� ��������, ��� ��� �������� ���� ����� ������������ � ����� ������.";
									link.l1.go = "exit";
								break;

								case 7:
									dialog.text = "�������, �������, ����������� ������ ����� �������� ���� �������?";
									link.l1 = "�������, ������. ���� �� ����, ���� �� ����� �������. � ���� � ��� ������ ��������� � �������!";
									link.l1.go = "exit";
								break;

								case 8:
									dialog.text = "��-��-��! ����� ������� ����� � ��� ���� �������, �������! �����, ��� ��� �� ����.";
									link.l1 = "������, � ���� ��� ���������. � ���, ������, � �� �������.";
									link.l1.go = "exit";
								break;

								case 9:
									dialog.text = "����� ��� �� �������, �������, ��������� �� ��� ������� �� �������, �������� �� ����� � �������� ����� ���� �������...";
									link.l1 = "��, ������, ������ �� ��� �����!";
									link.l1.go = "exit";
								break;

								case 10:
									dialog.text = "���! ���������� �� ���� �� ���� ��������� ����������! ��, �� ���� � ����� ���������� ������� �����������!";
									link.l1 = "�� ����� �������: ������ ����� �� ������� ������ ���� �� �����. ������, ����, ��� ����� ������.";
									link.l1.go = "exit";
								break;
							}
							link.l2 = RandPhraseSimple("���� ������ ����!", "� ���� � ���� ����.");
							link.l2.go = "quests";//(���������� � ���� ������)
							break;
						}
						else
						{ // ������, �� ����
							if (sti(pchar.GenQuest.Piratekill) > 20)
							{
								dialog.text = RandPhraseSimple("�������! ����� ������� ���� � �������!", "� ������, � ������! ����� ������� ����!");
								link.l1 = RandPhraseSimple("�? ���?", "�, �� ���� ���?!");
								link.l1.go = "pirate_fight";
							}
							else
							{
							dialog.text = LinkRandPhrase(RandPhraseSimple("� ��� �� ��� ����, �������?", "� ��� �� ����� �������, ���� ���-�� ���� - �����������, �� ������."), RandPhraseSimple("�������, � ����� �����, ��� ��� ������� ������ ������������.", "���-�� �� ���, �������? ���� �������� ���, �� ��������� ������."), "����� ������, �������, � ���������.");
							link.l1 = LinkRandPhrase("������, ��������, � "+ GetSexPhrase("���������","����������") +" ", "�����, ��������� ������ ������.", "���, ������.");
							link.l1.go = "exit";
							link.l2 = LinkRandPhrase(RandPhraseSimple("� ���� � ���� ���� ��������.", "� ���� � ���� ����."), RandPhraseSimple("����, ��� ����������. ���� ������ � ������ ��������.", "� "+ GetSexPhrase("�����","������") +" �������� ���-���."), "���� ���� ��������. � ��� ��� �������� "+ GetSexPhrase("�����","������") +".");
							link.l2.go = "quests";//(���������� � ���� ������)
							}
							break;
						}
					}
					else
					{ //���� �������, ������� ��� � ������������� ��� ����������� �����
						if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -15)
						{
							dialog.text = RandPhraseSimple("�� ����������, "+ GetSexPhrase("����� ��������! ������","������ ��������! �������") +" ������ � " + XI_ConvertString("Colony" + npchar.city)+ ". ����� "+ GetSexPhrase("���","��") +"!!", "��, � ����� ����, "+ GetSexPhrase("�������","���������") +"! ������ "+ GetSexPhrase("���","��") +"!!");
							link.l1 = RandPhraseSimple("����!..", "��, �� ���� �����������...");
							link.l1.go = "fight";
							break;						
						}
					}

					// --> ������ � ��������
					if(rand(2) == 1 && CheckAttribute(pchar,"GenQuest.EncGirl") && CheckAttribute(pchar,"GenQuest.EncGirl.MeetSoldiers"))
					{
						if(sti(pchar.GenQuest.EncGirl.MeetSoldiers) == 1)	
						{
							dialog.text = "�-�, ����� ����! ���� " + pchar.GenQuest.EncGirl.name + " � ��� ���������� ����������� ��������! � ��� ��� �� ����������? � �� ���� ���������� ���! ��������� � �������, ���� ������ ����� ������������ � ������ ��� ����������. ";
							link.l1 = "���� �� �����?! �� ����������! �� � "+ GetSexPhrase("���������","��������") +" � �������� ������, ����� ��������. ����������! ��� �� ������ � ���� ����������?! ��� ������ ������ ����������� �������, ����� ������� ����� �����������! "+ GetSexPhrase("�����, ����� ���� ��������, ���� ������ � �� ���������� � ������� ����","�������, �� ����� �� ���� ��������...") +"!";
							link.l1.go = "GirlEnc_1";
						}
						if(sti(pchar.GenQuest.EncGirl.MeetSoldiers) == 2)	
						{
							dialog.text = "� ��� � ��, ���������. ���� ������! ���� ������ ���� �������� �� ���� ������, ����� ���� ��������� � ����� �������";
							link.l1 = "����������! � ���� ���� ���� ��� ���� � � ����� ������ �� ��������!.. �������, ������� ��, ����� ������ ����.";
							link.l1.go = "GirlEnc_2";						
						}
						DeleteAttribute(pchar,"GenQuest.EncGirl.MeetSoldiers");
					}
					// <-- ������ � ��������

					switch (rand(10))
					{
						case 0: ////////////////////////////////////////
							dialog.text = "����� ���������� ������ �� ��������� ��� ������� � ���������";
							link.l1 = "�������, ������! ��� �������.";
							link.l1.go = "exit";
						break;

						case 1:
							dialog.text = "���-�� �������? �� �������� �����-�� ����������?";
							link.l1 = "���, �� � �������. �� ���� ������������ ���������.";
							link.l1.go = "exit";
						break;

						case 2: ///////////////////////////////////////////
							dialog.text = "����� � ����� �� ������ ������ ���������. ������ ����� �������� ������ � ������ ���������.";
							link.l1 = "������, � ����� ��� � ��������.";
							link.l1.go = "exit";
						break;

						case 3:
							dialog.text = "��, �������-�� �����! � � ����� �����, ��� �������... ������ ��� �����.";
							link.l1 = RandPhraseSimple("�� ������������, ������. ���� �� �������.", "������ �� ������ ��������. � ����� ����������� ����� �� ��������.");
							link.l1.go = "exit";
						break;

						case 4: ///////////////////////////////////////////
							dialog.text = "������� ������� �����������, ���� ��������� ���������� - ��� �������� �� �������� �������, � �� ������ ������.";
							link.l1 = "�������, ������, �������� �������! ������ ���� �� � ����.";
							link.l1.go = "exit";
						break;

						case 5: ////////////////////////////////////////////
							dialog.text = "������������ �������, ����� � ���, ��� ������ �� ��� ������, ��� ����� ���������� �� �������. ��� ����� ������������� � ������� ������. ��� ������ ��� � ���������...";
							link.l1 = LinkRandPhrase("�� ���������� �� �����.", "��� �� ��������� �� ������?!", "����, ��� ���������. ������ ������ � ������� ������.");
							link.l1.go = "exit";
						break;

						case 6: ////////////////////////////////////////////
							dialog.text = RandPhraseSimple("�� ���������� ����, " + GetAddress_Form(NPChar) + ", � �� �����.", "���������, " + GetAddress_Form(NPChar) + ", �� ���������� �������� �� ������� ������.");
							link.l1 = "� ������ "+ GetSexPhrase("��������","���������") +", �� ������ �� �� �� �����. � �� ������, ��� �������.";
							link.l1.go = "exit";
						break;

						case 7:
							dialog.text = "��, " + GetAddress_Form(NPChar) + ", � ��� �� �������� ���� ������� ����, ����� ��������� �����? ������ �� �����.";
							link.l1 = "������ ���� ������. �����, ���� �� ������.";
							link.l1.go = "exit";
						break;

						case 8://///////////////////////////////////////////
							dialog.text = ""+ GetSexPhrase("�� ��� �� ������ �����, ������� �������� ������� ���� �� ������� ������. �� ������ �� ��� �� �������� ���������� ��������","��, ���������! ��� ������ ����, ����� ������� ������������ � ������ ������") +"?";
							link.l1 = RandPhraseSimple("�� ����� �������, ��� ���������� �� �����, � �� � �������.", "��� ���� �� �������� �������... � ����� �������.");
							link.l1.go = "exit";
						break;

						case 9://///////////////////////////////////////////
							dialog.text = ""+ GetSexPhrase("�� ��������� ������� ������! �� ������ ��������� �� ������? � ��� ���������� �������, ������� ������� � ������� ���������.","�, �� ���� �� �������������, �������, ��������� ������� ��������� � ���� ���������� ����� ����� �����, ��� ��!") +"";
							link.l1 = ""+ GetSexPhrase("��������������, ���� ������, �� � �������� ����������. ����������� ������ �� ��� ����","������� �� ����������, ������") +".";
							link.l1.go = "exit";
						break;

						case 10:
							dialog.text = "��� ����... � �� ��� ����� �����, ����� ����� ��������� � ������.";
							link.l1 = RandPhraseSimple("�� ��, ����� �� ���� ����������.", "���������� ������ ����� �� �����.");
							link.l1.go = "exit";
						break;
					}
					link.l3 = "������. � ��� ��� �������� "+ GetSexPhrase("�����","������") +"...";
					link.l3.go = "quests";//(���������� � ���� ������)						
				}
			}
		break;
		//============================== ���� �� �������� ��� ������������� =========================
		case "PegYou":
			dialog.text = RandPhraseSimple("������� ���, ��� ��� �����... �����-�� ������� � �����������, "+ GetSexPhrase("��������","���������") +", ��� ����������...", "��, ���-�� ������������ ���, ��� �� �� "+ GetSexPhrase("���","��") +", �� ���� ���� �������... ���������� ������ ������, " + GetAddress_Form(npchar) + ", � �������� �� ���� ��� ����������� ���������������!");
			link.l1 = RandPhraseSimple("��� �� �� ���!", "����� ��������, � �������...");
			link.l1.go = "fight";
			if (sti(pchar.questTemp.stels.landSolder) != GetDataDay())
			{
				AddCharacterExpToSkill(pchar, SKILL_SNEAK, 40);
				pchar.questTemp.stels.landSolder = GetDataDay();
			}
		break;
		
		case "NotPegYou":
			dialog.text = RandPhraseSimple("�-�-�, ����... ��� � �������, �� ������ ����, " + GetAddress_Form(pchar) + ".", "���-�� � ������� �������� � �������... ��� � �������, " + GetAddress_Form(pchar) + ", ����� ��������.");
			link.l1 = "���-��!";
			link.l1.go = "exit";
			if (sti(pchar.questTemp.stels.landSolder) != GetDataDay())
			{
				AddCharacterExpToSkill(pchar, SKILL_SNEAK, 80);
				pchar.questTemp.stels.landSolder = GetDataDay();
			}
		break;
		
		case "vincento":
			dialog.text = RandPhraseSimple("�-�-�, ����... ��� � �������, �� ������ ����, " + GetAddress_Form(pchar) + ".", "���������... ��� � �������, " + GetAddress_Form(pchar) + ", ����� ��������.");
			link.l1 = "���-��!";
			link.l1.go = "exit";
		break;
		
		case "LicenceOk":
			iTemp = GetDaysContinueNationLicence(HOLLAND);
			if (ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -12)
			{
				dialog.text = "������ ��������, ����� ��������! ������� � ����� ��� ����� ��������! �� ���� �������� ��������� � ������ �������, �������! ��, ������ �� �� ������! ������ ���!";
				link.l1 = RandPhraseSimple("����!..", "��, �� ���� �����������...");
				link.l1.go = "fight";	
				TakeNationLicence(HOLLAND);
				break;
			}
			if (pchar.location != "Minentown_town" && findsubstr(pchar.location.from_sea, "_town" , 0) == -1) //���� �������� �� � ������ 300912
			{
				dialog.text = "�� ������� ���� ���������? ��������� �������� - �� ���? ��� ��� �������? ��� ��� ����� ������������� - � �������� ��� ��������� �� ���������. ������ ������ � �������� �� ����!";
				link.l1 = RandPhraseSimple("��� �� �� ���!", "����� ��������, � �������...");
				link.l1.go = "fight";	
				TakeNationLicence(HOLLAND);
				break;
			}
			if (iTemp == -1)
			{
				dialog.text = "���� �������� �������� �������, ��� ��� ���������� � ������� ���������������. ������ ������ � �������� �� ���� ��� ����������� ��������������!";
				link.l1 = RandPhraseSimple("��� �� �� ���!", "����� ��������, � �������...");
				link.l1.go = "fight";	
				TakeNationLicence(HOLLAND);
				break;
			}
			if (iTemp == 0)
			{
				dialog.text = "��, ��� �����. ������ ������� ���� ��������, ��� ���� �������� ����� �������� ������� ��������. � ������� ��� ������, �� ��� ����� ����� ������� �������� �� ��������������.";
				link.l1 = "�������, � ���������� ����� ��� ������ �� �����������.";
				link.l1.go = "exit";			
			}
			if (iTemp > 0 && iTemp <= 10)
			{
				dialog.text = "��, ��� �����. ������ ������� ���� ��������, ��� ���� �������� ����� �������� ������ �������� - ��� ������������� ��� ������ " + FindRussianDaysString(iTemp) + ". ��� ��� ������ � ����, " + GetAddress_Form(npchar) + ".";
				link.l1 = "�������, � ���������� ����� ��� ������ �� �����������.";
				link.l1.go = "exit";			
			}
			if (iTemp > 10)
			{
				dialog.text = LinkRandPhrase("�� ��� ��, ����� ������, ���� �������� ��������� ��� " + FindRussianDaysString(iTemp) + ". �� ������ ������.", "��� ����, "+GetAddress_Form(npchar)+". �� ������ �������� ��������� � �����, ���� �������� ��������� ��� " + FindRussianDaysString(iTemp) + ". ����� �������� �� ������������.", "��� � �������, " + GetAddress_Form(npchar) + ", �� ���� ��� �����������.");
				link.l1 = RandPhraseSimple("�������. ����� ��������.", "�������, ������.");
				link.l1.go = "exit";
			}
		break;
		//============================== ���� ����� ���� ����� =========================
		case "PortRoyal_Mayak":
			dialog.text = RandPhraseSimple("��, ��������, ������ ������ �� ������ �� �����.", "���� - ����� ������ ������ ��� ������. ���� ���������!");
			link.l1 = RandPhraseSimple("������, �� ���������.", "��� ����� � �������.");
			link.l1.go = "exit";
			NextDiag.TempNode = "PortRoyal_Mayak";
		break;
		case "PortRoyal_Gans":
			dialog.text = LinkRandPhrase("�� ����� ������ ����� ������ - ��� ������� ������!", "������ � ������� ����������� ��� ������������� ��������!", "���� � ������, ��� �� ���������� ����� ������ - ���� �����!");
			link.l1 = RandPhraseSimple("� ����� ����.", "������, � ��� �����.");
			link.l1.go = "exit";
			NextDiag.TempNode = "PortRoyal_Gans";
		break;

		// --> ��������� "������ � ��������"
		case "GirlEnc_1":
			dialog.text = "� ��, �������, ��� "+ GetSexPhrase("�����","�����") +" ������? �� "+ GetSexPhrase("�����������","����������") +" �� ����� ���������� �� �� ��������� �������?";
			link.l1 = "�� ���� "+ GetSexPhrase("'������������'","'�����������'") +" ������?! �� ������ ����������?! � ��, ������� ���� �� ��������!";
			link.l1.go = "GirlEnc_11";
			link.l2 = "�� �, ����������, ������ ��� � ��� "+ GetSexPhrase("������������","�������������") +"...";
			link.l2.go = "GirlEnc_12";
		break;

		case "GirlEnc_11":
			dialog.text = ""+ GetSexPhrase("������","��������") +", ��� ��������� � ��������� � ����������� � �������. � �������� �� �������, ��� ������� ��� ��������.";
			link.l1 = "��� ������ � ��������...";
			link.l1.go = "GirlEnc_11End";
		break;

		case "GirlEnc_11End":
			DialogExit();
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			sld = CharacterFromID("CangGirl");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "OpenTheDoors", -1.0);
			sld.lifeDay = 0;
			DeleteAttribute(pchar, "GenQuest.EncGirl");
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");		
		break;
		
		case "GirlEnc_12":
			dialog.text = "��? �� � ����� ������� ���������. �� ����� ���... ������� ���� ������������ � ������� ����� '�'";
			link.l1 = "�������, ������� �����������. ��� �� ���� ���� ��� �����������������...";
			link.l1.go = "GirlEnc_12End";		
		break;		
		
		case "GirlEnc_12End":
			pchar.money = sti(pchar.money) - makeint(sti(pchar.money)/20);
			NextDiag.CurrentNode = NextDiag.TempNode;
			sld = CharacterFromID("CangGirl");
			LAi_SetActorType(sld);
			LAi_ActorStay(sld);
			LAi_CharacterDisableDialog(sld);
			sld.lifeDay = 0;
			DeleteAttribute(pchar, "GenQuest.EncGirl");
			DialogExit();
		break;
		
		case "GirlEnc_2":
			dialog.text = ""+ GetSexPhrase("������","��������") +", ��� ��������� ��������� ��� ����� � ��������� � ����.";
			link.l1 = "��, �� �����������, ��� ���������.";
			link.l1.go = "GirlEnc_2End";
			link.l2 = "�� ��������. � ��� ���� � �����.";
			link.l2.go = "GirlEnc_21";
		break;
		
		case "GirlEnc_2End":
			NextDiag.CurrentNode = NextDiag.TempNode;
			sld = CharacterFromID("CangGirl");
			LAi_SetActorType(sld);
			LAi_ActorStay(sld);
			LAi_CharacterDisableDialog(sld);
			sld.lifeDay = 0;	
			ChangeCharacterComplexReputation(pchar,"nobility", -2);
			AddQuestRecord("JungleGirl", "11");	
			AddQuestUserData("JungleGirl", "sSex", GetSexPhrase("","�"));	
			CloseQuestHeader("JungleGirl");
			DeleteAttribute(pchar, "GenQuest.EncGirl");
			DialogExit();			
		break;
		
		case "GirlEnc_21":
			ChangeCharacterComplexReputation(pchar,"nobility", 2);
			if(GetSummonSkillFromName(pchar, SKILL_LEADERSHIP) < rand(100))
			{
				dialog.text = "�������, � ��� ���� ������ � �� �������� �������, ��� ������� ��� ��������.";
				link.l1 = "��� ������ � ��������...";
				link.l1.go = "GirlEnc_21End";
			}
			else
			{
				dialog.text = "��, "+ GetSexPhrase("�����������","�����������") +". Ÿ ������ ������ ����� ��������� ����, ��� ����� ������..";
				link.l1 = "�� ������������, ���� ������� ��� �������.";
				link.l1.go = "exit";			 
			}
		break;
		
		case "GirlEnc_21End":
			DialogExit();
			AddQuestRecord("JungleGirl", "12");
			AddQuestUserData("JungleGirl","sCity", XI_ConvertString("Colony" + pchar.GenQuest.EncGirl.city));
			CloseQuestHeader("JungleGirl");
			ChangeCharacterComplexReputation(pchar,"nobility", -1);
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(NPChar, Pchar);
			sld = CharacterFromID("CangGirl");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "OpenTheDoors", -1.0);
			sld.lifeDay = 0;
			DeleteAttribute(pchar, "GenQuest.EncGirl");
			if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			AddDialogExitQuest("MainHeroFightModeOn");				
		break;
		// <-- ��������� "������ � ��������"
		
		//��������� �� ����������� ������
		case "SoldierNotBlade":
			dialog.text = LinkRandPhrase("���� �� ������� ������������?! ���������� ������� ������!", "���������� ��� ���������� ������ ������!", "��, " + GetAddress_Form(NPChar) + ", �� ������� �����! ������� ������.");
			link.l1 = LinkRandPhrase("������, ������...", "��� "+ GetSexPhrase("�����","������") +".", "��� �������...");
			link.l1.go = "exit";
			link.l2 = LinkRandPhrase("����� � ���!", "������ ���� ��� � ����!", "�����, ����� ����� �����.");
			link.l2.go = "fight";
			npchar.greeting = "soldier_common";
			NextDiag.TempNode = "First Time";
		break;

		case "pirate_fight":
			DialogExit();
			SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			LAi_group_Attack(NPChar, Pchar);
			DoQuestFunctionDelay("TownPirate_battle", 0.5);
		break;
	}
}