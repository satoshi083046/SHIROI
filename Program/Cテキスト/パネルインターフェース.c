'�p�l���C���^�[�t�F�[�X
'----------------------------------------------------------------------------------
'<IOMAP.XLS / �p�l���C���^�[�t�F�[�X> 
'----------------------------------
'�y�O���[�o�����x���z
'pnlPBel����	�r�b�g	MR00100
'pnlPBel��	�r�b�g	MR00101
'pnlPBel�T	�r�b�g	MR00102
'pnlPBel��	�r�b�g	MR00103
'pnlPBel���ړ�	�r�b�g	MR00104
'pnlPBel�E�ړ�	�r�b�g	MR00105
'pnlPBel���ړ�	�r�b�g	MR00106
'pnlPBel�����ړ�	�r�b�g	MR00107
'pnlPBel��ړ�	�r�b�g	MR00108
'pnlPBel����ړ�	�r�b�g	MR00109
'pnlPBel�X�V	�r�b�g	MR00110
'pnlPBelALL	�r�b�g	MR00111
'pnlPBel�^�]��	�r�b�g	MR00112
'pnlPBel�������[�h	�r�b�g	MR00113
'pnlPBel�e�X�g�^�]	�r�b�g	MR00114
'pnlPBel����~	�r�b�g	MR00115
'pnlPBel�O�����^�]��	�r�b�g	MR00200
'init����	�r�b�g	MR00201
'init��	�r�b�g	MR00202
'init�T	�r�b�g	MR00203
'init��	�r�b�g	MR00204
'		
'Filewritestep	1���[�h�����Ȃ�����	DM1000
'Filereadstep	1���[�h�����Ȃ�����	DM1001
'ErrAnalyzestep	1���[�h�����Ȃ�����	DM1002
'ErrAnalyzeStatcheckBit	1���[�h�����Ȃ�����	DM1003
'ErrAnlyzeTotalCnt	1���[�h�����Ȃ�����	DM1004
'dspErrAnalOffset	1���[�h�����Ȃ�����	DM1005
'el���݃y�[�WNO	1���[�h�����Ȃ�����	DM1006
'dspErrAnalIndex	1���[�h�����Ȃ�����	DM1007
'wFilewritestep	1���[�h�����Ȃ�����	DM1008
'		
'setFindStart�N����	1���[�h�����Ȃ�����[6]	DM1010
'setFindEnd�N����	1���[�h�����Ȃ�����[6]	DM1020
'FindStart�N����	1���[�h�����Ȃ�����[6]	DM1030
'FindEnd�N����	1���[�h�����Ȃ�����[6]	DM1040 
'ErrAnalyzeCode	1���[�h�����Ȃ�����[50]	DM1100
'ErrAnalyzePersent	1���[�h�����Ȃ�����[50]	DM1150
'ErrAnalyzeCnt	1���[�h�����Ȃ�����[50]	DM1200
'----------------------------------------------------------------------------------
'�y���[�J�����x���z
'FindEndSec	2���[�h�����Ȃ�����
'FindStartSec	2���[�h�����Ȃ�����
'Find�N����	1���[�h�����Ȃ�����[6]
'dsp�X�V	�r�b�g
'todaySec	2���[�h�����Ȃ�����
'-----------------------------------------------------------------------------------------------------------------------------
'�y�[�W�ړ�
	el���݃y�[�WNO=dspErrAnalIndex+1
	dspErrAnalOffset=dspErrAnalIndex*10

	if ldp(pnlPBel�����ړ�) then
		dspErrAnalIndex=4
	
	else if ldp(pnlPBel���ړ�) then
		
		if dspErrAnalIndex>=4 then
			dspErrAnalIndex=4
		else
			dspErrAnalIndex=dspErrAnalIndex+1
		end if
		
	else if ldp(pnlPBel����ړ�) then
		dspErrAnalIndex=0
	
	else if ldp(pnlPBel��ړ�) then
		if dspErrAnalIndex>0 then
			dspErrAnalIndex=dspErrAnalIndex-1
		else
			dspErrAnalIndex=0
		end if
	end if

'----------------------------------------------------------------------------------
if ldp(pnlPBel�X�V) or dsp�X�V then
	FindStart�N����[0]=setFindStart�N����[0]
	FindStart�N����[1]=setFindStart�N����[1]
	FindStart�N����[2]=setFindStart�N����[2]
	setFindStart�N����[3]=0
	setFindStart�N����[4]=0
	setFindStart�N����[5]=0
	setFindEnd�N����[3]=23
	setFindEnd�N����[4]=59
	setFindEnd�N����[5]=0

	FindEnd�N����[0]=setFindEnd�N����[0]
	FindEnd�N����[1]=setFindEnd�N����[1]
	FindEnd�N����[2]=setFindEnd�N����[2]
	FindStart�N����[3]=0
	FindStart�N����[4]=0
	FindStart�N����[5]=0
	FindEnd�N����[3]=23
	FindEnd�N����[4]=59
	FindEnd�N����[5]=0
	
	Filereadstep=1
	dspErrAnalIndex=0
	dsp�X�V=OFF
	
end if

'----------------------------------------------------------------------------------
if ldp(pnlPBel����) then
	pnlPBel����=ON
	pnlPBel��=OFF
	pnlPBel�T=OFF
	pnlPBel��=OFF
	init����=ON	
else if ldp(pnlPBel��) then
	pnlPBel����=OFF
	pnlPBel��=ON
	pnlPBel�T=OFF
	pnlPBel��=OFF
	init��=ON
else if ldp(pnlPBel�T) then
	pnlPBel����=OFF
	pnlPBel��=OFF
	pnlPBel�T=ON
	pnlPBel��=OFF
	init�T=ON
else if ldp(pnlPBel��) then
	pnlPBel����=OFF
	pnlPBel��=OFF
	pnlPBel�T=OFF
	pnlPBel��=ON
	init��=ON
end if
'----------------------------------------------------------------------------------
if 	pnlPBel���� then
	if init���� then
		init����=OFF	
	
		setFindStart�N����[0]=CM700
		setFindStart�N����[1]=CM701
		setFindStart�N����[2]=CM702
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702
	
		dspErrAnalIndex=0
		dsp�X�V=ON
	else if CM700<>FindStart�N����[0] or CM701<>FindStart�N����[1] or  CM702<>FindStart�N����[2] then
		
		setFindStart�N����[0]=CM700
		setFindStart�N����[1]=CM701
		setFindStart�N����[2]=CM702
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702
		
		dsp�X�V=ON
	
	end if

	

else if pnlPBel�� then
	if init�� then
		init��=OFF
		
		setFindStart�N����[0]=CM700
		setFindStart�N����[1]=CM701
		setFindStart�N����[2]=CM702
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702

		dspErrAnalIndex=0
		dsp�X�V=ON
	else if setFindStart�N����[0]<>FindStart�N����[0] or setFindStart�N����[1]<>FindStart�N����[1] or  setFindStart�N����[2]<>FindStart�N����[2] then

		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702			
		else
			RSEC(FindStartSec,setFindStart�N����)
			RSEC(FindStartSec,setFindEnd�N����)			
		end if
		
		dsp�X�V=ON

	end if

	if ldp(pnlPBel���ړ�) then
		FindStartSec=SEC(setFindStart�N����)-86400
		RSEC(FindStartSec,setFindStart�N����)
		RSEC(FindStartSec,setFindEnd�N����)			
		
		dsp�X�V=ON

	else if ldp(pnlPBel�E�ړ�) then
	
		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=CM702
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		
		todaySec=SEC(Find�N����)
		
		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702			
		else
			FindStartSec=SEC(setFindStart�N����)+86400
			RSEC(FindStartSec,setFindStart�N����)
			RSEC(FindStartSec,setFindEnd�N����)			
		end if

		dsp�X�V=ON
	
	end if
	

else if pnlPBel�T then
	if init�T then
		init�T=OFF

		FindStartSec=SEC(CM700)-518400
		RSEC(FindStartSec,setFindStart�N����)
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702

		dspErrAnalIndex=0
		dsp�X�V=ON
	else if setFindStart�N����[0]<>FindStart�N����[0] or setFindStart�N����[1]<>FindStart�N����[1] or  setFindStart�N����[2]<>FindStart�N����[2] then

		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
		else
			RSEC(FindStartSec,setFindStart�N����)	
		end if
		FindEndSec=SEC(setFindEnd�N����)+518400-1 '1�T��
		if FindEndSec>=todaySec then
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd�N����)
		end if
		
		dsp�X�V=ON
		
	end if
	
	if ldp(pnlPBel���ړ�) then
		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart�N����)-518400
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
		else
			RSEC(FindStartSec,setFindStart�N����)		
		end if
		
		FindEndSec=SEC(setFindStart�N����)+518400-1 '1�T��
		if FindEndSec>=todaySec then
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd�N����)
		end if
		
		dsp�X�V=ON

	
	else if ldp(pnlPBel�E�ړ�) then
		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart�N����)+518400
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=CM702
		else
			RSEC(FindStartSec,setFindStart�N����)
		end if
		FindEndSec=SEC(setFindStart�N����)+518400-1 '1�T��
		if FindEndSec>=todaySec then
			setFindEnd�N����[0]=CM700
			setFindEnd�N����[1]=CM701
			setFindEnd�N����[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd�N����)
		end if
		
		dsp�X�V=ON


	end if

