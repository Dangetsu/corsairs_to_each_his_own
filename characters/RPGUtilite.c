// 11.08.05 Boal ������ ��� ����� ��� ������� S.P.E.C.I.A.L
// ����� ��� ������������� � .��� ������ (������ SKILLCHANGER)

#define MAX_ACHIEVMENTS		71

// ����� �����
int GetCharacterRankRate(ref _refCharacter)
{
    return 35 - GetCharacterSPECIALSimple(_refCharacter, SPECIAL_I);
}
int GetCharacterRankRateCur(ref _refCharacter)
{
    if(!CheckAttribute(_refCharacter, "rank_exp"))
	{
		_refCharacter.rank_exp = 0;
	}
    return sti(_refCharacter.rank_exp);
}
// ������� ��
int GetCharacterAddHPValue(ref _refCharacter)
{
	// --> ������ ������� �����
	int Ers = GetCharacterSPECIALSimple(_refCharacter, SPECIAL_E);
	if (GetCharacterEquipByGroup(_refCharacter, CIRASS_ITEM_TYPE) == "underwater") Ers = Ers+2;
	if (GetCharacterEquipByGroup(_refCharacter, CIRASS_ITEM_TYPE) == "cirass1") Ers = Ers+1;
	if (GetCharacterEquipByGroup(_refCharacter, CIRASS_ITEM_TYPE) == "cirass2") Ers = Ers+1;
	if (GetCharacterEquipByGroup(_refCharacter, CIRASS_ITEM_TYPE) == "cirass4") Ers = Ers+1;
	// <-- ������ ������� �����

	int ret = makeint(2 + Ers * 0.55 + 0.5);
  //  int ret = makeint(2 + GetCharacterSPECIALSimple(_refCharacter, SPECIAL_E) * 0.55 + 0.5);

	if (CheckCharacterPerk(_refCharacter, "HPPlus"))
	{
		ret = ret + 1;
		if(CheckAttribute(_refCharacter, "chr_ai.hp_max_back"))
		{
			_refCharacter.chr_ai.hp_max_back = stf(_refCharacter.chr_ai.hp_max_back) + ret;
		}
	}
	else
	{
		if(CheckAttribute(_refCharacter, "chr_ai.hp_max_back"))
		{
			_refCharacter.chr_ai.hp_max_back = stf(_refCharacter.chr_ai.hp_max_back) + ret;
		}
	}
	return ret;
}

int GetCharacterBaseHPValue(ref _refCharacter)
{
	int ret = makeint(30.0 + GetCharacterSPECIALSimple(_refCharacter, SPECIAL_S)*GetCharacterSPECIALSimple(_refCharacter, SPECIAL_E)*0.5);
	return ret;
}

float GetCharacterMaxEnergyValue(ref _refCharacter)
{
    float ret = (30.0 + GetCharacterSPECIAL(_refCharacter, SPECIAL_A)*10);
	if (CheckAttribute(_refCharacter, "PerkValue.EnergyPlus"))
	{
  		ret = ret + stf(_refCharacter.PerkValue.EnergyPlus);
	}
	if(IsEquipCharacterByArtefact(_refCharacter, "indian_7"))
	{
		ret = ret + makeint(1500 / ret);
	}
	return ret;
}

float GetCharacterMaxEnergyABSValue(ref _refCharacter)
{
    // �������� ������ to_do
	float ret = (30.0 + GetCharacterSPECIALSimple(_refCharacter, SPECIAL_A)*10);
	if (CheckAttribute(_refCharacter, "PerkValue.EnergyPlus"))
	{
  		ret = ret + stf(_refCharacter.PerkValue.EnergyPlus);
	}
	return ret;
}

void SetEnergyToCharacter(ref _refCharacter)
{
	_refCharacter.chr_ai.energyMax = GetCharacterMaxEnergyValue(_refCharacter);
	if (!CheckAttribute(_refCharacter, "chr_ai.energy"))
	{
		_refCharacter.chr_ai.energy    = _refCharacter.chr_ai.energyMax;
	}
	else
	{
	    if (sti(_refCharacter.chr_ai.energy) > sti(_refCharacter.chr_ai.energyMax))
	    {
	        _refCharacter.chr_ai.energy    = _refCharacter.chr_ai.energyMax;
	    }
	}
}

int GetCharacterMaxOfficersQty(ref _refCharacter)
{
    return GetCharacterSPECIAL(_refCharacter, SPECIAL_C)*2;
}

int AddCharacterExp(ref _refCharacter,int _exp)
{
	int retVal = false;
	return retVal;
}

int CalculateExperienceFromRank(int _Rank)
{
	if(_Rank<2) return 0;
	int retVal = 100;
	return retVal;
}

int GetFreePoints_SelfRate(ref _chref)
{
    return 40 - GetCharacterSPECIALSimple(_chref, SPECIAL_I);
}

int GetFreePoints_ShipRate(ref _chref)
{
    return 40 - GetCharacterSPECIALSimple(_chref, SPECIAL_I);
}
/////////////////////////////////////////////////////////////////////////

void SetSelfSkill(ref _refCharacter, int _fl, int _f, int _fh, int _p, int _fr)
{
    _refCharacter.Skill.FencingL      = _fl;
    _refCharacter.Skill.FencingS      = _f;
    _refCharacter.Skill.FencingH      = _fh;
    _refCharacter.Skill.Pistol        = _p;
    _refCharacter.Skill.Fortune       = _fr;
//    _refCharacter.Skill.Leadership = _ld;
//    _refCharacter.Skill.Sneak      = _sn;
}

void SetShipSkill(ref _refCharacter, int _ld, int _cr, int _ac, int _cn, int _sl, int _re, int _gr, int _de, int _sn)
{
    _refCharacter.Skill.Leadership = _ld;
    _refCharacter.Skill.Commerce   = _cr;
    _refCharacter.Skill.Accuracy   = _ac;
    _refCharacter.Skill.Cannons    = _cn;
    _refCharacter.Skill.Sailing    = _sl;
    _refCharacter.Skill.Repair     = _re;
    _refCharacter.Skill.Grappling  = _gr;
    _refCharacter.Skill.Defence    = _de;
    _refCharacter.Skill.Sneak      = _sn;
}

void SetSPECIAL(ref _refCharacter, int _s, int _p, int _e, int _c, int _i, int _a, int _l)
{
    _refCharacter.SPECIAL.Strength   = _s;
    _refCharacter.SPECIAL.Perception = _p;
    _refCharacter.SPECIAL.Endurance  = _e;
    _refCharacter.SPECIAL.Charisma   = _c;
    _refCharacter.SPECIAL.Intellect  = _i;
    _refCharacter.SPECIAL.Agility    = _a;
    _refCharacter.SPECIAL.Luck       = _l;
}

void SetRandSPECIAL(ref _refCharacter)
{
    SetSPECIAL(_refCharacter,
               (3 + rand(7)),
               (3 + rand(7)),
               (3 + rand(7)),
               (2 + rand(8)),
               (4 + rand(6)),
               (4 + rand(6)),
               (2 + rand(8)));
}

/// ������ ������ �� �������
int ApplayNavyPenalty(ref _refCharacter, string skillName, int sumSkill)
{
    if (IsCompanion(_refCharacter) && GetRemovable(_refCharacter))//����� ����� ��� ����������� ���� sti(_refCharacter.index) == GetMainCharacterIndex()) // ������ ��� ��������, ���� �� ��������� ��� ����
    {
        int sailSkill;
        // ����� ������ ���������
        sailSkill = GetSummonSkillFromNameSimple(_refCharacter, SKILL_SAILING);
        
        int shipClass = GetCharacterShipClass(_refCharacter);
        int needSkill = GetShipClassNavySkill(shipClass);
		if (CheckAttribute(_refCharacter, "NoNavyPenalty")) needSkill = 1;

        if (sailSkill < needSkill)
        {
			sailSkill = makeint((needSkill - sailSkill)/10.0 + 0.9); // ���������� �� ��� ������
			sumSkill = sumSkill - sailSkill;
	        if (sumSkill < 1) sumSkill = 1;
        }
    }
    return  sumSkill;
}
// �������� � �����
int ApplayNavyPenaltyToSkill(ref _refCharacter, string skillName, int sumSkill)
{
    if (IsCompanion(_refCharacter) && GetRemovable(_refCharacter))//����� ����� ��� ����������� ���� sti(_refCharacter.index) == GetMainCharacterIndex()) // ������ ��� ��������, ���� �� ��������� ��� ����
    {
        int sailSkill;

        // ����� ������ ���������
        sailSkill = GetSummonSkillFromNameSimple(_refCharacter, SKILL_SAILING);
        int shipClass = GetCharacterShipClass(_refCharacter);
        int needSkill = GetShipClassNavySkill(shipClass);
		if (CheckAttribute(_refCharacter, "NoNavyPenalty")) needSkill = 1;

        if (sailSkill < needSkill)
        {
			sailSkill = needSkill - sailSkill;
			sumSkill = sumSkill - sailSkill;
	        if (sumSkill < 1) sumSkill = 1;
        }
    }
    return  sumSkill;
}
// � �������� � ������ +1
int GetCharacterSPECIAL(ref _refCharacter, string skillName)
{
    int skillN;

	skillN = GetCharacterSPECIALSimple(_refCharacter, skillName);

 	skillN = ApplayNavyPenalty(_refCharacter, skillName, skillN);
	
    return skillN;
}

int GetCharacterSPECIALSimple(ref _refCharacter, string skillName)
{
	if (!CheckAttribute(_refCharacter,"SPECIAL."+skillName) )
    {
        return 3;
    }
	int skillN = sti(_refCharacter.SPECIAL.(skillName));
    // Health
    if (sti(_refCharacter.index) == GetMainCharacterIndex() && MOD_SKILL_ENEMY_RATE > 1) // �� ������
    {
        skillN = skillN + GetHealthNum(_refCharacter) - 6; // max -5
    }
    
	skillN += ApplySPECIALCirassPenalty(_refCharacter, skillName);
	skillN += ApplySPECIALMangarosaPotion(_refCharacter, skillName); // Jason
	
	if(CheckAttribute(_refCharacter, "GenQuest.EnergyPenalty")) 
	{
		skillN += ApplySPECIALQuestPenalty(_refCharacter, skillName); // Jason
	}
	
	if (skillN <= 1) skillN = 1;
	if( skillN > SPECIAL_MAX ) skillN = SPECIAL_MAX;

	return skillN;
}


void InitRPGType()
{
    NullCharacter.SPECIALType.Strength = true;
    NullCharacter.SPECIALType.Perception = true;
    NullCharacter.SPECIALType.Endurance = true;
    NullCharacter.SPECIALType.Charisma = true;
    NullCharacter.SPECIALType.Intellect = true;
    NullCharacter.SPECIALType.Agility = true;
    NullCharacter.SPECIALType.Luck = true;
    
    NullCharacter.SelfType.Leadership = true;
	NullCharacter.SelfType.FencingL = true;
    NullCharacter.SelfType.FencingS = true;
    NullCharacter.SelfType.FencingH = true;
    NullCharacter.SelfType.Pistol = true;
    NullCharacter.SelfType.Fortune = true;
    NullCharacter.SelfType.Sneak = true;
    // ��������� �����������
    NullCharacter.ShipType.Commerce = true;
    NullCharacter.ShipType.Accuracy = true;
    NullCharacter.ShipType.Cannons = true;
    NullCharacter.ShipType.Sailing = true;
    NullCharacter.ShipType.Repair = true;
    NullCharacter.ShipType.Grappling = true;
    NullCharacter.ShipType.Defence = true;

}

bool isSPECIALTypeSkill(string _param)
{
    return CheckAttribute(&NullCharacter, "SPECIALType." + _param);
}

bool isShipTypeSkill(string _param)
{
    return CheckAttribute(&NullCharacter, "ShipType." + _param);
}
bool isSelfTypeSkill(string _param)
{
    return CheckAttribute(&NullCharacter, "SelfType." + _param);
}

string GetRPGText(string _param)
{
    int    idLngFile = -1;
    string totalInfo;

    idLngFile = LanguageOpenFile("RPGDescribe.txt");
    totalInfo = LanguageConvertString(idLngFile, _param);
    LanguageCloseFile(idLngFile);

    return totalInfo;
}

string GetSkillNameByIdx(int idx)
{
    string ret = "";
    
    switch (idx)
    {
        case 1:    ret = SKILL_F_LIGHT;   break;
        case 2:    ret = SKILL_FENCING;   break;
        case 3:    ret = SKILL_F_HEAVY;   break;
        case 4:    ret = SKILL_PISTOL;    break;
        case 5:    ret = SKILL_FORTUNE;   break;
        
        case 6:    ret = SKILL_LEADERSHIP; break;
        case 7:    ret = SKILL_COMMERCE;   break;
        case 8:    ret = SKILL_ACCURACY;   break;
        case 9:    ret = SKILL_CANNONS;    break;
        case 10:   ret = SKILL_SAILING;    break;
        case 11:   ret = SKILL_REPAIR;     break;
        case 12:   ret = SKILL_GRAPPLING;  break;
        case 13:   ret = SKILL_DEFENCE;    break;
        case 14:   ret = SKILL_SNEAK;      break;
        
        case 15:   ret = SPECIAL_S;   break;
        case 16:   ret = SPECIAL_P;   break;
        case 17:   ret = SPECIAL_A;   break;
        case 18:   ret = SPECIAL_C;   break;
        case 19:   ret = SPECIAL_I;   break;
        case 20:   ret = SPECIAL_E;   break;
        case 21:   ret = SPECIAL_L;   break;
    }
    return ret;
}
//  _type   ShipType SelfType  SPECIALType
string GetSkillNameByTRIdx(string _type, int idx)
{
    string ret = "";

	switch (_type)
	{
		case "SelfType" :
		    switch (idx)
		    {
                case 1:    ret = SKILL_LEADERSHIP; break;
				case 2:    ret = SKILL_F_LIGHT;   break;
		        case 3:    ret = SKILL_FENCING;   break;
		        case 4:    ret = SKILL_F_HEAVY;   break;
		        case 5:    ret = SKILL_PISTOL;    break;
		        case 6:    ret = SKILL_FORTUNE;   break;
                case 7:    ret = SKILL_SNEAK;      break;
		    }
		break;
		
		case "ShipType" :
		    switch (idx)
		    {
                case 1:    ret = SKILL_SAILING; break;
				case 2:    ret = SKILL_ACCURACY;   break;
		        case 3:    ret = SKILL_CANNONS;   break;
		        case 4:    ret = SKILL_GRAPPLING;   break;
		        case 5:    ret = SKILL_DEFENCE;    break;
		        case 6:    ret = SKILL_REPAIR;   break;
                case 7:    ret = SKILL_COMMERCE;      break;
		    }
		break;
		
		case "SPECIALType" :
		    switch (idx)
		    {
                case 1:   ret = SPECIAL_S;   break;
		        case 2:   ret = SPECIAL_P;   break;
		        case 3:   ret = SPECIAL_A;   break;
		        case 4:   ret = SPECIAL_C;   break;
		        case 5:   ret = SPECIAL_I;   break;
		        case 6:   ret = SPECIAL_E;   break;
		        case 7:   ret = SPECIAL_L;   break;
		    }
		break;
    }
    return ret;
}
// �� ����� ����� ������� ��������
int GetSkillValue(ref _refCharacter, string _type, string _skillName)
{
    if (CheckAttribute(_refCharacter, _type + "." + _skillName))
    {
        return sti(_refCharacter.(_type).(_skillName));
    }
    return 0;
}

