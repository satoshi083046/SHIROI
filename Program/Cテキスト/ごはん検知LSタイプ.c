'���͂񌟒mLS�^�C�v
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'LS�^�C�v

'XSW73_�V�����_�㏸�[		�r�b�g	R43000
'XSW80_�V�����_���~�[		�r�b�g	R43001
'DLR1_���͂񌟒m 			�r�b�g	R43002		*pLS4_���͂񌟒m
'DLR1_���͂񌟒m���蓮��	�r�b�g	R43003
'DLR2_���͂񌟒m			�r�b�g	R43004
'DLR2_���͂񌟒m���蓮��	�r�b�g	R43005
'DLR3_���͂񌟒m			�r�b�g	R43006
'DLR3_���͂񌟒m���蓮��	�r�b�g	R43007
'SV58_�V�����_				�r�b�g	R46800
'�����t�@��					�r�b�g	R46801


ADRSET(DLR1_���͂񌟒m.B,pLS4_���͂񌟒m.D)

'===================================================================================================================
'
'	���͂񌟒m���j�b�g
'	
'===================================================================================================================
'�y ���������� �z
if CR2008 then
    ���͂񌟒mAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���͂񌟒mAutoRun=OFF
    ���͂񌟒m����=ON
    ���͂񌟒mOrgErr=OFF
    ���͂񌟒mErr=OFF
    ���͂񌟒mEmg=OFF
    ���͂񌟒mstep=0
    ���͂񌟒mErrStep=0
    ���͂񌟒mOrgErrStep=0
    ���͂񌟒mEmgStep=0
