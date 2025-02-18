// ��������� �������
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "�� ���-�� �����?";
			link.l1 = "�� ���, ������.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		case "portroyal":
			dialog.text = "��, ����� �� ���! ��� ��� �������������� � ����-�����! �������, �� ���� �� ������?";
			link.l1 = "�-�-�... ������� - ������ �������? ���� �������?";
			link.l1.go = "portroyal_1";
		break;
		
		case "portroyal_1":
			dialog.text = "�� �����... ��������� �������.";
			link.l1 = "��, ��������, ������. ��, � ��� ��������. �� ����������� �� ���� ������, � �����. � ���� ��� ��� ��� �������, ������ ��������. � ����� ��� ������� �� �����.";
			link.l1.go = "portroyal_2";
		break;
		
		case "portroyal_2":
			dialog.text = "� �����, �������! �� �� �������� ����� ���� - �� ������ ����� ������� � ����������� ������. � �� ������� - ���������� ���� ����� �� �������, �� ������� �� ���� ��������...";
			link.l1 = "�������������� ���� ������, ��� ��� ��������������� '����������' � ���� ������ �������� ��� ������ �� ������� �� ���� �������� �� ����� ��� ����� ��������� �����. ��� �������� �����, ��� �����?";
			link.l1.go = "portroyal_3";
		break;
		
		case "portroyal_3":
			dialog.text = "��. �� ���������� ������� � ��������� ��� ������ � ����� �����-�� ������. ��� ���������� ���. � �������, ���� �� ������ - ��� ��� ��������� ��������� ���� ���� � ��������?";
			link.l1 = "��� ����� ����� ��������� �� ���� � ���-����� ����� ������� ����� � � ����� ����� � �������� � ����. ����� �� ����� �� ��� � ����� � ������� �����. ��, � � ����� ���������� �� ����� ������� ��� � ��������. ����� ������ �� �������� ���������.";
			link.l1.go = "portroyal_4";
		break;
		
		case "portroyal_4":
			dialog.text = "�� ��, � �������� �������� ����� �� ���� � ��� ������ ������ ���������� - ������ ������ � ������������ �������...";
			link.l1 = "��, � ���� ���-��� ������ � �������� ������� ���������. ������� ��� � ���������.";
			link.l1.go = "portroyal_5";
		break;
		
		case "portroyal_5":
			dialog.text = "�������, ��������. ������ � ��������� ����� �� ����� ������ ����, ����� ���� �� ������� �����, ��� �� ������ �� ������, ���� � �������� ���������... ��� �������� � ����-����� - �� ������� �� ��������������� ������. ��� � ������, �������\n������� �� ���, �� �������� � ���������� ��������-���������: ��������� �������� ��� ������! ��� ��� ����������� ��� ��� �����, �������� �����, � � ���� ���� � ��� ����������. �������� �� ��� � �����, �������� ��������� ��������� �����, ���������. � ������!";
			link.l1 = "��... ���������, ��...";
			link.l1.go = "portroyal_6";
		break;
		
		case "portroyal_6":
			dialog.text = "�� �������, �������: �������� ���� ����. � ���� � ������� �������, ����� �� ������ ����� ��������: � ������ ������� ����� ��� ���������. ���������� ������ ��� ������ - ��������� ���� � ������, ��-��! ������, ������? �� ��������!";
			link.l1 = "���������!";
			link.l1.go = "portroyal_7";
		break;
		
		case "portroyal_7":
			dialog.text = "�������. ����� �� ����!";
			link.l1 = "...";
			link.l1.go = "portroyal_8";
		break;
		
		case "portroyal_8":
			DialogExit();
			NextDiag.CurrentNode = "portroyal_9";
			LAi_SetActorType(pchar);
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload6_back", "PortRoyal_store", "goto", "goto2", "GuardOT_ArchyIntoStore", -1);
			LAi_ActorFollow(pchar, npchar, "", -1);
		break;
		
		case "portroyal_9":
			LAi_SetSitType(Pchar);
			dialog.text = "������, ��� ������ ���, �������������... � ��� � ��������� � �����! ���������, �������!";
			link.l1 = "��, ������� ������ �� ��������� ������� � �������� ����������!";
			link.l1.go = "portroyal_10";
		break;
		
		case "portroyal_10":
			dialog.text = "� �������������!.. ��! � ��� �� ����� ������� �� ������, �, ����� �� ���?";
			link.l1 = "������������ �������... ��� �����. � � ��� �� ����, ��� �������. ��� �������, ������ � �������� ��� ������.";
			link.l1.go = "portroyal_11";
		break;
		
		case "portroyal_11":
			dialog.text = "��, �������� �������... ���� � � ������ ����� �����. � ��� ����� �� ���� ��������� ������, � �������� ���� ������ ����... ���-��, ��� � ����� - ������ �������� �������.";
			link.l1 = "���������! ��� �� ������ �����?";
			link.l1.go = "portroyal_12";
		break;
		
		case "portroyal_12":
			dialog.text = "����� - ��� ��������� ����, �� ������� � ��� ��� � ��� ������� ������, ����� � ����� ������ �������� ��� ���������... � ���� �������������� ���������� � ���������� ��������� � ����� ������������, � �� ������� ��� ������. ����� � ��������� ���������, � ���� ��� ���� �����\n��, � ��� � ��� ��������� ���� �� ��� ������� ������ ���������, ���������� ��������. � ��� �� ���� �� �����. �� �������, ��� �����, �� ��� ������� ��� �� �����, ��� ����! ������ ������� ������� �� ���������� � ��������� ����� �������� ���� �� ����, ��������� � ����� ������� � ����� � ���� �����\n��������� ���, ��� ���������� �������, � ���� ������ ����� �� ������ ������������ ����� ������������. ���� ������ ��� �������, �� ��� ������ �� ���� ��, �������� � �� �������. � ��� ����� ��� ��� ���� ������� �������� � ������-�� ���������� �������\n������� � ���� �� ������� - � ����� �� ���� ��� ����! ������ ��������� � ������-������ ���������... � � ������ ��� ��� ����, ������������ ��� ���������. ��� � ���� �� ��������� �������� - ��� �� �����.";
			link.l1 = "�� ������� ��� ���� �� ����������� �������?";
			link.l1.go = "portroyal_13";
		break;
		
		case "portroyal_13":
			dialog.text = "��� �����, ���� ��� ����! ������, ��� ��� ���� ������� ����. ������� � �������, ���������, ����� � �������. � ��� � ������ ��� - �������� ������. ������ � ���� �� ���� - ��������� ������, ����� � ���, ��� ������! ���-��! �����, �����, �������! � � ����� ����...";
			link.l1 = "�� ��, ���������� ���������.";
			link.l1.go = "portroyal_14";
		break;
		
		case "portroyal_14":
			dialog.text = "���! ������ ��� � � ������, ����� ������ ������ ��� �� ����� ����� ������ ����: '������� ����, ���� ��������� ����������, �� � �� �����������!' � ������, ��� ���� ������, �������?";
			link.l1 = "���������� ���� �������?";
			link.l1.go = "portroyal_15";
		break;
		
		case "portroyal_15":
			dialog.text = "���! ���� ���� ����! ����, ���� � ������ � �����! � ������ ���� ������, ���������� ������ ��� ������ � ��� ������������: � ������� ����������� �� ����� ������ � ���������� ������������! ��� ����� ���� ���������� �������������� � ������ �������. � ������, ��� � ������ ���� �����? �� ���������, ���������, �������!\n� ������ �: '����, ����� �� ����� � ���, ���� ����� ���������, � ������� ������ ���� ��� �����������'. ���-��! � ����� ������� ����� �������� �� �����, � ������: ��� �������� ���� �� ������ ������ � ���� ������ � �����!";
			link.l1 = "�� ������ �������, ������ �������. �� ������ ��� �� �������� � ����� �������� ������ ���� ���-�� �������...";
			link.l1.go = "portroyal_16";
		break;
		
		case "portroyal_16":
			dialog.text = "��, ������� ������� �� ��� ������� � ���������! ��-��! ��, ���� ���, ������ � ���������, � ������ �����, �� ��, ��� �������� � ���������� ������. ���������... ��� ���, � ��� �? �, ��! � ��������, � � �������� ���� �������� ���. � ��� � ����� ������� � ������ ���� ����� ���� � ����� ����������. ����� ����� ������ ���� � �������, � ��������� ���� ��������� � �����\n������ �� ����� � ���� ��� ��� �� �����, � ����� �� ������������ �� ������� �����, � ����-�����, � ����������� ���, ���� � ������ �������, � ��������� �� ��� ���� ������ ���������\n� ������� ���� ���, ��� ��������� �� ���� �� ��������� �� ������, � �� ����� ���������� ���. �� ������ ��������� ��� � �������� ������� ��������.";
			link.l1 = "��� ����������, ������ �������� ������ ��� � �������? �� ��� �� �� ����� ���? �� �� �������, ���...";
			link.l1.go = "portroyal_17";
		break;
		
		case "portroyal_17":
			dialog.text = "��, ��, ������ �� ��������� �� �� ����� �����. �� ����� - ��� �� ������� �����! �� ����� ��! � �� ������� ���� ������ ������ � ���� ����, �� ��� � ��� ���������� �� ���� �����. ��...";
			link.l1 = "��� �������� ������ � ������� ���������? �� ������ ����� �� ������� �����?";
			link.l1.go = "portroyal_18";
		break;
		
		case "portroyal_18":
			dialog.text = "������ � ���� ��������. ����� �����, �������, � ���� �� � ��� ��������� ����. ���� ��� ��� ������-��? ���, � ���� � ����� �� ����� ���� ����, ��� ���� �� �� ������� ���� �� ��������� ������, ��-��! ������, � ������: ���������!";
			link.l1 = "���... (����) �������, ������ �������, � ��� ��� ������, ��� �� ������ ���� ��������� �� �����������. ��� ���, ��� ������ ����?";
			link.l1.go = "portroyal_19";
		break;
		
		case "portroyal_19":
			dialog.text = "��� ��� ����� ������? ������� - ���� ����� �����? �������� ����� �� ����. �� ������ � ����� �� �������: ������ ����� ��� ����������������� � � ����������� � ���������, ���� ��� ��������, � ����� �� ���� ������. ��-�� ���� ������ ���� ������� �������� ��������, �� � � ���... ��, ����� �� ����� ����������\n� ������ ������� ��� ���� �����, � ������� ������ �� ��������� ����� ������ � �������. ���, � ����� ������ �� ��������, � ������!";
			link.l1 = "����������, ���������, � �� ������� �� ������� ��� �������� �� ����� ������ ������?";
			link.l1.go = "portroyal_20";
		break;
		
		case "portroyal_20":
			dialog.text = "������ ��� ����� ��� ���. � ��� ��?";
			link.l1 = "�� ���... �������� ����������� � ��������. ��� �� ������� - ��� � �� ����� � ���.";
			link.l1.go = "portroyal_21";
		break;
		
		case "portroyal_21":
			dialog.text = "��� ������ - �� �����! ������� ����� ��������� ��� ���� ��������-������! ��! ��� �����, �������� ��� ����� � ���������...";
			link.l1 = "...";
			link.l1.go = "portroyal_22";
		break;
		
		case "portroyal_22":
			DialogExit();
			AddDialogExitQuest("GuardOT_MCOutFromArchyRoom");
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}