float GetSkillValueExp(ref _refCharacter, string _skillName)
{
    string skillName_exp = _skillName + "_exp";
    if (!CheckAttribute(_refCharacter, "Skill."+skillName_exp))
	{
		_refCharacter.Skill.(skillName_exp) = 0;
	}
    return stf(_refCharacter.Skill.(skillName_exp));
}
int AddSPECIALValue(ref _refCharacter, string _skillName, int _add)
{
    string _type = SPECIAL_TYPE;
    
    if (CheckAttribute(_refCharacter, _type + "." + _skillName))
    {
        _refCharacter.(_type).(_skillName) = sti(_refCharacter.(_type).(_skillName)) + _add;
    }
    else
    {
        _refCharacter.(_type).(_skillName) = _add;
    }
    if (sti(_refCharacter.(_type).(_skillName)) < 1) {_refCharacter.(_type).(_skillName) = 1;}
    if (sti(_refCharacter.(_type).(_skillName)) > SPECIAL_MAX) {_refCharacter.(_type).(_skillName) = SPECIAL_MAX;}
    
    return sti(_refCharacter.(_type).(_skillName));
}

int AddCharacterSkill(ref _chref, string _skill, int _addValue)
{
    string  _skill_exp = _skill + "_exp";

    if (_addValue > 0)
	{
	    if ((sti(_chref.skill.(_skill)) + _addValue) > SKILL_MAX)
	    {
	        _addValue = SKILL_MAX - sti(_chref.skill.(_skill));
	    }
	}
    _chref.skill.(_skill) = sti(_chref.skill.(_skill)) + _addValue;

	if (sti(_chref.skill.(_skill)) < 1)
	{
        _chref.skill.(_skill) = 1;
	}
	if (sti(_chref.skill.(_skill)) > SKILL_MAX )
	{
	    _chref.skill.(_skill) = SKILL_MAX;
	}
	_chref.skill.(_skill_exp) = 0;
	if (_addValue >= 0)
	{
	   ApplayNewSkill(_chref, _skill, _addValue);
	}
	return sti(_chref.skill.(_skill));
}

void AddCharacterSkillDontClearExp(ref _chref, string _skill, int _addValue)
{
    /*if (_addValue > 0)
	{
	    if ((sti(_chref.skill.(_skill)) + _addValue) > SKILL_MAX)
	    {
	        _addValue = SKILL_MAX - sti(_chref.skill.(_skill));
	    }
	} */
	_chref.skill.(_skill) = sti(_chref.skill.(_skill)) + _addValue;

	if (sti(_chref.skill.(_skill)) < 1)
	{
        _chref.skill.(_skill) = 1;
	}
	if (sti(_chref.skill.(_skill)) > SKILL_MAX )
	{
	    _chref.skill.(_skill) = SKILL_MAX;
	}
	if (_addValue >= 0)
	{
	   ApplayNewSkill(_chref, _skill, _addValue);
	}
}

void ApplayNewSkill(ref _chref, string _skill, int _addValue)
{
    // ���� ���
    CheckAttribute(_chref, "BakSkill." + _skill);
    
	// boal 05.05.04 ���������� �� ������� -->
    if (isSelfTypeSkill(_skill))
    {
       if(CheckAttribute(_chref,"perks.FreePoints_self_exp"))
       {
           _chref.perks.FreePoints_self_exp = sti(_chref.perks.FreePoints_self_exp) + _addValue;
       }
       else
       {	_chref.perks.FreePoints_self_exp = _addValue;
       }
       if (sti(_chref.perks.FreePoints_self_exp) >= GetFreePoints_SelfRate(_chref))
       {
           _chref.perks.FreePoints_self_exp = 0;
           if(CheckAttribute(_chref,"perks.FreePoints_self"))
           {
               _chref.perks.FreePoints_self = sti(_chref.perks.FreePoints_self) + 1;
           }
           else
           {	_chref.perks.FreePoints_self = 1;
           }
           if (sti(_chref.index) == GetMainCharacterIndex())
           {
               Log_SetStringToLog(XI_ConvertString("Personal abilities") + " + 1");
           }
       }
    }
    else
    {
       if(CheckAttribute(_chref,"perks.FreePoints_ship_exp"))
       {
           _chref.perks.FreePoints_ship_exp = sti(_chref.perks.FreePoints_ship_exp) + _addValue;
       }
       else
       {	_chref.perks.FreePoints_ship_exp = _addValue;
       }
       if (sti(_chref.perks.FreePoints_ship_exp) >= GetFreePoints_ShipRate(_chref))
       {
           _chref.perks.FreePoints_ship_exp = 0;
           if(CheckAttribute(_chref,"perks.FreePoints_ship"))
           {
               _chref.perks.FreePoints_ship = sti(_chref.perks.FreePoints_ship) + 1;
           }
           else
           {	_chref.perks.FreePoints_ship = 1;
           }
           if (sti(_chref.index) == GetMainCharacterIndex())
           {
               Log_SetStringToLog(XI_ConvertString("Ship abilities") + " + 1");
           }
       }
    }
    // boal 05.05.04 ���������� �� ������� <--


    if(!CheckAttribute(_chref, "rank_exp"))
    {
      _chref.rank_exp = 0;
    }
    _chref.rank_exp = sti(_chref.rank_exp) + _addValue;

    if (sti(_chref.rank_exp) >= GetCharacterRankRate(_chref)) // use classic mode - 2 skill = 1 rank
    {
        _chref.rank_exp = 0;
        _chref.rank = sti(_chref.rank) + 1;
        float mhp = LAi_GetCharacterMaxHP(_chref) + GetCharacterAddHPValue(_chref);
        LAi_SetHP(_chref,mhp,mhp);

        if (CheckCharacterPerk(_chref, "EnergyPlus"))
		{
		    if (!CheckAttribute(_chref, "PerkValue.EnergyPlus"))
			{
		  		_chref.PerkValue.EnergyPlus = 0;
			}
			_chref.PerkValue.EnergyPlus = sti(_chref.PerkValue.EnergyPlus) + 1;
			SetEnergyToCharacter(_chref);
		}

        // ��������� � ���
        if(IsOfficer(_chref) || IsCompanion(_chref))
        {
            AddMsgToCharacter(_chref,MSGICON_LEVELUP);
            Log_SetStringToLog(XI_ConvertString("Level Up"));
            PlayStereoSound("interface\new_level.wav");
        }
    }
}
// �� ������� ����������� �����
void InitStartParam(ref _chref)
{
    int i;
    string  skillName;
    
    ClearCharacterExpRate(_chref);
    
    for (i=1; i<15; i++)
    {
        skillName = GetSkillNameByIdx(i);
        _chref.skill.(skillName) = makeint(MOD_EXP_RATE / GetCharacterExpRate(_chref, skillName) + 0.5);
    }
    LAi_SetHP(_chref, GetCharacterBaseHPValue(_chref), GetCharacterBaseHPValue(_chref));
}
// ����� ���������� ����� (���������)
float GetCharacterExpRate(ref _chref, string _skill)
{
    string  skill_rate = _skill + "_rate";

    if (!CheckAttribute(_chref, "skill." + skill_rate))
    {
        float  divBy = 1.0;

        switch (_skill)
        {
            case SKILL_F_LIGHT:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_A)*0.9 + GetCharacterSPECIAL(_chref, SPECIAL_P)*0.1;
            break;
            case SKILL_FENCING:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_S)*0.6 + GetCharacterSPECIAL(_chref, SPECIAL_A)*0.4;
            break;
            case SKILL_F_HEAVY:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_S)*0.9 + GetCharacterSPECIAL(_chref, SPECIAL_E)*0.1;
            break;
            case SKILL_PISTOL:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_A)*0.5 + GetCharacterSPECIAL(_chref, SPECIAL_L)*0.5;
            break;
            case SKILL_FORTUNE:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_L);
            break;
            
            case SKILL_LEADERSHIP:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_I)*0.1 + GetCharacterSPECIAL(_chref, SPECIAL_C)*0.9;
            break;
            case SKILL_COMMERCE:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_I)*0.8 + GetCharacterSPECIAL(_chref, SPECIAL_C)*0.2;
            break;
            case SKILL_ACCURACY:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_P)*0.8 + GetCharacterSPECIAL(_chref, SPECIAL_L)*0.2;
            break;
            case SKILL_CANNONS:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_I)*0.6 + GetCharacterSPECIAL(_chref, SPECIAL_S)*0.4;
            break;
            case SKILL_SAILING:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_P)*0.2 + GetCharacterSPECIAL(_chref, SPECIAL_I)*0.8;
            break;
            case SKILL_REPAIR:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_P)*0.2 + GetCharacterSPECIAL(_chref, SPECIAL_E)*0.8;
            break;
            case SKILL_GRAPPLING:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_A)*0.7 + GetCharacterSPECIAL(_chref, SPECIAL_I)*0.3;
            break;
            case SKILL_DEFENCE:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_C)*0.5 + GetCharacterSPECIAL(_chref, SPECIAL_E)*0.5;
            break;
            case SKILL_SNEAK:
                divBy = GetCharacterSPECIAL(_chref, SPECIAL_P)*0.5 + GetCharacterSPECIAL(_chref, SPECIAL_L)*0.5;
            break;
        }
        _chref.skill.(skill_rate) = makefloat(MOD_EXP_RATE / divBy);
    }
    return  stf(_chref.skill.(skill_rate));
}

// table service
string GetReputationComplexName(int reputation, string repName)
{	
	switch(repName)
	{
		case "fame" 	:
			if(reputation < 21)  return "REPUTATION_FAME_1";
			if(reputation < 41)  return "REPUTATION_FAME_2";
			if(reputation < 61)  return "REPUTATION_FAME_3";
			if(reputation < 81)  return "REPUTATION_FAME_4";
			return "REPUTATION_FAME_5";
		break;
		
		case "nobility" :
			if(reputation < 6)   return "REPUTATION_NOBILITY_1";
			if(reputation < 16)  return "REPUTATION_NOBILITY_2";
			if(reputation < 31)  return "REPUTATION_NOBILITY_3";
			if(reputation < 48)  return "REPUTATION_NOBILITY_4";
			if(reputation < 53)  return "REPUTATION_NOBILITY_5";
			if(reputation < 71)  return "REPUTATION_NOBILITY_6";
			if(reputation < 86)  return "REPUTATION_NOBILITY_7";
			if(reputation < 96)  return "REPUTATION_NOBILITY_8";
			return "REPUTATION_NOBILITY_9";
		break;
	}
}

string GetFullReputationComplexName(ref chref)
{
	string sReputation, sFame, sNobility;
	
	if(CheckAttribute(chref,"reputation.fame")) 
	{
		sFame = GetReputationComplexName(sti(chref.reputation.fame), "fame");
	}	
	else 
	{
		sFame = "REPUTATION_FAME_1";	
	}	
	
	if(CheckAttribute(chref,"reputation.nobility")) 
	{
		sNobility = GetReputationComplexName(sti(chref.reputation.nobility), "nobility");
	}	
	else
	{
		sNobility = "REPUTATION_NOBILITY_5";	
	}	
	sReputation = XI_ConvertString(sFame) + " " + XI_ConvertString(sNobility);
	
	return sReputation;
}

// table service
string GetReputationName(int reputation)
{
    if(reputation<11)
        return "REPUTATIONT_BAD_4";
    if(reputation<21)
        return "REPUTATIONT_BAD_3";
    if(reputation<31)
        return "REPUTATIONT_BAD_2";
    if(reputation<41)
        return "REPUTATIONT_BAD_1";
    if(reputation<51)
        return "REPUTATIONT_NEUTRAL";
    if(reputation<61)
        return "REPUTATIONT_GOOD_1";
    if(reputation<71)
        return "REPUTATIONT_GOOD_2";
    if(reputation<81)
        return "REPUTATIONT_GOOD_3";
    if(reputation<=90)
        return "REPUTATIONT_GOOD_4";

	return "REPUTATIONT_GOOD_4";
}
// to_do  del
string GetFameName(int fame)
{
   return "TO_DO for del";
}

string GetMoraleName(int morale)
{
	if(morale<10)
		return MoraleTable[MORALET_TREACHEROUS];
	if(morale<20)
		return MoraleTable[MORALET_AWFUL];
	if(morale<30)
		return MoraleTable[MORALET_LOW];
	if(morale<40)
		return MoraleTable[MORALET_POOR];
	if(morale<50)
		return MoraleTable[MORALET_NORMAL];
	if(morale<60)
		return MoraleTable[MORALET_ELATED];
	if(morale<70)
		return MoraleTable[MORALET_GOOD];
	if(morale<80)
		return MoraleTable[MORALET_HIGH];
	if(morale<90)
		return MoraleTable[MORALET_EXCELLENT];
	if(morale<=100)
		return MoraleTable[MORALET_HEROIC];
	return "";
}

string GetLoyalityName(int iLoyality)
{
	if(iLoyality<10)
		return LoyalityTable[MORALET_TREACHEROUS];
	if(iLoyality<20)
		return LoyalityTable[MORALET_AWFUL];
	if(iLoyality<30)
		return LoyalityTable[MORALET_LOW];
	if(iLoyality<40)
		return LoyalityTable[MORALET_POOR];
	if(iLoyality<50)
		return LoyalityTable[MORALET_NORMAL];
	if(iLoyality<60)
		return LoyalityTable[MORALET_ELATED];
	if(iLoyality<70)
		return LoyalityTable[MORALET_GOOD];
	if(iLoyality<80)
		return LoyalityTable[MORALET_HIGH];
	if(iLoyality<90)
		return LoyalityTable[MORALET_EXCELLENT];
	if(iLoyality<=100)
		return LoyalityTable[MORALET_HEROIC];
	return "";
}

// boal 15/01/04 ���� ����� ������ � ���� ����� ��� �������� ������ ����� -->
int SetCharacterSkillByItem(ref _refCharacter, string _skillName, string _itemSkillName, string _item, int _addValue)
{
	int iRetValue = 0;

	if(_skillName == _itemSkillName && GetCharacterItem(_refCharacter, _item) > 0)
	{
		iRetValue = _addValue;
	}

	return iRetValue;
}

int SetCharacterSkillByEquippedItem(ref _refCharacter, string _skillName, string _itemSkillName, string _item, int _addValue)
{
	int iRetValue = 0;
	
	if(_skillName == _itemSkillName && IsEquipCharacterByArtefact(_refCharacter, _item))
	{
		iRetValue = _addValue;
	}
	
	return iRetValue;
}

float AddMultiplySkillByEquippedItem(ref _refCharacter, string _skillName, string _itemSkillName, string _item, float _addValue)
{
	float fRetValue = 1.0;
	
	if(_skillName == _itemSkillName && IsEquipCharacterByArtefact(_refCharacter, _item))
	{
		fRetValue = _addValue;
	}
	
	return fRetValue;
}

int ApplySPECIALCirassPenalty(ref rChar, String sSkillName)
{
	int iValue = 0;
	String sSuit = GetCharacterEquipSuitID(rChar);
	
	if(sSuit == INVALID_SUIT) return 0;

	switch(sSuit)
	{	
		case "cirass1"	:
			if(sSkillName == SPECIAL_E)			iValue = -1;			
			if(sSkillName == SPECIAL_A)			iValue = -2;			
		break;
				
		case "cirass2"	:
			if(sSkillName == SPECIAL_E)			iValue = -1;
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
				
		case "cirass3"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
		
		case "cirass4"	:
			if(sSkillName == SPECIAL_E)			iValue = -1;
		break;
		
		case "cirass6"	:
			if(sSkillName == SPECIAL_P)			iValue = -1;
		break;
		
		case "cirass7"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
			if(sSkillName == SPECIAL_P)			iValue = -1;
		break;
		
		case "cirass8"	:
			if(sSkillName == SPECIAL_P)			iValue = -1;
		break;
		
		case "suit1"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
		
		case "suit2"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
		
		case "suit3"	:
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
		
		case "suit4"	:
			if(sSkillName == SPECIAL_P)			iValue = -1; // �������
		break;
		
		case "underwater"	: //Jason: �������
			if(sSkillName == SPECIAL_P)			iValue = -2;
			if(sSkillName == SPECIAL_E)			iValue = -2;
			if(sSkillName == SPECIAL_A)			iValue = -1;
		break;
	}
		
	return iValue;
}

