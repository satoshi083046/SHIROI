'�����R���x�AD
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AD
'
'  	�ړ����x  161.667mm/1sec
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    �����R���x�ADAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�ADAutoRun=OFF
    �����R���x�AD����=ON
    �����R���x�ADOrgErr=OFF
    �����R���x�ADErr=OFF
    �����R���x�ADEmg=OFF
    �����R���x�ADstep=0
    �����R���x�ADErrStep=0
    �����R���x�ADOrgErrStep=0
    �����R���x�ADEmgStep=0

	SV40_�X�g�b�pstep=0
	MC19_�������[�^step=0
	MC20_�������[�^step=0
	MC21_�������[�^���]���t�gstep=0
	MC21_�������[�^���]�ق���step=0
	MC21_�������[�^�t�]���t�gstep=0
	MC20_�������[�^LFTUPstep=0
	
	ManualInite=1

end if
'===================================================================================================================
'�y ���_ �z
�����R���x�ADOrg=1


'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�ADEmg=ON
	�����R���x�ADEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
tmr(not(SV40_�X�g�b�p) and not(XSW45_�X�g�b�p���~�[) and not(pnlPBXSW45_�X�g�b�p���~�[),tim_notXSW45_�X�g�b�p���~�[,#20) '743,04ms
tmr(SV40_�X�g�b�p and not(XSW46_�X�g�b�p�㏸�[) and not(pnlPBXSW46_�X�g�b�p�㏸�[), tim_notXSW46_�X�g�b�p�㏸�[, #20) '417,92ms
tmr(SV41_���t�g and not(XSW48_���t�g�㏸�[) and not(pnlPBXSW48_���t�g�㏸�[), tim_notXSW48_���t�g�㏸�[,#30) '1949.25ms
tmr(not(SV41_���t�g) and not(XSW47_���t�g���~�[) and not(pnlPBXSW47_���t�g���~�[),tim_notXSW47_���t�g���~�[,#30) '1607.98ms
tmr(not(SV42_�X�g�b�p) and not(XSW49_�X�g�b�p���~�[) and not(pnlPBXSW49_�X�g�b�p���~�[), tim_notXSW49_�X�g�b�p���~�[, #20) '1542.97ms
tmr(SV42_�X�g�b�p and not(XSW50_�X�g�b�p�㏸�[) and not(pnlPBXSW50_�X�g�b�p�㏸�[), tim_notXSW50_�X�g�b�p�㏸�[,#20) '1345.63ms
tmr(not(SV43_�X�g�b�p) and not(XSW51_�X�g�b�p���~�[) and not(pnlPBXSW51_�X�g�b�p���~�[), tim_notXSW51_�X�g�b�p���~�[, #20) '1589.02ms
tmr(SV43_�X�g�b�p and not(XSW52_�X�g�b�p�㏸�[) and not(pnlPBXSW52_�X�g�b�p�㏸�[), tim_notXSW52_�X�g�b�p�㏸�[, #20) '1714.07ms
tmr(not(SV44_���t�g) and not(XSW53_���t�g���~�[) and not(pnlPBXSW53_���t�g���~�[), tim_notXSW53_���t�g���~�[, #30) '758.48ms
tmr(SV44_���t�g and not(XSW54_���t�g�㏸�[) and not(pnlPBXSW54_���t�g�㏸�[),tim_notXSW54_���t�g�㏸�[,#30) '921.86ms

'tmr(SV40_�X�g�b�p and XSW45_�X�g�b�p���~�[,tim_XSW45_�X�g�b�p���~�[, #10)
if LDF(SV40_�X�g�b�p) and XSW45_�X�g�b�p���~�[ and not(pnlPBXSW45_�X�g�b�p���~�[) then
	SET(tim_XSW45_�X�g�b�p���~�[)
end if
'tmr(not(SV40_�X�g�b�p) and XSW46_�X�g�b�p�㏸�[, tim_XSW46_�X�g�b�p�㏸�[, #10)
if LDP(SV40_�X�g�b�p) and XSW46_�X�g�b�p�㏸�[ and not(pnlPBXSW46_�X�g�b�p�㏸�[) then
	SET(tim_XSW46_�X�g�b�p�㏸�[)
end if
'tmr(SV41_���t�g and XSW47_���t�g���~�[,tim_XSW47_���t�g���~�[,#10)
if LDF(SV41_���t�g) and XSW47_���t�g���~�[ and XSW48_���t�g�㏸�[ and not(pnlPBXSW47_���t�g���~�[) then
	SET(tim_XSW47_���t�g���~�[)
end if
'tmr(not(SV41_���t�g) and XSW48_���t�g�㏸�[, tim_XSW48_���t�g�㏸�[,#10)
if LDP(SV41_���t�g) and XSW48_���t�g�㏸�[ and not(pnlPBXSW48_���t�g�㏸�[) then
	SET(tim_XSW48_���t�g�㏸�[)
end if
'tmr(SV42_�X�g�b�p and XSW49_�X�g�b�p���~�[, tim_XSW49_�X�g�b�p���~�[, #10)
if LDF(SV42_�X�g�b�p) and XSW49_�X�g�b�p���~�[ and not(pnlPBXSW49_�X�g�b�p���~�[) then
	SET(tim_XSW49_�X�g�b�p���~�[)
end if
'tmr(not(SV42_�X�g�b�p) and XSW50_�X�g�b�p�㏸�[, tim_XSW50_�X�g�b�p�㏸�[,#10)
if LDP(SV42_�X�g�b�p) and XSW50_�X�g�b�p�㏸�[ and not(pnlPBXSW50_�X�g�b�p�㏸�[) then
	SET(tim_XSW50_�X�g�b�p�㏸�[)
end if
'tmr(SV43_�X�g�b�p and XSW51_�X�g�b�p���~�[, tim_XSW51_�X�g�b�p���~�[, #10)
if LDF(SV43_�X�g�b�p) and XSW51_�X�g�b�p���~�[ and not(pnlPBXSW51_�X�g�b�p���~�[) then
	SET(tim_XSW51_�X�g�b�p���~�[)
end if
'tmr(not(SV43_�X�g�b�p) and XSW52_�X�g�b�p�㏸�[, tim_XSW52_�X�g�b�p�㏸�[, #10)
if LDP(SV43_�X�g�b�p) and XSW52_�X�g�b�p�㏸�[ and not(pnlPBXSW52_�X�g�b�p�㏸�[) then
	SET(tim_XSW52_�X�g�b�p�㏸�[)
end if
'tmr(SV44_���t�g and XSW53_���t�g���~�[, tim_XSW53_���t�g���~�[, #10)
if LDF(SV44_���t�g) and XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[) then
	SET(tim_XSW53_���t�g���~�[)
end if
'tmr(not(SV44_���t�g) and XSW54_���t�g�㏸�[,tim_XSW54_���t�g�㏸�[,#10)
if LDP(SV44_���t�g) and XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[) then
	SET(tim_XSW54_���t�g�㏸�[)
end if

'passtimXSW45_�X�g�b�p���~�[_val=#743
tms(not(SV40_�X�g�b�p),passtimXSW45_�X�g�b�p���~�[,passtimXSW45_�X�g�b�p���~�[_val) 
'passtimXSW46_�X�g�b�p�㏸�[_val=#417
tms(SV40_�X�g�b�p, passtimXSW46_�X�g�b�p�㏸�[, passtimXSW46_�X�g�b�p�㏸�[_val) 
'passtimXSW48_���t�g�㏸�[_val=#1949
tms(SV41_���t�g, passtimXSW48_���t�g�㏸�[,passtimXSW48_���t�g�㏸�[_val) 
'passtimXSW47_���t�g���~�[_val=#1607
tms(not(SV41_���t�g),passtimXSW47_���t�g���~�[,passtimXSW47_���t�g���~�[_val) 
'passtimXSW49_�X�g�b�p���~�[_val=#1542
tms(not(SV42_�X�g�b�p), passtimXSW49_�X�g�b�p���~�[, passtimXSW49_�X�g�b�p���~�[_val) 
'passtimXSW50_�X�g�b�p�㏸�[_val=#1345
tms(SV42_�X�g�b�p, passtimXSW50_�X�g�b�p�㏸�[,passtimXSW50_�X�g�b�p�㏸�[_val) 
'passtimXSW51_�X�g�b�p���~�[_val=#1589
tms(not(SV43_�X�g�b�p), passtimXSW51_�X�g�b�p���~�[, passtimXSW51_�X�g�b�p���~�[_val) 
'passtimXSW52_�X�g�b�p�㏸�[_val=#1714
tms(SV43_�X�g�b�p, passtimXSW52_�X�g�b�p�㏸�[, passtimXSW52_�X�g�b�p�㏸�[_val) 

tmr(mMC19_�������[�^ and not(pauseMC19_�������[�^) and not(EmgMC19_�������[�^),timerr_MC19_�������[�^,#120)
tmr(mMC20_�������[�^ and not(pauseMC20_�������[�^) and not(EmgMC20_�������[�^),timerr_MC20_�������[�^,#170)
tmr(mMC21_�������[�^���] and not(pauseMC21_�������[�^���]) and not(EmgMC21_�������[�^���]),timerr_MC21_�������[�^���],#170)
tmr(mMC21_�������[�^�t�] and not(pauseMC21_�������[�^�t�]) and not(EmgMC21_�������[�^�t�]),timerr_MC21_�������[�^�t�],#120)
tmr(mMC22_�������[�^���] and not(pauseMC22_�������[�^���]) and not(EmgMC22_�������[�^���]),timerr_MC22_�������[�^���],#170)
tmr(mMC22_�������[�^�t�] and not(pauseMC22_�������[�^�t�]) and not(EmgMC22_�������[�^�t�]),timerr_MC22_�������[�^�t�],#120)

tmr(MC20_�������[�^ and (PH23_�����m or PH24_�t�^���m or PH25_�����m or PH26_�t�^���m or (not(SV57_�o�L���[�����t�g) and (PH27_�����m or PH28_�t�^���m))), timerr_MC20_�������[�^dec,#50) 

if ldp(timerr_MC19_�������[�^.B) then
	almMC19_�������[�^=ON
	
	mMC19_�������[�^=OFF
	mMC20_�������[�^=OFF
	mMC21_�������[�^���]=OFF
	mMC21_�������[�^�t�]=OFF
	mMC22_�������[�^���]=OFF
	mMC22_�������[�^�t�]=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC20_�������[�^.B or timerr_MC20_�������[�^dec.B) then
	almMC20_�������[�^=ON
	
	mMC19_�������[�^=OFF
	mMC20_�������[�^=OFF
	mMC21_�������[�^���]=OFF
	mMC21_�������[�^�t�]=OFF
	mMC22_�������[�^���]=OFF
	mMC22_�������[�^�t�]=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC21_�������[�^���].B) then
	almMC21_�������[�^���]=ON
	
	mMC19_�������[�^=OFF
	mMC20_�������[�^=OFF
	mMC21_�������[�^���]=OFF
	mMC21_�������[�^�t�]=OFF
	mMC22_�������[�^���]=OFF
	mMC22_�������[�^�t�]=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC21_�������[�^�t�].B) then
	almMC21_�������[�^�t�]=ON
	
	mMC19_�������[�^=OFF
	mMC20_�������[�^=OFF
	mMC21_�������[�^���]=OFF
	mMC21_�������[�^�t�]=OFF
	mMC22_�������[�^���]=OFF
	mMC22_�������[�^�t�]=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC22_�������[�^���].B) then
	almMC22_�������[�^���]=ON
	
	mMC19_�������[�^=OFF
	mMC20_�������[�^=OFF
	mMC21_�������[�^���]=OFF
	mMC21_�������[�^�t�]=OFF
	mMC22_�������[�^���]=OFF
	mMC22_�������[�^�t�]=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC22_�������[�^�t�].B) then
	almMC22_�������[�^�t�]=ON
	
	mMC19_�������[�^=OFF
	mMC20_�������[�^=OFF
	mMC21_�������[�^���]=OFF
	mMC21_�������[�^�t�]=OFF
	mMC22_�������[�^���]=OFF
	mMC22_�������[�^�t�]=OFF
	
	�R���x�A�ꎞ��~=ON
	
end if

if (ldp(tim_XSW45_�X�g�b�p���~�[.B) or ldp(tim_notXSW45_�X�g�b�p���~�[.B)) and not(pnlPBXSW45_�X�g�b�p���~�[) then
	almXSW45_�X�g�b�p���~�[=ON
	pnlPBXSW45_�X�g�b�p���~�[=ON
	if tim_XSW45_�X�g�b�p���~�[ then
		res(tim_XSW45_�X�g�b�p���~�[)
	end if
	�����R���x�ADErrStep=1

else if (ldp(tim_XSW46_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW46_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW46_�X�g�b�p�㏸�[) then
	pauseSV40_�X�g�b�p=ON
	almXSW46_�X�g�b�p�㏸�[=ON
	pnlPBXSW46_�X�g�b�p�㏸�[=ON
	if tim_XSW46_�X�g�b�p�㏸�[ then
		res(tim_XSW46_�X�g�b�p�㏸�[)
	end if
	�����R���x�ADErrStep=1

else if �����R���x�AD���쒆 and not(�����R���x�AE���쒆) and  (ldp(tim_XSW49_�X�g�b�p���~�[.B) or ldp(tim_notXSW49_�X�g�b�p���~�[.B)) and not(pnlPBXSW49_�X�g�b�p���~�[) then
	almXSW49_�X�g�b�p���~�[=ON
	pnlPBXSW49_�X�g�b�p���~�[=ON
	if tim_XSW49_�X�g�b�p���~�[ then
		res(tim_XSW49_�X�g�b�p���~�[)
	end if
	�����R���x�ADErrStep=1

else if �����R���x�AD���쒆 and not(�����R���x�AE���쒆) and (ldp(tim_XSW50_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW50_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW50_�X�g�b�p�㏸�[) then
	pauseSV42_�X�g�b�p=ON
	almXSW50_�X�g�b�p�㏸�[=ON
	pnlPBXSW50_�X�g�b�p�㏸�[=ON
	if tim_XSW50_�X�g�b�p�㏸�[ then
		res(tim_XSW50_�X�g�b�p�㏸�[)
	end if
	�����R���x�ADErrStep=1

else if �����R���x�AD���쒆 and not(�����R���x�AE���쒆) and (ldp(tim_XSW51_�X�g�b�p���~�[.B) or ldp(tim_notXSW51_�X�g�b�p���~�[.B)) and not(pnlPBXSW51_�X�g�b�p���~�[) then
	almXSW51_�X�g�b�p���~�[=ON
	pnlPBXSW51_�X�g�b�p���~�[=ON
	if tim_XSW51_�X�g�b�p���~�[ then
		res(tim_XSW51_�X�g�b�p���~�[)
	end if
	�����R���x�ADErrStep=1

else if �����R���x�AD���쒆 and not(�����R���x�AE���쒆) and (ldp(tim_XSW52_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW52_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW52_�X�g�b�p�㏸�[) then
	pauseSV43_�X�g�b�p=ON
	almXSW52_�X�g�b�p�㏸�[=ON
	pnlPBXSW52_�X�g�b�p�㏸�[=ON
	if tim_XSW52_�X�g�b�p�㏸�[ then
		res(tim_XSW52_�X�g�b�p�㏸�[)
	end if
	�����R���x�ADErrStep=1

else if �����R���x�AD���쒆 and not(�����R���x�AE���쒆) and (ldp(tim_XSW53_���t�g���~�[.B) or ldp(tim_notXSW53_���t�g���~�[.B)) and not(pnlPBXSW53_���t�g���~�[) then
	almXSW53_���t�g���~�[=ON
	pnlPBXSW53_���t�g���~�[=ON
	if tim_XSW53_���t�g���~�[ then
		res(tim_XSW53_���t�g���~�[)
	end if
	�����R���x�ADErrStep=1

else if �����R���x�AD���쒆 and not(�����R���x�AE���쒆) and (ldp(tim_XSW54_���t�g�㏸�[.B) or ldp(tim_notXSW54_���t�g�㏸�[.B)) and not(pnlPBXSW54_���t�g�㏸�[) then
	pauseSV44_���t�g=ON
	almXSW54_���t�g�㏸�[=ON
	pnlPBXSW54_���t�g�㏸�[=ON
	if tim_XSW54_���t�g�㏸�[ then
		res(tim_XSW54_���t�g�㏸�[)
	end if
	�����R���x�ADErrStep=1

else if (ldp(tim_XSW48_���t�g�㏸�[.B) or ldp(tim_notXSW48_���t�g�㏸�[.B)) and not(pnlPBXSW48_���t�g�㏸�[) then
	pauseSV41_���t�g=ON
	almXSW48_���t�g�㏸�[=ON
	pnlPBXSW48_���t�g�㏸�[=ON
	if tim_XSW48_���t�g�㏸�[ then
		res(tim_XSW48_���t�g�㏸�[)
	end if
	�����R���x�ADErrStep=1

else if (ldp(tim_XSW47_���t�g���~�[.B) or ldp(tim_notXSW47_���t�g���~�[.B)) and not(pnlPBXSW47_���t�g���~�[) then
	almXSW47_���t�g���~�[=ON
	pnlPBXSW47_���t�g���~�[=ON
	if tim_XSW47_���t�g���~�[ then
		res(tim_XSW47_���t�g���~�[)
	end if
	�����R���x�ADErrStep=1

end if

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�ADAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�ADAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�ADEmg	���̏��~

if �����R���x�ADEmgStep=0 then  
	
	if �����R���x�ADErrStep=0  then

	if not(�R���x�A�ꎞ��~) then
	
	if not(�����R���x�ADOrgErr) then

	if (�����R���x�ADAutoMode and ��������AutoMode ) or �����R���x�ADstep<>0 then
				
		if not(�����R���x�ADAutoMode and ��������AutoMode ) then
			�����R���x�ADAutoRun=OFF
		end if
		
		if not(�����R���x�ADAutoRun) then
			mSV41_���t�g=OFF		
		end if
		
		if ManualInite then
			if PH24_�t�^���m and PH23_�����m then
				mSV40_�X�g�b�p=ON		
			end if
			ManualInite=0
		end if
	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�ADstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�ADAutoRun then
				inc(�����R���x�ADstep)
			else 
				�����R���x�ADstep=0 '�I���ҋ@
			end if
		
		case 2
			if PH29_�����m or PH30_�t�^���m then '���t�^�[�Ɋ��t�^���������ꍇ�����I�ɔr�o����
				�����R���x�AD�r�o�v��=ON
				�����R���x�ADstep=1
			else
				inc(�����R���x�ADstep)
			end if
		
		case 3
		' [ ���̔����R���x�A��~�m�F ]
			if �����R���x�AD�r�o�v��=OFF and  �����R���x�AE���쒆=OFF and not(ejectMC19_�������[�^) then
				inc(�����R���x�ADstep)
			else
				�����R���x�ADstep=1
			end if
		
		case 4
			if 	�t�^���r�o�v�� and ���͂񌟒m�r�o�v�� and �������o�L���[���r�o�v�� then
				inc(�����R���x�ADstep)
			else
				�����R���x�ADstep=1
			end if

		
		case 5  '���_���o
			if �����R���x�ADOrg then
				errpass�R���x�A�ꎞ��~=OFF
				inc(�����R���x�ADstep)
			else
				�����R���x�ADstep=1
			end if

		case 6
			�����R���x�ADstep=100			
		'--------------------------------------------------------------------------------------------------------------
		case 100
		'------ �ق���A�Ɋ��������Ă���Ƃ��A�o�L���[���ʒu�Ɋ������B�����ꍇ�ɂ́A�ق���B�ɔ�������B
		'------ �ق���B�ɔ����������Ƃ��L�^���āA�ق���A��r�o����B
			if �R���x�AD���r�o�ҋ@ then
				if �ق����@A�r�o�v�� then
					if �ق����@A���j�b�g���� then
						'���ق���A���r�o (�ق����@�[>���t�g�܂łق������r�o)
						�����R���x�ADstep=200
					end if
				else
					�����R���x�ADstep=1
				end if
			else
		
				if PH27_�����m and PH28_�t�^���m then '������ (�o�L���[���ʒu�������o)

					if ���]�ق�����������A then
						if not(ejectMC19_�������[�^) then '�ނ炵�@�r�o��~��
						'���ق���B������ (���t�g�܂Ŋ�����)
							�ق���A���v��=OFF
							�����R���x�ADstep=300
						end if
					else
						if not(ejectMC19_�������[�^) then '�ނ炵�@�r�o��~��
						'���ق���A������ (�ق����@�܂Ŋ�����)
							�ق���A���v��=ON
							�����R���x�ADstep=300
						end if
					end if
				else if PH28_�t�^���m then '�t�^����
						if not(ejectMC19_�������[�^) then '�ނ炵�@�r�o��~��
							'�����t�g�܂Ŋ��t�^����
							�ق���A���v��=OFF
							�����R���x�ADstep=300
						end if
				
				else
						if not(ejectMC19_�������[�^) then '�ނ炵�@�r�o��~��
							�����R���x�ADstep=400			
						end if
				end if

			end if
				
		'----------------------------------------------------------------------------------------------------------------
		case 200'���ق����@�[>���t�g�܂łق���A���r�o
				if (���]�@���]�����M��_A or �������\�M��_A or ���]�ق����@A�֎~)  then
					inc(�����R���x�ADstep)
				end if
				
		case 201
				if PH31_�����m then '���]�ق���A
					MC21_�������[�^�t�]���t�gstep=1
					StageDevice22=$0000
				end if

				inc(�����R���x�ADstep)
		
		case 202
				if MC21_�������[�^�t�]���t�gstep=0 then
					inc(�����R���x�ADstep)
				end if			

		case 203
				
				�R���x�AD���r�o�ҋ@=OFF
				�ق����@A�r�o�v��=OFF
				�ق����@A���j�b�g����=OFF
				���]�ق�����������A=OFF
				�����R���x�AD���쒆=OFF
				�����R���x�AD�r�o�v��=ON
				�����R���x�ADstep=1
				
		'----------------------------------------------------------------------------------------------------------------
		case 300'�����t�g�A�ق���A�܂Ŋ��t�^����
				
			if �ق���A���v�� and not(�ق���A�����֎~) then			
				MC21_�������[�^���]�ق���step=1
			else
				��������=PH27_�����m
				MC21_�������[�^���]���t�gstep=1
			end if
			inc(�����R���x�ADstep)
		
		case 301
			if MC21_�������[�^���]�ق���step=0 and MC21_�������[�^���]���t�gstep=0 then 
				inc(�����R���x�ADstep)
			end if
		
		case 302
			
			if �ق���A���v��  and not(�ق���A�����֎~) then
				���]�ق�����������A=ON
				�ق���A���v��=OFF
				�����R���x�ADstep=1
				
			else
				if �������� and ���]�ق�����������A  and not(�ق���A�����֎~) then
					��������=OFF
					�R���x�AD���r�o�ҋ@=ON
				else
					�R���x�AD���r�o�ҋ@=OFF
				end if
				inc(�����R���x�ADstep)
			end if

		case 303
				�����R���x�AD�r�o�v��=ON
				
				�����R���x�AD���쒆=OFF
				�����R���x�ADstep=1
		
		'----------------------------------------------------------------------------------------------------------------
		case 400 '����ʒu�i�o�L���[���ʒu�j�Ƀ��[�N���Ȃ��ꍇ
				MC20_�������[�^step=1
				inc(�����R���x�ADstep)
		
		case 401
				if MC20_�������[�^step=0 and MC20_�������[�^LFTUPstep=0 then
					inc(�����R���x�ADstep)
				end if
		
		case 402
				�����R���x�ADstep=1
		
		end select

	'-----------------------------------------------------------------	
	'mMC19_�������[�^		
	'	�ނ炵�o��:	PH21_�ނ炵�@�o���Z���T	
	'	�G�X�P�[�v:	PH22_�����m
	
	'mMC20_�������[�^
	'	�t�^��葕�u:PH23_�����m PH24_�t�^���m 
	'	���͂񌟒m:		PH25_�����m PH26_�t�^���m 
	'	�����o�L���[��:	PH27_�����m PH28_�t�^���m   
	
	'mMC21_�������[�^���]
	'mMC21_�������[�^�t�]
	'mMC23_���[�^���[��
	'	�󂯓n�����[��:	PH29_�����m PH30_�t�^���m 
	
	'mMC22_�������[�^���]
	'mMC22_�������[�^�t�]
	'	���]�ق���A:	PH31_�����m
	
	'-----------------------------------------------------------------	
	'mSV40_�X�g�b�p
	'mSV41_���t�g
	'mSV42_�X�g�b�p
	'mSV43_�X�g�b�p
	'mSV44_���t�g
	'-----------------------------------------------------------------
	' �N�����̊�����
	'�ނ炵�o��
	'PH21_���N�����m=PH21_�ނ炵�@�o���Z���T 
	
	'�G�X�P�[�v
	'PH22_���N�����m=PH22_�����m 	
	
	'�t�^��葕�u
	'PH23_���N�����m=PH23_�����m 				
	'PH24_�t�^�N�����m=PH24_�t�^���m
	
	'���͂񌟒m
	'PH25_���N�����m=PH25_�����m 				
	'PH26_�t�^�N�����m=PH26_�t�^���m
	
	'�����o�L���[��
	'PH27_���N�����m=PH27_�����m 				 
	'PH28_�t�^�N�����m=PH28_�t�^���m
	
	'�󂯓n�����[��
	'PH29_���N�����m=PH29_�����m 				
	'PH30_�t�^�N�����m=PH30_�t�^���m
	
	'���]�ق���A
	'PH31_���N�����m=PH31_�����m 				

	'-----------------------------------------------------------------
	' �������[�^�A�X�g�b�pON/OFF�^�C�~���O�^�X�N
	'-----------------------------------------------------------------
	tmr(tim_SV40_�X�g�b�p,tim_SV40_�X�g�b�p_val) '�t�^��葕�u�X�g�b�p
	select case SV40_�X�g�b�pstep
	case 0
	
	case 1
		if (not(PH22_�������֎~) and PH22_�����m) or PH23_�����m or PH24_�t�^���m then
			mSV40_�X�g�b�p=OFF
			inc(SV40_�X�g�b�pstep)
		else
			SV40_�X�g�b�pstep=0 '�I��
		end if
		
	case 2
		if (XSW45_�X�g�b�p���~�[ and not(pnlPBXSW45_�X�g�b�p���~�[)) or passXSW45_�X�g�b�p���~�[ then
			inc(SV40_�X�g�b�pstep)
		end if

	case 3
		if errpass�R���x�A�ꎞ��~ then
			inc(SV40_�X�g�b�pstep)
		
		else if not(PH23_�����m) and not(PH24_�t�^���m) then
			tim_SV40_�X�g�b�p_val=20
			res(tim_SV40_�X�g�b�p)
			inc(SV40_�X�g�b�pstep)
		end if

	case 4
		if errpass�R���x�A�ꎞ��~ then
			inc(SV40_�X�g�b�pstep)
			
		else if not(PH22_�������֎~) and PH22_���N�����m then
			if tim_SV40_�X�g�b�p.B or PH23_�����m or PH24_�t�^���m then
				inc(SV40_�X�g�b�pstep)
			end if
		else
			inc(SV40_�X�g�b�pstep)	
		end if
	
	case 5
		if errpass�R���x�A�ꎞ��~ then
			inc(SV40_�X�g�b�pstep)
			
		else if PH23_���N�����m or PH24_�t�^�N�����m then
			if PH25_�����m or PH26_�t�^���m then
				inc(SV40_�X�g�b�pstep)
			end if
		else
			inc(SV40_�X�g�b�pstep)
		end if		
	
	case 6
		if not(PH22_�������֎~) and PH22_���N�����m then
			mSV40_�X�g�b�p=ON
		else
			mSV40_�X�g�b�p=OFF
		end if		
		inc(SV40_�X�g�b�pstep)
	
	case 7
		if mSV40_�X�g�b�p then
			if (XSW46_�X�g�b�p�㏸�[ and not(pnlPBXSW46_�X�g�b�p�㏸�[)) or passXSW46_�X�g�b�p�㏸�[ then
				inc(SV40_�X�g�b�pstep)
			end if
		else
			inc(SV40_�X�g�b�pstep)
		end if	
	
	case 8
		SV40_�X�g�b�pstep=0
	
	end select
	'-----------------------------------------------------------------
	'MC19_�������[�^
	tmr(tim_MC19_�������[�^,tim_MC19_�������[�^_val)
	
	select case MC19_�������[�^step
	case 0
	case 1
		if PH22_�������֎~ then
			MC19_�������[�^step=0
		else						
			'�G�X�P�[�v
			PH22_���N�����m=PH22_�����m 	
			inc(MC19_�������[�^step)
		end if
		
	case 2
		if PH22_�����m and not(�t�^���t�^��蒆) then
			inc(MC19_�������[�^step)
		else
			MC19_�������[�^step=0
		end if
	
	case 3
		if not(ejectMC19_�������[�^) then
			inc(MC19_�������[�^step)
		end if		
	
	case 4	
		if not(PH22_�������֎~) and mSV41_���t�g then
			mSV41_���t�g=OFF
			inc(MC19_�������[�^step)
		else
			inc(MC19_�������[�^step)
		end if
		
	case 5
		if not(mSV41_���t�g) then
			if (XSW47_���t�g���~�[ and not(pnlPBXSW47_���t�g���~�[)) or passXSW47_���t�g���~�[ then
				inc(MC19_�������[�^step)
			end if
		else
			inc(MC19_�������[�^step)		
		end if
	
	case 6
		mMC19_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC19_�������[�^step)

	case 7
		if errpass�R���x�A�ꎞ��~ then
			inc(MC19_�������[�^step)		
		
		else if not(PH22_�����m) and not(PH23_�����m) and not(PH24_�t�^���m) then
			inc(MC19_�������[�^step)		
		end if
	
	case 8
		if errpass�R���x�A�ꎞ��~ then
				inc(MC19_�������[�^step)
		
		else if PH22_���N�����m then
			if PH23_�����m or PH24_�t�^���m then
				inc(MC19_�������[�^step)
			end if
		end if
	
	case 9
		tim_MC19_�������[�^_val=10
		res(tim_MC19_�������[�^)
		inc(MC19_�������[�^step)

	case 10
		if tim_MC19_�������[�^.B then
			inc(MC19_�������[�^step)
		end if
	
	case 11
		mMC19_�������[�^=OFF
		inc(MC19_�������[�^step)
	
	case 12
		MC19_�������[�^step=0
	
	end select
	
	'-----------------------------------------------------------------
	'MC20_�������[�^���]
	tmr(tim_MC20_�������[�^,tim_MC20_�������[�^_val)
	
	select case MC20_�������[�^step
	case 0
	case 1
		'�G�X�P�[�v
		PH22_�������֎~=�G�X�P�[�v��
		PH22_���N�����m=PH22_�����m 	
		
		'�t�^��葕�u
		PH23_���N�����m=PH23_�����m 				
		PH24_�t�^�N�����m=PH24_�t�^���m
		
		'���͂񌟒m
		PH25_���N�����m=PH25_�����m 				
		PH26_�t�^�N�����m=PH26_�t�^���m
		
		'�����o�L���[��
		PH27_���N�����m=PH27_�����m 				 
		PH28_�t�^�N�����m=PH28_�t�^���m


		inc(MC20_�������[�^step)
	
	case 2
		if (not(PH22_�������֎~) and PH22_�����m) or PH23_�����m or PH24_�t�^���m or PH25_�����m or PH26_�t�^���m or PH27_�����m or PH28_�t�^���m then
			inc(MC20_�������[�^step)
		else
			MC20_�������[�^step=0
		end if
	
	case 3
		if not(PH22_�������֎~) and PH22_�����m then '�G�X�P�[�v
			StageDevice17=$8000
		else
			StageDevice17=0
		end if

		if PH23_�����m then '�t�^���
			StageDevice18=$8000
		else
			StageDevice18=0
		end if
		
		if PH25_�����m then '���͂񌟒m

			if ���͂񌟒m then
				StageDevice190=ORA(StageDevice190,$1000)
				StageDevice19=ORA(StageDevice19,$1000)
			end if
			StageDevice19=ORA(StageDevice19,$8000)
			StageDevice190=ORA(StageDevice190,$8000)
		
		else
			StageDevice19=0
			StageDevice190=0
		end if				
	
		if PH27_�����m then '�o�L���[��
			StageDevice200=ORA(StageDevice200,$8000)
			StageDevice20=ORA(StageDevice20,$8000)
		else
			StageDevice200=0
			StageDevice20=0
		end if
	
	
	
		SV40_�X�g�b�pstep=1
		inc(MC20_�������[�^step)
	
	case 4
		if SV40_�X�g�b�pstep=0 or (not(mSV40_�X�g�b�p) and ((XSW45_�X�g�b�p���~�[ and not(pnlPBXSW45_�X�g�b�p���~�[)) or passXSW45_�X�g�b�p���~�[)) then
			inc(MC20_�������[�^step)
		end if	
	
	case 5
		�����R���x�AD���쒆=ON
		MC19_�������[�^step=1
		inc(MC20_�������[�^step)
		
	case 6
		if  MC19_�������[�^step=0 or mMC19_�������[�^ then
			inc(MC20_�������[�^step)
		end if	
		
	case 7
		mMC20_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC20_�������[�^step)
	
	case 8
		if PH22_�������֎~ or �t�^���t�^��蒆 or not(PH22_�����m) then
			inc(MC20_�������[�^step)
		end if
	
	case 9
		if errpass�R���x�A�ꎞ��~ then
			inc(MC20_�������[�^step)
		else if not(PH23_�����m) and not(PH24_�t�^���m) then
				if not(PH25_�����m) and not(PH26_�t�^���m) then
					if not(PH27_�����m) and not(PH28_�t�^���m) then
						inc(MC20_�������[�^step)
					end if
				end if
		end if
	
	case 10
		if errpass�R���x�A�ꎞ��~ then
				inc(MC20_�������[�^step)		
		
		else if not(PH22_�������֎~) and PH22_���N�����m and not(�t�^���t�^��蒆) then
			if PH23_�����m or PH24_�t�^���m then
				tim_MC20_�������[�^_val=MC20�u���[�L�^�C�~���O 'L=8 R=9
				res(tim_MC20_�������[�^)
				inc(MC20_�������[�^step)
			end if

		else if PH23_���N�����m or PH24_�t�^�N�����m then
			if PH25_�����m or PH26_�t�^���m then
				tim_MC20_�������[�^_val=8
				res(tim_MC20_�������[�^)
				inc(MC20_�������[�^step)
			end if
		
		else if PH25_���N�����m or PH26_�t�^�N�����m then
			if PH27_�����m or PH28_�t�^���m then
				tim_MC20_�������[�^_val=8
				res(tim_MC20_�������[�^)
				inc(MC20_�������[�^step)
			end if
		else if PH27_���N�����m or PH28_�t�^�N�����m then
			if PH29_�����m or PH30_�t�^���m then
				tim_MC20_�������[�^_val=8
				res(tim_MC20_�������[�^)
				inc(MC20_�������[�^step)
			end if
		else
			tim_MC20_�������[�^_val=8
			res(tim_MC20_�������[�^)
			inc(MC20_�������[�^step)
		end if
	
	case 11
		if tim_MC20_�������[�^.B then
			inc(MC20_�������[�^step)
		end if
	
	case 12
		mMC20_�������[�^=OFF
		if MC21_�������[�^���]�ق���step=0 and MC21_�������[�^�t�]���t�gstep=0 and MC21_�������[�^���]���t�gstep=0 then
			StageDevice20=StageDevice19
			StageDevice19=StageDevice18
			StageDevice18=StageDevice17
		end if		
		StageDevice200=StageDevice190
		inc(MC20_�������[�^step)
		
	case 13
		if MC19_�������[�^step=0 then
			inc(MC20_�������[�^step)
		end if
	
	case 14
		tim_MC20_�������[�^_val=9
		res(tim_MC20_�������[�^)
		inc(MC20_�������[�^step)

	case 15
		if tim_MC20_�������[�^.B then
			inc(MC20_�������[�^step)
		end if
	
	case 16
		if SV40_�X�g�b�pstep=0 then
			inc(MC20_�������[�^step)
		end if

	case 17

		���͂񌟒m=OFF

		�t�^��芮��=OFF
		���͂񌟒m����=OFF
		�o�L���[������=OFF
		
		�t�^���r�o�v��=OFF
		���͂񌟒m�r�o�v��=OFF
		�������o�L���[���r�o�v��=OFF

		�����R���x�AD���쒆=OFF

		MC20_�������[�^step=0

	end select
	
	'-----------------------------------------------------------------
	'MC21_�������[�^���]���t�g
	tmr(tim_MC21_�������[�^���]���t�g,tim_MC21_�������[�^���]���t�g_val)
	
	select case MC21_�������[�^���]���t�gstep
	case 0
	case 1
		'�����o�L���[��
		PH22_�������֎~=�G�X�P�[�v��
		PH27_���N�����m=PH27_�����m 				 
		PH28_�t�^�N�����m=PH28_�t�^���m
		inc(MC21_�������[�^���]���t�gstep)
	
	case 2
		if PH27_�����m or PH28_�t�^���m then
			inc(MC21_�������[�^���]���t�gstep)
		else
			MC20_�������[�^step=1
			MC21_�������[�^���]���t�gstep=0
		end if
	
	'------------------------
	case 3
		if not(PH22_�������֎~) and PH22_�����m then '�G�X�P�[�v
			StageDevice17=$8000
		else
			StageDevice17=0
		end if

		if PH23_�����m then '�t�^���
			StageDevice18=$8000
		else
			StageDevice18=0
		end if
		
		if PH25_�����m then '���͂񌟒m

			if ���͂񌟒m then
				StageDevice19=ORA(StageDevice19,$1000)
			end if
			StageDevice19=ORA(StageDevice19,$8000)
		
		else
			StageDevice19=0
		end if				
	
		if PH27_�����m then '�o�L���[��
			StageDevice20=ORA(StageDevice20,$8000)
		else
			StageDevice20=0
		end if

		mSV42_�X�g�b�p=OFF
		mSV43_�X�g�b�p=ON
		mSV44_���t�g=OFF

		MC20_�������[�^step=1
		mMC21_�������[�^���]=ON
		errpass�R���x�A�ꎞ��~=OFF

		inc(MC21_�������[�^���]���t�gstep)

	case 4
		if (XSW49_�X�g�b�p���~�[ and not(pnlPBXSW49_�X�g�b�p���~�[)) or passXSW49_�X�g�b�p���~�[ then
			if (XSW52_�X�g�b�p�㏸�[ and not(pnlPBXSW52_�X�g�b�p�㏸�[)) or passXSW52_�X�g�b�p�㏸�[ then
				if (XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[)) or passXSW53_���t�g���~�[ then
					inc(MC21_�������[�^���]���t�gstep)
				end if
			end if
		end if

		inc(MC21_�������[�^���]���t�gstep)
	'------------------------
	case 5
		inc(MC21_�������[�^���]���t�gstep)

	case 6
		if errpass�R���x�A�ꎞ��~ then
			inc(MC21_�������[�^���]���t�gstep)
		
		else if not(PH27_�����m) and not(PH28_�t�^���m) then
			inc(MC21_�������[�^���]���t�gstep)
		end if		

	case 7
		if errpass�R���x�A�ꎞ��~ then
				inc(MC21_�������[�^���]���t�gstep)
		
		else if	PH27_���N�����m or PH28_�t�^�N�����m then
			if PH29_�����m or PH30_�t�^���m then
				inc(MC21_�������[�^���]���t�gstep)
			end if
		end if
	
	case 8
		tim_MC21_�������[�^���]���t�g_val=24 '�u���[�L�^�C�~���O
		res(tim_MC21_�������[�^���]���t�g)
		inc(MC21_�������[�^���]���t�gstep)
	
	case 9
		if tim_MC21_�������[�^���]���t�g.B then
			inc(MC21_�������[�^���]���t�gstep)
		end if		
	
	
	case 10
		mMC21_�������[�^���]=OFF
		inc(MC21_�������[�^���]���t�gstep)	
	
	case 11
		tim_MC21_�������[�^���]���t�g_val=0
		res(tim_MC21_�������[�^���]���t�g)
		inc(MC21_�������[�^���]���t�gstep)
	
	case 12
		if tim_MC21_�������[�^���]���t�g.B then
			inc(MC21_�������[�^���]���t�gstep)
		end if		
	'------------------------
	case 13
		mSV43_�X�g�b�p=ON
		mSV44_���t�g=OFF
		inc(MC21_�������[�^���]���t�gstep)

	case 14
		if (XSW52_�X�g�b�p�㏸�[ and not(pnlPBXSW52_�X�g�b�p�㏸�[)) or passXSW52_�X�g�b�p�㏸�[ then
			if (XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[)) or passXSW53_���t�g���~�[ then
				inc(MC21_�������[�^���]���t�gstep)
			end if
		end if

	case 15
		tim_MC21_�������[�^���]���t�g_val=0
		res(tim_MC21_�������[�^���]���t�g)
		inc(MC21_�������[�^���]���t�gstep)
	
	case 16
		if tim_MC21_�������[�^���]���t�g.B then
			inc(MC21_�������[�^���]���t�gstep)
		end if		
	case 17
		mSV43_�X�g�b�p=ON
		mSV44_���t�g=ON
		inc(MC21_�������[�^���]���t�gstep)

	case 18
		if (XSW52_�X�g�b�p�㏸�[ and not(pnlPBXSW52_�X�g�b�p�㏸�[)) or passXSW52_�X�g�b�p�㏸�[ then
			if (XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[)) or passXSW54_���t�g�㏸�[ then
				inc(MC21_�������[�^���]���t�gstep)
			end if
		end if

	case 19
		tim_MC21_�������[�^���]���t�g_val=0
		res(tim_MC21_�������[�^���]���t�g)
		inc(MC21_�������[�^���]���t�gstep)
	
	case 20
		if tim_MC21_�������[�^���]���t�g.B then
			inc(MC21_�������[�^���]���t�gstep)
		end if		
	
	case 21
		mSV42_�X�g�b�p=OFF
		mSV43_�X�g�b�p=OFF
		mSV44_���t�g=ON
		inc(MC21_�������[�^���]���t�gstep)

	case 22
		if not(XSW50_�X�g�b�p�㏸�[) or pnlPBXSW50_�X�g�b�p�㏸�[ then
			if not(XSW52_�X�g�b�p�㏸�[) or pnlPBXSW52_�X�g�b�p�㏸�[ then
				if (XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[)) or passXSW54_���t�g�㏸�[ then
					inc(MC21_�������[�^���]���t�gstep)
				end if
			end if
		end if

	case 23
		if MC20_�������[�^step=0 and MC20_�������[�^LFTUPstep=0 then
			inc(MC21_�������[�^���]���t�gstep)
		end if

	case 24
		StageDevice21=StageDevice20
		StageDevice20=StageDevice19
		StageDevice19=StageDevice18
		StageDevice18=StageDevice17

		MC21_�������[�^���]���t�gstep=0

	end select
	'-----------------------------------------------------------------
	'MC21_�������[�^���]�ق��� (MC22_�������[�^���]����쓮�j
	tmr(tim_MC21_�������[�^���]�ق���,tim_MC21_�������[�^���]�ق���_val)
	
	select case MC21_�������[�^���]�ق���step
	case 0
	case 1
		'�����o�L���[��
		PH22_�������֎~=�G�X�P�[�v��
		PH27_���N�����m=PH27_�����m 				 
		PH28_�t�^�N�����m=PH28_�t�^���m
		inc(MC21_�������[�^���]�ق���step)
	
	case 2
		MC20_�������[�^step=1
		if PH27_�����m or PH28_�t�^���m then
			inc(MC21_�������[�^���]�ق���step)
		else
			MC20_�������[�^step=1
			MC21_�������[�^���]�ق���step=0
		end if
	
	'------------------------
	case 3
		if not(PH22_�������֎~) and PH22_�����m then '�G�X�P�[�v
			StageDevice17=$8000
		else
			StageDevice17=0
		end if

		if PH23_�����m then '�t�^���
			StageDevice18=$8000
		else
			StageDevice18=0
		end if
		
		if PH25_�����m then '���͂񌟒m

			if ���͂񌟒m then
				StageDevice19=ORA(StageDevice19,$1000)
			end if
			StageDevice19=ORA(StageDevice19,$8000)
		
		else
			StageDevice19=0
		end if				
	
		if PH27_�����m then '�o�L���[��
			StageDevice20=ORA(StageDevice20,$8000)
		else
			StageDevice20=0
		end if

		mSV42_�X�g�b�p=OFF
		mSV43_�X�g�b�p=OFF
		mSV44_���t�g=OFF

		mMC21_�������[�^���]=ON
		mMC22_�������[�^���]=ON
		errpass�R���x�A�ꎞ��~=OFF

		inc(MC21_�������[�^���]�ق���step)

	case 4
		if (XSW49_�X�g�b�p���~�[ and not(pnlPBXSW49_�X�g�b�p���~�[)) or passXSW49_�X�g�b�p���~�[ then
			if (XSW51_�X�g�b�p���~�[ and not(pnlPBXSW51_�X�g�b�p���~�[)) or passXSW51_�X�g�b�p���~�[ then
				if (XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[)) or passXSW53_���t�g���~�[ then
					inc(MC21_�������[�^���]�ق���step)
				end if
			end if
		end if
		inc(MC21_�������[�^���]�ق���step)
	'------------------------
	case 5
		inc(MC21_�������[�^���]�ق���step)

	case 6
		if errpass�R���x�A�ꎞ��~ then
			inc(MC21_�������[�^���]�ق���step)
		
		else if not(PH27_�����m) and not(PH28_�t�^���m) then
			inc(MC21_�������[�^���]�ق���step)
		end if		

	case 7
		if errpass�R���x�A�ꎞ��~ then
			inc(MC21_�������[�^���]�ق���step)
		
		else if	PH27_���N�����m or PH28_�t�^�N�����m then
			if PH31_�����m then
				inc(MC21_�������[�^���]�ق���step)
			end if
		end if
	
	case 8
		tim_MC21_�������[�^���]�ق���_val=10 '�u���[�L�^�C�~���O
		res(tim_MC21_�������[�^���]�ق���)
		inc(MC21_�������[�^���]�ق���step)
	
	case 9
		if tim_MC21_�������[�^���]�ق���.B then
			inc(MC21_�������[�^���]�ق���step)
		end if		

	case 10
		mMC21_�������[�^���]=OFF
		mMC22_�������[�^���]=OFF

		inc(MC21_�������[�^���]�ق���step)	
	
	case 11
		if MC20_�������[�^step=0 and MC20_�������[�^LFTUPstep=0 then
			inc(MC21_�������[�^���]�ق���step)
		end if
	'------------------------
	case 12
		StageDevice22=StageDevice20
		StageDevice20=StageDevice19
		StageDevice19=StageDevice18
		StageDevice18=StageDevice17
		StageDevice21=0

		MC21_�������[�^���]�ق���step=0

	end select

	'-----------------------------------------------------------------
	'MC21_�������[�^�t�]���t�g
	
	'-----------------------------------------------------------------

	tmr(tim_MC21_�������[�^�t�]���t�g,tim_MC21_�������[�^�t�]���t�g_val)
	
	select case MC21_�������[�^�t�]���t�gstep
	case 0
	case 1
		'���]�ق���A
		PH31_���N�����m=PH31_�����m 				
		inc(MC21_�������[�^�t�]���t�gstep)
	
	case 2
		if PH31_�����m then
			inc(MC21_�������[�^�t�]���t�gstep)
		else
			MC21_�������[�^�t�]���t�gstep=0
		end if
	
	'------------------------
	case 3
		mSV42_�X�g�b�p=ON
		mSV43_�X�g�b�p=OFF
		mSV44_���t�g=OFF

		mMC21_�������[�^�t�]=ON
		mMC22_�������[�^�t�]=ON
		errpass�R���x�A�ꎞ��~=OFF

		inc(MC21_�������[�^�t�]���t�gstep)

	case 4
		if (XSW50_�X�g�b�p�㏸�[ and not(pnlPBXSW50_�X�g�b�p�㏸�[)) or passXSW50_�X�g�b�p�㏸�[ then
			if (XSW51_�X�g�b�p���~�[ and not(pnlPBXSW51_�X�g�b�p���~�[)) or passXSW51_�X�g�b�p���~�[ then
				if (XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[)) or passXSW53_���t�g���~�[ then
					inc(MC21_�������[�^�t�]���t�gstep)
				end if
			end if
		end if
		inc(MC21_�������[�^�t�]���t�gstep)
	'------------------------
	case 5
		inc(MC21_�������[�^�t�]���t�gstep)

	case 6

		'-------------------------------------------------------------------------
		MC20_�������[�^LFTUPstep=1 '���d�^�]
		'-------------------------------------------------------------------------

		if errpass�R���x�A�ꎞ��~ then
			inc(MC21_�������[�^�t�]���t�gstep)
		
		else if not(PH31_�����m) then
			inc(MC21_�������[�^�t�]���t�gstep)
		end if		

	case 7
		if errpass�R���x�A�ꎞ��~ then
			inc(MC21_�������[�^�t�]���t�gstep)
		
		else if	PH31_���N�����m then
			if PH29_�����m and PH30_�t�^���m then
				inc(MC21_�������[�^�t�]���t�gstep)
			end if
		end if

	case 8
		tim_MC21_�������[�^�t�]���t�g_val=24
		res(tim_MC21_�������[�^�t�]���t�g)
		inc(MC21_�������[�^�t�]���t�gstep)
	
	case 9
		if tim_MC21_�������[�^�t�]���t�g.B then
			inc(MC21_�������[�^�t�]���t�gstep)
		end if		
	

	case 10
		mMC21_�������[�^�t�]=OFF
		mMC22_�������[�^�t�]=OFF

		inc(MC21_�������[�^�t�]���t�gstep)	
	
	case 11
		tim_MC21_�������[�^�t�]���t�g_val=0
		res(tim_MC21_�������[�^�t�]���t�g)
		inc(MC21_�������[�^�t�]���t�gstep)
	
	case 12
		if tim_MC21_�������[�^�t�]���t�g.B then
			inc(MC21_�������[�^�t�]���t�gstep)
		end if
		
	case 13
		mSV42_�X�g�b�p=ON
		mSV44_���t�g=OFF
		inc(MC21_�������[�^�t�]���t�gstep)

	case 14
		if (XSW50_�X�g�b�p�㏸�[ and not(pnlPBXSW50_�X�g�b�p�㏸�[)) or passXSW50_�X�g�b�p�㏸�[ then
			if (XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[)) or passXSW53_���t�g���~�[ then
				inc(MC21_�������[�^�t�]���t�gstep)
			end if
		end if
		
	case 15
		mSV42_�X�g�b�p=ON
		mSV44_���t�g=ON
		inc(MC21_�������[�^�t�]���t�gstep)

	case 16
		if (XSW50_�X�g�b�p�㏸�[ and not(pnlPBXSW50_�X�g�b�p�㏸�[)) or passXSW50_�X�g�b�p�㏸�[ then
			if (XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[)) or passXSW54_���t�g�㏸�[ then
				inc(MC21_�������[�^�t�]���t�gstep)
			end if
		end if

	case 17
		tim_MC21_�������[�^�t�]���t�g_val=0
		res(tim_MC21_�������[�^�t�]���t�g)
		inc(MC21_�������[�^�t�]���t�gstep)
	
	case 18
		if tim_MC21_�������[�^�t�]���t�g.B then
			inc(MC21_�������[�^�t�]���t�gstep)
		end if		
	
	case 19
		mSV42_�X�g�b�p=OFF
		mSV43_�X�g�b�p=OFF
		mSV44_���t�g=ON
		inc(MC21_�������[�^�t�]���t�gstep)

	case 20
		if not(XSW50_�X�g�b�p�㏸�[) or pnlPBXSW50_�X�g�b�p�㏸�[ then
			if not(XSW52_�X�g�b�p�㏸�[) or pnlPBXSW52_�X�g�b�p�㏸�[ then
				if (XSW54_���t�g�㏸�[ and not(pnlPBXSW54_���t�g�㏸�[)) or passXSW54_���t�g�㏸�[ then
					inc(MC21_�������[�^�t�]���t�gstep)
				end if
			end if
		end if

	case 21
		if MC20_�������[�^step=0 and MC20_�������[�^LFTUPstep=0 then
			
			StageDevice21=0
			StageDevice22=0
			MC21_�������[�^�t�]���t�gstep=0
	
		end if
	end select
	'-----------------------------------------------------------------
	'MC20_�������[�^���]LFTUP
	tmr(tim_MC20_�������[�^LFTUP,tim_MC20_�������[�^LFTUP_val)
	
	select case MC20_�������[�^LFTUPstep
	case 0
	case 1
		'�G�X�P�[�v
		PH22_�������֎~=�G�X�P�[�v��
		PH22_���N�����m=PH22_�����m 	
		
		'�t�^��葕�u
		PH23_���N�����m=PH23_�����m 				
		PH24_�t�^�N�����m=PH24_�t�^���m
		
		'���͂񌟒m
		PH25_���N�����m=PH25_�����m 				
		PH26_�t�^�N�����m=PH26_�t�^���m
		
		'�����o�L���[��
		'PH27_���N�����m=PH27_�����m 				 
		'PH28_�t�^�N�����m=PH28_�t�^���m

		inc(MC20_�������[�^LFTUPstep)
	
	case 2
	
		if PH22_�������֎~ then
			MC20_�������[�^LFTUPstep=0
			
		else if ((PH25_�����m or PH26_�t�^���m) and (PH27_�����m or PH28_�t�^���m)) then '���͂񌟒m�ƃo�L���[�����j�b�g�ʒu
			MC20_�������[�^LFTUPstep=0
			
		else
			inc(MC20_�������[�^LFTUPstep)
		end if

	case 3
		if PH27_�����m or PH28_�t�^���m then '�o�L���[���ʒu
			mSV57_�o�L���[�����t�g=ON
		end if
		
		if mSV57_�o�L���[�����t�g then
			if (XSW72_�o�L���[�}���t�g�㏸�[ and not(pnlPBXSW72_�o�L���[�}���t�g�㏸�[)) or passXSW72_�o�L���[�}���t�g�㏸�[ then
				inc(MC20_�������[�^LFTUPstep)
			end if
		else
			inc(MC20_�������[�^LFTUPstep)
		end if

	case 4
	
		if not(PH22_�������֎~) and PH22_�����m then '�G�X�P�[�v 
			StageDevice17=$8000
		else
			StageDevice17=0
		end if

		if PH23_�����m then '�t�^���
			StageDevice18=$8000
		else
			StageDevice18=0
		end if
		
		if PH25_�����m then '���͂񌟒m

			if ���͂񌟒m then
				StageDevice190=ORA(StageDevice190,$1000)
				StageDevice19=ORA(StageDevice19,$1000)
			end if
			StageDevice19=ORA(StageDevice19,$8000)
			StageDevice190=ORA(StageDevice190,$8000)
		
		else
			StageDevice19=0
			StageDevice190=0
		end if				
	
		if PH27_�����m then '�o�L���[��
			StageDevice200=ORA(StageDevice200,$8000)
			StageDevice20=ORA(StageDevice20,$8000)
		else
			StageDevice200=0
			StageDevice20=0
		end if
	
	
	
		SV40_�X�g�b�pstep=1
		inc(MC20_�������[�^LFTUPstep)
	
	case 5
		if SV40_�X�g�b�pstep=0 or (not(mSV40_�X�g�b�p) and ((XSW45_�X�g�b�p���~�[ and not(pnlPBXSW45_�X�g�b�p���~�[)) or passXSW45_�X�g�b�p���~�[)) then
			inc(MC20_�������[�^LFTUPstep)
		end if	
	
	case 6
		�����R���x�AD���쒆=ON
		MC19_�������[�^step=1
		inc(MC20_�������[�^LFTUPstep)
		
	case 7
		if  MC19_�������[�^step=0 or mMC19_�������[�^ then
			inc(MC20_�������[�^LFTUPstep)
		end if	
		
	case 8
		mMC20_�������[�^=ON
		errpass�R���x�A�ꎞ��~=OFF
		inc(MC20_�������[�^LFTUPstep)
	
	case 9
		if PH22_�������֎~ or �t�^���t�^��蒆 or not(PH22_�����m) then
			inc(MC20_�������[�^LFTUPstep)
		end if
	
	case 10
		if errpass�R���x�A�ꎞ��~ then
			inc(MC20_�������[�^LFTUPstep)
		else if not(PH23_�����m) and not(PH24_�t�^���m) then
				if not(PH25_�����m) and not(PH26_�t�^���m) then
					inc(MC20_�������[�^LFTUPstep)
				end if
		end if
	
	case 11
		if errpass�R���x�A�ꎞ��~ then
				inc(MC20_�������[�^LFTUPstep)		
		
		else if not(PH22_�������֎~) and PH22_���N�����m and not(�t�^���t�^��蒆) then
			if PH23_�����m or PH24_�t�^���m then
				tim_MC20_�������[�^LFTUP_val=MC20�u���[�L�^�C�~���O 'L=8 R=9
				res(tim_MC20_�������[�^LFTUP)
				inc(MC20_�������[�^LFTUPstep)
			end if

		else if PH23_���N�����m or PH24_�t�^�N�����m then
			if PH25_�����m or PH26_�t�^���m then
				tim_MC20_�������[�^LFTUP_val=9
				res(tim_MC20_�������[�^LFTUP)
				inc(MC20_�������[�^LFTUPstep)
			end if
		
		else if PH25_���N�����m or PH26_�t�^�N�����m then
			if PH27_�����m or PH28_�t�^���m then
				tim_MC20_�������[�^LFTUP_val=9
				res(tim_MC20_�������[�^LFTUP)
				inc(MC20_�������[�^LFTUPstep)
			end if
		else
			tim_MC20_�������[�^LFTUP_val=8
			res(tim_MC20_�������[�^LFTUP)
			inc(MC20_�������[�^LFTUPstep)
		end if
	
	case 12
		if tim_MC20_�������[�^LFTUP.B then
			inc(MC20_�������[�^LFTUPstep)
		end if
	
	case 13
		mMC20_�������[�^=OFF
		if MC21_�������[�^���]�ق���step=0 and MC21_�������[�^�t�]���t�gstep=0 and MC21_�������[�^���]���t�gstep=0 then
			StageDevice20=StageDevice19
			StageDevice19=StageDevice18
			StageDevice18=StageDevice17
		end if		
		StageDevice200=StageDevice190
		inc(MC20_�������[�^LFTUPstep)
		
	case 14
		if MC19_�������[�^step=0 then
			inc(MC20_�������[�^LFTUPstep)
		end if
	
	case 15
		tim_MC20_�������[�^LFTUP_val=9
		res(tim_MC20_�������[�^LFTUP)
		inc(MC20_�������[�^LFTUPstep)

	case 16
		if tim_MC20_�������[�^LFTUP.B then
			inc(MC20_�������[�^LFTUPstep)
		end if
	
	case 17
		if SV40_�X�g�b�pstep=0 then
			inc(MC20_�������[�^LFTUPstep)
		end if

	case 18
		if mSV57_�o�L���[�����t�g then
			mSV57_�o�L���[�����t�g=OFF
		end if
		inc(MC20_�������[�^LFTUPstep)
	
	case 19
		if (XSW71_�o�L���[�}���t�g���~�[ and not(pnlPBXSW71_�o�L���[�}���t�g���~�[)) or passXSW71_�o�L���[�}���t�g���~�[ then
			inc(MC20_�������[�^LFTUPstep)
		end if		

	case 20

		���͂񌟒m=OFF

		�t�^��芮��=OFF
		���͂񌟒m����=OFF
		�o�L���[������=OFF
		
		�t�^���r�o�v��=OFF
		���͂񌟒m�r�o�v��=OFF
		�������o�L���[���r�o�v��=OFF

		�����R���x�AD���쒆=OFF

		MC20_�������[�^LFTUPstep=0

	end select






	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else
	
		if ManualInite=0 then
			mSV40_�X�g�b�p=OFF
			mSV42_�X�g�b�p=OFF
			mSV43_�X�g�b�p=OFF
			ManualInite=1
		end if
	
		res(timerr_MC19_�������[�^)
		res(timerr_MC20_�������[�^)
		res(timerr_MC21_�������[�^���])
		res(timerr_MC21_�������[�^�t�])
		res(timerr_MC22_�������[�^���])
		res(timerr_MC22_�������[�^�t�])

		res(timerr_MC20_�������[�^dec)

		�����R���x�ADAutoRun=OFF
		
		�����R���x�ADstep=0 '�I��
		
		if ldp(pnlPBSV41_���t�g) then
			if mSV41_���t�g then
				mSV41_���t�g=OFF '���~
			else 'if MC17_�ނ炵�@���[�^=OFF and  MC19_�������[�^=OFF then
				mSV41_���t�g=ON '�㏸
			end if
		end if
		
		if ldp(pnlPBSV40_�X�g�b�p) then
			if mSV40_�X�g�b�p then
				mSV40_�X�g�b�p=OFF
			else
				mSV40_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV42_�X�g�b�p) then
			if mSV42_�X�g�b�p then
				mSV42_�X�g�b�p=OFF
			else
				mSV42_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV43_�X�g�b�p) then
			if mSV43_�X�g�b�p then
				mSV43_�X�g�b�p=OFF
			else
				mSV43_�X�g�b�p=ON
			end if
		end if
		
		if ldp(pnlPBSV44_���t�g) then
			if mSV44_���t�g then
				mSV44_���t�g=OFF
			else
				mSV44_���t�g=ON
			end if
		end if
			
		if ldp(pnlPBMC19_�������[�^) then
			if mMC19_�������[�^ then
				mMC19_�������[�^=OFF
			else if �W��胆�j�b�gOrg then
				mMC19_�������[�^=ON
			end if
		end if
		
		if ldp(pnlPBMC20_�������[�^) then
			if mMC20_�������[�^ then
				mMC20_�������[�^=OFF
			else 
				mMC20_�������[�^=ON
			end if
		end if

		if ldp(pnlPBMC21_�������[�^���])  then
			if not(mMC21_�������[�^�t�]) then
				if mMC21_�������[�^���] then
					mMC21_�������[�^���]=OFF
				else if ((XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[)) or passXSW53_���t�g���~�[) then 
					mMC21_�������[�^���]=ON
				end if
			end if
		else if ldp(pnlPBMC21_�������[�^�t�])  then
			if not(mMC21_�������[�^���]) then
				if mMC21_�������[�^�t�] then
					mMC21_�������[�^�t�]=OFF
				else if  ((XSW53_���t�g���~�[ and not(pnlPBXSW53_���t�g���~�[)) or passXSW53_���t�g���~�[) then
					mMC21_�������[�^�t�]=ON
				end if
			end if
		end if
		
		if ldp(pnlPBMC22_�������[�^���]) then
			if not(mMC22_�������[�^�t�]) then
				if mMC22_�������[�^���] then
					mMC22_�������[�^���]=OFF
				else
					mMC22_�������[�^���]=ON
				end if
			end if
		else if ldp(pnlPBMC22_�������[�^�t�]) then
			if not(mMC22_�������[�^���]) then
				if mMC22_�������[�^�t�] then
					mMC22_�������[�^�t�]=OFF
				else
					mMC22_�������[�^�t�]=ON
				end if
			end if
		end if
				
			
	end if '�����R���x�ADAutoMode and not(�����R���x�ADOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�ADOrgErr���� �z
	else
	
		if ResetFlg then
			�����R���x�ADOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else
		res(timerr_MC19_�������[�^)
		res(timerr_MC20_�������[�^)
		res(timerr_MC21_�������[�^���])
		res(timerr_MC21_�������[�^�t�])
		res(timerr_MC22_�������[�^���])
		res(timerr_MC22_�������[�^�t�])
		
		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON			

		
		if ResetFlg then
			almMC19_�������[�^=OFF
			almMC20_�������[�^=OFF
			almMC21_�������[�^���]=OFF
			almMC21_�������[�^�t�]=OFF
			almMC22_�������[�^���]=OFF
			almMC22_�������[�^�t�]=OFF
			

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
		
		�����R���x�ADErr=ON

		pauseMC19_�������[�^=ON
		pauseMC20_�������[�^=ON
		pauseMC21_�������[�^�t�]=ON
		pauseMC22_�������[�^�t�]=ON
		

		select case �����R���x�ADErrStep
		case 0
		case 1
			alm�a�،x��=ON			
		
			if ResetFlg then
				almXSW45_�X�g�b�p���~�[=OFF
				almXSW46_�X�g�b�p�㏸�[=OFF
				almXSW49_�X�g�b�p���~�[=OFF
				almXSW50_�X�g�b�p�㏸�[=OFF
				almXSW51_�X�g�b�p���~�[=OFF
				almXSW52_�X�g�b�p�㏸�[=OFF
				almXSW53_���t�g���~�[=OFF
				almXSW54_���t�g�㏸�[=OFF
				almXSW48_���t�g�㏸�[=OFF
				almXSW47_���t�g���~�[=OFF

				alm�a�،x��=OFF

				inc(�����R���x�ADErrStep)
			end if
		case 2

			res(tim_XSW48_���t�g�㏸�[.B)
			res(tim_XSW47_���t�g���~�[.B)
			res(tim_XSW45_�X�g�b�p���~�[.B)
			res(tim_XSW46_�X�g�b�p�㏸�[.B)
			res(tim_XSW49_�X�g�b�p���~�[.B)
			res(tim_XSW50_�X�g�b�p�㏸�[.B)
			res(tim_XSW51_�X�g�b�p���~�[.B)
			res(tim_XSW52_�X�g�b�p�㏸�[.B)
			res(tim_XSW53_���t�g���~�[.B)
			res(tim_XSW54_���t�g�㏸�[.B)

			res(tim_notXSW48_���t�g�㏸�[.B)
			res(tim_notXSW47_���t�g���~�[.B)
			res(tim_notXSW45_�X�g�b�p���~�[.B)
			res(tim_notXSW46_�X�g�b�p�㏸�[.B)
			res(tim_notXSW49_�X�g�b�p���~�[.B)
			res(tim_notXSW50_�X�g�b�p�㏸�[.B)
			res(tim_notXSW51_�X�g�b�p���~�[.B)
			res(tim_notXSW52_�X�g�b�p�㏸�[.B)
			res(tim_notXSW53_���t�g���~�[.B)
			res(tim_notXSW54_���t�g�㏸�[.B)

			pauseMC19_�������[�^=OFF
			pauseMC20_�������[�^=OFF
			pauseMC21_�������[�^�t�]=OFF
			pauseMC22_�������[�^�t�]=OFF
			
			pauseSV40_�X�g�b�p=OFF
			pauseSV42_�X�g�b�p=OFF
			pauseSV43_�X�g�b�p=OFF
			pauseSV44_���t�g=OFF
			pauseSV41_���t�g=OFF

			�����R���x�ADErr=OFF
			�����R���x�ADErrStep=0
		end select

	end if 'if �����R���x�ADErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case �����R���x�ADEmgStep
	case 0
	
	case 1
		�����R���x�ADAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�ADAutoMode and ��������AutoMode ) or �����R���x�ADstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgMC19_�������[�^=ON
			EmgMC20_�������[�^=ON
			EmgMC21_�������[�^���]=ON
			EmgMC21_�������[�^�t�]=ON
			EmgMC22_�������[�^���]=ON
			EmgMC22_�������[�^�t�]=ON

			if timstack=OFF then
			
				tim_procstep_stack.U=tim_procstep.U
				tim_SV40_�X�g�b�p_stack.U=tim_SV40_�X�g�b�p.U
				tim_MC19_�������[�^_stack.U=tim_MC19_�������[�^.U
				tim_MC20_�������[�^_stack.U=tim_MC20_�������[�^.U
				tim_MC21_�������[�^���]���t�g_stack.U=tim_MC21_�������[�^���]���t�g.U
				tim_MC21_�������[�^���]�ق���_stack.U=tim_MC21_�������[�^���]�ق���.U
				tim_MC21_�������[�^�t�]���t�g_stack.U=tim_MC21_�������[�^�t�]���t�g.U
				tim_MC20_�������[�^LFTUP_stack.U=tim_MC20_�������[�^LFTUP.U
				
			' tmr(tim_procstep,tim_procstep_val)
			' tmr(tim_SV40_�X�g�b�p,tim_SV40_�X�g�b�p_val) '�t�^��葕�u�X�g�b�p
			' tmr(tim_MC19_�������[�^,tim_MC19_�������[�^_val)
			' tmr(tim_MC20_�������[�^,tim_MC20_�������[�^_val)
			' tmr(tim_MC21_�������[�^���]���t�g,tim_MC21_�������[�^���]���t�g_val)
			' tmr(tim_MC21_�������[�^���]�ق���,tim_MC21_�������[�^���]�ق���_val)
			' tmr(tim_MC21_�������[�^�t�]���t�g,tim_MC21_�������[�^�t�]���t�g_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC19_�������[�^=OFF
			mMC20_�������[�^=OFF
			mMC21_�������[�^���]=OFF
			mMC21_�������[�^�t�]=OFF
			mMC22_�������[�^���]=OFF
			mMC22_�������[�^�t�]=OFF
			mSV41_���t�g=OFF
			mSV40_�X�g�b�p=OFF
			mSV42_�X�g�b�p=OFF
			mSV43_�X�g�b�p=OFF
			mSV44_���t�g=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�ADEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�ADEmgStep)
		end if
	case 3
		if (�����R���x�ADAutoMode and ��������AutoMode ) or �����R���x�ADstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				EmgMC19_�������[�^=OFF
				EmgMC20_�������[�^=OFF
				EmgMC21_�������[�^���]=OFF
				EmgMC21_�������[�^�t�]=OFF
				EmgMC22_�������[�^���]=OFF
				EmgMC22_�������[�^�t�]=OFF

				'�X�^�b�N�̒l���^�C�}�[���ݒl�Ƀ��X�g�A
				tim_procstep.U=tim_procstep_stack.U
				tim_SV40_�X�g�b�p.U=tim_SV40_�X�g�b�p_stack.U
				tim_MC19_�������[�^.U=tim_MC19_�������[�^_stack.U
				tim_MC20_�������[�^.U=tim_MC20_�������[�^_stack.U
				tim_MC21_�������[�^���]���t�g.U=tim_MC21_�������[�^���]���t�g_stack.U
				tim_MC21_�������[�^���]�ق���.U=tim_MC21_�������[�^���]�ق���_stack.U
				tim_MC21_�������[�^�t�]���t�g.U=tim_MC21_�������[�^�t�]���t�g_stack.U
				tim_MC20_�������[�^LFTUP.U=tim_MC20_�������[�^LFTUP_stack.U
				
				' tmr(tim_procstep,tim_procstep_val)
				' tmr(tim_SV40_�X�g�b�p,tim_SV40_�X�g�b�p_val) '�t�^��葕�u�X�g�b�p
				' tmr(tim_MC19_�������[�^,tim_MC19_�������[�^_val)
				' tmr(tim_MC20_�������[�^,tim_MC20_�������[�^_val)
				' tmr(tim_MC21_�������[�^���]���t�g,tim_MC21_�������[�^���]���t�g_val)
				' tmr(tim_MC21_�������[�^���]�ق���,tim_MC21_�������[�^���]�ق���_val)
				' tmr(tim_MC21_�������[�^�t�]���t�g,tim_MC21_�������[�^�t�]���t�g_val)

				
				'���o�^�C�}�[�̃��Z�b�g


				'---------------------------------
				inc(�����R���x�ADEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�ADEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�ADEmgStep=0
		�����R���x�ADEmg=OFF
	end select

end if 'if �����R���x�ADEmgStep=0 then