else if	pnlPBel�� then
	setFindEnd�N����[0]=CM700
	setFindEnd�N����[1]=CM701
	setFindEnd�N����[2]=CM702

	if init�� then
		init��=OFF

		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=1
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		FindStartSec=SEC(Find�N����)
		RSEC(FindStartSec,setFindStart�N����)
		setFindEnd�N����[0]=CM700
		setFindEnd�N����[1]=CM701
		setFindEnd�N����[2]=CM702

		dspErrAnalIndex=0
		dsp�X�V=ON

	else if setFindStart�N����[0]<>FindStart�N����[0] or setFindStart�N����[1]<>FindStart�N����[1] or  setFindStart�N����[2]<>FindStart�N����[2] then

		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=1
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		todaySec=SEC(Find�N����)
		
		setFindStart�N����[2]=1 '�����I��1���ɂ���
		
		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=1
		else
			RSEC(FindStartSec,setFindStart�N����)
		end if
		dsp�X�V=ON
		
	end if
	
	if ldp(pnlPBel���ړ�) then
		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=1
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		todaySec=SEC(Find�N����)

		setFindStart�N����[2]=1 '�����I��1���ɂ���
		
		if setFindStart�N����[1]>=2 and setFindStart�N����[1]<=12 then
			setFindStart�N����[1]=setFindStart�N����[1]-1
		else if setFindStart�N����[1]=1 then
			setFindStart�N����[0]=setFindStart�N����[0]-1
			setFindStart�N����[1]=12
		end if
		
		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=1
		else
			RSEC(FindStartSec,setFindStart�N����)		
		end if
		
		dsp�X�V=ON

	
	else if ldp(pnlPBel�E�ړ�) then
		Find�N����[0]=CM700
		Find�N����[1]=CM701
		Find�N����[2]=1
		Find�N����[3]=0
		Find�N����[4]=0
		Find�N����[5]=0
		todaySec=SEC(Find�N����)

		setFindStart�N����[2]=1 '�����I��1���ɂ���
		
		if setFindStart�N����[1]>=1 and setFindStart�N����[1]<12 then
			setFindStart�N����[1]=setFindStart�N����[1]+1
		else if setFindStart�N����[1]=12 then
			setFindStart�N����[0]=setFindStart�N����[0]+1
			setFindStart�N����[1]=1
		end if

		FindStartSec=SEC(setFindStart�N����)
		if FindStartSec>=todaySec then
			setFindStart�N����[0]=CM700
			setFindStart�N����[1]=CM701
			setFindStart�N����[2]=1
		else
			RSEC(FindStartSec,setFindStart�N����)
		end if

		dsp�X�V=ON


	end if