int GetCharacterSuitType(ref rChar)
{
	int iValue = 0;
	String sSuit = GetCharacterEquipSuitID(rChar);
	
	if(sSuit == INVALID_SUIT) return -1;

	switch(sSuit)
	{	
		// ������� �������
		case "cirass1"	:
			iValue = 2;
		break;		
		case "cirass2"	:
			iValue = 2;
		break;				
		case "cirass3"	:
			iValue = 2;
		break;				
		case "cirass4"	:
			iValue = 2;
		break;
		
		// ������ �������
		case "cirass5"	:
			iValue = 1;
		break;				
		case "cirass6"	:
			iValue = 1;
		break;				
		case "cirass7"	:
			iValue = 1;
		break;				
		case "cirass8"	:
			iValue = 1;
		break;		
		
		// ������
		case "underwater":
			iValue = 0;
		break;						
		case "suit1":
			iValue = 0;
		break;						
		case "suit2":
			iValue = 0;
		break;						
		case "suit3":
			iValue = 0;
		break;				
	}
		
	return iValue;
}

// Warship 25.10.08 ���� ������
int SetCharacterSkillBySuit(ref rChar, String sSkillName)
{
	int iValue = 0;
	String sSuit = GetCharacterEquipSuitID(rChar);
	
	if(sSuit == INVALID_SUIT) return 0;
	
	switch(sSuit)
	{	
		case "cirass1"	:
			if(sSkillName == SKILL_SNEAK)		iValue = -5;
		break;

		case "cirass2"	:
			if(sSkillName == SKILL_SNEAK)		iValue = -10;
		break;

		case "cirass3"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 5;
			if(sSkillName == SKILL_SNEAK)		iValue = -15;
		break;
		
		case "cirass4"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 10;
			if(sSkillName == SKILL_SNEAK)		iValue = -20;
		break;
		
		case "cirass6"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -5;
			if(sSkillName == SKILL_SNEAK)		iValue = -5;
		break;
		
		case "cirass7"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -10;
			if(sSkillName == SKILL_SNEAK)		iValue = -10;
		break;
		
		case "cirass8"	:
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -15;
			if(sSkillName == SKILL_SNEAK)		iValue = 15;
		break;
		
		case "suit1"	: // ����������� ���������� ������
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 15;
			if(sSkillName == SKILL_SNEAK)		iValue = -15;
		break;
		
		case "suit2"	: // ���������� ���������� ������
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 15;
			if(sSkillName == SKILL_SNEAK)		iValue = -15;
		break;
		
		case "suit3"	: // ��������� ���������� ������
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 15;
			if(sSkillName == SKILL_SNEAK)		iValue = -15;
		break;
		
		case "suit4"	: // ������ �������� (�������)
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -25;
			if(sSkillName == SKILL_SNEAK)		iValue = 30;
		break;
		
		case "underwater"	: // Jason: �������
			if(sSkillName == SKILL_LEADERSHIP)	iValue = -20;
			if(sSkillName == SKILL_SNEAK)		iValue = -100;
			if(sSkillName == SKILL_F_LIGHT)		iValue = -15;
			if(sSkillName == SKILL_FENCING)		iValue = -15;
			if(sSkillName == SKILL_F_HEAVY)		iValue = -15;
			if(sSkillName == SKILL_PISTOL)		iValue = -50;
		break;
	}
	
	return iValue;
}
// Jason: ���� �������������� �������
int SetCharacterSkillByQuestBlade(ref rChar, String sSkillName)
{
	int iValue = 0;
	String sBlade = GetCharacterEquipByGroup(rChar, BLADE_ITEM_TYPE);
	
	switch(sBlade)
	{	
		case "knife_01"	:
			if(sSkillName == SKILL_F_LIGHT)		iValue = 5;
		break;
		
		case "q_blade_10"	:
			if(sSkillName == SKILL_FENCING)		iValue = 10;
		break;
		
		case "q_blade_13"	:
			if(sSkillName == SKILL_F_HEAVY)		iValue = 10;
		break;
		
			case "q_blade_16"	:
			if(sSkillName == SKILL_F_LIGHT)		iValue = 10;
		break;
		
			case "q_blade_18"	:
			if(sSkillName == SKILL_F_LIGHT)		iValue = 12;
		break;
		
			case "q_blade_19"	:
			if(sSkillName == SKILL_FENCING)		iValue = 12;
		break;
		
			case "q_blade_21"	:
			if(sSkillName == SKILL_F_HEAVY)		iValue = 12;
		break;
		
		case "topor_06"	: // Addon 2016-1 Jason ��������� �������
			if(sSkillName == SKILL_F_HEAVY)		iValue = 5;
		break;
	}
	
	return iValue;
}

// Jason: ����.�������
int SetCharacterSkillByPenalty(ref rChar, String sSkillName)
{
	int iValue = 0;
	int iPenalty = sti(rChar.GenQuest.BladePenalty);
	
	if(sSkillName == SKILL_F_LIGHT)		iValue = -iPenalty;
	if(sSkillName == SKILL_FENCING)		iValue = -iPenalty;
	if(sSkillName == SKILL_F_HEAVY)		iValue = -iPenalty;
	
	return iValue;
}

// Jason: ����.�������
int ApplySPECIALQuestPenalty(ref rChar, String sSkillName)
{
	int iValue = 0;
	int iPenalty = sti(rChar.GenQuest.EnergyPenalty);
	
	if(sSkillName == SPECIAL_A)			iValue = -iPenalty;
	
	return iValue;
}

// Jason: ����� ���������
int ApplySPECIALMangarosaPotion(ref rChar, String sSkillName) // 280313
{
	int iValue = 0;
	if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion"))
	{
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Power"))
		{
			if(sSkillName == SPECIAL_S)			iValue = 2;
			if(sSkillName == SPECIAL_E)			iValue = 2;
		}
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Fast"))
		{
			if(sSkillName == SPECIAL_A)			iValue = 2;
			if(sSkillName == SPECIAL_P)			iValue = 2;
		}
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Total"))
		{
			if(sSkillName == SPECIAL_S)			iValue = 1;
			if(sSkillName == SPECIAL_E)			iValue = 1;
			if(sSkillName == SPECIAL_A)			iValue = 1;
			if(sSkillName == SPECIAL_P)			iValue = 1;
			if(sSkillName == SPECIAL_C)			iValue = 1;
			if(sSkillName == SPECIAL_L)			iValue = 2;
		}
	}
	return iValue;
}

int SetCharacterSkillByMangarosa(ref rChar, String sSkillName) // 280313
{
	int iValue = 0;
	if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion"))
	{
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Power"))
		{
			if(sSkillName == SKILL_F_HEAVY)		iValue = 15;
			if(sSkillName == SKILL_FENCING)		iValue = 5;
		}
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Fast"))
		{
			if(sSkillName == SKILL_F_LIGHT)		iValue = 10;
			if(sSkillName == SKILL_PISTOL)		iValue = 10;
		}
		if (CheckAttribute(rChar, "questTemp.Mangarosa.Potion.Total"))
		{
			if(sSkillName == SKILL_F_HEAVY)		iValue = 5;
			if(sSkillName == SKILL_F_LIGHT)		iValue = 5;
			if(sSkillName == SKILL_PISTOL)		iValue = 5;
			if(sSkillName == SKILL_LEADERSHIP)	iValue = 5;
			if(sSkillName == SKILL_FORTUNE)		iValue = 5;
		}
	}
	
	return iValue;
}

// Jason: ������� - ������� �������������
int SetCharacterSkillByTuttuat(ref rChar, String sSkillName)
{
	int iValue = 0;
	
	if(sSkillName == SKILL_F_LIGHT)		iValue = 25;
	if(sSkillName == SKILL_FENCING)		iValue = 25;
	if(sSkillName == SKILL_F_HEAVY)		iValue = 25;
	if(sSkillName == SKILL_PISTOL)		iValue = 25;
	
	return iValue;
}

// boal 15/01/04 ���� ����� ������ � ���� ����� ��� �������� ������ ����� <--
float GetCharacterSkillToOld(ref _refCharacter, string skillName)
{
    return makefloat(GetCharacterSkill(_refCharacter, skillName) / SKILL_TO_OLD);
}
int GetCharacterSkill(ref _refCharacter, string skillName)
{
    int skillN;

    // boal 051104 ����� �������� ������� - �������� +1 �����, ����� ����� ��� � 10
    if (CheckAttribute(_refCharacter, "BakSkill." + skillName))
    {
        if (sti(_refCharacter.BakSkillCount.(skillName)) < 20 )
        {
            _refCharacter.BakSkillCount.(skillName) = sti(_refCharacter.BakSkillCount.(skillName)) + 1;
            return sti(_refCharacter.BakSkill.(skillName));
        }
    }

	skillN = GetCharacterSkillSimple(_refCharacter, skillName);


    // 14.03.05 �������� �� ������ ������� -->
 	skillN = ApplayNavyPenaltyToSkill(_refCharacter, skillName, skillN);
	// 14.03.05 �������� �� ������ ������� <--

	_refCharacter.BakSkill.(skillName)      =  skillN; // ��������
    _refCharacter.BakSkillCount.(skillName) = rand(5); // ������� ������� �������� ��������

    return skillN;
}

int GetCharacterSkillSimple(ref _refCharacter, string skillName)
{
	if( !CheckAttribute(_refCharacter,"Skill."+skillName) ) return 1;
	int skillN = sti(_refCharacter.Skill.(skillName));

	bool   bHero = (sti(_refCharacter.index) == GetMainCharacterIndex());
	
    // boal ���� ����� -->
    if (bHero || CheckAttribute(_refCharacter, "Payment")) //IsCompanion(_refCharacter) || IsOfficer(_refCharacter))
    {
        // Health
        if (bHero && MOD_SKILL_ENEMY_RATE > 1) // �� ������
        {
            if (isSelfTypeSkill(skillName))
            {
                skillN = skillN + 5*(GetHealthNum(_refCharacter) - 6); // max -5
            }
        }
		
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, 		"SkullAztec", 	-20);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, 	"SkullAztec", 	 10);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_PISTOL, 		"KnifeAztec", 	-30);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_LIGHT, 		"KnifeAztec", 	-20);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FENCING, 		"KnifeAztec", 	-20);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_F_HEAVY, 		"KnifeAztec", 	-20);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, 		  "mineral8",   -10);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, 		 "mineral14",   -10);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE, 			 "Coins",   -50);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, 	 "mineral30",   -10);
		skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_LEADERSHIP, 	 "mineral31", 	-10);
    	skillN += SetCharacterSkillByItem(_refCharacter, skillName, SKILL_FORTUNE,       "mineral31", 	-10);
		
		skillN += SetCharacterSkillByEquippedItem(_refCharacter, skillName, SKILL_SAILING, "obereg_7", 10);

		// Warship 25.10.08 ����� ���� ������
		skillN += SetCharacterSkillBySuit(_refCharacter, skillName);
	
		//Jason: ���� �������������� �������
		skillN += SetCharacterSkillByQuestBlade(_refCharacter, skillName);
		skillN += SetCharacterSkillByMangarosa(_refCharacter, skillName);
	
		//Jason: ���� ����������� ���������
		if(CheckAttribute(_refCharacter, "GenQuest.BladePenalty")) 
			{
				skillN += SetCharacterSkillByPenalty(_refCharacter, skillName);
			}
		//Jason: �������
		if(IsCharacterEquippedArtefact(_refCharacter, "kaleuche_amulet2"))
		{
			skillN += SetCharacterSkillByTuttuat(_refCharacter, skillName);
		}
		//navy --> �������� ��������
		if (CheckAttribute(_refCharacter, "chr_ai.drunk.skill." + skillName))
		{
			skillN += sti(_refCharacter.chr_ai.drunk.skill.(skillName));
		}
		//<--
		// ugeen - ������ ���� � �����, ��������� � ������� �� ������� ����������
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,   SKILL_ACCURACY, "indian_9", 1.10));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,      SKILL_SNEAK, "obereg_4", 1.15));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,    SKILL_FORTUNE, "obereg_5", 1.15));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName, SKILL_LEADERSHIP, "obereg_6", 1.15));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,   SKILL_COMMERCE, "obereg_8", 1.15));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,    SKILL_FORTUNE, "amulet_7", 0.50));
		skillN = makeint(skillN * AddMultiplySkillByEquippedItem(_refCharacter, skillName,      SKILL_SNEAK, "amulet_6", 0.50));
		
		if(!IsDay())
		{
			if(IsCharacterEquippedArtefact(_refCharacter, "totem_12") && skillName == SKILL_ACCURACY) 
			{
				skillN = skillN * 2; // ������ ������ ������� �� ����� !!!!
			}
		}
		
		if(CheckCharacterPerk(_refCharacter, "HT2") && skillName == SKILL_SNEAK)
		{
			skillN = skillN * 1.15;
		}
		
    	// boal ���� ��������� 19.01.2004 -->
    	if ( GetItemsWeight(_refCharacter) > GetMaxItemsWeight(_refCharacter) && !IsEquipCharacterByArtefact(_refCharacter, "totem_06"))
    	{
   	        skillN -= 20;
    	}
    	// boal ���� ��������� 19.01.2004 <--
	}
	// boal <--
	if (skillN <= 1) skillN = 1;
	if( skillN > SKILL_MAX ) skillN = SKILL_MAX;

	return skillN;
}
// boal 20.03.2004 -->
int GetShipClassNavySkill(int shipClass)
{
    int needSkill = 0;

    switch (shipClass)
    {
            case 1 : needSkill = 95; break;
            case 2 : needSkill = 80; break;
            case 3 : needSkill = 65; break;			
            case 4 : needSkill = 45; break;			
			case 5 : needSkill = 25; break;
            case 6 : needSkill = 1; break;
    }
    return needSkill;
}
// boal 20.03.2004 <--
void DelBakSkillAttr(ref _refCharacter) // boal ����������� ������
{
    DeleteAttribute(_refCharacter, "BakSkill");
    DeleteAttribute(_refCharacter, "BakSkillCount");
}
// ����� ���� ������� (����� �������, ��������������� �� ����� +1)
void ClearCharacterExpRate(ref _chref)
{
    int    i;
    string name;

    for (i=1; i<15; i++)
    {
        name = GetSkillNameByIdx(i);
        DeleteAttribute(_chref, "skill." + name + "_rate");
    }
}
// ����� �������� ����� ����, ����� �������� ����, ����� ����� �� 120%
void RefreshCharacterSkillExpRate(ref _chref)
{
    int    i;
    string name;

    for (i=1; i<15; i++)
    {
        name = GetSkillNameByIdx(i);
        AddCharacterExpToSkill(_chref, name, 0.0);
        ApplayNewSkill(_chref, name, 0); // ����� �����  ����� 23/22
    }
}

