'�[�Č�
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	�[�ČɃ��j�b�g�i�Čv�ʁj
'	
'===================================================================================================================
'�y ���������� �z
if CR2008 then

    �v��AutoMode=OFF
    �v��AutoRun=OFF
    �v�ʋ���=ON
    �v��OrgErr=OFF
    �v��Err=OFF
    �v��Emg=OFF
    �v��step=0
    �v��ErrStep=0
    �v��OrgErrStep=0
    �v��EmgStep=0

	�����T�C�N��flg=OFF

	�Z�Ѓ^���NA���쒆=OFF
	�Z�Ѓ^���NB���쒆=OFF
	
end if

'===================================================================================================================
'�y ���_ �z
�v��Org=1

'===================================================================================================================
'�y Runtime����  (�f�[�^ �C���|�[�g�A�G�N�X�|�[�g) �z

'�������[�^�͏�Ɏ蓮��ON/OFF�\

	if not(THR1_�����p���~�@���[�^) and PB33_�[�ČɑS��~ then
		if ldp(PB1_�����p���~ON) then
			if mMC1_�����p���~�@ then
				mMC1_�����p���~�@=OFF
			else
				mMC1_�����p���~�@=ON
			end if
		end if
	else
		mMC1_�����p���~�@=OFF
	end if
	
	PBL1_�����p���~�@=mMC1_�����p���~�@

'==============================================================================================================
'�y �v���f�[�^ ����� �v�Z�� �z

if 0 then
	DM_�v�ʐݒ�l=21

else
	if DM_�v�ʐݒ�l<1	then
		DM_�v�ʐݒ�l=1
	else if DM_�v�ʐݒ�l>30	then
		DM_�v�ʐݒ�l=30
	end if

end if

	cnt(MC3_�v�ʋ@,CNT_�v�ʌ��ݒl, DM_�v�ʐݒ�l,FLOS1_�v�ʋ@�ߐڃZ���T�[)
	cnt(MC3_�v�ʋ@,CNT_���v�ʌ��ݒl, DM_�v�ʐݒ�l,FLOS1_�v�ʋ@�ߐڃZ���T�[)

'==============================================================================================================
'�y �v���f�[�^ ����� �v�Z�� �z
'2017_0921_1536�ύX�O�f�[�^
'if 1 then
'	DM_�v�ʐݒ�l=21
'end if

'	cnt(MC3_�v�ʋ@,CNT_�v�ʌ��ݒl, DM_�v�ʐݒ�l,FLOS1_�v�ʋ@�ߐڃZ���T�[)
'	cnt(MC3_�v�ʋ@,CNT_���v�ʌ��ݒl, DM_�v�ʐݒ�l,FLOS1_�v�ʋ@�ߐڃZ���T�[)

'===================================================================================================================
'�y �ً}��~ �z

tmr(not(ESPB1_����~),ESPB1_����~tim,2)
tmr(ESPB5_����~,ESPB5_����~tim,2)

if ESPB1_����~tim or ESPB5_����~tim then
	�v��Emg=ON
	�v��EmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(SV12_���Đ؊��o���uA�� and not(XSW9_���Đ؊�A��) and not(pnlPBXSW9_���Đ؊�A��) ,tim_notXSW9_���Đ؊�A��,#100)
tmr(SV13_���Đ؊��o���uB�� and not(XSW10_���Đ؊�B��) and not(pnlPBXSW10_���Đ؊�B��), tim_notXSW10_���Đ؊�B��,#100)

if LDP(SV12_���Đ؊��o���uA��) and XSW9_���Đ؊�A�� and XSW10_���Đ؊�B�� and not(pnlPBXSW9_���Đ؊�A��) then
	SET(tim_XSW9_���Đ؊�A��)
end if
if LDP(SV13_���Đ؊��o���uB��) and XSW9_���Đ؊�A�� and XSW10_���Đ؊�B�� and not(pnlPBXSW10_���Đ؊�B��) then
	SET(tim_XSW10_���Đ؊�B��)
end if

if SV12_���Đ؊��o���uA�� then
	KeepSV12_���Đ؊��o���uA��=ON
	KeepSV13_���Đ؊��o���uB��=OFF
else if SV13_���Đ؊��o���uB�� then
	KeepSV12_���Đ؊��o���uA��=OFF
	KeepSV13_���Đ؊��o���uB��=ON
end if	
'passtimXSW9_���Đ؊�A��_val=#3000
tms(SV12_���Đ؊��o���uA�� or KeepSV12_���Đ؊��o���uA��,passtimXSW9_���Đ؊�A��,passtimXSW9_���Đ؊�A��_val)
'passtimXSW10_���Đ؊�B��_val=#3000
tms(SV13_���Đ؊��o���uB�� or KeepSV13_���Đ؊��o���uB��,passtimXSW10_���Đ؊�B��,passtimXSW10_���Đ؊�B��_val)

if (ldp(tim_XSW9_���Đ؊�A��.B) or ldp(tim_notXSW9_���Đ؊�A��)) and not(pnlPBXSW9_���Đ؊�A��) then
	almXSW9_���Đ؊�A��=ON
	pnlPBXSW9_���Đ؊�A��=ON
	pnlPBXSW10_���Đ؊�B��=ON
	if tim_XSW9_���Đ؊�A�� then
		res(tim_XSW9_���Đ؊�A��)
	end if
	�v��ErrStep=1
end if
if (ldp(tim_XSW10_���Đ؊�B��.B)or LDP(tim_notXSW10_���Đ؊�B��)) and not(pnlPBXSW10_���Đ؊�B��) then
	almXSW10_���Đ؊�B��=ON
	pnlPBXSW9_���Đ؊�A��=ON
	pnlPBXSW10_���Đ؊�B��=ON
	if tim_XSW10_���Đ؊�B�� then
		res(tim_XSW10_���Đ؊�B��)
	end if
	�v��ErrStep=1
end if

'===================================================================================================================
' PL�C���W�P�[�^
	
	PBL5_�v�ʋ@=�����T�C�N��flg
	
	PBL3_�r�o�p���~�@ = MC2_�r�o�p���~�@ or ( SSW4_�[�ČɎ蓮 and PB5_�v�ʋ@ON and PB33_�[�ČɑS��~ and not(mMC2_�r�o�p���~�@) and CR2005) 


'===================================================================================================================
' �Z���T�[���o�f�B���C�\

	tmr(PDL1_�p�h���Z���T�[���A and not(�ď��A���m����),timPDL1_�p�h���Z���T�[���A,20)
	tmr(PDL2_�p�h���Z���T�[����A,tim_PDL2_�p�h���Z���T�[����A,20)
	tmr(PDL3_�p�h���Z���T�[���B and not(�ď��B���m����),timPDL3_�p�h���Z���T�[���B,20)
	tmr(PDL4_�p�h���Z���T�[����B,tim_PDL4_�p�h���Z���T�[����B,20)

if ldp(timPDL1_�p�h���Z���T�[���A) then
	almPDL1_�p�h���Z���T�[���A=ON
end if
if ldp(timPDL3_�p�h���Z���T�[���B) then
	almPDL3_�p�h���Z���T�[���B=ON
end if

if almPDL1_�p�h���Z���T�[���A and ResetFlg then
	almPDL1_�p�h���Z���T�[���A=OFF
end if
if almPDL3_�p�h���Z���T�[���B and ResetFlg then
	almPDL3_�p�h���Z���T�[���B=OFF
end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �v��Emg	���̏��~


tmr(tim_�؊����o���u�؊����҂�,tim_�؊����o���u�؊����҂�_val)
'�؊����o���u

if �v��EmgStep=0 then  
	
	if �v��ErrStep=0  then

	if not(�v��OrgErr) then

	'if  (�v��AutoMode and ��������AutoMode) or �v��step<>0  then
	if  �v��AutoMode or �v��step<>0  then

	
		if not(�v��AutoMode) then
			�v��AutoRun=OFF
		end if

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim�v��,tim�v��_val)


		select case �v��step
		case 0

		case 1
			if �v��AutoRun or �����T�C�N��flg then
				�Z�Ѓ^���NA���쒆=OFF
				�Z�Ѓ^���NB���쒆=OFF				
				inc(�v��step)
			else 
				�v��step=100 '�r�o���~�x��
			end if
		
		case 2
			if �����T�C�N��flg then
				�v��step=5
			else if �Z�Ѓ^���N��������A=OFF then
				if timPDL1_�p�h���Z���T�[���A or DM_A�^���N���Č��ݒl>=DM_A�^���N�ݒ�l or DM_A�^���N�ݒ�l=0 then
					�Z�Ѓ^���NA���j�b�gStatusMsg=#0

					�Z�Ѓ^���NA���쒆=OFF
					�Z�Ѓ^���N��������A=ON
					���ă^���N�؊���=ON
				else
					�Z�Ѓ^���NA���j�b�gStatusMsg=#11	'	���Ē�
					�Z�Ѓ^���NB���j�b�gStatusMsg=#0

					�Z�Ѓ^���NA���쒆=ON
					�Z�Ѓ^���NB���쒆=OFF
					if not(mSV12_���Đ؊��o���uA��) then
						���ă^���N�؊���=OFF
						mSV12_���Đ؊��o���uA��=ON
						mSV13_���Đ؊��o���uB��=OFF
						tim_�؊����o���u�؊����҂�_val=#20
						res(tim_�؊����o���u�؊����҂�.B)
					else
						set(tim_�؊����o���u�؊����҂�.B)
					end if
					
					inc(�v��step)

				end if

			else if �Z�Ѓ^���N��������B=OFF then 
				if timPDL3_�p�h���Z���T�[���B or DM_B�^���N���Č��ݒl>=DM_B�^���N�ݒ�l or DM_B�^���N�ݒ�l=0 then
					�Z�Ѓ^���NB���j�b�gStatusMsg=#0

					�Z�Ѓ^���NB���쒆=OFF
					�Z�Ѓ^���N��������B=ON
				else 
					�Z�Ѓ^���NA���쒆=OFF
					�Z�Ѓ^���NB���쒆=ON
					if not(mSV13_���Đ؊��o���uB��) then
						�Z�Ѓ^���NA���j�b�gStatusMsg=#0
						�Z�Ѓ^���NB���j�b�gStatusMsg=#11'	���Ē�

						mSV12_���Đ؊��o���uA��=OFF
						mSV13_���Đ؊��o���uB��=ON
						tim_�؊����o���u�؊����҂�_val=#20
						res(tim_�؊����o���u�؊����҂�.B)
					else
						set(tim_�؊����o���u�؊����҂�.B)
					end if
					inc(�v��step)
				end if
			else
				�O�����v�ʊ���=ON
				�v��step=0
			end if
		

		case 3
			if tim_�؊����o���u�؊����҂�.B then '�_�u���\���m�C�hOFF�^�C�~���O
				if  (not(���ă^���N�؊���) or mSV12_���Đ؊��o���uA��) and ((XSW9_���Đ؊�A�� and not(pnlPBXSW9_���Đ؊�A��)) or passXSW9_���Đ؊�A��) then
					mSV12_���Đ؊��o���uA��=OFF
					mSV13_���Đ؊��o���uB��=OFF
					inc(�v��step)
				else if  (���ă^���N�؊��� or mSV13_���Đ؊��o���uB��) and ((XSW10_���Đ؊�B�� and not(pnlPBXSW10_���Đ؊�B��)) or passXSW10_���Đ؊�B��) then
					mSV12_���Đ؊��o���uA��=OFF
					mSV13_���Đ؊��o���uB��=OFF
					inc(�v��step)
				end if
			end if


		case 4
			if SSW4_�[�ČɎ��� then
				����AutoRun=ON
				����step=1
			end if
			inc(�v��step)
		'------------------------------------------
		'���~�@ ON Delay
		case 5
			�v�ʓ��쒆=ON
			if not(mMC2_�r�o�p���~�@) then 
				mMC2_�r�o�p���~�@=ON
				tim�v��_val=#1200  'ON Delay ����
				res(tim�v��)
			else
				set(tim�v��) 'ON Delay �Ȃ�
			end if

			inc(�v��step)
		case 6
			if tim�v��.B then
				inc(�v��step)
			end if				
		'------------------------------------------
		'�v�ʒ�
		case 7
			if ���Čv�ʈꎞ��~ then
				mMC3_�v�ʋ@=OFF			
				inc(�v��step)
			else if not(�O�����v�ʊ���) or �����T�C�N��flg then '�O�����S�̂̐Z�Ѓ^���NA�`B�ւ̌v�ʊ���
				res(CNT_�v�ʌ��ݒl)
				mMC3_�v�ʋ@=ON
				inc(�v��step)
			else
				mMC3_�v�ʋ@=OFF
				�v��step=100
			end if
			
		case 8
			if not(PB33_�[�ČɑS��~) then 
				�v��AutoRun=OFF
				inc(�v��step)
			else
				if CNT_�v�ʌ��ݒl.B then '�w��v�ʁi�J�b�v���j�I��
					if ((XSW9_���Đ؊�A�� and not(pnlPBXSW9_���Đ؊�A��)) or passXSW9_���Đ؊�A��) or SV12_���Đ؊��o���uA�� then
						if DM_A�^���N�ݒ�l>0 and DM_A�^���N���Č��ݒl=0 then
							�Z�Ў��Ԍv����=ON
						end if
						inc(DM_A�^���N���Č��ݒl) '���Ċ���
					else if ((XSW10_���Đ؊�B�� and not(pnlPBXSW10_���Đ؊�B��)) or passXSW10_���Đ؊�B��) or SV13_���Đ؊��o���uB�� then
						if DM_A�^���N�ݒ�l=0 and (DM_B�^���N�ݒ�l>0 and DM_B�^���N���Č��ݒl=0) then
							�Z�Ў��Ԍv����=ON
						end if
						inc(DM_B�^���N���Č��ݒl) '���Ċ���
					end if					
					inc(�v��step)
				end if
			end if
		case 9
			if not(FLOS1_�v�ʋ@�ߐڃZ���T�[) then
				inc(�v��step)
			end if
		case 10
			if FLOS1_�v�ʋ@�ߐڃZ���T�[ then
				inc(�v��step)
			end if			
		case 11
			tim�v��_val=#0 '�ʒu����^�C�}�[
			res(tim�v��)
			inc(�v��step)				
		
		case 12
			if tim�v��.B then
				mMC3_�v�ʋ@=OFF
				inc(�v��step)
			end if
		'------------------------------------------
		'�v�ʋ@ OFF Delay
		case 13
			if �����T�C�N��flg then
				�����T�C�N��flg=OFF
				�v��step=0
			else
				if ���Čv�ʈꎞ��~ then
					tim�v��_val=0
				else
					if FLOS2_���Ė����Đ؊����m then
						tim�v��_val=���ăC���^�[�o��������*10 '#180 '�v�ʃC���^�[�o���^�C�}
					else 			
						tim�v��_val=���ăC���^�[�o���ʏ��*10 '#310 '�v�ʃC���^�[�o���^�C�}
					end if
				end if
				res(tim�v��)
				inc(�v��step)

			end if
		case 14
			if tim�v��.B then
				inc(�v��step)
			end if
		'------------------------------------------
		'�c�ď���		
		case 15
			if not(�Z�Ѓ^���N��������A) and (timPDL1_�p�h���Z���T�[���A or DM_A�^���N���Č��ݒl>=DM_A�^���N�ݒ�l) then
				�v��step=100
			else if DM_B�^���N�ݒ�l>0 then
				inc(�v��step)
			else 
				�v��step=1						
			end if
			
		case 16
			if  not(�Z�Ѓ^���N��������B) and (timPDL3_�p�h���Z���T�[���B or DM_B�^���N���Č��ݒl>=DM_B�^���N�ݒ�l) then
				�v��step=100
			else
				inc(�v��step)
			end if		
		
		case 17
				�v��step=1			
		'------------------------------------------
		'�r�o���~�@ OFF Delay
		case 100
			tim�v��_val=#600 '�r�o�p���~�@�x���^�C�}�[
			res(tim�v��)
			inc(�v��step)
		case 101
			if tim�v��.B then
				mMC2_�r�o�p���~�@=OFF
				�v�ʓ��쒆=OFF
				inc(�v��step)	
			end if
		'------------------------------------------
		case 102
			if ����step=0 then
					�v��step=0
			end if
		'------------------------------------------
			
		end select
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else
		
		�v��AutoRun=OFF
		
		�v��step=0 '�I��
		
		'-----------------------------------
		if not(PB33_�[�ČɑS��~)  then
			manual�r�o�p���~�@=OFF
			mMC1_�����p���~�@=OFF
		end if
		'-----------------------------------		
		if ldp(pnlPBMC1_�����p���~�@) then
			if mMC1_�����p���~�@ then
				mMC1_�����p���~�@=OFF
			else
				mMC1_�����p���~�@=ON
			end if
		end if	

		'-----------------------------------
		' manual���~���[�^ON/OFF

		if  ldp(PB3_�r�o�p���~ON and SSW4_�[�ČɎ蓮) or ldp(pnlPBMC2_�r�o�p���~�@) then
			if manual�r�o�p���~�@ then
				manual�r�o�p���~�@=OFF
			else if PB33_�[�ČɑS��~ then
				manual�r�o�p���~�@=ON
				mMC2_�r�o�p���~�@=ON
			end if
		
		end if
		
		if (SSW4_�[�ČɎ��� or not(manual�r�o�p���~�@) ) and �v��step=0 then
			mMC2_�r�o�p���~�@=OFF
		end if
		
		'-----------------------------------
		' manual�v��step

		if (ldp(PB5_�v�ʋ@ON and SSW4_�[�ČɎ蓮) or ldp(pnlPBMC3_�v�ʋ@)) and SSW4_�[�ČɎ蓮 and  PB33_�[�ČɑS��~ and mMC2_�r�o�p���~�@ and �v��step=0 then
				if FLOS2_���Ė����Đ؊����m then
					�����ă��[�h=ON
				else
					�����ă��[�h=OFF
				end if

				�����T�C�N��flg=ON
				�v��step=1
		
		end if		
	
	end if 'AutoMode and not(�v��OrgErrStep)

	'===================================================================================================================
	'�y �v��OrgErr���� �z
	else
		
		�v��AutoRun=OFF
		�v��step=1
		
		if �v��OrgErr then
			if RestartFlg or PB34_���Z�b�g then
				if �v��AutoMode then
					�v��AutoRun=ON
				end if
				�v��OrgErr=OFF
			end if		
		end if

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
		PL2_�ُ�=ON

		�v��AutoRun=OFF

		pauseMC2_�r�o�p���~�@=ON
		pauseMC3_�v�ʋ@=ON

		select case �v��ErrStep
		case 0
		case 1
			if ResetFlg or PB34_���Z�b�g then
				almXSW9_���Đ؊�A��=OFF
				almXSW10_���Đ؊�B��=OFF
				almPDL1_�p�h���Z���T�[���A=OFF
				almPDL3_�p�h���Z���T�[���B=OFF
				inc(�v��ErrStep)
			end if
		case 2
			res(tim_XSW9_���Đ؊�A��)
			res(tim_XSW10_���Đ؊�B��)
			res(tim_notXSW9_���Đ؊�A��)
			res(tim_notXSW10_���Đ؊�B��)
		
			pauseMC2_�r�o�p���~�@=OFF
			pauseMC3_�v�ʋ@=OFF

			PL2_�ُ�=OFF
			�v��ErrStep=0
		end select

	end if 'if �v��ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �v��EmgStep
	case 0

	case 1
		�v��AutoRun=OFF

		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if  (�v��AutoMode and ��������AutoMode) or �v��step<>0  then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			mMC1_�����p���~�@=OFF
			pauseMC2_�r�o�p���~�@=ON
			pauseMC3_�v�ʋ@=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim�v��.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC1_�����p���~�@=OFF
			mMC2_�r�o�p���~�@=OFF
			mMC3_�v�ʋ@=OFF				
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�v��EmgStep)
	case 2
		if ResetFlg then
			inc(�v��EmgStep)
		end if
	case 3
		if  (�v��AutoMode and ��������AutoMode) or �v��step<>0  then
			if StartFlg then

				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				pauseMC2_�r�o�p���~�@=OFF
				pauseMC3_�v�ʋ@=OFF
				
				tim�v��.U=tim_procstep_stack
				'---------------------------------
				inc(�v��EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�v��EmgStep)		
		end if				
	case 4
		timstack=OFF	
		�v��EmgStep=0
		�v��Emg=OFF
	end select
		
end if 'if �v��EmgStep=0 then