end if
'===================================================================================================================
'�y ���_ �z
���͂񌟒mOrg=(XSW73_�V�����_�㏸�[ and not(pnlPBXSW73_�V�����_�㏸�[)) or passXSW73_�V�����_�㏸�[
���͂񌟒mOrg=���͂񌟒mOrg or ���͂񌟒m�֎~
'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	���͂񌟒mEmg=ON
	���͂񌟒mEmgStep=1
end if

if not(���͂񌟒m�֎~) then
	�������͂�L��=OFF
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(SV58_�V�����_ and not(XSW80_�V�����_���~�[) and not(pnlPBXSW80_�V�����_���~�[),tim_notXSW80_�V�����_���~�[,#50)
tmr(not(SV58_�V�����_) and not(XSW73_�V�����_�㏸�[) and not(pnlPBXSW73_�V�����_�㏸�[),tim_notXSW73_�V�����_�㏸�[,#50)

tms(SV58_�V�����_,passtimXSW80_�V�����_���~�[,passtimXSW80_�V�����_���~�[_val)
tms(not(SV58_�V�����_),passtimXSW73_�V�����_�㏸�[,passtimXSW73_�V�����_�㏸�[_val)

if LDP(SV58_�V�����_) and XSW80_�V�����_���~�[ and not(pnlPBXSW80_�V�����_���~�[) then
	SET(tim_XSW80_�V�����_���~�[)
end if
if LDF(SV58_�V�����_) and XSW73_�V�����_�㏸�[ and not(pnlPBXSW73_�V�����_�㏸�[) then
	SET(tim_XSW73_�V�����_�㏸�[)
end if

if not(���͂񌟒m�֎~) then
	if (ldp(tim_XSW80_�V�����_���~�[.B) or ldp(tim_notXSW80_�V�����_���~�[.B)) and not(pnlPBXSW80_�V�����_���~�[) then
		almXSW80_�V�����_���~�[=ON
		pnlPBXSW80_�V�����_���~�[=ON
		if tim_XSW80_�V�����_���~�[ then
			res(tim_XSW80_�V�����_���~�[)
		end if
		���͂񌟒mErrStep=1

	else if (ldp(tim_XSW73_�V�����_�㏸�[.B) or ldp(tim_notXSW73_�V�����_�㏸�[.B)) and not(pnlPBXSW73_�V�����_�㏸�[) then
		almXSW73_�V�����_�㏸�[=ON
		pnlPBXSW73_�V�����_�㏸�[=ON
		if tim_XSW73_�V�����_�㏸�[ then
			res(tim_XSW73_�V�����_�㏸�[)
		end if
		���͂񌟒mErrStep=1
	end if
else
	res(tim_XSW80_�V�����_���~�[)
	res(tim_XSW73_�V�����_�㏸�[)

	res(tim_notXSW80_�V�����_���~�[)
	res(tim_notXSW73_�V�����_�㏸�[)
end if

tmr(*pLS4_���͂񌟒m.B,timdly_LS4_���͂񌟒m,#4) '�`���^�����O�h�~
tmr(not(*pLS4_���͂񌟒m.B),timnotdly_LS4_���͂񌟒m,#4) '�`���^�����O�h�~

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���͂񌟒mAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���͂񌟒mAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���͂񌟒mEmg	���̏��~

if ���͂񌟒mEmgStep=0 then  
	
	if ���͂񌟒mErrStep=0  then

	if not(���͂񌟒mOrgErr) then

	if (���͂񌟒mAutoMode and ��������AutoMode ) or ���͂񌟒mstep<>0 then
	
		if not(���͂񌟒mAutoMode and ��������AutoMode ) then
			���͂񌟒mAutoRun=OFF
		end if

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ���͂񌟒mstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ���͂񌟒mAutoRun  then

				���͂񌟒mStatusMsg=#50	'	�ҋ@��
				inc(���͂񌟒mstep)
			else
				
				���͂񌟒mstep=0 '�I���ҋ@
			end if
		case 2
				inc(���͂񌟒mstep)
		
		case 3
		' [ �W�J�}�ړ���~�m�F ]
			if ���͂񌟒m�r�o�v��=OFF and  �����R���x�AD���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH25_�����m and PH26_�t�^���m then
						inc(���͂񌟒mstep) '�v���Z�X����
						
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH25_�����m) and PH26_�t�^���m then 
							���͂񌟒m�r�o�v��=ON
							���͂񌟒mstep=1
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
					else
							���͂񌟒m�r�o�v��=ON
							���͂񌟒mstep=1  '�I��
					end if
			
			else
			
				���͂񌟒mstep=1
			
			end if
		
		case 4
		' [ ���j�b�g�����o ]
			if not(���͂񌟒m�֎~) then
				���͂񌟒mstep=100 '�v���Z�X����
			else
				���͂񌟒m=�������͂�L��
				���͂񌟒m�r�o�v��=ON
				���͂񌟒mstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
		
			if ���͂񌟒m���� then '�����ړ���OFF
				���͂񌟒m�r�o�v��=ON
				���͂񌟒mstep=1
			else
				���͂񌟒m=OFF
				inc(���͂񌟒mstep)
			end if
		case 101
			if (XSW73_�V�����_�㏸�[ and not(pnlPBXSW73_�V�����_�㏸�[)) or passXSW73_�V�����_�㏸�[ then
				inc(���͂񌟒mstep)
			else
				���͂񌟒mOrgErr=ON
			end if
				
		case 102
			mSV58_�V�����_=ON
			inc(���͂񌟒mstep)
		
		case 103
			if (XSW80_�V�����_���~�[ and not(pnlPBXSW80_�V�����_���~�[)) or passXSW80_�V�����_���~�[ then
				inc(���͂񌟒mstep)
			end if

		case 104
			tim_procstep_val=15
			res(tim_procstep)
			res(timdly_LS4_���͂񌟒m)
			res(timnotdly_LS4_���͂񌟒m)			
			inc(���͂񌟒mstep)

		case 105
			if timdly_LS4_���͂񌟒m.B then
				���͂񌟒m=ON
			else if timnotdly_LS4_���͂񌟒m.B then
				���͂񌟒m=OFF
			end if

			if tim_procstep.B or ((timdly_LS4_���͂񌟒m.B and ���͂񌟒m) or (timnotdly_LS4_���͂񌟒m.B and not(���͂񌟒m)))  then
				inc(���͂񌟒mstep)
			end if
		
		
		case 106
			tim_procstep_val=0 
			res(tim_procstep)
			inc(���͂񌟒mstep)
			
		case 107
			if tim_procstep.B then
				inc(���͂񌟒mstep)
			end if

		case 108
			mSV58_�V�����_=OFF
			inc(���͂񌟒mstep)
		
		case 109
			if (XSW73_�V�����_�㏸�[ and not(pnlPBXSW73_�V�����_�㏸�[)) or passXSW73_�V�����_�㏸�[ then
				inc(���͂񌟒mstep)
			end if	
		
		case 110
			tim_procstep_val=#0 '�㏸�[���莞��
			res(tim_procstep)
			inc(���͂񌟒mstep)
			
		case 111
			if tim_procstep.B then
				���͂񌟒mstep=199
			end if
			
		case 199
			���͂񌟒m����=ON
			���͂񌟒m�r�o�v��=ON
			���͂񌟒mstep=1

		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		if ldp(pnlPBSV58_�V�����_) then
			if mSV58_�V�����_ then
				mSV58_�V�����_=OFF
			else
				mSV58_�V�����_=ON
			end if
		end if
		
	
	end if '���͂񌟒mAutoMode and not(���͂񌟒mOrgErrStep)

	'===================================================================================================================
	'�y ���͂񌟒mOrgErr���� �z
	else
		if ResetFlg then
			���͂񌟒mOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		���͂񌟒mErr=ON
		
		select case ���͂񌟒mErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW80_�V�����_���~�[=OFF
				almXSW73_�V�����_�㏸�[=OFF
				inc(���͂񌟒mErrStep)
			end if
		case 2
			
			res(tim_XSW80_�V�����_���~�[)
			res(tim_XSW73_�V�����_�㏸�[)
			
			res(tim_notXSW80_�V�����_���~�[)
			res(tim_notXSW73_�V�����_�㏸�[)

			���͂񌟒mErr=OFF
			���͂񌟒mErrStep=0
		end select

	end if 'if ���͂񌟒mErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case ���͂񌟒mEmgStep
	case 0
	
	case 1
		���͂񌟒mAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (���͂񌟒mAutoMode and ��������AutoMode ) or ���͂񌟒mstep<>0 then
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
			mSV58_�V�����_=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(���͂񌟒mEmgStep)
	case 2
		if ResetFlg then
			inc(���͂񌟒mEmgStep)
		end if
	case 3
		if (���͂񌟒mAutoMode and ��������AutoMode ) or ���͂񌟒mstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				
				
				'---------------------------------
				inc(���͂񌟒mEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(���͂񌟒mEmgStep)		
		end if				
	case 4
		timstack=OFF
		���͂񌟒mEmgStep=0
		���͂񌟒mEmg=OFF
	end select
		
end if 'if ���͂񌟒mEmgStep=0 then