float GetSummonSkillFromNameToOld(ref _refCharacter, string skillName)
{
    return (GetSummonSkillFromName(_refCharacter, skillName) / SKILL_TO_OLD);
}
int GetSummonSkillFromName(ref _refCharacter, string skillName)
{
    int sumSkill;

    // boal 051104 ����� �������� ������� - �������� +1 �����, ����� ����� ��� � 10
    if (CheckAttribute(_refCharacter, "BakSkill." + skillName))
    {
        if (sti(_refCharacter.BakSkillCount.(skillName)) < 25 )
        {
            _refCharacter.BakSkillCount.(skillName) = sti(_refCharacter.BakSkillCount.(skillName)) + 1;
            return sti(_refCharacter.BakSkill.(skillName));
        }
    }

    sumSkill = GetSummonSkillFromNameSimple(_refCharacter, skillName);

    // boal 27.01.2004 �������� �� ������ ������� -->
 	sumSkill = ApplayNavyPenaltyToSkill(_refCharacter, skillName, sumSkill);
    // boal 27.01.2004 <--

    _refCharacter.BakSkill.(skillName)      =  sumSkill; // ��������
    _refCharacter.BakSkillCount.(skillName) = rand(5); // ������� ������� �������� ��������

    return sumSkill;
}

int GetSummonSkillFromNameSimple(ref _refCharacter, string skillName)
{
    int sumSkill = GetCharacterSkillSimple(_refCharacter,skillName);

	if (sti(_refCharacter.index) == sti(pchar.index))
	{
	    int iOfficer = -1;
		int iOffSkill = -1;
		switch (skillName)
		{
			/*case SKILL_LEADERSHIP:
				iOfficer = sti(pchar.Fellows.Passengers.boatswain);
			break;*/

			case SKILL_SAILING:
				iOfficer = sti(pchar.Fellows.Passengers.navigator);
			break;

			case SKILL_CANNONS:
				iOfficer = sti(pchar.Fellows.Passengers.cannoner);
			break;

			case SKILL_ACCURACY:
				iOfficer = sti(pchar.Fellows.Passengers.cannoner);
			break;

			case SKILL_GRAPPLING:
				iOfficer = sti(pchar.Fellows.Passengers.boatswain);
			break;

			case SKILL_DEFENCE:
				iOfficer = sti(pchar.Fellows.Passengers.doctor);
			break;

			case SKILL_REPAIR:
				iOfficer = sti(pchar.Fellows.Passengers.carpenter);
			break;

			case SKILL_COMMERCE:
				iOfficer = sti(pchar.Fellows.Passengers.treasurer);
			break;
		}

		if(iOfficer != -1)
		{
			iOffSkill = GetCharacterSkillSimple(&characters[iOfficer], skillName);
			if (iOffSkill > sumSkill)
			{
				sumSkill = iOffSkill;
			}
		}
	}
	return sumSkill;
}

void AddPartyExp(ref _refCharacter,int _exp)
{
	/*int cn,i;
	ref chref;
	i = GetOfficersQuantity(_refCharacter);
	_exp = (_exp+i)/(i+1);
	for(i=0; i<4; i++)
	{
		cn = GetOfficersIndex(_refCharacter,i);
		if(cn!=-1)
		{	AddCharacterExp(GetCharacter(cn),_exp);
		}
	}*/
}

void AddExpAndShow(ref chref, int _exp)
{
	// boal Log_SetStringToLog("+" + _exp + XI_ConvertString("add experience"));
	//AddCharacterExp(chref, _exp);
}
// boal -->


void AddCharacterExpToSkillSquadron(ref _refCharacter, string _skill, float _addValue)
{
    int cn,i;
	ref chref;

	for(i=0; i<4; i++)
	{
		cn = GetCompanionIndex(_refCharacter,i);
		if(cn!=-1)
		{    // � ��������� ����
			AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue);
		}
	}
}
void AddCharacterExpToSkill(ref _chref, string _skill, float _addValue)
// _chref - character _skill - name ex -"Fencing"  _skill_exp = "Fencing_exp"   _addValue = 100
{
    string  _skill_exp = _skill + "_exp";
    if (!CheckAttribute(_chref, "skill." + _skill_exp))
    {
        _chref.skill.(_skill_exp) = 0;
    }
	
    if (bExpLogShow && _addValue > 0)
    {
	   if (IsOfficer(_chref))  Log_Info(_chref.id + " take " + FloatToString(_addValue, 2) + " exp to " + _skill);
    }
    // boal 300804 ������� ����� -->
    if (_addValue < 0)
    {
        if(CheckAttribute(_chref, "skill." + _skill_exp))
        {
            _chref.skill.(_skill_exp) = sti(_chref.skill.(_skill_exp)) + _addValue;
            if (sti(_chref.skill.(_skill_exp)) < 0)
            {
                _chref.skill.(_skill_exp) = 0;
            }
        }
        return;
    }
    // boal 300804 ������� ����� <--
    if (CheckAttribute(_chref, "skill." + _skill) && sti(_chref.skill.(_skill)) < SKILL_MAX)// && sti(_chref.skill.(_skill)) > 0)
    { // if skill = 0 then it is great loser
        _chref.skill.(_skill_exp) = stf(_chref.skill.(_skill_exp)) + _addValue;

        while ( makeint(sti(_chref.skill.(_skill)) * GetCharacterExpRate(_chref, _skill)) <= stf(_chref.skill.(_skill_exp))
                && sti(_chref.skill.(_skill)) < SKILL_MAX )
        {
            _chref.skill.(_skill_exp) = stf(_chref.skill.(_skill_exp)) - makeint(sti(_chref.skill.(_skill)) * GetCharacterExpRate(_chref, _skill));
            /*if (sti(_chref.index) == GetMainCharacterIndex())
            {
               Log_SetStringToLog(XI_ConvertString(_skill)+" UP");
            } */
            AddCharacterSkillDontClearExp(_chref, _skill, 1);
            // ����������� ������
            DeleteAttribute(_chref, "BakSkill." + _skill);
            DeleteAttribute(_chref, "BakSkillCount." + _skill);
        }
    }
    /// officers
    if (_addValue > 0 && sti(_chref.index) == GetMainCharacterIndex()) // ������ ��� ��
    {
		int cn, i, iPas;
		iPas = GetPassengersQuantity(_chref); // ����������
		if (CheckCharacterPerk(_chref, "SharedExperience"))
		{
			for(i=0; i<iPas; i++)
			{
				cn = GetPassenger(_chref,i);
				if(cn!=-1)
				{
				   if (isOfficerInShip(GetCharacter(cn), true))
				   {
				       AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 2.0);
				   }
				   else
				   {
				       AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 10.0);
				   }
				}
			}
	        for(i=1; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(_chref,i);
				if(cn!=-1)
				{
					AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 3.0);
				}
			}
		}
		else
		{
		    for(i=0; i<iPas; i++)
			{
				cn = GetPassenger(_chref,i);
				if(cn!=-1)
				{
				   if (isOfficerInShip(GetCharacter(cn), true))
				   {
				       AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 4.0);
				   }
				   else
				   {
				       AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 20.0);
				   }
				}
			}
	        for(i=1; i<COMPANION_MAX; i++)
			{
				cn = GetCompanionIndex(_chref,i);
				if(cn!=-1)
				{
					AddCharacterExpToSkill(GetCharacter(cn), _skill, _addValue / 6.0);
				}
			}
		}
    }
}

string GetPerkListText(ref _chref, string _type)
{
    int    perksQ,i;
    int    lngFilePerkID = -1;
	string perkName;
	string ret;
	aref   arPerksRoot;

    lngFilePerkID = LanguageOpenFile("AbilityDescribe.txt");
	// �������� ������, ������� ����� ��������
	makearef(arPerksRoot, _chref.perks.list);
	perksQ = GetAttributesNum(arPerksRoot);
	ret = "";
	for(i=0; i<perksQ; i++)
	{
		perkName = GetAttributeName(GetAttributeN(arPerksRoot,i));

        if (CheckAttribute(&ChrPerksList, "list." + perkName) && CheckAttribute(&ChrPerksList, "list." + perkName + ".BaseType"))
        {
            if (ChrPerksList.list.(perkName).BaseType == _type)
            {
                ret += "* " + LanguageConvertString(lngFilePerkID, perkName) + " ";
            }
        }
	}
	LanguageCloseFile(lngFilePerkID);
	return ret;
}
// boal ��� ��������� 19.01.2004 -->
float GetItemsWeight(ref _chref)
{
    float   Amount = 0;
    int     j;
    string  itemID;
    ref     itm;

    if (bCabinStarted || bAbordageStarted || !bSeaActive || !CheckAttribute(_chref, "ItemsWeight"))
    {
        for (j=0; j<TOTAL_ITEMS; j++)
    	{
    		makeref(itm,Items[j]);
			
			if(CheckAttribute(itm, "ID"))
			{
				itemID = itm.id;
				if (CheckAttribute(_chref, "items."+itemID) && itemID != "MapsAtlas")      // ugeen - ����� ���� �� ��������� !!
				{
					Amount += sti(_chref.items.(itemID))*stf(itm.Weight);
				}
			}
        }
        _chref.ItemsWeight = Amount; // ����������� �������� � ��� �� ����
    }
    else
    {
        Amount = stf(_chref.ItemsWeight);
    }
    return Amount;
}
int GetMaxItemsWeight(ref _chref)
{
	if (CheckAttribute(_chref, "Skill.FencingS"))
    {
        int iBonus = 0;
        if (IsCharacterPerkOn(_chref, "Grus")) iBonus = 30;
                                  //������� ��������  ���� ������ GetCharacterSPECIAL
        iBonus = iBonus + CHAR_ITEMS_WEIGHT + GetCharacterSPECIALSimple(_chref, SPECIAL_S)*(GetCharacterSPECIALSimple(_chref, SPECIAL_E) + 12 - MOD_SKILL_ENEMY_RATE);
		if(IsEquipCharacterByArtefact(_chref, "obereg_3")) iBonus = makeint(iBonus * 1.15);
		if(IsEquipCharacterByArtefact(_chref, "indian_7")) iBonus = makeint(iBonus * 0.9);
        return  iBonus;
    }
    else
    {
        return 10000; // ������ ��� ���� �� ������ ����� � �����������
    }
}
// boal 19.01.2004 <--

// boal -->
int Statistic_AddValue(ref _chref, string _attrName, int _add) // set and get(_add==0) value
{
    // KillShip_ 1..6
    // AbordShip_ 1..6
    // KillAbordShip_ 1..6
    // Solder_s  Solder_g ( s=sword g=gun)
    // Citizen_s  Citizen_g
    // Monster_s Monster_g
    // Warrior_s  Warrior_g
    // Fort
	
	if(!CheckAttribute(_chref, "index")) return 0;
	
    if (sti(_chref.index) != GetMainCharacterIndex()) return 0; // �����������
    
    if( !CheckAttribute(_chref,"Statistic." + _attrName) )
    {
        _chref.Statistic.(_attrName) = 0;
    }
    _chref.Statistic.(_attrName) = sti(_chref.Statistic.(_attrName)) + _add;

    if (sti(_chref.Statistic.(_attrName)) < 0)
    {
        _chref.Statistic.(_attrName) = 0;
    }
    return sti(_chref.Statistic.(_attrName));
}
void Statistic_KillChar(aref _attack, aref _enemy, string _attrName)
{
	if (sti(_attack.index) != GetMainCharacterIndex()) return; // �����������
	string  name = GetCharType(_enemy);

	switch (name)
	{
		case "Solder" 	:
			Achievment_SetStat(_attack, 34, 1);
		break;		
		case "Citizen" 	:
			Achievment_SetStat(_attack, 35, 1);
		break;
		case "Indian"	:
			Achievment_SetStat(_attack, 36, 1);
		break;
		case "Monster"	:
			Achievment_SetStat(_attack, 37, 1);
		break;
		case "Crab"		:
			Achievment_SetStat(_attack, 38, 1);
		break;	
		case "Pirate"	:
			Achievment_SetStat(_attack, 53, 1);
		break;
		case "Marginal"		:
			Achievment_SetStat(_attack, 52, 1);
		break;
	}	
	
	name = name + _attrName;

	Statistic_AddValue(_attack, name, 1);
}

// --> ������ 
// -->> ��������� �������
string Achievment_GetID(int achievNum)
{
	string id = "";
	switch (achievNum)
	{
		case  1  :	id = "ach_01"; break;
		case  2  :	id = "ach_02"; break;
		case  3  :	id = "ach_03"; break;
		case  4  :	id = "ach_04"; break;
		case  5  :	id = "ach_05"; break;
		case  6  :	id = "ach_06"; break;
		case  7  :	id = "ach_07"; break;
		case  8  :	id = "ach_08"; break;
		case  9  :	id = "ach_09"; break;
		case 10  :	id = "ach_10"; break;
		case 11  :	id = "ach_11"; break;
		case 12  :	id = "ach_12"; break;
		case 13  :	id = "ach_13"; break;
		case 14  :	id = "ach_14"; break;
		case 15  :	id = "ach_15"; break;
		case 16  :	id = "ach_16"; break;
		case 17  :	id = "ach_17"; break;
		case 18  :	id = "ach_18"; break;
		case 19  :	id = "ach_19"; break;
		case 20  :	id = "ach_20"; break;
		case 21  :	id = "ach_21"; break;
		case 22  :	id = "ach_22"; break;
		case 23  :	id = "ach_23"; break;
		case 24  :	id = "ach_24"; break;
		case 25  :	id = "ach_25"; break;
		case 26  :	id = "ach_26"; break;
		case 27  :	id = "ach_27"; break;
		case 28  :	id = "ach_28"; break;
		case 29  :	id = "ach_29"; break;
		case 30  :	id = "ach_30"; break;
		case 31  :	id = "ach_31"; break;
		case 32  :	id = "ach_32"; break;
		case 33  :	id = "ach_33"; break;
		case 34  :	id = "ach_34"; break;
		case 35  :	id = "ach_35"; break;
		case 36  :	id = "ach_36"; break;
		case 37  :	id = "ach_37"; break;
		case 38  :	id = "ach_38"; break;
		case 39  :	id = "ach_39"; break;
		case 40  :	id = "ach_40"; break;
		case 41  :	id = "ach_41"; break;
		case 42  :	id = "ach_42"; break;
		case 43  :	id = "ach_43"; break;
		case 44  :	id = "ach_44"; break;
		case 45  :	id = "ach_45"; break;
		case 46  :	id = "ach_46"; break;
		case 47  :	id = "ach_47"; break;
		case 48  :	id = "ach_48"; break;
		case 49  :	id = "ach_49"; break;
		case 50  :	id = "ach_50"; break;
		case 51  :	id = "ach_51"; break;		
		case 52  :	id = "ach_52"; break;
		case 53  :	id = "ach_53"; break;
		case 54  :	id = "ach_54"; break;
		case 55  :	id = "ach_55"; break;
//		case 56  :	id = "ach_56"; break;
		case 57  :	id = "ach_57"; break;
		case 58  :	id = "ach_58"; break;
		case 59  :	id = "ach_59"; break;
		case 60  :	id = "ach_60"; break;
		case 61  :	id = "ach_61"; break;
		case 62  :	id = "ach_62"; break;
		case 63  :	id = "ach_63"; break;
		case 64  :	id = "ach_64"; break;
		case 65  :	id = "ach_65"; break;
		case 66  :	id = "ach_66"; break;
		case 67  :	id = "ach_67"; break;
		case 68  :	id = "ach_68"; break;
		case 69  :	id = "ach_69"; break;
		case 70  :	id = "ach_70"; break;
		case 71  :	id = "ach_71"; break;
//		case 72  :	id = "ach_72"; break;
//		case 73  :	id = "ach_73"; break;
		case 79  :	id = "ach_79"; break;
	}
	return id;
}

