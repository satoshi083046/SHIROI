'���o������
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	���o������
'	
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������
    ���o������AutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���o������AutoRun=OFF
    ���o����������=ON
    ���o������OrgErr=OFF
    ���o������Err=OFF
    ���o������Emg=OFF
    ���o������step=0
    ���o������ErrStep=0
    ���o������OrgErrStep=0
    ���o������EmgStep=0
	
	MC10_���]���[�^���]step=0
	MC10_���]���[�^�t�]step=0
	
end if
'===================================================================================================================
'�y ���_ �z
���o������Org=LS5_�󊘔��]���_�ʒu or pnlPBLS5_�󊘔��]���_�ʒu

'===================================================================================================================
'�y �ً}��~ �z
if not(PB����~) then
	���o������Emg=ON
	���o������EmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(MC10_���]���[�^���] and not(pnlPBLS6_�󊘔��]���]�ʒu),tim_LS6_�󊘔��]���]�ʒu,#60)
tmr(MC10_���]���[�^�t�] and not(pnlPBLS5_�󊘔��]���_�ʒu),tim_LS5_�󊘔��]���_�ʒu,#60)
tmr(mINV3_�R���x�A���[�^���] and not(pauseINV3_�R���x�A���[�^���]) and not(EmgINV3_�R���x�A���[�^���]),timerr_INV3_�R���x�A���[�^���],#120)
tmr( (mMC32_�������[�^ or ejectMC32_�������[�^) and not(pauseMC32_�������[�^) and not(EmgMC32_�������[�^),timerr_MC32_�������[�^,#120)

if ldp(timerr_INV3_�R���x�A���[�^���].B) then
	almINV3_�R���x�A���[�^���]=ON
	
	mINV3_�R���x�A���[�^���]=OFF
	ejectMC32_�������[�^=OFF

	�R���x�A�ꎞ��~=ON
	
else if ldp(timerr_MC32_�������[�^.B) then
	almMC32_�������[�^=ON
	
	mINV3_�R���x�A���[�^���]=OFF
	ejectMC32_�������[�^=OFF
	
	�R���x�A�ꎞ��~=ON
end if

if (LS5_�󊘔��]���_�ʒu and not(pnlPBLS5_�󊘔��]���_�ʒu)) and (LS6_�󊘔��]���]�ʒu and not(pnlPBLS6_�󊘔��]���]�ʒu)) then
	errpassLS6_�󊘔��]���]�ʒu=ON	
	errpassLS5_�󊘔��]���_�ʒu=ON
	mMC10_���]���[�^���]=OFF
	mMC10_���]���[�^�t�]=OFF
	almLS5_�󊘔��]���_�ʒu=ON
	almLS6_�󊘔��]���]�ʒu=ON
	almMC10_���]���[�^���]=ON
	almMC10_���]���[�^�t�]=ON
	���o������ErrStep=1

else if ldp(tim_LS6_�󊘔��]���]�ʒu.B) then
	mMC10_���]���[�^���]=OFF
	mMC10_���]���[�^�t�]=OFF
	errpassLS6_�󊘔��]���]�ʒu=ON	
	almMC10_���]���[�^���]=ON
	���o������ErrStep=1
	
else if ldp(tim_LS5_�󊘔��]���_�ʒu.B) then
	mMC10_���]���[�^���]=OFF
	mMC10_���]���[�^�t�]=OFF
	errpassLS5_�󊘔��]���_�ʒu=ON
	almMC10_���]���[�^�t�]=ON
	���o������ErrStep=1

end if


tmr(PH7_�����m,timdly_PH7_�����m,5)
tmr(PH8_�t�^���m,timdly_PH8_�t�^���m,5)
tmr(PH9_�����m,timdly_PH9_�����m,5)
tmr(PH10_�t�^���m,timdly_PH10_�t�^���m,5)

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���o������AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���o������AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���o������Emg	���̏��~


