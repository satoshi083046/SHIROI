'�ق����@A���j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�ق����@A���j�b�g
'	
'===================================================================================================================

'�y ���������� �z
if CR2008 then
    �ق����@A���j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �ق����@A���j�b�gAutoRun=OFF
    �ق����@A���j�b�g����=ON
    �ق����@A���j�b�gOrgErr=OFF
    �ق����@A���j�b�gErr=OFF
    �ق����@A���j�b�gEmg=OFF
    �ق����@A���j�b�gstep=0
    �ق����@A���j�b�gErrStep=0
    �ق����@A���j�b�gOrgErrStep=0
    �ق����@A���j�b�gEmgStep=0
	
end if
'===================================================================================================================
'�y ���_ �z
�ق����@A���j�b�gOrg=(���]�ق����@A�֎~ or �������\�M��_A) and ( (���]�ق�����������A and PH31_�����m) or (not(���]�ق�����������A) and not(PH31_�����m)) )

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�ق����@A���j�b�gEmg=ON
	�ق����@A���j�b�gEmgStep=1
end if

'===================================================================================================================
if ��������AutoRun then '�^�]��
	if ldp(pnlPB���]�@��~�w��_A) then
		if not(���]�ق����@A�֎~) then
			���]�ق����@A�֎~=ON
		else if ���]�ق����@A�֎~ and �������\�M��_A then '�^�]���͏����t��
			���]�ق����@A�֎~=OFF
		end if
	end if
	'-- �������]A ON �� ���]�ق����@A�֎~=OFF
	'-- ���]�ق����@A�֎~=ON �� �������]A=OFF  
	if ldp(�������]A) then
		���]�ق����@A�֎~=OFF
	else if ldp(���]�ق����@A�֎~) then
		�������]A=OFF
	end if
else 
	if ldp(pnlPB���]�@��~�w��_A) then
		if not(���]�ق����@A�֎~) then
			���]�ق����@A�֎~=ON
		else if ���]�ق����@A�֎~ then '��~���͏����Ȃ�
			���]�ق����@A�֎~=OFF
		end if
	end if
	'-- �������]A ON �� ���]�ق����@A�֎~=OFF
	'-- ���]�ق����@A�֎~=ON �� �������]A=OFF  
	if ldp(�������]A) then
		���]�ق����@A�֎~=OFF
	else if ldp(���]�ق����@A�֎~) then 
		�������]A=OFF
	end if
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

if not(���]�ق����@A�֎~) and ���]�@�ُ�M��_A then
	alm���]�@�ُ�M��_A=ON
	�ق����@A���j�b�gErrStep=1
end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System ::  �ق����@A���j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System ::  �ق����@A���j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System ::  �ق����@A���j�b�gEmg	���̏��~


