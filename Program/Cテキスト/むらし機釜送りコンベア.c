'�ނ炵�@������R���x�A
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�ނ炵�@������R���x�A
'
' tmr(pauseMC17_�ނ炵���[�^,,) �� pauseMC17_�ނ炵���[�^�̎��ԊĎ�
'
'
' if �ނ炵���[�^pause then
'	[] �ނ炵���[�^ pause��ԏ���		
' else 
'-----------------------------------------------------------------
'	�ނ炵������R���x�Astep	
'		
'-----------------------------------------------------------------
'0: �������Ȃ��ҋ@		
'		
'-----------------------------------------------------------------
'1:�C���o�[�^�N���҂�
'		
'-----------------------------------------------------------------
'2:�X�^�[�g���̏�Ԍ��m	
'	�ނ炵���[�^���r���ʒu		step=300
'		
'	�ނ炵�o���Ɋ��L 			step=500
'	�ނ炵�����Ɋ��L			step=300
'	���яo���Ɋ��L				step=200
'
'	���̑� step=100 ���яo�� �i�g���K�҂��j
'
'-----------------------------------------------------------------
'�y ��A���� �z				
'-----------------------------------------------------------------
'100: 
'	�C���o�[�^�^�]���m  -> off�� step=1		
'
'	���яo�� �����m �i�g���K�҂��j	
'	[]�ނ炵����,�ނ炵�o��,pause��� ���L�G���[ <�ނ炵�����a��>
'
'-----------------------------------------------------------------
'200: ���яo�� ������				
'	[]�ނ炵�o��,pause��� ���L�G���[  <�ނ炵�o���a��>	
'201: MC18_������step=1
'
'-----------------------------------------------------------------
'300: �ނ炵����������				
'	[]�ނ炵�o��,pause��� ���L�G���[  <�ނ炵�o���a��>		
'301: MC17_�ނ炵�@���[�^step 
'
'-----------------------------------------------------------------
'400: �ނ炵�o��������				MC19_�������[�^step
'401: 
'		
'-----------------------------------------------------------------
'500:
'	step=100 �C���o�[�^�^�]���m or ���яo�� �����m(�g���K�҂�)
'
'===================================================================================================================
			
