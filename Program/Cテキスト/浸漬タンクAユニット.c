'�Z�Ѓ^���NA���j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�Z�Ѓ^���NA
'
'2025/1/27
'�@�[�U�o���u�Ď����Ԃ� #30->#50 �ɕύX
'tmr(SV2_�[�U�o���u�JA and not(XSW1_�[�U�o���u�JA) and not(pnlPBXSW1_�[�U�o���u�JA),tim_notXSW1_�[�U�o���u�JA,#50)
'tmr(not(SV2_�[�U�o���u�JA) and not(XSW2_�[�U�o���u��A) and not(pnlPBXSW2_�[�U�o���u��A),tim_notXSW2_�[�U�o���u��A,#50)
'�A1��ڂ̑��[�U�J�����Ԃ�5�b����7�b�ɕύX
'
'===================================================================================================================
'�Z�Ѓ^���NA���j�b�gErrStep


'�y ���������� �z
if CR2008 then
    �Z�Ѓ^���NA���j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �Z�Ѓ^���NA���j�b�gAutoRun=OFF
    �Z�Ѓ^���NA���j�b�g����=OFF
    �Z�Ѓ^���NA���j�b�gOrgErr=OFF
    �Z�Ѓ^���NA���j�b�gErr=OFF
    �Z�Ѓ^���NA���j�b�gEmg=OFF
    �Z�Ѓ^���NA���j�b�gstep=0
    �Z�Ѓ^���NA���j�b�gErrStep=0
    �Z�Ѓ^���NA���j�b�gOrgErrStep=0
    �Z�Ѓ^���NA���j�b�gEmgStep=0

	�����T�C�N��flg=OFF
	
	�z�ď���step=0
	�V���b�^�[�J��step=0

end if

'===================================================================================================================
'�y ���_ �z 
�Z�Ѓ^���NA���j�b�gOrg=not(�Z�Ѓ^���NA���j�b�g����) or (((XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A) and ((XSW4_���؂�V���b�^�[��A and not(pnlPBXSW4_���؂�V���b�^�[��A)) or passXSW4_���؂�V���b�^�[��A))

'===================================================================================================================
'�y �ً}��~ �z

if 	not(PB����~) then
	�Z�Ѓ^���NA���j�b�gEmg=ON
	�Z�Ѓ^���NA���j�b�gEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(SV2_�[�U�o���u�JA and not(XSW1_�[�U�o���u�JA) and not(pnlPBXSW1_�[�U�o���u�JA),tim_notXSW1_�[�U�o���u�JA,#50)
tmr(not(SV2_�[�U�o���u�JA) and not(XSW2_�[�U�o���u��A) and not(pnlPBXSW2_�[�U�o���u��A),tim_notXSW2_�[�U�o���u��A,#50)
tmr(SSW3_�������[�h and SV4_���؂�V���b�^�[�JA and not(XSW3_���؂�V���b�^�[�JA) and not(pnlPBXSW3_���؂�V���b�^�[�JA),tim_notXSW3_���؂�V���b�^�[�JA,#50)
tmr(SSW3_�������[�h and SV5_���؂�V���b�^�[��A and not(XSW4_���؂�V���b�^�[��A) and not(pnlPBXSW4_���؂�V���b�^�[��A),tim_notXSW4_���؂�V���b�^�[��A,#50)
'tmr(SV60_�r���o���u�JA and not(XSW76_�r���o���u�JA) and not(pnlPBXSW76_�r���o���u�JA), tim_notXSW76_�r���o���u�JA,#30)
'tmr(not(SV60_�r���o���u�JA) and not(XSW77_�r���o���u��A) and not(pnlPBXSW77_�r���o���u��A),tim_notXSW77_�r���o���u��A,#30)

if LDP(mSV2_�[�U�o���u�JA) and XSW1_�[�U�o���u�JA and not(pnlPBXSW1_�[�U�o���u�JA) then
	SET(tim_XSW1_�[�U�o���u�JA)
end if

if LDF(mSV2_�[�U�o���u�JA) and XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A) then
	SET(tim_XSW2_�[�U�o���u��A)
end if

if LDP(SV4_���؂�V���b�^�[�JA) and XSW3_���؂�V���b�^�[�JA and not(pnlPBXSW3_���؂�V���b�^�[�JA) then
	SET(tim_XSW3_���؂�V���b�^�[�JA)
end if

if LDP(SV5_���؂�V���b�^�[��A) and XSW4_���؂�V���b�^�[��A and not(pnlPBXSW4_���؂�V���b�^�[��A) then
	SET(tim_XSW4_���؂�V���b�^�[��A)
end if

if SV4_���؂�V���b�^�[�JA and not(SV5_���؂�V���b�^�[��A) then
	KeepSV4_���؂�V���b�^�[�JA=ON
else if SV5_���؂�V���b�^�[��A then
	KeepSV4_���؂�V���b�^�[�JA=OFF
end if
if SV5_���؂�V���b�^�[��A and not(SV4_���؂�V���b�^�[�JA) then
	KeepSV5_���؂�V���b�^�[��A=ON
else if SV4_���؂�V���b�^�[�JA then
	KeepSV5_���؂�V���b�^�[��A=OFF
end if

'passtimXSW1_�[�U�o���u�JA_val=#2000
tms(SV2_�[�U�o���u�JA,passtimXSW1_�[�U�o���u�JA,passtimXSW1_�[�U�o���u�JA_val)
'passtimXSW2_�[�U�o���u��A_val=#2000
tms(not(SV2_�[�U�o���u�JA),passtimXSW2_�[�U�o���u��A,passtimXSW2_�[�U�o���u��A_val)
'passtimXSW3_���؂�V���b�^�[�JA_val=#1147
tms(KeepSV4_���؂�V���b�^�[�JA,passtimXSW3_���؂�V���b�^�[�JA,passtimXSW3_���؂�V���b�^�[�JA_val)
'passtimXSW4_���؂�V���b�^�[��A_val=#943
tms(KeepSV5_���؂�V���b�^�[��A,passtimXSW4_���؂�V���b�^�[��A,passtimXSW4_���؂�V���b�^�[��A_val) 



if (ldp(tim_XSW1_�[�U�o���u�JA.B) or ldp(tim_notXSW1_�[�U�o���u�JA)) and not(pnlPBXSW1_�[�U�o���u�JA) then
	almXSW1_�[�U�o���u�JA=ON
	pnlPBXSW1_�[�U�o���u�JA=ON
	if tim_XSW1_�[�U�o���u�JA then
		res(tim_XSW1_�[�U�o���u�JA)
	end if
	�Z�Ѓ^���NA���j�b�gErrStep=1
else if (ldp(tim_XSW2_�[�U�o���u��A.B) or ldp(tim_notXSW2_�[�U�o���u��A)) and not(pnlPBXSW2_�[�U�o���u��A) then
	almXSW2_�[�U�o���u��A=ON
	pnlPBXSW2_�[�U�o���u��A=ON
	if tim_XSW2_�[�U�o���u��A then
		res(tim_XSW2_�[�U�o���u��A)
	end if
	�Z�Ѓ^���NA���j�b�gErrStep=1
else if (ldp(tim_XSW3_���؂�V���b�^�[�JA.B) or ldp(tim_notXSW3_���؂�V���b�^�[�JA.B)) and not(pnlPBXSW3_���؂�V���b�^�[�JA) then
	almXSW3_���؂�V���b�^�[�JA=ON
	pnlPBXSW3_���؂�V���b�^�[�JA=ON
	if tim_XSW3_���؂�V���b�^�[�JA then
		res(tim_XSW3_���؂�V���b�^�[�JA)
	end if
	�Z�Ѓ^���NA���j�b�gErrStep=1
else if (ldp(tim_XSW4_���؂�V���b�^�[��A.B) or ldp(tim_notXSW4_���؂�V���b�^�[��A.B)) and not(pnlPBXSW4_���؂�V���b�^�[��A) then
	almXSW4_���؂�V���b�^�[��A=ON
	pnlPBXSW4_���؂�V���b�^�[��A=ON
	if tim_XSW4_���؂�V���b�^�[��A then
		res(tim_XSW4_���؂�V���b�^�[��A)
	end if
	�Z�Ѓ^���NA���j�b�gErrStep=1
end if

'===================================================================================================================
' PL�C���W�P�[�^
	'-------------------------------------------------------------

	if �A���t�@���ă��[�h then
		�Z�Ѓ^���NA���j�b�g����=OFF
	end if
	
	'-------------------------------------------------------------
	
	if not(��������AutoMode) or not(�Z�Ѓ^���NA���j�b�gAutoMode) or �Z�Ѓ^���NA�Ė��� then
		PBL9_�����z��=�����T�C�N��flg and CR2006
	else
		PBL9_�����z��=OFF
	end if
	
	'-------------------------------------------------------------
	PBL10_�^���N����A=SV6_�����d����A

	if ldp(PB10_�^���N����A or pnlPBSV6_�����d����A) then
		if SV6_�����d����A then
			mSV6_�����d����A=OFF
		else
			mSV6_�����d����A=ON
		end if
	end if
	'-------------------------------------------------------------
	PBL30_�r���o���u�J��A=SV60_�r���o���u�JA

	if ldp(PB30_�r���o���u�J��A or pnlPBSV60_�r���o���u�JA ) then		
		if mSV60_�r���o���u�JA then
			mSV60_�r���o���u�JA=OFF
		else
			mSV60_�r���o���u�JA=ON
		end if
	end if
	'-------------------------------------------------------------
	PBL7_�[�U�o���uA=SV2_�[�U�o���u�JA and not(tPBL7_�[�U�o���uA and CR2006)
	tmr(PB7_�[�U�o���uA,tim_PB7_�[�U�o���uA,#30)
	
	select case �[�U�o���ustep

	case 0
		tPBL7_�[�U�o���uA=OFF

		'�ʏ��ON/OFF����
		if not(mSV2_�[�U�o���u�JA) and not(SV4_���؂�V���b�^�[�JA) then
			ejectSV2_�[�U�o���u�JA=PB7_�[�U�o���uA
		else
			ejectSV2_�[�U�o���u�JA=OFF
		end if
		
		if tim_PB7_�[�U�o���uA.B then
			inc(�[�U�o���ustep)
		end if
		
	case 1
		'PB7_�[�U�o���uA OFF�҂�		
		tPBL7_�[�U�o���uA=ON
		
		if not(mSV2_�[�U�o���u�JA) and not(SV4_���؂�V���b�^�[�JA) then
			ejectSV2_�[�U�o���u�JA=ON
		else
			ejectSV2_�[�U�o���u�JA=OFF
		end if
		
		if not(tim_PB7_�[�U�o���uA.B) then
			inc(�[�U�o���ustep)
		end if


	case 2
		'PB7_�[�U�o���uA 
		tPBL7_�[�U�o���uA=ON

		if PB7_�[�U�o���uA or mSV2_�[�U�o���u�JA or SV4_���؂�V���b�^�[�JA then
			ejectSV2_�[�U�o���u�JA=OFF
			inc(�[�U�o���ustep)
		end if
	
	case 3
		if not(PB7_�[�U�o���uA) then
			�[�U�o���ustep=0
		end if
	
	end select
	
	'-------------------------------------------------------------	
	PBL8_���؂�V���b�^�[A=KeepSV4_���؂�V���b�^�[�JA

	if ldp(PB8_���؂�V���b�^�[A) then
		if not(tPBL8_���؂�V���b�^�[A) and not(SV2_�[�U�o���u�JA) then
			mSV4_���؂�V���b�^�[�JA=ON
			mSV5_���؂�V���b�^�[��A=OFF
			tPBL8_���؂�V���b�^�[A=ON

			if not(�A���t�@���ă��[�h) then
				if ��������AutoMode and ��������AutoRun then			
					if ANDA(StageDevice0,$200)=0 and ANDA(StageDevice1,$200)=0 then  
						inc(DM_A�z�Č��ݒl)
					end if
				end if

				StageDevice0=ORA(StageDevice0,$200)
				StageDevice1=ORA(StageDevice1,$200)
			end if
			
		else if tPBL8_���؂�V���b�^�[A then
			mSV4_���؂�V���b�^�[�JA=OFF
			mSV5_���؂�V���b�^�[��A=ON
			tPBL8_���؂�V���b�^�[A=OFF
		end if
	end if

'	if not(mSV4_���؂�V���b�^�[�JA) then
'		tPBL8_���؂�V���b�^�[A=OFF
'	end if
	'-------------------------------------------------------------	


'===================================================================================================================
' �Z���T�[���o�f�B���C�\

	'tmr(PDL1_�p�h���Z���T�[���A,tim_PDL1_�p�h���Z���T�[���A,20)
	tmr(PDL2_�p�h���Z���T�[����A or pnlPBPDL2_�p�h���Z���T�[����A,tim_PDL2_�p�h���Z���T�[����A,20)
	tmr(RLY5_�p�h���Z���T�d�� and not(PDL2_�p�h���Z���T�[����A),timnot_PDL2_�p�h���Z���T�[����A,60)

'===================================================================================================================
' �[�U�o���u�J��

	'FLOS03_LMT121ALM 
	'SV2_�[�U�o���u�JA
	
	tmr(FLOS3_LMT121,timdly_FLOS03_LMT121,10) '�ėL
	tmr(not(FLOS3_LMT121),timnotdly_FLOS03_LMT121,60) '�Ė���

	if pnlPB�����ėLA  then
		�Z�Ѓ^���NA�Ė���=OFF '�ăZ���T�[OFF and �p�h���Z���T�[����OFF

	else if pnlPB�����Ė���A then	
		�Z�Ѓ^���NA�Ė���=ON '�ăZ���T�[ON or �p�h���Z���T�[����  or pnlPB�p�h���Z���T�[����
	
	else if timdly_FLOS03_LMT121.B or tim_PDL2_�p�h���Z���T�[����A.B then  '�ėL
		�Z�Ѓ^���NA�Ė���=OFF '�ăZ���T�[ON or �p�h���Z���T�[����  or pnlPB�p�h���Z���T�[����

	else if timnotdly_FLOS03_LMT121.B and timnot_PDL2_�p�h���Z���T�[����A.B then '�Ė���
		�Z�Ѓ^���NA�Ė���=ON '�ăZ���T�[OFF and �p�h���Z���T�[����OFF

	end if
	

	if ldp(�Z�Ѓ^���NA���j�b�gAutoRun) then
		�����[�U����=ON
	end if
	
'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �Z�Ѓ^���NA���j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �Z�Ѓ^���NA���j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �Z�Ѓ^���NA���j�b�gEmg	���̏��~


if �Z�Ѓ^���NA���j�b�gEmgStep=0 then  
	
	if �Z�Ѓ^���NA���j�b�gErrStep=0  then
	
	if not(�Z�Ѓ^���NA���j�b�gOrgErr) then

		'---------------------------------------------------------------------------------
		tmr(tim_�z�ď���,tim_�z�ď���_val)
		select case �z�ď���step

		case 0

		'1���_�[�U�o���u1�b��_�J��
		
		case 1
			if �A���t�@���ă��[�h then
				�z�ď�������A=ON
				�z�Ċ���A=ON
				�z�ď���step=0			

			else if �����T�C�N��flg or not(�Z�Ѓ^���NA�Ė���) then
				inc(�z�ď���step)
			else
				�z�ď�������A=ON
				�z�Ċ���A=ON
				�z�ď���step=0
			end if	

		case 2
			if �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			else		
				mSV2_�[�U�o���u�JA=ON
				inc(�z�ď���step)
			end if
			
		case 3
			if mSV2_�[�U�o���u�JA then
				if (XSW1_�[�U�o���u�JA and not(pnlPBXSW1_�[�U�o���u�JA)) or passXSW1_�[�U�o���u�JA then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)
			end if			

		case 4
			if �����[�U���� or �����T�C�N��flg then				
				tim_�z�ď���_val=#70 '#50 1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			else
				tim_�z�ď���_val=#15 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			end if			
			
			inc(�z�ď���step)
				
		case 5
			if tim_�z�ď���.B or �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			end if

		case 6
			mSV2_�[�U�o���u�JA=OFF
			inc(�z�ď���step)

		case 7
			if (XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A then
				inc(�z�ď���step)
			end if

		case 8
			tim_�z�ď���_val=#10 '1��ڏ[�U�o���u����
			res(tim_�z�ď���)
			inc(�z�ď���step)


		'2���_�[�U�o���u1�b��_�J��
		case 9
			inc(�z�ď���step)

		case 10
			if �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			else if tim_�z�ď���.B then
				mSV2_�[�U�o���u�JA=ON
				inc(�z�ď���step)
			end if

		case 11
			if mSV2_�[�U�o���u�JA then
				if (XSW1_�[�U�o���u�JA and not(pnlPBXSW1_�[�U�o���u�JA)) or passXSW1_�[�U�o���u�JA then				
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 12
			tim_�z�ď���_val=#15 '�[�U�o���u�J����
			res(tim_�z�ď���)
			inc(�z�ď���step)
			
		case 13
			if tim_�z�ď���.B or �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			end if

		case 14
			mSV2_�[�U�o���u�JA=OFF
			inc(�z�ď���step)

		case 15
			if (XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A then
				inc(�z�ď���step)
			end if

		case 16
			tim_�z�ď���_val=#10 '1��ڏ[�U�o���u����
			res(tim_�z�ď���)
			inc(�z�ď���step)

		'---------------------------------------------------------------------------------
		'�[�U�o���u_�J��
		case 17
			inc(�z�ď���step)

		case 18
			if �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			else if tim_�z�ď���.B then
				mSV2_�[�U�o���u�JA=ON
				inc(�z�ď���step)
			end if

		case 19
			if mSV2_�[�U�o���u�JA then
				if (XSW1_�[�U�o���u�JA and not(pnlPBXSW1_�[�U�o���u�JA)) or passXSW1_�[�U�o���u�JA then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 20
			if �����[�U���� or �����T�C�N��flg then				
				tim_�z�ď���_val=#50 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			else
				tim_�z�ď���_val=#15 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			end if			

			inc(�z�ď���step)

			
		case 21
			if tim_�z�ď���.B or �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			end if

		case 22
			mSV2_�[�U�o���u�JA=OFF
			inc(�z�ď���step)

		case 23
			if (XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A then
				inc(�z�ď���step)
			end if

		case 24
			tim_�z�ď���_val=#10
			res(tim_�z�ď���)
			inc(�z�ď���step)
			
		case 25
			if tim_�z�ď���.B then
				inc(�z�ď���step)
			end if
		
		'-------------------------------------------------------------------------------
		'�[�U�o���u4���
		case 26
			if �����[�U���� or �����T�C�N��flg then
				inc(�z�ď���step)
			else
				�z�ď���step=100
			end if
		
		case 27
			if �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			else 
				mSV2_�[�U�o���u�JA=ON
				inc(�z�ď���step)
			end if
			
		case 28
			if mSV2_�[�U�o���u�JA then
				if (XSW1_�[�U�o���u�JA and not(pnlPBXSW1_�[�U�o���u�JA)) or passXSW1_�[�U�o���u�JA then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 29
			tim_�z�ď���_val=#10 '�[�U�o���u�J����
			res(tim_�z�ď���)
			inc(�z�ď���step)
			
		case 30
			if tim_�z�ď���.B or �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			end if

		case 31
			mSV2_�[�U�o���u�JA=OFF
			inc(�z�ď���step)

		case 32
			if (XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A then
				inc(�z�ď���step)
			end if

		case 33
			tim_�z�ď���_val=#10
			res(tim_�z�ď���)
			inc(�z�ď���step)
			
		case 34
			if tim_�z�ď���.B then
				inc(�z�ď���step)
			end if
		'-------------------------------------------------------------------------------
		'�[�U�o���u5���
		case 35
			if �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			else
				mSV2_�[�U�o���u�JA=ON
				inc(�z�ď���step)
			end if
			
		case 36
			if mSV2_�[�U�o���u�JA then
				if (XSW1_�[�U�o���u�JA and not(pnlPBXSW1_�[�U�o���u�JA)) or passXSW1_�[�U�o���u�JA then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 37
			tim_�z�ď���_val=#10 '�[�U�o���u�J����
			res(tim_�z�ď���)
			inc(�z�ď���step)
			
		case 38
			if tim_�z�ď���.B or �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			end if

		case 39
			mSV2_�[�U�o���u�JA=OFF
			inc(�z�ď���step)

		case 40
			if (XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A then
				�z�ď���step=100
			end if


		'-------------------------------------------------------------------------------
		'���؂莞��
		case 100
			tim_�z�ď���_val=#20 '���؂莞��
			res(tim_�z�ď���)
			inc(�z�ď���step)

		case 101
			if tim_�z�ď���.B then
				inc(�z�ď���step)
			end if

		'-------------------------------------------------------------------------------
		case 102
			if �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			else
				mSV2_�[�U�o���u�JA=ON
				inc(�z�ď���step)
			end if
			
		case 103
			if mSV2_�[�U�o���u�JA then
				if (XSW1_�[�U�o���u�JA and not(pnlPBXSW1_�[�U�o���u�JA)) or passXSW1_�[�U�o���u�JA then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 104
			if �����[�U���� or �����T�C�N��flg then				
				tim_�z�ď���_val=#50 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			else
				tim_�z�ď���_val=#20 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			end if			

			inc(�z�ď���step)			
			
		case 105
			if tim_�z�ď���.B or �Z�Ѓ^���NA�Ė��� then
				inc(�z�ď���step)
			end if

		case 106
			mSV2_�[�U�o���u�JA=OFF
			inc(�z�ď���step)

		case 107
			if (XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A then
				inc(�z�ď���step)
			end if

		'-------------------------------------------------------------------------------
		case 108
			tim_�z�ď���_val=#80 '���؂莞��
			res(tim_�z�ď���)
			inc(�z�ď���step)

		case 109
			if tim_�z�ď���.B then
				inc(�z�ď���step)
			end if

		case 110
			�z�ď�������A=ON
			
			if �����T�C�N��flg and �V���b�^�[�J��step=0 then
				�V���b�^�[�J��step=1
			end if
			
			�z�ď���step=0
			�����[�U����=OFF

		end select
		'===================================================================================================================
		'�V���b�^�[�J��
		tmr(tim_�V���b�^�[�J��,tim_�V���b�^�[�J��_val)
		select case �V���b�^�[�J��step
		case 0
		case 1
'			if �����T�C�N��flg or �z�ď�������A then
			if �����T�C�N��flg or (not(�Z�Ѓ^���NA�Ė���) and �z�ď�������A) then
				�Z�Ѓ^���NA���j�b�gStatusMsg=#13	'	�z�Ē�

				inc(�V���b�^�[�J��step)
			else
				if �Z�Ѓ^���NA�Ė��� then
					�z�ď�������A	=	OFF
					�z�Ċ���A	=	OFF
				end if
				
				�Z�Ѓ^���NA���j�b�gStatusMsg=#0	'	�z�Ē�
				�V���b�^�[�J��step=0
				
			end if
			
		case 2
			mSV4_���؂�V���b�^�[�JA=ON
			mSV5_���؂�V���b�^�[��A=OFF
			inc(�V���b�^�[�J��step)

		case 3
			if (XSW3_���؂�V���b�^�[�JA and not(pnlPBXSW3_���؂�V���b�^�[�JA)) or passXSW3_���؂�V���b�^�[�JA then
				inc(�V���b�^�[�J��step)
			end if

		case 4
			mSV4_���؂�V���b�^�[�JA=OFF
			tim_�V���b�^�[�J��_val=#10 '���؂�V���b�^�[�J����
			res(tim_�V���b�^�[�J��)
			inc(�V���b�^�[�J��step)

		case 5
			if tim_�V���b�^�[�J��.B then
				inc(�V���b�^�[�J��step)
			end if
			
		case 6
			mSV5_���؂�V���b�^�[��A=ON
			inc(�V���b�^�[�J��step)

		case 7
			if (XSW4_���؂�V���b�^�[��A and not(pnlPBXSW4_���؂�V���b�^�[��A)) or passXSW4_���؂�V���b�^�[��A then
				inc(�V���b�^�[�J��step)
			end if

		case 8
			mSV5_���؂�V���b�^�[��A=OFF
			tim_�V���b�^�[�J��_val=10	'���؂�V���b�^�[����
			res(tim_�V���b�^�[�J��)
			inc(�V���b�^�[�J��step)

		case 9
			if tim_�V���b�^�[�J��.B then
				inc(�V���b�^�[�J��step)
			end if

		'---------------------------------------------------------------------------------
		' 2��ڂ̐��؂�V���b�^�[
		case 10
			mSV4_���؂�V���b�^�[�JA=ON
			mSV5_���؂�V���b�^�[��A=OFF
			inc(�V���b�^�[�J��step)

		case 11
			if (XSW3_���؂�V���b�^�[�JA and not(pnlPBXSW3_���؂�V���b�^�[�JA)) or passXSW3_���؂�V���b�^�[�JA then
				inc(�V���b�^�[�J��step)
			end if

		case 12
			mSV4_���؂�V���b�^�[�JA=OFF
			tim_�V���b�^�[�J��_val=#40 '���؂�V���b�^�[�J����
			res(tim_�V���b�^�[�J��)				
			inc(�V���b�^�[�J��step)

		case 13
			if tim_�V���b�^�[�J��.B then
				inc(�V���b�^�[�J��step)
			end if
			
		case 14
			mSV5_���؂�V���b�^�[��A=ON
			inc(�V���b�^�[�J��step)

		case 15
			if (XSW4_���؂�V���b�^�[��A and not(pnlPBXSW4_���؂�V���b�^�[��A)) or passXSW4_���؂�V���b�^�[��A then
				inc(�V���b�^�[�J��step)
			end if

		case 16
			mSV5_���؂�V���b�^�[��A=OFF
			tim_�V���b�^�[�J��_val=10'���؂�V���b�^�[����
			res(tim_�V���b�^�[�J��)
			inc(�V���b�^�[�J��step)

		'---------------------------------------------------------------------------------
		case 17
			if tim_�V���b�^�[�J��.B then
				inc(�V���b�^�[�J��step)
			end if

		case 18
			�Z�Ѓ^���NA���j�b�gStatusMsg=#0	'	�z�Ē�

			�z�ď�������A=OFF
			�z�Ċ���A=ON
			�����T�C�N��flg=OFF
			StageDevice1=ORA(StageDevice1,$200)
			�Z�Ѓ^���NA�r�o�v��=ON
			
			inc(DM_A�z�Č��ݒl)
			
			�V���b�^�[�J��step=0
		end select

	'===================================================================================================================
	'�y �v���Z�X�����i�z�āj �z
	'
	if (not(�Z�Ѓ^���NA�Ė���) and  �Z�Ѓ^���NA���j�b�gAutoMode and ��������AutoMode ) or  �Z�Ѓ^���NA���j�b�gstep<>0  then
'		if �Z�Ѓ^���NA�Ė��� or not(�Z�Ѓ^���NA���j�b�gAutoMode and ��������AutoMode ) then
		if not(�Z�Ѓ^���NA���j�b�gAutoMode and ��������AutoMode ) then	'�Z�Ѓ^���NA�Ė���  or���폜
			�Z�Ѓ^���NA���j�b�gAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �Z�Ѓ^���NA���j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �Z�Ѓ^���NA���j�b�gAutoRun then
				inc(�Z�Ѓ^���NA���j�b�gstep)
			else 
				�Z�Ѓ^���NA���j�b�g���쒆=OFF
				�Z�Ѓ^���NA���j�b�gstep=0 '�I���ҋ@
			end if
		
		case 2
		' [ �Z�Ѓ^���N�����m�F ]
			if not(�Z�Ѓ^���NA�Ė���) then
				inc(�Z�Ѓ^���NA���j�b�gstep)
			else
				�Z�Ѓ^���NA�r�o�v��=ON
				�z�ď�������A=OFF
				�z�Ċ���A=OFF
				�Z�Ѓ^���NA���j�b�gstep=1
			end if
		
		case 3
			' [ ���j�b�g�����o ]
			if �Z�Ѓ^���NA���j�b�g���� then
				'�^���N�ėL
				�Z�Ѓ^���NA���j�b�g���쒆=ON
				�Z�Ѓ^���NB���j�b�g���쒆=OFF
				inc(�Z�Ѓ^���NA���j�b�gstep)
			else
				'�^���N�Ė���
				�z�Ċ���A=ON				
				�Z�Ѓ^���NA���j�b�g���쒆=OFF
				�Z�Ѓ^���NA�r�o�v��=ON
				�Z�Ѓ^���NA���j�b�gstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		case 4
			'�z�ď�������A=OFF ���T�C�N���z�ď��������Ȃ�
			if �z�ď�������A then
				inc(�Z�Ѓ^���NA���j�b�gstep)
			else 
				if �z�ď���step=0 then
					�z�ď���step=1
					�Z�Ѓ^���NA���j�b�gstep=1				
				 else
					�Z�Ѓ^���NA�r�o�v��=ON
					�Z�Ѓ^���NA���j�b�gstep=1
				end if				
			end if			

		case 5
			if �z�Ċ���A then
				�Z�Ѓ^���NA���j�b�gStatusMsg=#14	'	�z�Ċ���				�Z�Ѓ^���NA�r�o�v��=ON
				�Z�Ѓ^���NA�r�o�v��=ON
				�Z�Ѓ^���NA���j�b�gstep=1
				
			else
				inc(�Z�Ѓ^���NA���j�b�gstep)
			end if

		'---------------------------------------------------------------------------------
		case 6					
				' [ �W�J�}�ړ���~�m�F ]
			if �Z�Ѓ^���NA�r�o�v��=OFF and �����R���x�AA���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH1_�����m and PH2_�t�^���m  and not(�z�ăC���^�[�o���֎~) then

						if ANDA(StageDevice1,$200)=0 then '�z�Ă���Ă��Ȃ���
						'if ANDA(StageDevice1,$100)=$100 and ANDA(StageDevice1,$200)=0 then '��򂳂ꂽ�� and �z�Ă���Ă��Ȃ���
							if not(�z�Ċ���A) and �V���b�^�[�J��step=0 then
								�V���b�^�[�J��step=1
							end if	
						else
							�Z�Ѓ^���NA�r�o�v��=ON
						end if
						�Z�Ѓ^���NA���j�b�gstep=1

				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH1_�����m) and PH2_�t�^���m then 
						�Z�Ѓ^���NA�r�o�v��=ON
						�Z�Ѓ^���NA���j�b�gstep=1
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
					else
						�Z�Ѓ^���NA�r�o�v��=ON
						�Z�Ѓ^���NA���j�b�gstep=1
					end if
			else			
				
				�Z�Ѓ^���NA���j�b�gstep=1
			
			end if
		'---------------------------------------------------------------------------------

		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if �Z�Ѓ^���NA���j�b�gstep=0 and �Z�Ѓ^���NA�Ė��� then
			�Z�Ѓ^���NA�r�o�v��=ON
		end if
	
		�Z�Ѓ^���NA���j�b�gAutoRun=OFF
		
		�Z�Ѓ^���NA���j�b�gstep=0 '�I��
		�z�ď�������A=OFF
		�z�Ċ���A=OFF
		
		
		if �Z�Ѓ^���NA���j�b�gstep=0 and �z�ď���step=0 and �V���b�^�[�J��step=0 then
			if not(�Z�Ѓ^���NA���j�b�gAutoMode and ��������AutoMode ) then
				'-------------------------------------------------------------	
				'�[�U�P�T�C�N��
				if ldp(PB9_�����z��A ) and �����T�C�N��flg=OFF  then
					if ((XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A) and ((XSW4_���؂�V���b�^�[��A and not(pnlPBXSW4_���؂�V���b�^�[��A)) or passXSW4_���؂�V���b�^�[��A) then
						mSV2_�[�U�o���u�JA=OFF
						mSV4_���؂�V���b�^�[�JA=OFF
						mSV5_���؂�V���b�^�[��A=OFF
						�����T�C�N��flg=ON
						�z�ď���step=1
					end if
				end if
				'-------------------------------------------------------------	
				if ldp(pnlPBSV2_�[�U�o���u�JA ) then
					if (XSW2_�[�U�o���u��A and not(pnlPBXSW2_�[�U�o���u��A)) or passXSW2_�[�U�o���u��A then
						mSV2_�[�U�o���u�JA=ON
					else if (XSW1_�[�U�o���u�JA and not(pnlPBXSW1_�[�U�o���u�JA)) or passXSW1_�[�U�o���u�JA then
						mSV2_�[�U�o���u�JA=OFF
					end if
				end if

			end if
			'�p�l���X�C�b�`�ł̑���
			if ldp(pnlPBSV4_���؂�V���b�^�[�JA) then
					mSV4_���؂�V���b�^�[�JA=ON
					mSV5_���؂�V���b�^�[��A=OFF
					tPBL8_���؂�V���b�^�[A=ON
					StageDevice0=ORA(StageDevice0,$200)			
					StageDevice1=ORA(StageDevice1,$200)			
					
			else if ldp(pnlPBSV5_���؂�V���b�^�[��A) then
					mSV4_���؂�V���b�^�[�JA=OFF
					mSV5_���؂�V���b�^�[��A=ON
					tPBL8_���؂�V���b�^�[A=OFF
			end if
			
			if mSV5_���؂�V���b�^�[��A and ( (XSW4_���؂�V���b�^�[��A and not(pnlPBXSW4_���؂�V���b�^�[��A)) or passXSW4_���؂�V���b�^�[��A) then
				mSV5_���؂�V���b�^�[��A=OFF
			end if
			if mSV4_���؂�V���b�^�[�JA and ( (XSW3_���؂�V���b�^�[�JA and not(pnlPBXSW3_���؂�V���b�^�[�JA)) or passXSW3_���؂�V���b�^�[�JA) then
				mSV4_���؂�V���b�^�[�JA=OFF
			end if
			
		end if
	
	end if '�Z�Ѓ^���NA���j�b�gAutoMode and not(�Z�Ѓ^���NA���j�b�gOrgErrStep)

	'===================================================================================================================
	'�y �Z�Ѓ^���NA���j�b�gOrgErr �z
	else

		if ResetFlg then
			�Z�Ѓ^���NA���j�b�gOrgErr=OFF
		end if		
		
	end if	
	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		select case �Z�Ѓ^���NA���j�b�gErrStep
		case 0
		case 1
			�Z�Ѓ^���NA���j�b�gErr=ON
			mSV2_�[�U�o���u�JA=OFF

			if ResetFlg then
				almXSW1_�[�U�o���u�JA=OFF
				almXSW2_�[�U�o���u��A=OFF
				almXSW3_���؂�V���b�^�[�JA=OFF
				almXSW4_���؂�V���b�^�[��A=OFF

				inc(�Z�Ѓ^���NA���j�b�gErrStep)
			end if
		case 2
			�Z�Ѓ^���NA���j�b�gErr=OFF

			mSV2_�[�U�o���u�JA=OFF
			res(tim_XSW1_�[�U�o���u�JA.B)
			res(tim_XSW2_�[�U�o���u��A.B)
			res(tim_XSW3_���؂�V���b�^�[�JA.B) 
			res(tim_XSW4_���؂�V���b�^�[��A.B)
			
			res(tim_notXSW1_�[�U�o���u�JA.B)
			res(tim_notXSW2_�[�U�o���u��A.B)
			res(tim_notXSW3_���؂�V���b�^�[�JA.B) 
			res(tim_notXSW4_���؂�V���b�^�[��A.B)
			
			�Z�Ѓ^���NA���j�b�gErrStep=0
		end select

	end if 'if �Z�Ѓ^���NA���j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �Z�Ѓ^���NA���j�b�gEmgStep
	case 0
	
	case 1
		�Z�Ѓ^���NA���j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (not(�Z�Ѓ^���NA�Ė���) and  �Z�Ѓ^���NA���j�b�gAutoMode and ��������AutoMode ) or  �Z�Ѓ^���NA���j�b�gstep<>0  then

			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseSV2_�[�U�o���u�JA=ON
			'eject2SV3_�[�U�o���u��A=ON
			pauseSV4_���؂�V���b�^�[�JA=ON
			ejectSV5_���؂�V���b�^�[��A=ON 'eject2SV5_���؂�V���b�^�[��A=ON
			pauseSV60_�r���o���u�JA=ON
			'eject2SV61_�r���o���u��A=ON

			if not(ejectSV6_�����d����A) then
				pauseSV6_�����d����A=ON
			end if

			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_�V���b�^�[�J��_stack=tim_�V���b�^�[�J��.U
				tim_�z�ď���_stack=tim_�z�ď���.U
				
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV2_�[�U�o���u�JA=OFF
			mSV4_���؂�V���b�^�[�JA=OFF
			mSV5_���؂�V���b�^�[��A=ON '-> Reset����
			mSV60_�r���o���u�JA=OFF
			mSV6_�����d����A=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�Z�Ѓ^���NA���j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�Z�Ѓ^���NA���j�b�gEmgStep)
		end if
	case 3
		if (not(�Z�Ѓ^���NA�Ė���) and  �Z�Ѓ^���NA���j�b�gAutoMode and ��������AutoMode ) or  �Z�Ѓ^���NA���j�b�gstep<>0  then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseSV2_�[�U�o���u�JA=OFF
				'eject2SV3_�[�U�o���u��A=OFF
				pauseSV4_���؂�V���b�^�[�JA=OFF
				ejectSV5_���؂�V���b�^�[��A=OFF 'eject2SV5_���؂�V���b�^�[��A=OFF
				pauseSV60_�r���o���u�JA=OFF
				'eject2SV61_�r���o���u��A=OFF
				
				pauseSV6_�����d����A=OFF

				tim_procstep.U=tim_procstep_stack
				tim_�V���b�^�[�J��.U=tim_�V���b�^�[�J��_stack
				tim_�z�ď���.U=tim_�z�ď���_stack
				
				'---------------------------------
				inc(�Z�Ѓ^���NA���j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			mSV5_���؂�V���b�^�[��A=OFF
			'---------------------------------
			inc(�Z�Ѓ^���NA���j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�Z�Ѓ^���NA���j�b�gEmgStep=0
		�Z�Ѓ^���NA���j�b�gEmg=OFF
	end select
		
end if 'if �Z�Ѓ^���NA���j�b�gEmgStep=0 then
