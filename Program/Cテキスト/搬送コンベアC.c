	'�����R���x�AC
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AC
'
'  	�ړ����x  161.667mm/1sec
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������

    �����R���x�ACAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�ACAutoRun=OFF
    �����R���x�AC����=ON
    �����R���x�ACOrgErr=OFF
    �����R���x�ACErr=OFF
    �����R���x�ACEmg=OFF
    �����R���x�ACstep=0
    �����R���x�ACErrStep=0
    �����R���x�ACOrgErrStep=0
    �����R���x�ACEmgStep=0

	SV29_�X�g�b�pstep=0
	SV30_�X�g�b�pstep=0
	MC14_�������[�^step=0
	MC15_�������[�^step=0
	MC43_��ڃR���x�Astep=0

	ManualInite=1
	
end if
'===================================================================================================================
'�y ���_ �z
�����R���x�ACOrg= ((XSW29_�X�g�b�p���~�[ and not(pnlPBXSW29_�X�g�b�p���~�[)) or passXSW29_�X�g�b�p���~�[) or ((XSW30_�X�g�b�p�㏸�[ and not(pnlPBXSW30_�X�g�b�p�㏸�[)) or passXSW30_�X�g�b�p�㏸�[)
�����R���x�ACOrg= �����R���x�ACOrg and (((XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[)) or passXSW31_�X�g�b�p���~�[) or ((XSW32_�X�g�b�p�㏸�[ and not(pnlPBXSW32_�X�g�b�p�㏸�[)) or passXSW32_�X�g�b�p�㏸�[))
�����R���x�ACOrg= �����R���x�ACOrg and (((XSW33_�N�����v���~�[ and not(pnlPBXSW33_�N�����v���~�[)) or passXSW33_�N�����v���~�[) or ((XSW34_�N�����v�㏸�[ and not(pnlPBXSW34_�N�����v�㏸�[)) or passXSW34_�N�����v�㏸�[))
�����R���x�ACOrg= �����R���x�ACOrg and (((XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[)) or passXSW35_�N�����v���~�[) or ((XSW36_�N�����v�㏸�[ and not(pnlPBXSW36_�N�����v�㏸�[)) or passXSW36_�N�����v�㏸�[))


'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�ACEmg=ON
	�����R���x�ACEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(not(SV65_�X�g�b�p) and not(XSW74_�X�g�b�p���~�[) and not(pnlPBXSW74_�X�g�b�p���~�[),tim_notXSW74_�X�g�b�p���~�[,#20) '626.94ms
tmr(SV65_�X�g�b�p and not(XSW75_�X�g�b�p�㏸�[) and not(pnlPBXSW75_�X�g�b�p�㏸�[),tim_notXSW75_�X�g�b�p�㏸�[,#20) '768.11ms
tmr(not(SV31_�N�����v) and not(XSW33_�N�����v���~�[) and not(pnlPBXSW33_�N�����v���~�[),tim_notXSW33_�N�����v���~�[,#20) '484.28ms
tmr(SV31_�N�����v and not(XSW34_�N�����v�㏸�[) and not(pnlPBXSW34_�N�����v�㏸�[),tim_notXSW34_�N�����v�㏸�[,#20) '363.10ms
tmr(not(SV29_�X�g�b�p) and not(XSW29_�X�g�b�p���~�[) and not(pnlPBXSW29_�X�g�b�p���~�[), tim_notXSW29_�X�g�b�p���~�[,#20) '1230.35ms
tmr(SV29_�X�g�b�p and not(XSW30_�X�g�b�p�㏸�[) and not(pnlPBXSW30_�X�g�b�p�㏸�[), tim_notXSW30_�X�g�b�p�㏸�[,#20) '396.88ms
tmr(not(SV32_�N�����v) and not(XSW35_�N�����v���~�[) and not(pnlPBXSW35_�N�����v���~�[), tim_notXSW35_�N�����v���~�[,#20) '493.49ms
tmr(SV32_�N�����v and not(XSW36_�N�����v�㏸�[) and not(pnlPBXSW36_�N�����v�㏸�[), tim_notXSW36_�N�����v�㏸�[,#20) '724.98ms
tmr(not(SV30_�X�g�b�p) and not(XSW31_�X�g�b�p���~�[) and not(pnlPBXSW31_�X�g�b�p���~�[),tim_notXSW31_�X�g�b�p���~�[,#20) '980.32ms
tmr(SV30_�X�g�b�p and not(XSW32_�X�g�b�p�㏸�[) and not(pnlPBXSW32_�X�g�b�p�㏸�[),tim_notXSW32_�X�g�b�p�㏸�[,#20) '819.96ms
tmr(not(SV33_���t�g) and not(XSW37_���t�g���~�[) and not(pnlPBXSW37_���t�g���~�[),tim_notXSW37_���t�g���~�[,#30) '932.62ms
tmr(SV33_���t�g and not(XSW38_���t�g�㏸�[) and not(pnlPBXSW38_���t�g�㏸�[),tim_notXSW38_���t�g�㏸�[,#30) '654.33ms

'tmr(SV65_�X�g�b�p and XSW74_�X�g�b�p���~�[,tim_XSW74_�X�g�b�p���~�[,#10)
if LDF(SV65_�X�g�b�p) and XSW74_�X�g�b�p���~�[ and not(pnlPBXSW74_�X�g�b�p���~�[) then
	SET(tim_XSW74_�X�g�b�p���~�[)
end if
'tmr(not(SV65_�X�g�b�p) and XSW75_�X�g�b�p�㏸�[,tim_XSW75_�X�g�b�p�㏸�[,#10)
if LDP(SV65_�X�g�b�p) and  XSW75_�X�g�b�p�㏸�[ and not(pnlPBXSW75_�X�g�b�p�㏸�[) then
	SET(tim_XSW75_�X�g�b�p�㏸�[)
end if
'tmr(SV31_�N�����v and XSW33_�N�����v���~�[,tim_XSW33_�N�����v���~�[,#10)
if LDF(SV31_�N�����v) and XSW33_�N�����v���~�[ and not(pnlPBXSW33_�N�����v���~�[) then
	SET(tim_XSW33_�N�����v���~�[)
end if
'tmr(not(SV31_�N�����v) and XSW34_�N�����v�㏸�[,tim_XSW34_�N�����v�㏸�[,#10)
if LDP(SV31_�N�����v) and XSW34_�N�����v�㏸�[ and not(pnlPBXSW34_�N�����v�㏸�[) then
	SET(tim_XSW34_�N�����v�㏸�[)
end if
'tmr(SV29_�X�g�b�p and XSW29_�X�g�b�p���~�[, tim_XSW29_�X�g�b�p���~�[,#10)
if LDF(SV29_�X�g�b�p) and XSW29_�X�g�b�p���~�[ and not(pnlPBXSW29_�X�g�b�p���~�[) then
	SET(tim_XSW29_�X�g�b�p���~�[)
end if
'tmr(not(SV29_�X�g�b�p) and XSW30_�X�g�b�p�㏸�[, tim_XSW30_�X�g�b�p�㏸�[,#10)
if LDP(SV29_�X�g�b�p) and XSW30_�X�g�b�p�㏸�[ and not(pnlPBXSW30_�X�g�b�p�㏸�[) then
	SET(tim_XSW30_�X�g�b�p�㏸�[)
end if
'tmr(SV32_�N�����v and XSW35_�N�����v���~�[, tim_XSW35_�N�����v���~�[,#10)
if LDF(SV32_�N�����v) and XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[) then
	SET(tim_XSW35_�N�����v���~�[)
end if
'tmr(not(SV32_�N�����v) and XSW36_�N�����v�㏸�[, tim_XSW36_�N�����v�㏸�[,#10)
if LDP(SV32_�N�����v) and  XSW36_�N�����v�㏸�[ and not(pnlPBXSW36_�N�����v�㏸�[) then
	SET(tim_XSW36_�N�����v�㏸�[)
end if
'tmr(SV30_�X�g�b�p and XSW31_�X�g�b�p���~�[,tim_XSW31_�X�g�b�p���~�[,#10)
if LDF(SV30_�X�g�b�p) and  XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[) then
	SET(tim_XSW31_�X�g�b�p���~�[)
end if
'tmr(not(SV30_�X�g�b�p) and XSW32_�X�g�b�p�㏸�[,tim_XSW32_�X�g�b�p�㏸�[,#10)
if LDP(SV30_�X�g�b�p) and  XSW32_�X�g�b�p�㏸�[ and not(pnlPBXSW32_�X�g�b�p�㏸�[) then
	SET(tim_XSW32_�X�g�b�p�㏸�[)
end if
'tmr(SV33_���t�g and XSW37_���t�g���~�[,tim_XSW37_���t�g���~�[,#10)
if LDF(SV33_���t�g) and XSW37_���t�g���~�[ and not(pnlPBXSW37_���t�g���~�[) then
	SET(tim_XSW37_���t�g���~�[)
end if
'tmr(not(SV33_���t�g) and XSW38_���t�g�㏸�[,tim_XSW38_���t�g�㏸�[,#10)
if LDP(SV33_���t�g) and XSW38_���t�g�㏸�[ and not(pnlPBXSW38_���t�g�㏸�[) then
	SET(tim_XSW38_���t�g�㏸�[)
end if

'passtimXSW74_�X�g�b�p���~�[_val=#626
tms(not(SV65_�X�g�b�p),passtimXSW74_�X�g�b�p���~�[,passtimXSW74_�X�g�b�p���~�[_val) 

'passtimXSW75_�X�g�b�p�㏸�[_val=#768
tms(SV65_�X�g�b�p,passtimXSW75_�X�g�b�p�㏸�[,passtimXSW75_�X�g�b�p�㏸�[_val) 

'passtimXSW33_�N�����v���~�[_val=#484
tms(not(SV31_�N�����v),passtimXSW33_�N�����v���~�[,passtimXSW33_�N�����v���~�[_val) 

'passtimXSW34_�N�����v�㏸�[_val=#363
tms(SV31_�N�����v,passtimXSW34_�N�����v�㏸�[,passtimXSW34_�N�����v�㏸�[_val)

'passtimXSW29_�X�g�b�p���~�[_val=#1230
tms(not(SV29_�X�g�b�p), passtimXSW29_�X�g�b�p���~�[,passtimXSW29_�X�g�b�p���~�[_val) 

'passtimXSW30_�X�g�b�p�㏸�[_val=#396
tms(SV29_�X�g�b�p, passtimXSW30_�X�g�b�p�㏸�[,passtimXSW30_�X�g�b�p�㏸�[_val) 

'passtimXSW35_�N�����v���~�[_val=#493
tms(not(SV32_�N�����v), passtimXSW35_�N�����v���~�[,passtimXSW35_�N�����v���~�[_val) 

'passtimXSW36_�N�����v�㏸�[_val=#724
tms(SV32_�N�����v, passtimXSW36_�N�����v�㏸�[,passtimXSW36_�N�����v�㏸�[_val) 

'passtimXSW31_�X�g�b�p���~�[_val=#980
tms(not(SV30_�X�g�b�p),passtimXSW31_�X�g�b�p���~�[,passtimXSW31_�X�g�b�p���~�[_val) 

'passtimXSW32_�X�g�b�p�㏸�[_val=#819
tms(SV30_�X�g�b�p,passtimXSW32_�X�g�b�p�㏸�[,passtimXSW32_�X�g�b�p�㏸�[_val) 

'passtimXSW37_���t�g���~�[_val=#932
tms(not(SV33_���t�g),passtimXSW37_���t�g���~�[,passtimXSW37_���t�g���~�[_val) 

'passtimXSW38_���t�g�㏸�[_val=#654
tms(SV33_���t�g,passtimXSW38_���t�g�㏸�[,passtimXSW38_���t�g�㏸�[_val) 

tmr(mMC14_�������[�^ and not(pauseMC14_�������[�^) and not(EmgMC14_�������[�^),timerr_MC14_�������[�^,#150)
tmr(mMC15_�������[�^ and not(pauseMC15_�������[�^) and not(EmgMC15_�������[�^),timerr_MC15_�������[�^,#150)
tmr(mMC43_��ڃR���x�A and not(pauseMC43_��ڃR���x�A) and not(EmgMC43_��ڃR���x�A),timerr_MC43_��ڃR���x�A,#150)

if ldp(timerr_MC14_�������[�^.B) then
	almMC14_�������[�^=ON

	mMC14_�������[�^=OFF
	mMC15_�������[�^=OFF
	mMC43_��ڃR���x�A=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC15_�������[�^.B) then
	almMC15_�������[�^=ON

	mMC14_�������[�^=OFF
	mMC15_�������[�^=OFF
	mMC43_��ڃR���x�A=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC43_��ڃR���x�A.B) then
	almMC43_��ڃR���x�A=ON

	mMC14_�������[�^=OFF
	mMC15_�������[�^=OFF
	mMC43_��ڃR���x�A=OFF
	
	�R���x�A�ꎞ��~=ON

end if

if (ldp(tim_XSW74_�X�g�b�p���~�[) or ldp(tim_notXSW74_�X�g�b�p���~�[)) and not(pnlPBXSW74_�X�g�b�p���~�[) then
	almXSW74_�X�g�b�p���~�[=ON
	pnlPBXSW74_�X�g�b�p���~�[=ON
	if tim_XSW74_�X�g�b�p���~�[ then
		res(tim_XSW74_�X�g�b�p���~�[)
	end if
	�����R���x�ACErrStep=1
	
else if	(ldp(tim_XSW75_�X�g�b�p�㏸�[) or ldp(tim_notXSW75_�X�g�b�p�㏸�[)) and not(pnlPBXSW75_�X�g�b�p�㏸�[) then
	pauseSV65_�X�g�b�p=ON
	almXSW75_�X�g�b�p�㏸�[=ON
	pnlPBXSW75_�X�g�b�p�㏸�[=ON
	if tim_XSW75_�X�g�b�p�㏸�[ then
		res(tim_XSW75_�X�g�b�p�㏸�[)
	end if
	�����R���x�ACErrStep=1	

else if (ldp(tim_XSW33_�N�����v���~�[.B) or ldp(tim_notXSW33_�N�����v���~�[.B)) and not(pnlPBXSW33_�N�����v���~�[) then
	almXSW33_�N�����v���~�[=ON
	pnlPBXSW33_�N�����v���~�[=ON
	if tim_XSW33_�N�����v���~�[ then
		res(tim_XSW33_�N�����v���~�[)
	end if
	�����R���x�ACErrStep=1

else if (ldp(tim_XSW34_�N�����v�㏸�[.B) or ldp(tim_notXSW34_�N�����v�㏸�[.B)) and not(pnlPBXSW34_�N�����v�㏸�[) then
	pauseSV31_�N�����v=ON
	almXSW34_�N�����v�㏸�[=ON
	pnlPBXSW34_�N�����v�㏸�[=ON
	if tim_XSW34_�N�����v�㏸�[ then
		res(tim_XSW34_�N�����v�㏸�[)
	end if
	�����R���x�ACErrStep=1

else if (ldp(tim_XSW29_�X�g�b�p���~�[.B) or ldp(tim_notXSW29_�X�g�b�p���~�[.B)) and not(pnlPBXSW29_�X�g�b�p���~�[) then
	almXSW29_�X�g�b�p���~�[=ON
	pnlPBXSW29_�X�g�b�p���~�[=ON
	if tim_XSW29_�X�g�b�p���~�[ then
		res(tim_XSW29_�X�g�b�p���~�[)
	end if
	�����R���x�ACErrStep=1

else if (ldp(tim_XSW30_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW30_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW30_�X�g�b�p�㏸�[) then
	pauseSV29_�X�g�b�p=ON
	almXSW30_�X�g�b�p�㏸�[=ON
	pnlPBXSW30_�X�g�b�p�㏸�[=ON
	if tim_XSW30_�X�g�b�p�㏸�[ then
		res(tim_XSW30_�X�g�b�p�㏸�[)
	end if
	�����R���x�ACErrStep=1
	
else if (ldp(tim_XSW35_�N�����v���~�[.B) or ldp(tim_notXSW35_�N�����v���~�[.B)) and not(pnlPBXSW35_�N�����v���~�[) then
	almXSW35_�N�����v���~�[=ON
	pnlPBXSW35_�N�����v���~�[=ON
	res(tim_XSW35_�N�����v���~�[)
	�����R���x�ACErrStep=1

else if (ldp(tim_XSW36_�N�����v�㏸�[.B) or ldp(tim_notXSW36_�N�����v�㏸�[.B)) and not(pnlPBXSW36_�N�����v�㏸�[) then
	pauseSV32_�N�����v=ON
	almXSW36_�N�����v�㏸�[=ON
	pnlPBXSW35_�N�����v���~�[=ON
	if tim_XSW36_�N�����v�㏸�[ then
		res(tim_XSW36_�N�����v�㏸�[)
	end if
	�����R���x�ACErrStep=1	

else if (ldp(tim_XSW31_�X�g�b�p���~�[.B) or ldp(tim_notXSW31_�X�g�b�p���~�[.B)) and not(pnlPBXSW31_�X�g�b�p���~�[) then
	almXSW31_�X�g�b�p���~�[=ON
	pnlPBXSW31_�X�g�b�p���~�[=ON
	if tim_XSW31_�X�g�b�p���~�[ then
		res(tim_XSW31_�X�g�b�p���~�[)
	end if
	�����R���x�ACErrStep=1

else if (ldp(tim_XSW32_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW32_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW32_�X�g�b�p�㏸�[) then
	pauseSV30_�X�g�b�p=ON
	almXSW32_�X�g�b�p�㏸�[=ON
	pnlPBXSW32_�X�g�b�p�㏸�[=ON
	if tim_XSW32_�X�g�b�p�㏸�[ then
		res(tim_XSW32_�X�g�b�p�㏸�[)
	end if
	�����R���x�ACErrStep=1

else if (ldp(tim_XSW37_���t�g���~�[) or ldp(tim_notXSW37_���t�g���~�[)) and not(pnlPBXSW37_���t�g���~�[) then
	almXSW37_���t�g���~�[=ON
	pnlPBXSW37_���t�g���~�[=ON
	if tim_XSW37_���t�g���~�[ then
		res(tim_XSW37_���t�g���~�[)
	end if
	�����R���x�ACErrStep=1

else if (ldp(tim_XSW38_���t�g�㏸�[) or ldp(tim_notXSW38_���t�g�㏸�[)) and not(pnlPBXSW38_���t�g�㏸�[) then
	pauseSV33_���t�g=ON
	almXSW38_���t�g�㏸�[=ON
	pnlPBXSW38_���t�g�㏸�[=ON
	if tim_XSW38_���t�g�㏸�[ then
		res(tim_XSW38_���t�g�㏸�[)
	end if
	�����R���x�ACErrStep=1

end if

	

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�ACAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�ACAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�ACEmg	���̏��~


if �����R���x�ACEmgStep=0 then  
	
	if �����R���x�ACErrStep=0  then

	if not(�R���x�A�ꎞ��~) then
	
	if not(�����R���x�ACOrgErr) then

	if (�����R���x�ACAutoMode and ��������AutoMode ) or �����R���x�ACstep<>0 then
	
		if ManualInite=1 then		
			mSV65_�X�g�b�p=ON
			mSV29_�X�g�b�p=ON
			mSV30_�X�g�b�p=ON

			'mSV32_�N�����v=ON
			'mSV31_�N�����v=ON
			ManualInite=0
		end if
	
		if not(�����R���x�ACAutoMode and ��������AutoMode ) then
			�����R���x�ACAutoRun=OFF
		end if
	
	tmr(PH17_�����m,timdly_PH17_�����m,5)
	tmr(PH18_�t�^���m,timdly_PH18_�t�^���m,5)
	tmr(PH19_�����m,timdly_PH19_�����m,5)
	tmr(PH20_�t�^���m,timdly_PH20_�t�^���m,5)
	tmr(PH54_������g���K,timdly_PH54_������g���K,5)
	
	'-----------------------------------------------------------------
	' �X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	tmr(tim_SV29_�X�g�b�p,tim_SV29_�X�g�b�p_val) '�Ȃ炵�X�g�b�p�A�N�����v
	select case SV29_�X�g�b�pstep
	case 0
		
	case 1
		PH15_���N�����m=LatchPH15_�����m
		PH16_�t�^�N�����m=LatchPH16_�t�^���m
		PH17_���N�����m=PH17_�����m
		PH18_�t�^�N�����m=PH18_�t�^���m
		
		if LatchPH15_�����m or LatchPH16_�t�^���m or PH17_�����m or PH18_�t�^���m then '�O�̃X�e�[�W(�����R���x�AB���t�g�j
			
			mSV65_�X�g�b�p=OFF '���t�g�X�g�b�p����
			mSV29_�X�g�b�p=OFF '�X�g�b�p���~
			mSV31_�N�����v=OFF '�N�����v���~
			inc(SV29_�X�g�b�pstep)
		else
			SV29_�X�g�b�pstep=0
		end if
		
	case 2
		if (XSW29_�X�g�b�p���~�[ and not(pnlPBXSW29_�X�g�b�p���~�[)) or passXSW29_�X�g�b�p���~�[ then
			if (XSW33_�N�����v���~�[ and not(pnlPBXSW33_�N�����v���~�[)) or passXSW33_�N�����v���~�[ then
				if (XSW74_�X�g�b�p���~�[ and not(pnlPBXSW74_�X�g�b�p���~�[)) or passXSW74_�X�g�b�p���~�[ then 			
					inc(SV29_�X�g�b�pstep)
				end if
			end if
		end if
	
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(SV29_�X�g�b�pstep)
		
		else if not(PH17_�����m) and not(PH18_�t�^���m) then
			inc(SV29_�X�g�b�pstep)
		end if
		
	case 4
		tim_SV29_�X�g�b�p_val=30
		res(tim_SV29_�X�g�b�p)
		inc(SV29_�X�g�b�pstep)

	case 5
		if tim_SV29_�X�g�b�p.B then
			inc(SV29_�X�g�b�pstep)
		end if
	
	case 6
		mSV29_�X�g�b�p=ON '�X�g�b�p�㏸
		inc(SV29_�X�g�b�pstep)

	case 7
		if (XSW30_�X�g�b�p�㏸�[ and not(pnlPBXSW30_�X�g�b�p�㏸�[)) or passXSW30_�X�g�b�p�㏸�[ then
			inc(SV29_�X�g�b�pstep)
		end if		
		

	case 8
		if errpass�R���x�A�ꎞ��~ then
				inc(SV29_�X�g�b�pstep)
		
		else if PH15_���N�����m or PH16_�t�^�N�����m then
			if (PH17_�����m and timdly_PH17_�����m.B) or (PH18_�t�^���m and timdly_PH18_�t�^���m.B) then
				inc(SV29_�X�g�b�pstep)
			end if
		else if PH17_���N�����m or PH18_�t�^�N�����m then
			if (PH19_�����m and timdly_PH19_�����m.B) or (PH20_�t�^���m and timdly_PH20_�t�^���m.B) then
				inc(SV29_�X�g�b�pstep)
			end if
		else
			inc(SV29_�X�g�b�pstep)
		end if
		
	case 9
		mSV65_�X�g�b�p=ON '���t�g�X�g�b�p�㏸
		mSV29_�X�g�b�p=ON '�X�g�b�p�㏸
		mSV33_���t�g=ON
		inc(SV29_�X�g�b�pstep)

	case 10
		if ((XSW30_�X�g�b�p�㏸�[ and not(pnlPBXSW30_�X�g�b�p�㏸�[)) or passXSW30_�X�g�b�p�㏸�[) and ((XSW75_�X�g�b�p�㏸�[ and not(pnlPBXSW75_�X�g�b�p�㏸�[)) or passXSW75_�X�g�b�p�㏸�[) then		
			inc(SV29_�X�g�b�pstep)
		end if
		
	case 11
		tim_SV29_�X�g�b�p_val=10 
		res(tim_SV29_�X�g�b�p)
		inc(SV29_�X�g�b�pstep)
	
	case 12
		if tim_SV29_�X�g�b�p.B then
			inc(SV29_�X�g�b�pstep)
		end if

	case 13
		if PH17_�����m or PH18_�t�^���m then
			mSV31_�N�����v=ON '�N�����v�㏸			
			inc(SV29_�X�g�b�pstep)
		else
			inc(SV29_�X�g�b�pstep)
		end if
		
	case 14
		if mSV31_�N�����v then
			if (XSW34_�N�����v�㏸�[ and not(pnlPBXSW34_�N�����v�㏸�[)) or passXSW34_�N�����v�㏸�[ then
				inc(SV29_�X�g�b�pstep)
			end if
		else
			inc(SV29_�X�g�b�pstep)
		end if

	case 15
		SV29_�X�g�b�pstep=0

	end select	
	'--------------------------------------------
	tmr(tim_SV30_�X�g�b�p, tim_SV30_�X�g�b�p_val) '�t�^�킹�X�g�b�p�[�A�N�����v
	select case SV30_�X�g�b�pstep
	case 0

	case 1
		PH17_���N�����m=PH17_�����m
		PH18_�t�^�N�����m=PH18_�t�^���m
		PH19_���N�����m=PH19_�����m
		PH20_�t�^�N�����m=PH20_�t�^���m
		
		if PH17_�����m or PH18_�t�^���m or PH19_�����m or PH20_�t�^���m then 
			mSV32_�N�����v=OFF '���~
			mSV30_�X�g�b�p=OFF '���~	
			inc(SV30_�X�g�b�pstep)
		else
			SV30_�X�g�b�pstep=0
		end if
		
	case 2
		if (XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[)) or passXSW31_�X�g�b�p���~�[ then
			if (XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[)) or passXSW35_�N�����v���~�[ then 
				inc(SV30_�X�g�b�pstep)
			end if
		end if
	
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(SV30_�X�g�b�pstep)
		
		else if not(PH19_�����m) and not(PH20_�t�^���m) then		
			inc(SV30_�X�g�b�pstep)
		end if
	
	case 4
		tim_SV30_�X�g�b�p_val=30
		res(tim_SV30_�X�g�b�p)
		inc(SV30_�X�g�b�pstep)

	case 5
		if tim_SV30_�X�g�b�p.B then
			inc(SV30_�X�g�b�pstep)
		end if
	
	case 6
		mSV30_�X�g�b�p=ON '�㏸	
		inc(SV30_�X�g�b�pstep)
	
	case 7
		if (XSW32_�X�g�b�p�㏸�[ and not(pnlPBXSW32_�X�g�b�p�㏸�[)) or passXSW32_�X�g�b�p�㏸�[ then
			inc(SV30_�X�g�b�pstep)
		end if

	case 8
		if errpass�R���x�A�ꎞ��~ then
				inc(SV30_�X�g�b�pstep)
		
		else if PH17_���N�����m or PH18_�t�^�N�����m then			
			if (PH19_�����m and timdly_PH19_�����m.B) or (PH20_�t�^���m and timdly_PH20_�t�^���m.B) then
				inc(SV30_�X�g�b�pstep)
			end if
		else
			inc(SV30_�X�g�b�pstep)
		end if
		
	case 9
		if errpass�R���x�A�ꎞ��~ then
				inc(SV30_�X�g�b�pstep)
	
		else if PH19_���N�����m or PH20_�t�^�N�����m then
			if PH54_������g���K then
				inc(SV30_�X�g�b�pstep)
			end if			
		else
			inc(SV30_�X�g�b�pstep)
		end if	
		
	case 10
		mSV30_�X�g�b�p=ON '�㏸	
		inc(SV30_�X�g�b�pstep)
	
	case 11
		if (XSW32_�X�g�b�p�㏸�[ and not(pnlPBXSW32_�X�g�b�p�㏸�[)) or passXSW32_�X�g�b�p�㏸�[ then
			inc(SV30_�X�g�b�pstep)
		end if

	case 12
		tim_SV30_�X�g�b�p_val=10 '�N�����v�㏸�^�C�~���O
		res(tim_SV30_�X�g�b�p)
		inc(SV30_�X�g�b�pstep)
	
	case 13
		if tim_SV30_�X�g�b�p.B then
			inc(SV30_�X�g�b�pstep)
		end if
	
	case 14
		if PH19_�����m and  PH20_�t�^���m then
			mSV32_�N�����v=ON '�㏸
			inc(SV30_�X�g�b�pstep)
		else if �W�킹���j�b�g���� and (not(PH19_�����m) and PH20_�t�^���m) then 
			mSV32_�N�����v=ON '�㏸
			inc(SV30_�X�g�b�pstep)
		else
			inc(SV30_�X�g�b�pstep)
		end if
	
	case 15
		if mSV32_�N�����v then
			if (XSW36_�N�����v�㏸�[ and not(pnlPBXSW36_�N�����v�㏸�[)) or passXSW36_�N�����v�㏸�[ then
				inc(SV30_�X�g�b�pstep)
			end if
		else
			inc(SV30_�X�g�b�pstep)
		end if
		
	case 16
		SV30_�X�g�b�pstep=0

	end select
	'--------------------------------------------
	'MC14_�������[�^
	tmr(tim_MC14_�������[�^,tim_MC14_�������[�^_val)
	
	select case MC14_�������[�^step
	case 0
	
	case 1
		inc(MC14_�������[�^step)
		
	case 2
		PH15_���N�����m=LatchPH15_�����m
		PH16_�t�^�N�����m=LatchPH16_�t�^���m
		PH17_���N�����m=PH17_�����m
		PH18_�t�^�N�����m=PH18_�t�^���m
		'PH19_�����m
		'PH20_�t�^���m
		
		if LatchPH15_�����m or LatchPH16_�t�^���m or PH17_�����m or PH18_�t�^���m then
				if (XSW29_�X�g�b�p���~�[ and not(pnlPBXSW29_�X�g�b�p���~�[)) or passXSW29_�X�g�b�p���~�[ then
					if (XSW33_�N�����v���~�[ and not(pnlPBXSW33_�N�����v���~�[)) or passXSW33_�N�����v���~�[ then
						mMC14_�������[�^=ON
						errpass�R���x�A�ꎞ��~=OFF
						inc(MC14_�������[�^step)
					end if
				end if
		else
			MC14_�������[�^step=0
		end if
		
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(MC14_�������[�^step)
		
		else if not(PH15_�����m) and not(PH16_�t�^���m) and not(PH17_�����m) and not(PH18_�t�^���m) then
			inc(MC14_�������[�^step)
		end if
	
	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(MC14_�������[�^step)
		
		else if PH15_���N�����m or PH16_�t�^�N�����m then
			if (PH17_�����m and timdly_PH17_�����m.B) or (PH18_�t�^���m and timdly_PH18_�t�^���m.B) then
				inc(MC14_�������[�^step)
			end if
		else if PH17_���N�����m or PH18_�t�^�N�����m then
			if (PH19_�����m and timdly_PH19_�����m.B) or (PH20_�t�^���m and timdly_PH20_�t�^���m.B) then
				inc(MC14_�������[�^step)
			end if
		end if
	
	case 5
		tim_MC14_�������[�^_val=10
		res(tim_MC14_�������[�^)
		inc(MC14_�������[�^step)
	
	case 6
		if tim_MC14_�������[�^.B then
			inc(MC14_�������[�^step)
		end if
	
	case 7
		mMC14_�������[�^=OFF
		inc(MC14_�������[�^step)

	case 8
		MC14_�������[�^step=0
	
	end select
	'--------------------------------------------
	'MC15_�������[�^
	tmr(tim_MC15_�������[�^,tim_MC15_�������[�^_val)
	
	select case MC15_�������[�^step
	case 0
	case 1
		inc(MC15_�������[�^step)
	
	case 2
		PH17_���N�����m=PH17_�����m
		PH18_�t�^�N�����m=PH18_�t�^���m
		PH19_���N�����m=PH19_�����m
		PH20_�t�^�N�����m=PH20_�t�^���m
		'PH54_������g���K
		
		if PH17_�����m or PH18_�t�^���m or PH19_�����m or PH20_�t�^���m then
			if (XSW31_�X�g�b�p���~�[ and not(pnlPBXSW31_�X�g�b�p���~�[)) or passXSW31_�X�g�b�p���~�[ then
				if (XSW35_�N�����v���~�[ and not(pnlPBXSW35_�N�����v���~�[)) or passXSW35_�N�����v���~�[ then
					mMC15_�������[�^=ON
					errpass�R���x�A�ꎞ��~=OFF
					inc(MC15_�������[�^step)
				end if
			end if
		else
			MC15_�������[�^step=0
		end if
		
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(MC15_�������[�^step)	
		
		else if not(PH17_�����m) and not(PH18_�t�^���m) and not(PH19_�����m) and not(PH20_�t�^���m) then
			inc(MC15_�������[�^step)	
		end if
	
	case 4
		if errpass�R���x�A�ꎞ��~ then
				inc(MC15_�������[�^step)
		
		else if PH17_���N�����m or PH18_�t�^�N�����m then
			if (PH19_�����m and timdly_PH19_�����m.B) or (PH20_�t�^���m and timdly_PH20_�t�^���m.B) then
				inc(MC15_�������[�^step)
			end if
		else if PH19_���N�����m or PH20_�t�^�N�����m then
			if (PH54_������g���K and timdly_PH54_������g���K.B) then
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
		StageDevice9=StageDevice8			
		StageDevice8=StageDevice7tmp
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
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC43_��ڃR���x�Astep)

	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(MC43_��ڃR���x�Astep)
		
		else if not(PH19_�����m) then 
			inc(MC43_��ڃR���x�Astep)
		end if
	
	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(MC43_��ڃR���x�Astep)
		
		else if PH54_������g���K and timdly_PH54_������g���K.B then
			inc(MC43_��ڃR���x�Astep)
		end if			
	
	case 5
		tim_MC43_��ڃR���x�A_val=5 '��~�^�C�~���O�^�C�}�[
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
	'�y ���ѓ����R���x�A �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�ACstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�ACAutoRun then
				inc(�����R���x�ACstep)
			else 
				�����R���x�ACstep=0 '�I���ҋ@
			end if

		case 2
		' [ �����R���x�A��~�m�F ]
			if (�����R���x�AC�r�o�v��=OFF or (not(PH19_�����m) and not(PH20_�t�^���m)) ) and  ������R���x�A���쒆=OFF and �����R���x�AB�r�o�v��  then
				inc(�����R���x�ACstep)
			else
				�����R���x�ACstep=1
			end if

		case 3
			if PH54_������g���K and (PH19_�����m or PH20_�t�^���m) then
					�����R���x�AC�r�o�v��=ON
					�����R���x�AC���쒆=OFF
					�����R���x�ACstep=1
			else
				inc(�����R���x�ACstep)
			end if					

		case 4
			if 	�Ȃ炵�r�o�v��  and �t�^�킹�r�o�v�� then
				inc(�����R���x�ACstep)
			else
				�����R���x�ACstep=1
			end if
	
		case 5 
		'[ ���_���o ]
			if �����R���x�ACOrg and �Ȃ炵���uOrg and �W�킹���j�b�gOrg then
				errpass�R���x�A�ꎞ��~=OFF
				inc(�����R���x�ACstep)
			else
				�����R���x�ACstep=1
			end if
		
		case 6
			LatchPH15_�����m=OFF
			LatchPH16_�t�^���m=OFF
			
			�����R���x�AC���쒆=ON
			�����R���x�ACstep=100
			
		'--------------------------------------------------------------------------------------------------------------
		' �y �v���Z�X���� �z
		case 100
			LatchPH15_�����m=PH15_�����m
			LatchPH16_�t�^���m=PH16_�t�^���m
			
			if LatchPH15_�����m or LatchPH16_�t�^���m then
				mSV33_���t�g=OFF '���t�g���~
				inc(�����R���x�ACstep)			
			else
				inc(�����R���x�ACstep)						
			end if
		case 101
			if not(mSV33_���t�g) then
				if (XSW37_���t�g���~�[ and not(pnlPBXSW37_���t�g���~�[)) or passXSW37_���t�g���~�[ then
					inc(�����R���x�ACstep)
				end if
			else
				inc(�����R���x�ACstep)
			end if
		case 102
				StageDevice7tmp=StageDevice7
				SV29_�X�g�b�pstep=1
				SV30_�X�g�b�pstep=1
				MC14_�������[�^step=1
				MC15_�������[�^step=1
				MC43_��ڃR���x�Astep=1
				inc(�����R���x�ACstep)
		
		case 103
			if SV29_�X�g�b�pstep=0 and SV30_�X�g�b�pstep=0 and MC14_�������[�^step=0 and MC15_�������[�^step=0 and MC43_��ڃR���x�Astep=0 then
				inc(�����R���x�ACstep)
			end if			
		
		case 104

		
			�����R���x�AB�r�o�v��=OFF
			
			
			�Ȃ炵����=OFF
			�Ȃ炵�r�o�v��=OFF
			
			�t�^�킹����=OFF
			�t�^�킹�r�o�v��=OFF
			
			�����R���x�AC�r�o�v��=ON
			�����R���x�AC���쒆=OFF

			�����R���x�ACstep=1
			
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ManualInite=0 then
			mSV65_�X�g�b�p=OFF
			mSV31_�N�����v=OFF
			mSV29_�X�g�b�p=OFF
			mSV32_�N�����v=OFF
			mSV30_�X�g�b�p=OFF
		
			ManualInite=1
		end if
	
		�����R���x�ACAutoRun=OFF
		
		�����R���x�ACstep=0 '�I��

		res(timerr_MC14_�������[�^)
		res(timerr_MC15_�������[�^)
		res(timerr_MC43_��ڃR���x�A)

		
		if ldp(pnlPBMC14_�������[�^) then
			if mMC14_�������[�^ then
				mMC14_�������[�^=OFF
			else if �Ȃ炵���uOrg and �W�킹���j�b�gOrg then
				mMC14_�������[�^=ON
			end if
		end if
		

		if ldp(pnlPBMC15_�������[�^) then
			if mMC15_�������[�^ then
				mMC15_�������[�^=OFF
			else if �Ȃ炵���uOrg and �W�킹���j�b�gOrg then
				mMC15_�������[�^=ON
			end if
		end if

		if ldp(pnlPBMC43_��ڃR���x�A) then
			if mMC43_��ڃR���x�A then
				mMC43_��ڃR���x�A=OFF
			else
				mMC43_��ڃR���x�A=ON
			end if
		end if


		if ldp(pnlPBSV65_�X�g�b�p) then
			if mSV65_�X�g�b�p then
				mSV65_�X�g�b�p=OFF
			else
				mSV65_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV33_���t�g) then
			if mSV33_���t�g then
				mSV33_���t�g=OFF
			else
				mSV33_���t�g=ON
			end if
		end if
		
		if ldp(pnlPBSV31_�N�����v) then
			if mSV31_�N�����v then
				mSV31_�N�����v=OFF
			else
				mSV31_�N�����v=ON
			end if
		end if
		
		if ldp(pnlPBSV29_�X�g�b�p) then
			if mSV29_�X�g�b�p then
				mSV29_�X�g�b�p=OFF
			else
				mSV29_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV32_�N�����v) then
			if mSV32_�N�����v then
				mSV32_�N�����v=OFF
			else
				mSV32_�N�����v=ON
			end if
		end if
		
		if ldp(pnlPBSV30_�X�g�b�p) then
			if mSV30_�X�g�b�p then
				mSV30_�X�g�b�p=OFF
			else 
				mSV30_�X�g�b�p=ON
			end if
		end if
		

	end if '�����R���x�ACAutoMode and not(�����R���x�ACOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�ACOrgErr���� �z
	else
	
		if ResetFlg then
			�����R���x�ACOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else
	'tmr(��������AutoMode and MC14_�������[�^,timerr_MC14_�������[�^,#150)
	'tmr(��������AutoMode and MC15_�������[�^,timerr_MC15_�������[�^,#150)
	'tmr(��������AutoMode and MC43_��ڃR���x�A ,timerr_MC43_��ڃR���x�A,#150)
	res(timerr_MC14_�������[�^)
	res(timerr_MC15_�������[�^)
	res(timerr_MC43_��ڃR���x�A)
	
	�R���x�A�ꎞ��~��=ON
	alm�a�،x��=ON			

	
		if ResetFlg then
			almMC14_�������[�^=OFF
			almMC15_�������[�^=OFF
			almMC43_��ڃR���x�A=OFF	
			
			pauseMC43_��ڃR���x�A=OFF	

			�R���x�A�ꎞ��~=OFF
			�R���x�A�ꎞ��~��=OFF
			alm�a�،x��=OFF			
		
			errpass�R���x�A�ꎞ��~=ON
			
		end if

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		�����R���x�ACErr=ON

		pauseMC14_�������[�^=ON
		pauseMC15_�������[�^=ON
		pauseMC43_��ڃR���x�A=ON
		

		
		select case �����R���x�ACErrStep
		case 0
		case 1
			alm�a�،x��=ON			
	
			if ResetFlg then
				almMC14_�������[�^=OFF
				almMC15_�������[�^=OFF
				almMC43_��ڃR���x�A=OFF

				almXSW37_���t�g���~�[=OFF
				almXSW38_���t�g�㏸�[=OFF
				almXSW74_�X�g�b�p���~�[=OFF
				almXSW75_�X�g�b�p�㏸�[=OFF
				almXSW33_�N�����v���~�[=OFF
				almXSW34_�N�����v�㏸�[=OFF
				almXSW29_�X�g�b�p���~�[=OFF
				almXSW30_�X�g�b�p�㏸�[=OFF
				almXSW35_�N�����v���~�[=OFF
				almXSW36_�N�����v�㏸�[=OFF
				almXSW31_�X�g�b�p���~�[=OFF
				almXSW32_�X�g�b�p�㏸�[=OFF
				
				alm�a�،x��=OFF			


				inc(�����R���x�ACErrStep)
			end if
		case 2
			�����R���x�ACErr=OFF

			res(tim_XSW37_���t�g���~�[)
			res(tim_XSW38_���t�g�㏸�[)
			res(tim_XSW74_�X�g�b�p���~�[)
			res(tim_XSW75_�X�g�b�p�㏸�[)
			res(tim_XSW33_�N�����v���~�[)
			res(tim_XSW34_�N�����v�㏸�[)
			res(tim_XSW29_�X�g�b�p���~�[)
			res(tim_XSW30_�X�g�b�p�㏸�[)
			res(tim_XSW35_�N�����v���~�[)
			res(tim_XSW36_�N�����v�㏸�[)
			res(tim_XSW31_�X�g�b�p���~�[)
			res(tim_XSW32_�X�g�b�p�㏸�[)

			res(tim_notXSW37_���t�g���~�[)
			res(tim_notXSW38_���t�g�㏸�[)
			res(tim_notXSW74_�X�g�b�p���~�[)
			res(tim_notXSW75_�X�g�b�p�㏸�[)
			res(tim_notXSW33_�N�����v���~�[)
			res(tim_notXSW34_�N�����v�㏸�[)
			res(tim_notXSW29_�X�g�b�p���~�[)
			res(tim_notXSW30_�X�g�b�p�㏸�[)
			res(tim_notXSW35_�N�����v���~�[)
			res(tim_notXSW36_�N�����v�㏸�[)
			res(tim_notXSW31_�X�g�b�p���~�[)
			res(tim_notXSW32_�X�g�b�p�㏸�[)

			pauseMC14_�������[�^=OFF
			pauseMC15_�������[�^=OFF
			pauseMC43_��ڃR���x�A=OFF
		
			pauseSV65_�X�g�b�p=OFF
			pauseSV31_�N�����v=OFF
			pauseSV29_�X�g�b�p=OFF
			pauseSV32_�N�����v=OFF
			pauseSV30_�X�g�b�p=OFF
			pauseSV33_���t�g=OFF

			�����R���x�ACErrStep=0
		end select

	end if 'if �����R���x�ACErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �����R���x�ACEmgStep
	case 0
	
	case 1
		�����R���x�ACAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�ACAutoMode and ��������AutoMode ) or �����R���x�ACstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgMC14_�������[�^=ON
			EmgMC15_�������[�^=ON
			EmgMC43_��ڃR���x�A=ON

			if timstack=OFF then
			
				timdly_PH17_�����m_stack.U=timdly_PH17_�����m.U
				timdly_PH18_�t�^���m_stack.U=timdly_PH18_�t�^���m.U
				timdly_PH19_�����m_stack.U=timdly_PH19_�����m.U
				timdly_PH20_�t�^���m_stack.U=timdly_PH20_�t�^���m.U
				timdly_PH54_������g���K_stack.U=timdly_PH54_������g���K.U
				tim_SV29_�X�g�b�p_stack.U=tim_SV29_�X�g�b�p.U
				tim_SV30_�X�g�b�p_stack.U=tim_SV30_�X�g�b�p.U
				tim_MC14_�������[�^_stack.U=tim_MC14_�������[�^.U
				tim_MC15_�������[�^_stack.U=tim_MC15_�������[�^.U
				tim_MC43_��ڃR���x�A_stack.U=tim_MC43_��ڃR���x�A.U
				tim_procstep_stack.U=tim_procstep.U
				
				
				' tmr(PH17_�����m,timdly_PH17_�����m,2)
				' tmr(PH18_�t�^���m,timdly_PH18_�t�^���m,2)
				' tmr(PH19_�����m,timdly_PH19_�����m,2)
				' tmr(PH20_�t�^���m,timdly_PH20_�t�^���m,2)
				' tmr(PH54_������g���K,timdly_PH54_������g���K,2)
				' tmr(tim_SV29_�X�g�b�p,tim_SV29_�X�g�b�p_val) '�Ȃ炵�X�g�b�p�A�N�����v
				' tmr(tim_SV30_�X�g�b�p, tim_SV30_�X�g�b�p_val) '�t�^�킹�X�g�b�p�[�A�N�����v
				' tmr(tim_MC14_�������[�^,tim_MC14_�������[�^_val)
				' tmr(tim_MC15_�������[�^,tim_MC15_�������[�^_val)
				' tmr(tim_MC43_��ڃR���x�A,tim_MC43_��ڃR���x�A_val)
				' tmr(tim_procstep,tim_procstep_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC14_�������[�^=OFF
			mMC15_�������[�^=OFF
			mSV65_�X�g�b�p=OFF
			mSV33_���t�g=OFF
			mSV31_�N�����v=OFF
			mSV29_�X�g�b�p=OFF
			mSV32_�N�����v=OFF
			mSV30_�X�g�b�p=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�ACEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�ACEmgStep)
		end if
	case 3
		if (�����R���x�ACAutoMode and ��������AutoMode ) or �����R���x�ACstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				EmgMC14_�������[�^=OFF
				EmgMC15_�������[�^=OFF
				EmgMC43_��ڃR���x�A=OFF

				'�X�^�b�N�̒l���^�C�}�[���ݒl�Ƀ��X�g�A
				tim_SV29_�X�g�b�p.U=tim_SV29_�X�g�b�p_stack.U
				tim_SV30_�X�g�b�p.U=tim_SV30_�X�g�b�p_stack.U
				tim_MC14_�������[�^.U=tim_MC14_�������[�^_stack.U
				tim_MC15_�������[�^.U=tim_MC15_�������[�^_stack.U
				tim_MC43_��ڃR���x�A.U=tim_MC43_��ڃR���x�A_stack.U
				tim_procstep.U=tim_procstep_stack.U
				
				' tmr(tim_SV29_�X�g�b�p,tim_SV29_�X�g�b�p_val) '�Ȃ炵�X�g�b�p�A�N�����v
				' tmr(tim_SV30_�X�g�b�p, tim_SV30_�X�g�b�p_val) '�t�^�킹�X�g�b�p�[�A�N�����v
				' tmr(tim_MC14_�������[�^,tim_MC14_�������[�^_val)
				' tmr(tim_MC15_�������[�^,tim_MC15_�������[�^_val)
				' tmr(tim_MC43_��ڃR���x�A,tim_MC43_��ڃR���x�A_val)
				' tmr(tim_procstep,tim_procstep_val)
				
				'���o�^�C�}�[�̃��Z�b�g
				res(timdly_PH17_�����m)
				res(timdly_PH18_�t�^���m)
				res(timdly_PH19_�����m)
				res(timdly_PH20_�t�^���m)
				res(timdly_PH54_������g���K)
				
				' tmr(PH17_�����m,timdly_PH17_�����m,2)
				' tmr(PH18_�t�^���m,timdly_PH18_�t�^���m,2)
				' tmr(PH19_�����m,timdly_PH19_�����m,2)
				' tmr(PH20_�t�^���m,timdly_PH20_�t�^���m,2)
				' tmr(PH54_������g���K,timdly_PH54_������g���K,2)

				'---------------------------------
				inc(�����R���x�ACEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�ACEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�ACEmgStep=0
		�����R���x�ACEmg=OFF
	end select
		
end if 'if �����R���x�ACEmgStep=0 then