string Stat_GetID(int achievNum)
{
	string id = "";
	switch (achievNum)
	{
		case  1  :	id = "stat_03"; break;
		case  2  :	id = "stat_02"; break;
		case  3  :	id = "stat_03"; break;
		case  4  :	id = "stat_04"; break;
		case  5  :	id = "stat_05"; break;
		case  6  :	id = "stat_06"; break;
		case  7  :	id = "stat_07"; break;
		case  8  :	id = "stat_08"; break;
		case  9  :	id = "stat_09"; break;
		case 10  :	id = "stat_10"; break;
		case 11  :	id = "stat_11"; break;
		case 12  :	id = "stat_12"; break;
		case 13  :	id = "stat_13"; break;
		case 14  :	id = "stat_14"; break;
		case 15  :	id = "stat_15"; break;
		case 16  :	id = "stat_16"; break;
		case 17  :	id = "stat_17"; break;
		case 18  :	id = "stat_18"; break;
		case 19  :	id = "stat_19"; break;
		case 20  :	id = "stat_20"; break;
		case 21  :	id = "stat_21"; break;
		case 22  :	id = "stat_22"; break;
		case 23  :	id = "stat_23"; break;
		case 24  :	id = "stat_24"; break;
		case 25  :	id = "stat_25"; break;
		case 26  :	id = "stat_26"; break;
		case 27  :	id = "stat_27"; break;
		case 28  :	id = "stat_28"; break;
		case 29  :	id = "stat_29"; break;
		case 30  :	id = "stat_30"; break;
		case 31  :	id = "stat_31"; break;
		case 32  :	id = "stat_32"; break;
		case 33  :	id = "stat_33"; break;
		case 34  :	id = "stat_34"; break;
		case 35  :	id = "stat_35"; break;
		case 36  :	id = "stat_36"; break;
		case 37  :	id = "stat_37"; break;
		case 38  :	id = "stat_38"; break;
		case 39  :	id = "stat_39"; break;
		case 40  :	id = "stat_40"; break;
		case 41  :	id = "stat_41"; break;
		case 42  :	id = "stat_42"; break;
		case 43  :	id = "stat_43"; break;
		case 44  :	id = "stat_44"; break;
		case 45  :	id = "stat_45"; break;
		case 46  :	id = "stat_46"; break;
		case 47  :	id = "stat_47"; break;
		case 48  :	id = "stat_48"; break;
		case 49  :	id = "stat_49"; break;
		case 50  :	id = "stat_50"; break;
		case 51  :	id = "stat_51"; break;		
		case 52  :	id = "stat_52"; break;
		case 53  :	id = "stat_53"; break;
		case 54  :	id = "stat_54"; break;
		case 55  :	id = "stat_55"; break;
//		case 56  :	id = "stat_56"; break;
		case 57  :	id = "stat_57"; break;
		case 58  :	id = "stat_58"; break;
		case 59  :	id = "stat_59"; break;
		case 60  :	id = "stat_60"; break;
		case 61  :	id = "stat_61"; break;
		case 62  :	id = "stat_62"; break;
		case 63  :	id = "stat_63"; break;
		case 64  :	id = "stat_64"; break;
		case 65  :	id = "stat_65"; break;
		case 66  :	id = "stat_66"; break;
		case 67  :	id = "stat_67"; break;
		case 68  :	id = "stat_68"; break;
		case 69  :	id = "stat_69"; break;
		case 70  :	id = "stat_70"; break;
		case 71  :	id = "stat_71"; break;
//		case 72  :	id = "stat_72"; break;
//		case 73  :	id = "stat_73"; break;
		case 79  :	id = "stat_79"; break;
	}
	return id;
}
// <<-- ��������� �������
//#event_handler("NextDay","AchievmentsDayUpdateStart");
#event_handler("EvAchievmentsDayUpdate","AchievmentsDayUpdate");
int AchievmentsDayUpdateCnt = 0;
void AchievmentsDayUpdateStart()
{	
	trace("AchievmentsDayUpdateStart() " + AchievmentsDayUpdateCnt );
	if(AchievmentsDayUpdateCnt == 0 ) 
	{
		AchievmentsDayUpdateCnt = 1;
	}
	PostEvent("EvAchievmentsDayUpdate", 500);	
}

void AchievmentsDayUpdate()
{
	if(AchievmentsDayUpdateCnt > 0)
	{
		trace("AchievmentsDayUpdate() " + AchievmentsDayUpdateCnt );
		CheckAchievments(pchar, AchievmentsDayUpdateCnt);
		AchievmentsDayUpdateCnt++;
		if(AchievmentsDayUpdateCnt > MAX_ACHIEVMENTS) 
		{
			AchievmentsDayUpdateCnt = 0;
			trace("reset AchievmentsDayUpdate() " + AchievmentsDayUpdateCnt );
		}	
		else PostEvent("EvAchievmentsDayUpdate", 500);
	}
}

void CheckAchievments(ref _chref, int achievNum)
{
	int 	iTmp, achState;
	bool 	bOk = false;

	if(!CheckAttribute(_chref, "index")) return;
	
    if (sti(_chref.index) != GetMainCharacterIndex()) return; // �����������, ������� ���� �� ��
	
	if(!bSteamAchievements) return;	
	
	switch (achievNum)
	{		
		case 5 :	// ����������� :  ������� >= 40
			if(sti(_chref.rank) >= 40) Achievment_SetStat(_chref, 5, 1);
		break;			
		case 11 : 	// �������� ������ : (����� = 100%)
			if(GetSkillValue(_chref, SKILL_TYPE, SKILL_FORTUNE) >= 100)	Achievment_SetStat(_chref, 11, 1);
		break;
		case 12 : 	// ������������ : (���� � �� = 100%)
			if(GetSkillValue(_chref, SKILL_TYPE, SKILL_F_LIGHT) >= 100)	Achievment_SetStat(_chref, 12, 1);
		break;
		case 13 : 	// ����� : (���� � �� = 100%)
			if(GetSkillValue(_chref, SKILL_TYPE, SKILL_FENCING) >= 100)	Achievment_SetStat(_chref, 13, 1);
		break;
		case 14 : 	// ������ : (���� � �� = 100%)
			if(GetSkillValue(_chref, SKILL_TYPE, SKILL_F_HEAVY) >= 100)	Achievment_SetStat(_chref, 14, 1);
		break;		
		case 15 : 	// ����� : (���������� = 100%)
			if(GetSkillValue(_chref, SKILL_TYPE, SKILL_SNEAK) >= 100)	Achievment_SetStat(_chref, 15, 1);
		break;
		case 16 : 	// ������� ������ : (������ = 100%)
			if(GetSkillValue(_chref, SKILL_TYPE, SKILL_DEFENCE) >= 100)	Achievment_SetStat(_chref, 16, 1);
		break;
		case 17 : 	// ������� : (��������� = 100%)
			if(GetSkillValue(_chref, SKILL_TYPE, SKILL_SAILING) >= 100)	Achievment_SetStat(_chref, 17, 1);
		break;
		case 18 : 	// ��������� : (�������� = 100%)
			if(GetSkillValue(_chref, SKILL_TYPE, SKILL_COMMERCE) >= 100) Achievment_SetStat(_chref, 18, 1);
		break;						
		case 19  :	// ������ :  ������� ������������ ���������
			if(sti(_chref.reputation.nobility) > 95) Achievment_SetStat(_chref, 19, 1);
		break;
		case 20  :	// ���� : ������� ����������� ���������
			if(sti(_chref.reputation.nobility) < 5) Achievment_SetStat(_chref, 20, 1);
		break;		
		case 28  :	// ������ : ��������� ������� >= 10 000 000
			if(sti(_chref.money) >= 10000000) Achievment_SetStat(_chref, 28, 1);
		break;		
		case 30  :	// ���������� : ������� ������������ �������
			if(GetRemovableCompanionsNumber(_chref) == COMPANION_MAX) Achievment_SetStat(_chref, 30, 1);
		break;		
		case 32  :	// ����������� : ������� �������� �� ��������
			if(GetHealthNum(_chref) <= 5) Achievment_SetStat(_chref, 32, 1);
		break;
		case 33  :	// ������������ : ������� ��������� �� 100 ��������
			if(CheckItemMyCabin("icollection") >= 100 || GetCharacterItem(_chref, "icollection") >= 100 ) Achievment_SetStat(_chref, 33, 1);
		break;						
		case 42  :	// ��������� :  ������ � ����������� �� 5000000 ����
			if(CheckTotalDepositsSum(_chref, 5000000)) Achievment_SetStat(_chref, 42, 1);
		break;		
		case 44  :	// ����� ������� -  ����������� �� ���������
			if(CheckAttribute(_chref,"questTemp.HWIC.Detector") && (_chref.questTemp.HWIC.Detector == "holl_win")) Achievment_SetStat(_chref, 44, 1);
		break;
		case 45  :	// �� ������ ������� -  ����������� �� ������
			if(CheckAttribute(_chref,"questTemp.HWIC.Detector") && (_chref.questTemp.HWIC.Detector == "eng_win")) Achievment_SetStat(_chref, 45, 1);
		break;
		case 46  :	// �� ���� ������ - ����������� "������ ����"
			if(CheckAttribute(_chref,"questTemp.HWIC.Detector") && (_chref.questTemp.HWIC.Detector == "self_win")) Achievment_SetStat(_chref, 46, 1);
		break;
		case 47  :	// ������������ -  ���������� �����
			if(CheckAttribute(_chref, "questTemp.Tieyasal_FailEnd")) Achievment_SetStat(_chref, 47, 1);
		break;
		case 48  :	// �������� -  ��������� �����
			if(CheckAttribute(_chref, "questTemp.Tieyasal_WinEnd")) Achievment_SetStat(_chref, 48, 1);
		break;
		case 49  :  // ������� ������ -  ����� ��������� �������
			if(CheckAttribute(_chref, "questTemp.Caleuche.Abordage") && (RealShips[sti(_chref.Ship.Type)].BaseType == SHIP_CURSED_FDM)) Achievment_SetStat(_chref, 49, 1);
		break;
		case 54  :  // "��������������" - �������� ��� ������� (�������) 
			if(sti(pchar.questTemp.TavernVisit.counter) == 28) Achievment_SetStat(_chref, 54, 1);
		break;
		case 55  :  // "������� ��������������" - ������ �������� �� ��� ���������
		    if(CheckForAllOfficers()) Achievment_SetStat(_chref, 55, 1);
		break;
	
		case 62  :  // �� ��� �������������� ����� �� ���������
			if(CheckAttribute(_chref, "Mangarosa.Alchemy.MP") && CheckAttribute(_chref, "Mangarosa.Alchemy.MF") && CheckAttribute(_chref, "Mangarosa.Alchemy.MT")) Achievment_SetStat(_chref, 62, 1);
		break;
		case 63  :  // �� ������ �� ���� ������ ����������
			if(sti(pchar.questTemp.ShipyardVisit.counter) == 23) Achievment_SetStat(_chref, 63, 1);
		break;
		case 66  :  // �� ������ ������� �������
			if(CheckAttribute(_chref, "achievment.Tuning.stage1") && CheckAttribute(_chref, "achievment.Tuning.stage2") && CheckAttribute(_chref, "achievment.Tuning.stage3") && CheckAttribute(_chref, "achievment.Tuning.stage4")) Achievment_SetStat(_chref, 66, 1);
		break;	
		case 69  :  // "����" ������-���������
			if(CheckAttribute(_chref,"questTemp.ShipCapellan.Yes") && (_chref.questTemp.ShipCapellan.Yes == "true")) Achievment_SetStat(_chref, 69, 1);
		break;
/*		
		case 72  :  // "�������" - ��������� � ���� 500 �����
		    if(GetPlayTimeHours() >= 500) Achievment_SetStat(_chref, 72, 1);
		break;
		case 73  :  // "�������" - ��������� � ���� 1000 �����
		    if(GetPlayTimeHours() >= 1000) Achievment_SetStat(_chref, 73, 1);
		break;
*/		
	}	
}

