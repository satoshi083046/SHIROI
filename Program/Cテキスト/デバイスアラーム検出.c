'�f�o�C�X�A���[�����o

tmr(systemwait,#30)

if systemwait.B then
'===================================================================================================================
'�y ����~ �z



'===================================================================================================================
'�y  �f�o�C�X�̃A���[�����o  �z
'-----------------------------------------------------------


'�@ KL-N20V  KL�����N�����[�R���g���[��


'�A KL-L21V Modbus�ʐM(���g���C�ʐM���F �ڑ��Ɉُ킪�Ȃ���Ύ������A���܂� �j

	select case ModbusC1AlmID

	case 0	'����
		���x���ߊ�1�ʐMAlm=OFF
		���x���ߊ�2�ʐMAlm=OFF
		���x���ߊ�3�ʐMAlm=OFF
		���x���ߊ�4�ʐMAlm=OFF
		���x���ߊ�5�ʐMAlm=OFF
		���x���ߊ�6�ʐMAlm=OFF
		�C���o�[�^1�ʐMAlm=OFF
		�C���o�[�^2�ʐMAlm=OFF
		�C���o�[�^3�ʐMAlm=OFF
		�C���o�[�^4�ʐMAlm=OFF

	'----------------------------------
	case 1
		���x���ߊ�1�ʐMAlm=ON
	case 2
		���x���ߊ�2�ʐMAlm=ON
	case 3
		���x���ߊ�3�ʐMAlm=ON
	case 4
		���x���ߊ�4�ʐMAlm=ON
	case 5
		���x���ߊ�5�ʐMAlm=ON
	case 6
		���x���ߊ�6�ʐMAlm=ON
	'----------------------------------
	case 10
		�C���o�[�^1�ʐMAlm=ON
	case 11
		�C���o�[�^2�ʐMAlm=ON
	case 12
		�C���o�[�^3�ʐMAlm=ON
	case 13
		�C���o�[�^4�ʐMAlm=ON
	'----------------------------------

	end select

'�B KL-L21V Modbus�ʐM(���g���C�ʐM���F �ڑ��Ɉُ킪�Ȃ���Ύ������A���܂��j

	select case ModbusC2AlmID
	case 0	'����
		ADR4410ch1�ʐMAlm=OFF
		ADR4410ch2�ʐMAlm=OFF
		AD4532ch1�ʐMAlm=OFF

	'----------------------------------
	case 1	
		ADR4410ch1�ʐMAlm=ON
	case 2	
		ADR4410ch2�ʐMAlm=ON
	'----------------------------------
	case 10	
		AD4532ch1�ʐMAlm=ON
	'----------------------------------

	end select

'-----------------------------------------------------------
'����{�b�N�X�̓d���m�F

'-- �[�Č�
if 0 then '---- �[�Čɂ��O������� ----
	if not(RLY_�d���m�F�[�Č�) then
		almRLY_�d���m�F�[�Č�=ON
		��������ErrStep=1
	end if
else
	RLY_�d���m�F�[�Č�=ON
end if

'-----------------------------------------------------------
'����{�b�N�X�̓d���m�F
'-- �Z��A,B,����
if LDP(not(RLY_�Z�Гd���m�F)) then
	almRLY_�Z�Гd���m�F=ON
	��������ErrStep=1
end if	

'-- �����R���x�AB
if LDP(not(RLY_�����R���x�AB�d���m�F)) then
	almRLY_�����R���x�AB�d���m�F=ON
	��������ErrStep=1
end if
'-- �ނ炵�@
if LDP(not(RLY_�ނ炵�d���m�F)) then
	almRLY_�ނ炵�d���m�F=ON
	��������ErrStep=1
end if
'-- ���@
if LDP(not(RLY12_�d���m�F�����[)) and not(�������֎~) then
	almRLY12_�d���m�F�����[=ON
	��������ErrStep=1
end if
'-- ���]��A
if LDP(not(�d���m�F�����[_A)) and not(���]�ق����@A�֎~) then
	alm�d���m�F�����[_A=ON
	��������ErrStep=1
end if
'-- ���]��B
if LDP(not(�d���m�F�����[_B)) and not(���]�ق����@B�֎~) then
	alm�d���m�F�����[_B=ON
	��������ErrStep=1
end if
'-- ���ы@
if LDP(not(INV4_�R���x�A�d���m�F)) then
	almINV4_�R���x�A�d���m�F=ON
	��������ErrStep=1
end if

'-----------------------------------------------------------
'�f�W�^�����͌v�̃A���[�����o


'-----------------------------------------------------------
'�󈳃X�C�b�`
if not(PS1_�G�A�[����) or not(PS2_�G�A�[����) or not(PS3_�G�A�[����) then
	if not(PS1_�G�A�[����) then
		almPS1_�G�A�[����=ON
		��������ErrStep=1
	end if
	if not(PS2_�G�A�[����) then
		almPS2_�G�A�[����=ON
		��������ErrStep=1
	end if
	if not(PS3_�G�A�[����) then
		almPS3_�G�A�[����=ON
		��������ErrStep=1
	end if
end if

'-----------------------------------------------------------
'���[�^�ߕ��� THR�A�V���b�N�����[�AINV�A���[��

if LDP(THR4_���ă|���v and RLY_�d���m�F�[�Č�) then
	almTHR4_���ă|���v=ON
	mMC4_���ă|���v=OFF
	ejectMC4_���ă|���v=OFF
	��������ErrStep=1
end if
if LDP(THR5_���ĉH�� and RLY_�d���m�F�[�Č�) then
	almTHR5_���ĉH��=ON
	mMC5_���ĉH��=OFF
	ejectMC5_���ĉH��=OFF
	��������ErrStep=1
end if
if LDP(THR1_�����p���~�@���[�^ and RLY_�d���m�F�[�Č�) then
	almTHR1_�����p���~�@���[�^=ON
	mMC1_�����p���~�@=OFF
	ejectMC1_�����p���~�@=OFF
	��������ErrStep=1
end if
if LDP(THR2_�r�o�p���~�@���[�^ and RLY_�d���m�F�[�Č�) then
	almTHR2_�r�o�p���~�@���[�^=ON
	mMC2_�r�o�p���~�@=OFF
	ejectMC2_�r�o�p���~�@=OFF
	��������ErrStep=1
end if
if LDP(THR3_�v�ʋ@���[�^ and RLY_�d���m�F�[�Č�) then
	almTHR3_�v�ʋ@���[�^=ON
	mMC3_�v�ʋ@=OFF
	ejectMC3_�v�ʋ@=OFF
	��������ErrStep=1
end if

'�����R���x�AA
if LDP(THR6_�������[�^ and RLY_�Z�Гd���m�F) then
	almTHR6_�������[�^=ON
	mMC6_�������[�^=OFF
	ejectMC6_�������[�^=OFF
	��������ErrStep=1
end if
if LDP(THR7_�������[�^ and RLY_�Z�Гd���m�F) then
	almTHR7_�������[�^=ON
	mMC7_�������[�^=OFF
	ejectMC7_�������[�^=OFF
	��������ErrStep=1
end if
if LDP(THR8_�������[�^ and RLY_�Z�Гd���m�F) then
	almTHR8_�������[�^=ON
	mMC8_�������[�^=OFF
	ejectMC8_�������[�^=OFF
	��������ErrStep=1
end if

'�����R���x�AB
if LDP(THR12_�������[�^ and RLY_�����R���x�AB�d���m�F) then
	almTHR12_�������[�^=ON
	mMC12_�������[�^=OFF
	ejectMC12_�������[�^=OFF
	��������ErrStep=1
end if
if LDP(THR13_�������[�^ and RLY_�����R���x�AB�d���m�F) then
	almTHR13_�������[�^=ON
	mMC13_�������[�^=OFF
	ejectMC13_�������[�^=OFF
	��������ErrStep=1
end if

'�����R���x�AC
if LDP(THR14_�������[�^ and RLY_�����R���x�AB�d���m�F) then
	almTHR14_�������[�^=ON
	mMC14_�������[�^=OFF
	ejectMC14_�������[�^=OFF
	��������ErrStep=1
end if
if LDP(THR15_�������[�^ and RLY_�����R���x�AB�d���m�F) then
	almTHR15_�������[�^=ON
	mMC15_�������[�^=OFF
	ejectMC15_�������[�^=OFF
	��������ErrStep=1
end if

'���ѓ���
if LDP(THR34_������R���x�A and RLY_�����R���x�AB�d���m�F) then
	almTHR34_������R���x�A=ON

	mMC34_�����萳�]=OFF
	ejectMC34_�����萳�]=OFF
	mMC34_������t�]=OFF
	ejectMC34_������t�]=OFF

	��������ErrStep=1
end if

'��芷��
if LDP(THR43_��ڃR���x�A and RLY_�����R���x�AB�d���m�F) then
	almTHR43_��ڃR���x�A=ON
	mMC43_��ڃR���x�A=OFF
	ejectMC43_��ڃR���x�A=OFF
	��������ErrStep=1
end if

'���яo��
if LDP(THR18_������R���x�A and RLY_�ނ炵�d���m�F) then
	almTHR18_������R���x�A=ON

	mMC18_�����萳�]=OFF
	ejectMC18_�����萳�]=OFF
	mMC18_������t�]=OFF
	ejectMC18_������t�]=OFF

	��������ErrStep=1
end if

'�ނ炵�@
if LDP(THR17_�ނ炵�@���[�^ and RLY_�ނ炵�d���m�F) then
	almTHR17_�ނ炵�@���[�^=ON
	'mMC17_�ނ炵�@���[�^=OFF
	��������ErrStep=1
end if
if CSR1_�V���b�N�����[ then
	almCSR1_�V���b�N�����[=ON
	'mMC17_�ނ炵�@���[�^=OFF
	��������ErrStep=1
end if


'�����R���x�AD
if LDP(THR19_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR19_�������[�^=ON
	mMC19_�������[�^=OFF
	ejectMC19_�������[�^=OFF
	��������ErrStep=1
end if
if LDP(THR20_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR20_�������[�^=ON
	mMC20_�������[�^=OFF
	ejectMC20_�������[�^=OFF
	��������ErrStep=1
end if
if LDP(THR21_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR21_�������[�^=ON
	mMC21_�������[�^���]=OFF
	ejectMC21_�������[�^���]=OFF
	mMC21_�������[�^�t�]=OFF
	ejectMC21_�������[�^�t�]=OFF
	��������ErrStep=1
end if
if LDP(THR22_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR22_�������[�^=ON
	mMC22_�������[�^���]=OFF
	ejectMC22_�������[�^���]=OFF
	mMC22_�������[�^�t�]=OFF
	ejectMC22_�������[�^�t�]=OFF
	��������ErrStep=1
end if

'�o�L���[���|���v
if LDP(THR24_�z���|���v and RLY_�ނ炵�d���m�F) then
	almTHR24_�z���|���v=ON
	mMC24_�z���|���v=OFF
	ejectMC24_�z���|���v=OFF
	��������ErrStep=1
end if

'�����R���x�AE
if LDP(THR25_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR25_�������[�^=ON
	mMC25_�������[�^=OFF
	ejectMC25_�������[�^=OFF
	��������ErrStep=1
end if
if LDP(THR26_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR26_�������[�^=ON
	mMC26_�������[�^=OFF
	��������ErrStep=1
end if


'�����R���x�AF
if LDP(THR28_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR28_�������[�^=ON
	mMC28_�������[�^���]=OFF
	ejectMC28_�������[�^���]=OFF
	mMC28_�������[�^�t�]=OFF
	ejectMC28_�������[�^�t�]=OFF
	��������ErrStep=1
end if
if LDP(THR29_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR29_�������[�^=ON
	mMC29_�������[�^���]=OFF
	ejectMC29_�������[�^���]=OFF
	mMC29_�������[�^�t�]=OFF
	ejectMC29_�������[�^�t�]=OFF
	��������ErrStep=1
end if


'���t�^���~A
if LDP(THR30_�������[�^ and RLY_�ނ炵�d���m�F) then
	almTHR30_�������[�^=ON
	mMC30_�������[�^=OFF
	ejectMC30_�������[�^=OFF
	��������ErrStep=1
end if

'���]������
if LDP(THR31_���]���[�^ and RLY_�ނ炵�d���m�F) then
	almTHR31_���]���[�^=ON
	mMC31_���]���[�^���]=OFF
	ejectMC31_���]���[�^���]=OFF
	mMC31_���]���[�^�t�]=OFF
	ejectMC31_���]���[�^�t�]=OFF
	��������ErrStep=1
end if

'���]��o��
if LDP(THR10_���]���[�^ and RLY_�Z�Гd���m�F) then
	almTHR10_���]���[�^=ON
	
	mMC10_���]���[�^���]=OFF
	ejectMC10_���]���[�^���]=OFF
	mMC10_���]���[�^�t�]=OFF
	ejectMC10_���]���[�^�t�]=OFF
	
	��������ErrStep=1
end if

'���t�^���~B

'-----------------------------------------------------------
'�C���o�[�^�A���[��

if not(�������֎~) then


if MC1_�C���o�[�^�p�d�� or not(RLY12_�d���m�F�����[) then
	if anda(getM14c1,statALM)=statALM or  �C���o�[�^1Alm then
		almINV1_�R���x�A�ُ�=ON
		mINV1_�R���x�A���[�^���]=OFF
		ejectINV1_�R���x�A���[�^���]=OFF
		��������ErrStep=1
	end if
	if  anda(getM14c2,statALM)=statALM or �C���o�[�^2Alm then
		almINV2_�R���x�A�ُ�=ON
		mINV2_�R���x�A���[�^���]=OFF
		ejectINV2_�R���x�A���[�^���]=OFF
		��������ErrStep=1
	end if
	if  anda(getM14c3,statALM)=statALM or �C���o�[�^3Alm then
		almINV3_�R���x�A�ُ�=ON
		mINV3_�R���x�A���[�^���]=OFF
		ejectINV3_�R���x�A���[�^���]=OFF
		��������ErrStep=1
	end if
end if

end if

if INV4_�R���x�A�d���m�F then
	if  anda(getM14c4,statALM)=statALM or �C���o�[�^4Alm or INV4_�R���x�A�ُ� then
		almINV4_�R���x�A�ُ�=ON
		��������ErrStep=1
	end if
end if

'-----------------------------------------------------------
'���|���v�A���[��

'�@�B���~�����܂���B
'���֎~��Ԃ̂Ƃ��͌��o���܂���B
'���Z�b�g�A���邢�͐��֎~�ŉ������܂��B

if PB34_���Z�b�g or PB24_���Z�b�g or PB6_���Z�b�g then
	almTHR35_���|���vA=OFF
	almTHR36_���|���vB=OFF
	almTHR37_���|���vC=OFF
	almTHR38_���|���vD=OFF
	almTHR39_���|���vE=OFF

else

	if LDP(THR35_���|���vA) and not(��򃆃j�b�g1�֎~) then
		mMC35_���|���vA=OFF
		almTHR35_���|���vA=ON
	else 
		almTHR35_���|���vA=OFF
	end if

	if LDP(THR36_���|���vB) and not(��򃆃j�b�g2�֎~) then
		mMC36_���|���vB=OFF
		almTHR36_���|���vB=ON
	else
		almTHR36_���|���vB=OFF
	end if

	if LDP(THR37_���|���vC) and not(��򃆃j�b�g3�֎~) then
		mMC37_���|���vC=OFF
		almTHR37_���|���vC=ON
	else
		almTHR37_���|���vC=OFF
	end if

	if LDP(THR38_���|���vD) and not(��򃆃j�b�g4�֎~) then
		mMC38_���|���vD=OFF
		almTHR38_���|���vD=ON
	else
		almTHR38_���|���vD=OFF
	end if

	if LDP(THR39_���|���vE) and not(��򃆃j�b�g5�֎~) then
		mMC39_���|���vE=OFF
		almTHR39_���|���vE=ON
	else
		almTHR39_���|���vE=OFF
	end if

end if

'===================================================================================================================
if 0 then
	if almPH51_�t�^���m=ON then

	else if almPH2_�t�^���m=ON then
		��������ErrStep=1

	else if almPH4_�t�^���m=ON then
		��������ErrStep=1

	else if almPH53_�t�^���m=ON then
		��������ErrStep=1

	else if almPH6_�t�^���m=ON then
		��������ErrStep=1

	else if almPH12_�t�^���m=ON then
		��������ErrStep=1

	else if almPH14_�t�^���m=ON then
		��������ErrStep=1

	else if almPH16_�t�^���m=ON then
		��������ErrStep=1

	else if almPH18_�t�^���m=ON then
		��������ErrStep=1

	else if almPH20_�t�^���m=ON then
		��������ErrStep=1

	else if almPH24_�t�^���m=ON then
		��������ErrStep=1

	else if almPH26_�t�^���m=ON then
		��������ErrStep=1

	else if almPH28_�t�^���m=ON then
		��������ErrStep=1

	else if almPH30_�t�^���m=ON then
		��������ErrStep=1

	else if almPH33_�t�^���m=ON then
		��������ErrStep=1

	else if almPH35_�t�^���m=ON then
		��������ErrStep=1

	else if almPH37_�t�^���m=ON then
		��������ErrStep=1

	else if almPH49_�t�^���m=ON then
		��������ErrStep=1

	else if almPH42_�t�^���m=ON then
		��������ErrStep=1

	else if almPH44_�t�^���m=ON then
		��������ErrStep=1

	else if almPH46_�t�^���m=ON then
		��������ErrStep=1

	else if almPH8_�t�^���m=ON then
		��������ErrStep=1

	else if almPH10_�t�^���m=ON then
		��������ErrStep=1

	else if almPH40_�t�^���m=ON then
		��������ErrStep=1

	end if
	
end if
'===================================================================================================================

'-----------------------------------------------------------
'���x���ߊ�A���[��
'
'��	EDC_ST1LBT0	1���[�h�����Ȃ�����	#1	$1:�q�[�^�d���l�I�[�o�[�iCT1�j
'��	EDC_ST1LBT1	1���[�h�����Ȃ�����	#2	$2:�q�[�^�d���l�z�[���h(CT1)
'��	EDC_ST1LBT2	1���[�h�����Ȃ�����	#4	$4:AD�R���o�[�^�ُ�
'��	EDC_ST1LBT3	1���[�h�����Ȃ�����	#8	$8:HS�iSSR�̏�j�x��(CT1)
'��	EDC_ST1LBT4	1���[�h�����Ȃ�����	#16	$10:RSP���ُ͈�
'��	EDC_ST1LBT6	1���[�h�����Ȃ�����	#64	$40:���ُ͈�
'��	EDC_ST1LBT7	1���[�h�����Ȃ�����	#128	$80:�|�e���V�������[�^���ُ͈�
'	EDC_ST1LBT8	1���[�h�����Ȃ�����	#256	$100:����o��(���M�j�I�[�v���o��
'	EDC_ST1LBT9	1���[�h�����Ȃ�����	#512	$200:����o��(��p)�N���[�Y�o��
'	EDC_ST1LBT10	1���[�h�����Ȃ�����	#1024	$400:HB(�q�[�^�f���j�x��(CT1)
'	EDC_ST1LBT11	1���[�h�����Ȃ�����	#2048	$800:HB(�q�[�^�f���j�x��(CT2)
'	EDC_ST1LBT12	1���[�h�����Ȃ�����	#4096	$1000:�x��1
'	EDC_ST1LBT13	1���[�h�����Ȃ�����	#8192	$2000:�x��2
'	EDC_ST1LBT14	1���[�h�����Ȃ�����	#16384	$4000:�x��3
'	EDC_ST1LBT15	1���[�h�����Ȃ�����	#32768	$8000:�v���O�����G���h�o��
'
	EDC_Almbit=0
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT0)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT1)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT2)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT3)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT4)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT6)
	EDC_Almbit=ORA(EDC_Almbit,EDC_ST1LBT7)
	
if ANDA(getEDC1_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�1Alm=ON
else
	���x���ߊ�1Alm=OFF
end if

if ANDA(getEDC2_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�2Alm=ON
else
	���x���ߊ�2Alm=OFF
end if

if ANDA(getEDC3_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�3Alm=ON
else
	���x���ߊ�3Alm=OFF
end if

if ANDA(getEDC4_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�4Alm=ON
else
	���x���ߊ�4Alm=OFF
end if

if ANDA(getEDC5_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�5Alm=ON
else
	���x���ߊ�5Alm=OFF
end if

if ANDA(getEDC6_ST1L,EDC_Almbit)<>0 then
	���x���ߊ�6Alm=ON
else
	���x���ߊ�6Alm=OFF
end if

'-----------------------------------------------------------
'�g�����j�b�g����ђʐM�G���[���o

if CR2306 then '�o�b�e���[�G���[ �����p���`�E���d�r  �^�� : KV-B1

end if

'-----------------------------------------------------------
'�A���[�������[�iCR3300�`CR3415�j�Ƀf�o�C�X�R�����g�Ƃ��ă��b�Z�[�W��o�^
'[�t�@�C��(F)] - CSV/TXT�`���Ńf�o�C�X�R�����g��ۑ�
'[�t�@�C��(F)] - CSV/TXT�`���̃f�o�C�X�R�����g��Ǐo

if  0 then	 		'հ�ޱװ�0
	set(CR3300)
else
	res(CR3300)	
end if
if  0 then	 		'հ�ޱװ�1
	set(CR3301)
else
	res(CR3301)	
end if
if  0 then	 		'հ�ޱװ�2
	set(CR3302)
else
	res(CR3302)	
end if
if  0 then	 		'հ�ޱװ�3
	set(CR3303)
else
	res(CR3303)	
end if
if  0 then	 		'հ�ޱװ�4
	set(CR3304)
else
	res(CR3304)	
end if
if  0 then	 		'հ�ޱװ�5
	set(CR3305)
else
	res(CR3305)	
end if
if  0 then	 		'հ�ޱװ�6
	set(CR3306)
else
	res(CR3306)	
end if
if  0 then	 		'հ�ޱװ�7
	set(CR3307)
else
	res(CR3307)	
end if
if  0 then	 		'հ�ޱװ�8
	set(CR3308)
else
	res(CR3308)	
end if
if  0 then	 		'հ�ޱװ�9
	set(CR3309)
else
	res(CR3309)	
end if
if  0 then	 		'հ�ޱװ�10
	set(CR3310)
else
	res(CR3310)	
end if
if  0 then	 		'հ�ޱװ�11
	set(CR3311)
else
	res(CR3311)	
end if
if  0 then	 		'հ�ޱװ�12
	set(CR3312)
else
	res(CR3312)	
end if
if  0 then	 		'հ�ޱװ�13
	set(CR3313)
else
	res(CR3313)	
end if
if  0 then	 		'հ�ޱװ�14
	set(CR3314)
else
	res(CR3314)	
end if
if  0 then	 		'հ�ޱװ�15
	set(CR3315)
else
	res(CR3315)	
end if
if  0 then	 		'հ�ޱװ�16
	set(CR3400)
else
	res(CR3400)	
end if
if  0 then	 		'հ�ޱװ�17
	set(CR3401)
else
	res(CR3401)	
end if
if  0 then	 		'հ�ޱװ�18
	set(CR3402)
else
	res(CR3402)	
end if
if  0 then	 		'հ�ޱװ�19
	set(CR3403)
else
	res(CR3403)	
end if
if  0 then	 		'հ�ޱװ�20
	set(CR3404)
else
	res(CR3404)	
end if
if  0 then	 		'հ�ޱװ�21
	set(CR3405)
else
	res(CR3405)	
end if
if  0 then	 		'հ�ޱװ�22
	set(CR3406)
else
	res(CR3406)	
end if
if  0 then	 		'հ�ޱװ�23
	set(CR3407)
else
	res(CR3407)	
end if
if  0 then	 		'հ�ޱװ�24
	set(CR3408)
else
	res(CR3408)	
end if
if  0 then	 		'հ�ޱװ�25
	set(CR3409)
else
	res(CR3409)	
end if
if  0 then	 		'հ�ޱװ�26
	set(CR3410)
else
	res(CR3410)	
end if
if  0 then	 		'հ�ޱװ�27
	set(CR3411)
else
	res(CR3411)	
end if
if  0 then	 		'հ�ޱװ�28
	set(CR3412)
else
	res(CR3412)	
end if
if  0 then	 		'հ�ޱװ�29
	set(CR3413)
else
	res(CR3413)	
end if
if  0 then	 		'հ�ޱװ�30
	set(CR3414)
else
	res(CR3414)	
end if
if  0 then	 		'հ�ޱװ�31
	set(CR3415)
else
	res(CR3415)	
end if

if 0 and CR3500 then 

end if


end if 'if systemwait.B then
'===================================================================================================================