if ���o������EmgStep=0 then  
	
	if ���o������ErrStep=0  then

	if not(�R���x�A�ꎞ��~) then

	if not(���o������OrgErr) then

	if (���o������AutoMode and ��������AutoMode ) or ���o������step<>0 or MC10_���]���[�^���]step<>0 or MC10_���]���[�^�t�]step<>0 then
	
		if not(���o������AutoMode and ��������AutoMode ) then
			���o������AutoRun=OFF
		end if
	'------------------------------------------------------------------------------------------------
	'MC10_���]���[�^���]  �i���~���u->���@���j
	tmr(tim_MC10_���]���[�^���],tim_MC10_���]���[�^���]_val)
	
	select case MC10_���]���[�^���]step
	
	case 0
	
	case 1
		mMC10_���]���[�^���]=ON
		errpassLS6_�󊘔��]���]�ʒu=OFF
		inc(MC10_���]���[�^���]step)

	case 2
		if LS6_�󊘔��]���]�ʒu or errpassLS6_�󊘔��]���]�ʒu or pnlPBLS6_�󊘔��]���]�ʒu then
			inc(MC10_���]���[�^���]step)
		end if
		
	case 3
		mMC10_���]���[�^���]=OFF
		inc(MC10_���]���[�^���]step)

	case 4		
		MC10_���]���[�^���]step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC10_���]���[�^�t�] (���@�� -> ���~�@���j
	tmr(tim_MC10_���]���[�^�t�],tim_MC10_���]���[�^�t�]_val)
	
	select case MC10_���]���[�^�t�]step
	
	case 0
	
	case 1
		mMC10_���]���[�^�t�]=ON
		errpassLS5_�󊘔��]���_�ʒu=OFF
		inc(MC10_���]���[�^�t�]step)

	case 2
		if LS5_�󊘔��]���_�ʒu or errpassLS5_�󊘔��]���_�ʒu or pnlPBLS5_�󊘔��]���_�ʒu then
			inc(MC10_���]���[�^�t�]step)
		end if
	
	case 3
		mMC10_���]���[�^�t�]=OFF
		inc(MC10_���]���[�^�t�]step)
		
	case 4
		MC10_���]���[�^�t�]step=0

	end select

	'------------------------------------------------------------------------------------------------


	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ���o������step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ���o������AutoRun then
				inc(���o������step)
			else 
				���o������step=0 '�I���ҋ@
			end if
	
		case 2
			if timdly_PH9_�����m or timdly_PH10_�t�^���m  then '���t�g��O�ʒu�̃��[�N
				���o�������r�o�v��=ON
				���o���������쒆=OFF
				���o������step=1
			else
				inc(���o������step)
			end if

		case 3
			if ���o�������r�o�v��=OFF and  ���R���x�A�������쒆=OFF and ���R���x�A�����r�o�v�� then
				inc(���o������step)
			else
				���o������step=1
			end if

		case 4
			if LS7_�����]�@���_�ʒu then
				errpass�R���x�A�ꎞ��~=OFF
				���o������step=100
			else
				���o������step=1			
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'�����]�@�N��
		case 100 'mINV3�Ŕ������ꂽ���t�^�m�F
			���o���������쒆=ON
			tim_procstep_val=20
			res(tim_procstep)
			
			res(timdly_PH7_�����m)
			res(timdly_PH8_�t�^���m)
			
			INC(���o������step) 
		
		case 101
			if tim_procstep.B then
				INC(���o������step) 
			end if
		
		case 102
		

		if 1 then
			if timdly_PH7_�����m.B and timdly_PH8_�t�^���m.B then
				'���]�@ ���] LS5 -> LS6
				��������=ON
				���o������step=200
			
			else if not(timdly_PH7_�����m.B) and timdly_PH8_�t�^���m.B then
				'���]�@ �t�] LS6 -> LS5
				��������=OFF
				���o������step=250
			
			else if not(timdly_PH7_�����m.B) and not(timdly_PH8_�t�^���m.B) then
				'�������Ȃ��ŏI��
				��������=OFF
				���R���x�A�����r�o�v��=OFF
				���o���������쒆=OFF
				���o������step=1
			
			end if
		end if
		
		if 0 then
		
		if StageDevice36=$80 then '�����o
			'���]�@ ���] LS5 -> LS6
			��������=ON
			���o������step=200
		
		else if StageDevice36=$40 then '�t�^���o
			'���]�@ �t�] LS6 -> LS5
			��������=OFF
			���o������step=250
		
		else if StageDevice36=0 then '�����Ȃ�
			'�������Ȃ��ŏI��
			��������=OFF
			���R���x�A�����r�o�v��=OFF
			���o���������쒆=OFF
			���o������step=1
		
		end if

		end if
		'--------------------------------------------------------
		'������
		case 200
			MC10_���]���[�^���]step=1
			inc(���o������step)
				
		case 201
			if MC10_���]���[�^���]step=0 then
				inc(���o������step)
			end if
		
		case 202
			if errpassLS6_�󊘔��]���]�ʒu or pnlPBLS5_�󊘔��]���_�ʒu or pnlPBLS6_�󊘔��]���]�ʒu then
				inc(���o������step)
			else
				setS05c3=4500
				mINV3_�R���x�A���[�^���]=ON
				errpass�R���x�A�ꎞ��~=OFF
				tim_procstep_val=INV3���}������ '1���@(47) 2���@(38)
				res(tim_procstep)
				inc(���o������step)
			end if
			
		case 203
			if tim_procstep.B then
				inc(���o������step)
			end if		

		case 204
			if errpassLS6_�󊘔��]���]�ʒu or pnlPBLS5_�󊘔��]���_�ʒu or pnlPBLS6_�󊘔��]���]�ʒu then
				inc(���o������step)
			else
				if (not(PH7_�����m) and not(PH8_�t�^���m) ) or errpass�R���x�A�ꎞ��~ then
					mINV3_�R���x�A���[�^���]=OFF
					inc(���o������step)
				end if
			end if
			
		case 205
			inc(���o������step)

		case 206
			MC10_���]���[�^�t�]step=1
			inc(���o������step)
		
		case 207

			���R���x�A�����r�o�v��=OFF
			���o���������쒆=OFF
			inc(���o������step)

		case 208
			if MC10_���]���[�^�t�]step=0 then
				tim_procstep_val=5
				res(tim_procstep)
				inc(���o������step)
			end if
		
		case 209
			if tim_procstep.B then
				if PH9_�����m then
					StageDevice36=0
					StageDevice37=$8000+$100 '<- StageDevice  [ ��  �n�̃f�[�^���ꍞ�ݽ��Ēn�_
				else
					StageDevice36=0
					StageDevice37=0 '<- StageDevice  [ ��  �n�̃f�[�^���ꍞ�ݽ��Ēn�_
				end if
				���o������step=1
			end if
					

		'----------------------------------------------------------------------
		'�t�^����
		case 250
			MC10_���]���[�^�t�]step=1
			inc(���o������step)
		
		case 251
			if MC10_���]���[�^�t�]step=0 then
				inc(���o������step)
			end if		
		
		case 252
			setS05c3=6000
			mINV3_�R���x�A���[�^���]=ON
			ejectMC32_�������[�^=ON
			errpass�R���x�A�ꎞ��~=OFF
			inc(���o������step)
			
		case 253
			if errpass�R���x�A�ꎞ��~ then
				res(tim���t�^���m�Ď�)
				inc(���o������step)
			
			else if not(PH8_�t�^���m) then
				res(tim���t�^���m�Ď�)
				inc(���o������step)
			end if

		case 254
			if errpass�R���x�A�ꎞ��~ then
				res(tim���t�^���m�Ď�)
				inc(���o������step)
			
			else if PH10_�t�^���m  then
				inc(���o������step)
			end if

		case 255
			tim_procstep_val=6
			res(tim_procstep)
			inc(���o������step)
		
		case 256
			if tim_procstep.B then
				inc(���o������step)		
			end if
			
		case 257
			mINV3_�R���x�A���[�^���]=OFF
			ejectMC32_�������[�^=OFF
			inc(���o������step)
			
		case 258
			StageDevice36=0
			StageDevice37=0               '<- StageDevice [ �t�^  �n�̃f�[�^���ꍞ�ݽ��Ēn�_
			���R���x�A�����r�o�v��=OFF
			���o���������쒆=OFF
			���o������step=1
		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		���o������AutoRun=OFF
		
		���o������step=0 '�I��

		res(timerr_INV3_�R���x�A���[�^���])
		res(timerr_MC32_�������[�^)

		if 0 then
			if ldp(pnlPBINV3_�R���x�A���[�^���]) then
				if mINV3_�R���x�A���[�^���] then
					mINV3_�R���x�A���[�^���]=OFF
				else
					mINV3_�R���x�A���[�^���]=ON
				end if
			end if
		end if
		
		if ldp(pnlPBMC32_�������[�^) then
			if mMC32_�������[�^ then
				mMC32_�������[�^=OFF
			else
				mMC32_�������[�^=ON
			end if
		end if
		
		
		if ldp(pnlPBMC10_���]���[�^���]) then
			'if LS5_�󊘔��]���_�ʒu then
				if mMC10_���]���[�^���] then
					mMC10_���]���[�^���]=OFF
				else if not(mMC10_���]���[�^�t�]) and  not(PH7_�����m) and not(PH8_�t�^���m) then
					mMC10_���]���[�^���]=ON
					mMC10_���]���[�^�t�]=OFF
				end if
			'end if
		else if ldp(pnlPBMC10_���]���[�^�t�]) then
			'if LS6_�󊘔��]���]�ʒu then
				if mMC10_���]���[�^�t�] then
					mMC10_���]���[�^�t�]=OFF
				else if not(mMC10_���]���[�^���]) and not(PH9_�����m) and not(PH10_�t�^���m) then	
					mMC10_���]���[�^���]=OFF
					mMC10_���]���[�^�t�]=ON
				end if
			'end if
		end if
		if mMC10_���]���[�^���] and LS6_�󊘔��]���]�ʒu then
			mMC10_���]���[�^���]=OFF
		end if
		if mMC10_���]���[�^�t�] and LS5_�󊘔��]���_�ʒu then
			mMC10_���]���[�^�t�]=OFF
		end if


	end if '���o������AutoMode and not(���o������OrgErrStep)

	'===================================================================================================================
	'�y ���o������OrgErr���� �z
	else
	
		if ResetFlg then
			���o������OrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else
		res(timerr_INV3_�R���x�A���[�^���])
		res(timerr_MC32_�������[�^)		
		
		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON
		
		if ResetFlg then
			almINV3_�R���x�A���[�^���]=OFF
			almMC32_�������[�^=OFF

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

		���o������Err=ON

		���o������AutoRun=OFF
		
		pauseINV3_�R���x�A���[�^���]=ON
		pauseMC32_�������[�^=ON
		
		tmr(tim_���o������ErrStep,tim_���o������ErrStep_val)
		
		select case ���o������ErrStep
		case 0
		
		case 1
			alm�a�،x��=ON
	
			if ResetFlg then
				alm�a�،x��=OFF
				inc(���o������ErrStep)
			end if

		case 2
			almLS6_�󊘔��]���]�ʒu=OFF
			almLS5_�󊘔��]���_�ʒu=OFF
			almMC10_���]���[�^���]=OFF
			almMC10_���]���[�^�t�]=OFF
			

			inc(���o������ErrStep)
		
		case 3
			pauseINV3_�R���x�A���[�^���]=OFF
			pauseMC32_�������[�^=OFF

			���o������Err=OFF
			���o������ErrStep=0
		end select

	end if 'if ���o������ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	'--- AutoMode
	'mMC10_���]���[�^���]=ON
	'mMC10_���]���[�^�t�]=ON
	'ejectMC32_�������[�^=ON
	'mINV3_�R���x�A���[�^���]=ON

	'--- Manual
	'mMC32_�������[�^=ON
	'mMC10_���]���[�^���]=ON
	'mMC10_���]���[�^�t�]=ON
	'mINV3_�R���x�A���[�^���]=ON

	select case ���o������EmgStep
	case 0
	
	case 1
		���o������AutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (���o������AutoMode and ��������AutoMode ) or ���o������step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC10_���]���[�^�t�]=ON
			pauseMC10_���]���[�^���]=ON
			pauseMC32_�������[�^=ON
			pauseINV3_�R���x�A���[�^���]=ON
		
			if timstack=OFF then
				'tmr(PH7_�����m,timdly_PH7_�����m,5)
				'tmr(PH8_�t�^���m,timdly_PH8_�t�^���m,5)
				'tmr(PH9_�����m,timdly_PH9_�����m,5)
				'tmr(PH10_�t�^���m,timdly_PH10_�t�^���m,5)
				timdly_PH7_�����m_stack.U=timdly_PH7_�����m.U
				timdly_PH8_�t�^���m_stack.U=timdly_PH8_�t�^���m.U
				timdly_PH9_�����m_stack.U=timdly_PH9_�����m.U
				timdly_PH10_�t�^���m_stack.U=timdly_PH10_�t�^���m.U

				'tmr(tim_MC10_���]���[�^���],tim_MC10_���]���[�^���]_val)
				'tmr(tim_MC10_���]���[�^�t�],tim_MC10_���]���[�^�t�]_val)
				'tmr(tim_procstep,tim_procstep_val)
				'tmr(tim_���o������ErrStep,tim_���o������ErrStep_val)				
				tim_MC10_���]���[�^���]_stack.U=tim_MC10_���]���[�^���].U
				tim_MC10_���]���[�^�t�]_stack.U=tim_MC10_���]���[�^�t�].U
				tim_procstep_stack.U=tim_procstep.U
				tim_���o������ErrStep_stack.U=tim_���o������ErrStep.U
			
				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC32_�������[�^=OFF
			mMC10_���]���[�^���]=OFF
			mMC10_���]���[�^�t�]=OFF
			mINV3_�R���x�A���[�^���]=OFF
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(���o������EmgStep)
	case 2
		if ResetFlg then
			inc(���o������EmgStep)
		end if
	case 3
		if (���o������AutoMode and ��������AutoMode ) or ���o������step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC10_���]���[�^�t�]=OFF
				pauseMC10_���]���[�^���]=OFF
				pauseMC32_�������[�^=OFF
				pauseINV3_�R���x�A���[�^���]=OFF

				tim_MC10_���]���[�^���].U=tim_MC10_���]���[�^���]_stack.U
				tim_MC10_���]���[�^�t�].U=tim_MC10_���]���[�^�t�]_stack.U
				tim_procstep.U=tim_procstep_stack.U
				tim_���o������ErrStep.U=tim_���o������ErrStep_stack.U
				'---------------------------------
				res(timdly_PH7_�����m)
				res(timdly_PH8_�t�^���m)
				res(timdly_PH9_�����m)
				res(timdly_PH10_�t�^���m)
				
				inc(���o������EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���o������EmgStep)		
		end if				
	case 4
		timstack=OFF
		���o������EmgStep=0
		���o������Emg=OFF
	end select
		
end if 'if ���o������EmgStep=0 then
