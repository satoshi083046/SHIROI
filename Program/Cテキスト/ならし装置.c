'�Ȃ炵���u
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�Ȃ炵���j�b�g
'	
'===================================================================================================================

'�y ���������� �z

if CR2008 then
    �Ȃ炵���uAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �Ȃ炵���uAutoRun=OFF
    �Ȃ炵���u����=ON
    �Ȃ炵���uOrgErr=OFF
    �Ȃ炵���uErr=OFF
    �Ȃ炵���uEmg=OFF
    �Ȃ炵���ustep=0
    �Ȃ炵���uErrStep=0
    �Ȃ炵���uOrgErrStep=0
    �Ȃ炵���uEmgStep=0
	
	�Ȃ炵�r�o�v��=ON
	
	SV23_�Ȃ炵�O�istep=1
	SV24_�Ȃ炵���step=0

end if

'===================================================================================================================
'�y ���_ �z
�Ȃ炵���uOrg=(XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[
�Ȃ炵���uOrg=�Ȃ炵���uOrg and (XSW27_�Ȃ炵��ޒ[ and not(pnlPBXSW27_�Ȃ炵��ޒ[)) or passXSW27_�Ȃ炵��ޒ[
�Ȃ炵���uOrg=�Ȃ炵���uOrg or not(�Ȃ炵���u����)

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then	
	�Ȃ炵���uEmg=ON
	�Ȃ炵���uEmgStep=1
end if

'------------------------------------------------------
'�������󂯂��痣�E
tmr(tim_SV23_�Ȃ炵�O�i,tim_SV23_�Ȃ炵�O�i_val)
select case SV23_�Ȃ炵�O�istep
case 0
case 1
	if not(XSW24_�Ȃ炵�O�i�[) or pnlPBXSW24_�Ȃ炵�O�i�[ then
		mSV23_�Ȃ炵�O�i=ON
		mSV24_�Ȃ炵���=OFF
	end if
	
	inc(SV23_�Ȃ炵�O�istep)
case 2
	if (XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[)) or passXSW24_�Ȃ炵�O�i�[  then
		inc(SV23_�Ȃ炵�O�istep)
	end if
case 3
	mSV23_�Ȃ炵�O�i=OFF
	mSV24_�Ȃ炵���=OFF
	SV23_�Ȃ炵�O�istep=0
end select
'------------------------------------------------------
'�������󂯂Ɉړ�
tmr(tim_SV24_�Ȃ炵���,tim_SV24_�Ȃ炵���_val)
select case SV24_�Ȃ炵���step
case 0
case 1
	if not(XSW23_�Ȃ炵��ޒ[) or pnlPBXSW23_�Ȃ炵��ޒ[ then
		mSV23_�Ȃ炵�O�i=OFF
		mSV24_�Ȃ炵���=ON
	end if
	inc(SV24_�Ȃ炵���step)
case 2
	if (XSW23_�Ȃ炵��ޒ[ and not(pnlPBXSW23_�Ȃ炵��ޒ[)) or passXSW23_�Ȃ炵��ޒ[ then
		inc(SV24_�Ȃ炵���step)	
	end if
case 3
	mSV23_�Ȃ炵�O�i=OFF
	mSV24_�Ȃ炵���=OFF
	SV24_�Ȃ炵���step=0
end select
'------------------------------------------------------


'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z


tmr(SV23_�Ȃ炵�O�i and not(XSW24_�Ȃ炵�O�i�[) and not(pnlPBXSW24_�Ȃ炵�O�i�[),tim_notXSW24_�Ȃ炵�O�i�[,#60)
tmr(SV24_�Ȃ炵��� and not(XSW23_�Ȃ炵��ޒ[) and not(pnlPBXSW23_�Ȃ炵��ޒ[),tim_notXSW23_�Ȃ炵��ޒ[,#60)
tmr(SV25_�Ȃ炵���~ and not(XSW26_�Ȃ炵���~�[) and not(pnlPBXSW26_�Ȃ炵���~�[),tim_notXSW26_�Ȃ炵���~�[,#80)
tmr(SV26_�Ȃ炵�㏸ and not(XSW25_�Ȃ炵�㏸�[) and not(pnlPBXSW25_�Ȃ炵�㏸�[),tim_notXSW25_�Ȃ炵�㏸�[,#80)
tmr(SV27_�Ȃ炵�O�i and not(XSW28_�Ȃ炵�O�i�[) and not(pnlPBXSW28_�Ȃ炵�O�i�[),tim_notXSW28_�Ȃ炵�O�i�[,#80)
tmr(SV28_�Ȃ炵��� and not(XSW27_�Ȃ炵��ޒ[) and not(pnlPBXSW27_�Ȃ炵��ޒ[),tim_notXSW27_�Ȃ炵��ޒ[,#80)

if LDP(SV23_�Ȃ炵�O�i) and XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[) then
	SET(tim_XSW24_�Ȃ炵�O�i�[)
end if
if LDP(SV24_�Ȃ炵���) and XSW23_�Ȃ炵��ޒ[ and not(pnlPBXSW23_�Ȃ炵��ޒ[) then
	SET(tim_XSW23_�Ȃ炵��ޒ[)
end if
if LDP(SV25_�Ȃ炵���~) and XSW26_�Ȃ炵���~�[ and not(pnlPBXSW26_�Ȃ炵���~�[) then
	SET(tim_XSW26_�Ȃ炵���~�[)
end if
if LDP(SV26_�Ȃ炵�㏸) and XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[) then
	SET(tim_XSW25_�Ȃ炵�㏸�[)
end if
if LDP(SV27_�Ȃ炵�O�i) and XSW28_�Ȃ炵�O�i�[ and not(pnlPBXSW28_�Ȃ炵�O�i�[) then
	SET(tim_XSW28_�Ȃ炵�O�i�[)
end if
if LDP(SV28_�Ȃ炵���) and XSW27_�Ȃ炵��ޒ[ and not(pnlPBXSW27_�Ȃ炵��ޒ[) then
	SET(tim_XSW27_�Ȃ炵��ޒ[)
end if	

if SV23_�Ȃ炵�O�i and not(SV24_�Ȃ炵���) then
	KeepSV23_�Ȃ炵�O�i=ON
	KeepSV24_�Ȃ炵���=OFF
else if SV24_�Ȃ炵��� and not(SV23_�Ȃ炵�O�i) then
	KeepSV23_�Ȃ炵�O�i=OFF
	KeepSV24_�Ȃ炵���=ON
end if

if SV25_�Ȃ炵���~ and not(SV26_�Ȃ炵�㏸) then
	KeepSV25_�Ȃ炵���~=ON
	KeepSV26_�Ȃ炵�㏸=OFF
else if SV26_�Ȃ炵�㏸ and not(SV25_�Ȃ炵���~) then
	KeepSV25_�Ȃ炵���~=OFF
	KeepSV26_�Ȃ炵�㏸=ON
end if

if SV27_�Ȃ炵�O�i and not(SV28_�Ȃ炵���) then
	KeepSV27_�Ȃ炵�O�i=ON
	KeepSV28_�Ȃ炵���=OFF
else if SV28_�Ȃ炵��� and not(SV27_�Ȃ炵�O�i) then
	KeepSV27_�Ȃ炵�O�i=OFF
	KeepSV28_�Ȃ炵���=ON
end if


'passtimXSW24_�Ȃ炵�O�i�[_val=#3000
tms(KeepSV23_�Ȃ炵�O�i,passtimXSW24_�Ȃ炵�O�i�[,passtimXSW24_�Ȃ炵�O�i�[_val)
'passtimXSW23_�Ȃ炵��ޒ[_val=#3000
tms(KeepSV24_�Ȃ炵���,passtimXSW23_�Ȃ炵��ޒ[,passtimXSW23_�Ȃ炵��ޒ[_val)
'passtimXSW26_�Ȃ炵���~�[_val=#3000
tms(KeepSV25_�Ȃ炵���~,passtimXSW26_�Ȃ炵���~�[,passtimXSW26_�Ȃ炵���~�[_val)
'passtimXSW25_�Ȃ炵�㏸�[_val=#3000
tms(KeepSV26_�Ȃ炵�㏸,passtimXSW25_�Ȃ炵�㏸�[,passtimXSW25_�Ȃ炵�㏸�[_val)
'passtimXSW28_�Ȃ炵�O�i�[_val=#3000
tms(KeepSV27_�Ȃ炵�O�i,passtimXSW28_�Ȃ炵�O�i�[,passtimXSW28_�Ȃ炵�O�i�[_val)
'passtimXSW27_�Ȃ炵��ޒ[_val=#3000
tms(KeepSV28_�Ȃ炵���,passtimXSW27_�Ȃ炵��ޒ[,passtimXSW27_�Ȃ炵��ޒ[_val)



if �Ȃ炵���u���� then
	if (ldp(tim_XSW24_�Ȃ炵�O�i�[.B) or ldp(tim_notXSW24_�Ȃ炵�O�i�[)) and not(pnlPBXSW24_�Ȃ炵�O�i�[) then
		almXSW24_�Ȃ炵�O�i�[=ON
		pnlPBXSW24_�Ȃ炵�O�i�[=ON
		if tim_XSW24_�Ȃ炵�O�i�[ then
			res(tim_XSW24_�Ȃ炵�O�i�[)
		end if
		�Ȃ炵���uErrStep=1

	else if (ldp(tim_XSW23_�Ȃ炵��ޒ[.B) or ldp(tim_notXSW23_�Ȃ炵��ޒ[)) and not(pnlPBXSW23_�Ȃ炵��ޒ[) then	
		almXSW23_�Ȃ炵��ޒ[=ON
		pnlPBXSW23_�Ȃ炵��ޒ[=ON
		if tim_XSW23_�Ȃ炵��ޒ[ then
			res(tim_XSW23_�Ȃ炵��ޒ[)
		end if
		�Ȃ炵���uErrStep=1

	else if (ldp(tim_XSW26_�Ȃ炵���~�[.B) or ldp(tim_notXSW26_�Ȃ炵���~�[)) and not(pnlPBXSW26_�Ȃ炵���~�[) then
		almXSW26_�Ȃ炵���~�[=ON
		pnlPBXSW26_�Ȃ炵���~�[=ON
		if tim_XSW26_�Ȃ炵���~�[ then
			res(tim_XSW26_�Ȃ炵���~�[)
		end if
		�Ȃ炵���uErrStep=1

	else if (ldp(tim_XSW25_�Ȃ炵�㏸�[.B) or ldp(tim_notXSW25_�Ȃ炵�㏸�[)) and not(pnlPBXSW25_�Ȃ炵�㏸�[) then
		almXSW25_�Ȃ炵�㏸�[=ON
		pnlPBXSW25_�Ȃ炵�㏸�[=ON
		if tim_XSW25_�Ȃ炵�㏸�[ then
			res(tim_XSW25_�Ȃ炵�㏸�[)
		end if
		�Ȃ炵���uErrStep=1

	else if (ldp(tim_XSW28_�Ȃ炵�O�i�[.B) or ldp(tim_notXSW28_�Ȃ炵�O�i�[)) and not(pnlPBXSW28_�Ȃ炵�O�i�[) then
		almXSW28_�Ȃ炵�O�i�[=ON
		pnlPBXSW28_�Ȃ炵�O�i�[=ON
		if tim_XSW28_�Ȃ炵�O�i�[ then
			res(tim_XSW28_�Ȃ炵�O�i�[)
		end if
		�Ȃ炵���uErrStep=1

	else if (ldp(tim_XSW27_�Ȃ炵��ޒ[.B) or ldp(tim_notXSW27_�Ȃ炵��ޒ[)) and not(pnlPBXSW27_�Ȃ炵��ޒ[) then
		almXSW27_�Ȃ炵��ޒ[=ON
		pnlPBXSW27_�Ȃ炵��ޒ[=ON
		if tim_XSW27_�Ȃ炵��ޒ[ then
			res(tim_XSW27_�Ȃ炵��ޒ[)
		end if
		�Ȃ炵���uErrStep=1

	end if
else
	res(tim_XSW24_�Ȃ炵�O�i�[)
	res(tim_XSW23_�Ȃ炵��ޒ[)
	res(tim_XSW26_�Ȃ炵���~�[)
	res(tim_XSW25_�Ȃ炵�㏸�[)
	res(tim_XSW28_�Ȃ炵�O�i�[)
	res(tim_XSW27_�Ȃ炵��ޒ[)

	res(tim_notXSW24_�Ȃ炵�O�i�[)
	res(tim_notXSW23_�Ȃ炵��ޒ[)
	res(tim_notXSW26_�Ȃ炵���~�[)
	res(tim_notXSW25_�Ȃ炵�㏸�[)
	res(tim_notXSW28_�Ȃ炵�O�i�[)
	res(tim_notXSW27_�Ȃ炵��ޒ[)
end if


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �Ȃ炵���uAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �Ȃ炵���uAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �Ȃ炵���uEmg	���̏��~


if �Ȃ炵���uEmgStep=0 then  
	
	if �Ȃ炵���uErrStep=0  then

	if not(�Ȃ炵���uOrgErr) then

	if (�Ȃ炵���uAutoMode and ��������AutoMode ) or �Ȃ炵���ustep<>0 then
		
	if not(�Ȃ炵���uAutoMode and ��������AutoMode ) then
			�Ȃ炵���uAutoRUn=OFF
		end if

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �Ȃ炵���ustep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
				�Ȃ炵���uStatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �Ȃ炵���uAutoRun then
				�Ȃ炵���uStatusMsg=#30	'	�ҋ@��
				SV24_�Ȃ炵���step=1
				inc(�Ȃ炵���ustep)
			else 
				SV23_�Ȃ炵�O�istep=1
				�Ȃ炵���ustep=0 '�I���ҋ@ 
			end if
		
		case 2
				if SV24_�Ȃ炵���step=0 then
					inc(�Ȃ炵���ustep)
				end if
		case 3
		' [ �W�J�}�ړ���~�m�F ]
			if �Ȃ炵�r�o�v��=OFF and  �����R���x�AC���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH17_�����m and PH18_�t�^���m then
						if ANDA(StageDevice8,$200)=$200 or ANDA(StageDevice8,$400)=$400 or 1 then 
							inc(�Ȃ炵���ustep) '�v���Z�X����
						else
							�Ȃ炵�r�o�v��=ON
							�Ȃ炵���ustep=1						
						end if
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH17_�����m) and PH18_�t�^���m then 
							�Ȃ炵�r�o�v��=ON
							�Ȃ炵���ustep=1
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
						else
							�Ȃ炵�r�o�v��=ON
							�Ȃ炵���ustep=1  '�I��
					end if
			
			else
			
				�Ȃ炵���ustep=1
			
			end if
		
		case 4
			if ((XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[) and ((XSW27_�Ȃ炵��ޒ[ and not(pnlPBXSW27_�Ȃ炵��ޒ[)) or pnlPBXSW27_�Ȃ炵��ޒ[) then
				inc(�Ȃ炵���ustep)
			else
				�Ȃ炵���ustep=1
			end if

		case 5
		' [ ���j�b�g�����o ]
			if �Ȃ炵���u���� then
				�Ȃ炵���ustep=100 '�v���Z�X����
			else
				�Ȃ炵�r�o�v��=ON
				�Ȃ炵���ustep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100		
			if �Ȃ炵���� then '�����ړ���OFF
				�Ȃ炵���ustep=199
			else
				inc(�Ȃ炵���ustep)
			end if
				
		case 101
			�Ȃ炵���uStatusMsg=#31	'	�Ȃ炵��
			
			DM_�Ȃ炵�񐔌��ݒl=0
			mSV23_�Ȃ炵�O�i=ON	'�������󂯂��痣�E
			inc(�Ȃ炵���ustep)
			
		case 102
			if (XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[)) or passXSW24_�Ȃ炵�O�i�[  then
				inc(�Ȃ炵���ustep)
			end if
		
		case 103
			mSV23_�Ȃ炵�O�i=OFF				
			tim_procstep_val=#0
			res(tim_procstep)
			inc(�Ȃ炵���ustep)

		case 104
			if tim_procstep.B then
				inc(�Ȃ炵���ustep)
			end if
				
		case 105
			mSV25_�Ȃ炵���~=ON
			inc(�Ȃ炵���ustep)

		case 106
			if (XSW26_�Ȃ炵���~�[ and not(pnlPBXSW26_�Ȃ炵���~�[)) or passXSW26_�Ȃ炵���~�[ then
				inc(�Ȃ炵���ustep)
			end if
		
		case 107
			mSV25_�Ȃ炵���~=OFF				
			tim_procstep_val=#0
			res(tim_procstep)
			inc(�Ȃ炵���ustep)
			
		case 108
			if tim_procstep.B then		
				inc(�Ȃ炵���ustep)
			end if
		
		case 109
			inc(�Ȃ炵���ustep)
		
		'----------------------------------------------------
		case 110 '�Ȃ炵���[�v  <-
			if DM_�Ȃ炵�񐔌��ݒl < DM_�Ȃ炵�񐔐ݒ�l then
				inc(�Ȃ炵���ustep)
			else 
				�Ȃ炵���ustep=150
			end if
		
		case 111
			mSV27_�Ȃ炵�O�i=ON
			inc(�Ȃ炵���ustep)
		
		case 112
			if (XSW28_�Ȃ炵�O�i�[ and not(pnlPBXSW28_�Ȃ炵�O�i�[)) or passXSW28_�Ȃ炵�O�i�[ then
				inc(�Ȃ炵���ustep)
			end if	
		
		case 113
			mSV27_�Ȃ炵�O�i=OFF
			tim_procstep_val=#5
			res(tim_procstep)
			inc(�Ȃ炵���ustep)

		case 114
			if tim_procstep.B then
				inc(�Ȃ炵���ustep)
			end if
			
		case 115
			mSV28_�Ȃ炵���=ON
			inc(�Ȃ炵���ustep)
			
		case 116
			if (XSW27_�Ȃ炵��ޒ[ and not(pnlPBXSW27_�Ȃ炵��ޒ[)) or passXSW27_�Ȃ炵��ޒ[ then
				inc(�Ȃ炵���ustep)
			end if
		
		case 117
			mSV28_�Ȃ炵���=OFF
			tim_procstep_val=#5
			res(tim_procstep)
			inc(�Ȃ炵���ustep)

		case 118
			if tim_procstep.B then
				inc(DM_�Ȃ炵�񐔌��ݒl)
				�Ȃ炵���ustep=110 '�Ȃ炵���[�v ->
			end if
		'----------------------------------------------------			
		case 150
			mSV26_�Ȃ炵�㏸=ON
			inc(�Ȃ炵���ustep)
			
		case 151
			if (XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[ then
				inc(�Ȃ炵���ustep)
			end if
		
		case 152
			mSV26_�Ȃ炵�㏸=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			inc(�Ȃ炵���ustep)
			
			�Ȃ炵����=ON
			�Ȃ炵�r�o�v��=ON

		
		case 153
			if tim_procstep.B then
				inc(�Ȃ炵���ustep)
			end if
		
		case 154
			mSV23_�Ȃ炵�O�i=OFF	'�������󂯂Ɉړ�
			mSV24_�Ȃ炵���=ON
			inc(�Ȃ炵���ustep)
			
		case 155
			if (XSW23_�Ȃ炵��ޒ[ and not(pnlPBXSW23_�Ȃ炵��ޒ[)) or passXSW23_�Ȃ炵��ޒ[ then
				inc(�Ȃ炵���ustep)
			end if

		case 156
			mSV24_�Ȃ炵���=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			�Ȃ炵���ustep=199

		case 199
			�Ȃ炵���ustep=1

		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�Ȃ炵���uAutoRun=OFF
		
		�Ȃ炵���ustep=0 '�I��
		�Ȃ炵����=OFF

		'---------------------------------------------------------
		if ldp(pnlPBSV23_�Ȃ炵�O�i)  then
			if ((XSW23_�Ȃ炵��ޒ[ and not(pnlPBXSW23_�Ȃ炵��ޒ[)) or passXSW23_�Ȃ炵��ޒ[) and ((XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[)then
				mSV23_�Ȃ炵�O�i=ON
				mSV24_�Ȃ炵���=OFF		
			end if
		end if
		if ldp(pnlPBSV24_�Ȃ炵���)  then
			if ((XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[)) or passXSW24_�Ȃ炵�O�i�[) and ((XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[) then
				mSV23_�Ȃ炵�O�i=OFF
				mSV24_�Ȃ炵���=ON
			end if
		end if
		if mSV23_�Ȃ炵�O�i and ((XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[)) or passXSW24_�Ȃ炵�O�i�[) then
			mSV23_�Ȃ炵�O�i=OFF
		end if 
		if mSV24_�Ȃ炵��� and ((XSW23_�Ȃ炵��ޒ[ and not(pnlPBXSW23_�Ȃ炵��ޒ[)) or passXSW23_�Ȃ炵��ޒ[) then 
			mSV24_�Ȃ炵���=OFF
		end if
		'---------------------------------------------------------
		if ldp(pnlPBSV25_�Ȃ炵���~) then
			if ((XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[) and ((XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[)) or passXSW24_�Ȃ炵�O�i�[) then
				mSV25_�Ȃ炵���~=ON
				mSV26_�Ȃ炵�㏸=OFF
			end if
		end if
		if ldp(pnlPBSV26_�Ȃ炵�㏸) then
			if ((XSW26_�Ȃ炵���~�[ and not(pnlPBXSW26_�Ȃ炵���~�[)) or passXSW26_�Ȃ炵���~�[) and ((XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[)) or passXSW24_�Ȃ炵�O�i�[) then
				mSV25_�Ȃ炵���~=OFF
				mSV26_�Ȃ炵�㏸=ON
			end if
		end if
		if mSV25_�Ȃ炵���~ and ((XSW26_�Ȃ炵���~�[ and not(pnlPBXSW26_�Ȃ炵���~�[)) or passXSW26_�Ȃ炵���~�[) then
			mSV25_�Ȃ炵���~=OFF
		end if
		if mSV26_�Ȃ炵�㏸ and ((XSW25_�Ȃ炵�㏸�[ and not(pnlPBXSW25_�Ȃ炵�㏸�[)) or passXSW25_�Ȃ炵�㏸�[) then
			mSV26_�Ȃ炵�㏸=OFF
		end if
		'---------------------------------------------------------
		if ldp(pnlPBSV27_�Ȃ炵�O�i) then
			if ((XSW27_�Ȃ炵��ޒ[ and not(pnlPBXSW27_�Ȃ炵��ޒ[)) or passXSW27_�Ȃ炵��ޒ[) and ((XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[)) or passXSW24_�Ȃ炵�O�i�[) then
				mSV27_�Ȃ炵�O�i=ON
				mSV28_�Ȃ炵���=OFF
			end if
		end if
		if ldp(pnlPBSV28_�Ȃ炵���) then
			if ((XSW28_�Ȃ炵�O�i�[ and not(pnlPBXSW28_�Ȃ炵�O�i�[)) or passXSW28_�Ȃ炵�O�i�[) and ((XSW24_�Ȃ炵�O�i�[ and not(pnlPBXSW24_�Ȃ炵�O�i�[)) or passXSW24_�Ȃ炵�O�i�[) then
				mSV27_�Ȃ炵�O�i=OFF
				mSV28_�Ȃ炵���=ON
			end if
		end if
		if mSV27_�Ȃ炵�O�i and ((XSW28_�Ȃ炵�O�i�[ and not(pnlPBXSW28_�Ȃ炵�O�i�[)) or passXSW28_�Ȃ炵�O�i�[) then
			mSV27_�Ȃ炵�O�i=OFF
		end if
		if mSV28_�Ȃ炵��� and ((XSW27_�Ȃ炵��ޒ[ and not(pnlPBXSW27_�Ȃ炵��ޒ[)) or passXSW27_�Ȃ炵��ޒ[) then
			mSV28_�Ȃ炵���=OFF
		end if
		'---------------------------------------------------------
	end if '�Ȃ炵���uAutoMode and not(�Ȃ炵���uOrgErrStep)

	'===================================================================================================================
	'�y �Ȃ炵���uOrgErr���� �z
	else

		if ResetFlg then
			�Ȃ炵���uOrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		
		�Ȃ炵���uErr=ON
		
		select case �Ȃ炵���uErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW24_�Ȃ炵�O�i�[=OFF
				almXSW23_�Ȃ炵��ޒ[=OFF
				almXSW26_�Ȃ炵���~�[=OFF
				almXSW25_�Ȃ炵�㏸�[=OFF
				almXSW28_�Ȃ炵�O�i�[=OFF
				almXSW27_�Ȃ炵��ޒ[=OFF
			
				inc(�Ȃ炵���uErrStep)
			end if
		case 2
			res(tim_XSW24_�Ȃ炵�O�i�[)
			res(tim_XSW23_�Ȃ炵��ޒ[)
			res(tim_XSW26_�Ȃ炵���~�[)
			res(tim_XSW25_�Ȃ炵�㏸�[)
			res(tim_XSW28_�Ȃ炵�O�i�[)
			res(tim_XSW27_�Ȃ炵��ޒ[)

			res(tim_notXSW24_�Ȃ炵�O�i�[)
			res(tim_notXSW23_�Ȃ炵��ޒ[)
			res(tim_notXSW26_�Ȃ炵���~�[)
			res(tim_notXSW25_�Ȃ炵�㏸�[)
			res(tim_notXSW28_�Ȃ炵�O�i�[)
			res(tim_notXSW27_�Ȃ炵��ޒ[)
			
			�Ȃ炵���uErr=OFF
			�Ȃ炵���uErrStep=0
		end select

	end if 'if �Ȃ炵���uErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �Ȃ炵���uEmgStep
	case 0
	
	case 1
		�Ȃ炵���uAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�Ȃ炵���uAutoMode and ��������AutoMode ) or �Ȃ炵���ustep<>0 then
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
			mSV23_�Ȃ炵�O�i=OFF
			mSV24_�Ȃ炵���=OFF
			mSV25_�Ȃ炵���~=OFF
			mSV26_�Ȃ炵�㏸=OFF
			mSV27_�Ȃ炵�O�i=OFF
			mSV28_�Ȃ炵���=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�Ȃ炵���uEmgStep)
	case 2
		if ResetFlg then
			inc(�Ȃ炵���uEmgStep)
		end if
	case 3
		if (�Ȃ炵���uAutoMode and ��������AutoMode ) or �Ȃ炵���ustep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				'---------------------------------
				inc(�Ȃ炵���uEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�Ȃ炵���uEmgStep)		
		end if				
	case 4
		timstack=OFF
		�Ȃ炵���uEmgStep=0
		�Ȃ炵���uEmg=OFF
	end select
end if 'if �Ȃ炵���uEmgStep=0 then
