'�ق����@B���j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�ق����@B���j�b�g
'	
'===================================================================================================================

'�y ���������� �z
if CR2008 then
    �ق����@B���j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
   	�ق����@B���j�b�gAutoRun=OFF
    �ق����@B���j�b�g����=ON
    �ق����@B���j�b�gOrgErr=OFF
    �ق����@B���j�b�gErr=OFF
    �ق����@B���j�b�gEmg=OFF
    �ق����@B���j�b�gstep=0
    �ق����@B���j�b�gErrStep=0
    �ق����@B���j�b�gOrgErrStep=0
    �ق����@B���j�b�gEmgStep=0
	
end if
'===================================================================================================================
'�y ���_ �z
�ق����@B���j�b�gOrg= (���]�ق����@B�֎~ or �������\�M��_B) and ( (���]�ق�����������B and PH38_�����m) or (not(���]�ق�����������B) and not(PH38_�����m)) ) 

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�ق����@B���j�b�gEmg=ON
	�ق����@B���j�b�gEmgStep=1
end if
'===================================================================================================================
if ��������AutoRun then
	if ldp(pnlPB���]�@��~�w��_B) then
		if not(���]�ق����@B�֎~) then
			���]�ق����@B�֎~=ON
		else if ���]�ق����@B�֎~ and �������\�M��_B then
			���]�ق����@B�֎~=OFF
		end if
	end if

	if ldp(�������]B) then
		���]�ق����@B�֎~=OFF
	else if ldp(���]�ق����@B�֎~) then
		�������]B=OFF
	end if
else
	if ldp(pnlPB���]�@��~�w��_B) then
		if not(���]�ق����@B�֎~) then
			���]�ق����@B�֎~=ON
		else if ���]�ق����@B�֎~ then
			���]�ق����@B�֎~=OFF
		end if
	end if

	if ldp(�������]B) then
		���]�ق����@B�֎~=OFF
	else if ldp(���]�ق����@B�֎~) then
		�������]B=OFF
	end if

end if
'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z


if not(���]�ق����@B�֎~) and ���]�@�ُ�M��_B then
	alm���]�@�ُ�M��_B=ON
	�ق����@B���j�b�gErrStep=1
end if


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �ق����@B���j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �ق����@B���j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �ق����@B���j�b�gEmg	���̏��~


