'�����R���x�AE
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AE
'
'  	�ړ����x  161.667mm/1sec
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    �����R���x�AEAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�AEAutoRun=OFF
    �����R���x�AE����=ON
    �����R���x�AEOrgErr=OFF
    �����R���x�AEErr=OFF
    �����R���x�AEEmg=OFF
    �����R���x�AEstep=0
    �����R���x�AEErrStep=0
    �����R���x�AEOrgErrStep=0
    �����R���x�AEEmgStep=0

	MC23_���[�^���[��step=0
	SV53_�X�g�b�pstep=0
	MC25_�������[�^step=0
	SV54_�X�g�b�pstep=0
	MC26_�������[�^step=0
	MC27_���[�^���[��step=0
	
	ManualInite=1

end if
'===================================================================================================================
'�y ���_ �z
�����R���x�AEOrg=( ((XSW64_�X�g�b�p�㏸�[ and not(pnlPBXSW64_�X�g�b�p�㏸�[)) or passXSW64_�X�g�b�p�㏸�[) or ((XSW63_�X�g�b�p���~�[ and not(pnlPBXSW63_�X�g�b�p���~�[)) or passXSW63_�X�g�b�p���~�[)) 
�����R���x�AEOrg=�����R���x�AEOrg and ( ((XSW66_�X�g�b�p�㏸�[ and not(pnlPBXSW66_�X�g�b�p�㏸�[)) or passXSW66_�X�g�b�p�㏸�[) or ((XSW65_�X�g�b�p���~�[ and not(pnlPBXSW65_�X�g�b�p���~�[)) or passXSW65_�X�g�b�p���~�[))

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�AEEmg=ON
	�����R���x�AEEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(not(SV53_�X�g�b�p) and not(XSW63_�X�g�b�p���~�[) and not(pnlPBXSW63_�X�g�b�p���~�[),tim_notXSW63_�X�g�b�p���~�[, #20) '427.69ms
tmr(SV53_�X�g�b�p and not(XSW64_�X�g�b�p�㏸�[) and not(pnlPBXSW64_�X�g�b�p�㏸�[), tim_notXSW64_�X�g�b�p�㏸�[,#20) '385.93ms
tmr(not(SV54_�X�g�b�p) and not(XSW65_�X�g�b�p���~�[) and not(pnlPBXSW65_�X�g�b�p���~�[),tim_notXSW65_�X�g�b�p���~�[,#20) '480.90ms
tmr(SV54_�X�g�b�p and not(XSW66_�X�g�b�p�㏸�[) and not(pnlPBXSW66_�X�g�b�p�㏸�[),tim_notXSW66_�X�g�b�p�㏸�[,#20) '520.00ms
tmr(not(SV55_���t�g) and not(XSW67_���t�g���~�[) and not(pnlPBXSW67_���t�g���~�[),tim_notXSW67_���t�g���~�[, #30) '808.65ms
tmr(SV55_���t�g and not(XSW68_���t�g�㏸�[) and not(pnlPBXSW68_���t�g�㏸�[), tim_notXSW68_���t�g�㏸�[, #30) '597.04ms
tmr(not(SV56_�X�g�b�p) and not(XSW69_�X�g�b�p���~�[) and not(pnlPBXSW69_�X�g�b�p���~�[),tim_notXSW69_�X�g�b�p���~�[, #20) '851.59ms
tmr(SV56_�X�g�b�p and not(XSW70_�X�g�b�p�㏸�[) and not(pnlPBXSW70_�X�g�b�p�㏸�[),tim_notXSW70_�X�g�b�p�㏸�[, #20) '598.55ms
tmr(not(SV44_���t�g) and not(XSW53_���t�g���~�[) and not(pnlPBXSW53_���t�g���~�[), tim_notXSW53_���t�g���~�[,#30) '758.48ms
tmr(SV44_���t�g and not(XSW54_���t�g�㏸�[) and not(pnlPBXSW54_���t�g�㏸�[),tim_notXSW54_���t�g�㏸�[,#30) '921.66ms

'tmr(SV53_�X�g�b�p and XSW63_�X�g�b�p���~�[,tim_XSW63_�X�g�b�p���~�[, #10) '427.69ms
if LDF(SV53_�X�g�b�p) and XSW63_�X�g�b�p���~�[ and not(pnlPBXSW63_�X�g�b�p���~�[) then
	SET(tim_XSW63_�X�g�b�p���~�[)
end if
'tmr(not(SV53_�X�g�b�p) and XSW64_�X�g�b�p�㏸�[, tim_XSW64_�X�g�b�p�㏸�[,#10) '385.93ms
if LDP(SV53_�X�g�b�p) and XSW64_�X�g�b�p�㏸�[ and not(pnlPBXSW64_�X�g�b�p�㏸�[) then
	SET(tim_XSW64_�X�g�b�p�㏸�[)
end if
'tmr(SV54_�X�g�b�p and XSW65_�X�g�b�p���~�[,tim_XSW65_�X�g�b�p���~�[,#10) '480.90ms
if LDF(SV54_�X�g�b�p) and XSW65_�X�g�b�p���~�[ and not(pnlPBXSW65_�X�g�b�p���~�[) then
	SET(tim_XSW65_�X�g�b�p���~�[)
end if
'tmr(not(SV54_�X�g�b�p) and XSW66_�X�g�b�p�㏸�[,tim_XSW66_�X�g�b�p�㏸�[,#10) '520.00ms
if LDP(SV54_�X�g�b�p) and XSW66_�X�g�b�p�㏸�[ and not(pnlPBXSW66_�X�g�b�p�㏸�[) then
	SET(tim_XSW66_�X�g�b�p�㏸�[)
end if
'tmr(SV55_���t�g and XSW67_���t�g���~�[,tim_XSW67_���t�g���~�[, #10) '808.65ms
if LDF(SV55_���t�g) and XSW67_���t�g���~�[ and not(pnlPBXSW67_���t�g���~�[) then
	SET(tim_XSW67_���t�g���~�[)
end if
'tmr(not(SV55_���t�g) and XSW68_���t�g�㏸�[, tim_XSW68_���t�g�㏸�[, #10) '597.04ms
if LDP(SV55_���t�g) and XSW68_���t�g�㏸�[ and not(pnlPBXSW68_���t�g�㏸�[) then
	SET(tim_XSW68_���t�g�㏸�[)
end if
'tmr(SV56_�X�g�b�p and XSW69_�X�g�b�p���~�[,tim_XSW69_�X�g�b�p���~�[, #10) '851.59ms
if LDF(SV56_�X�g�b�p) and XSW69_�X�g�b�p���~�[ and not(pnlPBXSW69_�X�g�b�p���~�[) then
	SET(tim_XSW69_�X�g�b�p���~�[)
end if
'tmr(not(SV56_�X�g�b�p) and XSW70_�X�g�b�p�㏸�[,tim_XSW70_�X�g�b�p�㏸�[, #10) '598.55ms
if LDP(SV56_�X�g�b�p) and XSW70_�X�g�b�p�㏸�[ and not(pnlPBXSW70_�X�g�b�p�㏸�[) then
	SET(tim_XSW70_�X�g�b�p�㏸�[)
end if
'tmr(SV44_���t�g and XSW53_���t�g���~�[, tim_XSW53_���t�g���~�[,#10) '758.48ms
if LDF(SV44_���t�g) and XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[) then
	SET(tim_XSW53_���t�g���~�[)
end if
'tmr(not(SV44_���t�g) and XSW54_���t�g�㏸�[,tim_XSW54_���t�g�㏸�[,#10) '921.66ms
if LDP(SV44_���t�g) and XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[) then
	SET(tim_XSW54_���t�g�㏸�[)
end if

'passtimXSW63_�X�g�b�p���~�[_val=#427
tms(not(SV53_�X�g�b�p),passtimXSW63_�X�g�b�p���~�[, passtimXSW63_�X�g�b�p���~�[_val) 

'passtimXSW64_�X�g�b�p�㏸�[_val=#385
tms(SV53_�X�g�b�p, passtimXSW64_�X�g�b�p�㏸�[,passtimXSW64_�X�g�b�p�㏸�[_val) 

'passtimXSW65_�X�g�b�p���~�[_val=#480
tms(not(SV54_�X�g�b�p),passtimXSW65_�X�g�b�p���~�[,passtimXSW65_�X�g�b�p���~�[_val) 

'passtimXSW66_�X�g�b�p�㏸�[_val=#520
tms(SV54_�X�g�b�p,passtimXSW66_�X�g�b�p�㏸�[,passtimXSW66_�X�g�b�p�㏸�[_val) 

'passtimXSW53_���t�g���~�[_val=#758
tms(not(SV44_���t�g), passtimXSW53_���t�g���~�[,passtimXSW53_���t�g���~�[_val) 

'passtimXSW54_���t�g�㏸�[_val=#921
tms(SV44_���t�g,passtimXSW54_���t�g�㏸�[,passtimXSW54_���t�g�㏸�[_val) 

tmr(mMC23_���[�^���[�� and not(pauseMC23_���[�^���[��) and not(EmgMC23_���[�^���[��),timerr_MC23_���[�^���[��,#150)
tmr(mMC25_�������[�^ and not(pauseMC25_�������[�^) and not(EmgMC25_�������[�^),timerr_MC25_�������[�^,#152)
tmr(mMC26_�������[�^ and not(pauseMC26_�������[�^) and not(EmgMC26_�������[�^),timerr_MC26_�������[�^,#154)
tmr(mMC27_���[�^���[�� and not(pauseMC27_���[�^���[��) and not(EmgMC27_���[�^���[��),timerr_MC27_���[�^���[��,#156)

if LDP(timerr_MC23_���[�^���[��.B) then
	almMC23_���[�^���[��=ON
	
	mMC23_���[�^���[��=OFF
	mMC25_�������[�^=OFF
	mMC26_�������[�^=OFF
	mMC27_���[�^���[��=OFF
	
	�R���x�A�ꎞ��~=ON
else if LDP(timerr_MC25_�������[�^.B) then
	almMC25_�������[�^=ON
	
	mMC23_���[�^���[��=OFF
	mMC25_�������[�^=OFF
	mMC26_�������[�^=OFF
	mMC27_���[�^���[��=OFF
	
	�R���x�A�ꎞ��~=ON

else if LDP(timerr_MC26_�������[�^.B) then
	almMC26_�������[�^=ON

	mMC23_���[�^���[��=OFF
	mMC25_�������[�^=OFF
	mMC26_�������[�^=OFF
	mMC27_���[�^���[��=OFF
	
	�R���x�A�ꎞ��~=ON

else if LDP(timerr_MC27_���[�^���[��.B) then
	almMC27_���[�^���[��=ON
	
	mMC23_���[�^���[��=OFF
	mMC25_�������[�^=OFF
	mMC26_�������[�^=OFF
	mMC27_���[�^���[��=OFF
	
	�R���x�A�ꎞ��~=ON

end if

if (ldp(tim_XSW63_�X�g�b�p���~�[.B) or ldp(tim_notXSW63_�X�g�b�p���~�[.B)) and not(pnlPBXSW63_�X�g�b�p���~�[)then
	almXSW63_�X�g�b�p���~�[=ON
	pnlPBXSW63_�X�g�b�p���~�[=ON
	if tim_XSW63_�X�g�b�p���~�[ then
		res(tim_XSW63_�X�g�b�p���~�[)
	end if
	�����R���x�AEErrStep=1

else if (ldp(tim_XSW64_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW64_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW64_�X�g�b�p�㏸�[)then
	pauseSV53_�X�g�b�p=ON
	almXSW64_�X�g�b�p�㏸�[=ON
	pnlPBXSW64_�X�g�b�p�㏸�[=ON
	if tim_XSW64_�X�g�b�p�㏸�[ then
		res(tim_XSW64_�X�g�b�p�㏸�[)
	end if
	�����R���x�AEErrStep=1

else if (ldp(tim_XSW65_�X�g�b�p���~�[.B) or ldp(tim_notXSW65_�X�g�b�p���~�[.B)) and not(pnlPBXSW65_�X�g�b�p���~�[)then
	almXSW65_�X�g�b�p���~�[=ON
	pnlPBXSW65_�X�g�b�p���~�[=ON
	if tim_XSW65_�X�g�b�p���~�[ then
		res(tim_XSW65_�X�g�b�p���~�[)
	end if
	�����R���x�AEErrStep=1

else if (ldp(tim_XSW66_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW66_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW66_�X�g�b�p�㏸�[)then
	pauseSV54_�X�g�b�p=ON
	almXSW66_�X�g�b�p�㏸�[=ON
	pnlPBXSW66_�X�g�b�p�㏸�[=ON
	if tim_XSW66_�X�g�b�p�㏸�[ then
		res(tim_XSW66_�X�g�b�p�㏸�[)
	end if
	�����R���x�AEErrStep=1

else if �����R���x�AE���쒆 and not(�����R���x�AF���쒆) and (ldp(tim_XSW68_���t�g�㏸�[.B) or ldp(tim_notXSW68_���t�g�㏸�[.B)) and not(pnlPBXSW68_���t�g�㏸�[) then
	pauseSV55_���t�g=ON
	almXSW68_���t�g�㏸�[=ON
	pnlPBXSW68_���t�g�㏸�[=ON
	if tim_XSW68_���t�g�㏸�[ then
		res(tim_XSW68_���t�g�㏸�[)
	end if
	�����R���x�AEErrStep=1

else if �����R���x�AE���쒆 and not(�����R���x�AF���쒆) and (ldp(tim_XSW67_���t�g���~�[.B) or ldp(tim_notXSW67_���t�g���~�[.B)) and not(pnlPBXSW67_���t�g���~�[) then
	almXSW67_���t�g���~�[=ON
	pnlPBXSW67_���t�g���~�[=ON
	if tim_XSW67_���t�g���~�[ then
		res(tim_XSW67_���t�g���~�[)
	end if
	�����R���x�AEErrStep=1

else if �����R���x�AE���쒆 and not(�����R���x�AF���쒆) and (ldp(tim_XSW69_�X�g�b�p���~�[.B) or ldp(tim_notXSW69_�X�g�b�p���~�[.B)) and not(pnlPBXSW69_�X�g�b�p���~�[) then
	almXSW69_�X�g�b�p���~�[=ON
	pnlPBXSW69_�X�g�b�p���~�[=ON
	if tim_XSW69_�X�g�b�p���~�[ then
		res(tim_XSW69_�X�g�b�p���~�[)
	end if
	�����R���x�AEErrStep=1

else if �����R���x�AE���쒆 and not(�����R���x�AF���쒆) and (ldp(tim_XSW70_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW70_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW70_�X�g�b�p�㏸�[) then
	pauseSV56_�X�g�b�p=ON
	almXSW70_�X�g�b�p�㏸�[=ON
	pnlPBXSW70_�X�g�b�p�㏸�[=ON
	if tim_XSW70_�X�g�b�p�㏸�[ then
		res(tim_XSW70_�X�g�b�p�㏸�[)
	end if
	�����R���x�AEErrStep=1

else if (ldp(tim_XSW53_���t�g���~�[.B) or ldp(tim_notXSW53_���t�g���~�[.B)) and not(pnlPBXSW53_���t�g���~�[) then
	almXSW53_���t�g���~�[=ON
	pnlPBXSW53_���t�g���~�[=ON
	if tim_XSW53_���t�g���~�[ then
		res(tim_XSW53_���t�g���~�[)
	end if
	�����R���x�ADErrStep=1

else if (ldp(tim_XSW54_���t�g�㏸�[.B) or ldp(tim_notXSW54_���t�g�㏸�[.B)) and not(pnlPBXSW54_���t�g�㏸�[) then
	pauseSV44_���t�g=ON
	almXSW54_���t�g�㏸�[=ON
	pnlPBXSW54_���t�g�㏸�[=ON
	if tim_XSW54_���t�g�㏸�[ then
		res(tim_XSW54_���t�g�㏸�[)
	end if
	�����R���x�ADErrStep=1


end if

tmr(not(PH29_�����m),timnotdly_PH29_�����m,3)
tmr(not(PH30_�t�^���m),timnotdly_PH30_�t�^���m,3)


'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�AEEmgStep	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�AEAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�AEEmg	���̏��~


if �����R���x�AEEmgStep=0 then  
	
	if �����R���x�AEErrStep=0  then

	if not(�R���x�A�ꎞ��~) then

	if not(�����R���x�AEOrgErr) then

	if (�����R���x�AEAutoMode and ��������AutoMode ) or �����R���x�AEstep<>0 then
	
		if ManualInite=1 then
			mSV53_�X�g�b�p=ON
			mSV54_�X�g�b�p=ON

			if PH36_�����m or PH37_�t�^���m then
				�����R���x�AE���쒆=OFF '�r�o���쎞�̓��쒆�M��OFF
				�����R���x�AE�r�o�v��=ON
				�����R���x�AEstep=1
			end if
			

			ManualInite=0
		end if
		
	
		if not(�����R���x�AEAutoMode and ��������AutoMode ) then
			�����R���x�AEAutoRun=OFF
		end if
	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�AEstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�AEAutoRun then
				inc(�����R���x�AEstep)
			else 
				�����R���x�AEstep=0 '�I���ҋ@
			end if
		
		case 2
			if PH36_�����m or PH37_�t�^���m then
				�����R���x�AE�r�o�v��=ON
				�����R���x�AEstep=1
			else
				inc(�����R���x�AEstep)

			end if				
		
		case 3
		' [ ���̔����R���x�A��~�m�F ]
			if (�����R���x�AE�r�o�v��=OFF and �����R���x�AF���쒆=OFF and not(�R���x�AF���r�o�ҋ@) and not(mMC22_�������[�^�t�])) or �����R���x�AD�r�o�v�� then
				if MC21_�������[�^���] and not(MC22_�������[�^���]) then
					�����R���x�AEstep=1
				else 			
					inc(�����R���x�AEstep)
				end if
			else
				�����R���x�AEstep=1
			end if
		
		case 4
			if not(PH29_�����m) and timnotdly_PH29_�����m and not(PH30_�t�^���m) and timnotdly_PH30_�t�^���m then
				if not(PH32_�����m) and not(PH33_�t�^���m) then
					if not(PH34_�����m) and not(PH35_�t�^���m) then
						�����R���x�AD�r�o�v��=OFF
						�����R���x�AEstep=1
					else
						inc(�����R���x�AEstep)
					end if
				else
					inc(�����R���x�AEstep)
				end if
			else
				inc(�����R���x�AEstep)
			end if
			
		case 5  '���_���o
			if �����R���x�AEOrg then
				errpass�R���x�A�ꎞ��~=OFF			
				inc(�����R���x�AEstep)
			else
				�����R���x�AEstep=1
			end if
				
		case 6 		 
			if �����R���x�AE�r�o�v��=OFF and �����R���x�AF���쒆=OFF and not(�R���x�AF���r�o�ҋ@) then
				inc(�����R���x�AEstep)
			else if �����R���x�AD�r�o�v�� then
				�����R���x�AE���쒆=ON
				�����R���x�AEstep=200
			end if
			
		case 7
			if PH34_�����m or PH35_�t�^���m then
				�����R���x�AE���쒆=ON
				�����R���x�AEstep=100
			else if �����R���x�AD�r�o�v�� then
				�����R���x�AE���쒆=ON
				�����R���x�AEstep=200			
			else
				�����R���x�AEstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		' �����R���x�AE�r�o
		'--------------------------------------------------------------------------------------------------------------	
		case 100		
			'�����R���x�AD���t�g
			PH29_���N�����m=OFF
			PH30_�t�^�N�����m=OFF
			'�ҋ@1
			PH32_���N�����m=OFF
			PH33_�t�^�N�����m=OFF
			'�ҋ@2
			PH34_���N�����m=OFF
			PH35_�t�^�N�����m=OFF
			
			tim_procstep_val=0 '���t�^���o����
			res(tim_procstep)
			
			inc(�����R���x�AEstep)
			
		case 101
			if not(MC21_�������[�^���]) then
				'�����R���x�AD���t�g
				PH29_���N�����m=PH29_���N�����m or PH29_�����m
				PH30_�t�^�N�����m=PH30_�t�^�N�����m or PH30_�t�^���m
			end if
			
			'�ҋ@1
			PH32_���N�����m=PH32_���N�����m or PH32_�����m
			PH33_�t�^�N�����m=PH33_�t�^�N�����m or PH33_�t�^���m
			'�ҋ@2
			PH34_���N�����m=PH34_���N�����m or PH34_�����m
			PH35_�t�^�N�����m=PH35_�t�^�N�����m or PH35_�t�^���m

			if tim_procstep.B then
				inc(�����R���x�AEstep)
			end if		

		
		case 102
			mSV56_�X�g�b�p=ON '�㏸
			mSV55_���t�g=ON '�㏸
			inc(�����R���x�AEstep)
			
		case 103
			if (XSW68_���t�g�㏸�[ and not(pnlPBXSW68_���t�g�㏸�[)) or passXSW68_���t�g�㏸�[ then
				if (XSW70_�X�g�b�p�㏸�[ and not(pnlPBXSW70_�X�g�b�p�㏸�[)) or passXSW70_�X�g�b�p�㏸�[ then
					inc(�����R���x�AEstep)
				end if
			end if
		
		case 104
			tim_procstep_val=0
			res(tim_procstep)
			MC27_���[�^���[��step=1
			inc(�����R���x�AEstep)
			
		case 105
			if tim_procstep.B then
				if PH32_�����m or PH33_�t�^���m or PH34_�����m or PH35_�t�^���m then
					tim_procstep_val=10
					res(tim_procstep)
					MC26_�������[�^step=1
				end if
				inc(�����R���x�AEstep)
			end if
			
		case 106
			if tim_procstep.B then
				if PH29_���N�����m or PH30_�t�^�N�����m or PH32_�����m or PH33_�t�^���m then
					tim_procstep_val=10
					res(tim_procstep)
					MC25_�������[�^step=1
				end if
				inc(�����R���x�AEstep)
			end if		


		case 107
			if tim_procstep.B then
				MC23_���[�^���[��step=1
				inc(�����R���x�AEstep)
			end if		
	
		case 108
			if MC23_���[�^���[��step=0 and MC25_�������[�^step=0 and MC26_�������[�^step=0 and MC27_���[�^���[��step=0 then
				StageDevice24=StageDevice23
				StageDevice23=StageDevice21			
				inc(�����R���x�AEstep)
			end if

		case 109
			mSV56_�X�g�b�p=OFF '���~
			�����R���x�AE���쒆=OFF
			inc(�����R���x�AEstep)

		case 110
			if (XSW69_�X�g�b�p���~�[ and not(pnlPBXSW69_�X�g�b�p���~�[)) or passXSW69_�X�g�b�p���~�[ then
				inc(�����R���x�AEstep)
			end if

		case 111
			�����R���x�AE���쒆=OFF '�r�o���쎞�̓��쒆�M��OFF
			�����R���x�AE�r�o�v��=ON
			�����R���x�AEstep=1

		'--------------------------------------------------------------------------------------------------------------
		' �����R���x�AE�����i�����R���x�AD�r�o�v������)
		'--------------------------------------------------------------------------------------------------------------	
		case 200
		
			'�����R���x�AD���t�g
			PH29_���N�����m=OFF
			PH30_�t�^�N�����m=OFF
			'�ҋ@1
			PH32_���N�����m=OFF
			PH33_�t�^�N�����m=OFF
			'�ҋ@2
			PH34_���N�����m=OFF
			PH35_�t�^�N�����m=OFF
			
			tim_procstep_val=0
			res(tim_procstep)
			
			inc(�����R���x�AEstep)
			
		case 201
			if not(MC21_�������[�^���]) then
				'�����R���x�AD���t�g
				PH29_���N�����m=PH29_���N�����m or PH29_�����m
				PH30_�t�^�N�����m=PH30_�t�^�N�����m or PH30_�t�^���m
			end if
			
			'�ҋ@1
			PH32_���N�����m=PH32_���N�����m or PH32_�����m
			PH33_�t�^�N�����m=PH33_�t�^�N�����m or PH33_�t�^���m
			'�ҋ@2
			PH34_���N�����m=PH34_���N�����m or PH34_�����m
			PH35_�t�^�N�����m=PH35_�t�^�N�����m or PH35_�t�^���m

			if tim_procstep.B then
				inc(�����R���x�AEstep)
			end if		
		
		case 202
			'�ҋ@1��,�ҋ@2��
			if not(PH32_���N�����m) and not(PH33_�t�^�N�����m) and not(PH34_���N�����m) and not(PH35_�t�^�N�����m) then 
				�����R���x�AEstep=230
			'�ҋ@1��
			else if (not(PH32_���N�����m) and not(PH33_�t�^�N�����m)) and (PH34_���N�����m or PH35_�t�^�N�����m) then
				�����R���x�AEstep=250		
			'�ҋ@�󂫂Ȃ� �r�o�҂�
			else if (PH32_���N�����m or PH33_�t�^�N�����m) and (not(PH34_���N�����m) and not(PH35_�t�^�N�����m)) then
				�����R���x�AEstep=280
				
			else if  (PH32_���N�����m or PH33_�t�^�N�����m) and (PH34_���N�����m or PH35_�t�^�N�����m) then
			
				�����R���x�AE�r�o�v��=ON
				�����R���x�AE���쒆=OFF
				�����R���x�AEstep=1			
			end if
		

		'----------------------
		'�ҋ@2�Ɉړ�
		'----------------------
		case 230
			mSV44_���t�g=ON
			mSV53_�X�g�b�p=OFF
			mSV54_�X�g�b�p=ON

			MC23_���[�^���[��step=1
			mMC25_�������[�^=ON
			mMC26_�������[�^=ON
			errpass�R���x�A�ꎞ��~=OFF

			inc(�����R���x�AEstep)

		case 231
			if (XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[)) or passXSW54_���t�g�㏸�[ then
				if (XSW63_�X�g�b�p���~�[ and not(pnlPBXSW63_�X�g�b�p���~�[)) or passXSW63_�X�g�b�p���~�[ then
					if (XSW66_�X�g�b�p�㏸�[ and not(pnlPBXSW66_�X�g�b�p�㏸�[))  or passXSW66_�X�g�b�p�㏸�[ then
						inc(�����R���x�AEstep)
					end if
				end if	
			end if
		
		case 232
			inc(�����R���x�AEstep)

		case 233
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�AEstep)
			
			else if not(PH29_�����m) and timnotdly_PH29_�����m and not(PH30_�t�^���m) and timnotdly_PH30_�t�^���m then
				inc(�����R���x�AEstep)
			end if
				
		case 234
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�AEstep)
			
			else if PH34_�����m or PH35_�t�^���m then
				inc(�����R���x�AEstep)
			end if
		
		case 235
			tim_procstep_val=20
			res(tim_procstep)
			inc(�����R���x�AEstep)
		
		case 236
			if tim_procstep.B then
				inc(�����R���x�AEstep)
			end if
		
		case 237
			mMC25_�������[�^=OFF
			mMC26_�������[�^=OFF
			mSV53_�X�g�b�p=ON
			inc(�����R���x�AEstep)
		
		case 238
			if MC23_���[�^���[��step=0 then
				inc(�����R���x�AEstep)
			end if
		
		case 239
			if (XSW64_�X�g�b�p�㏸�[ and not(pnlPBXSW64_�X�g�b�p�㏸�[)) or passXSW64_�X�g�b�p�㏸�[ then
				inc(�����R���x�AEstep)
			end if
		
		case 240
			StageDevice24=StageDevice21
			StageDevice23=0

			�����R���x�AD�r�o�v��=OFF
			�����R���x�AE�r�o�v��=ON
			�����R���x�AE���쒆=OFF
			�����R���x�AEstep=1

		
		'----------------------
		'�ҋ@1�Ɉړ�
		'----------------------
		case 250
			mSV44_���t�g=ON
			mSV53_�X�g�b�p=ON
			mSV54_�X�g�b�p=ON
			
			MC23_���[�^���[��step=1
			mMC25_�������[�^=ON
			errpass�R���x�A�ꎞ��~=OFF
			
			inc(�����R���x�AEstep)

		case 251
			if (XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[)) or passXSW54_���t�g�㏸�[ then
				if (XSW64_�X�g�b�p�㏸�[ and not(pnlPBXSW64_�X�g�b�p�㏸�[)) or passXSW64_�X�g�b�p�㏸�[ then
					if (XSW66_�X�g�b�p�㏸�[ and not(pnlPBXSW66_�X�g�b�p�㏸�[)) or passXSW66_�X�g�b�p�㏸�[ then
						inc(�����R���x�AEstep)
					end if
				end if
			end if
			
		case 252
			inc(�����R���x�AEstep)

		case 253
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�AEstep)
			
			else if not(PH29_�����m) and timnotdly_PH29_�����m and not(PH30_�t�^���m) and timnotdly_PH30_�t�^���m then
				inc(�����R���x�AEstep)
			end if
				
		case 254
			if errpass�R���x�A�ꎞ��~ then
				inc(�����R���x�AEstep)
			
			else if PH32_�����m or PH33_�t�^���m then
				inc(�����R���x�AEstep)
			end if
		
		case 255
			tim_procstep_val=20
			res(tim_procstep)
			inc(�����R���x�AEstep)
		
		case 256
			if tim_procstep.B then
				inc(�����R���x�AEstep)
			end if
		
		case 257
			mMC25_�������[�^=OFF
			inc(�����R���x�AEstep)
		
		case 258
			if MC23_���[�^���[��step=0 and MC25_�������[�^step=0 then
				inc(�����R���x�AEstep)
			end if
		
		case 259
			StageDevice23=StageDevice21			
			�����R���x�AE���쒆=OFF
			�����R���x�AD�r�o�v��=OFF
			�����R���x�AE�r�o�v��=ON
			inc(�����R���x�AEstep)
			
		case 260
			if (XSW64_�X�g�b�p�㏸�[ and not(pnlPBXSW64_�X�g�b�p�㏸�[)) or passXSW64_�X�g�b�p�㏸�[ then
				inc(�����R���x�AEstep)
			end if
		
		case 261
			�����R���x�AEstep=1
			
		'----------------------
		'�ҋ@2�Ɉړ�
		'----------------------
		case 280
			mSV44_���t�g=ON
			mSV54_�X�g�b�p=ON

			mMC26_�������[�^=ON
			errpass�R���x�A�ꎞ��~=OFF
			inc(�����R���x�AEstep)
			
		case 281
			if (XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[)) or passXSW54_���t�g�㏸�[ then
				if (XSW66_�X�g�b�p�㏸�[ and not(pnlPBXSW66_�X�g�b�p�㏸�[)) or passXSW66_�X�g�b�p�㏸�[ then
					inc(�����R���x�AEstep)
				end if
			end if
			
		case 282
			SV53_�X�g�b�pstep=1
			inc(�����R���x�AEstep)
		
		case 283
			tim_procstep_val=10
			res(tim_procstep)
			inc(�����R���x�AEstep)
		
		case 284
			if tim_procstep.B then
				inc(�����R���x�AEstep)
			end if
		
		case 285
			MC25_�������[�^step=1
			inc(�����R���x�AEstep)
		
		case 286
			tim_procstep_val=10
			res(tim_procstep)
			inc(�����R���x�AEstep)
		
		case 287
			if tim_procstep.B then
				inc(�����R���x�AEstep)
			end if

		case 288
			MC23_���[�^���[��step=1
			inc(�����R���x�AEstep)

		case 289
			if MC23_���[�^���[��step=0 and MC25_�������[�^step=0 and SV53_�X�g�b�pstep=0 then
				inc(�����R���x�AEstep)
			end if
		
		case 290
			mMC26_�������[�^=OFF
			inc(�����R���x�AEstep)
		
		case 291
			StageDevice24=StageDevice23						
			StageDevice23=StageDevice21			
			�����R���x�AE���쒆=OFF
			�����R���x�AD�r�o�v��=OFF
			�����R���x�AE�r�o�v��=ON
			�����R���x�AEstep=1

		end select

	
	'-----------------------------------------------------------------
	' �������[�^�A�X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	'���t�g
	'mMC23_���[�^���[��
	'PH29_���N�����m=PH29_�����m
	'PH30_�t�^�N�����m=PH30_�t�^���m
	
	'mMC25_�������[�^	mSV53_�X�g�b�p
	'PH32_���N�����m=PH32_�����m
	'PH33_�t�^�N�����m=PH33_�t�^���m
	
	'mMC26_�������[�^	mSV54_�X�g�b�p
	'PH34_���N�����m=PH34_�����m
	'PH35_�t�^�N�����m=PH35_�t�^���m
	
	'mMC27_���[�^���[�� mSV55_���t�g mSV56_�X�g�b�p
	'PH36_���N�����m=PH36_�����m
	'PH37_�t�^�N�����m=PH37_�t�^���m
	'-----------------------------------------------------------------
	tmr(tim_SV53_�X�g�b�p,tim_SV53_�X�g�b�p_val)
	select case SV53_�X�g�b�pstep
	case 0
	
	case 1
		inc(SV53_�X�g�b�pstep)

	case 2
		if PH29_���N�����m or PH30_�t�^�N�����m or PH32_�����m or PH33_�t�^���m then
			mSV53_�X�g�b�p=OFF
			inc(SV53_�X�g�b�pstep)
		else
			SV53_�X�g�b�pstep=0 '�I��
		end if

	case 3
		if (XSW63_�X�g�b�p���~�[ and not(pnlPBXSW63_�X�g�b�p���~�[)) or passXSW63_�X�g�b�p���~�[ then
			inc(SV53_�X�g�b�pstep)
		end if

	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(SV53_�X�g�b�pstep)

		else if not(PH32_�����m) and not(PH33_�t�^���m) then
			tim_SV53_�X�g�b�p_val=20
			res(tim_SV53_�X�g�b�p)
			inc(SV53_�X�g�b�pstep)
		end if

	case 5	
		if errpass�R���x�A�ꎞ��~ then
			inc(SV53_�X�g�b�pstep)

		else if PH32_���N�����m or PH33_�t�^�N�����m then
			if PH34_�����m or PH35_�t�^���m then
				set(tim_SV53_�X�g�b�p)
				inc(SV53_�X�g�b�pstep)
			end if
		else
			inc(SV53_�X�g�b�pstep)
		end if

	case 6
		if errpass�R���x�A�ꎞ��~ then
			inc(SV53_�X�g�b�pstep)

		else if PH29_���N�����m and PH30_�t�^�N�����m then
			if tim_SV53_�X�g�b�p.B or PH32_�����m or PH33_�t�^���m then
				set(tim_SV53_�X�g�b�p)
				inc(SV53_�X�g�b�pstep)
			end if
		else
			tim_SV53_�X�g�b�p_val=10 '20
			res(tim_SV53_�X�g�b�p)
			inc(SV53_�X�g�b�pstep)
		end if
	
			
	case 7
		if tim_SV53_�X�g�b�p.B then
			inc(SV53_�X�g�b�pstep)
		end if
	
	case 8
		mSV53_�X�g�b�p=ON
		inc(SV53_�X�g�b�pstep)
	
	case 9
		if (XSW64_�X�g�b�p�㏸�[ and not(pnlPBXSW64_�X�g�b�p�㏸�[)) or passXSW64_�X�g�b�p�㏸�[ then
			inc(SV53_�X�g�b�pstep)
		end if	
	
	case 10
		SV53_�X�g�b�pstep=0
	
	end select
	'-----------------------------------------------------------------
	'MC23_���[�^���[��
	tmr(tim_MC23_���[�^���[��,tim_MC23_���[�^���[��_val)
	
	select case MC23_���[�^���[��step
	case 0
	case 1	
		inc(MC23_���[�^���[��step)

	case 2
		if PH29_���N�����m or PH30_�t�^�N�����m then
			inc(MC23_���[�^���[��step)
		else
			�����R���x�AD�r�o�v��=OFF
			�����R���x�AE���쒆=OFF
			MC23_���[�^���[��step=0
		end if

	case 3
		mSV44_���t�g=ON '�㏸
		inc(MC23_���[�^���[��step)

	case 4
		if (XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[)) or passXSW54_���t�g�㏸�[ then
			inc(MC23_���[�^���[��step)
		end if
		
	case 5
		mMC23_���[�^���[��=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC23_���[�^���[��step)

	case 6
		if errpass�R���x�A�ꎞ��~ then
			inc(MC23_���[�^���[��step)		
		
		else if not(PH29_�����m) and timnotdly_PH29_�����m and not(PH30_�t�^���m) and timnotdly_PH30_�t�^���m then
			inc(MC23_���[�^���[��step)		
		end if
	
	case 7
		if errpass�R���x�A�ꎞ��~ then
			inc(MC23_���[�^���[��step)		
		else if PH29_���N�����m or PH30_�t�^�N�����m then
			if PH32_�����m or PH33_�t�^���m then
				inc(MC23_���[�^���[��step)
			end if
		end if
	
	case 8
		tim_MC23_���[�^���[��_val=0
		res(tim_MC23_���[�^���[��)
		inc(MC23_���[�^���[��step)

	case 9
		if tim_MC23_���[�^���[��.B then
			inc(MC23_���[�^���[��step)
		end if
	
	case 10
		mMC23_���[�^���[��=OFF
		mSV44_���t�g=OFF '���~
		inc(MC23_���[�^���[��step)
	
	case 11
		if (XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[)) or passXSW53_���t�g���~�[ then
			inc(MC23_���[�^���[��step)
		end if
	
	case 12
		�����R���x�AD�r�o�v��=OFF
		�����R���x�AE���쒆=OFF
		MC23_���[�^���[��step=0
	
	end select
	
	'--------------------------------------------
	'MC25_�������[�^
	tmr(tim_MC25_�������[�^,tim_MC25_�������[�^_val)
	select case MC25_�������[�^step
	case 0
	case 1
		inc(MC25_�������[�^step)

	case 2
		if PH29_���N�����m or PH30_�t�^�N�����m or PH32_�����m or PH33_�t�^���m then
			inc(MC25_�������[�^step)
		else
			MC25_�������[�^step=0
		end if

	case 3
		SV53_�X�g�b�pstep=1
		inc(MC25_�������[�^step)
	
	case 4
		if SV53_�X�g�b�pstep=0 or (not(mSV53_�X�g�b�p) and ( (XSW63_�X�g�b�p���~�[ and not(pnlPBXSW63_�X�g�b�p���~�[)) or passXSW63_�X�g�b�p���~�[)) then
			inc(MC25_�������[�^step)
		end if

	case 5
		mMC25_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC25_�������[�^step)

	case 6
		tim_MC25_�������[�^_val=10
		res(tim_MC25_�������[�^)
		inc(MC25_�������[�^step)
	
	case 7
		if tim_MC25_�������[�^.B then
			inc(MC25_�������[�^step)
		end if		
	
	case 8
		if MC23_���[�^���[��step=0 then
			MC23_���[�^���[��step=1
		end if
		inc(MC25_�������[�^step)

	case 9
		if errpass�R���x�A�ꎞ��~ then
			inc(MC25_�������[�^step)		
		
		else if not(PH32_�����m) and  not(PH33_�t�^���m)  then
			inc(MC25_�������[�^step)		
		end if

	case 10
		if errpass�R���x�A�ꎞ��~ then
			inc(MC25_�������[�^step)		
		
		else if PH29_���N�����m or PH30_�t�^�N�����m then
			if PH32_�����m or PH33_�t�^���m then
				inc(MC25_�������[�^step)
			end if
		else if PH32_���N�����m or PH33_�t�^�N�����m then
			if PH34_�����m or PH35_�t�^���m then
				inc(MC25_�������[�^step)
			end if
		end if
	
	case 11
		tim_MC25_�������[�^_val=10
		res(tim_MC25_�������[�^)
		inc(MC25_�������[�^step)

	case 12
		if tim_MC25_�������[�^.B then
			inc(MC25_�������[�^step)
		end if
	
	case 13
		mMC25_�������[�^=OFF
		inc(MC25_�������[�^step)
	
	case 14
		if  SV53_�X�g�b�pstep=0 and MC23_���[�^���[��step=0 then
			inc(MC25_�������[�^step)
		end if
	
	case 15
		MC25_�������[�^step=0

	
	end select
	'--------------------------------------------
	tmr(tim_SV54_�X�g�b�p, tim_SV54_�X�g�b�p_val)
	select case SV54_�X�g�b�pstep
	case 0
	case 1
		if PH32_�����m or PH33_�t�^���m or PH34_�����m or PH35_�t�^���m then
			mSV54_�X�g�b�p=OFF
			inc(SV54_�X�g�b�pstep)
		else
			SV54_�X�g�b�pstep=0 '�I��
		end if

	case 2
		if (XSW65_�X�g�b�p���~�[ and not(pnlPBXSW65_�X�g�b�p���~�[)) or passXSW65_�X�g�b�p���~�[ then
			inc(SV54_�X�g�b�pstep)
		end if

	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(SV54_�X�g�b�pstep)
		
		else if not(PH32_�����m) and not(PH33_�t�^���m) and not(PH34_�����m) and not(PH35_�t�^���m) then
			tim_SV54_�X�g�b�p_val=20
			res(tim_SV54_�X�g�b�p)
			inc(SV54_�X�g�b�pstep)
		end if

	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(SV54_�X�g�b�pstep)
		
		else if PH32_���N�����m and PH33_�t�^�N�����m then
			if tim_SV54_�X�g�b�p.B or PH34_�����m or PH35_�t�^���m then
				tim_SV54_�X�g�b�p_val=0
				res(tim_SV54_�X�g�b�p)
				inc(SV54_�X�g�b�pstep)
			end if
		else if PH34_���N�����m or PH35_�t�^�N�����m then
			if PH36_�����m or PH37_�t�^���m then
				tim_SV54_�X�g�b�p_val=20
				res(tim_SV54_�X�g�b�p)
				inc(SV54_�X�g�b�pstep)
			end if
		else
			inc(SV54_�X�g�b�pstep)
		end if

	case 5
		if tim_SV54_�X�g�b�p.B then
			inc(SV54_�X�g�b�pstep)
		end if	

	case 6
		mSV54_�X�g�b�p=ON
		inc(SV54_�X�g�b�pstep)
	
	case 7
		if (XSW66_�X�g�b�p�㏸�[ and not(pnlPBXSW66_�X�g�b�p�㏸�[)) or passXSW66_�X�g�b�p�㏸�[ then
			inc(SV54_�X�g�b�pstep)
		end if	
	
	case 8
		SV54_�X�g�b�pstep=0
	
	end select
	'--------------------------------------------
	'MC26_�������[�^
	tmr(tim_MC26_�������[�^,tim_MC26_�������[�^_val)
	select case MC26_�������[�^step
	case 0
	case 1
		inc(MC26_�������[�^step)

	case 2
		if PH32_�����m or PH33_�t�^���m or PH34_�����m or PH35_�t�^���m then
			inc(MC26_�������[�^step)
		else
			MC26_�������[�^step=0
		end if

	case 3
		SV54_�X�g�b�pstep=1
		inc(MC26_�������[�^step)

	case 4
		if SV54_�X�g�b�pstep=0 or (not(mSV54_�X�g�b�p) and ( (XSW65_�X�g�b�p���~�[ and not(pnlPBXSW65_�X�g�b�p���~�[)) or passXSW65_�X�g�b�p���~�[)) then
			inc(MC26_�������[�^step)
		 end if
		
	case 5
		MC25_�������[�^step=1
		mMC26_�������[�^=ON
		inc(MC26_�������[�^step)

	case 6
		if errpass�R���x�A�ꎞ��~ then
			inc(MC26_�������[�^step)		
		
		else if  not(PH32_�����m) and  not(PH33_�t�^���m) and not(PH34_�����m) and not(PH35_�t�^���m) then
			inc(MC26_�������[�^step)		
		end if

	case 7
		if errpass�R���x�A�ꎞ��~ then
			inc(MC26_�������[�^step)		
		
		else if PH32_���N�����m or PH33_�t�^�N�����m then
			if PH34_�����m or PH35_�t�^���m then
				inc(MC26_�������[�^step)
			end if
		else if PH34_���N�����m or PH35_�t�^�N�����m then
			if PH36_�����m or PH37_�t�^���m then
				inc(MC26_�������[�^step)
			end if
		end if
	
	case 8
		tim_MC26_�������[�^_val=25
		res(tim_MC26_�������[�^)
		inc(MC26_�������[�^step)

	case 9
		if tim_MC26_�������[�^.B then
			inc(MC26_�������[�^step)
		end if
	
	case 10
		mMC26_�������[�^=OFF
		inc(MC26_�������[�^step)
	
	case 11
		MC26_�������[�^step=0

	
	end select

	'--------------------------------------------
	'MC27_���[�^���[��
	tmr(tim_MC27_���[�^���[��,tim_MC27_���[�^���[��_val)
	select case MC27_���[�^���[��step
	case 0
	case 1
		inc(MC27_���[�^���[��step)

	case 2
		if PH34_�����m or PH35_�t�^���m then
			inc(MC27_���[�^���[��step)
		else
			MC27_���[�^���[��step=0
		end if
	
	case 3
		mMC27_���[�^���[��=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC27_���[�^���[��step)

	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(MC27_���[�^���[��step)		
		
		else if not(PH34_�����m) and not(PH35_�t�^���m) then
			inc(MC27_���[�^���[��step)		
		end if
	
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(MC27_���[�^���[��step)		
		
		else if PH34_���N�����m or PH35_�t�^�N�����m then
			if PH36_�����m or PH37_�t�^���m then
				inc(MC27_���[�^���[��step)
			end if
		end if
	
	case 6
		tim_MC27_���[�^���[��_val=30
		res(tim_MC27_���[�^���[��)
		inc(MC27_���[�^���[��step)

	case 7
		if tim_MC27_���[�^���[��.B then
			inc(MC27_���[�^���[��step)
		end if
	
	case 8
		mMC27_���[�^���[��=OFF
		inc(MC27_���[�^���[��step)
	
	case 9
		StageDevice25=StageDevice24
	
'		�����R���x�AE���쒆=OFF '�r�o���쎞�̓��쒆�M��OFF
'		�����R���x�AE�r�o�v��=ON
		MC27_���[�^���[��step=0
	
	end select
	'-----------------------------------------------------------------




	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else
	
		if ManualInite=0 then
			mSV53_�X�g�b�p=OFF
			mSV54_�X�g�b�p=OFF		
			ManualInite=1
		end if

		�����R���x�AEAutoRun=OFF
		
		�����R���x�AEstep=0 '�I��

		res(timerr_MC23_���[�^���[��)
		res(timerr_MC25_�������[�^)
		res(timerr_MC26_�������[�^)
		res(timerr_MC27_���[�^���[��)

		if ldp(pnlPBSV53_�X�g�b�p) then
			if mSV53_�X�g�b�p then
				mSV53_�X�g�b�p=OFF
			else
				mSV53_�X�g�b�p=ON
			end if
		end if
		
		
		if ldp(pnlPBSV54_�X�g�b�p) then
			if mSV54_�X�g�b�p then
				mSV54_�X�g�b�p=OFF
			else
				mSV54_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBMC23_���[�^���[��) then
			if mMC23_���[�^���[�� then
				mMC23_���[�^���[��=OFF
			else 'if XSW54_���t�g�㏸�[ then
				mMC23_���[�^���[��=ON
			end if
		end if
		
		if ldp(pnlPBMC25_�������[�^) then
			if mMC25_�������[�^ then
				mMC25_�������[�^=OFF
			else
				mMC25_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC26_�������[�^) then
			if mMC26_�������[�^ then
				mMC26_�������[�^=OFF
			else
				mMC26_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC27_���[�^���[��) then
			if mMC27_���[�^���[�� then
				mMC27_���[�^���[��=OFF
			else 'if XSW68_���t�g�㏸�[ and XSW70_�X�g�b�p�㏸�[ then
				mMC27_���[�^���[��=ON
			end if
		end if
		
				
		if ldp(pnlPBSV56_�X�g�b�p) then
			if mSV56_�X�g�b�p then
				mSV56_�X�g�b�p=OFF
			else
				mSV56_�X�g�b�p=ON
			end if
		end if
		
		
		if ldp(pnlPBSV55_���t�g) then
			if mSV55_���t�g then
				mSV55_���t�g=OFF
			else
				mSV55_���t�g=ON
			end if
		end if

			
	end if '�����R���x�AEEmgStep and not(�����R���x�AEOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�AEOrgErr���� �z
	else
	
		if ResetFlg then
			�����R���x�AEOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else
		res(timerr_MC25_�������[�^)
		res(timerr_MC26_�������[�^)
	
		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON
	
		if ResetFlg then
			almMC23_���[�^���[��=OFF
			almMC25_�������[�^=OFF
			almMC26_�������[�^=OFF
			almMC27_���[�^���[��=OFF
			
			�R���x�A�ꎞ��~=OFF
			�R���x�A�ꎞ��~��=OFF
			alm�a�،x��=OFF
			
			errpass�R���x�A�ꎞ��~=ON

		end if
	end if
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�AEErr=ON

		pauseMC23_���[�^���[��=ON
		pauseMC25_�������[�^=ON
		pauseMC26_�������[�^=ON
		pauseMC27_���[�^���[��=ON
		

		select case �����R���x�AEErrStep
		case 0
		case 1
			alm�a�،x��=ON
	
			if ResetFlg then
				almMC23_���[�^���[��=OFF
				almMC25_�������[�^=OFF
				almMC26_�������[�^=OFF
				almMC27_���[�^���[��=OFF

				almXSW63_�X�g�b�p���~�[=OFF
				almXSW64_�X�g�b�p�㏸�[=OFF
				almXSW65_�X�g�b�p���~�[=OFF
				almXSW66_�X�g�b�p�㏸�[=OFF

				almXSW68_���t�g�㏸�[=OFF
				almXSW67_���t�g���~�[=OFF
				almXSW69_�X�g�b�p���~�[=OFF
				almXSW70_�X�g�b�p�㏸�[=OFF

				almXSW53_���t�g���~�[=OFF
				almXSW54_���t�g�㏸�[=OFF
				
				alm�a�،x��=OFF

				inc(�����R���x�AEErrStep)
			end if
		case 2

			res(tim_XSW63_�X�g�b�p���~�[.B)
			res(tim_XSW64_�X�g�b�p�㏸�[.B)
			res(tim_XSW65_�X�g�b�p���~�[.B)
			res(tim_XSW66_�X�g�b�p�㏸�[.B)
			
			res(tim_XSW68_���t�g�㏸�[.B)
			res(tim_XSW67_���t�g���~�[.B)
			res(tim_XSW69_�X�g�b�p���~�[.B)
			res(tim_XSW70_�X�g�b�p�㏸�[.B)
			
			res(tim_XSW53_���t�g���~�[)
			res(tim_XSW54_���t�g�㏸�[)
			
			res(tim_notXSW63_�X�g�b�p���~�[.B)
			res(tim_notXSW64_�X�g�b�p�㏸�[.B)
			res(tim_notXSW65_�X�g�b�p���~�[.B)
			res(tim_notXSW66_�X�g�b�p�㏸�[.B)
			
			res(tim_notXSW68_���t�g�㏸�[.B)
			res(tim_notXSW67_���t�g���~�[.B)
			res(tim_notXSW69_�X�g�b�p���~�[.B)
			res(tim_notXSW70_�X�g�b�p�㏸�[.B)
			
			res(tim_notXSW53_���t�g���~�[)
			res(tim_notXSW54_���t�g�㏸�[)

			pauseMC23_���[�^���[��=OFF
			pauseMC25_�������[�^=OFF
			pauseMC26_�������[�^=OFF
			pauseMC27_���[�^���[��=OFF

			pauseSV53_�X�g�b�p=OFF
			pauseSV54_�X�g�b�p=OFF
			pauseSV55_���t�g=OFF
			pauseSV56_�X�g�b�p=OFF
			pauseSV44_���t�g=OFF

			�����R���x�AEErr=OFF
			�����R���x�AEErrStep=0
		end select

	end if 'if �����R���x�AEErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �����R���x�AEEmgStep
	case 0
	
	case 1
		�����R���x�AEAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�AEAutoMode and ��������AutoMode ) or �����R���x�AEstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgMC23_���[�^���[��=ON
			EmgMC25_�������[�^=ON
			EmgMC26_�������[�^=ON
			EmgMC27_���[�^���[��=ON


			if timstack=OFF then
			
				timnotdly_PH29_�����m_stack.U=timnotdly_PH29_�����m.U
				timnotdly_PH30_�t�^���m_stack.U=timnotdly_PH30_�t�^���m.U
				tim_procstep_stack.U=tim_procstep.U
				tim_SV53_�X�g�b�p_stack.U=tim_SV53_�X�g�b�p.U
				tim_MC23_���[�^���[��_stack.U=tim_MC23_���[�^���[��.U
				tim_MC25_�������[�^_stack.U=tim_MC25_�������[�^.U
				tim_SV54_�X�g�b�p_stack.U=tim_SV54_�X�g�b�p.U
				tim_MC26_�������[�^_stack.U=tim_MC26_�������[�^.U
				tim_MC27_���[�^���[��_stack.U=tim_MC27_���[�^���[��.U
				
			' tmr(not(PH29_�����m),timnotdly_PH29_�����m,3)
			' tmr(not(PH30_�t�^���m),timnotdly_PH30_�t�^���m,3)
			' tmr(tim_procstep,tim_procstep_val)
			' tmr(tim_SV53_�X�g�b�p,tim_SV53_�X�g�b�p_val)
			' tmr(tim_MC23_���[�^���[��,tim_MC23_���[�^���[��_val)
			' tmr(tim_MC25_�������[�^,tim_MC25_�������[�^_val)
			' tmr(tim_SV54_�X�g�b�p, tim_SV54_�X�g�b�p_val)
			' tmr(tim_MC26_�������[�^,tim_MC26_�������[�^_val)
			' tmr(tim_MC27_���[�^���[��,tim_MC27_���[�^���[��_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mSV53_�X�g�b�p=OFF
			mSV54_�X�g�b�p=OFF
			mMC23_���[�^���[��=OFF
			mMC25_�������[�^=OFF
			mMC26_�������[�^=OFF
			mMC27_���[�^���[��=OFF
			mSV56_�X�g�b�p=OFF
			mSV55_���t�g=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�AEEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�AEEmgStep)
		end if
	case 3
		if (�����R���x�AEAutoMode and ��������AutoMode ) or �����R���x�AEstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				EmgMC23_���[�^���[��=OFF
				EmgMC25_�������[�^=OFF
				EmgMC26_�������[�^=OFF
				EmgMC27_���[�^���[��=OFF

				'�X�^�b�N�̒l���^�C�}�[���ݒl�Ƀ��X�g�A
				tim_procstep.U=tim_procstep_stack.U
				tim_SV53_�X�g�b�p.U=tim_SV53_�X�g�b�p_stack.U
				tim_MC23_���[�^���[��.U=tim_MC23_���[�^���[��_stack.U
				tim_MC25_�������[�^.U=tim_MC25_�������[�^_stack.U
				tim_SV54_�X�g�b�p.U=tim_SV54_�X�g�b�p_stack.U
				tim_MC26_�������[�^.U=tim_MC26_�������[�^_stack.U
				tim_MC27_���[�^���[��.U=tim_MC27_���[�^���[��_stack.U
						
				' tmr(tim_procstep,tim_procstep_val)
				' tmr(tim_SV53_�X�g�b�p,tim_SV53_�X�g�b�p_val)
				' tmr(tim_MC23_���[�^���[��,tim_MC23_���[�^���[��_val)
				' tmr(tim_MC25_�������[�^,tim_MC25_�������[�^_val)
				' tmr(tim_SV54_�X�g�b�p, tim_SV54_�X�g�b�p_val)
				' tmr(tim_MC26_�������[�^,tim_MC26_�������[�^_val)
				' tmr(tim_MC27_���[�^���[��,tim_MC27_���[�^���[��_val)

				'���o�^�C�}�[�̃��Z�b�g
				res(timnotdly_PH29_�����m)
				res(timnotdly_PH30_�t�^���m)
				
				' tmr(not(PH29_�����m),timnotdly_PH29_�����m,3)
				' tmr(not(PH30_�t�^���m),timnotdly_PH30_�t�^���m,3)

				'---------------------------------
				inc(�����R���x�AEEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�AEEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�AEEmgStep=0
		�����R���x�AEEmg=OFF
	end select
		
end if 'if �����R���x�AEEmgStep=0 then