end if

'----------------------------------------------------------------------------------
' �ؑփy�[�W
if CR2008 then '�d��ON������������
	
	���C��TP_�ؑփy�[�W�m��=�X�^�[�g�A�b�v���
	�T�uTP_�ؑփy�[�W�m��=�X�^�[�g�A�b�v���
	�ނ炵TP_�ؑփy�[�W�m��=�X�^�[�g�A�b�v���
	
	
	MainStatusMsg=0
	�O�����H��StatusMsg=0
	��������StatusMsg=0
	�v��StatusMsg=0
	����StatusMsg=0
	�Z�Ѓ^���NAStatusMsg=0
	�Z�Ѓ^���NBStatusMsg=0
	�Z�Ѓ^���NA���j�b�gStatusMsg=0
	�Z�Ѓ^���NB���j�b�gStatusMsg=0
	�v�����j�b�gStatusMsg=0
	�Ȃ炵���uStatusMsg=0
	�W�킹���j�b�gStatusMsg=0
	�W��胆�j�b�gStatusMsg=0
	���͂񌟒mStatusMsg=0
	�o�L���[�����j�b�gStatusMsg=0
	�ق����@A���j�b�gStatusMsg=0
	�ق����@B���j�b�gStatusMsg=0
	�����R���x�AAStatusMsg=0
	�����R���x�ABStatusMsg=0
	�����R���x�ACStatusMsg=0
	������R���x�AStatusMsg=0
	�ނ炵�@������R���x�AStatusMsg=0
	�����R���x�ADStatusMsg=0
	�����R���x�AEStatusMsg=0
	�����R���x�AFStatusMsg=0
	���t�^���~���uAStatusMsg=0
	�����]����StatusMsg=0
	���������t�gStatusMsg=0
	����������StatusMsg=0
	��򃆃j�b�gStatusMsg=0
	���^���NStatusMsg=0
	���R���x�A����StatusMsg=0
	���o������StatusMsg=0
	���t�^���~���uBStatusMsg=0	

else

	'--------------------------------------------------------------------------------	
	'�ُ헚�����
	if ldp(��������ErrStep<>0) then
		���C��TP_�ؑփy�[�W�m��=�ُ헚�����
		�T�uTP_�ؑփy�[�W�m��=�ُ헚�����
		�ނ炵TP_�ؑփy�[�W�m��=�ُ헚�����
	
	'--------------------------------------------------------------------------------	
	'�\����e�m�F���
	else if �\��m�F then
			if DM_A�^���N�ݒ�l<>0 or DM_B�^���N�ݒ�l<>0 then
				�O�����ݒ芮��=ON
				���C��TP_�ؑփy�[�W�m��=12 '�\����e�m�F���
			else
				�O�����ݒ芮��=OFF		
			end if
	'--------------------------------------------------------------------------------	
	end if

end if



'--------------------------------------------------------------------------------	
'----------------------------------------------------------------------------------
'�A�C�e���A�h���X�Q��
'
'
'ITEM TABLE
'       �z�ďd��    �v�ʐ��d��  �A�C�e������
' 1		EM1020		EM1021(+1)	EM1030(+10)
' 2		EM1040(+20)	EM1041		EM1050
' 3		EM1060		EM1061		EM1070
' 4		EM1080		EM1081		EM1090

	'�A�C�e���ݒ�NO
	DM_ITEMNO=DM_ITEMNO

	if DM_ITEMNO>0 then
	
'			DM_�v���ڕW����1=DM_�ݒ萅�ʊ�l+DM_���ʕ␳�l
'			DM_�󊘌v���ڕW����1=DM_�������ʊ�l+DM_���ʕ␳�l
		if 0 then
			'�y�z�ďd�ʁz
			ADRSET(EM1020,ptr�A�C�e���z�ďd��)
			ADRADD(20 * (DM_ITEMNO-1),ptr�A�C�e���z�ďd��)
			DM_�ݒ萅�ʊ�l=*ptr�A�C�e���z�ďd��.U
			
			'�y�v�ʐ��d�ʁz
			ADRSET(EM1021,ptr�A�C�e���v�ʐ��d��)
			ADRADD(20 * (DM_ITEMNO-1),ptr�A�C�e���v�ʐ��d��)
			DM_�������ʊ�l=*ptr�A�C�e���v�ʐ��d��
			
			'�y�A�C�e�����́z
			ADRSET(EM1030,ptr�A�C�e������)
			ADRADD(20 * (DM_ITEMNO-1),ptr�A�C�e������)
			' -- �����o�b�t�@�N���A --
			ADRSET(EM4001.U,loopptr)
			FOR loop=1 TO 10
				*loopptr.U=0
				inc(loopptr)
			NEXT
			'-- ������R�s�[
			EM4001.T=*ptr�A�C�e������.T
		else
			'�y�z�ďd�ʁz
			DM_�ݒ萅�ʊ�l=�A�C�e���ݒ萅��[DM_ITEMNO]			
			'�y�v�ʐ��d�ʁz
			DM_�������ʊ�l=�A�C�e����������[DM_ITEMNO]
			
			' -- �����o�b�t�@�N���A --
			ADRSET(EM4001.U,loopptr)
			FOR loop=1 TO 10
				*loopptr.U=0
				inc(loopptr)
			NEXT
			'-- ������R�s�[
			ADRSET(�A�C�e������1,ptr�A�C�e������)
			ADRADD((DM_ITEMNO-1)*16,ptr�A�C�e������)
			EM4001.T=*ptr�A�C�e������.T
			
			
		
		end if

		
		
	else if DM_ITEMNO=0 then
		' -- �����o�b�t�@�N���A --
		ADRSET(EM4001.U,loopptr)
		FOR loop=1 TO 10
			*loopptr.U=0
			inc(loopptr)
		NEXT
		'-- �������
		EM4001.T=""	
	
	end if

	'--------------------------------------------------------------------------------------------
	' �A���t�@���Ẵr�b�g�Z�b�g
	'   �A             ��              �t            �@              ��              ��
if 0 then
	if EM4001.U=$4183 and EM4002.U=$8B83 and EM4003.U=$7483 and EM4004.U=$4083 and EM4005.U=$BB89 and EM4006.U=$C495 then
		�A���t�@���ă��[�h=ON
	else 
		�A���t�@���ă��[�h=OFF
	end if
else
	if EM4001.U=$8341 and EM4002.U=$838B and EM4003.U=$8374 and EM4004.U=$8340 and EM4005.U=$89BB and EM4006.U=$95C4 then
		�A���t�@���ă��[�h=ON
	else 
		�A���t�@���ă��[�h=OFF
	end if
end if

'----------------------------------------------------------------------------------
' �^�b�`�p�l���ɓo�^���ꂽ���b�Z�[�W�ԍ�����������
' xxxxStatusMsg=�i���b�Z�[�W�ԍ��j
'
'----------------------------------------------------------------------------------
'	���b�Z�[�W�R�[�h			
'		#0	'	���b�Z�[�W�Ȃ�
'----------------------------------------------------------------------------------
'	�V�[�P���V�����^�]���
'	MainStatusMsg=0
'		MainStatusMsg=#100 '���@�^���N������
'		MainStatusMsg=#102 '���@�^���N���M��
'		MainStatusMsg=#103 '���@�^���N�������A���M��
'		MainStatusMsg=#101 '���@�^���N��������
'		MainStatusMsg=#110 '���щ^�]�X�C�b�`�������Ă��������B�����R���x�A�����삵�܂��B�����ӂ��������B
'		MainStatusMsg=#111 '���ы@���Ίm�F
'		MainStatusMsg=#112 '�z�Ă̏������������܂����B
'		MainStatusMsg=#113 '�����^�]��
'		MainStatusMsg=#120 '��~������
'		MainStatusMsg=#121 '��~�������B���ы@���Ή\�ł��B
'----------------------------------------------------------------------------------
'	�O�����H��			
'	�O�����H��StatusMsg=0
'		�O�����H��StatusMsg=#20	'	�O������
'		�O�����H��StatusMsg=#21	'	�Z�В�
'		�O�����H��StatusMsg=#22	'	�����^�]��
'		�O�����H��StatusMsg=#23	'	��~������
'		�O�����H��StatusMsg=#24	'	��~��
'----------------------------------------------------------------------------------
'	�Z�Ѓ^���N		'	
'	�Z�Ѓ^���NA���j�b�gStatusMsg=0
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#10	'	������
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#11	'	���Ē�
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#12	'	�Z�В�
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#13	'	�z�Ē�
'		�Z�Ѓ^���NA���j�b�gStatusMsg=#14	'	�z�Ċ���
'	�Z�Ѓ^���NB���j�b�gStatusMsg=0
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#10	'	������
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#11	'	���Ē�
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#12	'	�Z�В�
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#13	'	�z�Ē�
'		�Z�Ѓ^���NB���j�b�gStatusMsg=#14	'	�z�Ċ���
'----------------------------------------------------------------------------------
'	�Ȃ炵�@		'
'	�Ȃ炵���uStatusMsg=0
'		�Ȃ炵���uStatusMsg=#30	'	�ҋ@��
'		�Ȃ炵���uStatusMsg=#31	'	�Ȃ炵��
'----------------------------------------------------------------------------------
'	�t�^�킹
'	�W�킹���j�b�gStatusMsg=0
'		�W�킹���j�b�gStatusMsg=#40	'	�t�^��蒆
'		�W�킹���j�b�gStatusMsg=#41	'	�t�^�킹�ҋ@���i�t�^�������Ă����ԁj
'		�W�킹���j�b�gStatusMsg=#42	'	�t�^�u����
'		�W�킹���j�b�gStatusMsg=#43	'	�ҋ@���i�t�^�������Ă��Ȃ��j
'----------------------------------------------------------------------------------
'	�t�^���
'	�W��胆�j�b�gStatusMsg=0
'		�W��胆�j�b�gStatusMsg=#45	'	�ҋ@��
'		�W��胆�j�b�gStatusMsg=#46	'	�t�^��蒆
'		�W��胆�j�b�gStatusMsg=#47	'	�t�^�u����
'----------------------------------------------------------------------------------
'	���ъ��m�F���u
'	���͂񌟒mStatusMsg=0
'		���͂񌟒mStatusMsg=#50	'	�ҋ@��
'		���͂񌟒mStatusMsg=#51	'	�m�F��
'		���͂񌟒mStatusMsg=#56	'	����
'		���͂񌟒mStatusMsg=#57	'	�Ĕъ�
'----------------------------------------------------------------------------------
'	�����o�L���[�}
'	�o�L���[�����j�b�gStatusMsg=0
'		�o�L���[�����j�b�gStatusMsg=#60	'	�ҋ@��
'		�o�L���[�����j�b�gStatusMsg=#61	'	�z����
'----------------------------------------------------------------------------------
'	�����@
'	��򃆃j�b�gStatusMsg=0
'		��򃆃j�b�gStatusMsg=#70	'	�ҋ@��
'		��򃆃j�b�gStatusMsg=#71	'	������
'		��򃆃j�b�gStatusMsg=#72	'	�^�]��
'----------------------------------------------------------------------------------

System�ύX�ʒm=��򃆃j�b�g1�֎~ or ��򃆃j�b�g2�֎~ or ��򃆃j�b�g3�֎~ or ��򃆃j�b�g4�֎~ or ��򃆃j�b�g5�֎~  
System�ύX�ʒm=System�ύX�ʒm or not(�v�����j�b�g����) or not(�Ȃ炵���u����) or not(�W�킹���j�b�g����) or not(�W��胆�j�b�g����)

'----------------------------------------------------------------------------------

IND_�z�ď���=IND_�z�ď���
IND_�z�Ē�=IND_�z�Ē�
IND_���ђ�=IND_���ђ�
IND_���ъ���=IND_���ъ���
IND_��~�ҋ@=IND_��~�ҋ@
IND_��򏀔���=IND_��򏀔���

'----------------------------------------------------------------------------------

if PH25_�����m and StageDevice19=$9000 then
	IND_StageDevice19=ON
else
	IND_StageDevice19=OFF
end if

if PH27_�����m and StageDevice20=$9000 then
	IND_StageDevice20=ON
else
	IND_StageDevice20=OFF
end if

if PH29_�����m and StageDevice21=$9000 then
	IND_StageDevice21=ON
else
	IND_StageDevice21=OFF
end if

if PH31_�����m and StageDevice22=$9000 then
	IND_StageDevice22=ON
else
	IND_StageDevice22=OFF
end if

if PH32_�����m and StageDevice23=$9000 then
	IND_StageDevice23=ON
else
	IND_StageDevice23=OFF
end if

if PH34_�����m and StageDevice24=$9000 then
	IND_StageDevice24=ON
else
	IND_StageDevice24=OFF
end if

if PH36_�����m and StageDevice25=$9000 then
	IND_StageDevice25=ON
else
	IND_StageDevice25=OFF
end if

if PH38_�����m and StageDevice26=$9000 then
	IND_StageDevice26=ON
else
	IND_StageDevice26=OFF
end if

IND_StageDevice27=OFF
IND_StageDevice28=OFF


'----------------------------------------------------------------------------------
'�����Ė��� 

	pnlPBL�����ėLA=pnlPB�����ėLA and CR2006
	pnlPBL�����Ė���A=pnlPB�����Ė���A and CR2006
	
	pnlPBL�����ėLB=pnlPB�����ėLB and CR2006
	pnlPBL�����Ė���B=pnlPB�����Ė���B and CR2006

'----------------------------------------------------------------------------------
' �ُ��ʂ���߂�Ƃ��ɃA���[���m�莞�̃r�b�g���N���A����

if INDalm�r�b�g�N���A then
 FMOV(0,R90000.U,58)  'R90000 ~ R95715
end if

if ldp(�o�L���[���֎~) then
	�����o�L���[��=OFF
else if ldp(�����o�L���[��) then
	�o�L���[���֎~=OFF
end if 

if ldp(���]�ق����@A�֎~) then
	�������]A=OFF
else if ldp(�������]A) then
	���]�ق����@A�֎~=OFF
end if

if ldp(���]�ق����@B�֎~) then
	�������]B=OFF
else if ldp(�������]B) then
	���]�ق����@B�֎~=OFF
end if
'----------------------------------------------------------------------------------
'�^�]���j�^ �R���x�A  pnlXSWxxx
INDpnlPBXSW=pnlPBXSW11_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW12_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW13_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW14_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW15_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW16_���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW17_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW18_���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW19_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW20_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW21_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW22_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW74_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW75_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW37_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW38_���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW33_�N�����v���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW34_�N�����v�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW29_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW30_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW35_�N�����v���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW36_�N�����v�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW31_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW32_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW47_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW48_���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW45_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW46_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW71_�o�L���[�}���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW72_�o�L���[�}���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW49_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW50_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW53_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW54_���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW51_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW52_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW63_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW64_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW65_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW66_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW67_���t�g���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW68_���t�g�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW69_�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW70_�X�g�b�p�㏸�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW85_���t�^�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW90_���t�^�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW95_���t�^�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW100_���t�^�X�g�b�p���~�[
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW105_���t�^�X�g�b�p���~�[
'�^�]���j�^ �R���x�A  pnlXSWxxx + �R���x�A�֎~�ӏ�
INDpnlPBXSW�֎~ = INDpnlPBXSW 
INDpnlPBXSW�֎~ = INDpnlPBXSW�֎~ or pnlPBLS5_�󊘔��]���_�ʒu
INDpnlPBXSW�֎~ = INDpnlPBXSW�֎~ or pnlPBLS6_�󊘔��]���]�ʒu
INDpnlPBXSW�֎~ = INDpnlPBXSW�֎~ or pnlPBLS7_�����]�@���_�ʒu
INDpnlPBXSW�֎~ = INDpnlPBXSW�֎~ or pnlPBLS8_�����]�@���]�ʒu
INDpnlPBXSW�֎~ = INDpnlPBXSW�֎~ or ������R���x�A�֎~
INDpnlPBXSW�֎~ = INDpnlPBXSW�֎~ or �ނ炵������R���x�A�֎~
INDpnlPBXSW�֎~ = INDpnlPBXSW�֎~ or �������֎~
'�^�]���j�^ ���j�b�g pnlXSWxxx
INDpnlPBXSWUnit=pnlPBXSW1_�[�U�o���u�JA
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW2_�[�U�o���u��A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW3_���؂�V���b�^�[�JA
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW4_���؂�V���b�^�[��A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW5_�[�U�o���u�JB
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW6_�[�U�o���u��B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW7_���؂�V���b�^�[�JB
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW8_���؂�V���b�^�[��B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW9_���Đ؊�A��
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW10_���Đ؊�B��
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW23_�Ȃ炵��ޒ[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW24_�Ȃ炵�O�i�[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW25_�Ȃ炵�㏸�[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW26_�Ȃ炵���~�[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW27_�Ȃ炵��ޒ[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW28_�Ȃ炵�O�i�[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW111_���ʒu�E��ޒ[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW112_���ʒu����ޒ[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW39_�V�����_�㏸�[A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW40_�V�����_���~�[A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW41_�V�����_�㏸�[B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW42_�V�����_���~�[B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW43_�N�����v
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW44_�A���N�����v
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW55_�V�����_�㏸�[A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW56_�V�����_���~�[A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW57_�V�����_�㏸�[B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW58_�V�����_���~�[B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW59_�A���N�����v
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW60_�N�����v
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW73_�V�����_�㏸�[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW80_�V�����_���~�[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW61_�V�����_�㏸�[
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW62_�V�����_���~�[
'�I�[�g�X�C�b�`���j�����Ă��܂��B�T�[�r�X�}���ɘA�����Ă��������B
MSGXSWl�j�� = INDpnlPBXSW or INDpnlPBXSWUnit