if �ق����@B���j�b�gEmgStep=0 then  
	
	if �ق����@B���j�b�gErrStep=0  then

	if not(�ق����@B���j�b�gOrgErr) then

	if (�ق����@B���j�b�gAutoMode and ��������AutoMode ) or �ق����@B���j�b�gstep<>0 then
	
		if not(�ق����@B���j�b�gAutoMode and ��������AutoMode ) then
			�ق����@B���j�b�gAutoRun=OFF
		end if

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �ق����@B���j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �ق����@B���j�b�gAutoRun and ��������AutoRun then
				inc(�ق����@B���j�b�gstep)
			else 
				�ق����@B���j�b�gstep=0 '�I���ҋ@
			end if
		
		case 2
			'�ق����@����~���Ɏ�t
			if ���]�ق����@B�֎~ then
				inc(�ق����@B���j�b�gstep)			
			
			else if �d���m�F�����[_B and �������\�M��_B then
				inc(�ق����@B���j�b�gstep)
			else			
				�ق����@B���j�b�gstep=1
			end if

		case 3
			if �ق����@B���j�b�g���� then
				if PH38_�����m then
					�ق����@B�r�o�v��=ON
					�ق����@B���j�b�gstep=1
				else
					inc(�ق����@B���j�b�gstep)
				end if
			else
				inc(�ق����@B���j�b�gstep)
			end if

		case 4
			if ���]�ق�����������B and not(�ق����@B�r�o�v��) and not(�ق����@B���j�b�g����) then
				inc(�ق����@B���j�b�gstep)
			else
				�ق����@B���j�b�gstep=1				
			end if

		case 5
			if ���]�ق����@B�֎~ then
				inc(�ق����@B���j�b�gstep)			
			
			else if �ق����@B���j�b�g���� then
				inc(�ق����@B���j�b�gstep)
			else
				�ق����@B�r�o�v��=ON
				�ق����@B���j�b�g����=ON
				�ق����@B���j�b�gstep=1
			end if

		case 6
			if ���]�ق����@B�֎~ then
				inc(�ق����@B���j�b�gstep)			
			
			else if (�������]B or  ANDA(StageDevice26,$1000)=$1000) and PH38_�����m then
				���]�@�^�]�w��_B=ON '--�w��ON
				tim_procstep_val=5 '200mSec�o��
				res(tim_procstep)
				inc(�ق����@B���j�b�gstep)
			else
				�ق����@B�r�o�v��=ON
				�ق����@B���j�b�g����=ON
				�ق����@B���j�b�gstep=1
			end if
		
		case 7
			if ���]�ق����@B�֎~ then
				inc(�ق����@B���j�b�gstep)			
			
			else if tim_procstep.B then
				INC(DM_�r�o����)
				���]�@�^�]�w��_B=OFF
				inc(�ق����@B���j�b�gstep)
			end if
		
		case 8
			if ���]�ق����@B�֎~ then
				inc(�ق����@B���j�b�gstep)			
			
			else if not(���]�@���]�����M��_B) or �������\�M��_B then
				tim_procstep_val=10
				res(tim_procstep)
				inc(�ق����@B���j�b�gstep)			
			end if
		
		case 9
			if ���]�ق����@B�֎~ then
				inc(�ق����@B���j�b�gstep)			
			
			else if tim_procstep.B then
				if ���]�@���]�����M��_B or �������\�M��_B then
					inc(�ق����@B���j�b�gstep)			
				end if
			end if
			
		case 10
			�ق����@B�r�o�v��=ON
			�ق����@B���j�b�g����=ON
			�ق����@B���j�b�gstep=1
			
		
		end select
		
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�ق����@B���j�b�gAutoRun=OFF
		
		�ق����@B���j�b�gstep=0 '�I��	
	
	
	end if '�ق����@B���j�b�gAutoMode and not(�ق����@B���j�b�gOrgErrStep)

	'===================================================================================================================
	'�y �ق����@B���j�b�gOrgErr���� �z
	else

		if ResetFlg then
			�ق����@B���j�b�gOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		�ق����@B���j�b�gErr=ON
		
		select case �ق����@B���j�b�gErrStep
		case 0
		case 1
			if ResetFlg then
				alm���]�@�ُ�M��_B=OFF
				inc(�ق����@B���j�b�gErrStep)
			end if
		case 2
			�ق����@B���j�b�gstep=0

			�ق����@B���j�b�gErr=OFF
			�ق����@B���j�b�gErrStep=0
		end select


	end if 'if �ق����@B���j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �ق����@B���j�b�gEmgStep
	case 0
	
	case 1
		�ق����@B���j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�ق����@B���j�b�gAutoMode and ��������AutoMode ) or �ق����@B���j�b�gstep<>0 then

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

			'---------------------------------
		end if
		
		'---------------------------------
		inc(�ق����@B���j�b�gEmgStep)
	case 2
		if ResetFlg then
			alm���]�@�ُ�M��_B=OFF
			alm�d���m�F�����[_B=OFF
			inc(�ق����@B���j�b�gEmgStep)
		end if
	case 3
		if (�ق����@B���j�b�gAutoMode and ��������AutoMode ) or �ق����@B���j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				'---------------------------------
				inc(�ق����@B���j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�ق����@B���j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�ق����@B���j�b�gstep=1
		
		�ق����@B���j�b�gEmgStep=0
		�ق����@B���j�b�gEmg=OFF
	end select
		
end if 'if �ق����@B���j�b�gEmgStep=0 then
