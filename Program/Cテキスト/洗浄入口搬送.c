'����������
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	����������
'	
'===================================================================================================================
'
'�����]�@�֎~��
'	  ���F�J�j�܂Ɋ����������甽�]���[�^���񂳂Ȃ��B�h���@�ɂ���X�C�b�`�h�ɂ�蔽�]���I���������Ƃ��w������
'			���]���[�^���]ON�AOFF ���]���[�^�t�]ON.OFF���p�X����B
'			�����]������������=ON  ���@�ɂ���X�C�b�`�̃����v��_��
'			�h���@�ɂ���X�C�b�`�h=ON and PH45_�����m and PH46_�t�^���m �ɂ�蓮��I���B
' 	�t�^�F�ʏ�ʂ�̓�������A�ʏ�ʂ�ɏI��������B
'
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    ����������AutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ����������AutoRun=OFF
    ��������������=ON
    ����������OrgErr=OFF
    ����������Err=OFF
    ����������Emg=OFF
    ����������step=0
    ����������ErrStep=0
    ����������OrgErrStep=0
    ����������EmgStep=0
	
	MC31_���]���[�^���]step=0
	MC31_���]���[�^�t�]step=0
	MC33_�������[�^step=0
	INV1_�R���x�A���[�^���]step=0
	
end if
'===================================================================================================================
'�y ���_ �z
����������Org=LS7_�����]�@���_�ʒu or pnlPBLS7_�����]�@���_�ʒu

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	����������Emg=ON
	����������EmgStep=1
end if


'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(MC31_���]���[�^���] and not(pnlPBLS8_�����]�@���]�ʒu) ,tim_LS8_�����]�@���]�ʒu,#60)
tmr(MC31_���]���[�^�t�] and not(pnlPBLS7_�����]�@���_�ʒu),tim_LS7_�����]�@���_�ʒu,#60)
tmr(mMC33_�������[�^ and not(pauseMC33_�������[�^) and not(EmgMC33_�������[�^),timerr_MC33_�������[�^,#80)
tmr(ejectINV1_�R���x�A���[�^���] and not(pauseINV1_�R���x�A���[�^���]) and not(EmgINV1_�R���x�A���[�^���]),timerr_INV1_�R���x�A���[�^���],#80)

if ldp(timerr_MC33_�������[�^.B) then
	almMC33_�������[�^=ON
	
	mMC33_�������[�^=OFF
	ejectINV1_�R���x�A���[�^���]=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_INV1_�R���x�A���[�^���].B) then
	almINV1_�R���x�A���[�^���]=ON
	
	mMC33_�������[�^=OFF
	ejectINV1_�R���x�A���[�^���]=OFF
	
	�R���x�A�ꎞ��~=ON

end if


if (LS7_�����]�@���_�ʒu and not(pnlPBLS7_�����]�@���_�ʒu)) and (LS8_�����]�@���]�ʒu and not(pnlPBLS8_�����]�@���]�ʒu)) then
	errpassLS8_�����]�@���]�ʒu=ON
	errpassLS7_�����]�@���_�ʒu=ON
	mMC31_���]���[�^�t�]=OFF
	mMC31_���]���[�^���]=OFF
	almLS8_�����]�@���]�ʒu=ON
	almLS7_�����]�@���_�ʒu=ON
	almMC31_���]���[�^���]=ON
	almMC31_���]���[�^�t�]=ON
	
	����������ErrStep=1

else if ldp(tim_LS8_�����]�@���]�ʒu.B) then
	mMC31_���]���[�^���]=OFF
	mMC31_���]���[�^�t�]=OFF
	almMC31_���]���[�^���]=ON
	errpassLS8_�����]�@���]�ʒu=ON
	����������ErrStep=1
else if ldp(tim_LS7_�����]�@���_�ʒu.B) then
	mMC31_���]���[�^���]=OFF
	mMC31_���]���[�^�t�]=OFF
	almMC31_���]���[�^�t�]=ON
	errpassLS7_�����]�@���_�ʒu=ON
	����������ErrStep=1
