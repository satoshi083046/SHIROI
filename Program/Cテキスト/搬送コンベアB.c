'�����R���x�AB
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AB
'
'  	�ړ����x  161.667mm/1sec
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������

	�����R���x�ABAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�ABAutoRun=OFF
    �����R���x�AB����=ON
    �����R���x�ABOrgErr=OFF
    �����R���x�ABErr=OFF
    �����R���x�ABEmg=OFF
    �����R���x�ABstep=0
    �����R���x�ABErrStep=0
    �����R���x�ABOrgErrStep=0
    �����R���x�ABEmgStep=0
	
	SV21_�X�g�b�pstep=0
	SV22_�X�g�b�pstep=0
	MC9_���[�^���[��step=0
	MC16_���[�^���[��step=0
	MC12_�������[�^step=0
	MC13_�������[�^step=0
	
	ManualInite=1
	
end if

'===================================================================================================================
'�y ���_ �z
�����R���x�ABOrg=1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�ABEmg=ON
	�����R���x�ABEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV21_�X�g�b�p and not(XSW20_�X�g�b�p�㏸�[) and not(pnlPBXSW20_�X�g�b�p�㏸�[), tim_notXSW20_�X�g�b�p�㏸�[,#20) '428.63ms
tmr(not(SV21_�X�g�b�p) and not(XSW19_�X�g�b�p���~�[) and not(pnlPBXSW19_�X�g�b�p���~�[),tim_notXSW19_�X�g�b�p���~�[,#20) '474.35ms
tmr(SV22_�X�g�b�p and not(XSW22_�X�g�b�p�㏸�[) and not(pnlPBXSW22_�X�g�b�p�㏸�[),tim_notXSW22_�X�g�b�p�㏸�[,#20) '544.79ms
tmr(not(SV22_�X�g�b�p) and not(XSW21_�X�g�b�p���~�[) and not(pnlPBXSW21_�X�g�b�p���~�[),tim_notXSW21_�X�g�b�p���~�[,#20) '480.27ms
tmr(SV65_�X�g�b�p and not(XSW75_�X�g�b�p�㏸�[) and not(pnlPBXSW75_�X�g�b�p�㏸�[), tim_notXSW75_�X�g�b�p�㏸�[,#20) '768.11ms
tmr(not(SV65_�X�g�b�p) and not(XSW74_�X�g�b�p���~�[) and not(pnlPBXSW74_�X�g�b�p���~�[),tim_notXSW74_�X�g�b�p���~�[,#20) '626.94ms
tmr(SV33_���t�g and not(XSW38_���t�g�㏸�[) and not(pnlPBXSW38_���t�g�㏸�[), tim_notXSW38_���t�g�㏸�[, #30) '654.33ms
tmr(not(SV33_���t�g) and not(XSW37_���t�g���~�[) and not(pnlPBXSW37_���t�g���~�[),tim_notXSW37_���t�g���~�[,#30) '932.62ms
tmr(SV16_���t�g and not(XSW16_���t�g�㏸�[) and not(pnlPBXSW16_���t�g�㏸�[),tim_notXSW16_���t�g�㏸�[,#30) '1171.94ms
tmr(not(SV16_���t�g) and not(XSW15_���t�g���~�[) and not(pnlPBXSW15_���t�g���~�[),tim_notXSW15_���t�g���~�[,#30) '1437.09ms

'tmr(not(SV21_�X�g�b�p) and XSW20_�X�g�b�p�㏸�[, tim_XSW20_�X�g�b�p�㏸�[,#10)
if LDP(SV21_�X�g�b�p) and XSW20_�X�g�b�p�㏸�[ and not(pnlPBXSW20_�X�g�b�p�㏸�[) then
	SET(tim_XSW20_�X�g�b�p�㏸�[)
end if
'tmr(SV21_�X�g�b�p and XSW19_�X�g�b�p���~�[,tim_XSW19_�X�g�b�p���~�[,#10)
if LDF(SV21_�X�g�b�p) and XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[) then
	SET(tim_XSW19_�X�g�b�p���~�[)
end if
'tmr(not(SV22_�X�g�b�p) and XSW22_�X�g�b�p�㏸�[,tim_XSW22_�X�g�b�p�㏸�[,#10)
if LDP(SV22_�X�g�b�p) and XSW22_�X�g�b�p�㏸�[ and not(pnlPBXSW22_�X�g�b�p�㏸�[) then
	SET(tim_XSW22_�X�g�b�p�㏸�[)
end if
'tmr(SV22_�X�g�b�p and XSW21_�X�g�b�p���~�[,tim_XSW21_�X�g�b�p���~�[,#10)
if LDF(SV22_�X�g�b�p) and XSW21_�X�g�b�p���~�[ and not(pnlPBXSW21_�X�g�b�p���~�[) then
	SET(tim_XSW21_�X�g�b�p���~�[)
end if
'tmr(not(SV65_�X�g�b�p) and XSW75_�X�g�b�p�㏸�[, tim_XSW75_�X�g�b�p�㏸�[,#10)
if LDP(SV65_�X�g�b�p) and XSW75_�X�g�b�p�㏸�[ and not(pnlPBXSW75_�X�g�b�p�㏸�[) then
	SET(tim_XSW75_�X�g�b�p�㏸�[)
end if
'tmr(SV65_�X�g�b�p and XSW74_�X�g�b�p���~�[,tim_XSW74_�X�g�b�p���~�[,#10)
if LDF(SV65_�X�g�b�p) and XSW74_�X�g�b�p���~�[ and not(pnlPBXSW74_�X�g�b�p���~�[) then
	SET(tim_XSW74_�X�g�b�p���~�[)
end if
'tmr(not(SV33_���t�g) and XSW38_���t�g�㏸�[, tim_XSW38_���t�g�㏸�[, #10)
if LDP(SV33_���t�g) and  XSW38_���t�g�㏸�[ and not(pnlPBXSW38_���t�g�㏸�[) then
	SET(tim_XSW38_���t�g�㏸�[)
end if
'tmr(SV33_���t�g and XSW37_���t�g���~�[,tim_XSW37_���t�g���~�[,#10)
if LDF(SV33_���t�g) and  XSW37_���t�g���~�[ and not(pnlPBXSW37_���t�g���~�[) then
	SET(tim_XSW37_���t�g���~�[)
end if
'tmr(not(SV16_���t�g) and XSW16_���t�g�㏸�[ ,tim_XSW16_���t�g�㏸�[,#10)
if LDP(SV16_���t�g) and XSW16_���t�g�㏸�[ and not(pnlPBXSW16_���t�g�㏸�[) then
	SET(tim_XSW16_���t�g�㏸�[)
end if
'tmr(SV16_���t�g and XSW15_���t�g���~�[,tim_XSW15_���t�g���~�[,#10)
if LDF(SV16_���t�g) and XSW15_���t�g���~�[ and not(pnlPBXSW15_���t�g���~�[) then
	SET(tim_XSW15_���t�g���~�[)
end if

'passtimXSW20_�X�g�b�p�㏸�[_val=#428
tms(SV21_�X�g�b�p, passtimXSW20_�X�g�b�p�㏸�[,passtimXSW20_�X�g�b�p�㏸�[_val)

'passtimXSW19_�X�g�b�p���~�[_val=#474
tms(not(SV21_�X�g�b�p),passtimXSW19_�X�g�b�p���~�[,passtimXSW19_�X�g�b�p���~�[_val) 

'passtimXSW22_�X�g�b�p�㏸�[_val=#544
tms(SV22_�X�g�b�p,passtimXSW22_�X�g�b�p�㏸�[,passtimXSW22_�X�g�b�p�㏸�[_val)

'passtimXSW21_�X�g�b�p���~�[_val=#480
tms(not(SV22_�X�g�b�p),passtimXSW21_�X�g�b�p���~�[,passtimXSW21_�X�g�b�p���~�[_val)

'passtimXSW16_���t�g�㏸�[_val=#1171
tms(SV16_���t�g,passtimXSW16_���t�g�㏸�[,passtimXSW16_���t�g�㏸�[_val) 

'passtimXSW15_���t�g���~�[_val=#1437
tms(not(SV16_���t�g),passtimXSW15_���t�g���~�[,passtimXSW15_���t�g���~�[_val) 

tmr(mMC9_���[�^���[�� and not(pauseMC9_���[�^���[��) and not(EmgMC9_���[�^���[��),timerr_MC9_���[�^���[��,#150)
tmr(mMC12_�������[�^ and not(pauseMC12_�������[�^) and not(EmgMC12_�������[�^),timerr_MC12_�������[�^,#150)
tmr(mMC13_�������[�^ and not(pauseMC13_�������[�^) and not(EmgMC13_�������[�^),timerr_MC13_�������[�^,#150)
tmr(mMC16_���[�^���[�� and not(pauseMC16_���[�^���[��) and not(EmgMC16_���[�^���[��),timerr_MC16_���[�^���[��,#150)


if ldp(timerr_MC9_���[�^���[��.B) then
	almMC9_���[�^���[��=ON

	mMC9_���[�^���[��=OFF
	mMC12_�������[�^=OFF
	mMC13_�������[�^=OFF
	mMC16_���[�^���[��=OFF

	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC12_�������[�^.B) then
	almMC12_�������[�^=ON

	mMC9_���[�^���[��=OFF
	mMC12_�������[�^=OFF
	mMC13_�������[�^=OFF
	mMC16_���[�^���[��=OFF

	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC13_�������[�^.B) then
	almMC13_�������[�^=ON

	mMC9_���[�^���[��=OFF
	mMC12_�������[�^=OFF
	mMC13_�������[�^=OFF
	mMC16_���[�^���[��=OFF

	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC16_���[�^���[��.B) then
	almMC16_���[�^���[��=ON

	mMC9_���[�^���[��=OFF
	mMC12_�������[�^=OFF
	mMC13_�������[�^=OFF
	mMC16_���[�^���[��=OFF

	�R���x�A�ꎞ��~=ON

end if

if (ldp(tim_XSW20_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW20_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW20_�X�g�b�p�㏸�[) then
	pauseSV21_�X�g�b�p=ON
	almXSW20_�X�g�b�p�㏸�[=ON
	pnlPBXSW20_�X�g�b�p�㏸�[=ON
	if tim_XSW20_�X�g�b�p�㏸�[ then
		res(tim_XSW20_�X�g�b�p�㏸�[)
	end if
	�����R���x�ABErrStep=1

else if (ldp(tim_XSW19_�X�g�b�p���~�[.B) or ldp(tim_notXSW19_�X�g�b�p���~�[.B)) and not(pnlPBXSW19_�X�g�b�p���~�[) then
	almXSW19_�X�g�b�p���~�[=ON
	pnlPBXSW19_�X�g�b�p���~�[=ON
	if tim_XSW19_�X�g�b�p���~�[ then
		res(tim_XSW19_�X�g�b�p���~�[)
	end if
	�����R���x�ABErrStep=1

else if (ldp(tim_XSW22_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW22_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW22_�X�g�b�p�㏸�[) then
	pauseSV22_�X�g�b�p=ON
	almXSW22_�X�g�b�p�㏸�[=ON
	pnlPBXSW22_�X�g�b�p�㏸�[=ON
	if tim_XSW22_�X�g�b�p�㏸�[ then
		res(tim_XSW22_�X�g�b�p�㏸�[)
	end if
	�����R���x�ABErrStep=1

else if (ldp(tim_XSW21_�X�g�b�p���~�[.B) or ldp(tim_notXSW21_�X�g�b�p���~�[.B)) and not(pnlPBXSW21_�X�g�b�p���~�[) then
	almXSW21_�X�g�b�p���~�[=ON
	pnlPBXSW21_�X�g�b�p���~�[=ON
	if tim_XSW21_�X�g�b�p���~�[ then
		res(tim_XSW21_�X�g�b�p���~�[)
	end if
	�����R���x�ABErrStep=1

else if �����R���x�AB���쒆 and not(�����R���x�AC���쒆) and (ldp(tim_XSW75_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW75_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW75_�X�g�b�p�㏸�[) then
	pauseSV65_�X�g�b�p=ON
	almXSW75_�X�g�b�p�㏸�[=ON
	pnlPBXSW75_�X�g�b�p�㏸�[=ON
	if tim_XSW75_�X�g�b�p�㏸�[ then
		res(tim_XSW75_�X�g�b�p�㏸�[)
	end if
	�����R���x�ABErrStep=1

else if �����R���x�AB���쒆 and not(�����R���x�AC���쒆) and (ldp(tim_XSW74_�X�g�b�p���~�[.B) or ldp(tim_notXSW74_�X�g�b�p���~�[.B)) and not(pnlPBXSW74_�X�g�b�p���~�[) then
	almXSW74_�X�g�b�p���~�[=ON
	pnlPBXSW74_�X�g�b�p���~�[=ON
	if tim_XSW74_�X�g�b�p���~�[ then
		res(tim_XSW74_�X�g�b�p���~�[)
	end if
	�����R���x�ABErrStep=1
	
else if �����R���x�AB���쒆 and not(�����R���x�AC���쒆) and (ldp(tim_XSW38_���t�g�㏸�[.B) or ldp(tim_notXSW38_���t�g�㏸�[.B)) and not(pnlPBXSW38_���t�g�㏸�[) then
	pauseSV33_���t�g=ON
	almXSW38_���t�g�㏸�[=ON
	pnlPBXSW38_���t�g�㏸�[=ON
	if tim_XSW38_���t�g�㏸�[ then
		res(tim_XSW38_���t�g�㏸�[)
	end if
	�����R���x�ABErrStep=1

else if �����R���x�AB���쒆 and not(�����R���x�AC���쒆) and (ldp(tim_XSW37_���t�g���~�[.B) or ldp(tim_notXSW37_���t�g���~�[.B)) and not(pnlPBXSW37_���t�g���~�[) then
	almXSW37_���t�g���~�[=ON
	pnlPBXSW37_���t�g���~�[=ON
	if tim_XSW37_���t�g���~�[ then
		res(tim_XSW37_���t�g���~�[)
	end if
	�����R���x�ABErrStep=1

else if (ldp(tim_XSW16_���t�g�㏸�[.B) or ldp(tim_notXSW16_���t�g�㏸�[.B)) and not(pnlPBXSW16_���t�g�㏸�[) then
	pauseSV16_���t�g=ON
	almXSW16_���t�g�㏸�[=ON
	pnlPBXSW16_���t�g�㏸�[=ON
	if tim_XSW16_���t�g�㏸�[ then
		res(tim_XSW16_���t�g�㏸�[)
	end if
	�����R���x�ABErrStep=1

else if (ldp(tim_XSW15_���t�g���~�[.B) or ldp(tim_notXSW15_���t�g���~�[.B)) and not(pnlPBXSW15_���t�g���~�[) then
	almXSW15_���t�g���~�[=ON
	pnlPBXSW15_���t�g���~�[=ON
	if tim_XSW15_���t�g���~�[ then
		res(tim_XSW15_���t�g���~�[)
	end if
	�����R���x�ABErrStep=1

end if

tmr(PH5_�����m,timdly_PH5_���N�����m,20)
tmr(PH6_�t�^���m,timdly_PH6_�t�^�N�����m,20)

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�ABAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�ABAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�ABEmg	���̏��~


if �����R���x�ABEmgStep=0 then  
	
	if �����R���x�ABErrStep=0  then

	if not(�R���x�A�ꎞ��~) then

	if not(�����R���x�ABOrgErr) then
	
	if (�����R���x�ABAutoMode and ��������AutoMode ) or �����R���x�ABstep<>0 then

	if ManualInite=1 then
		mSV21_�X�g�b�p=ON
		mSV22_�X�g�b�p=ON
		ManualInite=0
	end if

	tmr(PH11_�����m,timdly_PH11_�����m,5)
	tmr(PH12_�t�^���m,timdly_PH12_�t�^���m,5)
	tmr(PH13_�����m,timdly_PH13_�����m,5)
	tmr(PH14_�t�^���m,timdly_PH14_�t�^���m,5)
	tmr(PH15_�����m,timdly_PH15_�����m,5)
	tmr(PH16_�t�^���m,timdly_PH16_�t�^���m,5)
	
	'-----------------------------------------------------------------
	' �������[�^�A�X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	tmr(tim_SV21_�X�g�b�p,tim_SV21_�X�g�b�p_val)
	select case SV21_�X�g�b�pstep
	case 0
	case 1
		'PH11_���N�����m=PH11_�����m
		'PH12_�t�^�N�����m=PH12_�t�^���m
		
		if PH5_���N�����m or PH6_�t�^�N�����m or PH11_���N�����m or PH12_�t�^�N�����m then
			mSV21_�X�g�b�p=OFF
			inc(SV21_�X�g�b�pstep)
		else
			SV21_�X�g�b�pstep=0
		end if
	
	case 2
		if (XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[)) or passXSW19_�X�g�b�p���~�[ then
			inc(SV21_�X�g�b�pstep)
		end if
	
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(SV21_�X�g�b�pstep)
			
		else if not(PH11_�����m) and not(PH12_�t�^���m) then
			inc(SV21_�X�g�b�pstep)
		end if
	
	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(SV21_�X�g�b�pstep)
			
		else if  PH5_���N�����m or PH6_�t�^�N�����m then
			if (PH11_�����m and timdly_PH11_�����m.B) or (PH12_�t�^���m and timdly_PH12_�t�^���m.B) then
				inc(SV21_�X�g�b�pstep)
			end if
		else if PH11_���N�����m or PH12_�t�^�N�����m then
			if (PH13_�����m and timdly_PH13_�����m.B) or (PH14_�t�^���m and timdly_PH14_�t�^���m.B) then
				inc(SV21_�X�g�b�pstep)
			end if
		end if
	
	case 5
		tim_SV21_�X�g�b�p_val=0
		res(tim_SV21_�X�g�b�p)
		inc(SV21_�X�g�b�pstep)
	
	case 6
		if tim_SV21_�X�g�b�p.B then
			inc(SV21_�X�g�b�pstep)
		end if
		
	
	case 7
		mSV21_�X�g�b�p=ON
		inc(SV21_�X�g�b�pstep)

	case 8
		if (XSW20_�X�g�b�p�㏸�[ and not(pnlPBXSW20_�X�g�b�p�㏸�[)) or passXSW20_�X�g�b�p�㏸�[ then
			inc(SV21_�X�g�b�pstep)
		end if
	
	case 9
		tim_SV21_�X�g�b�p_val=0
		res(tim_SV21_�X�g�b�p)
		inc(SV21_�X�g�b�pstep)
	
	case 10
		if tim_SV21_�X�g�b�p.B then
			inc(SV21_�X�g�b�pstep)
		end if
	
	case 11
		SV21_�X�g�b�pstep=0
		
	end select	

	'--------------------------------------------
	tmr(tim_SV22_�X�g�b�p, tim_SV22_�X�g�b�p_val)
	select case SV22_�X�g�b�pstep
	case 0
	case 1
		'PH11_���N�����m=PH11_�����m
		'PH12_�t�^�N�����m=PH12_�t�^���m
		'PH13_���N�����m=PH13_�����m
		'PH14_�t�^�N�����m=PH14_�t�^���m
	
		if PH11_���N�����m or PH12_�t�^�N�����m or PH13_���N�����m or PH14_�t�^�N�����m then
			mSV22_�X�g�b�p=OFF
			inc(SV22_�X�g�b�pstep)
		else
			SV22_�X�g�b�pstep=0
		end if
	
	case 2
		if (XSW21_�X�g�b�p���~�[ and not(pnlPBXSW21_�X�g�b�p���~�[)) or passXSW21_�X�g�b�p���~�[ then
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(SV22_�X�g�b�pstep)
			
		else if not(PH13_�����m) and not(PH14_�t�^���m) then
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 4
		inc(SV22_�X�g�b�pstep)
	
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(SV22_�X�g�b�pstep)
			
		else if PH13_���N�����m or PH14_�t�^�N�����m then
			if (PH15_�����m and timdly_PH15_�����m.B) or (PH16_�t�^���m and timdly_PH16_�t�^���m.B) then
				tim_SV22_�X�g�b�p_val=25
				res(tim_SV22_�X�g�b�p)
				inc(SV22_�X�g�b�pstep)
			end if
		else
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 6
		if tim_SV22_�X�g�b�p.B then
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 7
		mSV22_�X�g�b�p=ON
		inc(SV22_�X�g�b�pstep)
	
	case 8
		if (XSW22_�X�g�b�p�㏸�[ and not(pnlPBXSW22_�X�g�b�p�㏸�[)) or passXSW22_�X�g�b�p�㏸�[ then
			inc(SV22_�X�g�b�pstep)
		end if		
	
	case 9
		tim_SV22_�X�g�b�p_val=0
		res(tim_SV22_�X�g�b�p)
		inc(SV22_�X�g�b�pstep)
	
	case 10
		if tim_SV22_�X�g�b�p.B then
			inc(SV22_�X�g�b�pstep)
		end if
	
	case 11
		SV22_�X�g�b�pstep=0
	
	end select	
	'--------------------------------------------
	tmr(tim_MC9_���[�^���[��,tim_MC9_���[�^���[��_val)
	select case MC9_���[�^���[��step
	case 0
	case 1
		if  PH5_���N�����m or PH6_�t�^�N�����m then
			mSV16_���t�g=ON
			inc(MC9_���[�^���[��step)
		else
			MC9_���[�^���[��step=0
		end if
	
	case 2
		if (XSW16_���t�g�㏸�[ and not(pnlPBXSW16_���t�g�㏸�[)) or passXSW16_���t�g�㏸�[ then
			inc(MC9_���[�^���[��step)
		end if

	case 3
		mMC9_���[�^���[��=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC9_���[�^���[��step)

	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(MC9_���[�^���[��step)		
		
		else if not(PH5_�����m) and not(PH11_�����m) and not(PH12_�t�^���m) then
			inc(MC9_���[�^���[��step)
		end if
	
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(MC9_���[�^���[��step)		

		else if PH5_���N�����m or PH6_�t�^�N�����m then
			if (PH11_�����m and timdly_PH11_�����m.B) or (PH12_�t�^���m and timdly_PH12_�t�^���m.B) then
				inc(MC9_���[�^���[��step)
			end if
		end if
	
	case 6
		mMC9_���[�^���[��=OFF
		inc(MC9_���[�^���[��step)
	
	case 7
		tim_MC9_���[�^���[��_val=0
		res(tim_MC9_���[�^���[��)
		inc(MC9_���[�^���[��step)
	
	case 8
		if tim_MC9_���[�^���[��.B then
			inc(MC9_���[�^���[��step)
		end if
	
	case 9
		mSV16_���t�g=OFF
		inc(MC9_���[�^���[��step)
	
	case 10
		if (XSW15_���t�g���~�[ and not(pnlPBXSW15_���t�g���~�[)) or passXSW15_���t�g���~�[ then
			inc(MC9_���[�^���[��step)
		end if		
	
	case 11
		�����R���x�AA�r�o�v��=OFF
		�����R���x�AB���쒆=OFF
		MC9_���[�^���[��step=0
	end select
	
	
	'-----------------------------------------------------------------
	'MC12_�������[�^
	tmr(tim_MC12_�������[�^,tim_MC12_�������[�^_val)
	select case MC12_�������[�^step
	case 0
	case 1
		'PH11_���N�����m=PH11_�����m
		'PH12_�t�^�N�����m=PH12_�t�^���m
		
		if PH5_���N�����m or PH6_�t�^�N�����m or PH11_���N�����m or PH12_�t�^�N�����m then
			if (XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[)) or passXSW19_�X�g�b�p���~�[ then
				mMC12_�������[�^=ON
				errpass�R���x�A�ꎞ��~=OFF
				inc(MC12_�������[�^step)
			end if
		else
			MC12_�������[�^step=0
		end if
	

	case 2
		if errpass�R���x�A�ꎞ��~ then
			inc(MC12_�������[�^step)
		
		else if not(PH11_�����m) and not(PH12_�t�^���m) then
			inc(MC12_�������[�^step)
		end if
	
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(MC12_�������[�^step)
		
		else if PH5_���N�����m or PH6_�t�^�N�����m then
			if (PH11_�����m and timdly_PH11_�����m.B) or (PH12_�t�^���m and timdly_PH12_�t�^���m.B) then
				inc(MC12_�������[�^step)
			end if
		else if PH11_���N�����m or PH12_�t�^�N�����m then
			if (PH13_�����m and timdly_PH13_�����m.B) or (PH14_�t�^���m and timdly_PH14_�t�^���m.B) then
				inc(MC12_�������[�^step)
			end if
		end if
	
	case 4
		tim_MC12_�������[�^_val=10
		res(tim_MC12_�������[�^)
		inc(MC12_�������[�^step)
	
	case 5
		if tim_MC12_�������[�^.B then
			inc(MC12_�������[�^step)
		end if

	
	case 6
		mMC12_�������[�^=OFF
		inc(MC12_�������[�^step)
	
	case 7
		tim_MC12_�������[�^_val=0
		res(tim_MC12_�������[�^)
		inc(MC12_�������[�^step)
	
	case 8
		if tim_MC12_�������[�^.B then
			inc(MC12_�������[�^step)
		end if
	
	case 9
		MC12_�������[�^step=0

	end select

	'-----------------------------------------------------------------
	'MC13_�������[�^
	tmr(tim_MC13_�������[�^,tim_MC13_�������[�^_val)
	select case MC13_�������[�^step
	case 0
	case 1
		'PH11_���N�����m=PH11_�����m
		'PH12_�t�^�N�����m=PH12_�t�^���m
		'PH13_���N�����m=PH13_�����m
		'PH14_�t�^�N�����m=PH14_�t�^���m
		
		if PH11_���N�����m or PH12_�t�^�N�����m or PH13_���N�����m or PH14_�t�^�N�����m then
			if (XSW21_�X�g�b�p���~�[ and not(pnlPBXSW21_�X�g�b�p���~�[))  or passXSW21_�X�g�b�p���~�[ then
				mMC13_�������[�^=ON
				errpass�R���x�A�ꎞ��~=OFF
				inc(MC13_�������[�^step)
			end if
		else
			MC13_�������[�^step=0
		end if
	

		
	case 2
		if errpass�R���x�A�ꎞ��~ then
			inc(MC13_�������[�^step)
		
		else if not(PH13_�����m) and not(PH14_�t�^���m) then
			inc(MC13_�������[�^step)
		end if
	
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(MC13_�������[�^step)

		else if PH11_���N�����m or PH12_�t�^�N�����m then
			if (PH13_�����m and timdly_PH13_�����m.B) or (PH14_�t�^���m and timdly_PH14_�t�^���m.B) then
				inc(MC13_�������[�^step)
			end if
		else if PH13_���N�����m or PH14_�t�^�N�����m then
			if (PH15_�����m and timdly_PH15_�����m.B) or (PH16_�t�^���m and timdly_PH16_�t�^���m.B) then
				inc(MC13_�������[�^step)
			end if
		end if
	
	case 4
		tim_MC13_�������[�^_val=10
		res(tim_MC13_�������[�^)
		inc(MC13_�������[�^step)
	
	case 5
		if tim_MC13_�������[�^.B then
			inc(MC13_�������[�^step)
		end if
	
	case 6
		mMC13_�������[�^=OFF
		inc(MC13_�������[�^step)
	
	case 7
		tim_MC13_�������[�^_val=0
		res(tim_MC13_�������[�^)
		inc(MC13_�������[�^step)
	
	case 8
		if tim_MC13_�������[�^.B then
			inc(MC13_�������[�^step)
		end if
	
	case 9
		MC13_�������[�^step=0

	end select
	'--------------------------------------------
	tmr(tim_MC16_���[�^���[��,tim_MC16_���[�^���[��_val)
	select case MC16_���[�^���[��step
	case 0
	case 1
		'PH13_���N�����m=PH13_�����m
		'PH14_�t�^�N�����m=PH14_�t�^���m
		
		if PH13_���N�����m or PH14_�t�^�N�����m then
			mSV33_���t�g=ON
			mSV65_�X�g�b�p=ON
			inc(MC16_���[�^���[��step)
		else
			MC16_���[�^���[��step=0
		end if
		
	
	case 2
		if mSV33_���t�g and mSV65_�X�g�b�p then
			if ((XSW38_���t�g�㏸�[ and not(pnlPBXSW38_���t�g�㏸�[)) or passXSW38_���t�g�㏸�[) and ((XSW75_�X�g�b�p�㏸�[ and not(pnlPBXSW75_�X�g�b�p�㏸�[)) or passXSW75_�X�g�b�p�㏸�[) then
				inc(MC16_���[�^���[��step)
			end if
		else
			inc(MC16_���[�^���[��step)
		end if

	case 3
		mMC16_���[�^���[��=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC16_���[�^���[��step)
	
	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(MC16_���[�^���[��step)

		else if not(PH13_�����m) and not(PH14_�t�^���m)  then
			inc(MC16_���[�^���[��step)
		end if
	
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(MC16_���[�^���[��step)

		else if PH13_���N�����m or PH14_�t�^�N�����m then
			if (PH15_�����m and timdly_PH15_�����m.B) or (PH16_�t�^���m and timdly_PH16_�t�^���m.B) then
				inc(MC16_���[�^���[��step)
			end if
		end if
	
	case 6
		tim_MC16_���[�^���[��_val=30
		res(tim_MC16_���[�^���[��)
		inc(MC16_���[�^���[��step)
	
	case 7
		if tim_MC16_���[�^���[��.B then
			inc(MC16_���[�^���[��step)
		end if

	
	case 8
		mMC16_���[�^���[��=OFF
		inc(MC16_���[�^���[��step)
	
	case 9
		tim_MC16_���[�^���[��_val=0
		res(tim_MC16_���[�^���[��)
		inc(MC16_���[�^���[��step)
	
	case 10
		if tim_MC16_���[�^���[��.B then
			inc(MC16_���[�^���[��step)
		end if
	
	case 11
		MC16_���[�^���[��step=0
		�����R���x�AB�r�o�v��=ON
	end select
		

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		
		if not(�����R���x�ABAutoMode and ��������AutoMode ) then
			�����R���x�ABAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�ABstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�ABAutoRun then
				inc(�����R���x�ABstep)
			else 
				�����R���x�ABstep=0 '�I���ҋ@
			end if
		
		case 2
			if PH15_�����m or PH16_�t�^���m then
				�����R���x�AB���쒆=OFF
				�����R���x�AB�r�o�v��=ON
				�����R���x�ABstep=1
			else
				inc(�����R���x�ABstep)
			end if

		case 3  '���_���o
			if �����R���x�ABOrg or 1 then
				errpass�R���x�A�ꎞ��~=OFF
				inc(�����R���x�ABstep)
			else
				�����R���x�ABOrgErr=ON
			end if
				
		case 4
			if �c�ď������ꎞ��~ then
				�����R���x�ABstep=1
			else
				inc(�����R���x�ABstep)			
			end if
		
		case 5
		' [ ���̔����R���x�A��~�m�F ]
			if �����R���x�AB�r�o�v��=OFF and  �����R���x�AC���쒆=OFF and (PH13_�����m or PH14_�t�^���m) then
				�����R���x�AB���쒆=ON
				�����R���x�ABstep=100
			else if �����R���x�AA�r�o�v�� then
				�����R���x�AB���쒆=ON
				�����R���x�ABstep=200
			else
				�����R���x�ABstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 100
			if �����R���x�ABOrg or 1 then
				inc(�����R���x�ABstep)
			else
				�����R���x�ABstep=1
			end if

		case 101
			'�����R���x�AA���t�g
			PH5_���N�����m=OFF
			PH6_�t�^�N�����m=OFF
			'�ҋ@1
			PH11_���N�����m=OFF
			PH12_�t�^�N�����m=OFF
			'�ҋ@2
			PH13_���N�����m=OFF
			PH14_�t�^�N�����m=OFF
		
			tim_procstep_val=15
			res(tim_procstep)
			inc(�����R���x�ABstep)

		case 102	
			'�����R���x�AA���t�g
			PH5_���N�����m=PH5_���N�����m or timdly_PH5_���N�����m
			PH6_�t�^�N�����m=PH6_�t�^�N�����m or timdly_PH6_�t�^�N�����m
			'�ҋ@1
			PH11_���N�����m=PH11_���N�����m or PH11_�����m
			PH12_�t�^�N�����m=PH12_�t�^�N�����m or PH12_�t�^���m
			'�ҋ@2
			PH13_���N�����m=PH13_���N�����m or PH13_�����m
			PH14_�t�^�N�����m=PH14_�t�^�N�����m or PH14_�t�^���m
			
			if tim_procstep.B then
				inc(�����R���x�ABstep)
			end if		
		
		case 103
			mSV65_�X�g�b�p=ON '�㏸
			mSV33_���t�g=ON '�㏸
			inc(�����R���x�ABstep)

		case 104
			if mSV65_�X�g�b�p and mSV33_���t�g then
				if ((XSW75_�X�g�b�p�㏸�[ and not(pnlPBXSW75_�X�g�b�p�㏸�[)) or passXSW75_�X�g�b�p�㏸�[)  and ((XSW38_���t�g�㏸�[ and not(pnlPBXSW38_���t�g�㏸�[)) or passXSW38_���t�g�㏸�[) then
					inc(�����R���x�ABstep)
				end if
			else
				inc(�����R���x�ABstep)
			end if			
		

		case 105
			SV21_�X�g�b�pstep=1
			SV22_�X�g�b�pstep=1
			MC16_���[�^���[��step=1
			inc(�����R���x�ABstep)

		case 106
			tim_procstep_val=5
			res(tim_procstep)
			inc(�����R���x�ABstep)
		
		case 107
			if tim_procstep.B then
				inc(�����R���x�ABstep)
			end if
			
		case 108
			MC13_�������[�^step=1
			inc(�����R���x�ABstep)

		case 109
			tim_procstep_val=10 '<- �X�g�b�p�[�̃A�b�p�[��Ԃ̒�������
			res(tim_procstep)
			inc(�����R���x�ABstep)
		
		case 110
			if tim_procstep.B then
				inc(�����R���x�ABstep)
			end if

		case 111
			MC12_�������[�^step=1
			inc(�����R���x�ABstep)

		case 112
			tim_procstep_val=15
			res(tim_procstep)
			inc(�����R���x�ABstep)
		
		case 113
			if tim_procstep.B then
				inc(�����R���x�ABstep)
			end if
		
		case 114
			MC9_���[�^���[��step=1
			inc(�����R���x�ABstep)

		case 115
			if SV21_�X�g�b�pstep=0 and SV22_�X�g�b�pstep=0 and MC9_���[�^���[��step=0 and MC16_���[�^���[��step=0 then
				if MC12_�������[�^step=0 and MC13_�������[�^step=0 then
					inc(�����R���x�ABstep)
				end if
			end if
 
			
		case 116
			inc(�����R���x�ABstep)			
			
		case 117
			if PH13_���N�����m or PH14_�t�^�N�����m then
				if PH15_�����m or PH16_�t�^���m then
					StageDevice7=StageDevice6
				end if
			else
				StageDevice7=0
			end if
			if PH11_���N�����m or PH12_�t�^�N�����m then
				if PH13_�����m or PH14_�t�^���m then
					StageDevice6=StageDevice5
				end if
			else
			 	StageDevice6=0
			end if
			if PH5_���N�����m or PH6_�t�^�N�����m then
				if PH11_�����m or PH12_�t�^���m then
					StageDevice5=StageDevice4
				end if
			else
				StageDevice5=0
			end if
		
			�����R���x�AB���쒆=OFF
			�����R���x�AA�r�o�v��=OFF
			�����R���x�AB�r�o�v��=ON
			�����R���x�ABstep=1

		'--------------------------------------------------------------------------------------------------------------
		
		case 200
			'�����R���x�AA���t�g
			PH5_���N�����m=OFF
			PH6_�t�^�N�����m=OFF
			'�ҋ@1
			PH11_���N�����m=OFF
			PH12_�t�^�N�����m=OFF
			'�ҋ@2
			PH13_���N�����m=OFF
			PH14_�t�^�N�����m=OFF
			
			tim_procstep_val=10
			res(tim_procstep)
			inc(�����R���x�ABstep)

		case 201
			'�����R���x�AA���t�g
			PH5_���N�����m=PH5_���N�����m or timdly_PH5_���N�����m
			PH6_�t�^�N�����m=PH6_�t�^�N�����m or timdly_PH6_�t�^�N�����m
			'�ҋ@1
			PH11_���N�����m=PH11_���N�����m or PH11_�����m
			PH12_�t�^�N�����m=PH12_�t�^�N�����m or PH12_�t�^���m
			'�ҋ@2
			PH13_���N�����m=PH13_���N�����m or PH13_�����m
			PH14_�t�^�N�����m=PH14_�t�^�N�����m or PH14_�t�^���m
			
			if tim_procstep.B then		
				inc(�����R���x�ABstep)
			end if
			
		case 202
			'�ҋ@1��.�ҋ@2��
			'�ҋ@1�E2�󂫂̏ꍇ�A�ҋ@�ʒu2�Ɉړ�
		
			if (not(PH11_���N�����m) and not(PH12_�t�^�N�����m)) and (not(PH13_���N�����m) and not(PH14_�t�^�N�����m)) then
				�����R���x�ABstep=230
			'�ҋ@1��
			'�ҋ@1�󂫂̏ꍇ�A�ҋ@�ʒu1�Ɉړ�
			else if (not(PH11_���N�����m) and not(PH12_�t�^�N�����m)) and (PH13_���N�����m or PH14_�t�^�N�����m) then
				�����R���x�ABstep=250
			'�ҋ@2��
			'�ҋ@2�󂫂̏ꍇ�A�ҋ@�ʒu1����ҋ@�ʒu2�Ɉړ�
			else if (PH11_���N�����m or PH12_�t�^�N�����m) and (not(PH13_���N�����m) and not(PH14_�t�^�N�����m)) then
				�����R���x�ABstep=280
			'�ҋ@�󂫂Ȃ� �r�o�҂�
			else if (PH11_���N�����m or PH12_�t�^�N�����m) and (PH13_���N�����m or PH14_�t�^�N�����m) then
				�����R���x�AB���쒆=OFF
				�����R���x�ABstep=1
			end if
		
		
		'----------------------
		'�ҋ@2�Ɉړ�
		'----------------------
		case 230
			mSV16_���t�g=ON
			mSV21_�X�g�b�p=OFF
			mSV22_�X�g�b�p=ON

			MC9_���[�^���[��step=1

			mMC12_�������[�^=ON
			mMC13_�������[�^=ON
			errpass�R���x�A�ꎞ��~=OFF
			inc(�����R���x�ABstep)
			
		case 231
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�ABstep)			

			else if ((XSW16_���t�g�㏸�[ and not(pnlPBXSW16_���t�g�㏸�[)) or passXSW16_���t�g�㏸�[) and (((XSW19_�X�g�b�p���~�[ and not(pnlPBXSW19_�X�g�b�p���~�[)) or passXSW19_�X�g�b�p���~�[)) and ((XSW22_�X�g�b�p�㏸�[ and not(pnlPBXSW22_�X�g�b�p�㏸�[)) or passXSW22_�X�g�b�p�㏸�[) then
				inc(�����R���x�ABstep)
			end if
			
		case 232
				inc(�����R���x�ABstep)
			
		case 233
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�ABstep)			

			else if not(PH5_�����m) and not(PH6_�t�^���m) then
				inc(�����R���x�ABstep)
			end if

		case 234
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�ABstep)			

			else if (PH13_�����m and timdly_PH13_�����m) or (PH14_�t�^���m and timdly_PH14_�t�^���m) then
				inc(�����R���x�ABstep)
			end if
			
		case 235
			tim_procstep_val=20
			res(tim_procstep)
			inc(�����R���x�ABstep)
			
		case 236
			if tim_procstep.B then
				inc(�����R���x�ABstep)
			end if
			
		case 237
			mMC12_�������[�^=OFF
			mMC13_�������[�^=OFF
			mSV21_�X�g�b�p=ON
			inc(�����R���x�ABstep)
			
		case 238
			if MC9_���[�^���[��step=0 then
				inc(�����R���x�ABstep)
			end if
			
		case 239
			mSV16_���t�g=OFF
			mSV21_�X�g�b�p=ON
			mSV22_�X�g�b�p=ON
			if (XSW20_�X�g�b�p�㏸�[ and not(pnlPBXSW20_�X�g�b�p�㏸�[)) or passXSW20_�X�g�b�p�㏸�[ then
				inc(�����R���x�ABstep)
			end if
		case 240

			StageDevice6=StageDevice4

			�����R���x�AA�r�o�v��=OFF
			�����R���x�AB���쒆=OFF
			�����R���x�ABstep=1
			
			
		'----------------------
		'�ҋ@1�Ɉړ�
		'----------------------
		case 250
			mSV16_���t�g=ON
			mSV21_�X�g�b�p=ON
			mSV22_�X�g�b�p=ON
			
			MC9_���[�^���[��step=1
			mMC12_�������[�^=ON
			errpass�R���x�A�ꎞ��~=OFF
			
			inc(�����R���x�ABstep)
			
		case 251
			if ((XSW16_���t�g�㏸�[ and not(pnlPBXSW16_���t�g�㏸�[)) or passXSW16_���t�g�㏸�[) and ((XSW20_�X�g�b�p�㏸�[ and not(pnlPBXSW20_�X�g�b�p�㏸�[)) or passXSW20_�X�g�b�p�㏸�[) and ((XSW22_�X�g�b�p�㏸�[ and not(pnlPBXSW22_�X�g�b�p�㏸�[)) or passXSW22_�X�g�b�p�㏸�[) then
				inc(�����R���x�ABStep)
			end if
			
		case 252
			inc(�����R���x�ABStep)
			
		case 253
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�ABStep)

			else if not(PH5_�����m) and not(PH6_�t�^���m) then
				inc(�����R���x�ABstep)
			end if
			
		case 254
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�ABStep)

			else if (PH11_�����m and timdly_PH11_�����m) or (PH12_�t�^���m and timdly_PH12_�t�^���m) then
				inc(�����R���x�ABstep)
			end if
			
		case 255
			tim_procstep_val=5
			res(tim_procstep)
			inc(�����R���x�ABstep)
			
		case 256
			if tim_procstep.B then
				inc(�����R���x�ABstep)
			end if
			
		case 257
			mMC12_�������[�^=OFF
			inc(�����R���x�ABstep)
			
		case 258
			if MC9_���[�^���[��step=0 then
				inc(�����R���x�ABstep)
			end if
			
		case 259
			mSV16_���t�g=OFF
			mSV21_�X�g�b�p=ON
			mSV22_�X�g�b�p=ON

			if (XSW20_�X�g�b�p�㏸�[ and not(pnlPBXSW20_�X�g�b�p�㏸�[)) or passXSW20_�X�g�b�p�㏸�[ then
				inc(�����R���x�ABstep)
			end if
		case 260
			StageDevice5=StageDevice4
		
			�����R���x�AB���쒆=OFF
			�����R���x�AA�r�o�v��=OFF
			�����R���x�ABstep = 1
		
		
		'----------------------
		'�ҋ@2�Ɉړ� PH5,PH6 (Stagedevice4)-> PH12,PH14(StageDevice6)
		'----------------------
		
		case 280
			mSV22_�X�g�b�p = ON
			mMC13_�������[�^ = ON
			errpass�R���x�A�ꎞ��~=OFF
			inc(�����R���x�ABstep)
			
		case 281
			if (XSW22_�X�g�b�p�㏸�[ and not(pnlPBXSW22_�X�g�b�p�㏸�[)) or passXSW22_�X�g�b�p�㏸�[ then
				inc(�����R���x�ABstep)
			end if
			
		case 282
			SV21_�X�g�b�pstep = 1
			inc(�����R���x�ABstep)
			
		case 283
			tim_procstep_val=10 '<- �X�g�b�p�[�̃A�b�p�[��Ԃ̒�������			
			res(tim_procstep)
			inc(�����R���x�ABstep)
			
		case 284
			if tim_procstep.B then
				inc(�����R���x�ABstep)
			end if
			
		case 285
			MC12_�������[�^step = 1
			inc(�����R���x�ABstep)

		case 286
			tim_procstep_val=15 '<- �X�g�b�p�[�̃A�b�p�[��Ԃ̒�������			
			res(tim_procstep)
			inc(�����R���x�ABstep)
			
		case 287
			if tim_procstep.B then
				inc(�����R���x�ABstep)
			end if

		case 288
			MC9_���[�^���[��step = 1
			inc(�����R���x�ABstep)

		
		case 289
			if (MC9_���[�^���[��step=0) and (SV21_�X�g�b�pstep=0) and (MC12_�������[�^step = 0) then
				inc(�����R���x�ABstep)
			end if

		case 290
			mSV16_���t�g=OFF
			mSV21_�X�g�b�p=ON
			mSV22_�X�g�b�p=ON
			mMC13_�������[�^ = OFF
			inc(�����R���x�ABstep)

		case 291
			StageDevice6=StageDevice5
			StageDevice5=StageDevice4		
			�����R���x�AB���쒆=OFF
			�����R���x�AA�r�o�v��=OFF
			�����R���x�ABstep = 1
					
		end select



	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ManualInite=0 then
			mSV21_�X�g�b�p=OFF
			mSV22_�X�g�b�p=OFF
			mSV16_���t�g=OFF
			ManualInite=1
		end if
	
		�����R���x�ABAutoRun=OFF
		
		�����R���x�ABstep=0 '�I��


		res(timerr_MC9_���[�^���[��)
		res(timerr_MC12_�������[�^)
		res(timerr_MC13_�������[�^)
		res(timerr_MC16_���[�^���[��)

		
		if ldp(pnlPBMC9_���[�^���[��) then
			if mMC9_���[�^���[�� then
				mMC9_���[�^���[��=OFF
			else 'if XSW16_���t�g�㏸�[ then '�C���^�[���b�N
					mMC9_���[�^���[��=ON
			end if
		end if
		
		if ldp(pnlPBMC12_�������[�^) then
			if mMC12_�������[�^ then
				mMC12_�������[�^=OFF
			else
				mMC12_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC13_�������[�^) then
			if mMC13_�������[�^ then
				mMC13_�������[�^=OFF
			else
				mMC13_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC16_���[�^���[��) then
			if mMC16_���[�^���[�� then
				mMC16_���[�^���[��=OFF
			else 'if XSW38_���t�g�㏸�[ then '�C���^�[���b�N
				mMC16_���[�^���[��=ON
			end if
		end if
		
		if ldp(pnlPBSV21_�X�g�b�p) then
			if mSV21_�X�g�b�p then
				mSV21_�X�g�b�p=OFF
			else
				mSV21_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV22_�X�g�b�p) then
			if mSV22_�X�g�b�p then
				mSV22_�X�g�b�p=OFF
			else
				mSV22_�X�g�b�p=ON
			end if
		end if

		if ldp(pnlPBSV16_���t�g) then
			if mSV16_���t�g then
				mSV16_���t�g=OFF
			else
				mSV16_���t�g=ON
			end if
		end if
			
	end if '�����R���x�ABAutoMode and not(�����R���x�ABOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�ABOrgErr���� �z
	else

		if ResetFlg then
			�����R���x�ABOrgErr=OFF
		end if
	
	end if
	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else

		res(timerr_MC12_�������[�^)
		res(timerr_MC13_�������[�^)
		res(timerr_MC9_���[�^���[�� )
		res(timerr_MC16_���[�^���[��)

		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON			

	
		if ResetFlg then
			almMC9_���[�^���[��=OFF
			almMC12_�������[�^=OFF
			almMC13_�������[�^=OFF	
			almMC16_���[�^���[��=OFF
			
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

		�����R���x�ABErr=ON

		pauseMC9_���[�^���[��=ON
		pauseMC12_�������[�^=ON
		pauseMC13_�������[�^=ON
		pauseMC16_���[�^���[��=ON

		select case �����R���x�ABErrStep
		case 0
		case 1
			alm�a�،x��=ON
			
			if ResetFlg then
				almMC9_���[�^���[��=OFF
				almMC12_�������[�^=OFF
				almMC13_�������[�^=OFF
				almMC16_���[�^���[��=OFF

				almXSW20_�X�g�b�p�㏸�[=OFF
				almXSW19_�X�g�b�p���~�[=OFF
				almXSW22_�X�g�b�p�㏸�[=OFF
				almXSW21_�X�g�b�p���~�[=OFF
				almXSW75_�X�g�b�p�㏸�[=OFF
				almXSW74_�X�g�b�p���~�[=OFF
				almXSW38_���t�g�㏸�[=OFF
				almXSW37_���t�g���~�[=OFF
				almXSW15_���t�g���~�[=OFF
				almXSW16_���t�g�㏸�[=OFF

				alm�a�،x��=OFF

				inc(�����R���x�ABErrStep)
			end if
		case 2
			�����R���x�ABErr=OFF
			
			
			res(tim_XSW15_���t�g���~�[)
			res(tim_XSW16_���t�g�㏸�[)			
			res(tim_XSW20_�X�g�b�p�㏸�[)
			res(tim_XSW19_�X�g�b�p���~�[)
			res(tim_XSW22_�X�g�b�p�㏸�[)
			res(tim_XSW21_�X�g�b�p���~�[)
			res(tim_XSW75_�X�g�b�p�㏸�[)
			res(tim_XSW74_�X�g�b�p���~�[)
			res(tim_XSW38_���t�g�㏸�[)
			res(tim_XSW37_���t�g���~�[)

			res(tim_notXSW15_���t�g���~�[)
			res(tim_notXSW16_���t�g�㏸�[)			
			res(tim_notXSW20_�X�g�b�p�㏸�[)
			res(tim_notXSW19_�X�g�b�p���~�[)
			res(tim_notXSW22_�X�g�b�p�㏸�[)
			res(tim_notXSW21_�X�g�b�p���~�[)
			res(tim_notXSW75_�X�g�b�p�㏸�[)
			res(tim_notXSW74_�X�g�b�p���~�[)
			res(tim_notXSW38_���t�g�㏸�[)
			res(tim_notXSW37_���t�g���~�[)

			pauseMC9_���[�^���[��=OFF
			pauseMC12_�������[�^=OFF
			pauseMC13_�������[�^=OFF
			pauseMC16_���[�^���[��=OFF
			
			pauseSV21_�X�g�b�p=OFF
			pauseSV22_�X�g�b�p=OFF
			pauseSV65_�X�g�b�p=OFF
			pauseSV33_���t�g=OFF
			pauseSV16_���t�g=OFF




			�����R���x�ABErrStep=0
		end select

	end if 'if �����R���x�ABErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	

	select case �����R���x�ABEmgStep
	case 0
		
	case 1
		�����R���x�ABAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		
		'�������s����
		if (�����R���x�ABAutoMode and ��������AutoMode ) or �����R���x�ABstep<>0 then

			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------			
			
			'�������s�ŋ쓮���Ă��郂�[�^ MC ���~
			EmgMC9_���[�^���[��=ON
			EmgMC12_�������[�^=ON
			EmgMC13_�������[�^=ON
			EmgMC16_���[�^���[��=ON

			if timstack=OFF then
			
				'���ݒl���X�^�b�N�ɋL��
				timdly_PH5_���N�����m_stack.U=timdly_PH5_���N�����m.U
				timdly_PH6_�t�^�N�����m_stack.U=timdly_PH6_�t�^�N�����m.U
				timdly_PH11_�����m_stack.U=timdly_PH11_�����m.U
				timdly_PH12_�t�^���m_stack.U=timdly_PH12_�t�^���m.U
				timdly_PH13_�����m_stack.U=timdly_PH13_�����m.U
				timdly_PH14_�t�^���m_stack.U=timdly_PH14_�t�^���m.U
				timdly_PH15_�����m_stack.U=timdly_PH15_�����m.U
				timdly_PH16_�t�^���m_stack.U=timdly_PH16_�t�^���m.U
				tim_SV21_�X�g�b�p_stack.U=tim_SV21_�X�g�b�p.U
				tim_SV22_�X�g�b�p_stack.U=tim_SV22_�X�g�b�p.U
				tim_MC9_���[�^���[��_stack.U=tim_MC9_���[�^���[��.U
				tim_MC12_�������[�^_stack.U=tim_MC12_�������[�^.U
				tim_MC13_�������[�^_stack.U=tim_MC13_�������[�^.U
				tim_MC16_���[�^���[��_stack.U=tim_MC16_���[�^���[��.U
				tim_procstep_stack.U=tim_procstep.U

				
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			
			'�蓮��ON/OFF���Ă���f�o�C�X�����ׂ�OFF�ɂ���
			mMC9_���[�^���[��=OFF
			mMC12_�������[�^=OFF
			mMC13_�������[�^=OFF
			mMC16_���[�^���[��=OFF

			mSV21_�X�g�b�p=OFF
			mSV22_�X�g�b�p=OFF
			mSV16_���t�g=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�ABEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�ABEmgStep)
		end if
	case 3
		
		'�������s����

		if (�����R���x�ABAutoMode and ��������AutoMode ) or �����R���x�ABstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------

				'�������s�ŋ쓮���Ă��郂�[�^ MC �������[�X
				EmgMC9_���[�^���[��=OFF
				EmgMC12_�������[�^=OFF
				EmgMC13_�������[�^=OFF
				EmgMC16_���[�^���[��=OFF

				'�X�^�b�N�̒l���^�C�}�[���ݒl�Ƀ��X�g�A
				tim_SV21_�X�g�b�p.U=tim_SV21_�X�g�b�p_stack.U
				tim_SV22_�X�g�b�p.U=tim_SV22_�X�g�b�p_stack.U
				tim_MC9_���[�^���[��.U=tim_MC9_���[�^���[��_stack.U
				tim_MC12_�������[�^.U=tim_MC12_�������[�^_stack.U
				tim_MC13_�������[�^.U=tim_MC13_�������[�^_stack.U
				tim_MC16_���[�^���[��.U=tim_MC16_���[�^���[��_stack.U
				tim_procstep.U=tim_procstep_stack.U
				
				'���o�^�C�}�[�̃��Z�b�g
				res(timdly_PH5_���N�����m)
				res(timdly_PH6_�t�^�N�����m)
				res(timdly_PH11_�����m)
				res(timdly_PH12_�t�^���m)
				res(timdly_PH13_�����m)
				res(timdly_PH14_�t�^���m)
				res(timdly_PH15_�����m)
				res(timdly_PH16_�t�^���m)
				
				
				'---------------------------------
				inc(�����R���x�ABEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�ABEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�ABEmgStep=0
		�����R���x�ABEmg=OFF
	end select
		
end if 'if �����R���x�ABEmgStep=0 then