void Achievment_SetStat(ref _chref, int achievNum, int _add)
{
	string sAchiev, sStat;
	string id, aName;
	string sAttr = "a" + (achievNum);
	int    achState, curState;
	int	   iOk;
	bool   bOk = false;
	bool   bSuccess;

	if(!CheckAttribute(_chref, "index")) return;
	
	if(_add <= 0) return;
	
    if(sti(_chref.index) != GetMainCharacterIndex()) return;
	
	if(!bSteamAchievements) return;
	
	sAchiev = Achievment_GetID(achievNum);
	achState = GetAchievement(sAchiev);
	trace("Check Achievment :" + achievNum + " state :" + achState);
	if(achState == 1) 
	{
		return;  // ����� ��� ��������, ������ �� ������, ���� ������� - ��� ��������
	}

	sStat = Stat_GetID(achievNum);
	curState = GetStat(sStat);			// �������� ������� �������� ���������� ��� ������� ���������� ����� achievNum

	SetStat(sStat, curState + _add); 	// ��������� � ���������� ��������
	curState = curState + _add;
	
	bSuccess = StoreStats();			// ���������� � ����!!
	if(bSuccess) 	trace("StoreStats() ok !!");
	else
	{	
		trace("StoreStats() error !!");
		return;
	}	
	
	switch (achievNum)
	{
		case 1  :	// ������ �������� : ������ ������� ������ � ����
			if(curState >= 1)
			{
				aName = "������ ��������";
				bOk = true;
			}
		break;
		case 2  :	// ���������� - ������� �������� (250)
			if(curState >= 250)
			{
				aName = "����������";
				bOk = true;
			}
		break;
		case 3  :	// ������� ���� - ����������� �������� (500)
			if(curState >= 500)
			{
				aName = "������� ����";
				bOk = true;
			}
		break;		
		case 4  :	// ���������� ����� : ��������� ��������� ������� ����
			if(curState >= 1)
			{
				aName = "���������� �����";
				bOk = true;
			}
		break;		
		case 5 :	// ����������� :  ������� >= 40
			if(curState >= 1)			
			{
				aName = "�����������";
				bOk = true;
			}
		break;	
		case 6 :	// �������� ������� : ��������� �������� >= 10000
			if(curState >= 10000)			
			{
				aName = "�������� �������";
				bOk = true;
			}		
		break;
		case 7 :	// ������� : ���-�� ����� ������� >= 200
			if(curState >= 200)
			{	
				aName = "�������";
				bOk = true;			
			}
		break;	
		case 8	:	// ������������� : (>= 100 ������� ������)
			if(CurState >= 100)
			{	
				aName = "�������������";
				bOk = true;			
			}		
		break;		
		case 9  :	// �������� : ������ � ������
			if(curState >= 1)
			{
				aName = "��������";
				bOk = true;
			}
		break;				
		case 10 :	// Home sweet home : ���������� ������ ����
			if(curState >= 1)			
			{
				aName = "Home sweet home";
				bOk = true;
			}
		break;		
		case 11 : 	// �������� ������ : (����� = 100%)
			if(curState >= 1)			
			{
				aName = "�������� ������";
				bOk = true;
			}
		break;
		case 12 : 	// ������������ : (���� � �� = 100%)			
			if(curState >= 1)			
			{
				aName = "������������";
				bOk = true;
			}
		break;
		case 13 : 	// ����� : (���� � �� = 100%)
			if(curState >= 1)			
			{
				aName = "�����";
				bOk = true;
			}
		break;
		case 14 : 	// ������ : (���� � �� = 100%)
			if(curState >= 1)			
			{
				aName		= "������";
				bOk = true;
			}			
		break;		
		case 15 : 	// ����� : (���������� = 100%)
			if(curState >= 1)			
			{
				aName = "�����";
				bOk = true;
			}			
		break;
		case 16 : 	// ������� ������ : (������ = 100%)			
			if(curState >= 1)			
			{
				aName = "������� ������";
				bOk = true;
			}
		break;
		case 17 : 	// ������� : (��������� = 100%)
			if(curState >= 1)			
			{
				aName = "�������";
				bOk = true;
			}
		break;
		case 18 : 	// ��������� : (�������� = 100%)
			if(curState >= 1)			
			{
				aName = "���������";
				bOk = true;
			}
		break;						
		case 19  :	// ������ :  ������� ������������ ���������
			if(curState >= 1)			
			{
				aName = "������";
				bOk = true;
			}
		break;
		case 20  :	// ���� : ������� ����������� ���������
			if(curState >= 1)			
			{
				aName = "����";
				bOk = true;
			}
		break;		
		case 21  :	// ������� : 9999 �������� �������� � ������� ��
			if(curState >= 9999)
			{
				aName = "�������";
				bOk = true;
			}
		break;
		case 22  :	// ������� : ���������� >= 15 ������
			if(curState >= 15)
			{
				aName = "�������";
				bOk = true;
			}		
		break;
		case 23  :	// �������� " �������� ������� 100 ���
			if(curState >= 100)
			{
				aName = "��������";
				bOk = true;
			}
		break;
		case 24  :	// ��������� : ���������� � ������� >=50 ���
			if(curState >= 50)
			{
				aName = "���������";
				bOk = true;
			}
		break;
		case 25  :	// �������� ����� : (������� � �����/����� >= 500 )	
			if(curState >= 500)
			{
				aName = "�������� �����";
				bOk = true;
			}
		break;
		case 26  :	// �������� : (�������� � �����/����� >= 500 )		
			if(curState >= 500)
			{
				aName = "��������";
				bOk = true;
			}		
		break;
		case 27  :	// ������� : �������� �� ��������� >= 500
			if(curState >= 500)
			{
				aName = "�������";
				bOk = true;
			}		
		break;		
		case 28  :	// ������ : ��������� ������� >= 10 000 000
			if(curState >= 1)			
			{
				aName = "������";
				bOk = true;
			}		
		break;
		case 29  :	// ������ ������ : ����� � ������� ���������������� (>= 100)
			if(curState >= 100)
			{
				aName = "������ ������";
				bOk = true;
			}		
		break;		
		case 30  :	// ���������� : ������� ������������ �������
			if(curState >= 1)			
			{
				aName = "����������";
				bOk = true;
			}
		break;		
		case 31  :	// ������������� : >=50 ������� ������ � ����������������
			if(curState >= 50)
			{
				aName = "�������������";
				bOk = true;
			}		
		break;		
		case 32  :	// ����������� : ������� �������� �� ��������
			if(curState >= 1)			
			{
				aName = "�����������";
				bOk = true;
			}		
		break;
		case 33  :	// ������������ : ������� ��������� �� 100 ��������
			if(CurState >= 1)			
			{
				aName = "������������";
				bOk = true;
			}		
		break;		
		case 34  :	// ������ ������ : �������� ������� (>=500)
			if(curState >= 500)
			{
				aName = "������ ������";
				bOk = true;
			}		
		break;
		case 35  :	// ������������ : �������� ����������� (>= 500)
			if(curState >= 500)
			{
				aName = "������������";
				bOk = true;
			}		
		break;
		case 36  :	// ����������� :  �������� �������� (>=250)
			if(curState >= 250)
			{
				aName = "�����������";
				bOk = true;
			}				
		break;
		case 37  :	// ��������� :  �������� ������� (>=100)
			if(CurState >= 100)
			{
				aName = "���������";
				bOk = true;
			}				
		break;
		case 38  :	// ������� ����� : �������� ������ (>=35)
			if(curState >= 35)
			{
				aName = "������� �����";
				bOk = true;
			}				
		break;
		case 39  :	// �������� : ���������� ���������/������������ 10000000
			if(CurState >= 10000000)
			{
				aName = "��������";
				bOk = true;
			}						
		break;		
		case 40  :	// ������������� : ����������� ����� (>=50)
			if(CurState >= 50)
			{
				aName = "�������������";
				bOk = true;
			}						
		break;
		case 41  :	// ������ : ������� ��������� 200 ���
			if(curState >= 200)
			{
				aName = "������";
				bOk = true;
			}						
		break;		
		case 42  :	// ��������� :  ������ � ����������� �� 5000000 ����
			if(curState >= 1)			
			{
				aName		= "���������";
				bOk = true;
			}						
		break;		
		case 43  :	// ������������ : ������� >= 5000 �����
			if(curState >= 5000)			
			{
				aName = "������������";
				bOk = true;
			}				
		break;		
		case 44  :	// ����� ������� -  ����������� �� ���������
			if(curState >= 1)			
			{
				aName = "����� �������";
				bOk = true;
			}
		break;
		case 45  :	// �� ������ ������� -  ����������� �� ������
			if(curState >= 1)			
			{
				aName = "�� ������ �������";
				bOk = true;
			}
		break;
		case 46  :	// �� ���� ������ - ����������� "������ ����"			
			if(curState >= 1)			
			{
				aName = "�� ���� ������";
				bOk = true;
			}
		break;
		case 47  :	// ������������ -  ���������� �����
			if(curState >= 1)			
			{
				aName = "������������";
				bOk = true;
			}
		break;
		case 48  :	// �������� -  ��������� �����
			if(curState >= 1)			
			{
				aName = "��������";
				bOk = true;
			}
		break;
		case 49  :  // ������� ������ -  ����� ��������� �������
			if(curState >= 1)			
			{
				aName = "������� ������";
				bOk = true;
			}
		break;		
		case 50  :	// ������� ��������� -  ������� ��� ��������� ������ >=100 ��������
			if(curState >= 100)
			{
				aName = "������� ���������";
				bOk = true;
			}
		break;	
		case 51  :  // ���� ������ - �������� ������� ���
			if(curState >= 1)
			{
				aName = "���� ������";
				bOk = true;
			}
		break;		
		case 52  :  // "��������" - �������� �������� >= 250
			if(curState >= 250)			
			{
				aName = "��������";
				bOk = true;
			}		
		break;
		case 53  : // "����� ����������" - �������� ������� >= 500
			if(curState >= 500)			
			{
				aName = "����� ����������";
				bOk = true;
			}		
		break;
		case 54  :  // "��������������" - �������� ��� ������� (�������)
			if(curState >= 1)			
			{
				aName = "��������������";
				bOk = true;
			}		
		break;
		case 55  :  // "������� ��������������" - ������ �������� �� ��� ���������
			if(curState >= 1)			
			{
				aName = "������� ��������������";
				bOk = true;
			}		
		break;
/*		
		case 56  :  // "����� �����" - ��������� DLC #4
			if(curState >= 1)			
			{
				aName = "����� �����";
				bOk = true;
			}				
		break;
*/		
		case 57  :  // "�� ��������� ����" - ��������� DLC #3
			if(curState >= 1)			
			{
				aName = "�� ��������� ����";
				bOk = true;
			}						
		break;
		case 58  :  // "��� ������ ������" - ��������� DLC #3
			if(curState >= 1)			
			{
				aName = "��� ������ ������";
				bOk = true;
			}								
		break;
		case 59  :  // �� 50 �������� �������� (��������� �� ���������� �����)
			if(curState >= 50)			
			{
				aName = "���������";
				bOk = true;
			}
		break;
		case 60  :  // �� 20 �������� ��������� (��������� �� ���������� �����)
			if(curState >= 20)			
			{
				aName = "�����������";
				bOk = true;
			}				
		break;
		case 61  :  // �� 200 ����������/������������� � ��� ���
			if(curState >= 200)			
			{
				aName = "�����";
				bOk = true;
			}						
		break;
		case 62  :  // �� ��� �������������� ����� �� ���������
			if(curState >= 1)			
			{
				aName = "�������";
				bOk = true;
			}		
		break;
		case 63  :  // �� ������ �� ���� ������ ����������
			if(curState >= 1)			
			{
				aName = "�������� ������";
				bOk = true;
			}		
		break;
		case 64  :  // �� ��������������� ������ � �����
			if(curState >= 5)			
			{
				aName = "������";
				bOk = true;
			}				
		break;
		case 65  :  // �� ����������� ����� ��� ���������� ���������;
			if(curState >= 1)			
			{
				aName = "��������";
				bOk = true;
			}		
		break;
		case 66  :  // �� ������� �������
			if(curState >= 1)			
			{
				aName = "�����������";
				bOk = true;
			}				
		break;
		case 67  :  // �� ������ ������
			if(curState >= 1)			
			{
				aName = "���������";
				bOk = true;
			}		
		break;
		case 68  :  // �� ��������� ��������� ��������� ���� ������  (5)
			if(curState >= 5)			
			{
				aName = "������";
				bOk = true;
			}		
		break;
		case 69  :  // "����" ������-���������
			if(curState >= 1)			
			{
				aName = "�������� ������";
				bOk = true;			
			}
		break;				
		case 70  :  // �� ������ � �������� "��� �� ���" ))
			if(curState >= 1)			
			{
				aName = "����� ���";
				bOk = true;
			}				
		break;
		case 71  :  // "��������� ����������" - ��������� DLC #3
			if(curState >= 1)			
			{
				aName = "��������� ����������";
				bOk = true;
			}				
		break;
/*		
		case 72  :  // "�������" - �������� � ���� 500 �����
			if(curState >= 1)			
			{
				aName = "�������";
				bOk = true;
			}				
		break;
		case 73  :  // "�������" - �������� � ���� 1000 �����
			if(curState >= 1)			
			{
				aName = "�������";
				bOk = true;
			}				
		break;
*/		
		case 79  :  // "����� �����" - ��������� DLC #4
			if(curState >= 1)			
			{
				aName = "����� �����";
				bOk = true;
			}				
		break;
	}
		
	if(bOk)
	{			
		achState = SetAchievement(sAchiev); // ������������� ������ � ����
		if(achState == 1) 
		{
			Log_SetStringToLog("�������� ����� ���������� - '" + aName + "'!!");
		}	
	}		
	return;		
}
// <-- ������ 

string GetCharType(aref _enemy)  //TO_DO ���������� �� ��� � ���
{
    string  name  	= "Warrior"; // define
    string  model 	= _enemy.model;
	string  _type;
	int     iNation = sti(_enemy.nation);
	
    switch (_enemy.chr_ai.type)
	{
		case LAI_TYPE_PATROL :
		    name = "Solder";
		break
		case LAI_TYPE_GUARDIAN :
		    name = "Solder";
		break
		case LAI_TYPE_OFFICER :
		    name = "Solder";
		break;
        // Citizen
		case LAI_TYPE_ACTOR :
		    name = "Citizen";
		break;
		case LAI_TYPE_BARMAN :
		    name = "Citizen";
		break;
		case LAI_TYPE_CITIZEN :
		    name = "Citizen";
		break;
		case LAI_TYPE_HUBER :
		    name = "Citizen";
		break;
		case LAI_TYPE_HUBERSTAY :
		    name = "Citizen";
		break;
		case LAI_TYPE_MERCHANT :
		    name = "Citizen";
		break;
		case LAI_TYPE_POOR :
		    name = "Citizen";
		break;
		case LAI_TYPE_PRIEST :
		    name = "Citizen";
		break;
		case LAI_TYPE_SIT :
		    name = "Citizen";
		break;
		case LAI_TYPE_STAY :
		    name = "Citizen";
		break;
		case LAI_TYPE_WAITRESS :
		    name = "Citizen";
		break;
		case LAI_TYPE_OWNER :
		    name = "Citizen";
		break;

		case LAI_TYPE_WARRIOR : // to_do ��������� ���
			if (findsubstr(model, "canib_" , 0) != -1 || findsubstr(model, "itza_" , 0) != -1 || findsubstr(model, "miskito_" , 0) != -1)
			{
				name = "Indian";
			}
		    if (model == "mummy" || model == "Skel1" || model == "Skel2" || model == "Skel3" || model == "Skel4" || model == "skeletcap" || model == "giant")
		    {
		        name = "Monster";
		    }
		    else
		    {
				if (model == "crabBig")
				{
					name = "Crab";
				}				
                if (findsubstr(model, "off_" , 0) != -1)
                {
                    name = "Solder";
                }
                else
                {
                    if (findsubstr(model, "sold_" , 0) != -1)
	                {
	                    name = "Solder";
	                }
                }
				
				if (findsubstr(model, "pirate_" , 0) != -1 || findsubstr(model, "citiz_" , 0) != -1 || findsubstr(model, "mercen_" , 0) != -1 ) // ugeen 2016
				{
				
					if(CheckAttribute(_enemy,"PhantomType")) 
					{
						_type = _enemy.PhantomType;
						if(_type == "marginal" ) 
						{
							name = "marginal";
						}
					}
					else 
					{
						if(iNation == PIRATE)
						{
							name = "Pirate";
						}					
					}
				}					
				
		    }
		break;
	}

	return  name;
}
// boal statistic info 17.12.2003 <--

// boal ���� �������� �� -->
int GetHealthNum(ref ch)
{
    if (!CheckAttribute(ch, "Health"))
	{
        return 0;
	}
    int i;

    i = makeint((stf(ch.Health.HP) + 9) / 10.0); // �� ������

    return i;
}

int GetHealthMaxNum(ref ch)
{
    if (!CheckAttribute(ch, "Health"))
	{
        return 0;
	}
    int i;

    i = makeint((stf(ch.Health.maxHP) + 9) / 10.0); // �� ������

    return i;
}

string GetHealthName(ref ch)
{
    string name = "";

    switch (GetHealthNum(ch))
    {
        case 1:
            name = "�������";
        break;
        case 2:
            name = "������";
        break;
        case 3:
            name = "��������";
        break;
        case 4:
            name = "�������";
        break;
        case 5:
            name = "�������";
        break;
        case 6:
            name = "��������";
        break;
    }
    return name;
}

string GetHealthNameMaxSmall(ref ch)
{
    string name = "";

    switch (GetHealthMaxNum(ch))
    {
        case 1:
            name = "�������";
        break;
        case 2:
            name = "������";
        break;
        case 3:
            name = "��������";
        break;
        case 4:
            name = "�������";
        break;
        case 5:
            name = "�������";
        break;
        case 6:
            name = "��������";
        break;
    }
    return name;
}

void SetNewDayHealth()
{
    ref mainChr = GetMainCharacter();

    float maxhp = stf(mainChr.chr_ai.hp_max);
    float damg  = stf(mainChr.Health.Damg);
    int   add   = 0;

    mainChr.Health.Damg = 0.0;

    if (IsCharacterPerkOn(mainChr, "Medic"))
    {
        add = 1;
    }
	if(IsEquipCharacterByArtefact(mainChr, "amulet_6"))
	{
		add += 1;
	}
    if (damg >= (maxhp / 1.5) )
    {
        if ((damg / maxhp) > add)
        {
            AddCharacterHealth(mainChr, -damg / maxhp + add);
        }
    }
    else
    {
        if (!IsEntity(worldMap)) // �� �� �����
        {
            AddCharacterHealth(mainChr, 1 + add);
        }
        else
        {
            AddCharacterHealth(mainChr, 0.5 + add / 2.0);
        }
    }
}

void SetNewDayHealthMax()
{
    ref mainChr = GetMainCharacter();

    float maxhp = stf(mainChr.chr_ai.hp_max);
    float damg  = stf(mainChr.Health.weekDamg);

    mainChr.Health.weekDamg = 0.0;

    if (damg > (maxhp * 3.5 * isEquippedAmuletUse(mainChr, "amulet_6", 1.0, 1.15)))
    {
        AddCharacterMaxHealth(mainChr, -1);
    }
}