end if


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ����������AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ����������AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ����������Emg	���̏��~


if ����������EmgStep=0 then  
	
	if ����������ErrStep=0  then
	
	if not(�R���x�A�ꎞ��~) then

	if not(����������OrgErr) then

	
	'------------------------------------------------------------------------------------------------
	'�����]���u���]
	tmr(tim_MC31_���]���[�^���],tim_MC31_���]���[�^���]_val)
	
	select case MC31_���]���[�^���]step
	
	case 0
	
	case 1
		mMC31_���]���[�^���]=ON
		mMC31_���]���[�^�t�]=OFF
		errpassLS8_�����]�@���]�ʒu=OFF
		inc(MC31_���]���[�^���]step)
		
	
	case 2
		if LS8_�����]�@���]�ʒu or errpassLS8_�����]�@���]�ʒu or pnlPBLS8_�����]�@���]�ʒu then
			inc(MC31_���]���[�^���]step)
		end if
	
	case 3
		mMC31_���]���[�^���]=OFF
		inc(MC31_���]���[�^���]step)
	
	case 4
		MC31_���]���[�^���]step=0
		
	end select

	'------------------------------------------------------------------------------------------------
	'�����]���u�t�]
	tmr(tim_MC31_���]���[�^�t�],tim_MC31_���]���[�^�t�]_val)
	
	select case MC31_���]���[�^�t�]step
	
	case 0
	
	case 1
		mMC31_���]���[�^���]=OFF
		mMC31_���]���[�^�t�]=ON
		errpassLS7_�����]�@���_�ʒu=OFF
		inc(MC31_���]���[�^�t�]step)

	case 2
		if LS7_�����]�@���_�ʒu or errpassLS7_�����]�@���_�ʒu or pnlPBLS7_�����]�@���_�ʒu then
			inc(MC31_���]���[�^�t�]step)
		end if

	case 3
		mMC31_���]���[�^�t�]=OFF
		inc(MC31_���]���[�^�t�]step)
		
	case 4
		MC31_���]���[�^�t�]step=0
		
	end select
	'------------------------------------------------------------------------------------------------
	'MC33_�������[�^
	tmr(tim_MC33_�������[�^,tim_MC33_�������[�^_val)
	
	select case MC33_�������[�^step
	
	case 0
	
	case 1
		mMC33_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC33_�������[�^step)

	case 2
		if errpass�R���x�A�ꎞ��~ then
			inc(MC33_�������[�^step)
		
		else if not(PH43_�����m) and not(PH44_�t�^���m) then
			inc(MC33_�������[�^step)
		end if	

	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(MC33_�������[�^step)
		
		else if PH45_�����m or PH46_�t�^���m then
			inc(MC33_�������[�^step)
		end if	

	case 4
		tim_MC33_�������[�^_val=10
		res(tim_MC33_�������[�^)
		inc(MC33_�������[�^step)
		
	case 5
		if tim_MC33_�������[�^.B then
			inc(MC33_�������[�^step)
		end if

	case 6
		mMC33_�������[�^=OFF
		inc(MC33_�������[�^step)
	
	case 7
		MC33_�������[�^step=0
	
	end select
	'------------------------------------------------------------------------------------------------
	'INV1_�R���x�A���[�^���]
	tmr(tim_INV1_�R���x�A���[�^���],tim_INV1_�R���x�A���[�^���]_val)
	tmr(tim_���H���I��,tim_���H���I��_val)
	
	select case INV1_�R���x�A���[�^���]step
	
	case 0
	
	case 1
		if �������� then
			setS05c1=4000
		else
			setS05c1=6500
		end if
		
		inc(INV1_�R���x�A���[�^���]step)


	case 2
		ejectINV1_�R���x�A���[�^���]=ON
		errpass�R���x�A�ꎞ��~=OFF
		
		if �������� then
			tim_���H���I��_val=0
			if pnlPBLS7_�����]�@���_�ʒu or pnlPBLS8_�����]�@���]�ʒu then
				ejectINV1_�R���x�A���[�^���]=OFF
			else
				tim_INV1_�R���x�A���[�^���]_val=INV1���r�o���� '1���@(27)  2���@(43)
			end if			
		else
			tim_���H���I��_val=40
			tim_INV1_�R���x�A���[�^���]_val=INV1�t�^�r�o���� '1���@(80)  2���@(83)->(78)
		end if

		res(tim_���H���I��)
		res(tim_INV1_�R���x�A���[�^���])
		inc(INV1_�R���x�A���[�^���]step)
		
	case 3
		if not(��������) and tim_���H���I��.B then
			���H���I��=ON '���O�ɐ�򃆃j�b�g�̍H�����I��������B
		end if			
	
		if tim_INV1_�R���x�A���[�^���].B then
			inc(INV1_�R���x�A���[�^���]step)
		end if

	case 4
		��������=OFF
		ejectINV1_�R���x�A���[�^���]=OFF
		inc(INV1_�R���x�A���[�^���]step)
	
	case 5
		tim_INV1_�R���x�A���[�^���]_val=5
		res(tim_INV1_�R���x�A���[�^���])
		inc(INV1_�R���x�A���[�^���]step)
	
	case 6
		if tim_INV1_�R���x�A���[�^���].B then
			inc(INV1_�R���x�A���[�^���]step)
		end if
	
	case 7
		INV1_�R���x�A���[�^���]step=0
	
	end select
	'------------------------------------------------------------------------------------------------

	if (����������AutoMode and ��������AutoMode ) or ����������step<>0 then
	
		if not(����������AutoMode and ��������AutoMode ) then
			����������AutoRun=OFF
		end if

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ����������step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ����������AutoRun then
				inc(����������step)
			else 
				����������step=0 '�I���ҋ@
			end if
	
		case 2
			if PH45_�����m or PH46_�t�^���m or shiftreg���t�^����0<>0 then '���R���x�A��̃��[�N����
				�����������r�o�v��=ON
				�������������쒆=OFF
				����������step=1
			else
				inc(����������step)
			end if

		case 3
			if �����������r�o�v��=OFF and  ���R���x�A�������쒆=OFF and ���������t�g�r�o�v�� then
				errpass�R���x�A�ꎞ��~=OFF
				����������step=100
			else
				����������step=1
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 100
			if not(LS7_�����]�@���_�ʒu or pnlPBLS7_�����]�@���_�ʒu) then 
				����������step=1

			else if PH43_�����m or PH44_�t�^���m then '�`�F�[�������R���x�A�̃��[�N����
				�������������쒆=ON
				inc(����������step)

			else
				���������t�g�r�o�v��=OFF
				����������step=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 101
			if PH43_�����m and PH44_�t�^���m then
				inc(����������step) '������
			else if not(PH43_�����m) and PH44_�t�^���m then
				����������step=150 '�t�^����
			end if

		'--------------------------------------------------------------------------------------------------------------
		'������
		case 102
			��������=ON
			'mMC33_�������[�^=ON
			tim_procstep_val=5 '���}������
			res(tim_procstep)
			inc(����������step)
		
		case 103
			if tim_procstep.B then
				'mMC33_�������[�^=OFF
				inc(����������step)
			end if
		
		case 104
			MC31_���]���[�^���]step=1
			inc(����������step)
		
		case 105
			if MC31_���]���[�^���]step=0 then
				���H���I��=ON
				inc(����������step)
			end if
		
		case 106
			tim_procstep_val=10
			res(tim_procstep)
			inc(����������step)

		case 107
			if tim_procstep.B then
				inc(����������step)
			end if			
		
		case 108
			if not(errpassLS8_�����]�@���]�ʒu) then
				INV1_�R���x�A���[�^���]step=1
			end if
			inc(����������step)
		
		case 109
			if INV1_�R���x�A���[�^���]step=0 then
				tim_procstep_val=5 '
				res(tim_procstep)
				inc(����������step)
			end if
		
		case 110
			if tim_procstep.B then
				'mMC33_�������[�^=OFF
				inc(����������step)
			end if
			
		case 111
			�����������r�o�v��=ON '���R���x�A�F�N��
			MC31_���]���[�^�t�]step=1
			inc(����������step)

		case 112
			if MC31_���]���[�^�t�]step=0 then
				inc(����������step)
			end if
						
		case 113
			���������t�g�r�o�v��=OFF	'���������t�g�F���t�g���~
			�������������쒆=OFF
			����������step=1

		'------------------------------------
		'�t�^����
		case 150
			MC33_�������[�^step=1
			INV1_�R���x�A���[�^���]step=1
			inc(����������step)
		
		case 151
			if MC33_�������[�^step=0 and INV1_�R���x�A���[�^���]step=0 then
				inc(����������step)
			end if
		
		case 152
			���������t�g�r�o�v��=OFF	'���������t�g�F���t�g���~
			�����������r�o�v��=ON
			�������������쒆=OFF
			����������step=1
		'--------------------------------------------------------------------------------------------------------------
			
		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		����������AutoRun=OFF
		
		����������step=0 '�I��

		res(timerr_MC33_�������[�^)
		res(timerr_INV1_�R���x�A���[�^���])
		
		if ldp(pnlPBMC33_�������[�^) then
			if mMC33_�������[�^ then
				mMC33_�������[�^=OFF
			else
				mMC33_�������[�^=ON
			end if
		end if
		
		
		if ldp(pnlPBMC31_���]���[�^���]) then
			'if LS7_�����]�@���_�ʒu then
				if mMC31_���]���[�^���] then
					mMC31_���]���[�^���]=OFF
				else if not(mMC31_���]���[�^�t�]) and not(PH45_�����m) and not(PH46_�t�^���m) then
					mMC31_���]���[�^���]=ON
					mMC31_���]���[�^�t�]=OFF
				end if
			'end if
		else if ldp(pnlPBMC31_���]���[�^�t�]) then
			'if LS8_�����]�@���]�ʒu then
				if mMC31_���]���[�^�t�] then
					mMC31_���]���[�^�t�]=OFF
				else if not(mMC31_���]���[�^���]) and not(PH44_�t�^���m) and not(PH43_�����m) then
					mMC31_���]���[�^���]=OFF
					mMC31_���]���[�^�t�]=ON
				end if
			'end if
		end if
		if mMC31_���]���[�^���] and LS8_�����]�@���]�ʒu then
			mMC31_���]���[�^���]=OFF
		end if
		if mMC31_���]���[�^�t�] and LS7_�����]�@���_�ʒu then
			mMC31_���]���[�^�t�]=OFF
		end if


	end if '����������AutoMode and not(����������OrgErrStep)

	'===================================================================================================================
	'�y ����������OrgErr���� �z
	else
		if ResetFlg then
			����������OrgErr=OFF
		end if
	end if

	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else
		res(timerr_MC33_�������[�^)		
		res(timerr_INV1_�R���x�A���[�^���])
		
		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON
		
		if ResetFlg then
			almMC33_�������[�^=OFF
			almINV1_�R���x�A���[�^���]=OFF

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

		����������Err=ON

		mMC33_�������[�^=OFF
		ejectINV1_�R���x�A���[�^���]=OFF

		select case ����������ErrStep
		case 0
		case 1
			alm�a�،x��=ON
	
			if ResetFlg then
				almLS8_�����]�@���]�ʒu=OFF
				almLS7_�����]�@���_�ʒu=OFF
				almMC31_���]���[�^���]=OFF				
				almMC31_���]���[�^�t�]=OFF

				alm�a�،x��=OFF
				inc(����������ErrStep)
			end if
		case 2
			����������Err=OFF
			����������ErrStep=0
		end select

	end if 'if ����������ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else



	select case ����������EmgStep
	case 0
	
	case 1
		����������AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (����������AutoMode and ��������AutoMode ) or ����������step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgINV1_�R���x�A���[�^���]=ON
			EmgMC31_���]���[�^�t�]=ON
			EmgMC31_���]���[�^���]=ON
			EmgMC33_�������[�^=ON
			
			if timstack=OFF then
				
				tim_MC31_���]���[�^���]_stack.U=tim_MC31_���]���[�^���].U
				tim_MC31_���]���[�^�t�]_stack.U=tim_MC31_���]���[�^�t�].U
				tim_MC33_�������[�^_stack.U=tim_MC33_�������[�^.U
				tim_INV1_�R���x�A���[�^���]_stack.U=tim_INV1_�R���x�A���[�^���].U
				tim_���H���I��_stack.U=tim_���H���I��.U
				tim_procstep_stack.U=tim_procstep.U
			' tmr(tim_MC31_���]���[�^���],tim_MC31_���]���[�^���]_val)
			' tmr(tim_MC31_���]���[�^�t�],tim_MC31_���]���[�^�t�]_val)
			' tmr(tim_MC33_�������[�^,tim_MC33_�������[�^_val)
			' tmr(tim_INV1_�R���x�A���[�^���],tim_INV1_�R���x�A���[�^���]_val)
			' tmr(tim_���H���I��,tim_���H���I��_val)
			' tmr(tim_procstep,tim_procstep_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC33_�������[�^=OFF
			mMC31_���]���[�^���]=OFF
			mMC31_���]���[�^�t�]=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(����������EmgStep)
	case 2
		if ResetFlg then
			inc(����������EmgStep)
		end if
	case 3
		if (����������AutoMode and ��������AutoMode ) or ����������step<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				EmgINV1_�R���x�A���[�^���]=OFF
				EmgMC31_���]���[�^�t�]=OFF
				EmgMC31_���]���[�^���]=OFF
				EmgMC33_�������[�^=OFF
				
				tim_MC31_���]���[�^���].U=tim_MC31_���]���[�^���]_stack.U
				tim_MC31_���]���[�^�t�].U=tim_MC31_���]���[�^�t�]_stack.U
				tim_MC33_�������[�^.U=tim_MC33_�������[�^_stack.U
				if ejectINV1_�R���x�A���[�^���] then
					if �������� then
						tim_INV1_�R���x�A���[�^���].U=tim_INV1_�R���x�A���[�^���]_stack.U+17
					else
						tim_INV1_�R���x�A���[�^���].U=tim_INV1_�R���x�A���[�^���]_stack.U+10
					end if					
				else
					tim_INV1_�R���x�A���[�^���].U=tim_INV1_�R���x�A���[�^���]_stack.U				
				end if
				tim_���H���I��.U=tim_���H���I��_stack.U
				tim_procstep.U=tim_procstep_stack.U
				' tmr(tim_MC31_���]���[�^���],tim_MC31_���]���[�^���]_val)
				' tmr(tim_MC31_���]���[�^�t�],tim_MC31_���]���[�^�t�]_val)
				' tmr(tim_MC33_�������[�^,tim_MC33_�������[�^_val)
				' tmr(tim_INV1_�R���x�A���[�^���],tim_INV1_�R���x�A���[�^���]_val)
				' tmr(tim_���H���I��,tim_���H���I��_val)
				' tmr(tim_procstep,tim_procstep_val)

				'���o�^�C�}�[�̃��Z�b�g

				'---------------------------------
				inc(����������EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(����������EmgStep)		
		end if				
	case 4
		timstack=OFF
		����������EmgStep=0
		����������Emg=OFF
	end select

end if 'if ����������EmgStep=0 then
