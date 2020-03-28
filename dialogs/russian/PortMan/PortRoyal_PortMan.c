// ������ �� �������
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("����� �������?", "��� ��� ������, " + GetAddress_Form(NPChar) + "?"), "������ ������� �� �������� ������ ��� ������ " + GetAddress_Form(NPChar) + "...", "� ������� ����� ��� �� ��� ������ ��� �������� � �����-�� �������...",
                          "����������, ���� �� �� �� ����� �����, �� �� ����� ���� ��������� ��������.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("� ���������"+ GetSexPhrase("","�") +"...", "������ ��� �� � ��� ��������"), "��, ���-�� � ������� ���� �����...",
                      "�� ��, ������������� � ������ ���...", "��������, �� �������� ���� ���� ������ �� ����������.", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			
			if (pchar.questTemp.Slavetrader == "FindRatJamaica")
            {
                link.l1 = "������ ����. � ��� �� ��������� ������� ������� �������, ��������� �� ����� �����? � ���� ������ �� ����� '" + pchar.questTemp.Slavetrader.ShipName + "'.";
                link.l1.go = "Jamaica_ratPP_1";
            }
			
		break;
		
		case "Jamaica_ratPP_1":
			dialog.text = NPCStringReactionRepeat("���. ������� ������� �� ���������, � ������ '" + pchar.questTemp.Slavetrader.ShipName + "' � ���� ����-����� �� �������.", "�� ��� "+ GetSexPhrase("����������","����������") +" �� ����, � ��� �������.", "� �� ������ ����, �� ��� "+ GetSexPhrase("����������","����������") +" �� ���� ��������.", "� ����� ��� �� ������ ��� ��������!", "block", 0, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("����. ����� ������ ������...", "��, �� ��...", "��, �����, "+ GetSexPhrase("���������","����������") +"...", "��������, " + npchar.name + "...", npchar, Dialog.CurrentNode);
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // ���� ���-�� ����� ������ switch  �� return �� ������ ������� �����
}

