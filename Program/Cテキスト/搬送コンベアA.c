'�����R���x�AA
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AA
'
'  	�ړ����x  161.667mm/1sec	
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������

    �����R���x�AAAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�AAAutoRun=OFF
    �����R���x�AA����=ON
    �����R���x�AAOrgErr=OFF
    �����R���x�AAErr=OFF
    �����R���x�AAEmg=OFF
    �����R���x�AAstep=0
    �����R���x�AAErrStep=0
    �����R���x�AAOrgErrStep=0
    �����R���x�AAEmgStep=0
	
	SV14_�X�g�b�pstep=0
	SV15_�X�g�b�pstep=0
	MC6_�������[�^step=0
	MC7_�������[�^step=0
	MC8_�������[�^step=0
		
	ManualInite=1

end if
'===================================================================================================================


'===================================================================================================================
'�y ���_ �z
�����R���x�AAOrg=( ((XSW12_�X�g�b�p�㏸�[ and not(pnlPBXSW12_�X�g�b�p�㏸�[)) or passXSW12_�X�g�b�p�㏸�[) or ((XSW11_�X�g�b�p���~�[ and not(pnlPBXSW11_�X�g�b�p���~�[)) or passXSW11_�X�g�b�p���~�[) ) 
�����R���x�AAOrg=�����R���x�AAOrg and (((XSW14_�X�g�b�p�㏸�[ and not(pnlPBXSW14_�X�g�b�p�㏸�[)) or passXSW14_�X�g�b�p�㏸�[) or ((XSW13_�X�g�b�p���~�[ and not(pnlPBXSW13_�X�g�b�p���~�[)) or passXSW13_�X�g�b�p���~�[))

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�AAEmg=ON
	�����R���x�AAEmgStep=1
end if


'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV14_�X�g�b�p and not(XSW12_�X�g�b�p�㏸�[) and not(pnlPBXSW12_�X�g�b�p�㏸�[), tim_notXSW12_�X�g�b�p�㏸�[,#20) '466.94ms
tmr(not(SV14_�X�g�b�p) and not(XSW11_�X�g�b�p���~�[) and not(pnlPBXSW11_�X�g�b�p���~�[),tim_notXSW11_�X�g�b�p���~�[,#20) '624.85ms
tmr(SV15_�X�g�b�p and not(XSW14_�X�g�b�p�㏸�[) and not(pnlPBXSW14_�X�g�b�p�㏸�[),tim_notXSW14_�X�g�b�p�㏸�[,#20) '417.30ms
tmr(not(SV15_�X�g�b�p) and not(XSW13_�X�g�b�p���~�[) and not(pnlPBXSW13_�X�g�b�p���~�[),tim_notXSW13_�X�g�b�p���~�[,#20) '580.42ms

'tmr(not(SV14_�X�g�b�p) and XSW12_�X�g�b�p�㏸�[, tim_XSW12_�X�g�b�p�㏸�[,#10) '466.94ms
if LDP(SV14_�X�g�b�p) and XSW12_�X�g�b�p�㏸�[ and not(pnlPBXSW12_�X�g�b�p�㏸�[) then
	SET(tim_XSW12_�X�g�b�p�㏸�[)
end if
'tmr(SV14_�X�g�b�p and XSW11_�X�g�b�p���~�[, tim_XSW11_�X�g�b�p���~�[,#10) '624.85ms
if LDF(SV14_�X�g�b�p) and XSW11_�X�g�b�p���~�[ and not(pnlPBXSW11_�X�g�b�p���~�[) then
	SET(tim_XSW11_�X�g�b�p���~�[)
end if
'tmr(not(SV15_�X�g�b�p) and XSW14_�X�g�b�p�㏸�[ ,tim_XSW14_�X�g�b�p�㏸�[,#10) '417.30ms
if LDP(SV15_�X�g�b�p) and XSW14_�X�g�b�p�㏸�[ and not(pnlPBXSW14_�X�g�b�p�㏸�[) then
	SET(tim_XSW14_�X�g�b�p�㏸�[)
end if
'tmr(SV15_�X�g�b�p and XSW13_�X�g�b�p���~�[,tim_XSW13_�X�g�b�p���~�[,#10) '580.42ms
if LDF(SV15_�X�g�b�p) and XSW13_�X�g�b�p���~�[ and not(pnlPBXSW13_�X�g�b�p���~�[) then
	SET(tim_XSW13_�X�g�b�p���~�[)
end if

'passtimXSW12_�X�g�b�p�㏸�[_val=#466
tms(SV14_�X�g�b�p , passtimXSW12_�X�g�b�p�㏸�[,passtimXSW12_�X�g�b�p�㏸�[_val) 
'passtimXSW11_�X�g�b�p���~�[_val=#624
tms(not(SV14_�X�g�b�p), passtimXSW11_�X�g�b�p���~�[,passtimXSW11_�X�g�b�p���~�[_val) 
'passtimXSW14_�X�g�b�p�㏸�[_val=#417
tms(SV15_�X�g�b�p,passtimXSW14_�X�g�b�p�㏸�[,passtimXSW14_�X�g�b�p�㏸�[_val) 
'passtimXSW13_�X�g�b�p���~�[_val=#580
tms(not(SV15_�X�g�b�p),passtimXSW13_�X�g�b�p���~�[,passtimXSW13_�X�g�b�p���~�[_val) 

tmr(mMC6_�������[�^ and not(pauseMC6_�������[�^) and not(EmgMC6_�������[�^),timerr_MC6_�������[�^,#120)
tmr(mMC7_�������[�^ and not(pauseMC7_�������[�^) and not(EmgMC7_�������[�^),timerr_MC7_�������[�^,#120)
tmr(mMC8_�������[�^ and not(pauseMC8_�������[�^) and not(EmgMC8_�������[�^),timerr_MC8_�������[�^,#120)


if ldp(timerr_MC6_�������[�^.B) then
	almMC6_�������[�^=ON

	mMC6_�������[�^=OFF
	mMC7_�������[�^=OFF
	mMC8_�������[�^=OFF

	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC7_�������[�^.B) then
	almMC7_�������[�^=ON

	mMC6_�������[�^=OFF
	mMC7_�������[�^=OFF
	mMC8_�������[�^=OFF

	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC8_�������[�^.B) then
	almMC8_�������[�^=ON

	mMC6_�������[�^=OFF
	mMC7_�������[�^=OFF
	mMC8_�������[�^=OFF

	�R���x�A�ꎞ��~=ON
	
else if ldp(almPH50_�����m or almPH51_�t�^���m) then 
	
	�R���x�A�ꎞ��~=ON

end if

if (ldp(tim_XSW12_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW12_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW12_�X�g�b�p�㏸�[) then
	pauseSV14_�X�g�b�p=ON
	almXSW12_�X�g�b�p�㏸�[=ON
	pnlPBXSW12_�X�g�b�p�㏸�[=ON
	if tim_XSW12_�X�g�b�p�㏸�[ then
		res(tim_XSW12_�X�g�b�p�㏸�[)
	end if
	�����R���x�AAErrStep=1

else if (ldp(tim_XSW11_�X�g�b�p���~�[.B) or ldp(tim_notXSW11_�X�g�b�p���~�[.B)) and not(pnlPBXSW11_�X�g�b�p���~�[) then
	almXSW11_�X�g�b�p���~�[=ON
	pnlPBXSW11_�X�g�b�p���~�[=ON
	if tim_XSW11_�X�g�b�p���~�[ then
		res(tim_XSW11_�X�g�b�p���~�[)
	end if
	�����R���x�AAErrStep=1

else if (ldp(tim_XSW14_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW14_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW14_�X�g�b�p�㏸�[) then
	pauseSV15_�X�g�b�p=ON
	almXSW14_�X�g�b�p�㏸�[=ON
	pnlPBXSW14_�X�g�b�p�㏸�[=ON
	if tim_XSW14_�X�g�b�p�㏸�[ then
		res(tim_XSW14_�X�g�b�p�㏸�[)
	end if
	�����R���x�AAErrStep=1

else if (ldp(tim_XSW13_�X�g�b�p���~�[.B) or ldp(tim_notXSW13_�X�g�b�p���~�[.B)) and not(pnlPBXSW13_�X�g�b�p���~�[) then
	almXSW13_�X�g�b�p���~�[=ON
	pnlPBXSW13_�X�g�b�p���~�[=ON
	if tim_XSW13_�X�g�b�p���~�[ then
		res(tim_XSW13_�X�g�b�p���~�[)
	end if
	�����R���x�AAErrStep=1

end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�AAAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�AAAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�AAEmg	���̏��~

'���t�^����:	���~���uB  -> ������

'���Z�Д���:   	������ -> �Z��A(�Z��B�j
'�t�^����:		������ -> �Z��B
'������:		�Z��A(�Z��B�j-> ����
'�t�^�r�o:		�Z��B -> (���t�g�j

'���r�o:		���� -> �i���t�g�j

if �����R���x�AAEmgStep=0 then  
	
	if �����R���x�AAErrStep=0  then

	if not(�R���x�A�ꎞ��~) then

	if not(�����R���x�AAOrgErr) then
	
	if (�����R���x�AAAutoMode and ��������AutoMode ) or �����R���x�AAstep<>0 then
	
		if ManualInite=1 then
			if PH1_�����m then
				mSV14_�X�g�b�p=ON
			end if

			 if PH3_�����m then
				mSV15_�X�g�b�p=ON
			end if

			ManualInite=0
		end if
		
		if not(�����R���x�AAAutoMode and ��������AutoMode ) then
			�����R���x�AAAutoRun=OFF
		end if
	
	tmr(PH1_�����m,timdly_PH1_�����m,4)
	tmr(PH2_�t�^���m,timdly_PH2_�t�^���m,4)
	tmr(PH3_�����m,timdly_PH3_�����m,4)
	tmr(PH4_�t�^���m,timdly_PH4_�t�^���m,4)
	tmr(PH5_�����m,timdly_PH5_�����m,10)
	tmr(PH6_�t�^���m,timdly_PH6_�t�^���m,10)
	tmr(PH52_�����m,timdly_PH52_�����m,4)
	tmr(PH53_�t�^���m,timdly_PH53_�t�^���m,4)	

	'-----------------------------------------------------------------
	' �X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	'SV14_�X�g�b�p 
	tmr(tim_SV14_�X�g�b�p,tim_SV14_�X�g�b�p_val)
	select case SV14_�X�g�b�pstep
	case 0
	case 1
		PH50_���N�����m=PH50_�����m '----������
		PH51_�t�^�N�����m=PH51_�t�^���m
		PH1_���N�����m=PH1_�����m '----�Z��A
		PH2_�t�^�N�����m=PH2_�t�^���m
		'PH3_�����m '----�Z��B
		'PH4_�t�^���m
		inc(SV14_�X�g�b�pstep)
	
	case 2
		if PH50_�����m or PH51_�t�^���m or PH1_�����m or PH2_�t�^���m then
			inc(SV14_�X�g�b�pstep)
		else
			SV14_�X�g�b�pstep=0
		end if
	
	case 3
		mSV14_�X�g�b�p=OFF		
		inc(SV14_�X�g�b�pstep)
		
	case 4
		if (XSW11_�X�g�b�p���~�[ and not(pnlPBXSW11_�X�g�b�p���~�[)) or passXSW11_�X�g�b�p���~�[ then
			inc(SV14_�X�g�b�pstep)
		end if				
		
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(SV14_�X�g�b�pstep)
		else if not(PH50_�����m) and not(PH51_�t�^���m) and not(PH1_�����m) and not(PH2_�t�^���m) then
			inc(SV14_�X�g�b�pstep)
		end if
		
	case 6
		tim_SV14_�X�g�b�p_val=30
		res(tim_SV14_�X�g�b�p)
		inc(SV14_�X�g�b�pstep)
		
	case 7
		if tim_SV14_�X�g�b�p.B then
			inc(SV14_�X�g�b�pstep)
		end if		

	case 8
		if not(PH50_���N�����m) and  PH51_�t�^�N�����m then
			mSV14_�X�g�b�p=OFF
		else
			mSV14_�X�g�b�p=ON		
		end if
		inc(SV14_�X�g�b�pstep)

	case 9
		if (mSV14_�X�g�b�p and ((XSW12_�X�g�b�p�㏸�[ and not(pnlPBXSW12_�X�g�b�p�㏸�[)) or passXSW12_�X�g�b�p�㏸�[)) or (not(mSV14_�X�g�b�p) and ((XSW11_�X�g�b�p���~�[ and not(pnlPBXSW11_�X�g�b�p���~�[)) or passXSW11_�X�g�b�p���~�[)) then
			inc(SV14_�X�g�b�pstep)
		end if				

	case 10
		if 	PH1_�����m and PH2_�t�^���m then  '�Z��A
			inc(���J�E���gA)
		end if

		SV14_�X�g�b�pstep=0
	
	end select	
	'--------------------------------------------
	'SV15_�X�g�b�p
	tmr(tim_SV15_�X�g�b�p, tim_SV15_�X�g�b�p_val)
	select case SV15_�X�g�b�pstep
	case 0
	case 1
		PH50_���N�����m=PH50_�����m '----������
		PH51_�t�^�N�����m=PH51_�t�^���m
		PH1_���N�����m=PH1_�����m '----�Z��A
		PH2_�t�^�N�����m=PH2_�t�^���m
		PH3_���N�����m=PH3_�����m '----�Z��B
		PH4_�t�^�N�����m=PH4_�t�^���m
		'PH52_�����m '----����
		'PH53_�t�^�N�����m=PH53_�t�^���m
		inc(SV15_�X�g�b�pstep)
	
	case 2
		if PH1_�����m or PH2_�t�^���m or PH3_�����m or PH4_�t�^���m then
			inc(SV15_�X�g�b�pstep)
		else
			SV15_�X�g�b�pstep=0
		end if

	case 3
		mSV15_�X�g�b�p=OFF
		inc(SV15_�X�g�b�pstep)

	case 4
		if (XSW13_�X�g�b�p���~�[ and not(pnlPBXSW13_�X�g�b�p���~�[)) or passXSW13_�X�g�b�p���~�[ then			
			inc(SV15_�X�g�b�pstep)
		end if
		
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(SV15_�X�g�b�pstep)
		else if not(PH3_�����m) and not(PH4_�t�^���m) then '----�Z��B
			inc(SV15_�X�g�b�pstep)
		end if
		
	case 6
		tim_SV15_�X�g�b�p_val=30
		res(tim_SV15_�X�g�b�p)
		inc(SV15_�X�g�b�pstep)
		
	case 7
		if tim_SV15_�X�g�b�p.B then
			inc(SV15_�X�g�b�pstep)
		end if	
	
	case 8
		if not(PH1_���N�����m) and PH2_�t�^�N�����m then
			mSV15_�X�g�b�p=OFF
		else
			mSV15_�X�g�b�p=ON
		end if
		inc(SV15_�X�g�b�pstep)
	
	case 9
		if (mSV15_�X�g�b�p and ((XSW14_�X�g�b�p�㏸�[ and not(pnlPBXSW14_�X�g�b�p�㏸�[)) or passXSW14_�X�g�b�p�㏸�[)) or (not(mSV15_�X�g�b�p) and ((XSW13_�X�g�b�p���~�[ and not(pnlPBXSW13_�X�g�b�p���~�[)) or passXSW13_�X�g�b�p���~�[)) then			
			inc(SV15_�X�g�b�pstep)
		end if		

	case 10
		if 	PH3_�����m and PH4_�t�^���m then  '�Z��B
			inc(���J�E���gB)
		end if
		SV15_�X�g�b�pstep=0
	
	end select
	'--------------------------------------------
	'MC6_�������[�^ [������->�Z��A]
	tmr(tim_MC6_�������[�^,tim_MC6_�������[�^_val)
	select case MC6_�������[�^step
	case 0
	case 1
		PH50_���N�����m=PH50_�����m '----������
		PH51_�t�^�N�����m=PH51_�t�^���m
		'PH1_�����m '----�Z��A
		'PH2_�t�^���m
		inc(MC6_�������[�^step)
		
	case 2
		if PH50_�����m or PH51_�t�^���m then
			inc(MC6_�������[�^step)
		else
			MC6_�������[�^step=0
		end if		

	case 3
		mMC6_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC6_�������[�^step)
	
	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(MC6_�������[�^step)
		
		else if not(PH50_�����m) and not(PH51_�t�^���m) and not(PH1_�����m) and not(PH2_�t�^���m) then
			inc(MC6_�������[�^step)
		end if
	
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(MC6_�������[�^step)		
		
		else if PH50_���N�����m or PH51_�t�^�N�����m  then
			if (PH1_�����m and timdly_PH1_�����m.B) or (PH2_�t�^���m and timdly_PH2_�t�^���m.B) then
				inc(MC6_�������[�^step)
			end if
		end if

	case 6
		mMC6_�������[�^=OFF
		inc(MC6_�������[�^step)
	
	case 7
		MC6_�������[�^step=0
		
	end select
	'--------------------------------------------
	'MC7_�������[�^	[������,�Z��A�A�Z��B,����,���t�g -> �Z��A�A�Z��B,����,���t�g ]
	tmr(tim_MC7_�������[�^,tim_MC7_�������[�^_val)
	select case MC7_�������[�^step
	case 0
	case 1
		PH50_���N�����m=PH50_�����m '----������
		PH51_�t�^�N�����m=PH51_�t�^���m
		PH1_���N�����m=PH1_�����m '----�Z��A
		PH2_�t�^�N�����m=PH2_�t�^���m
		PH3_���N�����m=PH3_�����m '----�Z��B
		PH4_�t�^�N�����m=PH4_�t�^���m
		PH52_���N�����m=PH52_�����m '----����
		PH53_�t�^�N�����m=PH53_�t�^���m
		'PH5_�����m '----�R���x�AB���t�g
		'PH6_�t�^���m
		inc(MC7_�������[�^step)
		
	
	case 2
		if PH50_�����m or PH51_�t�^���m then '----������
			inc(MC7_�������[�^step)
		else if PH1_�����m or PH2_�t�^���m then '----�Z��A
			inc(MC7_�������[�^step)
		else if PH3_�����m or PH4_�t�^���m then  '----�Z��B
			inc(MC7_�������[�^step)
		else if PH52_�����m or PH53_�t�^���m then
			inc(MC7_�������[�^step)
		else
			MC7_�������[�^step=0
		end if
	
	case 3
		if (not(PH1_���N�����m) or not(PH2_�t�^�N�����m) ) or (PH1_���N�����m and PH2_�t�^�N�����m and  ((XSW11_�X�g�b�p���~�[ and not(pnlPBXSW11_�X�g�b�p���~�[)) or passXSW11_�X�g�b�p���~�[) ) then 
			if (not(PH3_���N�����m) or not(PH4_�t�^�N�����m) ) or (PH3_���N�����m and PH4_�t�^�N�����m and  ((XSW13_�X�g�b�p���~�[ and not(pnlPBXSW13_�X�g�b�p���~�[)) or passXSW13_�X�g�b�p���~�[) ) then 
				inc(MC7_�������[�^step)
			end if
		end if	
	
	case 4
		mMC7_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC7_�������[�^step)
	
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(MC7_�������[�^step)
		
		else if not(PH50_�����m) and not(PH51_�t�^���m) then
			if not(PH1_�����m) and not(PH2_�t�^���m) then
				if not(PH3_�����m) and not(PH4_�t�^���m) then
					if not(PH52_�����m) and  not(PH53_�t�^���m) then
					inc(MC7_�������[�^step)
					end if
				end if
			end if
		end if
	
	case 6
		if errpass�R���x�A�ꎞ��~ then
			inc(MC7_�������[�^step)
		
		else if PH50_���N�����m or PH51_�t�^�N�����m then
			if PH50_���N�����m then
				if (PH1_�����m and timdly_PH1_�����m.B) then  '----�Z��A
					inc(MC7_�������[�^step)
				end if
			else if PH51_�t�^�N�����m then
				if (PH2_�t�^���m and timdly_PH2_�t�^���m.B) then
					inc(MC7_�������[�^step)
				end if
			end if
		
		else if PH1_���N�����m or PH3_���N�����m or PH52_���N�����m then
			if PH1_���N�����m then
				if (PH3_�����m and timdly_PH3_�����m.B) then '----�Z��B
					inc(MC7_�������[�^step)			
				end if			
			else if PH3_���N�����m then
				if (PH52_�����m and timdly_PH52_�����m.B) then
					inc(MC7_�������[�^step)						
				end if
			else if PH52_���N�����m then
				if (PH5_�����m and timdly_PH5_�����m.B) then
					inc(MC7_�������[�^step)
				end if
			end if
		
		else if PH2_�t�^�N�����m or PH4_�t�^�N�����m or PH53_�t�^�N�����m then
			if PH2_�t�^�N�����m then
				if (PH4_�t�^���m and timdly_PH4_�t�^���m.B) then
					inc(MC7_�������[�^step)
				end if
			else if PH4_�t�^�N�����m then			
				if (PH53_�t�^���m and timdly_PH53_�t�^���m.B) then
					inc(MC7_�������[�^step)
				end if
			else if PH53_�t�^�N�����m then
				if (PH6_�t�^���m and timdly_PH6_�t�^���m.B) then
					inc(MC7_�������[�^step)
				end if
			end if
		end if
			
	case 7
		tim_MC7_�������[�^_val=10 '�u���[�N�^�C�~���O
		res(tim_MC7_�������[�^)
		inc(MC7_�������[�^step)
	
	case 8
		if tim_MC7_�������[�^.B then
			inc(MC7_�������[�^step)
		end if
	
	case 9
		'---------------------------------------------------------
		'���ړ����m
		if errpass�R���x�A�ꎞ��~ then
			inc(MC7_�������[�^step)
		
				'�Z�Ѓ^���NA �� �Z�Ѓ^���NB                                   �Z�Ѓ^���NB �� �������j�b�g
		else if (not(PH1_���N�����m) or (PH1_���N�����m and PH3_�����m) ) and (not(PH3_���N�����m) or (PH3_���N�����m and PH52_�����m) ) then
			inc(MC7_�������[�^step)
		end if	
	
	case 10
		mMC7_�������[�^=OFF
		inc(MC7_�������[�^step)
	
	case 11
		MC7_�������[�^step=0
	
	end select
	'--------------------------------------------
	'MC8_�������[�^ [������,�Z��A�A�Z��B,����,���t�g -> ����,���t�g ]
	tmr(tim_MC8_�������[�^,tim_MC8_�������[�^_val)
	select case MC8_�������[�^step
	case 0
	case 1
		PH3_���N�����m=PH3_�����m '----�Z��B
		PH4_�t�^�N�����m=PH4_�t�^���m
		PH52_���N�����m=PH52_�����m '----����
		PH53_�t�^�N�����m=PH53_�t�^���m
		'PH5_�����m '----�R���x�AB���t�g
		'PH6_�t�^���m
		
		���������⏕=OFF
		
		inc(MC8_�������[�^step)
	
	case 2
		if PH3_�����m or PH4_�t�^���m or PH52_�����m or PH53_�t�^���m then '----����
			inc(MC8_�������[�^step)
			if (PH3_�����m or PH4_�t�^���m) and (not(PH52_�����m) and not(PH53_�t�^���m)) then
				���������⏕=ON
			end if
		else
			MC8_�������[�^step=0
		end if
	
	case 3
		mMC8_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC8_�������[�^step)

	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(MC8_�������[�^step)
		
		else if not(PH3_�����m) and not(PH4_�t�^���m) and not(PH52_�����m) and not(PH53_�t�^���m) then '----����
			inc(MC8_�������[�^step)
		end if
	

	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(MC8_�������[�^step)
			
		else if PH52_���N�����m or PH53_�t�^�N�����m then
			if (PH5_�����m and timdly_PH5_�����m.B) or (PH6_�t�^���m and timdly_PH6_�t�^���m.B) then
				SV16_���t�g�r�ostep=1
				tim_MC8_�������[�^_val=28
				res(tim_MC8_�������[�^)

				inc(MC8_�������[�^step)
			end if
		else
			inc(MC8_�������[�^step)
		end if
	
	case 6
		if errpass�R���x�A�ꎞ��~ then
			inc(MC8_�������[�^step)
			
		else if PH3_���N�����m and PH4_�t�^�N�����m then
				if (PH52_�����m and timdly_PH52_�����m.B) and (PH53_�t�^���m  and timdly_PH53_�t�^���m.B) then
					tim_MC8_�������[�^_val=8
					res(tim_MC8_�������[�^)
					inc(MC8_�������[�^step)
				end if				
		else
			tim_MC8_�������[�^_val=30
			res(tim_MC8_�������[�^)
			inc(MC8_�������[�^step)		
		end if
	
	case 7
		if tim_MC8_�������[�^.B then
			inc(MC8_�������[�^step)
		end if
	
	case 8
		mMC8_�������[�^=OFF
		inc(MC8_�������[�^step)
		
	case 9
		MC8_�������[�^step=0
						
	end select
	'--------------------------------------------
	'SV1 �r�o�^�X�N
	tmr(tim_SV16_���t�g�r�o,tim_SV16_���t�g�r�o_val)
	select case SV16_���t�g�r�ostep
	case 0
	case 1
		tim_SV16_���t�g�r�o_val=20
		res(tim_SV16_���t�g�r�o)
		inc(SV16_���t�g�r�ostep)
	
	case 2
		if tim_SV16_���t�g�r�o.B then
			inc(SV16_���t�g�r�ostep)
		end if
		
	case 3
		�����R���x�AA�r�o�v��=ON
		SV16_���t�g�r�ostep=0
	end select

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)
		tmr(PH50_�����m or PH51_�t�^���m, tim_�����������m , 20)

		select case �����R���x�AAstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�AAAutoRun then
				inc(�����R���x�AAstep)
			else 
				�����R���x�AAstep=0 '�I���ҋ@
			end if
		
		case 2
			if PH5_�����m or PH6_�t�^���m then
				�����R���x�AA���쒆=OFF
				�����R���x�AA�r�o�v��=ON
				�����R���x�AAstep=1
			else
				inc(�����R���x�AAstep)
			end if
			
		case 3
		' [ ���̔����R���x�A��~�m�F ]		
			if �����R���x�AA�r�o�v��=OFF  and (���t�^���~B�r�o�v�� or tim_�����������m.B ) then
				inc(�����R���x�AAstep)
			else
				�����R���x�AAstep=1
			end if
		
		case 4
			if �Z�Ѓ^���NA�r�o�v�� and �Z�Ѓ^���NB�r�o�v�� and �����r�o�v�� and ((XSW4_���؂�V���b�^�[��A and not(pnlPBXSW4_���؂�V���b�^�[��A)) or passXSW4_���؂�V���b�^�[��A) and ((XSW8_���؂�V���b�^�[��B and not(pnlPBXSW8_���؂�V���b�^�[��B)) or passXSW8_���؂�V���b�^�[��B) then
				inc(�����R���x�AAstep)
			else
				�����R���x�AAstep=1
			end if

			
		case 5  '���_���o
			if �����R���x�AAOrg then
				errpass�R���x�A�ꎞ��~=OFF
				inc(�����R���x�AAstep)
			else
				�����R���x�AAstep=1
			end if
			
		case 6
		
			if �c�ď������ꎞ��~ then
				�����R���x�AAstep=1
			else
				�����R���x�AAstep=100
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 100
			PH50_���N�����m=PH50_�����m '----������
			PH51_�t�^�N�����m=PH51_�t�^���m
			PH1_���N�����m=PH1_�����m '----�Z��A
			PH2_�t�^�N�����m=PH2_�t�^���m
			PH3_���N�����m=PH3_�����m '----�Z��B
			PH4_�t�^�N�����m=PH4_�t�^���m
			PH52_���N�����m=PH52_�����m '----����
			PH53_�t�^�N�����m=PH53_�t�^���m
			
			if �t�^���m and not(PH50_�����m) and PH51_�t�^���m then
				almPH51_�t�^���m=ON
				���t�^���~B�r�o�v��=OFF
				�����R���x�AAstep=1
			else if not(�t�^���m) and PH50_�����m and PH51_�t�^���m then
				almPH50_�����m=ON
				���t�^���~B�r�o�v��=OFF
				�����R���x�AAstep=1
			else 
			
				if not(PH50_�����m) and PH51_�t�^���m then '�t�^���m
						�t�^���m=ON
				else if PH50_�����m and PH51_�t�^���m then '�����m
						�t�^���m=OFF
				end if
				inc(�����R���x�AAstep)	

			end if
			

			
		case 101
			�����R���x�AA���쒆=ON
			SV14_�X�g�b�pstep=1
			SV15_�X�g�b�pstep=1
			MC6_�������[�^step=1
			MC7_�������[�^step=1
			MC8_�������[�^step=1

			���t�^���~B�r�o�v��=OFF
			inc(�����R���x�AAstep)
		
		case 102
			if 	SV14_�X�g�b�pstep=0 and SV15_�X�g�b�pstep=0	and MC6_�������[�^step=0 and MC7_�������[�^step=0 and MC8_�������[�^step=0 then
				mMC6_�������[�^=OFF
				mMC7_�������[�^=OFF
				mMC8_�������[�^=OFF
				
				inc(�����R���x�AAstep)
			end if		

		case 103
			StageDevice4=StageDevice3
			StageDevice3=StageDevice2
			StageDevice2=StageDevice1
			StageDevice1=StageDevice0
			
			
			'----------------------------------------------------------------------------
			'---- �z�ăC���^�[�o�� ----
			'----------------------------------------------------------------------------
			if �ق���A�����֎~ then
				�z�ăC���^�[�o���ݒ�l=�z�ăC���^�[�o���z�Đݒ�l+�z�ăC���^�[�o�������ݒ�l


				if (IND_���ђ� and IND_�z�Ē�) and PH1_�����m and PH2_�t�^���m then
					inc(�z�ăC���^�[�o��CNT)
				end if
		
				
				if (IND_���ђ� and IND_�z�Ē�) and �z�ăC���^�[�o���z�Đݒ�l>0 and �z�ăC���^�[�o�������ݒ�l>0 then	
					if �z�ăC���^�[�o��CNT < �z�ăC���^�[�o���ݒ�l then
						if �z�ăC���^�[�o��CNT >= �z�ăC���^�[�o���z�Đݒ�l then
							�z�ăC���^�[�o���֎~=ON
						end if
					else
						�z�ăC���^�[�o��CNT=0
						�z�ăC���^�[�o���֎~=OFF		
					end if			
				else
					�z�ăC���^�[�o��CNT=0
					�z�ăC���^�[�o���֎~=OFF		
				end if
				
			else
				�z�ăC���^�[�o��CNT=0
				�z�ăC���^�[�o���֎~=OFF					
			end if
			'----------------------------------------------------------------------------			
			if �z�ďI���t���O then
				if PH1_�����m and PH2_�t�^���m then
					inc(���Όx���܂ł̎c����)
					inc(��������)
				end if
			else
				���Όx���܂ł̎c����=0
				��������=0
			end if

			inc(�����R���x�AAstep)

		case 104
		
			�Z�Ѓ^���NA�r�o�v��=OFF
			�Z�Ѓ^���NB�r�o�v��=OFF
			�����r�o�v��=OFF
			�z�Ċ���A=OFF
			�z�Ċ���B=OFF
			��������=OFF

			�����R���x�AA���쒆=OFF
			�����R���x�AAstep=1
			

		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else
		if ManualInite=0 then
			mSV14_�X�g�b�p=OFF
			mSV15_�X�g�b�p=OFF
			ManualInite=1
		end if
		
		�����R���x�AAAutoRun=OFF
		
		�����R���x�AAstep=0 '�I��

		res(timerr_MC6_�������[�^)
		res(timerr_MC7_�������[�^)
		res(timerr_MC8_�������[�^)
		
		if ldp(pnlPBMC6_�������[�^) then
			if mMC6_�������[�^ then
				mMC6_�������[�^=OFF
			else
				mMC6_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC7_�������[�^) then
			if mMC7_�������[�^ then
				mMC7_�������[�^=OFF
			else
				mMC7_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC8_�������[�^) then
			if mMC8_�������[�^ then
				mMC8_�������[�^=OFF
			else
				mMC8_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBSV14_�X�g�b�p) then
			if mSV14_�X�g�b�p then
				mSV14_�X�g�b�p=OFF
			else
				mSV14_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV15_�X�g�b�p) then
			if mSV15_�X�g�b�p then
				mSV15_�X�g�b�p=OFF
			else
				mSV15_�X�g�b�p=ON
			end if
		end if
					
	end if '�����R���x�AAAutoMode and not(�����R���x�AAOrgErrStep)
	'===================================================================================================================
	'�y �����R���x�AAOrgErr���� �z
	else

		if ResetFlg then
			�����R���x�AAOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'�y �����R���x�AA�ꎞ��~���� �z
	else 

		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON			

	
		if ResetFlg then
		
			almPH50_�����m=OFF
			almPH51_�t�^���m=OFF

			almMC6_�������[�^=OFF
			almMC7_�������[�^=OFF
			almMC8_�������[�^=OFF

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

		�����R���x�AAErr=ON

		pauseMC6_�������[�^=ON
		pauseMC7_�������[�^=ON
		pauseMC8_�������[�^=ON
		pauseMC11_�������[�^=ON
		


		select case �����R���x�AAErrStep
		case 0
		case 1
			alm�a�،x��=ON			
	
			if ResetFlg then
				almMC6_�������[�^=OFF
				almMC7_�������[�^=OFF
				almMC8_�������[�^=OFF

				almXSW12_�X�g�b�p�㏸�[=OFF
				almXSW11_�X�g�b�p���~�[=OFF
				almXSW14_�X�g�b�p�㏸�[=OFF
				almXSW13_�X�g�b�p���~�[=OFF

				alm�a�،x��=OFF			

				inc(�����R���x�AAErrStep)
			end if
		case 2
			�����R���x�AAErr=OFF

			res(tim_XSW12_�X�g�b�p�㏸�[.B)
			res(tim_XSW11_�X�g�b�p���~�[.B)
			res(tim_XSW14_�X�g�b�p�㏸�[.B)
			res(tim_XSW13_�X�g�b�p���~�[.B)

			res(tim_notXSW12_�X�g�b�p�㏸�[.B)
			res(tim_notXSW11_�X�g�b�p���~�[.B)
			res(tim_notXSW14_�X�g�b�p�㏸�[.B)
			res(tim_notXSW13_�X�g�b�p���~�[.B)

			pauseMC6_�������[�^=OFF
			pauseMC7_�������[�^=OFF
			pauseMC8_�������[�^=OFF
			pauseMC11_�������[�^=OFF
			
			pauseSV14_�X�g�b�p=OFF
			pauseSV15_�X�g�b�p=OFF


			�����R���x�AAErrStep=0
		end select

	end if 'if �����R���x�AAErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �����R���x�AAEmgStep
	case 0
		
	case 1
		�����R���x�AAAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		
		'�������s����
		if (�����R���x�AAAutoMode and ��������AutoMode ) or �����R���x�AAstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			
			'�������s�ŋ쓮���Ă��郂�[�^ MC ���~
			
			EmgMC6_�������[�^=ON
			EmgMC7_�������[�^=ON
			EmgMC8_�������[�^=ON

			if timstack=OFF then
				
				'���ݒl���X�^�b�N�ɋL��
				timdly_PH1_�����m_stack.U=timdly_PH1_�����m.U
				timdly_PH2_�t�^���m_stack.U=timdly_PH2_�t�^���m.U
				timdly_PH3_�����m_stack.U=timdly_PH3_�����m.U
				timdly_PH4_�t�^���m_stack.U=timdly_PH4_�t�^���m.U
				timdly_PH5_�����m_stack.U=timdly_PH5_�����m.U
				timdly_PH6_�t�^���m_stack.U=timdly_PH6_�t�^���m.U
				timdly_PH52_�����m_stack.U=timdly_PH52_�����m.U
				timdly_PH53_�t�^���m_stack.U=timdly_PH53_�t�^���m.U
				tim_SV14_�X�g�b�p_stack.U=tim_SV14_�X�g�b�p.U
				tim_SV15_�X�g�b�p_stack.U=tim_SV15_�X�g�b�p.U
				tim_MC6_�������[�^_stack.U=tim_MC6_�������[�^.U
				tim_MC7_�������[�^_stack.U=tim_MC7_�������[�^.U
				tim_MC8_�������[�^_stack.U=tim_MC8_�������[�^.U
				tim_SV16_���t�g�r�o_stack.U=tim_SV16_���t�g�r�o.U
				tim_procstep_stack.U=tim_procstep.U
				tim_�����������m_stack.U=tim_�����������m.U
				
				
				' tmr(PH1_�����m,timdly_PH1_�����m,4)
				' tmr(PH2_�t�^���m,timdly_PH2_�t�^���m,4)
				' tmr(PH3_�����m,timdly_PH3_�����m,4)
				' tmr(PH4_�t�^���m,timdly_PH4_�t�^���m,4)
				' tmr(PH5_�����m,timdly_PH5_�����m,10)
				' tmr(PH6_�t�^���m,timdly_PH6_�t�^���m,10)
				' tmr(PH52_�����m,timdly_PH52_�����m,4)
				' tmr(PH53_�t�^���m,timdly_PH53_�t�^���m,4)	
				' tmr(tim_SV14_�X�g�b�p,tim_SV14_�X�g�b�p_val)
				' tmr(tim_SV15_�X�g�b�p, tim_SV15_�X�g�b�p_val)
				' tmr(tim_MC6_�������[�^,tim_MC6_�������[�^_val)
				' tmr(tim_MC7_�������[�^,tim_MC7_�������[�^_val)
				' tmr(tim_MC8_�������[�^,tim_MC8_�������[�^_val)
				' tmr(tim_SV16_���t�g�r�o,tim_SV16_���t�g�r�o_val)
				' tmr(tim_procstep,tim_procstep_val)
				' tmr(PH50_�����m or PH51_�t�^���m, tim_�����������m , 20)
				
				
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			
			'�蓮��ON/OFF���Ă���f�o�C�X�����ׂ�OFF�ɂ���
			
			mMC6_�������[�^=OFF
			mMC7_�������[�^=OFF
			mMC8_�������[�^=OFF
			mSV14_�X�g�b�p=OFF
			mSV15_�X�g�b�p=OFF
			mSV16_���t�g=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�AAEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�AAEmgStep)
		end if
	case 3
		
		'�������s����

		if (�����R���x�AAAutoMode and ��������AutoMode ) or �����R���x�AAstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------

				'�������s�ŋ쓮���Ă��郂�[�^ MC �������[�X

				EmgMC6_�������[�^=OFF
				EmgMC7_�������[�^=OFF
				EmgMC8_�������[�^=OFF

				'�X�^�b�N�̒l���^�C�}�[���ݒl�Ƀ��X�g�A
				tim_SV14_�X�g�b�p.U=tim_SV14_�X�g�b�p_stack.U
				tim_SV15_�X�g�b�p.U=tim_SV15_�X�g�b�p_stack.U
				tim_MC6_�������[�^.U=tim_MC6_�������[�^_stack.U
				tim_MC7_�������[�^.U=tim_MC7_�������[�^_stack.U
				tim_MC8_�������[�^.U=tim_MC8_�������[�^_stack.U
				tim_SV16_���t�g�r�o.U=tim_SV16_���t�g�r�o_stack.U
				tim_procstep.U=tim_procstep_stack.U
				' tmr(tim_SV14_�X�g�b�p,tim_SV14_���[�^_val)
				' tmr(tim_MC7_�������[�^,tim_MC7_�������[�^_val)
				' tmr(tim_MC8_�������[�^,tim_MC8_�������[�^_val)
				' tmr(tim_SV16_���t�g�r�o,tim_SV16_���t�g�r�o_val)
				' tmr(tim_procstep,tim_procstep_val)
				
				'���o�^�C�}�[�̃��Z�b�g
				res(timdly_PH1_�����m)
				res(timdly_PH2_�t�^���m)
				res(timdly_PH3_�����m)
				res(timdly_PH4_�t�^���m)
				res(timdly_PH5_�����m)
				res(timdly_PH6_�t�^���m)
				res(timdly_PH52_�����m)
				res(timdly_PH53_�t�^���m)
				res(tim_�����������m)
				
				' tmr(PH1_�����m,timdly_PH1_�����m,4)
				' tmr(PH2_�t�^���m,timdly_PH2_�t�^���m,4)
				' tmr(PH3_�����m,timdly_PH3_�����m,4)
				' tmr(PH4_�t�^���m,timdly_PH4_�t�^���m,4)
				' tmr(PH5_�����m,timdly_PH5_�����m,10)
				' tmr(PH6_�t�^���m,timdly_PH6_�t�^���m,10)
				' tmr(PH52_�����m,timdly_PH52_�����m,4)
				' tmr(PH53_�t�^���m,timdly_PH53_�t�^���m,4)	
				' tmr(PH50_�����m or PH51_�t�^���m, tim_�����������m , 20)
				'---------------------------------
				inc(�����R���x�AAEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�AAEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�AAEmgStep=0
		�����R���x�AAEmg=OFF
	end select
		
end if 'if �����R���x�AAEmgStep=0 then