void AddCharacterHealth(ref mainChr, float add)
{
    float maxhp = stf(mainChr.chr_ai.hp_max);
    int   remHP = GetHealthNum(mainChr);

    mainChr.Health.HP = makefloat(stf(mainChr.Health.HP) + add);

    if (stf(mainChr.Health.HP) < 1)
    {
        mainChr.Health.HP = 1.0;
    }

    if (stf(mainChr.Health.HP) > stf(mainChr.Health.maxHP))
    {
        mainChr.Health.HP = stf(mainChr.Health.maxHP);
    }

    if (GetHealthNum(mainChr) > remHP)
    {
        Log_Info("�������� ����� �����");
    }

    if (GetHealthNum(mainChr) < remHP)
    {
        Log_Info("�������� ����� ����");
    }
}

void AddCharacterMaxHealth(ref mainChr, float add)
{
    mainChr.Health.maxHP = makefloat(stf(mainChr.Health.maxHP) + add);

    if (stf(mainChr.Health.maxHP) < 1)
    {
        mainChr.Health.maxHP = 1.0;
    }

    if (stf(mainChr.Health.maxHP) > 60)
    {
        mainChr.Health.maxHP = 60.0;
    }

    if (stf(mainChr.Health.HP) > stf(mainChr.Health.maxHP))
    {
        mainChr.Health.HP = stf(mainChr.Health.maxHP);
    }
}
// boal ���� �������� �� <--

// ���������� �������� ������� �� ������ -->
int ChangeCharacterHunterScore(ref chref, string _huntName, int incr)
{
	int prevVal = -5; // ��� �����

	if (_huntName == "pirhunter") return 0;
	if (CheckAttribute(chref, "GenQuest.HunterScore2Pause")) incr = 0;

	if (CheckAttribute(chref, "reputation." + _huntName) )	prevVal = sti(chref.reputation.(_huntName));

	int newVal = prevVal + incr;
	if (newVal < -100)  newVal = -100;
	if (newVal > 100)   newVal = 100;

	chref.reputation.(_huntName) = newVal;

	if( sti(chref.index) != GetMainCharacterIndex() ) return newVal;

	if (newVal >= 10)
	{
	 	if (prevVal < newVal)
		{
			Log_SetStringToLog(XI_ConvertString(_huntName) + " ��������� ������� �� ���� ������");
		}

	    if (prevVal > newVal)
		{
	        Log_SetStringToLog(XI_ConvertString(_huntName) + " ������� ������� �� ���� ������");
		}
	}
	else
	{
		int iNation = 0;
		switch (_huntName) // ��� ��� ������������� �� ������
		{
		    case "enghunter":  iNation = ENGLAND; break;
		    case "frahunter":  iNation = FRANCE; break;
		    case "spahunter":  iNation = SPAIN; break;
		    case "holhunter":  iNation = HOLLAND; break;
		}
		string prevName = GetNationReputationName(iNation, -prevVal);
		string newName  = GetNationReputationName(iNation, -newVal);
		if (prevName!=newName)
		{
			string outString = XI_ConvertString("Your reputation with country")+ XI_ConvertString(Nations[iNation].Name + "Gen") +" ";
			if (incr<0)	{outString+=XI_ConvertString("increase");}
			else	{outString+=XI_ConvertString("decrease");}
			outString += " "+XI_ConvertString("to")+" "+newName;
			Log_SetStringToLog(outString);
		}
	}
	return newVal;
}

int ChangeCharacterNationReputation(ref chref, int _Nation, int incr)
{
	return -ChangeCharacterHunterScore(chref, NationShortName(_Nation) + "hunter", -incr); // ��� ��������, - ��� ������, + ���� ���
}

string GetNationReputation(ref chref, int _Nation)
{
    return GetNationReputationName(_Nation, ChangeCharacterNationReputation(chref, _Nation, 0));
}

string GetNationReputationName(int _Nation, int i)
{
	if (i <= -10)  return "������� �� ������ " + (-i*1000);
    if (i < 0 )    return "����������";
    if (i <= 20 )  return "�����������";
    if (i <= 50 )  return "�������";
    if (i <= 80 )  return "��������";
    if (i <= 100 ) return "����������";

    return "��������";
}
// boal 04.04.04
string NationShortName(int iNation)
{
    switch(iNation)
	{
		case ENGLAND:
            return "eng";
		break;
		case FRANCE:
            return "fra";
		break;
		case SPAIN:
            return "spa";
		break;
		case HOLLAND:
			return "hol";
		break;
		case PIRATE:
			return "pir";
		break;
	}
	return "eng";
}
// ���������� �������� ������� �� ������ <--


void setWDMPointXZ(string _location)
{
    // ���������� �� ������ ����� -->
    int n;
	string sTemp;

    n = FindIslandBySeaLocation(_location);
	if(n!=-1)
	{
		worldMap.island = Islands[n].id;
		Pchar.curIslandId = worldMap.island; // fix
		sTemp = worldMap.island;
		if (CheckAttribute(&worldMap, "islands." + sTemp))
		{
		    worldMap.zeroX = worldMap.islands.(sTemp).position.x;
			worldMap.zeroZ = worldMap.islands.(sTemp).position.z;
			if (CheckAttribute(&worldMap, "islands." + sTemp + "." + _location))
			{
			    worldMap.playerShipX = worldMap.islands.(sTemp).(_location).position.x;
				worldMap.playerShipZ = worldMap.islands.(sTemp).(_location).position.z;
				//trace(sTemp + "." + _location);
			}
			else
			{// ��� ���� � ����������� ������������
			    worldMap.playerShipX = worldMap.zeroX;
				worldMap.playerShipZ = worldMap.zeroZ;
			}
		}
	}
	// ���������� �� ������ ����� <--
}


// ����� �� ����������� ��� � �������� �������
void ChangeAttributesFromCharacter(ref CopyChref, ref PastChref, bool _dialogCopy)
{
    aref arToChar;
    aref arFromChar;

    CopyChref.model            = PastChref.model;
    CopyChref.model.animation  = PastChref.model.animation;
    CopyChref.sex              = CopyChref.sex;
    CopyChref.headModel        = PastChref.headModel;
    CopyChref.FaceId           = PastChref.FaceId;
    CopyChref.nation           = PastChref.nation;

	CopyChref.name             = PastChref.name;
    CopyChref.lastname         = PastChref.lastname;

    CopyChref.rank             = PastChref.rank;
    CopyChref.reputation       = makeint(PastChref.reputation);
	
	CopyChref.baseCapIdx       = PastChref.index; //Id ������������� � ��������� �����

    if (CheckAttribute(PastChref, "loyality"))
    {
    	CopyChref.loyality         = PastChref.loyality;
	}
	else DeleteAttribute(CopyChref, "loyality");
	if (CheckAttribute(PastChref, "alignment"))
	{
    	CopyChref.alignment        = PastChref.alignment;
    }
    else DeleteAttribute(CopyChref, "alignment");

    CopyChref.Money            = PastChref.Money;

    CopyChref.chr_ai.hp         = makeint(PastChref.chr_ai.hp);
    CopyChref.chr.chr_ai.hp_max = makeint(PastChref.chr_ai.hp_max);

    LAi_SetHP(CopyChref, makeint(PastChref.chr_ai.hp_max), makeint(PastChref.chr_ai.hp_max));
	LAi_SetCurHPMax(CopyChref);
	
	//�������� ��������� quest �� ������������� ����, ����� ����� �� ������� :)
	if (CheckAttribute(PastChref, "quest"))
    {
	    aref arToCharQuest, arFromCharQuest;
		makearef(arFromCharQuest, PastChref.quest);
		makearef(arToCharQuest, CopyChref.quest);
		DeleteAttribute(arToCharQuest, "");
		CopyAttributes(arToCharQuest, arFromCharQuest);
	}
	
	if (CheckAttribute(PastChref, "quest.officertype"))
    {
        CopyChref.quest.officertype     =   PastChref.quest.officertype;
    }
    else
    {
        DeleteAttribute(CopyChref, "quest.officertype");
    }

    if (CheckAttribute(PastChref, "Payment"))
    {
        CopyChref.Payment     =   PastChref.Payment; // ������� ��
    }
    else
    {
        DeleteAttribute(CopyChref, "Payment");
    }
    if (CheckAttribute(PastChref, "HoldEquip"))
    {
        CopyChref.HoldEquip   =   PastChref.HoldEquip; // �� �������� ����� � �������
    }
	else
    {
        DeleteAttribute(CopyChref, "HoldEquip");
    }
    if (CheckAttribute(PastChref, "SaveItemsForDead"))
    {
        CopyChref.SaveItemsForDead   =   true;
    }
	else
    {
        DeleteAttribute(CopyChref, "SaveItemsForDead");
    }
    if (CheckAttribute(PastChref, "DontClearDead"))
    {
        CopyChref.DontClearDead   =   true;
    }
	else
    {
        DeleteAttribute(CopyChref, "DontClearDead");
    }
    if (CheckAttribute(PastChref, "OfficerWantToGo.DontGo"))
    {
        CopyChref.OfficerWantToGo.DontGo   =   true;
    }
	else
    {
        DeleteAttribute(CopyChref, "OfficerWantToGo.DontGo");
    }
    // skill
    DeleteAttribute(CopyChref, "skill");
    CopyChref.skill = "";

    makearef(arToChar, CopyChref.skill);
    makearef(arFromChar, PastChref.skill);

    CopyAttributes(arToChar,arFromChar);

    // SPECIAL
    DeleteAttribute(CopyChref, "SPECIAL");
    CopyChref.SPECIAL = "";

    makearef(arToChar, CopyChref.SPECIAL);
    makearef(arFromChar, PastChref.SPECIAL);

    CopyAttributes(arToChar,arFromChar);

    // Statistic
    DeleteAttribute(CopyChref, "Statistic");
    CopyChref.Statistic = "";

    makearef(arToChar, CopyChref.Statistic);
    makearef(arFromChar, PastChref.Statistic);

    CopyAttributes(arToChar,arFromChar);

    // perks
    DeleteAttribute(CopyChref, "perks");
    CopyChref.perks = "";

    makearef(arToChar, CopyChref.perks);
    makearef(arFromChar, PastChref.perks);

    CopyAttributes(arToChar,arFromChar);
    // items
    DeleteAttribute(CopyChref, "Items");
    CopyChref.Items = "";

    makearef(arToChar, CopyChref.Items);
    makearef(arFromChar, PastChref.Items);

    CopyAttributes(arToChar,arFromChar);
	
	// equipped items
	DeleteAttribute(CopyChref, "equip_item");
	CopyChref.equip_item = "";
	makearef(arToChar, CopyChref.equip_item);
    makearef(arFromChar, PastChref.equip_item);

    CopyAttributes(arToChar,arFromChar);
	

    if (CheckAttribute(PastChref, "equip.blade"))
    {
		CopyChref.equip.blade =   PastChref.equip.blade;
	}
	if (CheckAttribute(PastChref, "equip.gun"))
    {
		CopyChref.equip.gun   =   PastChref.equip.gun;
	}
	// health
	if (CheckAttribute(PastChref, "Health.TotalDamg"))
    {
		CopyChref.Health.TotalDamg =   PastChref.Health.TotalDamg;
	}
	else
	{
        CopyChref.Health.TotalDamg = 0;
	}
	
	if (CheckAttribute(PastChref, "PerkValue.EnergyPlus"))
	{
		CopyChref.PerkValue.EnergyPlus =   PastChref.PerkValue.EnergyPlus;
	}

	// ugeen --> ����� ��� ��������� ��������� �������� � ����� ��������������� ����
	if (CheckAttribute(PastChref,"Situation")) // ���� � ����� ���� �������� �������� 
	{
		CopyChref.Situation = PastChref.Situation;
		CopyChref.Situation.type = PastChref.Situation.type;
	}
	
	if (CheckAttribute(PastChref,"EncType"))
	{
		CopyChref.EncType = PastChref.EncType;
	}
	
	if (CheckAttribute(PastChref,"RealEncounterType"))
	{
		CopyChref.RealEncounterType = PastChref.RealEncounterType;
	}

	if (CheckAttribute(PastChref,"Ship"))
	{
		makearef(arToChar, CopyChref.Back.Ship);
		makearef(arFromChar, PastChref.Ship);
		CopyAttributes(arToChar, arFromChar);		
	}	
	// <-- ugeen
	
	if (_dialogCopy && CheckAttribute(PastChref, "Dialog.Filename"))
	{
	    CopyChref.Dialog.Filename    = PastChref.Dialog.Filename;
	    CopyChref.Dialog.CurrentNode = PastChref.Dialog.CurrentNode;
	    if (CheckAttribute(PastChref, "greeting")) CopyChref.greeting = PastChref.greeting; //eddy.��� �����!
		else
		{
			DeleteAttribute(CopyChref, "greeting");
		}
	}
	SetEnergyToCharacter(CopyChref);
	//SetNewModelToChar(CopyChref);  // ���� ����� ���� ����������
}

int GetCharacterLoyality(ref chr)
{
    if (CheckAttribute(chr, "loyality"))
    {
        if (sti(chr.loyality) > MAX_LOYALITY)
        {
            chr.loyality = MAX_LOYALITY;
        }
        if (sti(chr.loyality) < 0)
        {
            chr.loyality = 0;
        }
        return sti(chr.loyality);
    }
    else
    {
        return  0; // ��� ������� � ��
    }
}

void CCS_SetNewMainCharacter(ref ch, int num)
{
	if(num < 1) num = 1;
	switch (num)
	{
		case 1: //����� �� ���
			ch.FaceId 				= 201;
			ch.HeroModel 			= "Sharle_1,Sharle_2,Sharle_3,Sharle_4,Sharle_5,protocusto,Sharle_6,Sharle_8";
			ch.name 				= "�����";
			ch.lastname				= "�� ���";
			ch.nameGen				= "�����";
			ch.lastnameGen			= "�� ����";
			ch.nameDat				= "�����";
			ch.lastnameDat			= "�� ����";
			ch.sex					= "man";
			ch.model.animation 		= "man_A";
			ch.HeroParam.HeroType 	= "HeroType_1";
			ch.nation				= FRANCE;
			ch.BaseNation			= FRANCE;
			ch.info					= "C�� ������������ ���������, ������ � �������, ������ �� ������, ����� ����� ��� ����� ���������� �����. " + 
									  "����� ��� ��������� ������� ����, ������� ����� ����� ���������, ����������� � �����, ��������� � ����������, ����� ���� ������, ������� ����������� � ���������� ��� ����������� �� ���� � ������������ ����. " + NewStr() +
                                      "� ������ ��������� ����� ����� ��� ��������������� ��� ����� ��������� � ������ � ��������. �� ����� ���� ������� �������, �� ������ ������ ��������� � �� ����� ������� ����� (�� � ������ �� ������� � ������������� ��������� �������?), " + 
									  "���������� �� ������� �� �������, �� ������������. �������� ����� ������������ ����������� � ������� ��������� ����������� ������������ �������, �������� ����� ���� �������������� �����. " + NewStr() +
									  "�������� �������������� � ��������� ��� ���� ��������� �� �������: ";
									  
		break;
		case 2: // �����  �� �������
			return;			
/*			
			ch.FaceId 				= 203;
			ch.HeroModel 			= "Diego_1,Diego_1,Diego_1,Diego_1,Diego_1,protocusto,Diego_6";
			ch.name 				= "�����";
			ch.lastname				= "�� �������";
			ch.nameGen				= "�����";
			ch.lastnameGen			= "�� �������";
			ch.nameDat				= "�����";
			ch.lastnameDat			= "�� �������";
			ch.sex					= "man";
			ch.model.animation 		= "man_A";
			ch.HeroParam.HeroType 	= "HeroType_1";
			ch.nation				= SPAIN;
			ch.BaseNation			= SPAIN;
			ch.info					= "����� ����� �������� �������� ����� ����� �� �������.";									
*/			
		break;		
		case 3: // ���������
			return;
/*			
			ch.FaceId 				= 202;
			ch.HeroModel 			= "Willy_1,Willy_1,Willy_1,Willy_1,Willy_1,protocusto,Willy_6";
			ch.name 				= "������";
			ch.lastname				= "��������";
			ch.nameGen				= "�������";
			ch.lastnameGen			= "���������";
			ch.nameDat				= "�������";
			ch.lastnameDat			= "���������";
			ch.sex					= "man";
			ch.model.animation 		= "man_A";
			ch.HeroParam.HeroType 	= "HeroType_3";
			ch.nation				= ENGLAND;
			ch.BaseNation			= ENGLAND;
			ch.info 				= "����������� ��������� ����� �������� ��������� � ������� �������� �� ����� ����� � ������������ �������� ��������� � ������ �������� ����������������." + 
			                          " �������� ������������ ��������� �������� � ������������ ���� ���� � �������������� ������� � �������, ����� � ��������� ������� ������� �����...";
*/									  
		break;
	}	
	
	ch.model = GetSubStringByNum(ch.HeroModel, 0);
	ch.cirassIDX = 0;
	
	if(ch.sex == "woman")
	{
		ch.model.height = 1.75;
	}
    else
    {
		ch.model.height = 1.8;
	}
}

