'���R���x�A����
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	���R���x�A����
'	
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    ���R���x�A����AutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���R���x�A����AutoRun=OFF
    ���R���x�A��������=ON
    ���R���x�A����OrgErr=OFF
    ���R���x�A����Err=OFF
    ���R���x�A����Emg=OFF
    ���R���x�A����step=0
    ���R���x�A����ErrStep=0
    ���R���x�A����OrgErrStep=0
    ���R���x�A����EmgStep=0

	INV1_�R���x�A���[�^���]step=0
	INV2_�R���x�A���[�^���]step=0
	INV3_�R���x�A���[�^���]step=0
	
	�����T�C�N��flg=OFF
	
	ManualInite=1

end if
'===================================================================================================================
'�y ���_ �z�������֎~
���R���x�A����Org=(not(SV71_���t�^�X�g�b�p) and ((XSW85_���t�^�X�g�b�p���~�[ and not(pnlPBXSW85_���t�^�X�g�b�p���~�[)) or passXSW85_���t�^�X�g�b�p���~�[)) or (SV71_���t�^�X�g�b�p and (not(XSW85_���t�^�X�g�b�p���~�[) or pnlPBXSW85_���t�^�X�g�b�p���~�[))
���R���x�A����Org=���R���x�A����Org and (not(SV77_���t�^�X�g�b�p) and ((XSW90_���t�^�X�g�b�p���~�[ and not(pnlPBXSW90_���t�^�X�g�b�p���~�[)) or passXSW90_���t�^�X�g�b�p���~�[)) or (SV77_���t�^�X�g�b�p and (not(XSW90_���t�^�X�g�b�p���~�[) or pnlPBXSW90_���t�^�X�g�b�p���~�[))
���R���x�A����Org=���R���x�A����Org and (not(SV83_���t�^�X�g�b�p) and ((XSW95_���t�^�X�g�b�p���~�[ and not(pnlPBXSW95_���t�^�X�g�b�p���~�[)) or passXSW95_���t�^�X�g�b�p���~�[)) or (SV83_���t�^�X�g�b�p and (not(XSW95_���t�^�X�g�b�p���~�[) or pnlPBXSW95_���t�^�X�g�b�p���~�[)) 
���R���x�A����Org=���R���x�A����Org and (not(SV89_���t�^�X�g�b�p) and ((XSW100_���t�^�X�g�b�p���~�[ and not(pnlPBXSW100_���t�^�X�g�b�p���~�[)) or passXSW100_���t�^�X�g�b�p���~�[)) or (SV89_���t�^�X�g�b�p and (not(XSW100_���t�^�X�g�b�p���~�[) or pnlPBXSW100_���t�^�X�g�b�p���~�[)) 
���R���x�A����Org=���R���x�A����Org and (not(SV95_���t�^�X�g�b�p) and ((XSW105_���t�^�X�g�b�p���~�[ and not(pnlPBXSW105_���t�^�X�g�b�p���~�[)) or passXSW105_���t�^�X�g�b�p���~�[)) or (SV95_���t�^�X�g�b�p and (not(XSW105_���t�^�X�g�b�p���~�[) or pnlPBXSW105_���t�^�X�g�b�p���~�[))
���R���x�A����Org=���R���x�A����Org or �������֎~

'===================================================================================================================
'�y �ً}��~ �z
if not(PB����~) then
	���R���x�A����Emg=ON
	���R���x�A����EmgStep=1
end if
'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(not(SV71_���t�^�X�g�b�p) and not(XSW85_���t�^�X�g�b�p���~�[) and not(pnlPBXSW85_���t�^�X�g�b�p���~�[), tim_notXSW85_���t�^�X�g�b�p���~�[,#20)
tmr(not(SV77_���t�^�X�g�b�p) and not(XSW90_���t�^�X�g�b�p���~�[) and not(pnlPBXSW90_���t�^�X�g�b�p���~�[), tim_notXSW90_���t�^�X�g�b�p���~�[,#20)
tmr(not(SV83_���t�^�X�g�b�p) and not(XSW95_���t�^�X�g�b�p���~�[) and not(pnlPBXSW95_���t�^�X�g�b�p���~�[), tim_notXSW95_���t�^�X�g�b�p���~�[,#20)
tmr(not(SV89_���t�^�X�g�b�p) and not(XSW100_���t�^�X�g�b�p���~�[) and not(pnlPBXSW100_���t�^�X�g�b�p���~�[), tim_notXSW100_���t�^�X�g�b�p���~�[,#20)
tmr(not(SV95_���t�^�X�g�b�p) and not(XSW105_���t�^�X�g�b�p���~�[) and not(pnlPBXSW105_���t�^�X�g�b�p���~�[), tim_notXSW105_���t�^�X�g�b�p���~�[,#20)

'tmr(SV71_���t�^�X�g�b�p and XSW85_���t�^�X�g�b�p���~�[ and not(pnlPBXSW85_���t�^�X�g�b�p���~�[), tim_XSW85_���t�^�X�g�b�p���~�[,#10)
if LDF(SV71_���t�^�X�g�b�p) and XSW85_���t�^�X�g�b�p���~�[ and not(pnlPBXSW85_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW85_���t�^�X�g�b�p���~�[)
end if
'tmr(SV77_���t�^�X�g�b�p and XSW90_���t�^�X�g�b�p���~�[ and not(pnlPBXSW90_���t�^�X�g�b�p���~�[), tim_XSW90_���t�^�X�g�b�p���~�[,#10)
if LDF(SV77_���t�^�X�g�b�p) and XSW90_���t�^�X�g�b�p���~�[ and not(pnlPBXSW90_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW90_���t�^�X�g�b�p���~�[)
end if
'tmr(SV83_���t�^�X�g�b�p and XSW95_���t�^�X�g�b�p���~�[ and not(pnlPBXSW95_���t�^�X�g�b�p���~�[), tim_XSW95_���t�^�X�g�b�p���~�[,#10)
if LDF(SV83_���t�^�X�g�b�p) and XSW95_���t�^�X�g�b�p���~�[ and not(pnlPBXSW95_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW95_���t�^�X�g�b�p���~�[)
end if
'tmr(SV89_���t�^�X�g�b�p and XSW100_���t�^�X�g�b�p���~�[ and not(pnlPBXSW100_���t�^�X�g�b�p���~�[), tim_XSW100_���t�^�X�g�b�p���~�[,#10)
if LDF(SV89_���t�^�X�g�b�p) and XSW100_���t�^�X�g�b�p���~�[ and not(pnlPBXSW100_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW100_���t�^�X�g�b�p���~�[)
end if
'tmr(SV95_���t�^�X�g�b�p and XSW105_���t�^�X�g�b�p���~�[ and not(pnlPBXSW105_���t�^�X�g�b�p���~�[), tim_XSW105_���t�^�X�g�b�p���~�[,#10)
if LDF(SV95_���t�^�X�g�b�p) and XSW105_���t�^�X�g�b�p���~�[ and not(pnlPBXSW105_���t�^�X�g�b�p���~�[) then
	SET(tim_XSW105_���t�^�X�g�b�p���~�[)
end if

'passtimXSW85_���t�^�X�g�b�p���~�[_val=#500
tms(not(SV71_���t�^�X�g�b�p), passtimXSW85_���t�^�X�g�b�p���~�[,passtimXSW85_���t�^�X�g�b�p���~�[_val)

'passtimXSW90_���t�^�X�g�b�p���~�[_val=#500
tms(not(SV77_���t�^�X�g�b�p), passtimXSW90_���t�^�X�g�b�p���~�[,passtimXSW90_���t�^�X�g�b�p���~�[_val)

'passtimXSW95_���t�^�X�g�b�p���~�[_val=#500
tms(not(SV83_���t�^�X�g�b�p), passtimXSW95_���t�^�X�g�b�p���~�[,passtimXSW95_���t�^�X�g�b�p���~�[_val) 

'passtimXSW100_���t�^�X�g�b�p���~�[_val=#500
tms(not(SV89_���t�^�X�g�b�p), passtimXSW100_���t�^�X�g�b�p���~�[,passtimXSW100_���t�^�X�g�b�p���~�[_val) 

'passtimXSW105_���t�^�X�g�b�p���~�[_val=#500
tms(not(SV95_���t�^�X�g�b�p), passtimXSW105_���t�^�X�g�b�p���~�[,passtimXSW105_���t�^�X�g�b�p���~�[_val) 

'tmr(mINV1_�R���x�A���[�^���] and not(tmp2INV1_�R���x�A���[�^���]) and not(pauseINV1_�R���x�A���[�^���]) and not(EmgINV1_�R���x�A���[�^���]),timerr_INV1_�R���x�A���[�^���],#150)
'tmr(mINV2_�R���x�A���[�^���] and not(tmp2INV2_�R���x�A���[�^���]) and not(pauseINV2_�R���x�A���[�^���]) and not(EmgINV2_�R���x�A���[�^���]),timerr_INV2_�R���x�A���[�^���],#200)
'tmr(ejectINV3_�R���x�A���[�^���] and not(tmp2INV3_�R���x�A���[�^���]) and not(pauseINV3_�R���x�A���[�^���]) and not(EmgINV3_�R���x�A���[�^���]),timerr_INV3_�R���x�A���[�^���],#200)

if ldp(timerr_INV1_�R���x�A���[�^���].B) then
	almINV1_�R���x�A���[�^���]=ON

	mINV1_�R���x�A���[�^���]=OFF
	mINV2_�R���x�A���[�^���]=OFF
	ejectINV3_�R���x�A���[�^���]=OFF
	

	���R���x�A����ErrStep=1

else if ldp(timerr_INV2_�R���x�A���[�^���].B) then
	almINV2_�R���x�A���[�^���]=ON

	mINV1_�R���x�A���[�^���]=OFF
	mINV2_�R���x�A���[�^���]=OFF
	ejectINV3_�R���x�A���[�^���]=OFF
	
	���R���x�A����ErrStep=1


else if ldp(timerr_INV3_�R���x�A���[�^���]) then
	almINV3_�R���x�A���[�^���]=ON

	mINV1_�R���x�A���[�^���]=OFF
	mINV2_�R���x�A���[�^���]=OFF
	ejectINV3_�R���x�A���[�^���]=OFF
	
	���R���x�A����ErrStep=1

else if (ldp(tim_XSW85_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW85_���t�^�X�g�b�p���~�[.B)) and not(pnlPBXSW85_���t�^�X�g�b�p���~�[) then
	almXSW85_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW85_���t�^�X�g�b�p���~�[=ON
	if tim_XSW85_���t�^�X�g�b�p���~�[ then
		res(tim_XSW85_���t�^�X�g�b�p���~�[)
	end if
	���R���x�A����ErrStep=1

else if (ldp(tim_XSW90_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW90_���t�^�X�g�b�p���~�[.B)) and not(pnlPBXSW90_���t�^�X�g�b�p���~�[) then
	almXSW90_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW90_���t�^�X�g�b�p���~�[=ON
	if tim_XSW90_���t�^�X�g�b�p���~�[ then
		res(tim_XSW90_���t�^�X�g�b�p���~�[)
	end if
	���R���x�A����ErrStep=1

else if (ldp(tim_XSW95_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW95_���t�^�X�g�b�p���~�[.B)) and not(pnlPBXSW95_���t�^�X�g�b�p���~�[) then
	almXSW95_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW95_���t�^�X�g�b�p���~�[=ON
	if tim_XSW95_���t�^�X�g�b�p���~�[ then
		res(tim_XSW95_���t�^�X�g�b�p���~�[)
	end if
	���R���x�A����ErrStep=1

else if (ldp(tim_XSW100_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW100_���t�^�X�g�b�p���~�[.B)) and not(pnlPBXSW100_���t�^�X�g�b�p���~�[) then
	almXSW100_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW100_���t�^�X�g�b�p���~�[=ON
	if tim_XSW100_���t�^�X�g�b�p���~�[ then
		res(tim_XSW100_���t�^�X�g�b�p���~�[)
	end if
	���R���x�A����ErrStep=1

else if (ldp(tim_XSW105_���t�^�X�g�b�p���~�[.B) or ldp(tim_notXSW105_���t�^�X�g�b�p���~�[.B)) and not(pnlPBXSW105_���t�^�X�g�b�p���~�[) then
	almXSW105_���t�^�X�g�b�p���~�[=ON
	pnlPBXSW105_���t�^�X�g�b�p���~�[=ON
	if tim_XSW105_���t�^�X�g�b�p���~�[ then
		res(tim_XSW105_���t�^�X�g�b�p���~�[)
	end if
	���R���x�A����ErrStep=1

end if
'===================================================================================================================
'�y �t�^�����oLS�f�B���[�z
'tmr(LS11_���t�^���m,timdly_LS11_���t�^���m,2)
'tmr(LS12_���t�^���m,timdly_LS12_���t�^���m,2)
'tmr(LS13_���t�^���m,timdly_LS13_���t�^���m,2)
'tmr(LS14_���t�^���m,timdly_LS14_���t�^���m,2)
'tmr(LS15_���t�^���m,timdly_LS15_���t�^���m,2)

TMR(PH7_�����m,timdly_PH7_�����m,4)
TMR(PH8_�t�^���m,timdly_PH8_�t�^���m,4)

TMR(PH45_�����m,timdly_PH45_�����m,4)
TMR(PH46_�t�^���m,timdly_PH46_�t�^���m,4)

	
if ���R���x�A����AutoRun  then	
	if not(��򃆃j�b�g1�֎~) and (MC35_���|���vA and INV10_���|���vA�^�] and  getEDC1_PV>=(setEDC1_SV-5) ) then
		�z�ď��������J�E���g�\=ON
	else if not(��򃆃j�b�g2�֎~) and (MC36_���|���vB and INV11_���|���vB�^�] and  getEDC2_PV>=(setEDC2_SV-5) ) then
		�z�ď��������J�E���g�\=ON
	else if not(��򃆃j�b�g3�֎~) and (MC37_���|���vC and INV12_���|���vC�^�] and  getEDC3_PV>=(setEDC3_SV-5) ) then
		�z�ď��������J�E���g�\=ON
	else if not(��򃆃j�b�g4�֎~) and (MC38_���|���vD and INV13_���|���vD�^�] and  getEDC4_PV>=(setEDC4_SV-5) ) then
		�z�ď��������J�E���g�\=ON
	else if not(��򃆃j�b�g5�֎~) and (MC39_���|���vE and INV14_���|���vE�^�] and  getEDC5_PV>=(setEDC5_SV-5) ) then
		�z�ď��������J�E���g�\=ON	
	end if
else
	�z�ď��������J�E���g�\=OFF
end if


if not(�z�ď��������J�E���g�\) then
	IND_��򏀔���=ON
else
	IND_��򏀔���=OFF
end if



'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���R���x�A����AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���R���x�A����AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���R���x�A����Emg	���̏��~


if not(���R���x�A����Emg) then  
	
	if ���R���x�A����ErrStep=0  then

	if not(���R���x�A����OrgErr) then

	if �����T�C�N��flg or (���R���x�A����AutoMode and ��������AutoMode ) or ���R���x�A����step<>0 then
	
		if not(���R���x�A����AutoMode and ��������AutoMode ) then
			���R���x�A����AutoRun=OFF
		end if

		if ManualInite=1 then
			PBL44_�R���x�A=OFF
		
			mSV71_���t�^�X�g�b�p=ON
			mSV77_���t�^�X�g�b�p=ON
			mSV83_���t�^�X�g�b�p=ON
			mSV89_���t�^�X�g�b�p=ON
			mSV95_���t�^�X�g�b�p=ON

			mINV1_�R���x�A���[�^���]=OFF
			mINV2_�R���x�A���[�^���]=OFF
			ejectINV3_�R���x�A���[�^���]=OFF
			
			manual���R���x�A=OFF
			tmp1INV1_�R���x�A���[�^���]=OFF
			tmp1INV2_�R���x�A���[�^���]=OFF
			tmp1INV3_�R���x�A���[�^���]=OFF
			tmp2INV1_�R���x�A���[�^���]=OFF
			tmp2INV2_�R���x�A���[�^���]=OFF
			tmp2INV3_�R���x�A���[�^���]=OFF
	
			ManualInite=0
		end if

	'------------------------------------------------------------------------------------------------
	'INV1_�R���x�A���[�^���]
	tmr(tim_INV1_�R���x�A���[�^���],tim_INV1_�R���x�A���[�^���]_val)
	
	select case INV1_�R���x�A���[�^���]step
	
	case 0
	
	case 1
		PH45_���N�����m=timdly_PH45_�����m
		PH46_�t�^�N�����m=timdly_PH46_�t�^���m		

		if PH45_���N�����m or PH46_�t�^�N�����m then

			if PH45_���N�����m or PH46_�t�^�N�����m then			
				if PH45_���N�����m and PH46_�t�^�N�����m then
					shiftreg���t�^����0=$80

					if �z�ď��������J�E���g�\ and ���ы@�_�Ύ��s�m�F�y�ρz then
						if �z�ď����������ݒl<�z�ď��������ݒ�l then
							inc(�z�ď����������ݒl)
						end if
					end if			


					if DM_EndCnt>0 then
						dec(DM_EndCnt)
					end if
										
					
				else if not(PH45_���N�����m) and PH46_�t�^�N�����m then
					shiftreg���t�^����0=$40			
				end if
			else
				shiftreg���t�^����0=$0
			end if


			inc(INV1_�R���x�A���[�^���]step)
		else
			INV1_�R���x�A���[�^���]step=0
			�����������r�o�v��=OFF
		end if

	case 2
		setS05c1=6000
		setS08c1=10
		setS09c1=10
		mINV1_�R���x�A���[�^���]=ON
		inc(INV1_�R���x�A���[�^���]step)
	
	case 3
		if not(PH45_�����m) and not(PH46_�t�^���m) then
			'if not(LS11_���t�^���m) then
				inc(INV1_�R���x�A���[�^���]step)
			'end if
		end if


	case 4
		'if LS11_���t�^���m then
			tim_INV1_�R���x�A���[�^���]_val=70 '���[�^��~�^�C�~���O
			res(tim_INV1_�R���x�A���[�^���])
			inc(INV1_�R���x�A���[�^���]step)
		'end if
	
	case 5
		if tim_INV1_�R���x�A���[�^���].B then
			inc(INV1_�R���x�A���[�^���]step)
		end if
		
	case 6
		mINV1_�R���x�A���[�^���]=OFF
		inc(INV1_�R���x�A���[�^���]step)
	
	case 7
		�����������r�o�v��=OFF
		INV1_�R���x�A���[�^���]step=0

	end select
	'------------------------------------------------------------------------------------------------
	'INV2_�R���x�A���[�^���]
	tmr(tim_INV2_�R���x�A���[�^���],tim_INV2_�R���x�A���[�^���]_val)
	
	select case INV2_�R���x�A���[�^���]step
	
	case 0
	
	case 1
		tim_INV2_�R���x�A���[�^���]_val=INV2�N���҂����� '1���@(0) 2���@(10)
		res(tim_INV2_�R���x�A���[�^���])
		inc(INV2_�R���x�A���[�^���]step)
		
	case 2
		if tim_INV2_�R���x�A���[�^���].B then
			inc(INV2_�R���x�A���[�^���]step)
		end if		
	
	case 3
		inc(INV2_�R���x�A���[�^���]step)

	case 4
		setS05c2=6000
		setS08c2=10 '<- ���R���x�A�������W���[�� 22/1/13 20����10�ɕύX 
		setS09c2=20 '<-��~����
		mINV2_�R���x�A���[�^���]=ON

		inc(INV2_�R���x�A���[�^���]step)
	
	case 5
		'if tim_INV2_�R���x�A���[�^���].B or (not(LS11_���t�^���m) and not(LS12_���t�^���m) and not(LS13_���t�^���m) and not(LS14_���t�^���m) and not(LS15_���t�^���m) )then
			inc(INV2_�R���x�A���[�^���]step)
		'end if
	

	
	case 6
		tim_INV2_�R���x�A���[�^���]_val=�X�g�b�p�[�㏸�^�C�~���O
		res(tim_INV2_�R���x�A���[�^���])
		inc(INV2_�R���x�A���[�^���]step)

	case 7
		if tim_INV2_�R���x�A���[�^���].B then
			mSV71_���t�^�X�g�b�p=ON	'�X�g�b�p�[�㏸
			mSV77_���t�^�X�g�b�p=ON
			mSV83_���t�^�X�g�b�p=ON
			mSV89_���t�^�X�g�b�p=ON
			mSV95_���t�^�X�g�b�p=ON

			tim_INV2_�R���x�A���[�^���]_val=120 '������~����
			res(tim_INV2_�R���x�A���[�^���])
			inc(INV2_�R���x�A���[�^���]step)
		end if
	

	case 8	
		'if (LS12_���t�^���m and timdly_LS12_���t�^���m) or (LS13_���t�^���m and timdly_LS13_���t�^���m) or (LS14_���t�^���m and timdly_LS14_���t�^���m) or (LS15_���t�^���m and timdly_LS15_���t�^���m) or tim_INV2_�R���x�A���[�^���].B then
			tim_INV2_�R���x�A���[�^���]_val=INV2�u���[�L�^�C�~���O '1���@(28) 2���@(24)
			res(tim_INV2_�R���x�A���[�^���])
			inc(INV2_�R���x�A���[�^���]step)
		'end if
		
	case 9
		if tim_INV2_�R���x�A���[�^���].B then
			inc(INV2_�R���x�A���[�^���]step)
		end if
	
	case 10
		mINV2_�R���x�A���[�^���]=OFF
		inc(INV2_�R���x�A���[�^���]step)
	
	case 11
		tim_INV2_�R���x�A���[�^���]_val=15 '�I���^�C�~���O
		res(tim_INV2_�R���x�A���[�^���])
		inc(INV2_�R���x�A���[�^���]step)

	case 12
		if tim_INV2_�R���x�A���[�^���].B then
			inc(INV2_�R���x�A���[�^���]step)
		end if	
	
	case 13
		INV2_�R���x�A���[�^���]step=0

	end select
	
	'------------------------------------------------------------------------------------------------
	'INV3_�R���x�A���[�^���]
	tmr(tim_INV3_�R���x�A���[�^���],tim_INV3_�R���x�A���[�^���]_val)
	
	select case INV3_�R���x�A���[�^���]step
	
	case 0
	
	case 1
		if PH7_�����m or PH8_�t�^���m then
			INV3_�R���x�A���[�^���]step=0
		else
			inc(INV3_�R���x�A���[�^���]step)	
		end if
	
	case 2
		setS05c3=6000
		setS08c3=5
		setS09c3=5
		ejectINV3_�R���x�A���[�^���]=ON
		
		
		StageDevice36=shiftreg���t�^����5 'StageDevice37 , ��:$80  �t�^:$40


		LatchPH7_�����m=OFF
		LatchPH8_�t�^���m=OFF
		
		inc(INV3_�R���x�A���[�^���]step)

	case 3
		if not(PH7_�����m) and not(PH8_�t�^���m) then
				tim_INV3_�R���x�A���[�^���]_val=120 '���[�^��~�^�C�~���O
				res(tim_INV3_�R���x�A���[�^���])
				inc(INV3_�R���x�A���[�^���]step)
		end if

	case 4
		if (PH7_�����m and timdly_PH7_�����m) or (PH8_�t�^���m and timdly_PH8_�t�^���m) or tim_INV3_�R���x�A���[�^���].B then
		
			if SEL2_1_�^�]�؊��i�P���j and tim_INV3_�R���x�A���[�^���].B then
				StageDevice36=0
			end if
			
			inc(INV3_�R���x�A���[�^���]step)
		end if
		
	case 5
		ejectINV3_�R���x�A���[�^���]=OFF
		inc(INV3_�R���x�A���[�^���]step)
	
	case 6
		if PH7_�����m or PH8_�t�^���m then
			���R���x�A�����r�o�v��=ON
		else
			���R���x�A�����r�o�v��=OFF
		end if		
	
		
		INV3_�R���x�A���[�^���]step=0
	
	end select
	'------------------------------------------------------------------------------------------------


	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ���R���x�A����step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ���R���x�A����AutoRun or �����T�C�N��flg then
				inc(���R���x�A����step)
			else 
				���R���x�A����step=0 '�I���ҋ@
			end if

		
		case 2
			if PH7_�����m or PH8_�t�^���m then
				StageDevice36=shiftreg���t�^����6
				���R���x�A�����r�o�v��=ON
				���R���x�A����step=1
			else
				inc(���R���x�A����step)
			end if
							

		case 3
		
		' [ ���̔����R���x�A��~�m�F ]
			if (���R���x�A�����r�o�v��=OFF or �����T�C�N��flg) and  ���o���������쒆=OFF and  (�����������r�o�v�� or �����T�C�N��flg)  and ��򃆃j�b�gOrg then
				inc(���R���x�A����step)
			else
				���R���x�A����step=1
			end if
		
		case 4
			if ��򊮗� then
				inc(���R���x�A����step)
			else
				���R���x�A����step=1
			end if
		
		case 5
			'�������V�����_�[�㏸�[�m�F
			inc(���R���x�A����step)
		
		case 6
			inc(���R���x�A����step)
			
		case 7
			���R���x�A�������쒆=ON
			���R���x�A����step=100			
		'--------------------------------------------------------------------------------------------------------------
		case 100			
			mSV71_���t�^�X�g�b�p=OFF	'�X�g�b�p�[���~
			mSV77_���t�^�X�g�b�p=OFF
			mSV83_���t�^�X�g�b�p=OFF
			mSV89_���t�^�X�g�b�p=OFF
			mSV95_���t�^�X�g�b�p=OFF
			
			inc(���R���x�A����step)
		
		case 101
			'�X�g�b�p���~�[�m�F
			if (XSW85_���t�^�X�g�b�p���~�[ and not(pnlPBXSW85_���t�^�X�g�b�p���~�[)) or passXSW85_���t�^�X�g�b�p���~�[ then
				if (XSW90_���t�^�X�g�b�p���~�[ and not(pnlPBXSW90_���t�^�X�g�b�p���~�[)) or passXSW90_���t�^�X�g�b�p���~�[ then
					if (XSW95_���t�^�X�g�b�p���~�[ and not(pnlPBXSW95_���t�^�X�g�b�p���~�[)) or passXSW95_���t�^�X�g�b�p���~�[ then
						if (XSW100_���t�^�X�g�b�p���~�[ and not(pnlPBXSW100_���t�^�X�g�b�p���~�[)) or passXSW100_���t�^�X�g�b�p���~�[ then
							if (XSW105_���t�^�X�g�b�p���~�[ and not(pnlPBXSW105_���t�^�X�g�b�p���~�[)) or passXSW105_���t�^�X�g�b�p���~�[ then
								inc(���R���x�A����step)
							end if
						end if
					end if
				end if
			end if

		case 102
			tim_procstep_val=10 '�������t�^�����o���ԑ҂�
			res(tim_procstep)
			inc(���R���x�A����step)

		case 103
			if tim_procstep.B then			
				inc(���R���x�A����step)
			end if

		case 104

			INV1_�R���x�A���[�^���]step=1			
			INV2_�R���x�A���[�^���]step=1
			INV3_�R���x�A���[�^���]step=1
			
			inc(���R���x�A����step)
		
		case 105
			if INV1_�R���x�A���[�^���]step=0 and  INV2_�R���x�A���[�^���]step=0 and INV3_�R���x�A���[�^���]step=0 then
				inc(���R���x�A����step)
			end if
		

		case 106
			��򊮗�=OFF
			�����������r�o�v��=OFF
			���R���x�A�������쒆=OFF
			
					
			shiftreg���t�^����8	=	shiftreg���t�^����7
			shiftreg���t�^����7	=	shiftreg���t�^����6
			shiftreg���t�^����6	=	shiftreg���t�^����5
			shiftreg���t�^����5	=	shiftreg���t�^����4
			shiftreg���t�^����4	=	shiftreg���t�^����3
			shiftreg���t�^����3	=	shiftreg���t�^����2
			shiftreg���t�^����2	=	shiftreg���t�^����1
			shiftreg���t�^����1	=	shiftreg���t�^����0
			shiftreg���t�^����0 = 0

			inc(���R���x�A����step)

		case 107
			tim_procstep_val=30
			res(tim_procstep)
			inc(���R���x�A����step)

		case 108
			if tim_procstep.B then			
				inc(���R���x�A����step)
			end if
		
		case 109
			�����T�C�N��flg=OFF

			���R���x�A����step=1

		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else
		if ManualInite=0 and �����T�C�N��flg=OFF then
			PBL44_�R���x�A=OFF
		
			mSV71_���t�^�X�g�b�p=OFF
			mSV77_���t�^�X�g�b�p=OFF
			mSV83_���t�^�X�g�b�p=OFF
			mSV89_���t�^�X�g�b�p=OFF
			mSV95_���t�^�X�g�b�p=OFF

			mINV1_�R���x�A���[�^���]=OFF
			mINV2_�R���x�A���[�^���]=OFF
			ejectINV3_�R���x�A���[�^���]=OFF
			
			manual���R���x�A=OFF
			tmp1INV1_�R���x�A���[�^���]=OFF
			tmp1INV2_�R���x�A���[�^���]=OFF
			tmp1INV3_�R���x�A���[�^���]=OFF
			tmp2INV1_�R���x�A���[�^���]=OFF
			tmp2INV2_�R���x�A���[�^���]=OFF
			tmp2INV3_�R���x�A���[�^���]=OFF
			
			ManualInite=1
		end if

		���R���x�A����AutoRun=OFF
		���R���x�A����step=0 '�I��
		

		'---------------------------------------------------------------------
		'���t�^�X�g�b�p���~�[���o
		'---------------------------------------------------------------------
		if (not(XSW85_���t�^�X�g�b�p���~�[) or pnlPBXSW85_���t�^�X�g�b�p���~�[) and (not(XSW90_���t�^�X�g�b�p���~�[) or pnlPBXSW90_���t�^�X�g�b�p���~�[) then
			if  (not(XSW95_���t�^�X�g�b�p���~�[) or pnlPBXSW95_���t�^�X�g�b�p���~�[) and (not(XSW100_���t�^�X�g�b�p���~�[) or pnlPBXSW100_���t�^�X�g�b�p���~�[) then
				if (not(XSW105_���t�^�X�g�b�p���~�[) or pnlPBXSW105_���t�^�X�g�b�p���~�[) then
					���t�^�X�g�b�p���~�[=ON
				else
					���t�^�X�g�b�p���~�[=OFF
				end if
			else
				���t�^�X�g�b�p���~�[=OFF
			end if
		else
			���t�^�X�g�b�p���~�[=OFF
		end if

		'---------------------------------------------------------------------
		' ���R���x�A �}�j���A���^�]
		'---------------------------------------------------------------------
		PBL44_�R���x�A=mINV1_�R���x�A���[�^���] or mINV2_�R���x�A���[�^���] or ejectINV3_�R���x�A���[�^���]
		
		mINV1_�R���x�A���[�^���]=tmp1INV1_�R���x�A���[�^���] or tmp2INV1_�R���x�A���[�^���]
		mINV2_�R���x�A���[�^���]=tmp1INV2_�R���x�A���[�^���] or tmp2INV2_�R���x�A���[�^���]
		ejectINV3_�R���x�A���[�^���]=tmp1INV3_�R���x�A���[�^���] or tmp2INV3_�R���x�A���[�^���]
		
		if PB45_�S��~SW and not(timdly_PH7_�����m) and not(timdly_PH8_�t�^���m) then
			
		
		
			if SEL2_1_�^�]�؊��i�P���j then
				if ��򃆃j�b�gOrg and ���R���x�A����Org and ���o������Org then 
			
					tmp2INV1_�R���x�A���[�^���]=OFF
					tmp2INV2_�R���x�A���[�^���]=OFF
					tmp2INV3_�R���x�A���[�^���]=OFF
					
					if ldp(PB44_�R���x�ASW) then
						if manual���R���x�A then
							manual���R���x�A=OFF
						else
							manual���R���x�A=ON
						end if
					end if
					
					tmp1INV1_�R���x�A���[�^���]=manual���R���x�A
					tmp1INV2_�R���x�A���[�^���]=manual���R���x�A
					tmp1INV3_�R���x�A���[�^���]=manual���R���x�A
			  else
					if ldp(PB44_�R���x�ASW) then
						if not(��򃆃j�b�gOrg) then
							��򃆃j�b�gOrgErr=ON
						end if
						
						if not(���R���x�A����Org) then
							���R���x�A����OrgErr=ON
						end if
						
						if not(���o������Org) then
							���o������OrgErr=ON
						end if
					end if
			  end if
			else
				
					manual���R���x�A=OFF
					tmp1INV1_�R���x�A���[�^���]=OFF
					tmp1INV2_�R���x�A���[�^���]=OFF
					tmp1INV3_�R���x�A���[�^���]=OFF

					if ldp(pnlPBINV1_�R���x�A���[�^���]) then
						if tmp2INV1_�R���x�A���[�^���] then
							tmp2INV1_�R���x�A���[�^���]=OFF
						else
							tmp2INV1_�R���x�A���[�^���]=ON
						end if
					end if
							
				if ��򃆃j�b�gOrg and ���R���x�A����Org  and ���o������Org then 
					if ldp(pnlPBINV2_�R���x�A���[�^���]) then
						if tmp2INV2_�R���x�A���[�^���] then
							tmp2INV2_�R���x�A���[�^���]=OFF
						else
							tmp2INV2_�R���x�A���[�^���]=ON
						end if
					end if

					if ldp(pnlPBINV3_�R���x�A���[�^���]) then
						if tmp2INV3_�R���x�A���[�^���] then
							tmp2INV3_�R���x�A���[�^���]=OFF
						else
							tmp2INV3_�R���x�A���[�^���]=ON
						end if
					end if
				else
					if ldp(pnlPBINV2_�R���x�A���[�^���]) or ldp(pnlPBINV3_�R���x�A���[�^���]) then
						if not(��򃆃j�b�gOrg) then
							��򃆃j�b�gOrgErr=ON
						end if
						
						if not(���R���x�A����Org) then
							���R���x�A����OrgErr=ON
						end if
						
						if not(���o������Org) then
							���o������OrgErr=ON
						end if

					end if								
				end if
			end if

		else
			mINV1_�R���x�A���[�^���]=OFF
			mINV2_�R���x�A���[�^���]=OFF
			ejectINV3_�R���x�A���[�^���]=OFF
			
			manual���R���x�A=OFF
			tmp1INV1_�R���x�A���[�^���]=OFF
			tmp1INV2_�R���x�A���[�^���]=OFF
			tmp1INV3_�R���x�A���[�^���]=OFF
			tmp2INV1_�R���x�A���[�^���]=OFF
			tmp2INV2_�R���x�A���[�^���]=OFF
			tmp2INV3_�R���x�A���[�^���]=OFF
						
		end if
		'---------------------------------------------------------------------		
		'���X�g�b�p  �}�j���A���^�]		
		'---------------------------------------------------------------------		
		if not(manual���R���x�A) then
		
			if ldp(pnlPBSV71_���t�^�X�g�b�p) then
				if mSV71_���t�^�X�g�b�p then
					mSV71_���t�^�X�g�b�p=OFF
				else
					mSV71_���t�^�X�g�b�p=ON
				end if
			end if
			
			if ldp(pnlPBSV77_���t�^�X�g�b�p) then
				if mSV77_���t�^�X�g�b�p then
					mSV77_���t�^�X�g�b�p=OFF
				else
					mSV77_���t�^�X�g�b�p=ON
				end if
			end if
			
			if ldp(pnlPBSV83_���t�^�X�g�b�p) then
				if mSV83_���t�^�X�g�b�p then
					mSV83_���t�^�X�g�b�p=OFf
				else
					mSV83_���t�^�X�g�b�p=ON
				end if
			end if
			
			if ldp(pnlPBSV89_���t�^�X�g�b�p) then
				if mSV89_���t�^�X�g�b�p then
					mSV89_���t�^�X�g�b�p=OFF
				else
					mSV89_���t�^�X�g�b�p=ON
				end if
			end if
			
			if ldp(pnlPBSV95_���t�^�X�g�b�p) then
				if mSV95_���t�^�X�g�b�p then
					mSV95_���t�^�X�g�b�p=OFF
				else
					mSV95_���t�^�X�g�b�p=ON
				end if
			end if
			
			if ldp(PB25_���@�P���^�]) and (not(PH7_�����m) and not(PH8_�t�^���m))  and (not(PH9_�����m) and not(PH10_�t�^���m)) and  ��򃆃j�b�gOrg then

					�����T�C�N��flg=ON
					���R���x�A����step=1

			end if
			
		end if		
		
	end if '���R���x�A����AutoMode and not(���R���x�A����OrgErrStep)

	'===================================================================================================================
	'�y ���R���x�A����OrgErr���� �z
	else
	
		if ResetFlg then
			���R���x�A����OrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'�y�^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		���R���x�A����Err=ON


		mINV1_�R���x�A���[�^���]=OFF
		mINV2_�R���x�A���[�^���]=OFF
		ejectINV3_�R���x�A���[�^���]=OFF

		mSV71_���t�^�X�g�b�p=OFF
		mSV77_���t�^�X�g�b�p=OFF
		mSV83_���t�^�X�g�b�p=OFF
		mSV89_���t�^�X�g�b�p=OFF
		mSV95_���t�^�X�g�b�p=OFF
		
		INV1_�R���x�A���[�^���]step=0
		INV2_�R���x�A���[�^���]step=0
		INV3_�R���x�A���[�^���]step=0
		���R���x�A����step=0
		�����T�C�N��flg=OFF

		���R���x�A�������쒆=OFF

		tmr(tim_���R���x�A����ErrStep,tim_���R���x�A����ErrStep_val)
		
		select case ���R���x�A����ErrStep
		case 0
		
		'------------------------------------------------------------------
		case 1
			alm�a�،x��=ON			

			if ResetFlg then
				alm�a�،x��=OFF			
		 		inc(���R���x�A����ErrStep)
			end if
			
		case 2
			almINV1_�R���x�A���[�^���]=OFF
			almINV2_�R���x�A���[�^���]=OFF			
			almINV3_�R���x�A���[�^���]=OFF
			almXSW85_���t�^�X�g�b�p���~�[=OFF
			almXSW90_���t�^�X�g�b�p���~�[=OFF
			almXSW95_���t�^�X�g�b�p���~�[=OFF
			almXSW100_���t�^�X�g�b�p���~�[=OFF
			almXSW105_���t�^�X�g�b�p���~�[=OFF
			almLS6_�󊘔��]���]�ʒu=OFF
			almLS5_�󊘔��]���_�ʒu=OFF
			almMC10_���]���[�^���]=OFF			
			almMC10_���]���[�^�t�]=OFF

			inc(���R���x�A����ErrStep)
		case 3
			���R���x�A����Err=OFF

			res(tim_XSW85_���t�^�X�g�b�p���~�[.B)
			res(tim_XSW90_���t�^�X�g�b�p���~�[.B)
			res(tim_XSW95_���t�^�X�g�b�p���~�[.B)
			res(tim_XSW100_���t�^�X�g�b�p���~�[.B)
			res(tim_XSW105_���t�^�X�g�b�p���~�[.B)

			res(tim_notXSW85_���t�^�X�g�b�p���~�[.B)
			res(tim_notXSW90_���t�^�X�g�b�p���~�[.B)
			res(tim_notXSW95_���t�^�X�g�b�p���~�[.B)
			res(tim_notXSW100_���t�^�X�g�b�p���~�[.B)
			res(tim_notXSW105_���t�^�X�g�b�p���~�[.B)

			���R���x�A����step=0
			INV1_�R���x�A���[�^���]step=0
			INV2_�R���x�A���[�^���]step=0
			INV3_�R���x�A���[�^���]step=0

			���R���x�A����ErrStep=0
		end select

	end if 'if ���R���x�A����ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case ���R���x�A����EmgStep
	case 0
	
	case 1
		���R���x�A����AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if �����T�C�N��flg or (���R���x�A����AutoMode and ��������AutoMode ) or ���R���x�A����step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC10_���]���[�^�t�]=ON
			pauseMC10_���]���[�^���]=ON
			
			pauseINV1_�R���x�A���[�^���]=ON
			pauseINV2_�R���x�A���[�^���]=ON
			pauseINV3_�R���x�A���[�^���]=ON
			
			if timstack=OFF then
				'tmr(tim_INV1_�R���x�A���[�^���],tim_INV1_�R���x�A���[�^���]_val)
				'tmr(tim_INV2_�R���x�A���[�^���],tim_INV2_�R���x�A���[�^���]_val)
				'tmr(tim_INV3_�R���x�A���[�^���],tim_INV3_�R���x�A���[�^���]_val)
				'tmr(tim_MC10_���]���[�^���],tim_MC10_���]���[�^���]_val)
				'tmr(tim_MC10_���]���[�^�t�],tim_MC10_���]���[�^�t�]_val)
				'tmr(tim_procstep,tim_procstep_val)
				'tmr(tim_���R���x�A����ErrStep,tim_���R���x�A����ErrStep_val)

				tim_INV1_�R���x�A���[�^���]_stack=tim_INV1_�R���x�A���[�^���].U
				if mINV2_�R���x�A���[�^���] then
					tim_INV2_�R���x�A���[�^���]_stack=tim_INV2_�R���x�A���[�^���].U+20
				else
					tim_INV2_�R���x�A���[�^���]_stack=tim_INV2_�R���x�A���[�^���].U
				end if				
				tim_INV3_�R���x�A���[�^���]_stack=tim_INV3_�R���x�A���[�^���].U
				tim_procstep_stack=tim_procstep.U
				tim_���R���x�A����ErrStep_stack=tim_���R���x�A����ErrStep.U

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------			
			mINV1_�R���x�A���[�^���]=OFF
			mINV2_�R���x�A���[�^���]=OFF
			ejectINV3_�R���x�A���[�^���]=OFF

			mSV71_���t�^�X�g�b�p=OFF	'�X�g�b�p�[���~
			mSV77_���t�^�X�g�b�p=OFF
			mSV83_���t�^�X�g�b�p=OFF
			mSV89_���t�^�X�g�b�p=OFF
			mSV95_���t�^�X�g�b�p=OFF

			tmp1INV1_�R���x�A���[�^���]=OFF
			tmp1INV2_�R���x�A���[�^���]=OFF
			tmp1INV3_�R���x�A���[�^���]=OFF
			tmp2INV1_�R���x�A���[�^���]=OFF
			tmp2INV2_�R���x�A���[�^���]=OFF
			tmp2INV3_�R���x�A���[�^���]=OFF

			'---------------------------------
		end if
		
		'---------------------------------
		inc(���R���x�A����EmgStep)
	case 2
		if ResetFlg then
			inc(���R���x�A����EmgStep)
		end if
	case 3
		if �����T�C�N��flg or (���R���x�A����AutoMode and ��������AutoMode ) or ���R���x�A����step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC10_���]���[�^�t�]=OFF
				pauseMC10_���]���[�^���]=OFF
				
				pauseINV1_�R���x�A���[�^���]=OFF
				pauseINV2_�R���x�A���[�^���]=OFF
				pauseINV3_�R���x�A���[�^���]=OFF
				
				tim_INV1_�R���x�A���[�^���].U=tim_INV1_�R���x�A���[�^���]_stack
				tim_INV2_�R���x�A���[�^���].U=tim_INV2_�R���x�A���[�^���]_stack
				tim_INV3_�R���x�A���[�^���].U=tim_INV3_�R���x�A���[�^���]_stack
				tim_procstep.U=tim_procstep_stack
				tim_���R���x�A����ErrStep.U=tim_���R���x�A����ErrStep_stack

				
				'---------------------------------
				inc(���R���x�A����EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���R���x�A����EmgStep)		
		end if				
	case 4
		timstack=OFF
		���R���x�A����EmgStep=0
		���R���x�A����Emg=OFF
	end select

		
end if 'if Emgstep_proc=0 then
