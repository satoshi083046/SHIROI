'�W�킹���j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�W�킹���j�b�g
'
'
'	�t�^�킹���̃G���[���
'	�t�^�킹�ʒu�C���G���[����  -> ���g���C  ->  ���r�o  (MC15�������[�^ , MC43��ڃR���x�A) -> �t�^�u�� �� �t�^�킹�G���[����
'                    (reset sw)                                                                               (reset sw)
'                    *�t�^�C��                                                                                *��Ńt�^�킹  
'
'===================================================================================================================

'�y ���������� �z
if CR2008 then
    �W�킹���j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �W�킹���j�b�gAutoRun=OFF
    �W�킹���j�b�g����=ON
    �W�킹���j�b�gOrgErr=OFF
    �W�킹���j�b�gErr=OFF
    �W�킹���j�b�gEmg=OFF
    �W�킹���j�b�gstep=0
    �W�킹���j�b�gErrStep=0
    �W�킹���j�b�gOrgErrStep=0
    �W�킹���j�b�gEmgStep=0

end if
'===================================================================================================================
'�y ���_ �z
�W�킹���j�b�gOrg=(XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A  
�W�킹���j�b�gOrg=�W�킹���j�b�gOrg and ((XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B)
�W�킹���j�b�gOrg=�W�킹���j�b�gOrg and ((XSW111_���ʒu�E��ޒ[ and not(pnlPBXSW111_���ʒu�E��ޒ[)) or passXSW111_���ʒu�E��ޒ[)
�W�킹���j�b�gOrg=�W�킹���j�b�gOrg and ((XSW112_���ʒu����ޒ[ and not(pnlPBXSW112_���ʒu����ޒ[)) or passXSW112_���ʒu����ޒ[)
�W�킹���j�b�gOrg=�W�킹���j�b�gOrg or not(�W�킹���j�b�g����) 

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�W�킹���j�b�gEmg=ON
	�W�킹���j�b�gEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV34_�V�����_�㏸A and not(XSW39_�V�����_�㏸�[A) and not(pnlPBXSW39_�V�����_�㏸�[A),tim_notXSW39_�V�����_�㏸�[A,#50)
tmr(SV35_�V�����_���~A and not(XSW40_�V�����_���~�[A) and not(pnlPBXSW40_�V�����_���~�[A),tim_notXSW40_�V�����_���~�[A,#50)
tmr(SV36_�V�����_�㏸B and not(XSW41_�V�����_�㏸�[B) and not(pnlPBXSW41_�V�����_�㏸�[B),tim_notXSW41_�V�����_�㏸�[B,#50)
tmr(SV37_�V�����_���~B and not(XSW42_�V�����_���~�[B) and not(pnlPBXSW42_�V�����_���~�[B),tim_notXSW42_�V�����_���~�[B,#50)
tmr(SV38_�N�����v and not(XSW43_�N�����v) and not(pnlPBXSW43_�N�����v),tim_notXSW43_�N�����v,#40)
tmr(SV39_�A���N�����v and not(XSW44_�A���N�����v) and not(pnlPBXSW44_�A���N�����v),tim_notXSW44_�A���N�����v,#40)
tmr(not(SV64_���ʒu) and not(XSW111_���ʒu�E��ޒ[),tim_notXSW111_���ʒu�E��ޒ[,#10)
tmr(not(SV64_���ʒu) and not(XSW112_���ʒu����ޒ[),tim_notXSW112_���ʒu����ޒ[,#10)

if LDP(SV34_�V�����_�㏸A) and XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A) then
	SET(tim_XSW39_�V�����_�㏸�[A)
end if
if LDP(SV35_�V�����_���~A) and XSW40_�V�����_���~�[A and not(pnlPBXSW40_�V�����_���~�[A) then
	SET(tim_XSW40_�V�����_���~�[A)
end if
if LDP(SV36_�V�����_�㏸B) and XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B) then
	SET(tim_XSW41_�V�����_�㏸�[B)
end if
if LDP(SV37_�V�����_���~B) and XSW42_�V�����_���~�[B and not(pnlPBXSW42_�V�����_���~�[B) then
	SET(tim_XSW42_�V�����_���~�[B)
end if
if LDP(SV38_�N�����v) and XSW43_�N�����v and XSW44_�A���N�����v and not(pnlPBXSW43_�N�����v) then
	SET(tim_XSW43_�N�����v)
end if
if LDP(SV39_�A���N�����v) and XSW43_�N�����v and XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v) then
	SET(tim_XSW44_�A���N�����v)
end if
if LDF(SV64_���ʒu) and XSW111_���ʒu�E��ޒ[ and not(pnlPBXSW111_���ʒu�E��ޒ[) then
	SET(tim_XSW111_���ʒu�E��ޒ[)
end if
if LDF(SV64_���ʒu) and XSW112_���ʒu����ޒ[ and not(pnlPBXSW112_���ʒu����ޒ[) then
	SET(tim_XSW112_���ʒu����ޒ[)
end if


if SV34_�V�����_�㏸A then
	KeepSV34_�V�����_�㏸A=ON
	KeepSV35_�V�����_���~A=OFF
else if SV35_�V�����_���~A then
	KeepSV34_�V�����_�㏸A=OFF
	KeepSV35_�V�����_���~A=ON
end if
if SV36_�V�����_�㏸B then
	KeepSV36_�V�����_�㏸B=ON
	KeepSV37_�V�����_���~B=OFF
else if SV37_�V�����_���~B then
	KeepSV36_�V�����_�㏸B=OFF
	KeepSV37_�V�����_���~B=ON
end if
if SV38_�N�����v then
	KeepSV38_�N�����v=ON
	KeepSV39_�A���N�����v=OFF
else if SV39_�A���N�����v then
	KeepSV38_�N�����v=OFF
	KeepSV39_�A���N�����v=ON
end if

'passtimXSW39_�V�����_�㏸�[A_val=#3000
tms(KeepSV34_�V�����_�㏸A,passtimXSW39_�V�����_�㏸�[A,passtimXSW39_�V�����_�㏸�[A_val)
'passtimXSW40_�V�����_���~�[A_val=#3000
tms(KeepSV35_�V�����_���~A,passtimXSW40_�V�����_���~�[A,passtimXSW40_�V�����_���~�[A_val)
'passtimXSW41_�V�����_�㏸�[B_val=#3000
tms(KeepSV36_�V�����_�㏸B,passtimXSW41_�V�����_�㏸�[B,passtimXSW41_�V�����_�㏸�[B_val)
'passtimXSW42_�V�����_���~�[B_val=#3000
tms(KeepSV37_�V�����_���~B,passtimXSW42_�V�����_���~�[B,passtimXSW42_�V�����_���~�[B_val)
'passtimXSW43_�N�����v_val=#500
tms(KeepSV38_�N�����v,passtimXSW43_�N�����v,passtimXSW43_�N�����v_val)
'passtimXSW44_�A���N�����v_val=#500
tms(KeepSV39_�A���N�����v,passtimXSW44_�A���N�����v,passtimXSW44_�A���N�����v_val)

'passtimXSW111_���ʒu�E��ޒ[_val=#500
tms(not(SV64_���ʒu),passtimXSW111_���ʒu�E��ޒ[,passtimXSW111_���ʒu�E��ޒ[_val)
'passtimXSW112_���ʒu����ޒ[_val=#500
tms(not(SV64_���ʒu),passtimXSW112_���ʒu����ޒ[,passtimXSW112_���ʒu����ޒ[_val)

if �W�킹���j�b�g���� then

	if (ldp(tim_XSW39_�V�����_�㏸�[A.B) or ldp(tim_notXSW39_�V�����_�㏸�[A.B)) and not(pnlPBXSW39_�V�����_�㏸�[A)  then
		almXSW39_�V�����_�㏸�[A=ON
		pnlPBXSW39_�V�����_�㏸�[A=ON
		res(tim_XSW39_�V�����_�㏸�[A)
		�W�킹���j�b�gErrStep=1

	else if (ldp(tim_XSW40_�V�����_���~�[A.B) or ldp(tim_notXSW40_�V�����_���~�[A.B)) and not(pnlPBXSW40_�V�����_���~�[A)  then
		if �t�^�킹�t�^��蒆 then
			errXSW40_�V�����_���~�[A=ON '�t�^�킹�G���[�ʒm
			almXSW40_�V�����_���~�[A=ON
			pnlPBXSW40_�V�����_���~�[A=ON
			res(tim_XSW40_�V�����_���~�[A)
			�W�킹���j�b�gErrStep=1
		else
			almXSW40_�V�����_���~�[A=ON
			pnlPBXSW40_�V�����_���~�[A=ON
			res(tim_XSW40_�V�����_���~�[A)			
			�W�킹���j�b�gErrStep=1
		end if

	else if (ldp(tim_XSW41_�V�����_�㏸�[B.B) or ldp(tim_notXSW41_�V�����_�㏸�[B.B)) and not(pnlPBXSW41_�V�����_�㏸�[B) then
		almXSW41_�V�����_�㏸�[B=ON
		pnlPBXSW41_�V�����_�㏸�[B=ON
		if tim_XSW41_�V�����_�㏸�[B then
			res(tim_XSW41_�V�����_�㏸�[B)
		end if
		�W�킹���j�b�gErrStep=1
		
	else if (ldp(tim_XSW42_�V�����_���~�[B.B) or ldp(tim_notXSW42_�V�����_���~�[B.B)) and not(pnlPBXSW42_�V�����_���~�[B) then
		almXSW42_�V�����_���~�[B=ON
		pnlPBXSW42_�V�����_���~�[B=ON
		if tim_XSW42_�V�����_���~�[B then
			res(tim_XSW42_�V�����_���~�[B)
		end if
		�W�킹���j�b�gErrStep=1
		
	else if (ldp(tim_XSW43_�N�����v.B) or ldp(tim_notXSW43_�N�����v.B)) and not(pnlPBXSW43_�N�����v) then
		almXSW43_�N�����v=ON
		pnlPBXSW43_�N�����v=ON
		pnlPBXSW44_�A���N�����v=ON
		if tim_XSW43_�N�����v then
			res(tim_XSW43_�N�����v)
		end if
		�W�킹���j�b�gErrStep=1

	else if (ldp(tim_XSW44_�A���N�����v.B) or ldp(tim_notXSW44_�A���N�����v.B)) and not(pnlPBXSW44_�A���N�����v) then
		almXSW44_�A���N�����v=ON
		pnlPBXSW43_�N�����v=ON
		pnlPBXSW44_�A���N�����v=ON
		if tim_XSW44_�A���N�����v then
			res(tim_XSW44_�A���N�����v)
		end if
		�W�킹���j�b�gErrStep=1

	else if (ldp(tim_XSW111_���ʒu�E��ޒ[) or ldp(tim_notXSW111_���ʒu�E��ޒ[)) and not(pnlPBXSW111_���ʒu�E��ޒ[) then
		almXSW111_���ʒu�E��ޒ[=ON
		pnlPBXSW111_���ʒu�E��ޒ[=ON
		if tim_XSW111_���ʒu�E��ޒ[ then
			res(tim_XSW111_���ʒu�E��ޒ[)
		end if
		�W�킹���j�b�gErrStep=1
	
	else if (ldp(tim_XSW112_���ʒu����ޒ[) or ldp(tim_notXSW112_���ʒu����ޒ[)) and not(pnlPBXSW112_���ʒu����ޒ[) then
		almXSW112_���ʒu����ޒ[=ON
		pnlPBXSW112_���ʒu����ޒ[=ON
		if tim_XSW112_���ʒu����ޒ[ then
			res(tim_XSW112_���ʒu����ޒ[)
		end if
		�W�킹���j�b�gErrStep=1

	end if
	
	
else
	res(tim_notXSW31_�X�g�b�p���~�[)
	res(tim_notXSW32_�X�g�b�p�㏸�[)
	res(tim_notXSW35_�N�����v���~�[)
	res(tim_notXSW36_�N�����v�㏸�[)
	
	res(tim_notXSW39_�V�����_�㏸�[A)
	res(tim_notXSW40_�V�����_���~�[A)
	res(tim_notXSW41_�V�����_�㏸�[B)
	res(tim_notXSW42_�V�����_���~�[B)
	res(tim_notXSW43_�N�����v)
	res(tim_notXSW44_�A���N�����v)
	res(tim_notXSW111_���ʒu�E��ޒ[)
	res(tim_notXSW112_���ʒu����ޒ[)
	

	res(tim_XSW31_�X�g�b�p���~�[)
	res(tim_XSW32_�X�g�b�p�㏸�[)
	res(tim_XSW35_�N�����v���~�[)
	res(tim_XSW36_�N�����v�㏸�[)

	res(tim_XSW39_�V�����_�㏸�[A)
	res(tim_XSW40_�V�����_���~�[A)
	res(tim_XSW41_�V�����_�㏸�[B)
	res(tim_XSW42_�V�����_���~�[B)
	res(tim_XSW43_�N�����v)
	res(tim_XSW44_�A���N�����v)
	res(tim_XSW111_���ʒu�E��ޒ[)
	res(tim_XSW112_���ʒu����ޒ[)

end if


tmr(not(SV32_�N�����v) and not(XSW35_�N�����v���~�[) and not(pnlPBXSW35_�N�����v���~�[), tim_notXSW35_�N�����v���~�[, #30)
tmr(SV32_�N�����v and not(XSW36_�N�����v�㏸�[) and not(pnlPBXSW36_�N�����v�㏸�[), tim_notXSW36_�N�����v�㏸�[,#30)
tmr(not(SV30_�X�g�b�p) and not(XSW31_�X�g�b�p���~�[) and not(pnlPBXSW31_�X�g�b�p���~�[),tim_notXSW31_�X�g�b�p���~�[,#30)
tmr(SV30_�X�g�b�p and not(XSW32_�X�g�b�p�㏸�[) and not(pnlPBXSW32_�X�g�b�p�㏸�[),tim_notXSW32_�X�g�b�p�㏸�[,#30)

if LDF(SV32_�N�����v) and  XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[) then
	SET(tim_XSW35_�N�����v���~�[)
end if
if LDP(SV32_�N�����v) and XSW36_�N�����v�㏸�[ and not(pnlPBXSW36_�N�����v�㏸�[) then
	SET(tim_XSW36_�N�����v�㏸�[)
end if
if LDF(SV30_�X�g�b�p) and XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[) then
	SET(tim_XSW31_�X�g�b�p���~�[)
end if
if LDP(SV30_�X�g�b�p) and XSW32_�X�g�b�p�㏸�[ and not(pnlPBXSW32_�X�g�b�p�㏸�[) then
	SET(tim_XSW32_�X�g�b�p�㏸�[)
end if

if not(�����R���x�AC���쒆) and (ldp(tim_XSW35_�N�����v���~�[.B) or ldp(tim_notXSW35_�N�����v���~�[.B)) and not(pnlPBXSW35_�N�����v���~�[) then
	almXSW35_�N�����v���~�[=ON
	pnlPBXSW35_�N�����v���~�[=ON
	res(tim_XSW35_�N�����v���~�[)
	�W�킹���j�b�gErrStep=1

else if not(�����R���x�AC���쒆) and (ldp(tim_XSW36_�N�����v�㏸�[.B) or ldp(tim_notXSW36_�N�����v�㏸�[.B)) and not(pnlPBXSW36_�N�����v�㏸�[) then
	pauseSV32_�N�����v=ON
	almXSW36_�N�����v�㏸�[=ON
	pnlPBXSW36_�N�����v�㏸�[=ON
	res(tim_XSW36_�N�����v�㏸�[)
	�W�킹���j�b�gErrStep=1

else if not(�����R���x�AC���쒆) and (ldp(tim_XSW31_�X�g�b�p���~�[.B) or ldp(tim_notXSW31_�X�g�b�p���~�[.B)) and not(pnlPBXSW31_�X�g�b�p���~�[) then
	almXSW31_�X�g�b�p���~�[=ON
	pnlPBXSW31_�X�g�b�p���~�[=ON
	res(tim_XSW31_�X�g�b�p���~�[)
	�W�킹���j�b�gErrStep=1

else if not(�����R���x�AC���쒆) and (ldp(tim_XSW32_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW32_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW32_�X�g�b�p�㏸�[) then
	pauseSV30_�X�g�b�p=ON
	almXSW32_�X�g�b�p�㏸�[=ON
	pnlPBXSW32_�X�g�b�p�㏸�[=ON
	res(tim_XSW32_�X�g�b�p�㏸�[)
	�W�킹���j�b�gErrStep=1

end if
'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �W�킹���j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �W�킹���j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �W�킹���j�b�gEmg	���̏��~

if �W�킹���j�b�gEmgStep=0 then  
	
	if �W�킹���j�b�gErrStep=0  or errXSW40_�V�����_���~�[A then
	
	if not(�W�킹���j�b�gOrgErr) then

	if (�W�킹���j�b�gAutoMode and ��������AutoMode ) or �W�킹���j�b�gstep<>0 then
		
		if not(�W�킹���j�b�gAutoMode and ��������AutoMode ) then
			�W�킹���j�b�gAutoRun=OFF
		end if
		
	'--------------------------------------------
	'MC15_�������[�^
	tmr(tim_MC15_�������[�^,tim_MC15_�������[�^_val)
	
	select case MC15_�������[�^step
	case 0
	
	case 1
		mSV30_�X�g�b�p=OFF
		mSV32_�N�����v=OFF
		inc(MC15_�������[�^step)
		
	case 2
		PH19_���N�����m=PH19_�����m
		PH20_�t�^�N�����m=PH20_�t�^���m
		'PH54_������g���K

		if PH19_�����m or PH20_�t�^���m then
			if ((XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[)) or passXSW31_�X�g�b�p���~�[) and ((XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[)) or passXSW35_�N�����v���~�[) then
				mMC15_�������[�^=ON
				inc(MC15_�������[�^step)
			end if
		else
			MC15_�������[�^step=0
		end if
		
	case 3
		if not(PH19_�����m) and not(PH20_�t�^���m) then
			inc(MC15_�������[�^step)	
		end if
	
	case 4
		if PH19_���N�����m or PH20_�t�^�N�����m then
			if PH54_������g���K then
				inc(MC15_�������[�^step)
			end if
		end if
		
	case 5
		tim_MC15_�������[�^_val=10 '�u���[�N�^�C�~���O
		res(tim_MC15_�������[�^)
		inc(MC15_�������[�^step)
	
	case 6
		if tim_MC15_�������[�^.B then 
			inc(MC15_�������[�^step)
		end if
	
	case 7
		mMC15_�������[�^=OFF
		inc(MC15_�������[�^step)
		
	case 8
		tim_MC15_�������[�^_val=0
		res(tim_MC15_�������[�^)
		inc(MC15_�������[�^step)
	
	case 9
		if tim_MC15_�������[�^.B then 
			inc(MC15_�������[�^step)
		end if
	
	case 10
		MC15_�������[�^step=0
		
	end select
		
	'--------------------------------------------
	' ��芷���R���x�A PH58 PH54+tim
	tmr(tim_MC43_��ڃR���x�A,tim_MC43_��ڃR���x�A_val)
	
	select case MC43_��ڃR���x�Astep
	case 0

	case 1
		if  PH19_�����m  then
			inc(MC43_��ڃR���x�Astep)
		else
			MC43_��ڃR���x�Astep=0
		end if
		
	case 2
		mMC43_��ڃR���x�A=ON
		inc(MC43_��ڃR���x�Astep)

	case 3
		if not(PH19_�����m) then 
			inc(MC43_��ڃR���x�Astep)
		end if
	
	case 4
		if PH54_������g���K then
			inc(MC43_��ڃR���x�Astep)
		end if			
	
	case 5
		tim_MC43_��ڃR���x�A_val=10 '��~�^�C�~���O�^�C�}�[
		res(tim_MC43_��ڃR���x�A)
		inc(MC43_��ڃR���x�Astep)
	
	case 6
		if tim_MC43_��ڃR���x�A.B then
			inc(MC43_��ڃR���x�Astep)		
		end if
	
	case 7
		mMC43_��ڃR���x�A=OFF
		inc(MC43_��ڃR���x�Astep)		
	
	case 8
		MC43_��ڃR���x�Astep=0
	
	end select



	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �W�킹���j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
			�W�킹���j�b�gStatusMsg=#0

		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �W�킹���j�b�gAutoRun then
				if �t�^�킹�t�^��蒆 then
					�W�킹���j�b�gStatusMsg=#41	'	�t�^�킹�ҋ@���i�t�^�������Ă����ԁj
				else
					�W�킹���j�b�gStatusMsg=#43	'	�ҋ@���i�t�^�������Ă��Ȃ��j
				end if
				
				inc(�W�킹���j�b�gstep)
			else 
				�W�킹���j�b�gstep=0 '�I���ҋ@
			end if

		case 2
		' [ �W�J�}�ړ���~�m�F ]
			if �t�^�킹�r�o�v��=OFF and  �����R���x�AC���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH19_�����m and PH20_�t�^���m then
						�W�킹���j�b�gStatusMsg=#42	'	�t�^�u����
						inc(�W�킹���j�b�gstep) '�t�^�킹
						
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH19_�����m) and PH20_�t�^���m then 
							�W�킹���j�b�gStatusMsg=#40	'	�t�^��蒆
							inc(�W�킹���j�b�gstep) '�t�^���
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
						else
							�t�^�킹�r�o�v��=ON
							�W�킹���j�b�gstep=1  '�I��
					end if
			
			else
			
				�W�킹���j�b�gstep=1
			
			end if
		
		case 3
		' [ ���j�b�g�����o ]
			if �W�킹���j�b�g���� then
				�W�킹���j�b�gstep=100 '�v���Z�X����
			else
				�t�^�킹�r�o�v��=ON
				�W�킹���j�b�gstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			if �t�^�킹���� then '�����ړ���OFF
				�t�^�킹�r�o�v��=ON
				�W�킹���j�b�gstep=1
			else
				if �t�^�킹�t�^��蒆 and  PH19_�����m and PH20_�t�^���m then
					inc(�W�킹���j�b�gstep) '�t�^�킹����
				else if not(�t�^�킹�t�^��蒆) and  not(PH19_�����m) and PH20_�t�^���m then
					�W�킹���j�b�gstep=150 '�t�^��菈��
				else
					�t�^�킹�r�o�v��=ON
					�W�킹���j�b�gstep=1
				end if
			end if

		'------------------------------------------------------
		case 101  '�t�^�킹 (�A���N�����v�j
			mSV34_�V�����_�㏸A=OFF
			mSV35_�V�����_���~A=OFF
			mSV36_�V�����_�㏸B=OFF
			mSV37_�V�����_���~B=OFF
			mSV38_�N�����v=OFF
			mSV39_�A���N�����v=OFF

			
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)

		case 102
			if tim_procstep.B then
				if ((XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A) and ((XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B) then 
					if ((XSW111_���ʒu�E��ޒ[ and not(pnlPBXSW111_���ʒu�E��ޒ[)) or passXSW111_���ʒu�E��ޒ[) and ((XSW112_���ʒu����ޒ[ and not(pnlPBXSW112_���ʒu����ޒ[)) or passXSW112_���ʒu����ޒ[) then
						if ((XSW43_�N�����v and not(pnlPBXSW43_�N�����v)) or passXSW43_�N�����v) then
							inc(�W�킹���j�b�gstep)
						else
							�W�킹���j�b�gstep=1
						end if
					else
						�W�킹���j�b�gstep=1						
					end if
				else
					�W�킹���j�b�gstep=1
				end if
			end if

		'------------------------------------------------------
		case 103
			mSV64_���ʒu=ON
			inc(�W�킹���j�b�gstep)
			
		case 104
			if (not(XSW111_���ʒu�E��ޒ[) or pnlPBXSW111_���ʒu�E��ޒ[) and (not(XSW112_���ʒu����ޒ[) or pnlPBXSW112_���ʒu����ޒ[) then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 105
			tim_procstep_val=20
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)
		
		case 106
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 107
			mSV64_���ʒu=OFF
			inc(�W�킹���j�b�gstep)
			
		case 108
			if ((XSW111_���ʒu�E��ޒ[ and not(pnlPBXSW111_���ʒu�E��ޒ[)) or passXSW111_���ʒu�E��ޒ[) and ((XSW112_���ʒu����ޒ[ and not(pnlPBXSW112_���ʒu����ޒ[)) or passXSW112_���ʒu����ޒ[) then
				inc(�W�킹���j�b�gstep)
			end if
		'------------------------------------------------------
		case 109
			mSV35_�V�����_���~A=ON
			inc(�W�킹���j�b�gstep)

		case 110
			if (XSW40_�V�����_���~�[A and not(pnlPBXSW40_�V�����_���~�[A)) or passXSW40_�V�����_���~�[A then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 111
			mSV35_�V�����_���~A=OFF
			tim_procstep_val=5
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)
		
		case 112
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 113
			'-- errpassXSW40_�V�����_���~�[A  �̏ꍇ�̓N�����v���O���Ȃ� --
			if not(errXSW40_�V�����_���~�[A) then
				mSV39_�A���N�����v=ON	
				errpassXSW44_�A���N�����v=OFF
				inc(�W�킹���j�b�gstep)
			else
				inc(�W�킹���j�b�gstep)
			end if				
		
		case 114
			if not(errXSW40_�V�����_���~�[A) then		
				if (XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v)) or passXSW44_�A���N�����v then
					inc(�W�킹���j�b�gstep)
				end if
			else
				inc(�W�킹���j�b�gstep)		
			end if
		
		case 115
			mSV39_�A���N�����v=OFF
			tim_procstep_val=0 '�A���N�����v�ҋ@����
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)
		
		case 116
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 117
			mSV34_�V�����_�㏸A=ON
			inc(�W�킹���j�b�gstep)

		case 118
			if (XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 119
			mSV34_�V�����_�㏸A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)
			
		
		case 120
			if tim_procstep.B then
				if not(errXSW40_�V�����_���~�[A) then					
					�t�^�킹�t�^��蒆=OFF
				end if
				inc(�W�킹���j�b�gstep)
			end if
		
		case 121
			if errXSW40_�V�����_���~�[A then
				errXSW40_�V�����_���~�[A=OFF
			else
				RetryMode=OFF
				�t�^�킹����=ON
				�t�^�킹�r�o�v��=ON
			end if
			�W�킹���j�b�gstep=1
		'------------------------------------------------------
		case 150 '�t�^���  �i�N�����v�j
			mSV34_�V�����_�㏸A=OFF
			mSV35_�V�����_���~A=OFF
			mSV36_�V�����_�㏸B=OFF
			mSV37_�V�����_���~B=OFF
			mSV38_�N�����v=OFF
			mSV39_�A���N�����v=OFF
			inc(�W�킹���j�b�gstep)

		case 151
			mSV39_�A���N�����v=ON	
			inc(�W�킹���j�b�gstep)

		case 152
			if (XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v)) or passXSW44_�A���N�����v then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 153
			mSV39_�A���N�����v=OFF
			tim_procstep_val=0 '�A���N�����v�ҋ@����
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)


		case 154
			if tim_procstep.B then
				if ((XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A) and ((XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B) then  
					if ((XSW111_���ʒu�E��ޒ[ and not(pnlPBXSW111_���ʒu�E��ޒ[)) or passXSW111_���ʒu�E��ޒ[) and ((XSW112_���ʒu����ޒ[ and not(pnlPBXSW112_���ʒu����ޒ[)) or passXSW112_���ʒu����ޒ[) then
						if ((XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v)) or passXSW44_�A���N�����v) then
							inc(�W�킹���j�b�gstep)
						else
							�W�킹���j�b�gstep=1
						end if
					else
						�W�킹���j�b�gstep=1					
					end if
				else
					�W�킹���j�b�gstep=1
				end if
			end if

		case 155
			mSV35_�V�����_���~A=ON
			mSV37_�V�����_���~B=ON
			inc(�W�킹���j�b�gstep)

		case 156
			if (XSW40_�V�����_���~�[A and not(pnlPBXSW40_�V�����_���~�[A)) or passXSW40_�V�����_���~�[A then
				mSV35_�V�����_���~A=OFF
				inc(�W�킹���j�b�gstep)
			end if		
		
		case 157
			if (XSW42_�V�����_���~�[B and not(pnlPBXSW42_�V�����_���~�[B)) or passXSW42_�V�����_���~�[B then
				mSV37_�V�����_���~B=OFF
				inc(�W�킹���j�b�gstep)
			end if

		case 158
			tim_procstep_val=5
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)		

		case 159
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 160
			mSV38_�N�����v=ON
			inc(�W�킹���j�b�gstep)
		
		case 161
			if (XSW43_�N�����v and not(pnlPBXSW43_�N�����v)) or passXSW43_�N�����v then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 162
			mSV38_�N�����v=OFF
			inc(�W�킹���j�b�gstep)

		case 163
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)				

		case 164
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if

		case 165
			mSV30_�X�g�b�p=OFF '�R���x�AC�X�g�b�p
			mSV32_�N�����v=OFF '�R���x�AC�N�����v
			inc(�W�킹���j�b�gstep)

		case 166
			if ((XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[)) or passXSW31_�X�g�b�p���~�[) and ((XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[)) or passXSW35_�N�����v���~�[) then
				inc(�W�킹���j�b�gstep)
			end if		

		
		case 167
			mSV36_�V�����_�㏸B=ON
			mSV34_�V�����_�㏸A=ON
			inc(�W�킹���j�b�gstep)

		case 168
			if (XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B then
				mSV36_�V�����_�㏸B=OFF
				inc(�W�킹���j�b�gstep)
			end if
		
		case 169
			if (XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A then
				mSV34_�V�����_�㏸A=OFF
				inc(�W�킹���j�b�gstep)
			end if

		case 170
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)

		case 171
			if tim_procstep.B then
				�t�^�킹�t�^��蒆=ON
				inc(�W�킹���j�b�gstep)
			end if

		case 172
			if errpassXSW40_�V�����_���~�[A then
				errpassXSW40_�V�����_���~�[A=OFF
			end if
			�t�^�킹����=ON
			�t�^�킹�r�o�v��=ON
			�W�킹���j�b�gstep=1
		'------------------------------------------------------
		'�W���ߴװ���̊��r�o�A�t�^�u��
		case 200 '�t�^�킹�G���[���̊��r�o�A�t�^�u��
			mSV30_�X�g�b�p=OFF '�R���x�AC�X�g�b�p
			mSV32_�N�����v=OFF '�R���x�AC�N�����v
			inc(�W�킹���j�b�gstep)

		case 201
			if ((XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[)) or passXSW31_�X�g�b�p���~�[) and ((XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[)) or passXSW35_�N�����v���~�[) then
				inc(�W�킹���j�b�gstep)
			end if
			
		case 202
			if not(PH54_������g���K) then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 203
			MC15_�������[�^step=1
			MC43_��ڃR���x�Astep=1
			inc(�W�킹���j�b�gstep)
		
		case 204
			if MC15_�������[�^step=0 and MC43_��ڃR���x�Astep=0 then
				inc(�W�킹���j�b�gstep)		
			end if 
		
		case 205 '�t�^�O��
			mSV34_�V�����_�㏸A=OFF
			mSV35_�V�����_���~A=OFF
			mSV36_�V�����_�㏸B=OFF
			mSV37_�V�����_���~B=OFF
			mSV38_�N�����v=OFF
			mSV39_�A���N�����v=OFF
			inc(�W�킹���j�b�gstep)


		case 206
			mSV35_�V�����_���~A=ON
			mSV37_�V�����_���~B=ON
			inc(�W�킹���j�b�gstep)

		case 207
			if (XSW40_�V�����_���~�[A and not(pnlPBXSW40_�V�����_���~�[A)) or passXSW40_�V�����_���~�[A then
				mSV35_�V�����_���~A=OFF
				inc(�W�킹���j�b�gstep)
			end if		
		
		case 208
			if (XSW42_�V�����_���~�[B and not(pnlPBXSW42_�V�����_���~�[B)) or passXSW42_�V�����_���~�[B then
				mSV37_�V�����_���~B=OFF
				inc(�W�킹���j�b�gstep)
			end if

		case 209
			tim_procstep_val=5
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)		

		case 210
			if tim_procstep.B then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 211
			mSV39_�A���N�����v=ON	
			inc(�W�킹���j�b�gstep)
		
		case 212
			if (XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v)) or passXSW44_�A���N�����v then
				inc(�W�킹���j�b�gstep)
			end if
		
		case 213
			mSV39_�A���N�����v=OFF
			inc(�W�킹���j�b�gstep)


		case 214
			mSV36_�V�����_�㏸B=ON
			mSV34_�V�����_�㏸A=ON
			inc(�W�킹���j�b�gstep)

		case 215
			if (XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B then
				mSV36_�V�����_�㏸B=OFF
				inc(�W�킹���j�b�gstep)
			end if
		
		case 216
			if (XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A then
				mSV34_�V�����_�㏸A=OFF
				inc(�W�킹���j�b�gstep)
			end if

		case 217
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W�킹���j�b�gstep)

		case 218
			if tim_procstep.B then
				errXSW40_�V�����_���~�[A=OFF
				EjectMode=OFF
				�t�^�킹�t�^��蒆=OFF
				�t�^�킹����=ON
				�t�^�킹�r�o�v��=ON

				almXSW40_�V�����_���~�[A=ON
				�W�킹���j�b�gErrStep=1
				
				�W�킹���j�b�gstep=1
			end if
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�W�킹���j�b�gAutoRun=OFF
		
		�W�킹���j�b�gstep=0 '�I��
		�t�^�킹����=OFF


		'------------------------------------------------------
		if ldp(pnlPBSV35_�V�����_���~A) then
			if ((XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A) then
				mSV35_�V�����_���~A=ON
				mSV34_�V�����_�㏸A=OFF
			end if
		else if ldp(pnlPBSV34_�V�����_�㏸A) then
			if ((XSW40_�V�����_���~�[A and not(pnlPBXSW40_�V�����_���~�[A)) or passXSW40_�V�����_���~�[A) then
				mSV35_�V�����_���~A=OFF
				mSV34_�V�����_�㏸A=ON
			end if
		end if
		if mSV35_�V�����_���~A and (XSW40_�V�����_���~�[A and not(pnlPBXSW40_�V�����_���~�[A)) or passXSW40_�V�����_���~�[A then
			mSV35_�V�����_���~A=OFF
		end if
		if mSV34_�V�����_�㏸A and (XSW39_�V�����_�㏸�[A and not(pnlPBXSW39_�V�����_�㏸�[A)) or passXSW39_�V�����_�㏸�[A then
			mSV34_�V�����_�㏸A=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV37_�V�����_���~B) then
			'���~
			if not(PH19_�����m)  then
				if ((XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B) and ((XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v)) or passXSW44_�A���N�����v) then
					if ((XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[)) or passXSW31_�X�g�b�p���~�[) and ((XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[)) or passXSW35_�N�����v���~�[) then
						mSV37_�V�����_���~B=ON
						mSV36_�V�����_�㏸B=OFF		
					end if
				end if
			end if		
		else if ldp(pnlPBSV36_�V�����_�㏸B) then
			'�㏸
			if ((XSW42_�V�����_���~�[B and not(pnlPBXSW42_�V�����_���~�[B)) or passXSW42_�V�����_���~�[B) and ((XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v)) or passXSW44_�A���N�����v) then
				mSV37_�V�����_���~B=OFF
				mSV36_�V�����_�㏸B=ON
			
			else if ((XSW42_�V�����_���~�[B and not(pnlPBXSW42_�V�����_���~�[B)) or passXSW42_�V�����_���~�[B) and  ((XSW43_�N�����v and not(pnlPBXSW43_�N�����v)) or passXSW43_�N�����v) then 
					if ((XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[)) or passXSW31_�X�g�b�p���~�[) and ((XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[)) or passXSW35_�N�����v���~�[) then
						mSV37_�V�����_���~B=OFF
						mSV36_�V�����_�㏸B=ON
					end if
			end if
		end if
		if mSV37_�V�����_���~B and ((XSW42_�V�����_���~�[B and not(pnlPBXSW42_�V�����_���~�[B)) or passXSW42_�V�����_���~�[B) then
			mSV37_�V�����_���~B=OFF
		end if
		if mSV36_�V�����_�㏸B and ((XSW41_�V�����_�㏸�[B and not(pnlPBXSW41_�V�����_�㏸�[B)) or passXSW41_�V�����_�㏸�[B) then
			mSV36_�V�����_�㏸B=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV38_�N�����v) then
			if (XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v)) or passXSW44_�A���N�����v then
				mSV38_�N�����v=ON
				mSV39_�A���N�����v=OFF
				
				�t�^�킹�t�^��蒆=ON
			end if
		else if ldp(pnlPBSV39_�A���N�����v) then
			if (XSW43_�N�����v and not(pnlPBXSW43_�N�����v)) or passXSW43_�N�����v then
				mSV38_�N�����v=OFF
				mSV39_�A���N�����v=ON
				
				�t�^�킹�t�^��蒆=OFF
			end if
		end if
		if mSV39_�A���N�����v and ((XSW44_�A���N�����v and not(pnlPBXSW44_�A���N�����v)) or passXSW44_�A���N�����v) then
			mSV39_�A���N�����v=OFF
		end if
		if mSV38_�N�����v and ((XSW43_�N�����v and not(pnlPBXSW43_�N�����v)) or passXSW43_�N�����v) then
			mSV38_�N�����v=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV64_���ʒu) then
			if mSV64_���ʒu then
				mSV64_���ʒu=OFF
			else
				mSV64_���ʒu=ON
			end if
		end if
		'------------------------------------------------------
			
		
		

	end if '�W�킹���j�b�gAutoMode
	'===================================================================================================================
	'�y �W�킹���j�b�gOrgErr���� �z
	else

		if ResetFlg then
			�W�킹���j�b�gOrgErr=OFF
		end if		

	end if

	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		if �t�^�킹�t�^��蒆 then
			tmr(tim_errXSW40_�V�����_���~�[,tim_errXSW40_�V�����_���~�[_val)
			select case �W�킹���j�b�gErrStep
			case 0
			'------------------------------------------------------------------
			case 1
				�W�킹���j�b�gErr=ON
				pauseMC15_�������[�^=ON
				pauseMC43_��ڃR���x�A=ON
				
				if ResetFlg then				' 
					almXSW39_�V�����_�㏸�[A=OFF
					almXSW40_�V�����_���~�[A=OFF
					almXSW41_�V�����_�㏸�[B=OFF
					almXSW42_�V�����_���~�[B=OFF
					almXSW43_�N�����v=OFF
					almXSW44_�A���N�����v=OFF
					
					almXSW111_���ʒu�E��ޒ[=OFF
					almXSW112_���ʒu����ޒ[=OFF
					
					almXSW35_�N�����v���~�[=OFF
					almXSW36_�N�����v�㏸�[=OFF
					almXSW31_�X�g�b�p���~�[=OFF
					almXSW32_�X�g�b�p�㏸�[=OFF


					pauseSV32_�N�����v=OFF
					pauseSV30_�X�g�b�p=OFF
					pauseMC15_�������[�^=OFF
					pauseMC43_��ڃR���x�A=OFF

					inc(�W�킹���j�b�gErrStep)
				end if
			case 2
				if EjectMode then
					EjectMode=OFF
				else 
					if RetryMode then
						RetryMode=OFF
						EjectMode=ON
						inc(�W�킹���j�b�gErrStep)
					else
						RetryMode=ON
						EjectMode=OFF
						inc(�W�킹���j�b�gErrStep)
					end if
				end if
			case 3
				if EjectMode and �W�킹���j�b�gstep<100 then '�W�킹���j�b�gstep�� 0�܂���1�Ńv���Z�X���I�����Ă��邱��
					�W�킹���j�b�gstep=200
				else if RetryMode and �W�킹���j�b�gstep<100 then '�W�킹���j�b�gstep�� 0�܂���1�Ńv���Z�X���I�����Ă��邱��
					�W�킹���j�b�gstep=101
				end if
				inc(�W�킹���j�b�gErrStep)
			'------------------------------------------------------------------
			case 4
				res(tim_notXSW31_�X�g�b�p���~�[)
				res(tim_notXSW32_�X�g�b�p�㏸�[)				
				res(tim_notXSW35_�N�����v���~�[)
				res(tim_notXSW36_�N�����v�㏸�[)
				
				res(tim_notXSW39_�V�����_�㏸�[A)
				res(tim_notXSW40_�V�����_���~�[A)
				res(tim_notXSW41_�V�����_�㏸�[B)
				res(tim_notXSW42_�V�����_���~�[B)
				res(tim_notXSW43_�N�����v)
				res(tim_notXSW44_�A���N�����v)
				res(tim_notXSW111_���ʒu�E��ޒ[)
				res(tim_notXSW112_���ʒu����ޒ[)
				
				res(tim_XSW31_�X�g�b�p���~�[)
				res(tim_XSW32_�X�g�b�p�㏸�[)				
				res(tim_XSW35_�N�����v���~�[)
				res(tim_XSW36_�N�����v�㏸�[)

				res(tim_XSW39_�V�����_�㏸�[A)
				res(tim_XSW40_�V�����_���~�[A)
				res(tim_XSW41_�V�����_�㏸�[B)
				res(tim_XSW42_�V�����_���~�[B)
				res(tim_XSW43_�N�����v)
				res(tim_XSW44_�A���N�����v)
				res(tim_XSW111_���ʒu�E��ޒ[)
				res(tim_XSW112_���ʒu����ޒ[)

				�W�킹���j�b�gErr=OFF
				�W�킹���j�b�gErrStep=0
			
			end select
		
		else
			�W�킹���j�b�gErr=ON

			select case �W�킹���j�b�gErrStep
			case 0
			case 1
				if ResetFlg then
					
					almXSW39_�V�����_�㏸�[A=OFF
					almXSW40_�V�����_���~�[A=OFF
					almXSW41_�V�����_�㏸�[B=OFF
					almXSW42_�V�����_���~�[B=OFF
					almXSW43_�N�����v=OFF
					almXSW44_�A���N�����v=OFF

					almXSW111_���ʒu�E��ޒ[=OFF
					almXSW112_���ʒu����ޒ[=OFF

					almXSW35_�N�����v���~�[=OFF
					almXSW36_�N�����v�㏸�[=OFF
					almXSW31_�X�g�b�p���~�[=OFF
					almXSW32_�X�g�b�p�㏸�[=OFF

					
					inc(�W�킹���j�b�gErrStep)
				end if
			case 2
					res(tim_notXSW31_�X�g�b�p���~�[)
					res(tim_notXSW32_�X�g�b�p�㏸�[)				
					res(tim_notXSW35_�N�����v���~�[)
					res(tim_notXSW36_�N�����v�㏸�[)
					
					res(tim_notXSW39_�V�����_�㏸�[A)
					res(tim_notXSW40_�V�����_���~�[A)
					res(tim_notXSW41_�V�����_�㏸�[B)
					res(tim_notXSW42_�V�����_���~�[B)
					res(tim_notXSW43_�N�����v)
					res(tim_notXSW44_�A���N�����v)
					res(tim_notXSW111_���ʒu�E��ޒ[)
					res(tim_notXSW112_���ʒu����ޒ[)
					
					res(tim_XSW31_�X�g�b�p���~�[)
					res(tim_XSW32_�X�g�b�p�㏸�[)				
					res(tim_XSW35_�N�����v���~�[)
					res(tim_XSW36_�N�����v�㏸�[)

					res(tim_XSW39_�V�����_�㏸�[A)
					res(tim_XSW40_�V�����_���~�[A)
					res(tim_XSW41_�V�����_�㏸�[B)
					res(tim_XSW42_�V�����_���~�[B)
					res(tim_XSW43_�N�����v)
					res(tim_XSW44_�A���N�����v)
					res(tim_XSW111_���ʒu�E��ޒ[)
					res(tim_XSW112_���ʒu����ޒ[)

				�W�킹���j�b�gErr=OFF
				�W�킹���j�b�gErrStep=0
			end select
		
		end if

	end if 'if �W�킹���j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �W�킹���j�b�gEmgStep
	case 0
	
	case 1
		�W�킹���j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�W�킹���j�b�gAutoMode and ��������AutoMode ) or �W�킹���j�b�gstep<>0 then

			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV35_�V�����_���~A=OFF
			mSV34_�V�����_�㏸A=OFF
			mSV37_�V�����_���~B=OFF
			mSV36_�V�����_�㏸B=OFF
			mSV38_�N�����v=OFF
			mSV39_�A���N�����v=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�W�킹���j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�W�킹���j�b�gEmgStep)
		end if
	case 3
		if (�W�킹���j�b�gAutoMode and ��������AutoMode ) or �W�킹���j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				'---------------------------------
				inc(�W�킹���j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�W�킹���j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�W�킹���j�b�gEmgStep=0
		�W�킹���j�b�gEmg=OFF
	end select
		
end if 'if �W�킹���j�b�gEmgStep=0 then
