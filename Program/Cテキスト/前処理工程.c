'�O�����H��
'===================================================================================================================
'
'<<<<<<<	�O�����H��	>>>>>>>>
'
'===================================================================================================================
'
'	�O�����H��
'	
'	�O������������  �|  �Z�Ѓ^���N��������A  -    �O�����v�ʊ���  -   �O��������
'	                        DM_A�^���N�ݒ�l
'  		                    DM_A�^���N���Č��ݒl
'
'                   -   �Z�Ѓ^���N��������B
'                        	DM_B�^���N�ݒ�l
'                        	DM_B�^���N���Č��ݒl
'
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������

    �O�����H��AutoMode=OFF
    �O�����H��AutoRun=OFF
    �O�����H������=ON
    �O�����H��OrgErr=OFF
    �O�����H��Err=OFF
    �O�����H��Emg=OFF
    �O�����H��step=0
    �O�����H��ErrStep=0
    �O�����H��OrgErrStep=0
    �O�����H��EmgStep=0
    
    �O�����H��StatusMsg=0

end if

tmr(StartUpTim,10)

'===================================================================================================================
'�y �ً}��~ �z
tmr(not(ESPB1_����~),ESPB1_����~tim,2)
tmr(ESPB5_����~,ESPB5_����~tim,2)

if ESPB1_����~tim or ESPB5_����~tim then
	�O�����H��Emg=ON
	�O�����H��EmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

