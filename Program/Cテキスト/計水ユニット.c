'�v�����j�b�g
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�v�����j�b�g
'
'===================================================================================================================
'
'  ��  Modbsu�ʐM�Ōv����������������ݒ肷��B
'
'	setADR4532c1_Up	=DM_�v���ڕW���x (x: 1,2,3)
'	setADR4532c1_Low=DM_�v���ڕW����x (x: 1,2,3)
'
'	*����  ZERO�@�\�i�{�́A�O�ʃX�C�b�`�j  ZERO�X�C�b�`�������Ēl��0�ɂ��邱�Ƃ��ł��邪�A�ēd��������A0�ł͂Ȃ��l�����Ƃɖ߂�܂��B

'��l�̐ݒ�
	DM_�v���ڕW����1=DM_�ݒ萅�ʊ�l+DM_���ʕ␳�l
	DM_�󊘌v���ڕW����1=DM_�������ʊ�l+DM_���ʕ␳�l

'�z�čς݊��ւ̒���
	DM_�v���ڕW���1=DM_�v���ڕW����1+10	'���ʖ���
'	DM_�v���ڕW����1=1027					'���ʖ��� � (�ݒ�l�j
	DM_�v���ڕW���2=DM_�v���ڕW����2+10	'���ʒ���
	DM_�v���ڕW����2=(DM_�v���ڕW����1-100)	'���ʒ���
	DM_�v���ڕW���3=50						'�r��
	DM_�v���ڕW����3=-50					'�r��

'�󊘂ւ̒���
	DM_�󊘌v���ڕW���1=DM_�󊘌v���ڕW����1+10	'���ʖ���
'	DM_�󊘌v���ڕW����1=1027						'���ʖ��� � (�ݒ�l�j
	DM_�󊘌v���ڕW���2=DM_�󊘌v���ڕW����2+10	'���ʒ���
	DM_�󊘌v���ڕW����2=(DM_�󊘌v���ڕW����1-100)	'���ʒ���


	if DM_�󊘌v���ڕW����1>DM_�v���ڕW����1 then
		DM_�󊘌v���ڕW����1=DM_�v���ڕW����1
	end if	
'
'�C���W�P�[�^�\���l
'
	DM_�v���ʌ��ݒl=getADR4532c1_Raw
	
	if DM_�v���ڕW����1>0 then
		if  DM_�v���ʌ��ݒl<10 then
			�����ʃO���t=0
		else if DM_�v���ʌ��ݒl>(DM_�v���ڕW����1-20) then
			�����ʃO���t=100
		else 	
			�����ʃO���t=(DM_�v���ʌ��ݒl*100) / DM_�v���ڕW����1
		end if	
	else
		'���т̐���  650�Ōv�Z
		if DM_�v���ʌ��ݒl<10 then
			�����ʃO���t=0
		else if DM_�v���ʌ��ݒl>(650-20) then
			�����ʃO���t=100
		else
			�����ʃO���t=(DM_�v���ʌ��ݒl*100)/650
		end if
	end if
	
	if not(�A���t�@���ă��[�h) then
		�ݒ�����ꎞ��~=OFF
	end if
'
'����  �r���o���u
'
'�����o���u
'	SV17_�v���^���N�����i��j
'	SV18_�v���^���N�����i���j
'�r���o���u
'	mSV19_�v���d����_A �J��
'	mSV64_�v���d����_B �� - 2017/7/5 �폜
'

'------------------------------------------------------------------------------------------------------------------
'AD4532 ZERO RESET 1.0S �����V���b�g

tmr(AD4532_ZERO,tim_AD4532_ZERO,10)
if AD4532_ZERO and not(tim_AD4532_ZERO.B) then
	AD4532_ZERO=ON
else
	AD4532_ZERO=OFF
end if

if not(SV17_�v���^���N�����i��j) and not(SV18_�v���^���N�����i���j) and not(SV19_�v���d����_A) then
	if ldp(pnlPBAD4532_ZERO) then
			AD4532_ZERO=ON
			res(tim_AD4532_ZERO)
	end if
end if

'===================================================================================================================
'

'�y ���������� �z
if CR2008 then
    �v�����j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �v�����j�b�gAutoRun=OFF
    �v�����j�b�g����=ON
    �v�����j�b�gOrgErr=OFF
    �v�����j�b�gErr=OFF
    �v�����j�b�gEmg=OFF
    �v�����j�b�gstep=0
    �v�����j�b�gErrStep=0
    �v�����j�b�gOrgErrStep=0
    �v�����j�b�gEmgStep=0

	�����T�C�N��flg=OFF
	�v������step=0
	
	TestPass=0

end if
'===================================================================================================================
'�y ���_ �z
�v�����j�b�gOrg=1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�v�����j�b�gEmg=ON
	�v�����j�b�gEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(SV18_�v���^���N�����i���j ,tim_�v���^���N�����i���j,#250)
tmr(SV17_�v���^���N�����i��j,tim_�v���^���N�����i��j,#250)
tmr(SV19_�v���d����_A,tim_�v���d����_A,#250)
TMR(setADR4532c1_Low<>getADR4532c1_Low or setADR4532c1_Up<>getADR4532c1_Up,tim_dataerr,#50)

if ldp(tim_�v���^���N�����i���j.B) then
	errpassSV18_�v���^���N�����i���j=ON
	almSV18_�v���^���N�����i���j=ON
	�v�����j�b�gErrStep=1

else if ldp(tim_�v���^���N�����i��j.B) then
	errpassSV17_�v���^���N�����i��j=ON
	almSV17_�v���^���N�����i��j=ON
	�v�����j�b�gErrStep=1

else if ldp(tim_�v���d����_A.B) then
	errpassSV19_�v���d����_A=ON
	almSV19_�v���d����_A=ON
	�v�����j�b�gErrStep=1

else if ldp(tim_dataerr) then
	errpassDataErr=ON
	almAD4532_COMP1=ON
	�v�����j�b�gErrStep=1
end if
'===================================================================================================================
' PL�C���W�P�[�^
	if not(��������AutoMode) or not(�v�����j�b�gAutoMode) then
		PBL32_�v��= �����T�C�N��flg
	else
		PBL32_�v��=OFF
	end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �v�����j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �v�����j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �v�����j�b�gEmg	���̏��~

tmr(tim_TestPass,tim_TestPass_val) 

if �v�����j�b�gEmgStep=0 then  
	
	if �v�����j�b�gErrStep=0  then
	
	if not(�v�����j�b�gOrgErr) then


		'-----------------------------------------------------------------------------
		' �󊘂̌v��
		tmr(tim_�v������,tim_�v������_val)
		select case �v������step
		case 0
		case 1
			������������=OFF
			mSV19_�v���d����_A=OFF '�J��
			tim_�v������_val=#10
			res(tim_�v������)
			inc(�v������step)
		
		case 2
			if tim_�v������.B then
				inc(�v������step)
			end if

		case 3
			setADR4532c1_Low=DM_�󊘌v���ڕW����2
			setADR4532c1_Up=DM_�󊘌v���ڕW���2
			errpassDataErr=OFF
			inc(�v������step)

		case 4
			if errpassDataErr then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				mSV19_�v���d����_A=OFF
				�v������step=0
				
			else if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then
				inc(�v������step)			
			end if
		
		case 5
			tim_�v������_val=10 'ADR4532��OK�M�����Z�b�g�҂�
			res(tim_�v������)
			inc(�v������step)
			
		case 6
			if tim_�v������.B then
				inc(�v������step)
			end if

		case 7
			mSV17_�v���^���N�����i��j=ON
			mSV18_�v���^���N�����i���j=ON
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF
			errpassSV19_�v���d����_A=OFF
			inc(�v������step)

		case 8
			tim_TestPass_val=120
			res(tim_TestPass)
			inc(�v������step)
		
		case 9
			if (TestPass and tim_TestPass.B) or errpassSV19_�v���d����_A or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_HI then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=ON
				inc(�v������step)
			end if
		
		case 10		
			setADR4532c1_Low=DM_�󊘌v���ڕW����1
			setADR4532c1_Up=DM_�󊘌v���ڕW���1
			errpassDataErr=OFF
			inc(�v������step)

		case 11
			if errpassDataErr then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				mSV19_�v���d����_A=OFF
				�v������step=0
			
			else if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(�v������step)
			end if

		case 12
			tim_�v������_val=10 'ADR4532��OK�M�����Z�b�g�҂�
			res(tim_�v������)
			inc(�v������step)
			
		case 13
			if tim_�v������.B then
				inc(�v������step)
			end if

		case 14
			mSV17_�v���^���N�����i��j=OFF
			mSV18_�v���^���N�����i���j=ON
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF
			errpassSV19_�v���d����_A=OFF

			inc(�v������step)
		
		case 15
			tim_TestPass_val=80
			res(tim_TestPass)
			inc(�v������step)
		
		case 16
			if (TestPass and tim_TestPass.B) or errpassSV19_�v���d����_A or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_HI then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				inc(�v������step)
			end if


		case 17
			tim_�v������_val=#10 'Wait
			res(tim_�v������)
			inc(�v������step)
		
		case 18
			if tim_�v������.B then
				inc(�v������step)
			end if

		case 19
			������������=ON
			�v������step=0

		end select
		
		'-----------------------------------------------------------------------------
		' ���ъ��̌v��
		tmr(tim_�v���ǉ�,tim_�v���ǉ�_val)
		select case �v���ǉ�step
		case 0

		case 1
			if DM_�v���ʌ��ݒl>=DM_�v���ڕW����1 then
				�v���ǉ�step=0
			else
				inc(�v���ǉ�step)
			end if

		case 2
			setADR4532c1_Low=DM_�v���ڕW����2
			setADR4532c1_Up=DM_�v���ڕW���2
			errpassDataErr=OFF

			inc(�v���ǉ�step)

		case 3
			if errpassDataErr then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				mSV19_�v���d����_A=OFF
				�v���ǉ�step=0
				
			else if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(�v���ǉ�step)
			end if
			
		case 4
			tim_�v���ǉ�_val=#10  'ADR4532��OK�M�����Z�b�g�҂�
			res(tim_�v���ǉ�)
			inc(�v���ǉ�step)
		
		case 5
			if tim_�v���ǉ�.B then
				inc(�v���ǉ�step)
			end if

		case 6
			mSV17_�v���^���N�����i��j=ON
			mSV18_�v���^���N�����i���j=ON
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF
			errpassSV19_�v���d����_A=OFF
			inc(�v���ǉ�step)
		
		case 7
			tim_TestPass_val=120
			res(tim_TestPass)
			inc(�v���ǉ�step)
		
		case 8
			if (TestPass and tim_TestPass.B) or errpassSV19_�v���d����_A or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_HI then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=ON
				inc(�v���ǉ�step)
			end if		

		case 9
			mSV17_�v���^���N�����i��j=OFF
			mSV18_�v���^���N�����i���j=ON
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF
			errpassSV19_�v���d����_A=OFF
			inc(�v���ǉ�step)
		
		case 10		
			setADR4532c1_Low=DM_�v���ڕW����1
			setADR4532c1_Up=DM_�v���ڕW���1
			errpassDataErr=OFF
			
			inc(�v���ǉ�step)

		case 11
			if errpassDataErr then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				mSV19_�v���d����_A=OFF
				�v���ǉ�step=0
				
			else if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(�v���ǉ�step)
			end if

		case 12
			tim_�v���ǉ�_val=#10  'ADR4532��OK�M�����Z�b�g�҂�
			res(tim_�v���ǉ�)
			inc(�v���ǉ�step)
		
		case 13
			if tim_�v���ǉ�.B then
				inc(�v���ǉ�step)
			end if

		case 14
			tim_TestPass_val=60
			res(tim_TestPass)
			inc(�v���ǉ�step)
		
		case 15
			if (TestPass and tim_TestPass.B) or errpassSV19_�v���d����_A or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_HI then
				mSV17_�v���^���N�����i��j=OFF
				mSV18_�v���^���N�����i���j=OFF
				inc(�v���ǉ�step)
			end if


		case 16
			tim_�v���ǉ�_val=#10 'Wait
			res(tim_�v���ǉ�)
			inc(�v���ǉ�step)
		
		case 17
			if tim_�v���ǉ�.B then
				inc(�v���ǉ�step)
			end if
			
		case 18
			if  �A���t�@���ă��[�h then
				if DM_A�^���N�ݒ�l>0 and  DM_A�z�Č��ݒl<DM_A�^���N�ݒ�l then
					inc(DM_A�z�Č��ݒl)
				else if DM_B�^���N�ݒ�l>0 and  DM_B�z�Č��ݒl<DM_B�^���N�ݒ�l then
					inc(DM_B�z�Č��ݒl)
				end if
			end if
			�v���ǉ�step=0

		end select


	'===================================================================================================================
	'�y �v���Z�X�����i�z�āj �z
	'
	if (�v�����j�b�gAutoMode and ��������AutoMode) or �����T�C�N��flg or �v�����j�b�gstep<>0 then
	
		if not(�v�����j�b�gAutoMode and ��������AutoMode) then
			�v�����j�b�gAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case �v�����j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �v�����j�b�gAutoRun then
				inc(�v�����j�b�gstep)
			else 
				�v�����j�b�gstep=0 '�I���ҋ@
			end if
		
		case 2
		' [ �H���������� ]
		 if �v�����j�b�g���� then
			if ������������ then
				inc(�v�����j�b�gstep)
			else
				if �v������step=0 then
					�v������step=1
				end if
				inc(�v�����j�b�gstep)
			end if
		else
			if ������������ then
				inc(�v�����j�b�gstep)
			else
				�����r�o�v��=ON
				�v�����j�b�gstep=1
			end if
		end if
		
		case 3
		' [ �W�J�}�ړ���~�m�F ]
			if �����r�o�v��=OFF and  �����R���x�AA���쒆=OFF then

				'[ ���X�e�[�W��"��"�L���o ]
					if PH52_�����m and PH53_�t�^���m then
							�v�����j�b�gstep=100 '�v���Z�X����
						
				'[ ���X�e�[�W��"�t�^"�L���o ]	
					else if not(PH52_�����m) and PH53_�t�^���m then 
							�����r�o�v��=ON
							�v�����j�b�gstep=1
				
				'[ ���X�e�[�W��"���t�^"�Ȃ� ]
						else
							�����r�o�v��=ON
							�v�����j�b�gstep=1
					end if
			
			else
			
				�v�����j�b�gstep=1
			
			end if
		
		case 4
			�v�����j�b�gstep=100 '�v���Z�X����
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			if �������� then '�����ړ���OFF
				�v�����j�b�gstep=199
				
			else if ������������  then
				
				if �A���t�@���ă��[�h then	
					if (IND_�z�Ē� and DM_�z�đ���<DM_�z�đ����ݒ�l and not(�ݒ�����ꎞ��~) and not(�z�ăC���^�[�o���֎~) ) or �����T�C�N��flg then
					 	���ъ��v������=ON
					else
					 	���ъ��v������=OFF					
					end if 

				else if ANDA(StageDevice3,$200)=$200 or ANDA(StageDevice3,$400)=$400 or �����T�C�N��flg then
				 	���ъ��v������=ON
				else
				 	���ъ��v������=OFF
				end if
				
				inc(�v�����j�b�gstep)

			end if

		'-----------------------------------------------------------------------------
		case 101
			������������=OFF
			inc(�v�����j�b�gstep)
		
		'-----------------------------------------------------------------------------
		' ���ъ��ւ̐��ʒǉ�
		case 102
			if ���ъ��v������ then
				if �v���ǉ�step=0 then
					�v���ǉ�step=1
					inc(�v�����j�b�gstep)
				end if
			else
				inc(�v�����j�b�gstep)
			end if
		
		case 103
			if �v���ǉ�step=0 then
				inc(�v�����j�b�gstep)
			end if
		'-----------------------------------------------------------------------------
		' ���� �i���ւ̔r���j
		case 104
			setADR4532c1_Low=DM_�v���ڕW����3
			setADR4532c1_Up=DM_�v���ڕW���3
			errpassSV18_�v���^���N�����i���j=OFF 
			errpassSV17_�v���^���N�����i��j=OFF
			errpassSV19_�v���d����_A=OFF
			errpassDataErr=OFF

			inc(�v�����j�b�gstep)

		case 105 
			if errpassDataErr then
				mSV19_�v���d����_A=OFF '�J��
				�v�����j�b�gstep=199

			else if setADR4532c1_Low=getADR4532c1_Low and setADR4532c1_Up=getADR4532c1_Up then 
				inc(�v�����j�b�gstep)
			end if
			
		case 106
			tim_procstep_val=#10 '�ʐM�҂�����
			res(tim_procstep)
			inc(�v�����j�b�gstep)
		
		case 107
			if tim_procstep.B then
				inc(�v�����j�b�gstep)
			end if
			
		case 108
			tim_TestPass_val=80
			res(tim_TestPass)			
			inc(�v�����j�b�gstep)
		
		case 109
			mSV19_�v���d����_A=ON '�J��
			errpassSV19_�v���d����_A=OFF
			inc(�v�����j�b�gstep)
		
		case 110
			if (TestPass and tim_TestPass.B) or errpassSV19_�v���d����_A or errpassSV18_�v���^���N�����i���j or errpassSV17_�v���^���N�����i��j or AD4532_OK or AD4532_LO then
				inc(�v�����j�b�gstep)
			end if
						
		case 111
			tim_procstep_val=#20 '���҂�����
			res(tim_procstep)
			inc(�v�����j�b�gstep)
		
		case 112
			if tim_procstep.B then
				mSV19_�v���d����_A=OFF '�J��
				�v�����j�b�gstep=199
			end if
		

		'--------------------------------------------------------------------------------------------------------------
		case 199
			if �����������ݒl<���������ݒ�l then
				inc(�����������ݒl)
			end if

			�����T�C�N��flg=OFF
			mSV19_�v���d����_A=OFF '�J��
			'mSV64_�v���d����_B=ON '��
			��������=ON
			�����r�o�v��=ON
			�v�����j�b�gstep=1
		'--------------------------------------------------------------------------------------------------------------
		'�����T�C�N������
		case 200
			if ������������  then
				inc(�v�����j�b�gstep)
			else
				if �v������step=0 then
					�v������step=1
				end if
				inc(�v�����j�b�gstep)
			end if
		
		case 201
			if ������������  then
				�v�����j�b�gstep=100
			end if
			
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�v�����j�b�gAutoRun=OFF
		
		res(tim_�v���^���N�����i���j.B) 
		res(tim_�v���^���N�����i��j.B)
		res(tim_�v���d����_A.B)
		
		
		if not(�����T�C�N��flg) then
		
				if ldp(PB32_�v��) and �v�����j�b�gstep=0 then
					if PH52_�����m and PH53_�t�^���m then
						������������=OFF
						��������=OFF
						�����T�C�N��flg=ON
						�v�����j�b�gstep=200
					end if											
				end if
				
				
				if ldp(pnlPBSV17_�v���^���N�����i��j) then
					if mSV17_�v���^���N�����i��j then
						mSV17_�v���^���N�����i��j=OFF
					else
						mSV17_�v���^���N�����i��j=ON
					end if
				end if
				if ldp(pnlPBSV18_�v���^���N�����i���j) then
					if mSV18_�v���^���N�����i���j then
						mSV18_�v���^���N�����i���j=OFF
					else
						mSV18_�v���^���N�����i���j=ON
					end if
				end if
				if ldp(pnlPBSV19_�v���d����_A) then
					if mSV19_�v���d����_A then
						mSV19_�v���d����_A=OFF
						'mSV64_�v���d����_B=OFF
					else
						mSV19_�v���d����_A=ON
						'mSV64_�v���d����_B=OFF
					end if
				end if
		end if
	end if '�v�����j�b�gAutoMode and not(�v�����j�b�gOrgErrStep)
	'===================================================================================================================
	'�y OrgErr�z
	else
	
		if ResetFlg then
			�v�����j�b�gOrgErr=OFF
		end if
		
	end if
	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�v�����j�b�gErr=ON

		mSV17_�v���^���N�����i��j=OFF
		mSV18_�v���^���N�����i���j=OFF
		mSV19_�v���d����_A=OFF '�J��
		'mSV64_�v���d����_B=ON '��

		select case �v�����j�b�gErrStep
		case 0
		case 1
			if ResetFlg then
				almSV18_�v���^���N�����i���j=OFF
				almSV17_�v���^���N�����i��j=OFF
				almSV19_�v���d����_A=OFF
				almAD4532_COMP1=OFF
			
				inc(�v�����j�b�gErrStep)
			end if
		case 2
			res(tim_�v���^���N�����i���j.B) 
			res(tim_�v���^���N�����i��j.B)
			res(tim_�v���d����_A.B)
			res(tim_dataerr.B)
			�v�����j�b�gErrStep=0
			�v�����j�b�gErr=OFF
		end select

	end if 'if �v�����j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �v�����j�b�gEmgStep
	case 0
	
	case 1
		�v�����j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�v�����j�b�gAutoMode and ��������AutoMode) or �����T�C�N��flg or �v�����j�b�gstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			�����T�C�N��flg=OFF

			�v�����j�b�gstep=0 '�I���ҋ@
			�v������step=0
			�v���ǉ�step=0
			������������=OFF

			mSV17_�v���^���N�����i��j=OFF
			mSV18_�v���^���N�����i���j=OFF
			mSV19_�v���d����_A=OFF
			'mSV64_�v���d����_B=OFF
		
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_TestPass_stack=tim_TestPass.U
				tim_�v���ǉ�_stack=tim_�v���ǉ�.U
				tim_�v������_stack=tim_�v������.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV17_�v���^���N�����i��j=OFF
			mSV18_�v���^���N�����i���j=OFF
			mSV19_�v���d����_A=OFF
			'mSV64_�v���d����_B=OFF		

			tim_procstep_stack=tim_procstep.U
			tim_TestPass_stack=tim_TestPass.U
			tim_�v���ǉ�_stack=tim_�v���ǉ�.U
			tim_�v������_stack=tim_�v������.U

			'---------------------------------
		end if
		
		'---------------------------------
		inc(�v�����j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(�v�����j�b�gEmgStep)
		end if
	case 3
		if (�v�����j�b�gAutoMode and ��������AutoMode) or �����T�C�N��flg or �v�����j�b�gstep<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				tim_TestPass.U=tim_TestPass_stack
				tim_�v���ǉ�.U=tim_�v���ǉ�_stack
				tim_�v������.U=tim_�v������_stack

				'---------------------------------
				inc(�v�����j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			tim_procstep.U=tim_procstep_stack
			tim_TestPass.U=tim_TestPass_stack
			tim_�v���ǉ�.U=tim_�v���ǉ�_stack
			tim_�v������.U=tim_�v������_stack
			
			'---------------------------------
			inc(�v�����j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		�v�����j�b�gEmgStep=0
		�v�����j�b�gEmg=OFF
	end select

		
end if 'if �v�����j�b�gEmgStep=0 then
