'������R���x�A
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	������R���x�A
'	
'===================================================================================================================

'�y ���������� �z
if CR2008 then
    ������R���x�AAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ������R���x�AAutoRun=OFF
    ������R���x�A����=ON
    ������R���x�AOrgErr=OFF
    ������R���x�AErr=OFF
    ������R���x�AEmg=OFF
    ������R���x�Astep=0
    ������R���x�AErrStep=0
    ������R���x�AOrgErrStep=0
    ������R���x�AEmgStep=0
		
	'������R���x�A�C���^�[�o������=#200 '���уR���x�A setS05c4=49.00Hz
	tim_notPH59_�����m���ы@����stack=������R���x�A�C���^�[�o������
	
	ManualInite=1

	
end if
'===================================================================================================================
'�y ���_ �z
������R���x�AOrg=LS10_�������ޒ[ or ������R���x�A�֎~

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	������R���x�AEmg=ON
	������R���x�AEmgStep=1
end if

if ������R���x�A�֎~ then
	mMC34_�����萳�]=OFF
	mMC34_������t�]=OFF
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(mMC34_�����萳�] and not(pauseMC34_�����萳�]) and not(EmgMC34_�����萳�]) and not(������R���x�A�֎~),tim_LS9_������O�i�[,#130)
tmr(mMC34_������t�] and not(pauseMC34_������t�]) and not(EmgMC34_������t�]) and not(������R���x�A�֎~),tim_LS10_�������ޒ[,#130)
tmr(������R���x�AAutoRun and PH59_�����m���ы@���� and not(MC34_�����萳�]) and not(������R���x�A�֎~),tim_PH59_�����m���ы@����,#180)

if ldp(tim_PH59_�����m���ы@����.B) then
	almPH59_�����m���ы@����=ON
	alm�a�،x��=ON			
'	pauseMC34_�����萳�]=ON
'	pauseMC34_������t�]=ON

'	������R���x�AErrStep=1

else if LS9_������O�i�[ and LS10_�������ޒ[ and not(������R���x�A�֎~) then
	almLS9_������O�i�[=ON
	almLS10_�������ޒ[=ON
	almMC34_�����萳�]=ON
	almMC34_������t�]=ON

	������R���x�AErrStep=1

else if ldp(tim_LS10_�������ޒ[.B) then
	errpassMC34_������t�]=ON
	almMC34_������t�]=ON

	������R���x�AErrStep=1
else if ldp(tim_LS9_������O�i�[.B) then
	errpassMC34_�����萳�]=ON
	almMC34_�����萳�]=ON
	
	������R���x�AErrStep=1
end if	

if almPH59_�����m���ы@����=ON then
	if ResetFlg then
		almPH59_�����m���ы@����=OFF
		alm�a�،x��=OFF			
	end if
end if

'------------------------------------------------------------------------------------------------------
'������R���x�A�C���^�[�o������
'------------------------------------------------------------------------------------------------------
	if ldp(INV4_�R���x�A���쒆) then
		tim_notPH59_�����m���ы@����.D=tim_notPH59_�����m���ы@����stack.D
	else if ldf(INV4_�R���x�A���쒆) then
		tim_notPH59_�����m���ы@����stack.D=tim_notPH59_�����m���ы@����.D
	end if
	
	if INV4_�R���x�A���쒆 then
		tmr(not(PH59_�����m���ы@����),tim_notPH59_�����m���ы@����,������R���x�A�C���^�[�o������)
	end if
'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ������R���x�AAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ������R���x�AAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ������R���x�AEmg	���̏��~


if ������R���x�AEmgStep=0 then  
	
	if ������R���x�AErrStep=0  then

	if not(������R���x�AOrgErr) then

	'--------------------------------------------
	' �����萳�]�t�]
	tmr(tim_MC34_������,tim_MC34_������_val)
	select case MC34_������step
	case 0
	case 1
		������R���x�A���쒆=ON

		mMC34_�����萳�]=ON
		mMC43_��ڃR���x�A=ON
		errpassMC34_�����萳�]=OFF
		res(notdly_PH54_������g���K.B)
		inc(MC34_������step)
	
	case 2
		tmr(not(PH54_������g���K),notdly_PH54_������g���K,#10)
		
		if LS9_������O�i�[ or (not(PH54_������g���K) and notdly_PH54_������g���K.B) then
			�����R���x�AC�r�o�v��=OFF
			������R���x�A���쒆=OFF
			inc(MC34_������step)
		end if
	
	case 3
		if errpassMC34_�����萳�] then
			inc(MC34_������step)
		else if LS9_������O�i�[ or PH55_�����m�X�e�[�W then
			mMC43_��ڃR���x�A=OFF
			inc(MC34_������step)		
		end if
	
	case 4
		if errpassMC34_�����萳�] then
			inc(MC34_������step)
		
		else if LS9_������O�i�[ then
			inc(MC34_������step)
		end if
	
	case 5
		mMC34_�����萳�]=OFF
		inc(MC34_������step)
	
	case 6
		tim_MC34_������_val=#10 '���] Wait
		res(tim_MC34_������)
		inc(MC34_������step)
	
	case 7
		if tim_MC34_������.B then
			inc(MC34_������step)
		end if

	case 8
		mMC34_������t�]=ON
		errpassMC34_������t�]=OFF
		inc(MC34_������step)
	
	case 9
		if errpassMC34_������t�] then
			inc(MC34_������step)
		
		else if LS10_�������ޒ[ then
			inc(MC34_������step)
		end if			
	
	case 10
		mMC34_������t�]=OFF
		tim_MC34_������_val=#10
		res(tim_MC34_������)
		inc(MC34_������step)
		
	case 11
		if tim_MC34_������.B then
			MC34_������step=0
		end if
	end select
	
	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
	if (������R���x�AAutoMode and ��������AutoMode ) or ������R���x�Astep<>0 then
	

		if not(������R���x�AAutoMode and ��������AutoMode ) then
			������R���x�AAutoRun=OFF
		end if

		'------------------------------------------------------------------------------------------------------
		
		tmr(tim_procstep,tim_procstep_val)

		select case ������R���x�Astep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]

			if ������R���x�AAutoRun then			
				if ManualInite=1 then
					ManualInite=0
				end if
				inc(������R���x�Astep)
			else 
				������R���x�Astep=0 '�I���ҋ@
			end if

		case 2
			if INV4_�R���x�A���쒆 then
				inc(������R���x�Astep)			
			else
				�����R���x�AC�r�o�v��=OFF
				������R���x�A���쒆=OFF			
				������R���x�A�r�o�v��=OFF
				������R���x�Astep=1			
			end if
			
		case 3
		' [ �����R���x�A��~�m�F ]
			if INV4_�R���x�A���쒆 and ������R���x�A�r�o�v��=OFF and  �����R���x�AC���쒆=OFF and �����R���x�AC�r�o�v��=ON then
				inc(������R���x�Astep)
			else
				������R���x�Astep=1
			end if
		
		case 4
			if PH54_������g���K then
				inc(������R���x�Astep)
			else
				�����R���x�AC�r�o�v��=OFF
				������R���x�A���쒆=OFF			
				������R���x�A�r�o�v��=OFF
				������R���x�Astep=1
			end if
			
		case 5  '���_���o
			if ������R���x�AOrg and not(������R���x�A�֎~) then
				inc(������R���x�Astep)
			else
				������R���x�Astep=1
			end if
			
		case 6
			������R���x�Astep=100
		'--------------------------------------------------------------------------------------------------------------
		case 100			
			if not(PH59_�����m���ы@����) then
				if tim_notPH59_�����m���ы@����.B then
					inc(������R���x�Astep)
				else
					������R���x�Astep=1
				end if
			else
				������R���x�Astep=1
			end if
			
		case 101
			MC34_������step=1
			inc(������R���x�Astep)
		
		case 102		
			if 	MC34_������step=0  then
				inc(������R���x�Astep)
			end if		

		case 103
			������R���x�A�r�o�v��=OFF '�펞OFF�G���̃X�e�[�W�̐��уR���x�A�͏펞��]
			������R���x�Astep=1
		
		end select
		
		
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		������R���x�AAutoRun=OFF
		
		������R���x�Astep=0 '�I��
		
		if ManualInite=0 then
			ManualInite=1
		end if

		
		'--------------------------------------------
		if ldp(pnlPBMC34_�����萳�]) then
			if mMC34_�����萳�] then
					mMC34_�����萳�]=OFF
			
			else if not(mMC34_������t�]) then
				if not(PH59_�����m���ы@����) and not(PH55_�����m�X�e�[�W) then
					mMC34_�����萳�]=ON
					mMC34_������t�]=OFF
				end if
			end if
		
		else if ldp(pnlPBMC34_������t�])  then
			if mMC34_������t�] then			
					mMC34_������t�]=OFF
					
			else if not(mMC34_�����萳�]) then
					mMC34_�����萳�]=OFF
					mMC34_������t�]=ON
			end if
		end if
		
		if mMC34_�����萳�] and LS9_������O�i�[ then
			mMC34_�����萳�]=OFF
		end if
		if mMC34_������t�] and LS10_�������ޒ[ then
			mMC34_������t�]=OFF
		end if
		'--------------------------------------------
		

	end if
	'===================================================================================================================
	'�y ������R���x�AOrgErr���� �z
	else
	
		if ResetFlg then
			������R���x�AOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		������R���x�AErr=ON

		mMC34_�����萳�]=OFF
		mMC34_������t�]=OFF
		mMC43_��ڃR���x�A=OFF

		res(tim_PH59_�����m���ы@����)
		res(tim_LS10_�������ޒ[)
		res(tim_LS9_������O�i�[)

		select case ������R���x�AErrStep
		case 0
		
		case 1
			alm�a�،x��=ON			

			if ResetFlg then
				almPH59_�����m���ы@����=OFF
				almLS10_�������ޒ[=OFF
				almLS9_������O�i�[=OFF
				almMC34_�����萳�]=OFF
				almMC34_������t�]=OFF

				alm�a�،x��=OFF			

				inc(������R���x�AErrStep)
			end if
		
		case 2
			inc(������R���x�AErrStep)

		case 3
			MC34_������step=0
			������R���x�AErrStep=0
			������R���x�AErr=OFF

		end select

	end if 'if ������R���x�AErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case ������R���x�AEmgStep
	case 0
	
	case 1
		������R���x�AAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (������R���x�AAutoMode and ��������AutoMode ) or ������R���x�Astep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgMC34_�����萳�]=ON
			EmgMC34_������t�]=ON
			EmgMC43_��ڃR���x�A=ON
			
			if timstack=OFF then
			
				tim_notPH59_�����m���ы@����_stack.U=tim_notPH59_�����m���ы@����.U
				tim_MC34_������_stack.U=tim_MC34_������.U
				notdly_PH54_������g���K_stack.U=notdly_PH54_������g���K.U
				tim_procstep_stack.U=tim_procstep.U
				
				' tmr(not(PH59_�����m���ы@����),tim_notPH59_�����m���ы@����,m������R���x�A�C���^�[�o������)
				' tmr(tim_MC34_������,tim_MC34_������_val)
				' tmr(not(PH54_������g���K),notdly_PH54_������g���K,#10)
				' tmr(tim_procstep,tim_procstep_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC34_�����萳�]=OFF
			mMC34_������t�]=OFF
			mMC43_��ڃR���x�A=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(������R���x�AEmgStep)
	case 2
		if ResetFlg then
			inc(������R���x�AEmgStep)
		end if
	case 3
		if (������R���x�AAutoMode and ��������AutoMode ) or ������R���x�Astep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				EmgMC34_�����萳�]=OFF
				EmgMC34_������t�]=OFF
				EmgMC43_��ڃR���x�A=OFF


				'�X�^�b�N�̒l���^�C�}�[���ݒl�Ƀ��X�g�A
				tim_notPH59_�����m���ы@����.U=tim_notPH59_�����m���ы@����_stack.U
				tim_MC34_������.U=tim_MC34_������_stack.U
				tim_procstep.U=tim_procstep_stack.U
				
				' tmr(not(PH59_�����m���ы@����),tim_notPH59_�����m���ы@����,m������R���x�A�C���^�[�o������)
				' tmr(tim_MC34_������,tim_MC34_������_val)
				' tmr(tim_procstep,tim_procstep_val)
				
				'���o�^�C�}�[�̃��Z�b�g
				res(notdly_PH54_������g���K)
				
				' tmr(not(PH54_������g���K),notdly_PH54_������g���K,#10)

				'---------------------------------
				inc(������R���x�AEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(������R���x�AEmgStep)		
		end if				
	case 4
		timstack=OFF
		������R���x�AEmgStep=0
		������R���x�AEmg=OFF
	end select
		
end if 'if ������R���x�AEmgStep=0 then
