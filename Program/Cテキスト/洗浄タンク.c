'���^���N
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	���^���N���j�b�g
'	
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    ���^���NAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ���^���NAutoRun=OFF
    ���^���N����=ON
    ���^���NOrgErr=OFF
    ���^���NErr=OFF
    ���^���NEmg=OFF
    ���^���Nstep=0
    ���^���NErrStep=0
    ���^���NOrgErrStep=0
    ���^���NEmgStep=0
	
	set(tim_notFLT1_�^���N���) '����q�X�e���V�X�^�C�}�[
	set(tim_notFLT3_�^���N���) '����q�X�e���V�X�^�C�}�[
	set(tim_notFLT5_�^���N���) '����q�X�e���V�X�^�C�}�[
	set(tim_notFLT7_�^���N���) '����q�X�e���V�X�^�C�}�[
	set(tim_notFLT9_�^���N���) '����q�X�e���V�X�^�C�}�[
end if
'===================================================================================================================
'�y ���_ �z
���^���NOrg=1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	���^���NEmg=ON
	���^���NEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o

tmr(SV69_�����d���� and not(FLT2_�^���N����) and not(pnlPBFLT2_�^���N����),tim_FLT2_�^���N����,#100)
tmr(SV69_�����d���� and FLT2_�^���N���� and not(FLT1_�^���N���) and not(pnlPBFLT1_�^���N���),tim_FLT1_�^���N���,#100)
tmr(SV75_�����d���� and not(FLT4_�^���N����) and not(pnlPBFLT4_�^���N����),tim_FLT4_�^���N����,#100)
tmr(SV75_�����d���� and FLT4_�^���N���� and not(FLT3_�^���N���) and not(pnlPBFLT3_�^���N���),tim_FLT3_�^���N���,#100)
tmr(SV81_�����d���� and not(FLT6_�^���N����) and not(pnlPBFLT6_�^���N����),tim_FLT6_�^���N����,#100)
tmr(SV81_�����d���� and FLT6_�^���N���� and not(FLT5_�^���N���) and not(pnlPBFLT5_�^���N���),tim_FLT5_�^���N���,#100)
tmr(SV87_�����d���� and not(FLT8_�^���N����) and not(pnlPBFLT8_�^���N����),tim_FLT8_�^���N����,#100)
tmr(SV87_�����d���� and FLT8_�^���N���� and not(FLT7_�^���N���) and not(pnlPBFLT7_�^���N���),tim_FLT7_�^���N���,#100)
tmr(SV93_�����d���� and not(FLT10_�^���N����) and not(pnlPBFLT10_�^���N����),tim_FLT10_�^���N����,#100)
tmr(SV93_�����d���� and FLT10_�^���N���� and not(FLT9_�^���N���) and not(pnlPBFLT9_�^���N���),tim_FLT9_�^���N���,#100)


if getEDC1_PV>85 then
	if ldp(getEDC1_PV>85)  then
	 	almSV70_���C�d����=ON
		���^���NErrStep=1
	end if
	SV70_���C�d����=OFF
	mSV70_���C�d����=OFF
	pauseSV70_���C�d����=OFF
end if
if getEDC2_PV>85 then
	if ldp(getEDC2_PV>85) then
	 	almSV76_���C�d����=ON
		���^���NErrStep=1
	end if
	SV76_���C�d����=OFF
	mSV76_���C�d����=OFF
	pauseSV76_���C�d����=OFF
end if
if getEDC3_PV>85 then
	if ldp(getEDC3_PV>85) then
	 	almSV82_���C�d����=ON
		���^���NErrStep=1
	end if
	SV82_���C�d����=OFF
	mSV82_���C�d����=OFF
	pauseSV82_���C�d����=OFF
end if
if getEDC4_PV>85 then
	if ldp(getEDC4_PV>85) then
	 	almSV88_���C�d����=ON
		���^���NErrStep=1
	end if
	SV88_���C�d����=OFF
	mSV88_���C�d����=OFF
	pauseSV88_���C�d����=OFF
end if
if getEDC5_PV>85 then
	if ldp(getEDC5_PV>85) then
	 	almSV94_���C�d����=ON
		���^���NErrStep=1
	end if
	SV94_���C�d����=OFF
	mSV94_���C�d����=OFF
	pauseSV94_���C�d����=OFF
end if	

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ���^���NAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ���^���NAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ���^���NEmg	���̏��~

'------------------------------------------------------------------------------------------
'�q�X�e���V�X�^�C�}�[
'------------------------------------------------------------------------------------------
tmr(tim_notFLT1_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
tmr(tim_notFLT3_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
tmr(tim_notFLT5_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
tmr(tim_notFLT7_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
tmr(tim_notFLT9_�^���N���,#100) '����q�X�e���V�X�^�C�}�[
'------------------------------------------------------------------------------------------
'���x���ߊ퐧��
'
' 83���ŋ��U����B�i����v���F�o���u�̔M�ɂ�鋤�U�j
'------------------------------------------------------------------------------------------
	if not(timFLT2_�^���N����.B)  then
		mSV70_���C�d����=OFF
	end if

	if not(timFLT4_�^���N����.B)  then
		mSV76_���C�d����=OFF
	end if

	if not(timFLT6_�^���N����.B) then
		mSV82_���C�d����=OFF
	end if
	
	if not(timFLT8_�^���N����.B) then
		mSV88_���C�d����=OFF
	end if
	
	if not(timFLT10_�^���N����.B) then
		mSV94_���C�d����=OFF
	end if


	if mSV70_���C�d���� then
		if ANDA(getEDC1_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8  and not(���x���ߊ�1Alm) then
			pauseSV70_���C�d����=OFF '�ꎞ��~����
		else
			pauseSV70_���C�d����=ON '�ꎞ��~	
		end if
	else
		pauseSV70_���C�d����=OFF '�ꎞ��~����
	end if

	if mSV76_���C�d���� then
		if  ANDA(getEDC2_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(���x���ߊ�2Alm) then
			pauseSV76_���C�d����=OFF
		else
			pauseSV76_���C�d����=ON
		end if
	else
		pauseSV76_���C�d����=OFF
	end if

	if mSV82_���C�d���� then
		if  ANDA(getEDC3_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(���x���ߊ�3Alm) then
			pauseSV82_���C�d����=OFF
		else
			pauseSV82_���C�d����=ON
		end if
	else
		pauseSV82_���C�d����=OFF
	end if
	
	if mSV88_���C�d���� then
		if ANDA(getEDC4_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(���x���ߊ�4Alm) then
			pauseSV88_���C�d����=OFF
		else
			pauseSV88_���C�d����=ON
		end if
	else
		pauseSV88_���C�d����=OFF	
	end if
	
	if mSV94_���C�d���� then
		if ANDA(getEDC5_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(���x���ߊ�5Alm) then
			pauseSV94_���C�d����=OFF
		else
			pauseSV94_���C�d����=ON
		end if
	else
		pauseSV94_���C�d����=OFF
	end if
'------------------------------------------------------------------------------------------
if not(PB45_�S��~SW) and not(��������AutoMode) then
		���^���NAutoRun=OFF
end if

if ldp(PB36_����SW) then
	if ���^���NAutoRun and not(��������AutoRun) and not(�e�X�g�^�]) then
		���^���NAutoRun=OFF
	else 
		���^���NAutoRun=ON
	end if
end if

PBL36_����=���^���NAutoRun
PBL42_�q�[�^=���^���NAutoRun

'------------------------------------------------------------------------------------------



if ���^���NEmgStep=0 then  
	
	if ���^���NErrStep=0 then

	'if ���^���NAutoMode and ��������AutoMode then
	if ���^���NAutoRun then

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		if ���^���NAutoRun then
			�蓮�����N��=OFF

			'-----------------------
			'	1�F����  , ���C
			'-----------------------			
			if timFLT2_�^���N����.B and getEDC1_PV<=85 then
				mSV70_���C�d����=ON
			else
				mSV70_���C�d����=OFF
			end if
		
			
			if not(timFLT1_�^���N���.B) and not(timFLT2_�^���N����.B) then
				mSV69_�����d����=ON	
			else if not(timFLT1_�^���N���.B) and tim_notFLT1_�^���N���.B and timFLT2_�^���N����.B  then
				mSV69_�����d����=ON	
			else if timFLT1_�^���N���.B and timFLT2_�^���N����.B then
				mSV69_�����d����=OFF
				res(tim_notFLT1_�^���N���)
			end if
			
			'-----------------------
			'	2�F����  , ���C
			'-----------------------
			if timFLT4_�^���N����.B and getEDC2_PV<=85 then
				mSV76_���C�d����=ON
			else
				mSV76_���C�d����=OFF
			end if
		
			if not(timFLT3_�^���N���.B) and not(timFLT4_�^���N����.B) then
				mSV75_�����d����=ON	
			else if not(timFLT3_�^���N���.B) and tim_notFLT3_�^���N���.B and timFLT4_�^���N����.B then
				mSV75_�����d����=ON	
			else if timFLT3_�^���N���.B and timFLT4_�^���N����.B then
				mSV75_�����d����=OFF
				res(tim_notFLT3_�^���N���)
			end if
			'-----------------------
			'	3�F����  , ���C
			'-----------------------
			if timFLT6_�^���N����.B and getEDC3_PV<=85 then
				mSV82_���C�d����=ON
			else 
				mSV82_���C�d����=OFF
			end if

			if not(timFLT5_�^���N���.B) and not(timFLT6_�^���N����.B) then
				mSV81_�����d����=ON	
			else if not(timFLT5_�^���N���.B) and tim_notFLT5_�^���N���.B and timFLT6_�^���N����.B then
				mSV81_�����d����=ON	
			else if timFLT5_�^���N���.B and timFLT6_�^���N����.B then
				mSV81_�����d����=OFF
				res(tim_notFLT5_�^���N���)
			end if
			'-----------------------
			'	  4�F����  , ���C
			'-----------------------
			if timFLT8_�^���N����.B and getEDC4_PV<=85 then
				mSV88_���C�d����=ON
			else
				mSV88_���C�d����=OFF
			end if
			
			if not(timFLT7_�^���N���.B) and not(timFLT8_�^���N����.B) then
				mSV87_�����d����=ON	
			else if not(timFLT7_�^���N���.B) and tim_notFLT7_�^���N���.B and timFLT8_�^���N����.B then
				mSV87_�����d����=ON	
			else if timFLT7_�^���N���.B and timFLT8_�^���N����.B then
				mSV87_�����d����=OFF
				res(tim_notFLT7_�^���N���)
			end if
			'-----------------------
			'	  5�F����  , ���C
			'-----------------------
			if timFLT10_�^���N����.B and getEDC5_PV<=85 then
				mSV94_���C�d����=ON
			else
				mSV94_���C�d����=OFF
			end if
		
			if not(timFLT9_�^���N���.B) and not(timFLT10_�^���N����.B) then
				mSV93_�����d����=ON	
			else if not(timFLT9_�^���N���.B) and tim_notFLT9_�^���N���.B and timFLT10_�^���N����.B then
				mSV93_�����d����=ON	
			else if timFLT9_�^���N���.B and timFLT10_�^���N����.B then
				mSV93_�����d����=OFF
				res(tim_notFLT9_�^���N���)
			end if
		
		else
			mSV70_���C�d����=OFF
			mSV69_�����d����=OFF
			
			mSV76_���C�d����=OFF
			mSV75_�����d����=OFF
			
			mSV82_���C�d����=OFF
			mSV81_�����d����=OFF
			
			mSV88_���C�d����=OFF
			mSV87_�����d����=OFF
			
			mSV94_���C�d����=OFF
			mSV93_�����d����=OFF
			
		end if
			

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		'�����A�����͎����A�蓮�֌W�Ȃ��}�j���A������\�Ȃ���
		'Auto���[�hOFF�ł̃}�j���A�����암���͂Ȃ�
		
		if not(�蓮�����N��) then
			�蓮�����N��=ON

			mSV69_�����d����=OFF
			mSV70_���C�d����=OFF
	
			mSV75_�����d����=OFF
			mSV76_���C�d����=OFF

			mSV81_�����d����=OFF
			mSV82_���C�d����=OFF

			mSV87_�����d����=OFF
			mSV88_���C�d����=OFF

			mSV93_�����d����=OFF
			mSV94_���C�d����=OFF
			
			mSV97_�������d����=OFF
			mSV98_�d�グ�d����=OFF
		
		
			tmp_�����d����=OFF
			tmp1SV69_�����d����=OFF
			tmp2SV69_�����d����=OFF
			tmp1SV75_�����d����=OFF
			tmp2SV75_�����d����=OFF
			tmp1SV81_�����d����=OFF
			tmp2SV81_�����d����=OFF
			tmp1SV87_�����d����=OFF
			tmp2SV87_�����d����=OFF
			tmp1SV93_�����d����=OFF
			tmp2SV93_�����d����=OFF
			tmp_���C�d����=OFF
			tmp1SV70_���C�d����=OFF
			tmp2SV70_���C�d����=OFF
			tmp1SV76_���C�d����=OFF
			tmp2SV76_���C�d����=OFF
			tmp1SV82_���C�d����=OFF
			tmp2SV82_���C�d����=OFF
			tmp1SV88_���C�d����=OFF
			tmp2SV88_���C�d����=OFF
			tmp1SV94_���C�d����=OFF
			tmp2SV94_���C�d����=OFF
		end if
		
		if ldp(pnlPBSV97_�������d����) then
			if mSV97_�������d���� then
				mSV97_�������d����=OFF
			else
				mSV97_�������d����=ON
			end if
		end if
		if ldp(pnlPBSV98_�d�グ�d����) then
			if mSV98_�d�グ�d���� then
				mSV98_�d�グ�d����=OFF
			else
				mSV98_�d�グ�d����=ON
			end if
		end if

		mSV69_�����d����=tmp1SV69_�����d���� or tmp2SV69_�����d����
		mSV75_�����d����=tmp1SV75_�����d���� or tmp2SV75_�����d����
		mSV81_�����d����=tmp1SV81_�����d���� or tmp2SV81_�����d����
		mSV87_�����d����=tmp1SV87_�����d���� or tmp2SV87_�����d����
		mSV93_�����d����=tmp1SV93_�����d���� or tmp2SV93_�����d����
		
		mSV70_���C�d����=(tmp1SV70_���C�d���� or tmp2SV70_���C�d����) and FLT2_�^���N����
		mSV76_���C�d����=(tmp1SV76_���C�d���� or tmp2SV76_���C�d����) and FLT4_�^���N����
		mSV82_���C�d����=(tmp1SV82_���C�d���� or tmp2SV82_���C�d����) and FLT6_�^���N����
		mSV88_���C�d����=(tmp1SV88_���C�d���� or tmp2SV88_���C�d����) and FLT8_�^���N����
		mSV94_���C�d����=(tmp1SV94_���C�d���� or tmp2SV94_���C�d����) and FLT10_�^���N����


		if PB45_�S��~SW then 
			'----------------
			'�R�}���hSW����
			'----------------
			if SEL2_1_�^�]�؊��i�P���j then 'B�ړ_
				tmp2SV69_�����d����=OFF
				tmp2SV75_�����d����=OFF
				tmp2SV81_�����d����=OFF
				tmp2SV87_�����d����=OFF
				tmp2SV93_�����d����=OFF

				tmp2SV70_���C�d����=OFF
				tmp2SV76_���C�d����=OFF
				tmp2SV82_���C�d����=OFF
				tmp2SV88_���C�d����=OFF
				tmp2SV94_���C�d����=OFF
			'--------------------------------------------------------------
				'if ldp(PB36_����SW) then
				'	if tmp_�����d���� then
				'		tmp_�����d����=OFF
				'	else
				'		tmp_�����d����=ON
				'	end if
				'end if
				
				'tmp1SV69_�����d����=tmp_�����d����
				'tmp1SV75_�����d����=tmp_�����d����
				'tmp1SV81_�����d����=tmp_�����d����
				'tmp1SV87_�����d����=tmp_�����d����
				'tmp1SV93_�����d����=tmp_�����d����
			'--------------------------------------------------------------
				'if ldp(PB42_�q�[�^SW) then 
				'	if tmp_���C�d���� then
				'		tmp_���C�d����=OFF
				'	else
				'		tmp_���C�d����=ON
				'	end if
				'end if
					
				'if tmp_���C�d���� and FLT2_�^���N���� then
				'	tmp1SV70_���C�d����=ON
				'else
				'	tmp1SV70_���C�d����=OFF
				'end if
				'----------------
				'if tmp_���C�d���� and FLT4_�^���N���� then
				'	tmp1SV76_���C�d����=ON
				'else
				'	tmp1SV76_���C�d����=OFF
				'end if
				'----------------
				'if tmp_���C�d���� and FLT6_�^���N���� then
				'	tmp1SV82_���C�d����=ON
				'else
				'	tmp1SV82_���C�d����=OFF
				'end if
				'----------------			
				'if tmp_���C�d���� and FLT8_�^���N���� then
				'	tmp1SV88_���C�d����=ON
				'else
				'	tmp1SV88_���C�d����=OFF
				'end if
				'----------------
				'if tmp_���C�d���� and FLT10_�^���N���� then
				'	tmp1SV94_���C�d����=ON
				'else
				'	tmp1SV94_���C�d����=OFF
				'end if
				'----------------

			else
				tmp_�����d����=OFF
				tmp1SV69_�����d����=OFF
				tmp1SV75_�����d����=OFF
				tmp1SV81_�����d����=OFF
				tmp1SV87_�����d����=OFF
				tmp1SV93_�����d����=OFF
				tmp_���C�d����=OFF
				tmp1SV70_���C�d����=OFF
				tmp1SV76_���C�d����=OFF
				tmp1SV82_���C�d����=OFF
				tmp1SV88_���C�d����=OFF
				tmp1SV94_���C�d����=OFF
				
				'----------------			
				' �p�l������	
				'----------------			
				if ldp(pnlPBSV69_�����d����) then
					if tmp2SV69_�����d���� then
						tmp2SV69_�����d����=OFF
					else
						tmp2SV69_�����d����=ON
					end if
				end if
				'----------------						
				if ldp(pnlPBSV75_�����d����) then
					if tmp2SV75_�����d���� then
						tmp2SV75_�����d����=OFF
					else
						tmp2SV75_�����d����=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV81_�����d����) then
					if tmp2SV81_�����d���� then
						tmp2SV81_�����d����=OFF
					else
						tmp2SV81_�����d����=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV87_�����d����) then
					if tmp2SV87_�����d���� then
						tmp2SV87_�����d����=OFF
					else
						tmp2SV87_�����d����=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV93_�����d����) then
					if tmp2SV93_�����d���� then
						tmp2SV93_�����d����=OFF
					else
						tmp2SV93_�����d����=ON
					end if
				end if
				'--------------------------------------------------------------
				if ldp(pnlPBSV70_���C�d����) then
					if tmp2SV70_���C�d���� then
						tmp2SV70_���C�d����=OFF
					else if FLT2_�^���N���� then
						tmp2SV70_���C�d����=ON
					end if
				end if
				'----------------
					if ldp(pnlPBSV76_���C�d����) then
					if tmp2SV76_���C�d���� then
						tmp2SV76_���C�d����=OFF
					else if FLT4_�^���N���� then
						tmp2SV76_���C�d����=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV82_���C�d����) then
					if tmp2SV82_���C�d���� then
						tmp2SV82_���C�d����=OFF
					else if FLT6_�^���N���� then
						tmp2SV82_���C�d����=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV88_���C�d����) then
					if tmp2SV88_���C�d���� then
						tmp2SV88_���C�d����=OFF
					else if FLT8_�^���N���� then
						tmp2SV88_���C�d����=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV94_���C�d����) then
					if tmp2SV94_���C�d���� then
						tmp2SV94_���C�d����=OFF
					else if FLT10_�^���N���� then
						tmp2SV94_���C�d����=ON
					end if
				end if
				'--------------------------------------------------------------
					
				

			end if
		else
			PBL36_����=OFF
			PBL42_�q�[�^=OFF
		
			mSV69_�����d����=OFF
			mSV70_���C�d����=OFF
	
			mSV75_�����d����=OFF
			mSV76_���C�d����=OFF

			mSV81_�����d����=OFF
			mSV82_���C�d����=OFF

			mSV87_�����d����=OFF
			mSV88_���C�d����=OFF

			mSV93_�����d����=OFF
			mSV94_���C�d����=OFF
		
			mSV97_�������d����=OFF
			mSV98_�d�グ�d����=OFF
		
			tmp_�����d����=OFF
			tmp1SV69_�����d����=OFF
			tmp2SV69_�����d����=OFF
			tmp1SV75_�����d����=OFF
			tmp2SV75_�����d����=OFF
			tmp1SV81_�����d����=OFF
			tmp2SV81_�����d����=OFF
			tmp1SV87_�����d����=OFF
			tmp2SV87_�����d����=OFF
			tmp1SV93_�����d����=OFF
			tmp2SV93_�����d����=OFF
			tmp_���C�d����=OFF
			tmp1SV70_���C�d����=OFF
			tmp2SV70_���C�d����=OFF
			tmp1SV76_���C�d����=OFF
			tmp2SV76_���C�d����=OFF
			tmp1SV82_���C�d����=OFF
			tmp2SV82_���C�d����=OFF
			tmp1SV88_���C�d����=OFF
			tmp2SV88_���C�d����=OFF
			tmp1SV94_���C�d����=OFF
			tmp2SV94_���C�d����=OFF
		end if
		

	
	end if
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else
	
		���^���NErr=ON

		if almSV70_���C�d���� or almSV76_���C�d���� or almSV82_���C�d���� or almSV88_���C�d���� or almSV94_���C�d���� then
		
			select case ���^���NErrStep
			case 0
			case 1
				if ResetFlg then
					almSV70_���C�d����=OFF
					almSV76_���C�d����=OFF
					almSV82_���C�d����=OFF
					almSV88_���C�d����=OFF
					almSV94_���C�d����=OFF
					inc(���^���NErrStep)
				end if
			case 2
				���^���NErr=OFF

				���^���NErrStep=0
			end select
		
		else 

			mSV70_���C�d����=OFF
			mSV69_�����d����=OFF
			
			mSV76_���C�d����=OFF
			mSV75_�����d����=OFF
			
			mSV82_���C�d����=OFF
			mSV81_�����d����=OFF
			
			mSV88_���C�d����=OFF
			mSV87_�����d����=OFF
			
			mSV94_���C�d����=OFF
			mSV93_�����d����=OFF


			select case ���^���NErrStep
			case 0
			case 1
				if ResetFlg then
					almFLT2_�^���N���� =OFF
					almFLT1_�^���N���=OFF
					almFLT4_�^���N����=OFF
					almFLT3_�^���N���=OFF
					almFLT6_�^���N����=OFF
					almFLT10_�^���N����=OFF
					almFLT9_�^���N���=OFF

					inc(���^���NErrStep)
				end if
			case 2
				���^���NErr=OFF
				
				res(tim_FLT2_�^���N����.B)
				res(tim_FLT1_�^���N���.B)
				res(tim_FLT4_�^���N����.B)
				res(tim_FLT3_�^���N���.B)
				res(tim_FLT6_�^���N����.B)
				res(tim_FLT7_�^���N���.B)
				res(tim_FLT10_�^���N����.B)
				res(tim_FLT9_�^���N���.B)

				���^���NErrStep=0
			end select
		
		end if

	end if
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case ���^���NEmgStep
	case 0

	case 1
		���^���NAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------

		
		
		if ���^���NAutoMode  and ��������AutoMode then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
		
			mSV69_�����d����=OFF
			mSV70_���C�d����=OFF

			mSV75_�����d����=OFF
			mSV76_���C�d����=OFF

			mSV81_�����d����=OFF
			mSV82_���C�d����=OFF

			mSV87_�����d����=OFF
			mSV88_���C�d����=OFF

			mSV93_�����d����=OFF
			mSV94_���C�d����=OFF
		
		
			tmp_�����d����=OFF
			tmp1SV69_�����d����=OFF
			tmp2SV69_�����d����=OFF
			tmp1SV75_�����d����=OFF
			tmp2SV75_�����d����=OFF
			tmp1SV81_�����d����=OFF
			tmp2SV81_�����d����=OFF
			tmp1SV87_�����d����=OFF
			tmp2SV87_�����d����=OFF
			tmp1SV93_�����d����=OFF
			tmp2SV93_�����d����=OFF
			tmp_���C�d����=OFF
			tmp1SV70_���C�d����=OFF
			tmp2SV70_���C�d����=OFF
			tmp1SV76_���C�d����=OFF
			tmp2SV76_���C�d����=OFF
			tmp1SV82_���C�d����=OFF
			tmp2SV82_���C�d����=OFF
			tmp1SV88_���C�d����=OFF
			tmp2SV88_���C�d����=OFF
			tmp1SV94_���C�d����=OFF
			tmp2SV94_���C�d����=OFF			

			if timstack=OFF then

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			PBL36_����=OFF
			PBL42_�q�[�^=OFF
		
			mSV69_�����d����=OFF
			mSV70_���C�d����=OFF
	
			mSV75_�����d����=OFF
			mSV76_���C�d����=OFF

			mSV81_�����d����=OFF
			mSV82_���C�d����=OFF

			mSV87_�����d����=OFF
			mSV88_���C�d����=OFF

			mSV93_�����d����=OFF
			mSV94_���C�d����=OFF
		
		
			tmp_�����d����=OFF
			tmp1SV69_�����d����=OFF
			tmp2SV69_�����d����=OFF
			tmp1SV75_�����d����=OFF
			tmp2SV75_�����d����=OFF
			tmp1SV81_�����d����=OFF
			tmp2SV81_�����d����=OFF
			tmp1SV87_�����d����=OFF
			tmp2SV87_�����d����=OFF
			tmp1SV93_�����d����=OFF
			tmp2SV93_�����d����=OFF
			tmp_���C�d����=OFF
			tmp1SV70_���C�d����=OFF
			tmp2SV70_���C�d����=OFF
			tmp1SV76_���C�d����=OFF
			tmp2SV76_���C�d����=OFF
			tmp1SV82_���C�d����=OFF
			tmp2SV82_���C�d����=OFF
			tmp1SV88_���C�d����=OFF
			tmp2SV88_���C�d����=OFF
			tmp1SV94_���C�d����=OFF
			tmp2SV94_���C�d����=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(���^���NEmgStep)
	case 2
		if ResetFlg then
			inc(���^���NEmgStep)
		end if
	case 3
		if StartFlg then
			'---------------------------------
			'�ً}��~����(����  �����T�C�N��)
			'---------------------------------

			'---------------------------------
			inc(���^���NEmgStep)
		end if
	case 4
		timstack=OFF
		���^���NEmgStep=0
		���^���NEmg=OFF
	end select
		
		
end if 'if ���^���NEmgStep=0 then