if  �ق����@A���j�b�gEmgStep=0 then  
	
	if �ق����@A���j�b�gErrStep=0  then

	if not(�ق����@A���j�b�gOrgErr) then

	if  (�ق����@A���j�b�gAutoMode and ��������AutoMode ) or �ق����@A���j�b�gstep<>0 then
	
		if not(�ق����@A���j�b�gAutoMode and ��������AutoMode ) then
			�ق����@A���j�b�gAutoRun=OFF
		end if
		

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �ق����@A���j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if  �ق����@A���j�b�gAutoRun and ��������AutoRun then
				inc(�ق����@A���j�b�gstep)
			else 
				�ق����@A���j�b�gstep=0 '�I���ҋ@
			end if
				
		case 2
			'�ق����@����~���Ɏ�t
			if ���]�ق����@A�֎~ then
				inc(�ق����@A���j�b�gstep)			
			
			else if �d���m�F�����[_A and �������\�M��_A then
				inc(�ق����@A���j�b�gstep)
			
			else			
				�ق����@A���j�b�gstep=1
			end if
			
		
		case 3
			if �ق����@A���j�b�g���� then
				if PH31_�����m then
					�ق����@A�r�o�v��=ON
					�ق����@A���j�b�gstep=1
				else
					inc(�ق����@A���j�b�gstep)
				end if
			else
				inc(�ق����@A���j�b�gstep)
			end if

		case 4
			if ���]�ق�����������A and not(�ق����@A�r�o�v��) and not(�ق����@A���j�b�g����) then
				inc(�ق����@A���j�b�gstep)
			else 
				�ق����@A���j�b�gstep=1
			end if
	
		case 5
			if ���]�ق����@A�֎~ then
				inc(�ق����@A���j�b�gstep)			

			else if �ق����@A���j�b�g���� then
				inc(�ق����@A���j�b�gstep)
			else
				�ق����@A�r�o�v��=ON
				�ق����@A���j�b�g����=ON
				�ق����@A���j�b�gstep=1
			end if

		case 6
			if ���]�ق����@A�֎~ then
				inc(�ق����@A���j�b�gstep)			

			else if (�������]A or  ANDA(StageDevice22,$1000)=$1000 ) and PH31_�����m then
				���]�@�^�]�w��_A=ON '--�w��ON
				tim_procstep_val=5 '200mSec�o��
				res(tim_procstep)
				inc(�ق����@A���j�b�gstep)
			else
				�ق����@A�r�o�v��=ON
				�ق����@A���j�b�g����=ON
				�ق����@A���j�b�gstep=1
			end if
		
		case 7
			if ���]�ق����@A�֎~ then
				inc(�ق����@A���j�b�gstep)			

			else if tim_procstep.B then
				INC(DM_�r�o����)
				���]�@�^�]�w��_A=OFF '--�w��OFF
				inc(�ق����@A���j�b�gstep)
			end if
		
		case 8
			if ���]�ق����@A�֎~ then
				inc(�ق����@A���j�b�gstep)			

			else if not(���]�@���]�����M��_A) or �������\�M��_A then
				tim_procstep_val=10
				res(tim_procstep)
				inc(�ق����@A���j�b�gstep)			
			end if
		
		case 9
			if ���]�ق����@A�֎~ then
				inc(�ق����@A���j�b�gstep)			
			
			else if tim_procstep.B then
				if ���]�@���]�����M��_A or �������\�M��_A then
					inc(�ق����@A���j�b�gstep)			
				end if
			end if
			
		case 10
			�ق����@A�r�o�v��=ON
			�ق����@A���j�b�g����=ON
			�ق����@A���j�b�gstep=1

		
		end select
		
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		 �ق����@A���j�b�gAutoRun=OFF	
		�ق����@A���j�b�gstep=0 '�I��

	
	end if ' �ق����@A���j�b�gAutoMode and not(�ق����@A���j�b�gOrgErrStep)

	'===================================================================================================================
	'�y �ق����@A���j�b�gOrgErr���� �z
	else
	
		if ResetFlg then
			�ق����@A���j�b�gOrgErr=OFF
		end if
	
	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		�ق����@A���j�b�gErr=ON
		
		select case �ق����@A���j�b�gErrStep
		case 0
		case 1
			if ResetFlg then
				alm���]�@�ُ�M��_A=OFF
				inc(�ق����@A���j�b�gErrStep)
			end if
		case 2
			�ق����@A���j�b�gstep=0		
			
			�ق����@A���j�b�gErr=OFF			
			�ق����@A���j�b�gErrStep=0
		end select
		
	end if 'if �ق����@A���j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �ق����@A���j�b�gEmgStep
	case 0
	
	case 1
		�ق����@A���j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�ق����@A���j�b�gAutoMode and ��������AutoMode ) or �ق����@A���j�b�gstep<>0 then

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
		inc(�ق����@A���j�b�gEmgStep)
	case 2
		if ResetFlg then
			alm���]�@�ُ�M��_A=OFF
			alm�d���m�F�����[_A=OFF
			inc(�ق����@A���j�b�gEmgStep)
		end if
		
	case 3
		if (�ق����@A���j�b�gAutoMode and ��������AutoMode ) or �ق����@A���j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				'---------------------------------
				inc(�ق����@A���j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�ق����@A���j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�ق����@A���j�b�gEmgStep=0
		�ق����@A���j�b�gEmg=OFF
	end select
	
end if 'if  �ق����@A���j�b�gEmgStep=0 then