'�y ���������� �z
'if CR2008 or ldp(INV4_�R���x�A���쒆) or ldp(RLY_�ނ炵�d���m�F) then '�d��ON������������
if CR2008 or not(RLY_�ނ炵�d���m�F) then '�d��ON������������

	'INV4_�C���o�[�^�^�]���Ɠ������邽�߁AINV4_�C���o�[�^�^�]��  or AutoRun ���N�������ɂȂ�B

    �ނ炵�@������R���x�AAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �ނ炵�@������R���x�AAutoRun=ON
    �ނ炵�@������R���x�A����=ON
    �ނ炵�@������R���x�AOrgErr=OFF
    �ނ炵�@������R���x�AErr=OFF
    �ނ炵�@������R���x�AEmg=OFF
    �ނ炵�@������R���x�Astep=0
    �ނ炵�@������R���x�AErrStep=0
    �ނ炵�@������R���x�AOrgErrStep=0
    �ނ炵�@������R���x�AEmgStep=0
	
	MC17_�ނ炵�@���[�^step=0
	MC18_������step=0
	MC19_�������[�^step=0

	mINV4_�C���o�[�^���]=OFF
	mINV4_�C���o�[�^��~=OFF
	mMC17_�ނ炵�@���[�^=OFF
	mMC18_������t�]=OFF
	mMC18_�����萳�]=OFF
	mMC19_�������[�^=OFF

end if


'===================================================================================================================
'�y ���_ �z
�ނ炵�@������R���x�AOrg=SSW1_2_�^�]�؊��i�A���j and not(MC17_�ނ炵�@���[�^) and not(mMC17_�ނ炵�@���[�^) and LS3_�ނ炵�@�s�b�`���m
				
if mMC18_�����萳�] and LS1_������O�i�[ then
	mMC18_�����萳�]=OFF
end if
if mMC18_������t�] and LS2_�������ޒ[ then
	mMC18_������t�]=OFF
end if

if ldp(INV4_�R���x�A���쒆) then
	if LS31_�ނ炵�@�����Z���T and not(MC17_�ނ炵�@���[�^) and not(mMC17_�ނ炵�@���[�^) then
		MC17_�ނ炵�@���[�^�N��=ON
	else
		MC17_�ނ炵�@���[�^�N��=OFF
	end if
end if
'--------------------------------------------------------------------
'�����N���A������~���̐��ы@�C���o�[�^�N���A��~

	if ldp(��������AutoRun) then
		mINV4_�C���o�[�^���]=ON
		mINV4_�C���o�[�^��~=OFF
	else if ��������AutoMode and not(��������AutoRun) then
		mINV4_�C���o�[�^���]=OFF
		mINV4_�C���o�[�^��~=ON
	end if

	if INV4_�R���x�A���쒆 then
		mINV4_�C���o�[�^���]=OFF
	else if not(INV4_�R���x�A���쒆) then
		mINV4_�C���o�[�^��~=OFF
	end if

	if �ނ炵������R���x�A�֎~ then
		mMC18_������t�]=OFF		
		mMC18_�����萳�]=OFF
	end if

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�ނ炵�@������R���x�AEmg=ON
	�ނ炵�@������R���x�AEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(not(SV41_���t�g) and not(XSW47_���t�g���~�[) and not(pnlPBXSW47_���t�g���~�[),tim_notXSW47_���t�g���~�[,#30) '1607.98ms

if LDF(SV41_���t�g) and  XSW47_���t�g���~�[ and XSW48_���t�g�㏸�[ and not(pnlPBXSW47_���t�g���~�[) then
	SET(tim_XSW47_���t�g���~�[)
end if

tmr(MC18_�����萳�] and not(pauseMC18_�����萳�]) and not(EmgMC18_�����萳�]) and not(�ނ炵������R���x�A�֎~),tim_MC18_�����萳�],#120)
tmr(MC18_������t�] and not(pauseMC18_������t�]) and not(EmgMC18_������t�]) and not(�ނ炵������R���x�A�֎~),tim_MC18_������t�],#120)

'   �o���ɂ��銘��r�o��       �ނ炵�@���[�^��]��                        
tmr(MC17_�ނ炵�@���[�^ and not(LS3_�ނ炵�@�s�b�`���m),tim_LS3_�ނ炵�@�s�b�`���m,#215) '#215) '25.0 LS�͂���܂ł̎��� 5.48

tmr(ejectMC19_�������[�^ and not(pauseMC19_�������[�^) and not(EmgMC19_�������[�^),tim_ejectMC19_�������[�^,#100)

'LS3_�ނ炵�@�s�b�`���m - LS3_�ނ炵�@�s�b�`���m �܂ł̎����l=25Sec

'���~�b�gLS�̃`���^�����O�h�~
tmr(LS3_�ނ炵�@�s�b�`���m, timdlyLS3_�ނ炵�@�s�b�`���m,10)
tmr(not(LS3_�ނ炵�@�s�b�`���m), timnotdlyLS3_�ނ炵�@�s�b�`���m,10)

'�ނ炵����������g���K
tmr(PH56_������g���K ,tim_PH56_������g���K,#50)

if MC17_�ނ炵�@���[�^�N�� and PH21_�ނ炵�@�o���Z���T then
	alm�a�،x��=ON			
	alm�a�،x��o��=ON
	�ނ炵�@������R���x�AErrStep=1	
end if

if LS1_������O�i�[ and LS2_�������ޒ[  and not(�ނ炵������R���x�A�֎~) then
	errpassLS1_������O�i�[=ON
	errpassLS2_�������ޒ[=ON
	almLS1_������O�i�[=ON
	almMC18_�����萳�]=ON
	almLS2_�������ޒ[=ON
	almMC18_������t�]=ON
	
	�ނ炵�@������R���x�AErrStep=1

else if ldp(tim_MC18_�����萳�].B)  and not(�ނ炵������R���x�A�֎~) then
	errpassLS1_������O�i�[=ON
	almLS1_������O�i�[=ON
	almMC18_�����萳�]=ON
	�ނ炵�@������R���x�AErrStep=1

else if ldp(tim_MC18_������t�].B)  and not(�ނ炵������R���x�A�֎~) then
	errpassLS2_�������ޒ[=ON
	almLS2_�������ޒ[=ON
	almMC18_������t�]=ON
	�ނ炵�@������R���x�AErrStep=1

else if ldp(tim_LS3_�ނ炵�@�s�b�`���m.B) or (ldp(timdlyLS3_�ނ炵�@�s�b�`���m.B) and not(PH21_�ނ炵�@�o���Z���T) and 0) then
	
	if tim_LS3_�ނ炵�@�s�b�`���m.B then
		almLS3_�ނ炵�@�s�b�`���m=ON
	else if timdlyLS3_�ނ炵�@�s�b�`���m.B and not(PH21_�ނ炵�@�o���Z���T) then
		almPH21_�ނ炵�@�o���Z���T=ON
	end if
	
	
	mMC17_�ނ炵�@���[�^=OFF
	
	�ނ炵�@������R���x�Astep=0
	manuMC17_�ނ炵�@���[�^step=0
	MC17_�ނ炵�@���[�^step=0	
	MC17_�ނ炵�@���[�^�N��=OFF
	�s�b�`���m����=OFF

	�ނ炵�@������R���x�AErrStep=1

else if ldp(tim_ejectMC19_�������[�^.B) then
	almMC19_�������[�^=ON
	ejectMC19_�������[�^=OFF
	errpass�R���x�A�ꎞ��~=ON
	
	�ނ炵�@������R���x�AErrStep=1

else if (LDP(tim_notXSW47_���t�g���~�[) or LDP(tim_XSW47_���t�g���~�[)) and not(pnlPBXSW47_���t�g���~�[) then
	almXSW47_���t�g���~�[=ON
	pnlPBXSW47_���t�g���~�[=ON
	errpass�R���x�A�ꎞ��~=ON

	�ނ炵�@������R���x�AErrStep=1
end if

if MC17_�ނ炵�@���[�^�N�� and PH21_�ނ炵�@�o���Z���T then
	mMC17_�ނ炵�@���[�^=OFF
	alm�a�،x��=ON			
	alm�a�،x��o��=ON
	�ނ炵�@������R���x�AErrStep=1
end if

'===================================================================================================================
' PL�C���W�P�[�^

	if manuMC17_�ނ炵�@���[�^step<>0 then
		PBL15_�ނ炵�@�^�]��=ON
	else
		PBL15_�ނ炵�@�^�]��=OFF
	end if


	'��~�X�C�b�`
	if CSR1_�V���b�N�����[ or (not(�ނ炵�@������R���x�AAutoRun) and SSW1_1_�^�]�؊��i�P���j and not(PB16_�ނ炵�@��~)) then
		�ނ炵�@������R���x�Astep=0
		mMC17_�ނ炵�@���[�^=OFF
		manuMC17_�ނ炵�@���[�^step=0
		MC17_�ނ炵�@���[�^step=0
		MC17_�ނ炵�@���[�^�N��=OFF
		�s�b�`���m����=OFF

	end if

'===================================================================================================================
'�ނ炵�s�b�`����̑ҋ@(Pause)
'�ނ炵�@���s�b�`�����]����D�R���x�A���G�X�P�[�v���t�g��̃��[�N��������悤�Ƃ���ƁA�����R���x�A�łނ炵�@�o����
'���[�N�܂Ŕ�������Ă��܂��B
'   <�듮��>
'   �ނ炵��]����  �o�������B  ��   
'
'                                  [�ނ炵�o���̃��[�N]    [�G�X�P�[�v���t�g��̃��[�N]  �� D�R���x�A����
'	<���P>
'   �ނ炵��]����  �o�������B  �� [-�ނ炵�o���̃��[�N-]   [�G�X�P�[�v���t�g��̃��[�N]
'									�ނ炵��]�A�ꎞ��~    [�G�X�P�[�v���t�g��̃��[�N]  �� D�R���x�A����
'						          [-�ނ炵�o���̃��[�N-]  
'                                    �ނ炵��]�A�ꎞ��~����                                  
'								  [�ނ炵�o���̃��[�N]
	tmr(PH22_�����m,timdlyPH22_�����m,2)
'	if mMC17_�ނ炵�@���[�^ and tim_PH21_�ނ炵�@�o���Z���T.B	then

	if mMC17_�ނ炵�@���[�^ and PH21_�ނ炵�@�o���Z���T then
		if timdlyPH22_�����m.B or mMC19_�������[�^ then
			pauseMC17_�ނ炵�@���[�^=ON
			
			if ldp(pauseMC17_�ނ炵�@���[�^) then
				alm�a�،x��=ON			
				alm�a�،x��o��=ON
				�ނ炵�@������R���x�AErrStep=1
			end if
		
		else
			pauseMC17_�ނ炵�@���[�^=OFF	
		end if
	else
		pauseMC17_�ނ炵�@���[�^=OFF

		if alm�a�،x��o�� and mMC17_�ނ炵�@���[�^=OFF then
			�ނ炵�@������R���x�AErrStep=1
		end if

	end if
	
	
	if INV4_�R���x�A���쒆 and PH57_�����m�X�e�[�W then
		tmr(INV4_�R���x�A���쒆 and PH57_�����m�X�e�[�W,timon_PH57_�����m�X�e�[�W,150)
		if ldp(timon_PH57_�����m�X�e�[�W.B) then
			alm�a�،x��=ON			
			alm�a�،x�����=ON
			�ނ炵�@������R���x�AErrStep=1
		end if
	else
		res(timon_PH57_�����m�X�e�[�W)
	end if
	

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �ނ炵�@������R���x�AAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �ނ炵�@������R���x�AEmg	���̏��~


if MC17_�ނ炵�@���[�^step=0 and MC18_������step=0 and MC19_�������[�^step=0 then
	
	if ldp(INV4_�R���x�A���쒆) then
		if �ނ炵�@������R���x�Astep=0 then
			�ނ炵�@������R���x�Astep=1
		end if
		�s�b�`���m����=OFF
	end if
	
end if
'--------------------------------------------
'�r�o�͏I���܂Ŏ��s
'--------------------------------------------
'MC19_�������[�^ ���r�o���[�^
tmr(PH21_�ނ炵�@�o���Z���T,tim_PH21_�ނ炵�@�o���Z���T,#5) 
tmr(PH22_�����m,tim_PH22_�����m,#5) 

tmr(tim_MC19_�������[�^,tim_MC19_�������[�^_val)
select case MC19_�������[�^step
case 0
	'mconvMC19_�������[�^=OFF

case 1
	if PH21_�ނ炵�@�o���Z���T then
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC19_�������[�^step)
	else
		MC19_�������[�^step=0
	end if

case 2
	if not(mMC19_�������[�^) then
		mSV41_���t�g=OFF
		errpass�R���x�A�ꎞ��~=OFF		
		inc(MC19_�������[�^step)
	end if
	
case 3	
	if errpass�R���x�A�ꎞ��~ or ((XSW47_���t�g���~�[ and not(pnlPBXSW47_���t�g���~�[)) or passXSW47_���t�g���~�[) then
		ejectMC19_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC19_�������[�^step)
	end if						

case 4
	if errpass�R���x�A�ꎞ��~ then
		inc(MC19_�������[�^step)

	else if not(PH21_�ނ炵�@�o���Z���T) then
		res(tim_PH21_�ނ炵�@�o���Z���T)
		inc(MC19_�������[�^step)
	end if
	
case 5
	if errpass�R���x�A�ꎞ��~ then
		inc(MC19_�������[�^step)

	else if PH22_�����m then
		inc(MC19_�������[�^step)
	end if			

case 6
	tim_MC19_�������[�^_val=#21 '���t�g�Z���^�[�A�ʒu���킹����
	res(tim_MC19_�������[�^)
	inc(MC19_�������[�^step)

case 7
	if tim_MC19_�������[�^.B then
		ejectMC19_�������[�^=OFF
		inc(MC19_�������[�^step)
	end if

case 8
	'�G�X�P�[�v���A�t�^���Ɋ��A�t�^����������G�X�P�[�v���t�g
	if �G�X�P�[�v�� or PH23_�����m or PH24_�t�^���m or �t�^���t�^��蒆 then
		mSV41_���t�g=ON
	else
		mSV41_���t�g=OFF
	end if
	inc(MC19_�������[�^step)

case 9
	MC19_�������[�^step=0

end select
'--------------------------------------------
' �����萳�]�t�]
tmr(tim_MC18_������,tim_MC18_������_val)
select case MC18_������step
case 0
	'mMC18_�����萳�]=OFF
	'mMC18_������t�]=OFF

case 1
  	if not(�ނ炵������R���x�A�֎~) then
		mMC18_�����萳�]=ON
		errpassLS1_������O�i�[=OFF
		inc(MC18_������step)
	else
		MC18_������step=0
	end if
	
case 2
	if LS1_������O�i�[ or errpassLS1_������O�i�[ then
		inc(MC18_������step)
	end if			

case 3
	mMC18_�����萳�]=OFF
	tim_MC18_������_val=�ނ炵������ҋ@���� 'R=45 L=30
	res(tim_MC18_������)
	inc(MC18_������step)

case 4
	if tim_MC18_������.B then
		inc(MC18_������step)
	end if

case 5
	mMC18_������t�]=ON
	errpassLS2_�������ޒ[=OFF
	inc(MC18_������step)

case 6
	if LS2_�������ޒ[  or errpassLS2_�������ޒ[ then
		inc(MC18_������step)
	end if

case 7
	mMC18_������t�]=OFF

	if PH21_�ނ炵�@�o���Z���T then
		alm�a�،x��=ON			
		alm�a�،x��o��=ON
		�ނ炵�@������R���x�AErrStep=1
	end if

	MC17_�ނ炵�@���[�^�N��=ON
	MC18_������step=0

end select

'--------------------------------------------
' �ނ炵�s�b�`����
tmr(tim_MC17_�ނ炵�@���[�^,tim_MC17_�ނ炵�@���[�^_val)

select case MC17_�ނ炵�@���[�^step
case 0
	'mMC17_�ނ炵�@���[�^=OFF
case 1
	if MC17_�ނ炵�@���[�^�N�� then
		if PH21_�ނ炵�@�o���Z���T then
			alm�a�،x��=ON			
			alm�a�،x��o��=ON
			�ނ炵�@������R���x�AErrStep=1
			MC17_�ނ炵�@���[�^step=0	
		else
			MC17_�ނ炵�@���[�^�N��=OFF
			mMC17_�ނ炵�@���[�^=ON
			inc(MC17_�ނ炵�@���[�^step)
		end if
	else 
			mMC17_�ނ炵�@���[�^=ON
			inc(MC17_�ނ炵�@���[�^step)
	end if
	
case 2
	if not(LS3_�ނ炵�@�s�b�`���m) and timnotdlyLS3_�ނ炵�@�s�b�`���m.B then
		res(timdlyLS3_�ނ炵�@�s�b�`���m)
		inc(MC17_�ނ炵�@���[�^step)
	end if

case 3
	if LS3_�ނ炵�@�s�b�`���m  and timdlyLS3_�ނ炵�@�s�b�`���m.B then
		res(timnotdlyLS3_�ނ炵�@�s�b�`���m)
		inc(MC17_�ނ炵�@���[�^step)
	end if

case 4
	mMC17_�ނ炵�@���[�^=OFF
	MC17_�ނ炵�@���[�^step=0
	
end select


if �ނ炵�@������R���x�AEmgStep=0 then  
	
	if �ނ炵�@������R���x�AErrStep=0  then

	if not(�ނ炵�@������R���x�AOrgErr) then

		if not(�ނ炵�@������R���x�AAutoMode and ��������AutoMode ) then
			�ނ炵�@������R���x�AAutoRun=OFF
		end if

	if (INV4_�R���x�A���쒆  or �ނ炵�@������R���x�Astep<>0 or MC17_�ނ炵�@���[�^step<>0 or  MC18_������step<>0) and manuMC17_�ނ炵�@���[�^step=0 then
	
	
	

		'===================================================================================================================
		'�y �ނ炵������R���x�A �z
		'

		select case �ނ炵�@������R���x�Astep
		case 0
		
		case 1
			if INV4_�R���x�A���쒆 then
				inc(�ނ炵�@������R���x�Astep)
			else
				�ނ炵�@������R���x�Astep=0
			end if
			
		'--------------------------------------------
		'�^�]����
		case 2
			if �s�b�`���m���� then
				�ނ炵�@������R���x�Astep=100
			else
				inc(�ނ炵�@������R���x�Astep)
			end if
		
		case 3
			if not(LS3_�ނ炵�@�s�b�`���m) then
				MC17_�ނ炵�@���[�^step=1 '�ނ炵���������J���鋭���I�ɂނ炵�R���x�A��1�s�b�`����
				inc(�ނ炵�@������R���x�Astep)
			else
				�ނ炵�@������R���x�Astep=100
			end if			
			
		case 4
			if MC17_�ނ炵�@���[�^step=0 then	
				�ނ炵�@������R���x�Astep=100
			end if
		'--------------------------------------------
		'�^�]			
 		case 100
			�s�b�`���m����=ON
		'--------------------------------------------
		'�ނ炵�o����						
			if PH21_�ނ炵�@�o���Z���T then 
				if LS3_�ނ炵�@�s�b�`���m and not(PH22_�����m) and not(mMC19_�������[�^) and MC19_�������[�^step=0 then
					MC19_�������[�^step=1
				end if
			else
				if 	MC17_�ނ炵�@���[�^�N�� and LS3_�ނ炵�@�s�b�`���m and MC19_�������[�^step=0 and MC17_�ނ炵�@���[�^step=0 and MC18_������step=0 then
						MC17_�ނ炵�@���[�^step=1
				end if
			end if

		'--------------------------------------------
		'�ނ炵������
			if (tim_PH56_������g���K.B or �ނ炵������R���x�A�֎~) and MC17_�ނ炵�@���[�^step=0 and MC18_������step=0 then
			 	if not(INV4_�R���x�A���쒆) then
					�ނ炵�@������R���x�Astep=0
				else if not(MC17_�ނ炵�@���[�^�N��) then
					if not(�ނ炵������R���x�A�֎~) and not(LS31_�ނ炵�@�����Z���T) then
						MC18_������step=1
					else if �ނ炵������R���x�A�֎~ and ldp(timLS31_�ނ炵�@�����Z���T) then
						MC17_�ނ炵�@���[�^�N��=ON
					end if
				end if
			end if

			�ނ炵�@������R���x�Astep=1
		'--------------------------------------------
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if not(�ނ炵�@������R���x�AAutoRun)  or manuMC17_�ނ炵�@���[�^step<>0 then 
		
		�ނ炵�@������R���x�Astep=0 '�I��
			'--------------------------------------------
			' �蓮�ނ炵�s�b�`����
			if (ldp(PB15_�ނ炵�@�^�] and SSW1_1_�^�]�؊��i�P���j) or (ldp(pnlPBMC17_�ނ炵�@���[�^) and SSW1_2_�^�]�؊��i�A���j) ) and  manuMC17_�ނ炵�@���[�^step=0 then  
				if not(LS3_�ނ炵�@�s�b�`���m and PH21_�ނ炵�@�o���Z���T) then
				manuMC17_�ނ炵�@���[�^step=1
				end if
			end if
			
			tmr(tim_manuMC17_�ނ炵�@���[�^,tim_manuMC17_�ނ炵�@���[�^_val)
			select case manuMC17_�ނ炵�@���[�^step
			case 0
			
			case 1 
				mMC17_�ނ炵�@���[�^=ON
				inc(manuMC17_�ނ炵�@���[�^step)
			
			case 2
				if not(LS3_�ނ炵�@�s�b�`���m) and timnotdlyLS3_�ނ炵�@�s�b�`���m then
					inc(manuMC17_�ނ炵�@���[�^step)
				end if
				
			case 3
				if LS3_�ނ炵�@�s�b�`���m and timdlyLS3_�ނ炵�@�s�b�`���m then
					mMC17_�ނ炵�@���[�^=OFF
					manuMC17_�ނ炵�@���[�^step=0
				end if
			end select
			
			'--------------------------------------------
			if SSW1_2_�^�]�؊��i�A���j then
			
				if ldp(pnlPBMC18_�����萳�]) then
					if mMC18_�����萳�] then
						mMC18_�����萳�]=OFF
					else if not(mMC18_������t�]) then
						mMC18_�����萳�]=ON
						mMC18_������t�]=OFF
					end if
				else if ldp(pnlPBMC18_������t�]) then
					if mMC18_������t�] then
						mMC18_������t�]=OFF
					else if not(mMC18_�����萳�]) then
						mMC18_�����萳�]=OFF
						mMC18_������t�]=ON	
					end if
				end if
			end if
			'--------------------------------------------
		end if
			
	end if '�ނ炵�@������R���x�AAutoMode and not(�ނ炵�@������R���x�AOrgErrStep)

	'===================================================================================================================
	'�y �ނ炵�@������R���x�AOrgErr���� �z
	else
	
		if ResetFlg then
			�ނ炵�@������R���x�AOrgErr=OFF
		end if

	end if

	'==================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�ނ炵�@������R���x�AErr=ON

		pauseMC18_�����萳�]=ON
		pauseMC18_������t�]=ON
		pauseMC17_�ނ炵�@���[�^=ON
		
		mINV4_�C���o�[�^��~=ON

		select case �ނ炵�@������R���x�AErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW47_���t�g���~�[=OFF
				almMC19_�������[�^=OFF
				almLS1_������O�i�[=OFF
				almLS2_�������ޒ[=OFF
				almMC18_�����萳�]=OFF
				almMC18_������t�]=OFF
				almLS3_�ނ炵�@�s�b�`���m=OFF
				almPH21_�ނ炵�@�o���Z���T=OFF
				alm�a�،x��=OFF
				alm�a�،x��o��=OFF
				alm�a�،x�����=OFF
				inc(�ނ炵�@������R���x�AErrStep)
			end if
			if timerrstack=OFF then
				timdlyLS3_�ނ炵�@�s�b�`���m_stack.U=timdlyLS3_�ނ炵�@�s�b�`���m.U
				timerrstack=ON
			end if
			
		case 2

			res(tim_notXSW47_���t�g���~�[)
			res(tim_XSW47_���t�g���~�[)
			res(tim_MC18_�����萳�])
			res(tim_MC18_������t�])
			timdlyLS3_�ނ炵�@�s�b�`���m.U=timdlyLS3_�ނ炵�@�s�b�`���m_stack.U
			timerrstack=OFF
			
			pauseMC18_�����萳�]=OFF
			pauseMC18_������t�]=OFF
			pauseMC17_�ނ炵�@���[�^=OFF

			�ނ炵�@������R���x�AErr=OFF
			
			�ނ炵�@������R���x�AErrStep=0
		end select

	end if 'if �ނ炵�@������R���x�AErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �ނ炵�@������R���x�AEmgStep
	case 0
	
	case 1
		�ނ炵�@������R���x�AAutoRun=OFF
		
		EmgMC17_�ނ炵�@���[�^=ON
		EmgMC18_������t�]=ON
		EmgMC18_�����萳�]=ON
		EmgMC19_�������[�^=ON
		
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (INV4_�R���x�A���쒆  or �ނ炵�@������R���x�Astep<>0 or MC17_�ނ炵�@���[�^step<>0 or  MC18_������step<>0) and manuMC17_�ނ炵�@���[�^step=0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgMC17_�ނ炵�@���[�^=ON
			EmgMC18_������t�]=ON
			EmgMC18_�����萳�]=ON
			EmgMC19_�������[�^=ON
			

			if timstack=OFF then
				timdlyLS3_�ނ炵�@�s�b�`���m_stack.U=timdlyLS3_�ނ炵�@�s�b�`���m.U
				timnotdlyLS3_�ނ炵�@�s�b�`���m_stack.U=timnotdlyLS3_�ނ炵�@�s�b�`���m.U
				tim_PH56_������g���K_stack.U=tim_PH56_������g���K.U
				timdlyPH22_�����m_stack.U=timdlyPH22_�����m.U
				timon_PH57_�����m�X�e�[�W_stack.U=timon_PH57_�����m�X�e�[�W.U
				tim_PH21_�ނ炵�@�o���Z���T_stack.U=tim_PH21_�ނ炵�@�o���Z���T.U
				tim_PH22_�����m_stack.U=tim_PH22_�����m.U
				tim_MC19_�������[�^_stack.U=tim_MC19_�������[�^.U
				tim_MC18_������_stack.U=tim_MC18_������.U
				tim_MC17_�ނ炵�@���[�^_stack.U=tim_MC17_�ނ炵�@���[�^.U
				tim_manuMC17_�ނ炵�@���[�^_stack.U=tim_manuMC17_�ނ炵�@���[�^.U
			' tmr(LS3_�ނ炵�@�s�b�`���m, timdlyLS3_�ނ炵�@�s�b�`���m,2)
			' tmr(not(LS3_�ނ炵�@�s�b�`���m), timnotdlyLS3_�ނ炵�@�s�b�`���m,2)
			' tmr(PH56_������g���K,tim_PH56_������g���K,#50)
			' tmr(PH22_�����m,timdlyPH22_�����m,2)
			' tmr(INV4_�R���x�A���쒆 and PH57_�����m�X�e�[�W,timon_PH57_�����m�X�e�[�W,150)
			' tmr(PH21_�ނ炵�@�o���Z���T,tim_PH21_�ނ炵�@�o���Z���T,#5) 
			' tmr(PH22_�����m,tim_PH22_�����m,#5) 
			' tmr(tim_MC19_�������[�^,tim_MC19_�������[�^_val)
			' tmr(tim_MC18_������,tim_MC18_������_val)
			' tmr(tim_MC17_�ނ炵�@���[�^,tim_MC17_�ނ炵�@���[�^_val)
			' tmr(tim_manuMC17_�ނ炵�@���[�^,tim_manuMC17_�ނ炵�@���[�^_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC17_�ނ炵�@���[�^=OFF
			mMC18_�����萳�]=OFF
			mMC18_������t�]=OFF

			manuMC17_�ނ炵�@���[�^step=0
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�ނ炵�@������R���x�AEmgStep)
	case 2
		if ResetFlg then
			inc(�ނ炵�@������R���x�AEmgStep)
		end if
	case 3
		EmgMC17_�ނ炵�@���[�^=OFF
		EmgMC18_������t�]=OFF
		EmgMC18_�����萳�]=OFF
		EmgMC19_�������[�^=OFF

		if (INV4_�R���x�A���쒆  or �ނ炵�@������R���x�Astep<>0 or MC17_�ނ炵�@���[�^step<>0 or  MC18_������step<>0) and manuMC17_�ނ炵�@���[�^step=0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				EmgMC17_�ނ炵�@���[�^=OFF
				EmgMC18_������t�]=OFF
				EmgMC18_�����萳�]=OFF
				EmgMC19_�������[�^=OFF

				'�X�^�b�N�̒l���^�C�}�[���ݒl�Ƀ��X�g�A
				tim_PH56_������g���K.U=tim_PH56_������g���K_stack.U
				timon_PH57_�����m�X�e�[�W.U=timon_PH57_�����m�X�e�[�W_stack.U
				tim_MC19_�������[�^.U=tim_MC19_�������[�^_stack.U
				tim_MC18_������.U=tim_MC18_������_stack.U
				tim_MC17_�ނ炵�@���[�^.U=tim_MC17_�ނ炵�@���[�^_stack.U
				tim_manuMC17_�ނ炵�@���[�^.U=tim_manuMC17_�ނ炵�@���[�^_stack
				' tmr(PH56_������g���K,tim_PH56_������g���K,#50)
				' tmr(INV4_�R���x�A���쒆 and PH57_�����m�X�e�[�W,timon_PH57_�����m�X�e�[�W,150)
				' tmr(tim_MC19_�������[�^,tim_MC19_�������[�^_val)
				' tmr(tim_MC18_������,tim_MC18_������_val)
				' tmr(tim_MC17_�ނ炵�@���[�^,tim_MC17_�ނ炵�@���[�^_val)
				' tmr(tim_manuMC17_�ނ炵�@���[�^,tim_manuMC17_�ނ炵�@���[�^_val)
				
				'���o�^�C�}�[�̃��Z�b�g
				res(timdlyLS3_�ނ炵�@�s�b�`���m)
				res(timnotdlyLS3_�ނ炵�@�s�b�`���m)
				res(timdlyPH22_�����m)
				res(tim_PH21_�ނ炵�@�o���Z���T)
				res(tim_PH22_�����m)
				' tmr(LS3_�ނ炵�@�s�b�`���m, timdlyLS3_�ނ炵�@�s�b�`���m,2)
				' tmr(not(LS3_�ނ炵�@�s�b�`���m), timnotdlyLS3_�ނ炵�@�s�b�`���m,2)
				' tmr(PH22_�����m,timdlyPH22_�����m,2)
				' tmr(PH21_�ނ炵�@�o���Z���T,tim_PH21_�ނ炵�@�o���Z���T,#5)
				' tmr(PH22_�����m,tim_PH22_�����m,#5) 

				'---------------------------------
				inc(�ނ炵�@������R���x�AEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�ނ炵�@������R���x�AEmgStep)		
		end if				
	case 4
		timstack=OFF
		�ނ炵�@������R���x�AEmgStep=0
		�ނ炵�@������R���x�AEmg=OFF
	end select
		
		
end if 'if �ނ炵�@������R���x�AEmgStep=0 then
