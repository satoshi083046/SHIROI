'���t�^���~���uB
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	���t�^���~���uB
'	
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    ���t�^���~���uBAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���t�^���~���uBAutoRun=OFF
    ���t�^���~���uB����=ON
    ���t�^���~���uBOrgErr=OFF
    ���t�^���~���uBErr=OFF
    ���t�^���~���uBEmg=OFF
    ���t�^���~���uBstep=0
    ���t�^���~���uBErrStep=0
    ���t�^���~���uBOrgErrStep=0
    ���t�^���~���uBEmgStep=0
	
	MC32_�������[�^step=0
	MC11_�������[�^step=0
	MC11_�������[�^�r�ostep=0
	
	
end if
'===================================================================================================================
'�y ���_ �z
���t�^���~���uBOrg=((XSW18_���t�g�㏸�[ and not(pnlPBXSW18_���t�g�㏸�[)) or passXSW18_���t�g�㏸�[) or ((XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[)) or passXSW17_���t�g���~�[)

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	���t�^���~���uBEmg=ON
	���t�^���~���uBEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV20_���t�g�㏸ and not(XSW18_���t�g�㏸�[) and not(pnlPBXSW18_���t�g�㏸�[), tim_notXSW18_���t�g�㏸�[,#60) '3590.35ms
tmr(SV100_���t�g���~ and not(XSW17_���t�g���~�[) and not(pnlPBXSW17_���t�g���~�[), tim_notXSW17_���t�g���~�[,#60) '3696.96ms

'tmr(SV100_���t�g���~ and XSW18_���t�g�㏸�[, tim_XSW18_���t�g�㏸�[,#10) '3590.35ms
if LDP(SV20_���t�g�㏸) and XSW18_���t�g�㏸�[ and XSW17_���t�g���~�[ and not(pnlPBXSW18_���t�g�㏸�[) then
	SET(tim_XSW18_���t�g�㏸�[)
end if
'tmr(SV20_���t�g�㏸ and XSW17_���t�g���~�[, tim_XSW17_���t�g���~�[,#10) '3696.96ms
if LDP(SV100_���t�g���~) and XSW18_���t�g�㏸�[ and XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[) then
	SET(tim_XSW17_���t�g���~�[)
end if

if SV20_���t�g�㏸ then
	KeepSV20_���t�g�㏸=ON
	KeepSV100_���t�g���~=OFF
else if SV100_���t�g���~ then
	KeepSV20_���t�g�㏸=OFF
	KeepSV100_���t�g���~=ON
end if

'passtimXSW18_���t�g�㏸�[_val=#3590
tms(KeepSV20_���t�g�㏸, passtimXSW18_���t�g�㏸�[,passtimXSW18_���t�g�㏸�[_val) 

'passtimXSW17_���t�g���~�[_val=#3696
tms(KeepSV100_���t�g���~, passtimXSW17_���t�g���~�[,passtimXSW17_���t�g���~�[_val) 

tmr((mMC11_�������[�^ or ejectMC11_�������[�^) and not(pauseMC11_�������[�^) and not(EmgMC11_�������[�^), timerr_MC11_�������[�^,#80)
tmr(mMC32_�������[�^ and not(pauseMC32_�������[�^) and not(EmgMC32_�������[�^), timerr_MC32_�������[�^,#90)
tmr(ejectMC6_�������[�^ and not(pauseMC6_�������[�^) and not(EmgMC6_�������[�^),timerr_MC6_�������[�^,#90)

if ldp(timerr_MC11_�������[�^.B) then
	almMC11_�������[�^=ON
	
	mMC11_�������[�^=OFF
	mMC32_�������[�^=OFF
	ejectMC6_�������[�^=OFF

	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC32_�������[�^.B) then
	almMC32_�������[�^=ON
	
	mMC11_�������[�^=OFF
	mMC32_�������[�^=OFF
	ejectMC6_�������[�^=OFF

	�R���x�A�ꎞ��~=ON
	
else if ldp(timerr_MC6_�������[�^.B) then
	almMC6_�������[�^=ON
	
	mMC11_�������[�^=OFF
	mMC32_�������[�^=OFF
	ejectMC6_�������[�^=OFF
	
	�R���x�A�ꎞ��~=ON

end if


if (ldp(tim_XSW18_���t�g�㏸�[.B) or ldp(tim_notXSW18_���t�g�㏸�[.B)) and not(pnlPBXSW18_���t�g�㏸�[) then
	if ���t�^���~���uBstep>0 and tim_notXSW18_���t�g�㏸�[.B then
		mSV20_���t�g�㏸=OFF
		mSV100_���t�g���~=ON
	end if
	almXSW18_���t�g�㏸�[=ON
	pnlPBXSW17_���t�g���~�[=ON
	pnlPBXSW18_���t�g�㏸�[=ON
	if tim_XSW18_���t�g�㏸�[ then
		res(tim_XSW18_���t�g�㏸�[)
	end if
	���t�^���~���uBErrStep=1

else if (ldp(tim_XSW17_���t�g���~�[.B) or ldp(tim_notXSW17_���t�g���~�[.B)) and not(pnlPBXSW17_���t�g���~�[) then
	if ���t�^���~���uBstep>0 and tim_notXSW17_���t�g���~�[.B then
		mSV20_���t�g�㏸=ON
		mSV100_���t�g���~=OFF
	end if
	almXSW17_���t�g���~�[=ON
	pnlPBXSW17_���t�g���~�[=ON
	pnlPBXSW18_���t�g�㏸�[=ON
	if tim_XSW17_���t�g���~�[ then
		res(tim_XSW17_���t�g���~�[)
	end if
	���t�^���~���uBErrStep=1

end if


'===================================================================================================================
'���m�^�C�}�[

TMR(PH50_�����m,timdly_PH50_�����m,4)
TMR(PH51_�t�^���m,timdly_PH51_�t�^���m,4)

tmr(PH39_�����m,timdly_PH39_�����m,4)
tmr(PH40_�t�^���m,timdly_PH40_�t�^���m,4)
tmr(not(PH39_�����m),timnotdly_PH39_�����m,4)
tmr(not(PH40_�t�^���m),timnotdly_PH40_�t�^���m,4)


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���t�^���~���uBAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���t�^���~���uBAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���t�^���~���uBEmg	���̏��~


if ���t�^���~���uBEmgStep=0 then  
	
	if ���t�^���~���uBErrStep=0  then
	
	if not(�R���x�A�ꎞ��~) then

	if not(���t�^���~���uBOrgErr) then

		
	'------------------------------------------------------------------------------------------------
	'MC32_�������[�^
	tmr(tim_MC32_�������[�^,tim_MC32_�������[�^_val)
	
	select case MC32_�������[�^step
	
	case 0
	
	case 1
		mMC32_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC32_�������[�^step)

	case 2
		if errpass�R���x�A�ꎞ��~ then
				inc(MC32_�������[�^step)
		
		else if not(PH9_�����m) and not(PH10_�t�^���m) then
				inc(MC32_�������[�^step)
		end if

	case 3
		if errpass�R���x�A�ꎞ��~ then
				inc(MC32_�������[�^step)
				
		else if PH39_�����m or PH40_�t�^���m then
			tim_MC32_�������[�^_val=1 '���[�^��~�^�C�~���O
			res(tim_MC32_�������[�^)
			inc(MC32_�������[�^step)
		end if
	
	case 4
		if tim_MC32_�������[�^.B then
			inc(MC32_�������[�^step)
		end if
		
	case 5
		mMC32_�������[�^=OFF
		inc(MC32_�������[�^step)
	
	case 6
		MC32_�������[�^step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC11_�������[�^
	tmr(tim_MC11_�������[�^,tim_MC11_�������[�^_val)
	
	select case MC11_�������[�^step	
	case 0
	case 1
		mMC11_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC11_�������[�^step)

	case 2
		if errpass�R���x�A�ꎞ��~ then
			inc(MC11_�������[�^step)
			
		else if not(PH9_�����m) and not(PH10_�t�^���m) then
				inc(MC11_�������[�^step)
		end if
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(MC11_�������[�^step)
	
		else if PH39_�����m or PH40_�t�^���m then
			if �������� or PH39_�����m then
				tim_MC11_�������[�^_val=9 '���[�^��~�^�C�~���O
			else if not(��������) or PH40_�t�^���m then
				tim_MC11_�������[�^_val=5 '���[�^��~�^�C�~���O
			end if			
			
			res(tim_MC11_�������[�^)
			inc(MC11_�������[�^step)
		end if
	
	case 4
		��������=OFF
		if tim_MC11_�������[�^.B then
			inc(MC11_�������[�^step)
		end if
		
	case 5
		mMC11_�������[�^=OFF
		inc(MC11_�������[�^step)
	
	case 6
		MC11_�������[�^step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC11_�������[�^�r�o
	tmr(tim_MC11_�������[�^�r�o,tim_MC11_�������[�^�r�o_val)
	
	select case MC11_�������[�^�r�ostep	
	case 0
	case 1
		PH39_���N�����m=PH39_�����m '----���t�^���~B
		PH40_�t�^�N�����m=PH40_�t�^���m
		'PH50_�����m '----������
		'PH51_�t�^���m
		inc(MC11_�������[�^�r�ostep)
	
	case 2
		'mSV20_���t�g=OFF
		mSV20_���t�g�㏸=OFF
		mSV100_���t�g���~=ON
		inc(MC11_�������[�^�r�ostep)
		
	case 3
		if (XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[)) or passXSW17_���t�g���~�[ then
			inc(MC11_�������[�^�r�ostep)
		end if
	
	case 4
		tim_MC11_�������[�^�r�o_val=0
		res(tim_MC11_�������[�^�r�o)
		inc(MC11_�������[�^�r�ostep)
	
	case 5
		if tim_MC11_�������[�^�r�o.B then
			inc(MC11_�������[�^�r�ostep)
		end if
	
	case 6
		ejectMC11_�������[�^=ON
		ejectMC6_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC11_�������[�^�r�ostep)

	case 7
		if errpass�R���x�A�ꎞ��~ then
			inc(MC11_�������[�^�r�ostep)
		
		else if not(PH39_�����m) and not(PH40_�t�^���m) then
			inc(MC11_�������[�^�r�ostep)
		end if
	
	case 8
		tim_MC11_�������[�^�r�o_val=55
		res(tim_MC11_�������[�^�r�o)
		inc(MC11_�������[�^�r�ostep)
	
	case 9
		if tim_MC11_�������[�^�r�o.B then
			RES(timdly_PH50_�����m)
			RES(timdly_PH51_�t�^���m)
			inc(MC11_�������[�^�r�ostep)
		end if

	case 10
		if errpass�R���x�A�ꎞ��~ then
			inc(MC11_�������[�^�r�ostep)
		
		else if (PH50_�����m and timdly_PH50_�����m) or (PH51_�t�^���m and timdly_PH51_�t�^���m) then
			inc(MC11_�������[�^�r�ostep)
		end if
	
	case 11
		ejectMC11_�������[�^=OFF
		ejectMC6_�������[�^=OFF
		inc(MC11_�������[�^�r�ostep)
	
	case 12
		MC11_�������[�^�r�ostep=0

	end select

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
	if (���t�^���~���uBAutoMode and ��������AutoMode ) or ���t�^���~���uBstep<>0 then
	
		if not(���t�^���~���uBAutoMode and ��������AutoMode ) then
			���t�^���~���uBAutoRun=OFF
		end if


		tmr(tim_procstep,tim_procstep_val)

		select case ���t�^���~���uBstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ���t�^���~���uBAutoRun then
				inc(���t�^���~���uBstep)
			else 
				���t�^���~���uBstep=0 '�I���ҋ@
			end if
		
		case 2
			if timdly_PH39_�����m.B or timdly_PH40_�t�^���m.B then
				���t�^���~���uBstep=100 '���t�g�Ɋ��t�^����
			else if timnotdly_PH39_�����m.B and timnotdly_PH40_�t�^���m.B then 
				���t�^���~���uBstep=200 '���t�g�Ɋ��t�^�Ȃ�
			end if
		'--------------------------------------------------------------------------------------------------------------
		�f[���t�g���~]
		case 100
			���t�^���~���uB���쒆=OFF
			inc(���t�^���~���uBstep)
		
		case 101
			'mSV20_���t�g=OFF '���t�g���~
			mSV20_���t�g�㏸=OFF
			mSV100_���t�g���~=ON
			inc(���t�^���~���uBstep)
		
		case 102
			if (XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[)) or passXSW17_���t�g���~�[ then
				inc(���t�^���~���uBstep)
			end if		
	
		case 103
			���t�^���~���uBstep=110
		
		'--------------------------------------------------------------------------------------------------------------
		'�y���t�g���~�[�z
		case 110
			if ���t�^���~B�r�o�v��=OFF and �����R���x�AA���쒆=OFF  then '�����R���x�AA�����ړ��m�F
				inc(���t�^���~���uBstep)
			else
				���t�^���~���uBstep=1
			end if
			
		case 111
			if not(PH50_�����m) and not(PH51_�t�^���m) then
				MC11_�������[�^�r�ostep=1 'MC6���܂�
				inc(���t�^���~���uBstep)
			else
				���t�^���~���uBstep=1			
			end if
			
		case 112
			if MC11_�������[�^�r�ostep=0 then
	 			���t�^���~B�r�o�v��=ON  '�r�o�v��
				inc(���t�^���~���uBstep)
			end if			

		case 113
			if  not(PH39_�����m) and not(PH40_�t�^���m) then '���t�g��̊��t�^�Ȃ��m�F
				inc(���t�^���~���uBstep)
			end if
		
		case 114
			StageDevice0=StageDevice38
			StageDevice38=0
			���t�^���~���uBstep=200

		'--------------------------------------------------------------------------------------------------------------
		'[���t�g�㏸]
		case 200 '���t�g��O�ʒu�̃��[�N����			
			'mSV20_���t�g=ON '�㏸
			mSV20_���t�g�㏸=ON
			mSV100_���t�g���~=OFF
			inc(���t�^���~���uBstep)

		case 201
			if ���o���������쒆=OFF and ���o�������r�o�v�� then	
				���t�^���~���uBstep=210
			else
				���t�^���~���uBstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		'�y���t�g�㏸�[�z
		case 210
			if PH9_�����m or PH10_�t�^���m then
				if PH9_�����m and PH10_�t�^���m then
					��������=ON
				else
					��������=OFF
				end if
								
				inc(���t�^���~���uBstep)
			else
				���t�^���~���uBstep=1
			end if
		
		case 211
			if (XSW18_���t�g�㏸�[ and not(pnlPBXSW18_���t�g�㏸�[)) or passXSW18_���t�g�㏸�[ then
				errpass�R���x�A�ꎞ��~=OFF
				MC32_�������[�^step=1
				MC11_�������[�^step=1
				inc(���t�^���~���uBstep)
			end if
		
		case 212
			if MC32_�������[�^step=0 and MC11_�������[�^step=0 then
				StageDevice38=StageDevice37
				StageDevice37=0
				inc(���t�^���~���uBstep)
			end if

		case 213
			���o�������r�o�v��=OFF
			���t�^���~���uB���쒆=OFF
			���t�^���~���uBstep=1

		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 

		���t�^���~���uBAutoRun=OFF	
		���t�^���~���uBstep=0 '�I��

		'res(tim_XSW18_���t�g�㏸�[)
		'res(tim_XSW17_���t�g���~�[)

		res(timerr_MC11_�������[�^)
		res(timerr_MC32_�������[�^)
		res(timerr_MC6_�������[�^)

		if ldp(pnlPBSV20_���t�g�㏸) then
			mSV20_���t�g�㏸=ON
			mSV100_���t�g���~=OFF
		else if ldp(pnlPBSV100_���t�g���~) then		
			mSV20_���t�g�㏸=OFF
			mSV100_���t�g���~=ON
		end if
		if mSV20_���t�g�㏸ and ( (XSW18_���t�g�㏸�[ and not(pnlPBXSW18_���t�g�㏸�[)) or passXSW18_���t�g�㏸�[) then
			mSV20_���t�g�㏸=OFF
		end if
		if mSV100_���t�g���~ and ( (XSW17_���t�g���~�[ and not(pnlPBXSW17_���t�g���~�[)) or passXSW17_���t�g���~�[) then
			mSV100_���t�g���~=OFF
		end if
				
		if ldp(pnlPBMC11_�������[�^) then
			if mMC11_�������[�^ then
				mMC11_�������[�^=OFF
			else 'if XSW17_���t�g���~�[ or XSW18_���t�g�㏸�[ then
				mMC11_�������[�^=ON
			end if
		end if
		
	end if '���t�^���~���uBAutoMode and not(���t�^���~���uBOrgErrStep)

	'===================================================================================================================
	'�y ���t�^���~���uBOrgErr���� �z
	else

		if ResetFlg then
			���t�^���~���uBOrgErr=OFF
		end if
	
	end if
	
	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else
		res(timerr_MC11_�������[�^)		
		res(timerr_MC32_�������[�^)		
		res(timerr_MC6_�������[�^)		

		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON
		
		if ResetFlg then
			almMC11_�������[�^=OFF
			almMC32_�������[�^=OFF
			almMC6_�������[�^=OFF

			�R���x�A�ꎞ��~=OFF
			�R���x�A�ꎞ��~��=OFF
			alm�a�،x��=OFF
			
			errpass�R���x�A�ꎞ��~=ON
			
		end if
		
	end if



	
	'===================================================================================================================
	'�y�^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		���t�^���~���uBErr=ON

		���t�^���~���uBAutoRun=OFF	
		���t�^���~���uBstep=0 '�I��

		pauseMC11_�������[�^=ON
		pauseMC32_�������[�^=ON
		pauseMC6_�������[�^=ON

		select case ���t�^���~���uBErrStep
		case 0
		case 1
			alm�a�،x��=ON
		
			if ResetFlg then
				almXSW18_���t�g�㏸�[=OFF
				almXSW17_���t�g���~�[=OFF

				alm�a�،x��=OFF
				
				inc(���t�^���~���uBErrStep)
			end if
		case 2
			pauseMC11_�������[�^=OFF
			pauseMC32_�������[�^=OFF
			pauseMC6_�������[�^=OFF
		
			res(tim_XSW18_���t�g�㏸�[.B)
			res(tim_XSW17_���t�g���~�[.B)
			res(tim_notXSW18_���t�g�㏸�[.B)
			res(tim_notXSW17_���t�g���~�[.B)

			���o�������r�o�v��=OFF
			���t�^���~���uB���쒆=OFF
			���t�^���~���uBErr=OFF
			���t�^���~���uBErrStep=0
		end select

	end if 'if ���t�^���~���uBErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	'mMC32_�������[�^=ON
	'mMC11_�������[�^=ON
	'ejectMC11_�������[�^=ON
	'ejectMC6_�������[�^=ON

	select case ���t�^���~���uBEmgStep
	case 0
	
	case 1
		���t�^���~���uBAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (���t�^���~���uBAutoMode and ��������AutoMode ) or ���t�^���~���uBstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC32_�������[�^=ON
			pauseMC11_�������[�^=ON
			pauseMC11_�������[�^=ON
			pauseMC6_�������[�^=ON
		
			if timstack=OFF then
			
				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC32_�������[�^=OFF
			mMC11_�������[�^=OFF
			ejectMC11_�������[�^=OFF
			ejectMC6_�������[�^=OFF
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(���t�^���~���uBEmgStep)
	case 2
		if ResetFlg then
			inc(���t�^���~���uBEmgStep)
		end if
	case 3
		if (���t�^���~���uBAutoMode and ��������AutoMode ) or ���t�^���~���uBstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC32_�������[�^=OFF
				pauseMC11_�������[�^=OFF
				pauseMC11_�������[�^=OFF
				pauseMC6_�������[�^=OFF

				'---------------------------------
				inc(���t�^���~���uBEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���t�^���~���uBEmgStep)		
		end if				
	case 4
		timstack=OFF
		���t�^���~���uBEmgStep=0
		���t�^���~���uBEmg=OFF
	end select
		
end if 'if ���t�^���~���uBEmgStep=0 then
