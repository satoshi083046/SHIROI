'�Z�Ѓ^���NB���j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�Z�Ѓ^���NB
'
'2025/1/27
'�@�[�U�o���u�Ď����Ԃ� #30->#50 �ɕύX
'tmr(SV7_�[�U�o���u�JB and not(XSW5_�[�U�o���u�JB) and not(pnlPBXSW5_�[�U�o���u�JB),tim_notXSW5_�[�U�o���u�JB,#50)
'tmr(not(SV7_�[�U�o���u�JB) and not(XSW6_�[�U�o���u��B) and not(pnlPBXSW6_�[�U�o���u��B),tim_notXSW6_�[�U�o���u��B,#50)
'�A1��ڂ̑��[�U�J�����Ԃ�5�b����7�b�ɕύX
'
'===================================================================================================================

'�y ���������� �z

if CR2008 then
    �Z�Ѓ^���NB���j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �Z�Ѓ^���NB���j�b�gAutoRun=OFF
    �Z�Ѓ^���NB���j�b�g����=OFF
    �Z�Ѓ^���NB���j�b�gOrgErr=OFF
    �Z�Ѓ^���NB���j�b�gErr=OFF
    �Z�Ѓ^���NB���j�b�gEmg=OFF
    �Z�Ѓ^���NB���j�b�gstep=0
    �Z�Ѓ^���NB���j�b�gErrStep=0
    �Z�Ѓ^���NB���j�b�gOrgErrStep=0
    �Z�Ѓ^���NB���j�b�gEmgStep=0

	�����T�C�N��flg=OFF
	
	�z�ď���step=0
	�V���b�^�[�J��step=0

end if

'===================================================================================================================
'�y ���_ �z
�Z�Ѓ^���NB���j�b�gOrg=not(�Z�Ѓ^���NB���j�b�g����) or ((XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B) and ((XSW8_���؂�V���b�^�[��B and not(pnlPBXSW8_���؂�V���b�^�[��B)) or passXSW8_���؂�V���b�^�[��B)

'===================================================================================================================
'�y �ً}��~ �z


if not(PB����~) then
	�Z�Ѓ^���NB���j�b�gEmg=ON
	�Z�Ѓ^���NB���j�b�gEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(SV7_�[�U�o���u�JB and not(XSW5_�[�U�o���u�JB) and not(pnlPBXSW5_�[�U�o���u�JB),tim_notXSW5_�[�U�o���u�JB,#50)
tmr(not(SV7_�[�U�o���u�JB) and not(XSW6_�[�U�o���u��B) and not(pnlPBXSW6_�[�U�o���u��B),tim_notXSW6_�[�U�o���u��B,#50)
tmr(SSW3_�������[�h and SV9_���؂�V���b�^�[�JB and not(XSW7_���؂�V���b�^�[�JB) and not(pnlPBXSW7_���؂�V���b�^�[�JB),tim_notXSW7_���؂�V���b�^�[�JB,#50)
tmr(SSW3_�������[�h and SV10_���؂�V���b�^�[��B and not(XSW8_���؂�V���b�^�[��B) and not(pnlPBXSW8_���؂�V���b�^�[��B),tim_notXSW8_���؂�V���b�^�[��B,#50)
'tmr(SV62_�r���o���u�JB and not(XSW78_�r���o���u�JB) and not(pnlPBXSW78_�r���o���u�JB), tim_notXSW78_�r���o���u�JB,#30)
'tmr(not(SV62_�r���o���u�JB) and not(XSW79_�r���o���u��B) and not(pnlPBXSW79_�r���o���u��B),tim_notXSW79_�r���o���u��B,#30)

if LDP(mSV7_�[�U�o���u�JB) and XSW5_�[�U�o���u�JB and not(pnlPBXSW5_�[�U�o���u�JB) then
	SET(tim_XSW5_�[�U�o���u�JB)
end if

if LDF(mSV7_�[�U�o���u�JB) and XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B) then'
	SET(tim_XSW6_�[�U�o���u��B)
end if

if LDP(SV9_���؂�V���b�^�[�JB) and XSW7_���؂�V���b�^�[�JB and not(pnlPBXSW7_���؂�V���b�^�[�JB) then
	SET(tim_XSW7_���؂�V���b�^�[�JB)
end if

if LDP(SV10_���؂�V���b�^�[��B) and XSW8_���؂�V���b�^�[��B and not(pnlPBXSW8_���؂�V���b�^�[��B) then
	SET(tim_XSW8_���؂�V���b�^�[��B)
end if

if SV9_���؂�V���b�^�[�JB and not(SV10_���؂�V���b�^�[��B) then
	KeepSV9_���؂�V���b�^�[�JB=ON
else if SV10_���؂�V���b�^�[��B then
	KeepSV9_���؂�V���b�^�[�JB=OFF
end if

if SV10_���؂�V���b�^�[��B and not(SV9_���؂�V���b�^�[�JB) then
	KeepSV10_���؂�V���b�^�[��B=ON
else if SV9_���؂�V���b�^�[�JB then
	KeepSV10_���؂�V���b�^�[��B=OFF
end if

'passtimXSW5_�[�U�o���u�JB_val=#2000
tms(SV7_�[�U�o���u�JB,passtimXSW5_�[�U�o���u�JB,passtimXSW5_�[�U�o���u�JB_val)
'passtimXSW6_�[�U�o���u��B_val=#2000
tms(not(SV7_�[�U�o���u�JB),passtimXSW6_�[�U�o���u��B,passtimXSW6_�[�U�o���u��B_val)
'passtimXSW7_���؂�V���b�^�[�JB_val=#1281
tms(KeepSV9_���؂�V���b�^�[�JB,passtimXSW7_���؂�V���b�^�[�JB,passtimXSW7_���؂�V���b�^�[�JB_val)
'passtimXSW8_���؂�V���b�^�[��B_val=#881
tms(KeepSV10_���؂�V���b�^�[��B,passtimXSW8_���؂�V���b�^�[��B,passtimXSW8_���؂�V���b�^�[��B_val) 

if (ldp(tim_XSW5_�[�U�o���u�JB.B) or ldp(tim_notXSW5_�[�U�o���u�JB)) and not(pnlPBXSW5_�[�U�o���u�JB) then
	almXSW5_�[�U�o���u�JB=ON
	pnlPBXSW5_�[�U�o���u�JB=ON
	if tim_XSW5_�[�U�o���u�JB then
		res(tim_XSW5_�[�U�o���u�JB)
	end if
	�Z�Ѓ^���NB���j�b�gErrStep=1

else if (ldp(tim_XSW6_�[�U�o���u��B.B) or ldp(tim_notXSW6_�[�U�o���u��B)) and not(pnlPBXSW6_�[�U�o���u��B) then
	almXSW6_�[�U�o���u��B=ON
	pnlPBXSW6_�[�U�o���u��B=ON
	if tim_XSW6_�[�U�o���u��B then
		res(tim_XSW6_�[�U�o���u��B)
	end if
	�Z�Ѓ^���NB���j�b�gErrStep=1

else if (ldp(tim_XSW7_���؂�V���b�^�[�JB.B) or ldp(tim_notXSW7_���؂�V���b�^�[�JB.B)) and not(pnlPBXSW7_���؂�V���b�^�[�JB) then
	almXSW7_���؂�V���b�^�[�JB=ON
	pnlPBXSW7_���؂�V���b�^�[�JB=ON
	if tim_XSW7_���؂�V���b�^�[�JB then
		res(tim_XSW7_���؂�V���b�^�[�JB)
	end if
	�Z�Ѓ^���NB���j�b�gErrStep=1		

else if (ldp(tim_XSW8_���؂�V���b�^�[��B.B) or ldp(tim_notXSW8_���؂�V���b�^�[��B.B)) and not(pnlPBXSW8_���؂�V���b�^�[��B) then
	almXSW8_���؂�V���b�^�[��B=ON
	pnlPBXSW8_���؂�V���b�^�[��B=ON
	if tim_XSW8_���؂�V���b�^�[��B then
		res(tim_XSW8_���؂�V���b�^�[��B)
	end if
	�Z�Ѓ^���NB���j�b�gErrStep=1

end if
'===================================================================================================================
' PL�C���W�P�[�^
	'-------------------------------------------------------------

	if �A���t�@���ă��[�h then
		�Z�Ѓ^���NB���j�b�g����=OFF
	end if
	
	'-------------------------------------------------------------

	if not(��������AutoMode) or not(�Z�Ѓ^���NB���j�b�gAutoMode) or �Z�Ѓ^���NB�Ė��� then
		PBL13_�����z��B = �����T�C�N��flg and CR2006
	else
		PBL13_�����z��B=OFF
	end if

	'-------------------------------------------------------------
	PBL14_�^���N����B = SV11_�����d����B

	if ldp(pnlPBSV11_�����d����B or PB14_�^���N����B) then
		if mSV11_�����d����B then
			mSV11_�����d����B=OFF
		else
			mSV11_�����d����B=ON
		end if
	end if
	'-------------------------------------------------------------
	PBL31_�r���o���u�J��B = SV62_�r���o���u�JB

	if ldp(PB31_�r���o���u�J��B or pnlPBSV62_�r���o���u�JB) then
		if mSV62_�r���o���u�JB then
			mSV62_�r���o���u�JB=OFF
		else
			mSV62_�r���o���u�JB=ON
		end if
	end if
	'-------------------------------------------------------------
	PBL11_�[�U�o���uB =SV7_�[�U�o���u�JB and not(tPBL11_�[�U�o���uB and CR2006)
	tmr(PB11_�[�U�o���uB,tim_PB11_�[�U�o���uB,#30)

	select case �[�U�o���ustep
	case 0
		'�ʏ��ON/OFF����
		tPBL11_�[�U�o���uB=OFF
		if not(mSV7_�[�U�o���u�JB) and not(SV9_���؂�V���b�^�[�JB) then
			ejectSV7_�[�U�o���u�JB=PB11_�[�U�o���uB
		else
			ejectSV7_�[�U�o���u�JB=OFF
		end if
		
		if tim_PB11_�[�U�o���uB.B then
			inc(�[�U�o���ustep)
		end if
		
	case 1
		'PB11_�[�U�o���uB OFF�҂�		
		tPBL11_�[�U�o���uB=ON
		if not(mSV7_�[�U�o���u�JB) and not(SV9_���؂�V���b�^�[�JB) then
			ejectSV7_�[�U�o���u�JB=ON
		else
			ejectSV7_�[�U�o���u�JB=OFF
		end if
		
		if not(tim_PB11_�[�U�o���uB.B) then
			inc(�[�U�o���ustep)
		end if


	case 2
		'PB11_�[�U�o���uB
		tPBL11_�[�U�o���uB=ON
		if PB11_�[�U�o���uB or mSV7_�[�U�o���u�JB or SV9_���؂�V���b�^�[�JB then
			ejectSV7_�[�U�o���u�JB=OFF
			inc(�[�U�o���ustep)
		end if
	
	
	case 3
		if not(PB11_�[�U�o���uB) then
			�[�U�o���ustep=0
		end if
	end select

	'-------------------------------------------------------------	
	PBL12_���؂�V���b�^�[B=KeepSV9_���؂�V���b�^�[�JB

	if ldp(PB12_���؂�V���b�^�[B) then
		if not(tPBL12_���؂�V���b�^�[B) and not(SV7_�[�U�o���u�JB) then
			mSV9_���؂�V���b�^�[�JB=ON
			mSV10_���؂�V���b�^�[��B=OFF
			tPBL12_���؂�V���b�^�[B=ON

			if not(�A���t�@���ă��[�h) then
				if ��������AutoMode and ��������AutoRun then
					if ANDA(StageDevice1,$200)=0 and ANDA(StageDevice2,$200)=0 and ANDA(StageDevice1,$400)=0 and ANDA(StageDevice2,$400)=0 then
						inc(DM_B�z�Č��ݒl)
					end if
				end if
				
				StageDevice1=ORA(StageDevice1,$400)
				StageDevice2=ORA(StageDevice2,$400)
			end if
			
		else if tPBL12_���؂�V���b�^�[B then
			mSV9_���؂�V���b�^�[�JB=OFF
			mSV10_���؂�V���b�^�[��B=ON
			tPBL12_���؂�V���b�^�[B=OFF

		end if
	end if

'	if not(mSV9_���؂�V���b�^�[�JB) then
'		tPBL12_���؂�V���b�^�[B=OFF
'	end if

'===================================================================================================================
' �Z���T�[���o�f�B���C�\

	tmr(PDL3_�p�h���Z���T�[���B,tim_PDL3_�p�h���Z���T�[���B,20)
	tmr(PDL4_�p�h���Z���T�[����B or pnlPBPDL4_�p�h���Z���T�[����B,tim_PDL4_�p�h���Z���T�[����B,20)
	tmr(RLY5_�p�h���Z���T�d�� and not(PDL4_�p�h���Z���T�[����B),timnot_PDL4_�p�h���Z���T�[����B,60)
'===================================================================================================================
' �[�U�o���u�J��
	'FLOS4_LMT121
	'SV7_�[�U�o���u�JB
	'SV8_�[�U�o���u��B
	tmr(FLOS4_LMT121,timdly_FLOS4_LMT121,10)
	tmr(not(FLOS4_LMT121),timnotdly_FLOS4_LMT121,60)
	
	if pnlPB�����ėLB then
		�Z�Ѓ^���NB�Ė���=OFF
	
	else if pnlPB�����Ė���B then
		�Z�Ѓ^���NB�Ė���=ON	
	
	else if timdly_FLOS4_LMT121.B or tim_PDL4_�p�h���Z���T�[����B.B then
		�Z�Ѓ^���NB�Ė���=OFF '�ăZ���T�[ON or �p�h���Z���T�[����  or pnlPB�p�h���Z���T�[����

	else if timnotdly_FLOS4_LMT121.B and timnot_PDL4_�p�h���Z���T�[����B.B then
		�Z�Ѓ^���NB�Ė���=ON '�ăZ���T�[OFF and �p�h���Z���T�[����OFF
	end if

	if ldp(�Z�Ѓ^���NB���j�b�gAutoRun) then
		�����[�U����=ON
	end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �Z�Ѓ^���NB���j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �Z�Ѓ^���NB���j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �Z�Ѓ^���NB���j�b�gEmg	���̏��~


if �Z�Ѓ^���NB���j�b�gEmgStep=0 then  
	
	if �Z�Ѓ^���NB���j�b�gErrStep=0  then
	
	if not(�Z�Ѓ^���NB���j�b�gOrgErr) then
		'---------------------------------------------------------------------------------
		tmr(tim_�z�ď���,tim_�z�ď���_val)
		select case �z�ď���step

		case 0
		'1���_�[�U�o���u1�b��_�J��
		case 1
			if �A���t�@���ă��[�h then 
				�z�ď�������B=ON
				�z�Ċ���B=ON
				�z�ď���step=0
			
			else if �����T�C�N��flg or  not(�Z�Ѓ^���NB�Ė���) then
				inc(�z�ď���step)
			else
				�z�ď�������B=ON
				�z�Ċ���B=ON
				�z�ď���step=0
			end if	

		case 2
			if �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			else
				mSV7_�[�U�o���u�JB=ON
				inc(�z�ď���step)
			end if

		case 3
			if mSV7_�[�U�o���u�JB then
				if (XSW5_�[�U�o���u�JB and not(pnlPBXSW5_�[�U�o���u�JB)) or passXSW5_�[�U�o���u�JB then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 4
			if �����[�U���� or �����T�C�N��flg then				
				tim_�z�ď���_val=#70 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			else
				tim_�z�ď���_val=#15 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			end if			
			
			inc(�z�ď���step)

		case 5
			if tim_�z�ď���.B or �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			end if

		case 6
			mSV7_�[�U�o���u�JB=OFF	
			inc(�z�ď���step)

		case 7
			if (XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B then
				inc(�z�ď���step)
			end if

		case 8
			tim_�z�ď���_val=#10 '�[�U�o���u����
			res(tim_�z�ď���)
			inc(�z�ď���step)

		'2���_�[�U�o���u1�b��_�J��
		case 9
			inc(�z�ď���step)

		case 10
			if �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			else if tim_�z�ď���.B then
				mSV7_�[�U�o���u�JB=ON			
				inc(�z�ď���step)
			end if

		case 11
			if mSV7_�[�U�o���u�JB then
				if (XSW5_�[�U�o���u�JB and not(pnlPBXSW5_�[�U�o���u�JB)) or passXSW5_�[�U�o���u�JB then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if
		case 12
			if �����[�U���� or �����T�C�N��flg then				
				tim_�z�ď���_val=#50 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			else
				tim_�z�ď���_val=#20 '1��ڏ[�U�o���u�J������
				res(tim_�z�ď���)
			end if			

			inc(�z�ď���step)

		case 13
			if tim_�z�ď���.B or �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			end if

		case 14
			mSV7_�[�U�o���u�JB=OFF	
			inc(�z�ď���step)

		case 15
			if (XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B then
				inc(�z�ď���step)
			end if

		case 16
			tim_�z�ď���_val=#10 '�[�U�o���u����
			res(tim_�z�ď���)
			inc(�z�ď���step)

		'---------------------------------------------------------------------------------
		case 17
			inc(�z�ď���step)

		case 18
			if �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			else if tim_�z�ď���.B then
				mSV7_�[�U�o���u�JB=ON
				inc(�z�ď���step)
			end if

		case 19
			if mSV7_�[�U�o���u�JB then
				if (XSW5_�[�U�o���u�JB and not(pnlPBXSW5_�[�U�o���u�JB)) or passXSW5_�[�U�o���u�JB then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 20
			tim_�z�ď���_val=#10 '�[�U�o���u�J������
			res(tim_�z�ď���)
			inc(�z�ď���step)
					
		case 21
			if tim_�z�ď���.B or �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			end if

		case 22
			'mSV8_�[�U�o���u��B=ON
			mSV7_�[�U�o���u�JB=OFF	
			inc(�z�ď���step)

		case 23
			if (XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B then
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

		'-------------------------------------------------------------------------
		'�[�U�o���u4���
		case 26
			if �����[�U���� or �����T�C�N��flg then
				inc(�z�ď���step)
			else
				�z�ď���step=100
			end if
		
		case 27
			if �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			else if tim_�z�ď���.B then
				mSV7_�[�U�o���u�JB=ON
				inc(�z�ď���step)
			end if

		case 28
			if mSV7_�[�U�o���u�JB then
				if (XSW5_�[�U�o���u�JB and not(pnlPBXSW5_�[�U�o���u�JB)) or passXSW5_�[�U�o���u�JB then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 29
			tim_�z�ď���_val=#10 '�[�U�o���u�J������
			res(tim_�z�ď���)
			inc(�z�ď���step)
					
		case 30
			if tim_�z�ď���.B or �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			end if

		case 31
			mSV7_�[�U�o���u�JB=OFF	
			inc(�z�ď���step)

		case 32
			if (XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B then
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

		'-------------------------------------------------------------------------
		'�[�U�o���u5���
		case 35
			if �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			else if tim_�z�ď���.B then
				mSV7_�[�U�o���u�JB=ON
				inc(�z�ď���step)
			end if

		case 36
			if mSV7_�[�U�o���u�JB then
				if (XSW5_�[�U�o���u�JB and not(pnlPBXSW5_�[�U�o���u�JB)) or passXSW5_�[�U�o���u�JB then
					inc(�z�ď���step)
				end if
			else
				inc(�z�ď���step)			
			end if

		case 37
			'mSV7_�[�U�o���u�JB=OFF	
			tim_�z�ď���_val=#10 '�[�U�o���u�J������
			res(tim_�z�ď���)
			inc(�z�ď���step)
					
		case 38
			if tim_�z�ď���.B or �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			end if

		case 39
			mSV7_�[�U�o���u�JB=OFF	
			inc(�z�ď���step)

		case 40
			if (XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B then
				�z�ď���step=100
			end if


		'-------------------------------------------------------------------------
		'���؂莞��
		case 100
			tim_�z�ď���_val=#20 '���؂莞��
			res(tim_�z�ď���)
			inc(�z�ď���step)
			
		case 101
			if tim_�z�ď���.B then
				inc(�z�ď���step)
			end if
		
		'-------------------------------------------------------------------------
		case 102
			if �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)		
			else 		
				mSV7_�[�U�o���u�JB=ON
				inc(�z�ď���step)
			end if
			
		case 103
			if �����[�U���� or �����T�C�N��flg then
				tim_�z�ď���_val=#50 '�[�U�o���u�J����
				res(tim_�z�ď���)
			else
				tim_�z�ď���_val=#20 '�[�U�o���u�J����
				res(tim_�z�ď���)			
			end if

			inc(�z�ď���step)

		case 104
			tim_�z�ď���_val=#20 '�[�U�o���u�J������
			res(tim_�z�ď���)
			inc(�z�ď���step)
					
		case 105
			if tim_�z�ď���.B or �Z�Ѓ^���NB�Ė��� then
				inc(�z�ď���step)
			end if

		case 106
			mSV7_�[�U�o���u�JB=OFF	
			inc(�z�ď���step)

		case 107
			if (XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B then
				inc(�z�ď���step)
			end if
		
		'-------------------------------------------------------------------------
		case 108
			tim_�z�ď���_val=#80 '���؂莞��
			res(tim_�z�ď���)
			inc(�z�ď���step)

		case 109
			if tim_�z�ď���.B then
				inc(�z�ď���step)
			end if


		case 110
			�z�ď�������B=ON
			
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
'			if �����T�C�N��flg or �z�ď�������B then
			if �����T�C�N��flg or (not(�Z�Ѓ^���NB�Ė���) and �z�ď�������B) then
				inc(�V���b�^�[�J��step)
			else
					if �Z�Ѓ^���NB�Ė���	then
						�z�ď�������B = OFF
						�z�Ċ���B = OFF
					end if
				�V���b�^�[�J��step=0
			end if
		
		case 2
			mSV9_���؂�V���b�^�[�JB=ON
			mSV10_���؂�V���b�^�[��B=OFF			
			inc(�V���b�^�[�J��step)

		case 3
			if (XSW7_���؂�V���b�^�[�JB and not(pnlPBXSW7_���؂�V���b�^�[�JB)) or passXSW7_���؂�V���b�^�[�JB then
				inc(�V���b�^�[�J��step)
			end if

		case 4
			mSV9_���؂�V���b�^�[�JB=OFF
			tim_�V���b�^�[�J��_val=#10 '���؂�V���b�^�[�J����
			res(tim_�V���b�^�[�J��)				
			inc(�V���b�^�[�J��step)
				
		case 5
			if tim_�V���b�^�[�J��.B then
				inc(�V���b�^�[�J��step)
			end if

		case 6
			mSV10_���؂�V���b�^�[��B=ON
			inc(�V���b�^�[�J��step)

		case 7
			if (XSW8_���؂�V���b�^�[��B and not(pnlPBXSW8_���؂�V���b�^�[��B)) or passXSW8_���؂�V���b�^�[��B then
				inc(�V���b�^�[�J��step)
			end if

		case 8
			mSV10_���؂�V���b�^�[��B=OFF
			tim_�V���b�^�[�J��_val=10	'���؂�V���b�^�[����
			res(tim_�V���b�^�[�J��)
			inc(�V���b�^�[�J��step)

		case 9
			if tim_�V���b�^�[�J��.B then
				inc(�V���b�^�[�J��step)
			end if

		'---------------------------------------------------------------------------------
		'2��ڂ̐��؂�V���b�^�[

		case 10
			mSV9_���؂�V���b�^�[�JB=ON
			mSV10_���؂�V���b�^�[��B=OFF
			inc(�V���b�^�[�J��step)

		case 11
			if (XSW7_���؂�V���b�^�[�JB and not(pnlPBXSW7_���؂�V���b�^�[�JB)) or passXSW7_���؂�V���b�^�[�JB then
				inc(�V���b�^�[�J��step)
			end if

		case 12
			mSV9_���؂�V���b�^�[�JB=OFF
			tim_�V���b�^�[�J��_val=#40 '���؂�V���b�^�[�J����
			res(tim_�V���b�^�[�J��)				
			inc(�V���b�^�[�J��step)
				
		case 13
			if tim_�V���b�^�[�J��.B then
				inc(�V���b�^�[�J��step)
			end if

		case 14
			mSV10_���؂�V���b�^�[��B=ON
			inc(�V���b�^�[�J��step)

		case 15
			if (XSW8_���؂�V���b�^�[��B and not(pnlPBXSW8_���؂�V���b�^�[��B)) or passXSW8_���؂�V���b�^�[��B then
				inc(�V���b�^�[�J��step)
			end if

		case 16
			mSV10_���؂�V���b�^�[��B=OFF
			tim_�V���b�^�[�J��_val=10	'���؂�V���b�^�[����
			res(tim_�V���b�^�[�J��)
			inc(�V���b�^�[�J��step)

		'---------------------------------------------------------------------------------
		case 17
			if tim_�V���b�^�[�J��.B then
				inc(�V���b�^�[�J��step)
			end if

		case 18
			�z�ď�������B=OFF
			�z�Ċ���B=ON
			�����T�C�N��flg=OFF
			StageDevice2=ORA(StageDevice2,$400)
			�Z�Ѓ^���NB�r�o�v��=ON

			inc(DM_B�z�Č��ݒl)
			
			�V���b�^�[�J��step=0

		end select
	'===================================================================================================================
	'�y �v���Z�X�����i�z�āj �z
	'
	if (not(�Z�Ѓ^���NB�Ė���) and �Z�Ѓ^���NB���j�b�gAutoMode and ��������AutoMode ) or �Z�Ѓ^���NB���j�b�gstep<>0 then

'		if �Z�Ѓ^���NB�Ė��� or not(�Z�Ѓ^���NB���j�b�gAutoMode and ��������AutoMode ) then
		if not(�Z�Ѓ^���NB���j�b�gAutoMode and ��������AutoMode ) then	'�Z�Ѓ^���NB�Ė��� or �폜
			�Z�Ѓ^���NB���j�b�gAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �Z�Ѓ^���NB���j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �Z�Ѓ^���NB���j�b�gAutoRun then
				inc(�Z�Ѓ^���NB���j�b�gstep)
			else
				�Z�Ѓ^���NB���j�b�g���쒆=OFF
				�Z�Ѓ^���NB���j�b�gstep=0 '�I���ҋ@
			end if
		
		case 2
		' [ �Z�Ѓ^���N�����m�F ]
			if not(�Z�Ѓ^���NB�Ė���) then
				inc(�Z�Ѓ^���NB���j�b�gstep)
			else
				�Z�Ѓ^���NB�r�o�v��=ON
				�z�ď�������B=OFF
				�z�Ċ���B=OFF
				�Z�Ѓ^���NB���j�b�gstep=1
			end if
		
		case 3
		' [ ���j�b�g�����o ]
			if �Z�Ѓ^���NB���j�b�g���� and (�Z�Ѓ^���NA�Ė��� or not(�Z�Ѓ^���NA���j�b�g����)) then
				'�^���N�ėL
				�Z�Ѓ^���NB���j�b�g���쒆=ON	
				�Z�Ѓ^���NA���j�b�g���쒆=OFF
				inc(�Z�Ѓ^���NB���j�b�gstep)
			else
				'�^���N�Ė���
				�Z�Ѓ^���NA���j�b�g���쒆=OFF
				�Z�Ѓ^���NB���j�b�g���쒆=OFF
				�z�Ċ���B=ON
				�Z�Ѓ^���NB�r�o�v��=ON
				�Z�Ѓ^���NB���j�b�gstep=1
			end if
		

		case 4
			if �z�ď�������B then
				inc(�Z�Ѓ^���NB���j�b�gstep)
			else 
				if �z�ď���step=0 then
					�z�ď���step=1
					�Z�Ѓ^���NB���j�b�gstep=1
				else
					�Z�Ѓ^���NB�r�o�v��=ON
					�Z�Ѓ^���NB���j�b�gstep=1				
				end if
			end if

		case 5
			if �z�Ċ���B then
				�Z�Ѓ^���NB���j�b�gStatusMsg=#14	'	�z�Ċ���
				�Z�Ѓ^���NB�r�o�v��=ON
				�Z�Ѓ^���NB���j�b�gstep=1
			else
				inc(�Z�Ѓ^���NB���j�b�gstep)
			end if

			'---------------------------------------------------------------------------------
		case 6
		' [ �W�J�}�ړ���~�m�F ]
			if �Z�Ѓ^���NB�r�o�v��=OFF and  �����R���x�AA���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH3_�����m and PH4_�t�^���m and not(�z�ăC���^�[�o���֎~) then
						if ANDA(StageDevice2,$200)=0 and ANDA(StageDevice2,$400)=0 then
						'if ANDA(StageDevice2,$100)=$100 and ANDA(StageDevice2,$200)=0 and ANDA(StageDevice2,$400)=0 then
							if not(�z�Ċ���B) and �V���b�^�[�J��step=0 then
								�V���b�^�[�J��step=1
							end if
						else
							�Z�Ѓ^���NB�r�o�v��=ON
						end if

						�Z�Ѓ^���NB���j�b�gstep=1					
											
						
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH3_�����m) and PH4_�t�^���m then 
						�Z�Ѓ^���NB�r�o�v��=ON
						�Z�Ѓ^���NB���j�b�gstep=1
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
					else
						�Z�Ѓ^���NB�r�o�v��=ON
						�Z�Ѓ^���NB���j�b�gstep=1
					end if
			
			else
				
				�Z�Ѓ^���NB���j�b�gstep=1
			
			end if
		
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if �Z�Ѓ^���NB���j�b�gstep=0 and �Z�Ѓ^���NB�Ė��� then
			�Z�Ѓ^���NB�r�o�v��=ON
		end if

		�Z�Ѓ^���NB���j�b�gAutoRun=OFF
		
		�Z�Ѓ^���NB���j�b�gstep=0 '�I��
		�z�ď�������B=OFF
		�z�Ċ���B=OFF
		
		if �Z�Ѓ^���NB���j�b�gstep=0 and �z�ď���step=0 and �V���b�^�[�J��step=0 then
			if not(�Z�Ѓ^���NB���j�b�gAutoMode and ��������AutoMode ) then
				'-------------------------------------------------------------
				'�[�U�P�T�C�N��
				if ldp(PB13_�����z��B) and �����T�C�N��flg=OFF then
					if ((XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B) and ((XSW8_���؂�V���b�^�[��B and not(pnlPBXSW8_���؂�V���b�^�[��B)) or passXSW8_���؂�V���b�^�[��B) then
						mSV7_�[�U�o���u�JB=OFF
						mSV9_���؂�V���b�^�[�JB=OFF
						mSV10_���؂�V���b�^�[��B=OFF			
						�����T�C�N��flg=ON
						�z�ď���step=1
				
					end if
				end if
				'-------------------------------------------------------------				
				if ldp(pnlPBSV7_�[�U�o���u�JB ) then
					if (XSW6_�[�U�o���u��B and not(pnlPBXSW6_�[�U�o���u��B)) or passXSW6_�[�U�o���u��B then
						mSV7_�[�U�o���u�JB=ON						
					else if (XSW5_�[�U�o���u�JB and not(pnlPBXSW5_�[�U�o���u�JB)) or passXSW5_�[�U�o���u�JB then
						mSV7_�[�U�o���u�JB=OFF
					end if
				end if
				
			end if
			'-------------------------------------------------------------
			'�p�l���X�C�b�`�ł̊J��
			if ldp(pnlPBSV9_���؂�V���b�^�[�JB) then
					mSV9_���؂�V���b�^�[�JB=ON
					mSV10_���؂�V���b�^�[��B=OFF
					tPBL12_���؂�V���b�^�[B=ON
					
					StageDevice1=ORA(StageDevice1,$400)
					StageDevice2=ORA(StageDevice2,$400)

			else if ldp(pnlPBSV10_���؂�V���b�^�[��B) then
					mSV9_���؂�V���b�^�[�JB=OFF
					mSV10_���؂�V���b�^�[��B=ON
					tPBL12_���؂�V���b�^�[B=OFF
			end if
			
			if mSV10_���؂�V���b�^�[��B and ( (XSW8_���؂�V���b�^�[��B and not(pnlPBXSW8_���؂�V���b�^�[��B)) or passXSW8_���؂�V���b�^�[��B) then
				mSV10_���؂�V���b�^�[��B=OFF
			end if
			if mSV9_���؂�V���b�^�[�JB and ( (XSW7_���؂�V���b�^�[�JB and not(pnlPBXSW7_���؂�V���b�^�[�JB)) or passXSW7_���؂�V���b�^�[�JB) then
				mSV9_���؂�V���b�^�[�JB=OFF
			end if
			

		end if

		'-------------------------------------------------------------
		
	
	end if '�Z�Ѓ^���NB���j�b�gAutoMode and not(�Z�Ѓ^���NB���j�b�gOrgErrStep)
	'===================================================================================================================
	'�y �Z�Ѓ^���NB���j�b�gOrgErr���� �z
	else
		if ResetFlg then
			�Z�Ѓ^���NB���j�b�gOrgErr=OFF
		end if		

	end if
	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		�Z�Ѓ^���NB���j�b�gErr=ON

		select case �Z�Ѓ^���NB���j�b�gErrStep
		case 0
		case 1
			mSV7_�[�U�o���u�JB=OFF
			'mSV8_�[�U�o���u��B=ON
			
			if ResetFlg then
				almXSW5_�[�U�o���u�JB=OFF
				almXSW6_�[�U�o���u��B=OFF
				almXSW7_���؂�V���b�^�[�JB=OFF
				almXSW8_���؂�V���b�^�[��B=OFF

				inc(�Z�Ѓ^���NB���j�b�gErrStep)
			end if
		case 2
			mSV7_�[�U�o���u�JB=OFF
			'mSV8_�[�U�o���u��B=OFF

			�Z�Ѓ^���NB���j�b�gErr=OFF

			res(tim_XSW5_�[�U�o���u�JB.B)
			res(tim_XSW6_�[�U�o���u��B.B)
			res(tim_XSW7_���؂�V���b�^�[�JB.B) 
			res(tim_XSW8_���؂�V���b�^�[��B.B)
			
			res(tim_notXSW5_�[�U�o���u�JB.B)
			res(tim_notXSW6_�[�U�o���u��B.B)
			res(tim_notXSW7_���؂�V���b�^�[�JB.B) 
			res(tim_notXSW8_���؂�V���b�^�[��B.B)
			
			�Z�Ѓ^���NB���j�b�gErrStep=0
		end select

	end if 'if �Z�Ѓ^���NB���j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else


	select case �Z�Ѓ^���NB���j�b�gEmgStep
	case 0
	
	case 1
		�Z�Ѓ^���NB���j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (not(�Z�Ѓ^���NB�Ė���) and �Z�Ѓ^���NB���j�b�gAutoMode and ��������AutoMode ) or �Z�Ѓ^���NB���j�b�gstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseSV7_�[�U�o���u�JB=ON
			'eject2SV8_�[�U�o���u��B=ON
			pauseSV9_���؂�V���b�^�[�JB=ON
			ejectSV10_���؂�V���b�^�[��B=ON
			pauseSV62_�r���o���u�JB=ON
			'eject2SV63_�r���o���u��B=ON

			if not(ejectSV11_�����d����B) then
				pauseSV11_�����d����B=ON
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
			mSV7_�[�U�o���u�JB=OFF
			mSV9_���؂�V���b�^�[�JB=OFF
			mSV10_���؂�V���b�^�[��B=ON '��Reset����
			mSV62_�r���o���u�JB=OFF
			mSV11_�����d����B=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�Z�Ѓ^���NB���j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�Z�Ѓ^���NB���j�b�gEmgStep)
		end if
	case 3
		if (not(�Z�Ѓ^���NB�Ė���) and �Z�Ѓ^���NB���j�b�gAutoMode and ��������AutoMode ) or �Z�Ѓ^���NB���j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseSV7_�[�U�o���u�JB=OFF
				'eject2SV8_�[�U�o���u��B=OFF
				pauseSV9_���؂�V���b�^�[�JB=OFF
				ejectSV10_���؂�V���b�^�[��B=OFF
				pauseSV62_�r���o���u�JB=OFF
				'eject2SV63_�r���o���u��B=OFF
				pauseSV11_�����d����B=OFF
				
				tim_procstep.U=tim_procstep_stack
				tim_�V���b�^�[�J��.U=tim_�V���b�^�[�J��_stack
				tim_�z�ď���.U=tim_�z�ď���_stack
				
				'---------------------------------
				inc(�Z�Ѓ^���NB���j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------	
			mSV10_���؂�V���b�^�[��B=OFF
			'---------------------------------
			inc(�Z�Ѓ^���NB���j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�Z�Ѓ^���NB���j�b�gEmgStep=0
		�Z�Ѓ^���NB���j�b�gEmg=OFF
	end select
		
end if 'if �Z�Ѓ^���NB���j�b�gEmgStep=0 then
