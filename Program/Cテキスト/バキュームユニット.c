'�o�L���[�����j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�o�L���[�����j�b�g
'	
'===================================================================================================================

'�y ���������� �z
if CR2008 then
    �o�L���[�����j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �o�L���[�����j�b�gAutoRun=OFF
    �o�L���[�����j�b�g����=ON
    �o�L���[�����j�b�gOrgErr=OFF
    �o�L���[�����j�b�gErr=OFF
    �o�L���[�����j�b�gEmg=OFF
    �o�L���[�����j�b�gstep=0
    �o�L���[�����j�b�gErrStep=0
    �o�L���[�����j�b�gOrgErrStep=0
    �o�L���[�����j�b�gEmgStep=0
end if
'===================================================================================================================
'�y ���_ �z
�o�L���[�����j�b�gOrg=((XSW61_�V�����_�㏸�[ and not(pnlPBXSW61_�V�����_�㏸�[)) or passXSW61_�V�����_�㏸�[) and ((XSW71_�o�L���[�}���t�g���~�[ and not(pnlPBXSW71_�o�L���[�}���t�g���~�[)) or passXSW71_�o�L���[�}���t�g���~�[)
�o�L���[�����j�b�gOrg=�o�L���[�����j�b�gOrg or �o�L���[���֎~
'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�o�L���[�����j�b�gEmg=ON
	�o�L���[�����j�b�gEmgStep=1
end if


'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV52_�V�����_ and not(XSW62_�V�����_���~�[) and not(pnlPBXSW62_�V�����_���~�[),tim_notXSW62_�V�����_���~�[,#80)
tmr(not(SV52_�V�����_) and not(XSW61_�V�����_�㏸�[) and not(pnlPBXSW61_�V�����_�㏸�[),tim_notXSW61_�V�����_�㏸�[,#80)
tmr(SV57_�o�L���[�����t�g and not(XSW72_�o�L���[�}���t�g�㏸�[) and not(pnlPBXSW72_�o�L���[�}���t�g�㏸�[),tim_notXSW72_�o�L���[�}���t�g�㏸�[,#50)
tmr(not(SV57_�o�L���[�����t�g) and not(XSW71_�o�L���[�}���t�g���~�[) and not(pnlPBXSW71_�o�L���[�}���t�g���~�[),tim_notXSW71_�o�L���[�}���t�g���~�[,#50)

if LDP(SV52_�V�����_) and XSW62_�V�����_���~�[ and not(pnlPBXSW62_�V�����_���~�[) then
	SET(tim_XSW62_�V�����_���~�[)
end if
if LDF(SV52_�V�����_) and XSW61_�V�����_�㏸�[ and not(pnlPBXSW61_�V�����_�㏸�[) then
	SET(tim_XSW61_�V�����_�㏸�[)
end if
if LDP(SV57_�o�L���[�����t�g) and XSW72_�o�L���[�}���t�g�㏸�[ and not(pnlPBXSW72_�o�L���[�}���t�g�㏸�[) then
	SET(tim_XSW72_�o�L���[�}���t�g�㏸�[)
end if
if LDF(SV57_�o�L���[�����t�g) and XSW71_�o�L���[�}���t�g���~�[ and not(pnlPBXSW71_�o�L���[�}���t�g���~�[) then
	SET(tim_XSW71_�o�L���[�}���t�g���~�[)
end if

'passtimXSW62_�V�����_���~�[_val=#3000
tms(SV52_�V�����_,passtimXSW62_�V�����_���~�[,passtimXSW62_�V�����_���~�[_val)
'passtimXSW61_�V�����_�㏸�[_val=#3000
tms(not(SV52_�V�����_),passtimXSW61_�V�����_�㏸�[,passtimXSW61_�V�����_�㏸�[_val)
'passtimXSW72_�o�L���[�}���t�g�㏸�[_val=#2000
tms(SV57_�o�L���[�����t�g,passtimXSW72_�o�L���[�}���t�g�㏸�[,passtimXSW72_�o�L���[�}���t�g�㏸�[_val)
'passtimXSW71_�o�L���[�}���t�g���~�[_val=#2000
tms(not(SV57_�o�L���[�����t�g),passtimXSW71_�o�L���[�}���t�g���~�[,passtimXSW71_�o�L���[�}���t�g���~�[_val)

if not(�o�L���[���֎~) then
	if (ldp(tim_XSW62_�V�����_���~�[.B) or ldp(tim_notXSW62_�V�����_���~�[.B)) and not(pnlPBXSW62_�V�����_���~�[) then
		almXSW62_�V�����_���~�[=ON
		pnlPBXSW62_�V�����_���~�[=ON
		if tim_XSW62_�V�����_���~�[ then
			res(tim_XSW62_�V�����_���~�[)
		end if
		�o�L���[�����j�b�gErrStep=1
		
	else if (ldp(tim_XSW61_�V�����_�㏸�[.B) or ldp(tim_notXSW61_�V�����_�㏸�[.B)) and not(pnlPBXSW61_�V�����_�㏸�[) then
		almXSW61_�V�����_�㏸�[=ON
		pnlPBXSW61_�V�����_�㏸�[=ON
		if tim_XSW61_�V�����_�㏸�[ then
			res(tim_XSW61_�V�����_�㏸�[)
		end if
		�o�L���[�����j�b�gErrStep=1

	else if (ldp(tim_XSW72_�o�L���[�}���t�g�㏸�[.B) or ldp(tim_notXSW72_�o�L���[�}���t�g�㏸�[.B)) and not(pnlPBXSW72_�o�L���[�}���t�g�㏸�[) then
		almXSW72_�o�L���[�}���t�g�㏸�[=ON
		pnlPBXSW72_�o�L���[�}���t�g�㏸�[=ON
		if tim_XSW72_�o�L���[�}���t�g�㏸�[ then
			res(tim_XSW72_�o�L���[�}���t�g�㏸�[)
		end if
		�o�L���[�����j�b�gErrStep=1

	else if (ldp(tim_XSW71_�o�L���[�}���t�g���~�[.B) or ldp(tim_notXSW71_�o�L���[�}���t�g���~�[.B)) and not(pnlPBXSW71_�o�L���[�}���t�g���~�[) then
		almXSW71_�o�L���[�}���t�g���~�[=ON
		pnlPBXSW71_�o�L���[�}���t�g���~�[=ON
		if tim_XSW71_�o�L���[�}���t�g���~�[ then
			res(tim_XSW71_�o�L���[�}���t�g���~�[)
		end if
		�o�L���[�����j�b�gErrStep=1
		
	end if
else
	res(tim_XSW62_�V�����_���~�[)
	res(tim_XSW61_�V�����_�㏸�[)
	res(tim_XSW72_�o�L���[�}���t�g�㏸�[)
	res(tim_XSW71_�o�L���[�}���t�g���~�[)

	res(tim_notXSW62_�V�����_���~�[)
	res(tim_notXSW61_�V�����_�㏸�[)
	res(tim_notXSW72_�o�L���[�}���t�g�㏸�[)
	res(tim_notXSW71_�o�L���[�}���t�g���~�[)

end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �o�L���[�����j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �o�L���[�����j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �o�L���[�����j�b�gEmg	���̏��~

if 0 then
	pauseMC24_�z���|���v=ON
end if

if �o�L���[�����j�b�gEmgStep=0 then  
	
	if �o�L���[�����j�b�gErrStep=0  then

	if not(�o�L���[�����j�b�gOrgErr) then

	if (�o�L���[�����j�b�gAutoMode and ��������AutoMode ) or �o�L���[�����j�b�gstep<>0 then
	
		if not(�o�L���[�����j�b�gAutoMode and ��������AutoMode ) then
			�o�L���[�����j�b�gAutoRun=OFF
		end if

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)
		tmr(tim_MC24_�z���|���v�҂�����,tim_MC24_�z���|���v�҂�����_val)
		tmr(tim_MC24_�z���|���v,tim_MC24_�z���|���v_val)

		select case �o�L���[�����j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �o�L���[�����j�b�gAutoRun then
				inc(�o�L���[�����j�b�gstep)
			else 
				�o�L���[�����j�b�gstep=0 '�I���ҋ@
			end if
		
		case 2
				inc(�o�L���[�����j�b�gstep)
		
		case 3
		' [ �W�J�}�ړ���~�m�F ]
			if �������o�L���[���r�o�v��=OFF and  �����R���x�AD���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH27_�����m and PH28_�t�^���m then
						inc(�o�L���[�����j�b�gstep) '�v���Z�X����
						
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH27_�����m) and PH28_�t�^���m then 
							�������o�L���[���r�o�v��=ON
							�o�L���[�����j�b�gstep=1
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
						else
							�������o�L���[���r�o�v��=ON
							�o�L���[�����j�b�gstep=1  '�I��
					end if
			
			else
			
				�o�L���[�����j�b�gstep=1
			
			end if
		
		case 4
			if ((XSW61_�V�����_�㏸�[ and not(pnlPBXSW61_�V�����_�㏸�[)) or passXSW61_�V�����_�㏸�[) and ((XSW71_�o�L���[�}���t�g���~�[ and not(pnlPBXSW71_�o�L���[�}���t�g���~�[)) or passXSW71_�o�L���[�}���t�g���~�[) then
				inc(�o�L���[�����j�b�gstep)
			else
				�o�L���[�����j�b�gstep=1
			end if

		case 5
		' [ ���j�b�g�����o ]
			if not(�o�L���[���֎~) and (�����o�L���[�� or StageDevice200=$8000) then
				�o�L���[�����j�b�gstep=100 '�v���Z�X����
			else
				�������o�L���[���r�o�v��=ON
				�o�L���[�����j�b�gstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			if �o�L���[������ then '�����ړ���OFF
				�o�L���[�����j�b�gstep=199
			else
				inc(�o�L���[�����j�b�gstep)
			end if
		
		case 101
			mSV57_�o�L���[�����t�g=ON
			inc(�o�L���[�����j�b�gstep)

		case 102
			if (XSW72_�o�L���[�}���t�g�㏸�[ and not(pnlPBXSW72_�o�L���[�}���t�g�㏸�[)) or passXSW72_�o�L���[�}���t�g�㏸�[ then
				inc(�o�L���[�����j�b�gstep)
			end if			
		
		case 103
			mSV51_�����d����=ON	'�|���v��p�p����ON
			mSV52_�V�����_=ON	'�V�����_���~
			
			tim_MC24_�z���|���v�҂�����_val=#30 '�z�����ԑ҂�����
			res(tim_MC24_�z���|���v�҂�����)
			
			inc(�o�L���[�����j�b�gstep)
			
		case 104
			if (XSW62_�V�����_���~�[ and not(pnlPBXSW62_�V�����_���~�[)) or passXSW62_�V�����_���~�[ then
				inc(�o�L���[�����j�b�gstep)
			end if
		

		case 105
			if tim_MC24_�z���|���v�҂�����.B then
				inc(�o�L���[�����j�b�gstep)
			end if			

		case 106
			mMC24_�z���|���v=ON
			inc(�o�L���[�����j�b�gstep)
			
		case 107
			tim_MC24_�z���|���v_val=#80 '�z������
			res(tim_MC24_�z���|���v)
			inc(�o�L���[�����j�b�gstep)
	
		case 108
			if tim_MC24_�z���|���v.B then
				inc(�o�L���[�����j�b�gstep)
			end if

		case 109
			mMC24_�z���|���v=OFF
			mSV51_�����d����=OFF	'�|���v��p�p����OFF
			mSV52_�V�����_=OFF	'�V�����_�㏸
			mSV57_�o�L���[�����t�g=OFF
			inc(�o�L���[�����j�b�gstep)
		
		case 110
			if (XSW61_�V�����_�㏸�[ and not(pnlPBXSW61_�V�����_�㏸�[)) or passXSW61_�V�����_�㏸�[ then
				inc(�o�L���[�����j�b�gstep)
			end if	

		case 111
			if (XSW71_�o�L���[�}���t�g���~�[ and not(pnlPBXSW71_�o�L���[�}���t�g���~�[)) or passXSW71_�o�L���[�}���t�g���~�[ then
				inc(�o�L���[�����j�b�gstep)
			end if			

		case 112
			�o�L���[�����j�b�gstep=199

		'------------------------------------------------------
		case 199
			�o�L���[������=ON
			�������o�L���[���r�o�v��=ON
			�o�L���[�����j�b�gstep=1
		'------------------------------------------------------

		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�o�L���[�����j�b�gAutoRun=OFF
		
		�o�L���[�����j�b�gstep=0 '�I��
		�o�L���[������=OFF
		
		if ldp(pnlPBSV52_�V�����_) then
			if mSV52_�V�����_ then
				mSV52_�V�����_=OFF
				mSV51_�����d����=OFF
			else
				mSV52_�V�����_=ON
			end if
		end if
		
		if LDP(pnlPBMC24_�z���|���v) then
			if mMC24_�z���|���v then
				mMC24_�z���|���v=OFF
			else if not(mMC24_�z���|���v)  and ((XSW62_�V�����_���~�[ and not(pnlPBXSW62_�V�����_���~�[)) or passXSW62_�V�����_���~�[) then
				mMC24_�z���|���v=ON
			end if
		end if
				
		if LDP(pnlPBSV51_�����d����) then '�����d���كp�l�����蓖�ĕs�
			if mSV51_�����d���� then
				mSV51_�����d����=OFF
			else
				mSV51_�����d����=ON
			end if
		end if
		
		if LDP(pnlPBSV57_�o�L���[�����t�g) then
			if mSV57_�o�L���[�����t�g then
				mSV57_�o�L���[�����t�g=OFF
			else
				mSV57_�o�L���[�����t�g=ON
			end if
		end if
	
	end if '�o�L���[�����j�b�gAutoMode and not(�o�L���[�����j�b�gOrgErrStep)

	'===================================================================================================================
	'�y �o�L���[�����j�b�gOrgErr���� �z
	else

		if ResetFlg then
			�o�L���[�����j�b�gOrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		�o�L���[�����j�b�gErr=ON

		select case �o�L���[�����j�b�gErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW62_�V�����_���~�[=OFF
				almXSW61_�V�����_�㏸�[=OFF
				almXSW71_�o�L���[�}���t�g���~�[=OFF
				almXSW72_�o�L���[�}���t�g�㏸�[=OFF
				inc(�o�L���[�����j�b�gErrStep)
			end if
		case 2
			�o�L���[�����j�b�gErr=OFF
			
			res(tim_XSW62_�V�����_���~�[)
			res(tim_XSW61_�V�����_�㏸�[)
			res(tim_XSW71_�o�L���[�}���t�g���~�[)
			res(tim_XSW72_�o�L���[�}���t�g�㏸�[)
			
			res(tim_notXSW62_�V�����_���~�[)
			res(tim_notXSW61_�V�����_�㏸�[)
			res(tim_notXSW71_�o�L���[�}���t�g���~�[)
			res(tim_notXSW72_�o�L���[�}���t�g�㏸�[)

			�o�L���[�����j�b�gErrStep=0
		end select

	end if 'if �o�L���[�����j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �o�L���[�����j�b�gEmgStep
	case 0
	
	case 1
		�o�L���[�����j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�o�L���[�����j�b�gAutoMode and ��������AutoMode ) or �o�L���[�����j�b�gstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			pauseMC24_�z���|���v=ON
			pauseSV51_�����d����=ON
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV52_�V�����_=OFF
			mMC24_�z���|���v=OFF
			mSV51_�����d����=OFF
			mSV57_�o�L���[�����t�g=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�o�L���[�����j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�o�L���[�����j�b�gEmgStep)
		end if
	case 3
		if (�o�L���[�����j�b�gAutoMode and ��������AutoMode ) or �o�L���[�����j�b�gstep<>0 then
			if StartFlg then
				pauseMC24_�z���|���v=OFF
				pauseSV51_�����d����=OFF

				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				
				
				'---------------------------------
				inc(�o�L���[�����j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�o�L���[�����j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�o�L���[�����j�b�gEmgStep=0
		�o�L���[�����j�b�gEmg=OFF
	end select
		
end if 'if �o�L���[�����j�b�gEmgStep=0 then
