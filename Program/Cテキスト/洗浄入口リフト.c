'���������t�g
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	���������t�g
'	
'===================================================================================================================

'�y ���������� �z
if CR2008 then '�d��ON������������

	 '���������t�gAutoMode  ��  ���������t�gAutoRun  �͍ċN���̍ۂɓˑROFF�ɂȂ邽�߁A
	 '���������t�gAutoMode -> ����������AutoMode  ���������t�gAutoRun -> ����������AutoRun �ɕύX

    '���������t�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    '���������t�gAutoRun=OFF
    ���������t�g����=ON
    ���������t�gOrgErr=OFF
    ���������t�gErr=OFF
    ���������t�gEmg=OFF
    ���������t�gstep=0
    ���������t�gErrStep=0
    ���������t�gOrgErrStep=0
    ���������t�gEmgStep=0
	
	MC30_�������[�^step=0
	
end if
'===================================================================================================================
'�y ���_ �z
���������t�gOrg=1 'not(�������֎~ and (PH48_�����m or PH49_�t�^���m))

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	���������t�gEmg=ON
	���������t�gEmgStep=1
end if


'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(mMC30_�������[�^ and not(pauseMC30_�������[�^) and not(EmgMC30_�������[�^),timerr_MC30_�������[�^,#150)
tmr(ejectMC33_�������[�^ and not(pauseMC33_�������[�^) and not(EmgMC33_�������[�^),timerr_MC33_�������[�^,#100)

if ldp(timerr_MC30_�������[�^.B) then
	almMC30_�������[�^=ON
	
	mMC30_�������[�^=OFF
	ejectMC33_�������[�^=OFF
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC33_�������[�^.B) then
	almMC33_�������[�^=ON

	mMC30_�������[�^=OFF
	ejectMC33_�������[�^=OFF
	�R���x�A�ꎞ��~=ON
end if

tmr(not(PH48_�����m) and not(PH49_�t�^���m),timoffdly_PH48PH49,#20) 


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���������t�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���������t�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���������t�gEmg	���̏��~


if ���������t�gEmgStep=0 then  
	
	if ���������t�gErrStep=0  then

	if not(�R���x�A�ꎞ��~) then

	if not(���������t�gOrgErr) then

	if (����������AutoMode and ��������AutoMode ) or ���������t�gstep<>0 then
	
		if not(����������AutoMode and ��������AutoMode ) then
			����������AutoRun=OFF
		end if
	
	'------------------------------------------------------------------------------------------------
	'MC30_�������[�^, MC33_�������[�^ 
	tmr(tim_MC30_�������[�^,tim_MC30_�������[�^_val)
	
	select case MC30_�������[�^step
	case 0
	case 1
		mMC30_�������[�^=ON
		ejectMC33_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC30_�������[�^step)
	case 2
		if errpass�R���x�A�ꎞ��~ then
			inc(MC30_�������[�^step)
		
		else if not(PH48_�����m) and not(PH49_�t�^���m) then
			inc(MC30_�������[�^step)
		end if	
	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(MC30_�������[�^step)
		
		else if PH43_�����m or PH44_�t�^���m then
			inc(MC30_�������[�^step)
		end if	

	case 4
		if �������� then
			tim_MC30_�������[�^_val=10
		else
			tim_MC30_�������[�^_val=5 '3 '�t�^�̒�~�ʒu
		end if
		
		res(tim_MC30_�������[�^)
		inc(MC30_�������[�^step)

	case 5
		if tim_MC30_�������[�^.B then
			mMC30_�������[�^=OFF
			ejectMC33_�������[�^=OFF

			���������t�g�r�o�v��=ON
			�����R���x�AF�r�o�v��=OFF
			inc(MC30_�������[�^step)
		end if

	case 6
		���������t�g���쒆=OFF
		inc(MC30_�������[�^step)

	case 7
		MC30_�������[�^step=0
	
	end select
	'------------------------------------------------------------------------------------------------

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ���������t�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ����������AutoRun then
				inc(���������t�gstep)
			else 
				���������t�gstep=0 '�I���ҋ@
			end if

		case 2		
			if not(�������֎~) and (PH43_�����m or PH44_�t�^���m) then '���R���x�A��̃��[�N����
				���������t�g�r�o�v��=ON
				���������t�g���쒆=OFF
				���������t�gstep=1
			else
				inc(���������t�gstep)
			end if
			
		case 3
			if  ���������t�g�r�o�v��=OFF and  �����R���x�AF�r�o�v�� then
				errpass�R���x�A�ꎞ��~=OFF
				���������t�gstep=100
			else
				���������t�gstep=1
			end if

		'--------------------------------------------------------------------------------------------------------------
		case 100
			if PH48_�����m or PH49_�t�^���m then '�ʏ�����F���t�g�̃��[�N����
				���������t�gstep=200
			else
				�����R���x�AF�r�o�v��=OFF
				���������t�gstep=1			
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 200 '���t�g�㏸ -> �w��ҋ@�ʒu�Ɋ��t�^����
			���������t�g���쒆=ON
			inc(���������t�gstep)
			
		case 201
			if �������֎~ then
				if timoffdly_PH48PH49 then
					�����R���x�AF�r�o�v��=OFF
					���������t�g�r�o�v��=OFF
					���������t�g���쒆=OFF
				end if			
					���������t�gstep=1
			else
				inc(���������t�gstep)
			end if

			'------------------------------------------------------
			' �����������ҋ@
		case 202
			if ���������t�g�r�o�v��=OFF and  �������������쒆=OFF then
				inc(���������t�gstep) '������
			else
				���������t�gstep=1
			end if

		case 203
			if not(PH43_�����m) and not(PH44_�t�^���m) then
				inc(���������t�gstep)
			end if				
		
		case 204
			tim_procstep_val=0
			res(tim_procstep)
			inc(���������t�gstep)

		case 205
			if tim_procstep.B then
				inc(���������t�gstep)
			end if

		case 206
			if PH48_�����m and PH49_�t�^���m then
				��������=ON
			else if not(PH48_�����m) and PH49_�t�^���m then
				��������=OFF
			end if
			inc(���������t�gstep) '������
		
			'------------------------------------------------------
			' ������
		case 207
			MC30_�������[�^step=1
			inc(���������t�gstep)
		
		case 208
			if MC30_�������[�^step=0 then
				inc(���������t�gstep)
			end if
		
		case 209
			�����R���x�AF�r�o�v��=OFF
			���������t�g���쒆=OFF
			���������t�gstep=1
		'--------------------------------------------------------------------------------------------------------------
			
		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		����������AutoRun=OFF
		
		���������t�gstep=0 '�I��
	
		res(timerr_MC30_�������[�^)
		res(timerr_MC33_�������[�^)
		
		
		if ldp(pnlPBMC30_�������[�^) then
			if mMC30_�������[�^ then
				mMC30_�������[�^=OFF
			else 'if XSW72_���t�g�㏸�[ then
				mMC30_�������[�^=ON
			end if
		end if
		

	end if '���������t�gAutoMode and not(���������t�gOrgErrStep)

	'===================================================================================================================
	'�y ���������t�gOrgErr���� �z
	else
	
		if ResetFlg then
			���������t�gOrgErr=OFF
		end if

	end if
	
	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else
		res(timerr_MC30_�������[�^)
		res(timerr_MC33_�������[�^)	
		
		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON
		
		if ResetFlg then
			almMC30_�������[�^=OFF
			almMC33_�������[�^=OFF

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

		pauseMC30_�������[�^=ON
		pauseMC33_�������[�^=ON
		
		���������t�gErr=ON


		select case ���������t�gErrStep
		case 0
		case 1
			alm�a�،x��=ON

			if ResetFlg then
				alm�a�،x��=OFF
				inc(���������t�gErrStep)
			end if
		case 2

			pauseMC30_�������[�^=OFF
			pauseMC33_�������[�^=OFF

			���������t�gErr=OFF
			���������t�gErrStep=0
			
			���������t�gstep=0 '�I���ҋ@

		end select

	end if 'if ���������t�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else


	select case ���������t�gEmgStep
	case 0
	
	case 1
		���������t�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (���������t�gAutoMode and ��������AutoMode ) or ���������t�gstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgMC30_�������[�^=ON
			EmgMC33_�������[�^=ON


			if timstack=OFF then
			
				tim_MC30_�������[�^_stack.U=tim_MC30_�������[�^.U
				tim_procstep_stack.U=tim_procstep.U
			' tmr(tim_MC30_�������[�^,tim_MC30_�������[�^_val)
			' tmr(tim_procstep,tim_procstep_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC30_�������[�^=OFF
			
			'---------------------------------
		end if
		
		'---------------------------------
		inc(���������t�gEmgStep)
	case 2
		if ResetFlg then
			inc(���������t�gEmgStep)
		end if
	case 3
		if (���������t�gAutoMode and ��������AutoMode ) or ���������t�gstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				EmgMC30_�������[�^=OFF
				EmgMC33_�������[�^=OFF
				
				tim_MC30_�������[�^.U=tim_MC30_�������[�^_stack.U
				tim_procstep.U=tim_procstep_stack.U
				' tmr(tim_MC30_�������[�^,tim_MC30_�������[�^_val)
				' tmr(tim_procstep,tim_procstep_val)

				'���o�^�C�}�[�̃��Z�b�g

				'---------------------------------
				inc(���������t�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���������t�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		���������t�gEmgStep=0
		���������t�gEmg=OFF
	end select
		
end if 'if ���������t�gEmgStep=0 then
