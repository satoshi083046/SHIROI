'�W��胆�j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�W��胆�j�b�g
'	
'===================================================================================================================

'�y ���������� �z
if CR2008 then

	�W��胆�j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �W��胆�j�b�gAutoRun=OFF
    �W��胆�j�b�g����=ON
    �W��胆�j�b�gOrgErr=OFF
    �W��胆�j�b�gErr=OFF
    �W��胆�j�b�gEmg=OFF
    �W��胆�j�b�gstep=0
    �W��胆�j�b�gErrStep=0
    �W��胆�j�b�gOrgErrStep=0
    �W��胆�j�b�gEmgStep=0

end if
'===================================================================================================================
'�y ���_ �z
�W��胆�j�b�gOrg=((XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A) and ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B)
�W��胆�j�b�gOrg=�W��胆�j�b�gOrg or not(�W��胆�j�b�g����)
'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�W��胆�j�b�gEmg=ON
	�W��胆�j�b�gEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(SV45_�V�����_�㏸A and not(XSW55_�V�����_�㏸�[A) and not(pnlPBXSW55_�V�����_�㏸�[A),tim_notXSW55_�V�����_�㏸�[A,#40)
tmr(SV46_�V�����_���~A and not(XSW56_�V�����_���~�[A) and not(pnlPBXSW56_�V�����_���~�[A),tim_notXSW56_�V�����_���~�[A,#40)
tmr(SV47_�V�����_�㏸B and not(XSW57_�V�����_�㏸�[B) and not(pnlPBXSW57_�V�����_�㏸�[B),tim_notXSW57_�V�����_�㏸�[B,#40)
tmr(SV48_�V�����_���~B and not(XSW58_�V�����_���~�[B) and not(pnlPBXSW58_�V�����_���~�[B),tim_notXSW58_�V�����_���~�[B,#40)
tmr(SV49_�A���N�����v and not(XSW59_�A���N�����v) and not(pnlPBXSW59_�A���N�����v),tim_notXSW59_�A���N�����v,#40)
tmr(SV50_�N�����v and not(XSW60_�N�����v) and not(pnlPBXSW60_�N�����v),tim_notXSW60_�N�����v,#40)

if LDP(SV45_�V�����_�㏸A) and XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A) then
	SET(tim_XSW55_�V�����_�㏸�[A)
end if
if LDP(SV46_�V�����_���~A) and XSW56_�V�����_���~�[A and not(pnlPBXSW56_�V�����_���~�[A) then
	SET(tim_XSW56_�V�����_���~�[A)
end if
if LDP(SV47_�V�����_�㏸B) and XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B) then
	SET(tim_XSW57_�V�����_�㏸�[B)
end if
if LDP(SV48_�V�����_���~B) and XSW58_�V�����_���~�[B and not(pnlPBXSW58_�V�����_���~�[B) then
	SET(tim_XSW58_�V�����_���~�[B)
end if
if LDP(SV49_�A���N�����v) and XSW60_�N�����v and XSW59_�A���N�����v and not(pnlPBXSW59_�A���N�����v) then
	SET(tim_XSW59_�A���N�����v)
end if
if LDP(SV50_�N�����v) and XSW60_�N�����v and XSW59_�A���N�����v and not(pnlPBXSW60_�N�����v) then
	SET(tim_XSW60_�N�����v)
end if

if SV45_�V�����_�㏸A then
	KeepSV45_�V�����_�㏸A=ON
	KeepSV46_�V�����_���~A=OFF
else if SV46_�V�����_���~A then
	KeepSV45_�V�����_�㏸A=OFF
	KeepSV46_�V�����_���~A=ON
end if
if SV47_�V�����_�㏸B then
	KeepSV47_�V�����_�㏸B=ON
	KeepSV48_�V�����_���~B=OFF
else if SV48_�V�����_���~B then
	KeepSV47_�V�����_�㏸B=OFF
	KeepSV48_�V�����_���~B=ON
end if
if SV49_�A���N�����v then
	KeepSV49_�A���N�����v=ON
	KeepSV50_�N�����v=OFF
else if SV50_�N�����v then
	KeepSV49_�A���N�����v=OFF
	KeepSV50_�N�����v=ON
end if

'passtimXSW55_�V�����_�㏸�[A_val=#2000
tms(KeepSV45_�V�����_�㏸A,passtimXSW55_�V�����_�㏸�[A,passtimXSW55_�V�����_�㏸�[A_val)
'passtimXSW56_�V�����_���~�[A_val=#2000
tms(KeepSV46_�V�����_���~A,passtimXSW56_�V�����_���~�[A,passtimXSW56_�V�����_���~�[A_val)
'passtimXSW57_�V�����_�㏸�[B_val=#4000
tms(KeepSV47_�V�����_�㏸B,passtimXSW57_�V�����_�㏸�[B,passtimXSW57_�V�����_�㏸�[B_val)
'passtimXSW58_�V�����_���~�[B_val=#4000
tms(KeepSV48_�V�����_���~B,passtimXSW58_�V�����_���~�[B,passtimXSW58_�V�����_���~�[B_val)
'passtimXSW59_�A���N�����v_val=#500
tms(KeepSV49_�A���N�����v,passtimXSW59_�A���N�����v,passtimXSW59_�A���N�����v_val)
'passtimXSW60_�N�����v_val=#500
tms(KeepSV50_�N�����v,passtimXSW60_�N�����v,passtimXSW60_�N�����v_val)

if �W��胆�j�b�g���� then
	if (ldp(tim_XSW55_�V�����_�㏸�[A.B) or ldp(tim_notXSW55_�V�����_�㏸�[A)) and not(pnlPBXSW55_�V�����_�㏸�[A) then
		almXSW55_�V�����_�㏸�[A=ON
		pnlPBXSW55_�V�����_�㏸�[A=ON
		if tim_XSW55_�V�����_�㏸�[A then
			res(tim_XSW55_�V�����_�㏸�[A)
		end if
		�W��胆�j�b�gErrStep=1

	else if (ldp(tim_XSW56_�V�����_���~�[A.B) or ldp(tim_notXSW56_�V�����_���~�[A)) and not(pnlPBXSW56_�V�����_���~�[A) then
		almXSW56_�V�����_���~�[A=ON
		pnlPBXSW56_�V�����_���~�[A=ON
		if tim_XSW56_�V�����_���~�[A then
			res(tim_XSW56_�V�����_���~�[A)
		end if
		�W��胆�j�b�gErrStep=1

	else if (ldp(tim_XSW57_�V�����_�㏸�[B.B) or ldp(tim_notXSW57_�V�����_�㏸�[B.B)) and not(pnlPBXSW57_�V�����_�㏸�[B) then
		almXSW57_�V�����_�㏸�[B=ON
		pnlPBXSW57_�V�����_�㏸�[B=ON
		if tim_XSW57_�V�����_�㏸�[B then
			res(tim_XSW57_�V�����_�㏸�[B)
		end if
		�W��胆�j�b�gErrStep=1

	else if (ldp(tim_XSW58_�V�����_���~�[B.B) or ldp(tim_notXSW58_�V�����_���~�[B.B)) and not(pnlPBXSW58_�V�����_���~�[B) then
		almXSW58_�V�����_���~�[B=ON
		pnlPBXSW58_�V�����_���~�[B=ON
		if tim_XSW58_�V�����_���~�[B then
			res(tim_XSW58_�V�����_���~�[B)
		end if
		�W��胆�j�b�gErrStep=1

	else if (ldp(tim_XSW59_�A���N�����v.B) or ldp(tim_notXSW59_�A���N�����v.B)) and not(pnlPBXSW59_�A���N�����v) then
		almXSW59_�A���N�����v=ON
		pnlPBXSW60_�N�����v=ON
		pnlPBXSW59_�A���N�����v=ON
		if tim_XSW59_�A���N�����v then
			res(tim_XSW59_�A���N�����v)
		end if
		�W��胆�j�b�gErrStep=1

	else if (ldp(tim_XSW60_�N�����v.B) or ldp(tim_notXSW60_�N�����v.B)) and not(pnlPBXSW60_�N�����v) then
		almXSW60_�N�����v=ON
		pnlPBXSW60_�N�����v=ON
		pnlPBXSW59_�A���N�����v=ON
		if tim_XSW60_�N�����v then
			res(tim_XSW60_�N�����v)
		end if
		�W��胆�j�b�gErrStep=1

	end if
else
	res(tim_XSW55_�V�����_�㏸�[A)
	res(tim_XSW56_�V�����_���~�[A)
	res(tim_XSW57_�V�����_�㏸�[B)
	res(tim_XSW58_�V�����_���~�[B)
	res(tim_XSW59_�A���N�����v)
	res(tim_XSW60_�N�����v)

	res(tim_notXSW55_�V�����_�㏸�[A)
	res(tim_notXSW56_�V�����_���~�[A)
	res(tim_notXSW57_�V�����_�㏸�[B)
	res(tim_notXSW58_�V�����_���~�[B)
	res(tim_notXSW59_�A���N�����v)
	res(tim_notXSW60_�N�����v)
end if
'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �W��胆�j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �W��胆�j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �W��胆�j�b�gEmg	���̏��~


if �W��胆�j�b�gEmgStep=0 then  
	
	if �W��胆�j�b�gErrStep=0  then

	if not(�W��胆�j�b�gOrgErr) then

		if not(�W��胆�j�b�gAutoMode and ��������AutoMode ) then
			�W��胆�j�b�gAutoRun=OFF
		end if

	if (�W��胆�j�b�gAutoMode and ��������AutoMode ) or �W��胆�j�b�gstep<>0 then
		

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �W��胆�j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
			�W��胆�j�b�gStatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �W��胆�j�b�gAutoRun then
				�W��胆�j�b�gStatusMsg=#45	'	�ҋ@��
				inc(�W��胆�j�b�gstep)
			else 
				�W��胆�j�b�gstep=0 '�I���ҋ@
			end if
		
		case 2
		' [ �W�J�}�ړ���~�m�F ]
			if �t�^���r�o�v��=OFF and  �����R���x�AD���쒆=OFF and not(MC19_�������[�^) and not(MC20_�������[�^) then
				inc(�W��胆�j�b�gstep)
			else
				�W��胆�j�b�gstep=1
			end if
		
		case 3
		' [ ���j�b�g�����o ]
			if �W��胆�j�b�g���� then
				�W��胆�j�b�gstep=100 '�v���Z�X����
			else
				�t�^���r�o�v��=ON
				�W��胆�j�b�gstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			if �t�^��芮�� then '�����ړ���OFF
				�W��胆�j�b�gstep=199
			else
				if not(�t�^���t�^��蒆) and  PH23_�����m and PH24_�t�^���m then
					�W��胆�j�b�gStatusMsg=#46	'	�t�^��蒆
					inc(�W��胆�j�b�gstep) '�t�^���
				else if �t�^���t�^��蒆 and  not(PH23_�����m) and not(PH24_�t�^���m) then
					�W��胆�j�b�gStatusMsg=#47	'	�t�^�u����
					�W��胆�j�b�gstep=150 '�t�^�u��
				else
					�t�^���r�o�v��=ON
					�W��胆�j�b�gstep=1
				end if
			end if

		'------------------------------------------------------
		case 101  '�t�^���
			mSV45_�V�����_�㏸A=OFF
			mSV46_�V�����_���~A=OFF
			mSV47_�V�����_�㏸B=OFF
			mSV48_�V�����_���~B=OFF
			mSV49_�A���N�����v=OFF
			mSV50_�N�����v=OFF
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)

		case 102
			if tim_procstep.B then
				if ((XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A) and ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B) then
					if (XSW59_�A���N�����v and not(pnlPBXSW59_�A���N�����v)) or passXSW59_�A���N�����v then
						inc(�W��胆�j�b�gstep)
					else
						�W��胆�j�b�gstep=1
					end if
				else
					�W��胆�j�b�gstep=1
				end if
			end if

		case 103
			mSV46_�V�����_���~A=ON
			inc(�W��胆�j�b�gstep)

		case 104
			if (XSW56_�V�����_���~�[A and not(pnlPBXSW56_�V�����_���~�[A)) or passXSW56_�V�����_���~�[A then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 105
			mSV46_�V�����_���~A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)
		
		case 106
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 107
			mSV50_�N�����v=ON
			inc(�W��胆�j�b�gstep)
		
		case 108
			if (XSW60_�N�����v and not(pnlPBXSW60_�N�����v)) or passXSW60_�N�����v then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 109
			mSV50_�N�����v=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)
		
		case 110
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 111
			mSV45_�V�����_�㏸A=ON
			inc(�W��胆�j�b�gstep)
		
		case 112
			if (XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 113
			mSV45_�V�����_�㏸A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)
		
		case 114
			if tim_procstep.B then
				�t�^���t�^��蒆=ON
				�W��胆�j�b�gstep=199
			end if
		'------------------------------------------------------
		case 150 '�t�^�u��
			mSV45_�V�����_�㏸A=OFF
			mSV46_�V�����_���~A=OFF
			mSV47_�V�����_�㏸B=OFF
			mSV48_�V�����_���~B=OFF
			mSV49_�A���N�����v=OFF
			mSV50_�N�����v=OFF
			mSV40_�X�g�b�p=OFF
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)

		case 151
			if tim_procstep.B then
				if ((XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A) and ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B) then
					if (XSW60_�N�����v and not(pnlPBXSW60_�N�����v)) or passXSW60_�N�����v then
						inc(�W��胆�j�b�gstep)
					else
						�W��胆�j�b�gstep=1
					end if
				else
					�W��胆�j�b�gstep=1
				end if
			end if

		case 152
			mSV46_�V�����_���~A=ON
			inc(�W��胆�j�b�gstep)
			
		case 153
			mSV48_�V�����_���~B=ON
			inc(�W��胆�j�b�gstep)		
		
		case 154
			if (XSW56_�V�����_���~�[A and not(pnlPBXSW56_�V�����_���~�[A)) or passXSW56_�V�����_���~�[A then
				inc(�W��胆�j�b�gstep)
			end if		
		
		case 155
			mSV46_�V�����_���~A=OFF
			inc(�W��胆�j�b�gstep)

		case 156
			if (XSW58_�V�����_���~�[B and not(pnlPBXSW58_�V�����_���~�[B)) or passXSW58_�V�����_���~�[B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 157			
			mSV48_�V�����_���~B=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)

		case 158
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 159
			inc(�W��胆�j�b�gstep)
		
		case 160
			mSV49_�A���N�����v=ON
			inc(�W��胆�j�b�gstep)
		
		case 161
			if (XSW59_�A���N�����v and not(pnlPBXSW59_�A���N�����v)) or passXSW59_�A���N�����v then
				inc(�W��胆�j�b�gstep)
			end if

		case 162
			mSV49_�A���N�����v=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)
				
		case 163
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 164
			mSV45_�V�����_�㏸A=ON
			inc(�W��胆�j�b�gstep)
		
		case 165
			mSV47_�V�����_�㏸B=ON
			inc(�W��胆�j�b�gstep)

		case 166
			if (XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A then
				inc(�W��胆�j�b�gstep)
			end if
			
		case 167
			mSV45_�V�����_�㏸A=OFF
			inc(�W��胆�j�b�gstep)

		
		case 168
			if (XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B then
				inc(�W��胆�j�b�gstep)
			end if
	
		case 169
			mSV47_�V�����_�㏸B=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(�W��胆�j�b�gstep)

		case 170
			if tim_procstep.B then
				inc(�W��胆�j�b�gstep)
			end if
		
		case 171
			if tim_procstep.B then
				�t�^���t�^��蒆=OFF
				�W��胆�j�b�gstep=199
			end if
		'------------------------------------------------------
		case 199
			�t�^��芮��=ON
			�t�^���r�o�v��=ON
			�W��胆�j�b�gstep=1
		'------------------------------------------------------


		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�W��胆�j�b�gAutoRun=OFF
		
		�W��胆�j�b�gstep=0 '�I��
		�t�^��芮��=OFF
		
		'------------------------------------------------------
		if ldp(pnlPBSV46_�V�����_���~A) then
			'���~
			if (XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A then
				mSV46_�V�����_���~A=ON
				mSV45_�V�����_�㏸A=OFF
			end if			
		else if ldp(pnlPBSV45_�V�����_�㏸A) then
			'�㏸
			if ((XSW56_�V�����_���~�[A and not(pnlPBXSW56_�V�����_���~�[A)) or passXSW56_�V�����_���~�[A) and ((XSW59_�A���N�����v and not(pnlPBXSW59_�A���N�����v)) or passXSW59_�A���N�����v) then
				mSV46_�V�����_���~A=OFF
				mSV45_�V�����_�㏸A=ON
			else if (XSW56_�V�����_���~�[A and not(pnlPBXSW56_�V�����_���~�[A)) or passXSW56_�V�����_���~�[A then
					if ((XSW60_�N�����v and not(pnlPBXSW60_�N�����v)) or passXSW60_�N�����v) and ((XSW45_�X�g�b�p���~�[ and not(pnlPBXSW45_�X�g�b�p���~�[)) or passXSW45_�X�g�b�p���~�[) then
						mSV46_�V�����_���~A=OFF
						mSV45_�V�����_�㏸A=ON
					end if
			end if
		end if
		if mSV46_�V�����_���~A and ((XSW56_�V�����_���~�[A and not(pnlPBXSW56_�V�����_���~�[A)) or passXSW56_�V�����_���~�[A) then
			mSV46_�V�����_���~A=OFF
		end if
		if mSV45_�V�����_�㏸A and ((XSW55_�V�����_�㏸�[A and not(pnlPBXSW55_�V�����_�㏸�[A)) or passXSW55_�V�����_�㏸�[A) then
			mSV45_�V�����_�㏸A=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV48_�V�����_���~B) then
			'���~
			if not(PH23_�����m)  then 
				if ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B) and ((XSW59_�A���N�����v and not(pnlPBXSW59_�A���N�����v)) or passXSW59_�A���N�����v) then
					mSV48_�V�����_���~B=ON
					mSV47_�V�����_�㏸B=OFF
				end if 

			else if not(PH23_�����m) and not(PH24_�t�^���m)  then 
				if ((XSW60_�N�����v and not(pnlPBXSW60_�N�����v)) or passXSW60_�N�����v) and ((XSW45_�X�g�b�p���~�[ and not(pnlPBXSW45_�X�g�b�p���~�[)) or passXSW45_�X�g�b�p���~�[) then
					if ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B) then
						mSV48_�V�����_���~B=ON
						mSV47_�V�����_�㏸B=OFF
					end if
				end if
			end if
		else if ldp(pnlPBSV47_�V�����_�㏸B) then
			'�㏸
			if (XSW58_�V�����_���~�[B and not(pnlPBXSW58_�V�����_���~�[B)) or passXSW58_�V�����_���~�[B then
				if ((XSW59_�A���N�����v and not(pnlPBXSW59_�A���N�����v)) or passXSW59_�A���N�����v) then
					mSV48_�V�����_���~B=OFF
					mSV47_�V�����_�㏸B=ON
				end if

			else if (XSW58_�V�����_���~�[B and not(pnlPBXSW58_�V�����_���~�[B)) or passXSW58_�V�����_���~�[B then
					if ((XSW60_�N�����v and not(pnlPBXSW60_�N�����v)) or passXSW60_�N�����v) and  ((XSW45_�X�g�b�p���~�[ and not(pnlPBXSW45_�X�g�b�p���~�[)) or passXSW45_�X�g�b�p���~�[) then
						mSV48_�V�����_���~B=OFF
						mSV47_�V�����_�㏸B=ON
					end if
			end if
		end if
		
		if mSV48_�V�����_���~B and ((XSW58_�V�����_���~�[B and not(pnlPBXSW58_�V�����_���~�[B)) or passXSW58_�V�����_���~�[B) then
			mSV48_�V�����_���~B=OFF
		end if
		if mSV47_�V�����_�㏸B and ((XSW57_�V�����_�㏸�[B and not(pnlPBXSW57_�V�����_�㏸�[B)) or passXSW57_�V�����_�㏸�[B) then
			mSV47_�V�����_�㏸B=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV50_�N�����v) then 
			if (XSW59_�A���N�����v and not(pnlPBXSW59_�A���N�����v)) or passXSW59_�A���N�����v then
				mSV50_�N�����v=ON
				mSV49_�A���N�����v=OFF
			
				�t�^���t�^��蒆=ON
			end if
		else if ldp(pnlPBSV49_�A���N�����v) then
			if (XSW60_�N�����v and not(pnlPBXSW60_�N�����v)) or passXSW60_�N�����v then
				mSV50_�N�����v=OFF
				mSV49_�A���N�����v=ON			

				�t�^���t�^��蒆=OFF
			end if	
		end if
		if mSV50_�N�����v and ((XSW60_�N�����v and not(pnlPBXSW60_�N�����v)) or passXSW60_�N�����v) then
			mSV50_�N�����v=OFF
		end if
		if mSV49_�A���N�����v and ((XSW59_�A���N�����v and not(pnlPBXSW59_�A���N�����v)) or passXSW59_�A���N�����v) then
			mSV49_�A���N�����v=OFF
		end if
		'------------------------------------------------------

	end if '�W��胆�j�b�gAutoMode and not(�W��胆�j�b�gOrgErrStep)
	'===================================================================================================================
	'�y �W��胆�j�b�gOrgErr���� �z
	else

		if ResetFlg then
			�W��胆�j�b�gOrgErr=OFF
		end if

	end if

	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		�W��胆�j�b�gErr=ON
	
		select case �W��胆�j�b�gErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW55_�V�����_�㏸�[A=OFF
				almXSW56_�V�����_���~�[A=OFF
				almXSW57_�V�����_�㏸�[B=OFF
				almXSW58_�V�����_���~�[B=OFF
				almXSW59_�A���N�����v=OFF
				almXSW60_�N�����v=OFF

				inc(�W��胆�j�b�gErrStep)
			end if
		case 2
			�W��胆�j�b�gErr=OFF

			res(tim_XSW55_�V�����_�㏸�[A.B)
			res(tim_XSW56_�V�����_���~�[A.B)
			res(tim_XSW57_�V�����_�㏸�[B.B)
			res(tim_XSW58_�V�����_���~�[B.B)
			res(tim_XSW59_�A���N�����v)
			res(tim_XSW60_�N�����v)

			res(tim_notXSW55_�V�����_�㏸�[A.B)
			res(tim_notXSW56_�V�����_���~�[A.B)
			res(tim_notXSW57_�V�����_�㏸�[B.B)
			res(tim_notXSW58_�V�����_���~�[B.B)
			res(tim_notXSW59_�A���N�����v)
			res(tim_notXSW60_�N�����v)
			
			�W��胆�j�b�gErrStep=0
		end select

	end if 'if �W��胆�j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �W��胆�j�b�gEmgStep
	case 0
	
	case 1
		�W��胆�j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�W��胆�j�b�gAutoMode and ��������AutoMode ) or �W��胆�j�b�gstep<>0 then
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
			mSV45_�V�����_�㏸A=OFF
			mSV46_�V�����_���~A=OFF
			mSV47_�V�����_�㏸B=OFF
			mSV48_�V�����_���~B=OFF
			mSV49_�A���N�����v=OFF
			mSV50_�N�����v=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�W��胆�j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�W��胆�j�b�gEmgStep)
		end if
	case 3
		if (�W��胆�j�b�gAutoMode and ��������AutoMode ) or �W��胆�j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				
				
				'---------------------------------
				inc(�W��胆�j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�W��胆�j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�W��胆�j�b�gEmgStep=0
		�W��胆�j�b�gEmg=OFF
	end select
		
end if 'if �W��胆�j�b�gEmgStep=0 then