int CCS_GetNewMainCharacterFace(ref ch)
{
    return sti(ch.FaceId);
}

// boal 091004 ����� ������  -->
// boal 23.01.2004 ����� ���������-->
void setNewMainCharacter(ref ch, int num)
{
	string heroModel, heroFaceId;
	int    idLngFile = -1;
    string totalInfo;

    idLngFile = LanguageOpenFile("HeroDescribe.txt");

    totalInfo = LanguageConvertString(idLngFile, "heroFace_" + num);
    heroFaceId  = sti(totalInfo);
    ch.FaceId   = heroFaceId;

    totalInfo = LanguageConvertString(idLngFile, "heroModel_" + num);
    ch.HeroModel = totalInfo;
    ch.model	= GetSubStringByNum(ch.HeroModel, 0);
    ch.headModel = "h_" + ch.model;

    totalInfo = LanguageConvertString(idLngFile, "heroName_" + num);
    ch.name 	=  totalInfo;

    totalInfo = LanguageConvertString(idLngFile, "heroLastname_" + num);
    ch.lastname = totalInfo;

    totalInfo = LanguageConvertString(idLngFile, "sex_" + num);
    ch.sex = totalInfo;

    totalInfo = LanguageConvertString(idLngFile, "animation_" + num);
    ch.model.animation = totalInfo;

    if(ch.sex == "woman")
	{
		ch.model.height = 1.75;
	}
    else
    {
		ch.model.height = 1.8;
	}

    LanguageCloseFile(idLngFile);
    // ��� ���
    ch.HeroParam.HeroType = GetNewMainCharacterType(num);
    ch.nation             = GetNewMainCharacterNation(num);
}

string GetNewMainCharacterType(int _startHeroType)
{
	string ret;
    switch (_startHeroType) 
	{
        case 1:
    	    ret = "HeroType_1";
	    break;
        case 2:
    	    ret = "HeroType_2";
	    break;
        case 3:
    	    ret = "HeroType_3";
	    break;
        case 4:
    	    ret = "HeroType_4";
	    break;	    
	}
	return ret;
}


void initNewMainCharacter()//������������� �������� �����
{
	ref ch = GetMainCharacter();
	string sTemp;
	int    iTmp, i;

    CCS_SetNewMainCharacter(ch, startHeroType);
    // �������� ������ -->
    ch.VersionNumber              = GetVerNum();
    ch.VersionNumberCompatibility = VERSION_NUM;
    // �������� ������ <--
    	
    MOD_EXP_RATE =  makeint(MOD_EXP_RATE + MOD_SKILL_ENEMY_RATE * MOD_EXP_RATE / 1.666666666); // ������ ������ ��� ����
    if (MOD_EXP_RATE < 10) MOD_EXP_RATE = 10; // ����� ����� ������ ����������� ������, ����� ��������� ������ ��� ���� ����������.
    
	// ���� ������	
	ch.HeroParam.ToCityId     = FindAlliedColonyForNation(sti(ch.nation), true);

	// ������ ������
    ch.HeroParam.FromCityId  = Colonies[FindNonEnemyColonyForAdventure(sti(ch.nation), ch.HeroParam.ToCityId, true)].id;

	// ��� ��������	
	ch.HeroParam.Location = ch.HeroParam.ToCityId + "_town";
	ch.HeroParam.Group    = "reload";
	ch.HeroParam.Locator  = "reload1";
	
	setCharacterShipLocation(ch, ch.HeroParam.Location);
    setWDMPointXZ(ch.HeroParam.Location);  // ����� �� �����
    
	// � ���� �� ��� ��� ?
	SetTimerCondition("Move_Govenour", 0, 0, 25 + rand(10), true); // to_do ��������� � ���� ����� ���������
	
	//��������� �������� �� ������� �������� ��� � 5 ����
    SetTimerCondition("CheckMaxHealthQuest", 0, 0, 5, true);
    
    SetTimerCondition("Nation_Legend", 0, 0, 25 + rand(10), true);

	// Jason: ����� ������ �������-������������. �� ��������� - ������, �������, ����, �� �������
	SetGovenoursToResidence();

	ReloadProgressUpdate();

 	SetNationRelations();
 	// �� ���� �������
	ch.HeroParam.EnemyNation  = FindEnemyNation2Nation(sti(ch.nation));
	
    // boal ������ ���������� �� ��������� ������� (��� ���� � �����) -->
    SetTimerCondition("SeaHunterCheck", 0, 0, 6, true);
    SaveCurrentQuestDateParam("Land_HunterTimerEng");
    SaveCurrentQuestDateParam("Land_HunterTimerFra");
    SaveCurrentQuestDateParam("Land_HunterTimerSpa");
    SaveCurrentQuestDateParam("Land_HunterTimerHol");
    // boal ������ ���������� �� ��������� ������� (��� ���� � �����) <--
    LAi_SetHP(ch, LAI_DEFAULT_HP, LAI_DEFAULT_HP);

    ch.HeroParam.HeroType = NullCharacter.HeroParam.HeroType;

	SetSPECIAL(ch, 4,4,4,4,4,4,4);
	switch (ch.HeroParam.HeroType)
	{        
		case "HeroType_1":
			SetSPECIAL(ch, 5, 6, 6, 5, 7, 7, 6);
			SetSelfSkill(ch, 15, 5, 3, 5, 10);
			SetShipSkill(ch, 12, 5, 6, 3, 3, 3, 3, 3, 15);
			SetCharacterPerk(ch, "HPPlus");
			SetCharacterPerk(ch, "HT1");
		break;
		
		case "HeroType_2":
			SetSPECIAL(ch, 7, 4, 7, 6, 6, 7, 5);
			SetSelfSkill(ch, 4, 15, 4, 5, 8);
			SetShipSkill(ch, 15, 15, 3, 3, 3, 3, 3, 3, 8);
			SetCharacterPerk(ch, "Trustworthy");
			SetCharacterPerk(ch, "HT2");
		break;
		
		case "HeroType_3":
			SetSPECIAL(ch, 10, 3, 8, 5, 4, 8, 4);
			SetSelfSkill(ch, 3, 5, 15, 5, 7);
			SetShipSkill(ch, 5, 3, 3, 8, 3, 10, 8, 3, 3);
			SetCharacterPerk(ch, "Medic");
			SetCharacterPerk(ch, "HT3");
		break;
		
		case "HeroType_4":
			SetSPECIAL(ch, 4, 9, 6, 4, 5, 5, 9);
			SetSelfSkill(ch, 5, 5, 5, 15, 20);
			SetShipSkill(ch, 10, 3, 15, 12, 3, 3, 3, 3, 12);
			SetCharacterPerk(ch, "Gunman");
			SetCharacterPerk(ch, "HT4");
		break;
	}
	
	ch.skill.freeskill   = 0;
	ch.Skill.FreeSPECIAL = 0;
	sGlobalTemp   = "Flag" + NationShortName(sti(ch.nation));
	SetCharacterPerk(ch, sGlobalTemp); // ���� ����� �����
	SetCharacterPerk(ch, "FlagPir");
	SetCharacterPerk(ch, "Energaiser"); // ������� ���� ���� 1.5 � �������� �������, ������ �� � ������ �������
	SetCharacterPerk(ch, "Rush");
	// ��������� ����� ������
    //InitStartParam(ch); // Jason - fix
	LAi_SetHP(ch, GetCharacterBaseHPValue(ch), GetCharacterBaseHPValue(ch));
    SetEnergyToCharacter(ch);
    initMainCharacterItem();
	
	ReloadProgressUpdate();	
    DeleteAttribute(ch, "Ship");
    
	if (startHeroType == 1)	// �����
	{
		ch.Ship.Type = SHIP_NOTUSED;
		Ch.GenQuest.VideoAVI = "intro_Sharle";
		Ch.GenQuest.VideoAfterQuest = "Sharlie_Start";
		DoQuestCheckDelay("PostVideo_Start", 0.2);
	}
	else
	{
		ch.Ship.Type = GenerateShipExt((SHIP_CAREERLUGGER + rand(2)), 0, ch);
		SetBaseShipData(ch);
		ch.Ship.Name = "������� �����";
		SetCrewQuantity(ch, GetMinCrewQuantity(ch));
		// ������ �������
		// ch.ship.SP = sti(ch.ship.SP) - 10; <-- ���� ��� �� ����� ������
		ch.ship.HP = sti(ch.ship.HP) - makeint(sti(ch.ship.HP)/2);
		//Tutorial - ������ ����
	    ch.quest.Tut_start.win_condition.l1          = "location";
	    ch.quest.Tut_start.win_condition.l1.location = "Ship_deck_Low";
	    ch.quest.Tut_start.function                  = "Tut_StartGame";
	}	
	// Warship ��� ������ �������
	// �����: ������� MaryCelesteInit() ������ ���� ���, � �� � initStartState2Character()
	// �.�. � ��� ���� ������� �������, ������� � ������� initStartState2Character() ��� �� ���������
	OtherQuestCharactersInit(); // ������������� ������ �������
	MaryCelesteInit(); // Warship 07.07.09 �������� "���� ������"
	// ��������� ��������� ������� ������
	ch.DayRandom = Random();
}

void initMainCharacterItem()
{
    ref ch = GetMainCharacter();
	String itemID;
	
	switch (ch.HeroParam.HeroType)
	{
		case "HeroType_1":
			itemID = GetGeneratedItem("blade_09");	// ����������
            GiveItem2Character(ch, itemID);
            EquipCharacterbyItem(ch, itemID);
			TakenItems(ch, "jewelry3", 1);
			TakenItems(ch, "jewelry42", 1);
			TakenItems(ch, "jewelry43", 2);
			TakenItems(ch, "jewelry46", 3);
         	ch.money = 500;		
		break;
		
		case "HeroType_2":
			itemID = GetGeneratedItem("blade_12");	// ���������
            GiveItem2Character(ch, itemID);
            EquipCharacterbyItem(ch, itemID);
			TakenItems(ch, "jewelry3", 1);
			TakenItems(ch, "jewelry42", 1);
			TakenItems(ch, "jewelry43", 2);
			TakenItems(ch, "jewelry46", 3);
         	ch.money = 500;				
		break;
		
		case "HeroType_3":
			itemID = GetGeneratedItem("blade_14");	// ���������� �����
            GiveItem2Character(ch, itemID);
            EquipCharacterbyItem(ch, itemID);
			TakenItems(ch, "jewelry3", 1);
			TakenItems(ch, "jewelry42", 1);
			TakenItems(ch, "jewelry43", 2);
			TakenItems(ch, "jewelry46", 3);
         	ch.money = 500;				
		break;
		
		case "HeroType_4":
			itemID = GetGeneratedItem("blade_08");	// ������
            GiveItem2Character(ch, itemID);
            EquipCharacterbyItem(ch, itemID);			
			AddItems(ch, "pistol3", 1);
			EquipCharacterbyItem(ch, "pistol3");			
			AddItems(ch, "grapeshot", 5);
			AddItems(ch, "gunpowder", 5);
			LAi_SetCharacterUseBullet(ch, "grapeshot");
			TakenItems(ch, "jewelry3", 1);
			TakenItems(ch, "jewelry42", 1);
			TakenItems(ch, "jewelry43", 2);
			TakenItems(ch, "jewelry46", 3);
         	ch.money = 500;				
		break;
	}
}

int GetNewMainCharacterFace()
{
    return sti(GetNewMainCharacterParam("heroFace_" + startHeroType));
}

string GetNewMainCharacterName()
{
    return GetHeroName(startHeroType);
}

string GetMainCharacterNameGen()  // ==> eddy. ����������� ����� ������� ����� ��
{
    return GetHeroNameGen(startHeroType);
}

string GetMainCharacterNameDat()  // ==> eddy. ��������� ����� ������� ����� ��
{
    return GetHeroNameDat(startHeroType);
}

string GetHeroName(int _n)
{
    string totalInfo;

    totalInfo = GetNewMainCharacterParam("heroName_" + _n);
    totalInfo = totalInfo + " " + GetNewMainCharacterParam("heroLastname_" + _n);

    return totalInfo;
}

string GetHeroNameGen(int _n)
{
    string totalInfo;

    totalInfo = GetNewMainCharacterParam("heroNameGen_" + _n);
    totalInfo = totalInfo + " " + GetNewMainCharacterParam("heroLastnameGen_" + _n);

    return totalInfo;
}

string GetHeroNameDat(int _n)
{
    string totalInfo;

    totalInfo = GetNewMainCharacterParam("heroNameDat_" + _n);
    totalInfo = totalInfo + " " + GetNewMainCharacterParam("heroLastnameDat_" + _n);

    return totalInfo;
}

int GetNewMainCharacterNation(int _startHeroType)
{
    int    idLngFile = -1;
    string totalInfo;

    idLngFile = LanguageOpenFile("HeroDescribe.txt");
    totalInfo = LanguageConvertString(idLngFile, "heroNation_" + _startHeroType);
    LanguageCloseFile(idLngFile);

    switch(totalInfo)
	{
		case "������":
            return ENGLAND;
		break;
		case "�������":
            return FRANCE;
		break;
		case "�������":
            return SPAIN;
		break;
		case "���������":
			return HOLLAND;
		break;
		case "��������� ��������":
			return PIRATE;
		break;

		case "ENGLAND":
            return ENGLAND;
		break;
		case "FRANCE":
            return FRANCE;
		break;
		case "SPAIN":
            return SPAIN;
		break;
		case "HOLLAND":
			return HOLLAND;
		break;
		case "PIRATE":
			return PIRATE;
		break;
	}
	return PIRATE;
}

string GetNewMainCharacterParam(string _param)
{
    int    idLngFile = -1;
    string totalInfo;

    idLngFile = LanguageOpenFile("HeroDescribe.txt");
    totalInfo = LanguageConvertString(idLngFile, _param);
    LanguageCloseFile(idLngFile);

    return totalInfo;
}

// ������� ������� ����� �� ��� ������
int GetBaseHeroNation()
{
	if (isMainCharacterPatented())
	{
	    return sti(Items[sti(pchar.EquipedPatentId)].Nation);
	}
	return sti(pchar.BaseNation);
}