if almPS1_�G�A�[���� or almPS2_�G�A�[���� or almPS3_�G�A�[���� then
	
	if �O�����H��step<>0 then '1�T�C�N���͓��삳����
		�O�����H��AutoRun=OFF
	else
		�O�����H��ErrStep=1
	end if
	
end if
'===================================================================================================================
' PL�C���W�P�[�^
	PL19_�����^�]=�����^�]���[�h or (�����^�]���[�hEndWait and CR2006)
	PBL20_�\��^�]=(�\��^�]���[�h or ���^���N�\��^�]���[�h) or (�\��^�]���[�hEndWait and CR2006)

	�Z�Ѓ^���NA���ʌ��ݒl=R41000.U
	�Z�Ѓ^���NB���ʌ��ݒl=R41100.U




'===================================================================================================================

tmr(tim_RLY_���x���X�C�b�`,10)
RLY_���x���X�C�b�`�p�d��=not(tim_RLY_���x���X�C�b�`.B)


'===================================================================================================================
'�[�ČɃR�}���h�X�C�b�`����

'-------------------------------
'���C������{�b�N�X
'
'PB19_�����^�]
'PB20_�\��^�]
'PB21_�O������~
'
'--------------------------------
'�[�Čɑ���{�b�N�X
'
'SSW4_�[�ČɎ蓮
'SSW4_�[�ČɎ���
'PB1_�����p���~ON
'PB3_�r�o�p���~ON
'PB5_�v�ʋ@ON
'PB33_�[�ČɑS��~ '���[�^OFF�A�v�ʃ��[�^���ߐڂ�OFF�A
'
'--------------------------------
'
'PL10_�ُ�
'PL19_�����^�]
'PBL20_�\��^�]
'PBL22_�����^�]
'
'--------------------------------
'����������
'--------------------------------
if CR2008 then
	�O�����H���蓮����step=0
end if
	
�Z�Ѓ^���NA����= �Z�Ѓ^���NA���ʌ��ݒl
�Z�Ѓ^���NB����= �Z�Ѓ^���NB���ʌ��ݒl

'--------------------------------
'�^�C�}�[����	
'--------------------------------
tmr(FLOS3_LMT121,timdly_FLOS03_LMT121,20) '10 -> 20�ɕύX
tmr(not(FLOS3_LMT121),timnotdly_FLOS03_LMT121,20) '10 -> 20�ɕύX
if timdly_FLOS03_LMT121 or �Z�Ѓ^���NA�ėL�� then
	�Z�Ѓ^���NA�ėL��=ON
end if
if (�Z�Ѓ^���NA�ėL�� and timnotdly_FLOS03_LMT121 and not(PDL2_�p�h���Z���T�[����A) ) or (�O�����H��AutoRun=OFF and �v��step=0 and ����step=0 and (timnotdly_FLOS03_LMT121 and not(PDL2_�p�h���Z���T�[����A)) ) then
	if not(�^�]��������) then
		DM_A�^���N���Č��ݒl=0
	end if
	�Z�Ѓ^���NA�ėL��=OFF
end if

tmr(FLOS4_LMT121,timdly_FLOS4_LMT121,20) '10 -> 20�ɕύX
tmr(not(FLOS4_LMT121),timnotdly_FLOS4_LMT121,20) '10 -> 20�ɕύX
if timdly_FLOS4_LMT121 or �Z�Ѓ^���NB�ėL�� then
	�Z�Ѓ^���NB�ėL��=ON
end if
if (�Z�Ѓ^���NB�ėL�� and timnotdly_FLOS4_LMT121 and not(PDL4_�p�h���Z���T�[����B) ) or (�O�����H��AutoRun=OFF and �v��step=0 and ����step=0 and (timnotdly_FLOS4_LMT121 and not(PDL4_�p�h���Z���T�[����B)) ) then
	'DM_�Z�Ѓ^���NB���Ċ���=0 '�R�����g��
	if not(�^�]��������) then
		DM_B�^���N���Č��ݒl=0
	end if
	�Z�Ѓ^���NB�ėL��=OFF
end if

'--------------------------------
'�R�}���h����
'--------------------------------

if RLY_�d���m�F�[�Č�  then


	if �O�����H��AutoRun=OFF and �v��step=0 and ����step=0 then
		�����^�]���[�hEndWait=OFF
		�\��^�]���[�hEndWait=OFF
	end if

	'�ăZ���T�[�������Ă��� PB21_�O������~ ��������
	if not(�\��^�]���[�h) and �O������������ and DM_A�^���N�ݒ�l>0  then
		if not(FLOS3_LMT121) and ((XSW9_���Đ؊�A�� and not(pnlPBXSW9_���Đ؊�A��)) or passXSW9_���Đ؊�A��) then
			�Z�Ѓ^���NA��~����=OFF
		else
			�Z�Ѓ^���NA��~����=ON
		end if
	else
		�Z�Ѓ^���NA��~����=ON
	end if
	
	
	if not(�\��^�]���[�h) and �O������������ and DM_B�^���N�ݒ�l>0 then
		if not(FLOS4_LMT121) and ((XSW10_���Đ؊�B�� and not(pnlPBXSW10_���Đ؊�B��)) or passXSW10_���Đ؊�B�� )then
			�Z�Ѓ^���NB��~����=OFF
		else
			�Z�Ѓ^���NB��~����=ON
		end if
	else
		�Z�Ѓ^���NB��~����=ON			
	end if

	
	tmr(not(FLOS3_LMT121),nottim_FLOS3_LMT121,10)
	tmr(not(FLOS4_LMT121),nottim_FLOS4_LMT121,10)


	if not(PB21_�O������~) or SSW4_�[�ČɎ蓮 or �O�����v�ʊ��� then
		�O�����H��AutoRun=OFF
		�v��AutoRun=OFF
		
		if SSW4_�[�ČɎ蓮 then
			����AutoRun=OFF
		end if
		
		if �����^�]���[�h and (�v��step<>0 or ����step<>0) then
			�����^�]���[�hEndWait=ON
		end if
		�����^�]���[�h=OFF
		
		if �\��^�]���[�h and (�v��step<>0 or ����step<>0) then
			�\��^�]���[�hEndWait=ON
		end if
		�\��^�]���[�h=OFF
		
		���^���N�\��^�]���[�h=OFF
		

	
	end if
	'-------------------------------------------------------------------------------------------------------------
	' �[�ČɎ蓮�؂�ւ��A���[��
	'-------------------------------------------------------------------------------------------------------------
	
	if ldp(SSW4_�[�ČɎ蓮) then
		almSSW4_�[�ČɎ蓮=ON
	end if
	if almSSW4_�[�ČɎ蓮 and ResetFlg then
		almSSW4_�[�ČɎ蓮=OFF
	end if
	

	'-------------------------------------------------------------------------------------------------------------
	' �\�񂨂�ё����̃X�^�[�g�`�F�b�N
	'-------------------------------------------------------------------------------------------------------------
	if almSSW4_�[�ČɎ��� then
		if ResetFlg then
			almSSW4_�[�ČɎ���=OFF
		end if
	else if almSV2_�[�U�o���u�JA or almSV4_���؂�V���b�^�[�JA or almSV60_�r���o���u�JA or almSV6_�����d����A then
		if ResetFlg then
			almSV2_�[�U�o���u�JA=OFF
			almSV4_���؂�V���b�^�[�JA=OFF
			almSV60_�r���o���u�JA=OFF
			almSV6_�����d����A=OFF
		end if
	else if almSV7_�[�U�o���u�JB or almSV9_���؂�V���b�^�[�JB or almSV62_�r���o���u�JB or almSV11_�����d����B then  
		if ResetFlg then	
			almSV7_�[�U�o���u�JB=OFF
			almSV9_���؂�V���b�^�[�JB=OFF
			almSV62_�r���o���u�JB=OFF
			almSV11_�����d����B=OFF
		end if
	else if almPDL1_�p�h���Z���T�[���A or almPDL3_�p�h���Z���T�[���B then
		if ResetFlg then	
			almPDL1_�p�h���Z���T�[���A=OFF
			almPDL3_�p�h���Z���T�[���B=OFF
		end if
		
	'-------------------------------------------------------------------------------------------------------------
	else if �O�����H��step=0 and (ldp(PB19_�����^�]) or ldp(PB20_�\��^�]) ) then

		'-----------------------------------------------------------
		if not(SSW4_�[�ČɎ���) then
			almSSW4_�[�ČɎ���=ON
		'-----------------------------------------------------------
		else if timPDL1_�p�h���Z���T�[���A then
			almPDL1_�p�h���Z���T�[���A=ON
		else if timPDL3_�p�h���Z���T�[���B then
			almPDL3_�p�h���Z���T�[���B=ON
		'-----------------------------------------------------------
		else if SV2_�[�U�o���u�JA then
			almSV2_�[�U�o���u�JA=ON
		else if KeepSV4_���؂�V���b�^�[�JA then 
			almSV4_���؂�V���b�^�[�JA=ON
		else if	SV60_�r���o���u�JA then
			almSV60_�r���o���u�JA=ON
		'-----------------------------------------------------------
		else if SV7_�[�U�o���u�JB then
			almSV7_�[�U�o���u�JB=ON
		else if KeepSV9_���؂�V���b�^�[�JB then
			almSV9_���؂�V���b�^�[�JB=ON
		else if	SV62_�r���o���u�JB then
			almSV62_�r���o���u�JB=ON
		'-----------------------------------------------------------
		end if
	
	'-------------------------------------------------------------------------------------------------------------
	else
	
		if ldp(PB19_�����^�]) and not(PB20_�\��^�]) and SSW4_�[�ČɎ��� and PB21_�O������~ then' and �O�����ݒ芮�� then
			res(tim_RLY_���x���X�C�b�`)
			if not(�O�����H��AutoRun) and �O�����H��step=0 and �v��step=0 and ����step=0 and (DM_A�^���N���Č��ݒl<DM_A�^���N�ݒ�l or DM_B�^���N���Č��ݒl<DM_B�^���N�ݒ�l) then
			
				if (DM_A�^���N�ݒ�l>0 and DM_A�^���N���Č��ݒl=0) or (DM_B�^���N�ݒ�l>0 and DM_B�^���N���Č��ݒl=0) then
					�Z�Ў��Ԍv����=OFF
				end if
			
			
				'if nottim_FLOS3_LMT121.B then '�Z�Ѓ^���NA�ĂȂ�
				'	DM_A�^���N���Č��ݒl=0
				'end if
				
				'if nottim_FLOS4_LMT121.B then '�Z�Ѓ^���NB�ĂȂ�
				'	DM_B�^���N���Č��ݒl=0
				'end if
					
				
				if DM_A�^���N���Č��ݒl>=DM_A�^���N�ݒ�l then
					�Z�Ѓ^���N��������A=ON
				else
					�Z�Ѓ^���N��������A=OFF
				end if
				
				if DM_B�^���N���Č��ݒl>=DM_B�^���N�ݒ�l then
					�Z�Ѓ^���N��������B=ON
				else 
					�Z�Ѓ^���N��������B=OFF
				end if
				
				�O������������=OFF
				�O�����v�ʊ���=OFF
				�O��������=OFF

				�O�����H��AutoMode=ON
				�O�����H��AutoRun=ON		
				�O�����H��step=1

				mSV1_�����d����_������=OFF
				
				if FLOS2_���Ė����Đ؊����m then
					�����ă��[�h=ON
				else
					�����ă��[�h=OFF
				end if
				
				����Inite=OFF

				�����^�]���[�h=ON		
				�\��^�]���[�h=OFF
			
			end if
		end if

		if ldp(PB20_�\��^�]) and not(�����^�]���[�h) and SSW4_�[�ČɎ��� and not(PB19_�����^�]) and PB21_�O������~ and PB33_�[�ČɑS��~ then 'and �O�����ݒ芮�� then
			res(tim_RLY_���x���X�C�b�`)
			if not(�O�����H��AutoRun) and  �O�����H��step=0 and �v��step=0 and ����step=0 and (DM_A�^���N���Č��ݒl<DM_A�^���N�ݒ�l or DM_B�^���N���Č��ݒl<DM_B�^���N�ݒ�l) then
				'�����t���O=OFF
				
				if (DM_A�^���N�ݒ�l>0 and DM_A�^���N���Č��ݒl=0) or (DM_B�^���N�ݒ�l>0 and DM_B�^���N���Č��ݒl=0) then
					�Z�Ў��Ԍv����=OFF
				end if
				
				
				if nottim_FLOS3_LMT121.B then '�Z�Ѓ^���NA�ĂȂ�
					DM_A�^���N���Č��ݒl=0
				end if
				
				if nottim_FLOS4_LMT121.B then '�Z�Ѓ^���NB�ĂȂ�
					DM_B�^���N���Č��ݒl=0
				end if

				if DM_A�^���N���Č��ݒl>=DM_A�^���N�ݒ�l then
					�Z�Ѓ^���N��������A=ON
				else
					�Z�Ѓ^���N��������A=OFF
				end if
				
				if DM_B�^���N���Č��ݒl>=DM_B�^���N�ݒ�l then
					�Z�Ѓ^���N��������B=ON
				else 
					�Z�Ѓ^���N��������B=OFF
				end if

				�O������������=OFF
				�O�����v�ʊ���=OFF
				�O��������=OFF

				�����^�]���[�h=OFF		
				�\��^�]���[�h=ON

				mSV1_�����d����_������=OFF

			end if
		end if
	

	end if
	'----------------------------------------------------------------------------------------------------------
	'���^���N�\�񃂁[�h
	if 0 then
	if ���^���N�\��^�]���[�h then
	
		if ldp(PB20_�\��^�]) or �����^�]���[�h or (SSW3_�������[�h and PB22_�����^�]) then
		    ���^���NAutoRun=OFF
			���^���N�\��^�]���[�h=OFF
		end if
	
		if ldp(���^���NONTIME) then
			    ���^���NAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
			    ���^���NAutoRun=ON
		else
			
			if (timFLT1_�^���N���.B and timFLT2_�^���N����.B) then
				if (timFLT3_�^���N���.B and timFLT4_�^���N����.B) then
					if (timFLT5_�^���N���.B and timFLT6_�^���N����.B) then
						if (timFLT7_�^���N���.B and timFLT8_�^���N����.B) then
							if (timFLT9_�^���N���.B and timFLT10_�^���N����.B) then
								���^���N�\��^�]���[�h=OFF
							end if
						end if
					end if
				end if
			end if
			
		end if		
			
	else if ldp(PB20_�\��^�]) and not(�����^�]���[�h) then
		���^���N�\��^�]���[�h=ON		
	end if
	end if
	'----------------------------------------------------------------------------------------------------------

	

	if �\��^�]���[�h  then

		if ldp(ONTIME) and �O��������=OFF and �O�����H��step=0 then
			if FLOS2_���Ė����Đ؊����m then
				�����ă��[�h=ON
			else
				�����ă��[�h=OFF
			end if

			�\��^�]���[�h=ON		
			
			�O������������=OFF
			�Z�Ѓ^���N��������A=OFF
			�Z�Ѓ^���N��������B=OFF
			�O�����v�ʊ���=OFF
			�O��������=OFF

			�O�����H��AutoMode=ON
			�O�����H��AutoRun=ON		
			�O�����H��step=1
			
						
			mSV60_�r���o���u�JA=OFF
			mSV2_�[�U�o���u�JA=OFF
			ejectSV2_�[�U�o���u�JA=OFF
			
			mSV62_�r���o���u�JB=OFF
			mSV7_�[�U�o���u�JB=OFF
			ejectSV7_�[�U�o���u�JB=OFF			
			
			
		end if
		
	else
		'�Z���N�g�X�C�b�`=�蓮  �[�ČɑS��~-> �O�����H��AutoRun=OFF
		'���_�Œ�~��  -> �Z���N�^�X�C�b�`�Ń��[�h�ؑ�
		if SSW4_�[�ČɎ��� and not(SSW4_�[�ČɎ蓮) then
			�O�����H���蓮�v��=OFF
			�O�����H��AutoMode=ON
		else
			�O�����H��AutoMode=OFF		
		end if

	end if

else

		�����^�]���[�h=OFF
		�����^�]���[�hEndWait=OFF
		���^���N�\��^�]���[�h=OFF
		'�\��^�]���[�h=OFF
		�\��^�]���[�hEndWait=OFF
		�O�����H��AutoMode=OFF
		�O�����H��AutoRun=OFF
		�O�����H��ErrStep=1
end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �O�����H��AutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: AutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\
'System :: �O�����H��Emg	���̏��~



if �O�����H��EmgStep=0 then  
	
	if �O�����H��ErrStep=0  then
	
	if not(�O�����H��OrgErr) then

	if �O�����H��AutoMode or �O�����H��step<>0 then
		
		if not(�O�����H��AutoMode)  then
			�v��AutoMode=OFF			
			�O�����H��AutoRun=OFF
		else
			�v��AutoMode=ON
		end if
	
		tmr(tim_procstep,tim_procstep_val)

		'--------------------------------------------------------------------------------------------------------------
		if �O�������� then
			�O�����H��StatusMsg=#21	'	�Z�В�
		else
			�O�����H��StatusMsg=#20	'	�O������;
		end if

		select case �O�����H��step
		case 0	' �I���ҋ@
			�O�����H��StatusMsg=#24	'	��~��
		case 1	' ���s
		' [ �����p���^�] ]
			if �O�����H��AutoRun  then
				�O�����H��StatusMsg=#22	'	�����^�]��
				inc(�O�����H��step)
			else 
				�v��AutoRun=OFF
				if not(�O������������) then '������
					mSV1_�����d����=OFF
					ejectSV6_�����d����A=OFF
					ejectSV11_�����d����B=OFF				
				end if
				�O�����H��step=0 '�I���ҋ@
			end if

		
		case 2
		' [ ������������ ]
			if �O������������  then
				inc(�O�����H��step)
			else
				�O�����H��step=1000 '��������
			end if
		
		case 3
		if not(�O��������) then
			
			if not(�O�����v�ʊ���) then

				if �v��step=0 then	'�v��
					if FLOS2_���Ė����Đ؊����m then
						�����ă��[�h=ON
					else
						�����ă��[�h=OFF
					end if

					�v��step=1
					�C���^�[�o��������=ON

				end if
				�v��AutoRun=ON
					
			else
				
				if �v��step=0 and ����step=0 then
					�O��������=ON
				end if

			end if
		
			�O�����H��step=1
		else
		
			if �v��step=0 and ����step=0 then
				�O�����H��step=0
			else
				�O�����H��step=1
			end if			
			
		end if
		'--------------------------------------------------------------------------------------------------------------
		'�^���N��������
		
		case 1000
		
			'�Z�Ѓ^���NA ����l R41000=3670
			'�Z�Ѓ^���NB ����l R41100=3670
			
		
			�O������������=OFF
			�O��������=OFF
			�O�����v�ʊ���=OFF
			
			
			
			if mSV1_�����d����_������=OFF then '���ċ@
				mSV1_�����d����_������=ON
				tim_mSV1_�����d����_val=#600
				res(tim_mSV1_�����d����)
				mSV1_�����d����=ON
			end if
			
			if DM_A�^���N�ݒ�l<>0 and DM_A�^���N���Č��ݒl<DM_A�^���N�ݒ�l and �Z�Ѓ^���NA���ʌ��ݒl<3650 then  '�Z�Ѓ^���NA
				�Z�Ѓ^���NA���j�b�gStatusMsg=#10	'	������
				ejectSV6_�����d����A=ON
			else
				ejectSV6_�����d����A=OFF
			end if
			
			if DM_B�^���N�ݒ�l<>0 and DM_B�^���N���Č��ݒl<DM_B�^���N�ݒ�l and �Z�Ѓ^���NB���ʌ��ݒl<3650 then  '�Z�Ѓ^���NB
				�Z�Ѓ^���NB���j�b�gStatusMsg=#10	'	������
				ejectSV11_�����d����B=ON
			else 
				ejectSV11_�����d����B=OFF
			end if
				
			inc(�O�����H��step)
			
		case 1001
			tmr(mSV1_�����d���� and RS1_���^���N����Z���T�[, tim_mSV1_�����d����, tim_mSV1_�����d����_val)
			if RS1_���^���N����Z���T�[ and tim_mSV1_�����d����.B  then
				mSV1_�����d����=OFF
			end if

			if ejectSV6_�����d����A and �Z�Ѓ^���NA���ʌ��ݒl>3650 then
				ejectSV6_�����d����A=OFF
			end if

			if ejectSV11_�����d����B and �Z�Ѓ^���NB���ʌ��ݒl>3650 then
				ejectSV11_�����d����B=OFF
			end if

			if not(mSV1_�����d����) and not(ejectSV6_�����d����A) and not(ejectSV11_�����d����B) then
				tim_procstep_val=0
				res(tim_procstep)	
				inc(�O�����H��step)
			end if

			if not(PB21_�O������~) or SSW4_�[�ČɎ蓮 then
				mSV1_�����d����=OFF
				ejectSV6_�����d����A=OFF
				ejectSV11_�����d����B=OFF
				�O�����H��step=1		
			end if
						
						
		case 1002
			if DM_A�^���N�ݒ�l<>0 and DM_A�^���N���Č��ݒl<DM_A�^���N�ݒ�l then  '�Z�Ѓ^���NA
				ejectSV6_�����d����A=ON
			else
				ejectSV6_�����d����A=OFF
			end if
			
			if DM_B�^���N�ݒ�l<>0 and DM_B�^���N���Č��ݒl<DM_B�^���N�ݒ�l then  '�Z�Ѓ^���NB
				ejectSV11_�����d����B=ON
			else 
				ejectSV11_�����d����B=OFF
			end if
			
			if tim_procstep.B then
				ejectSV6_�����d����A=OFF
				ejectSV11_�����d����B=OFF
				inc(�O�����H��step)
			end if		

			if not(PB21_�O������~) or SSW4_�[�ČɎ蓮 then
				mSV1_�����d����=OFF
				ejectSV6_�����d����A=OFF
				ejectSV11_�����d����B=OFF
				�O�����H��step=1		
			end if

		case 1003	
			�O������������=ON			
			�O�����H��step=1

		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		
		�O�����H��AutoRun=OFF
		�O�����H��step=0 '�I��
		
		�v��AutoRun=OFF
		if �v��step=0 then
			�v��AutoMode=OFF
		end if
		
		����AutoRun=OFF
		if ����step=0 then
			����AutoMode=OFF
		end if

	end if '�O�����H��AutoMode and not(�O�����H��OrgErrStep)

	'===================================================================================================================
	'�y �O�����H��OrgErr �z
	else

		�O�����H��AutoRun=OFF
		�O�����H��step=1

		�v��AutoRun=OFF

		if �O�����H��OrgErr then
			if RestartFlg or PB34_���Z�b�g then
				if �O�����H��AutoMode then
					�O�����H��AutoRun=ON
				end if
				�O�����H��OrgErr=OFF
			end if		
		end if
		
	end if	
	
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�O�����H��AutoRun=OFF

		PL2_�ُ�=ON

		select case �O�����H��ErrStep
		case 0
		case 1
			if ResetFlg then
				inc(�O�����H��ErrStep)
			end if
		case 2
			PL2_�ُ�=OFF

			�O�����H��ErrStep=0
		end select

	end if 'if �O�����H��ErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �O�����H��EmgStep
	case 0
	
	case 1
		�����^�]���[�h=OFF
		�O�����H��AutoRun=OFF

		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if �O�����H��AutoMode or �O�����H��step<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgSV1_�����d����=ON
			EmgSV6_�����d����A=ON
			EmgSV11_�����d����B=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_mSV1_�����d����_stack=tim_mSV1_�����d����.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV1_�����d����=OFF
			ejectSV6_�����d����A=OFF
			ejectSV11_�����d����B=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�O�����H��EmgStep)
	case 2
		if ResetFlg then
			inc(�O�����H��EmgStep)
		end if
	case 3
		if �O�����H��AutoMode or �O�����H��step<>0 then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				EmgSV1_�����d����=OFF
				EmgSV6_�����d����A=OFF
				EmgSV11_�����d����B=OFF

				tim_procstep.U=tim_procstep_stack
				tim_mSV1_�����d����.U=tim_mSV1_�����d����_stack
				'---------------------------------
				inc(�O�����H��EmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�O�����H��EmgStep)		
		end if				
	case 4
		timstack=OFF
		if �v��EmgStep=0 and ����EmgStep=0 then
			�O�����H��EmgStep=0
			�O�����H��Emg=OFF
		end if
	end select
		
end if 'if �O�����H��EmgStep=0 then
