'���[�N���O�t�@�C��
'
'-----------------------------------------------------------------------------------------------------------------------------
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
'FileErr	�r�b�g[2]
'WriteFileName	������[40]
'WriteSec	2���[�h�����Ȃ�����
'WriteSecStr	������[20]
'WriteStatstr	������[20]
'WriteStepstr	������[500]
'WriteStr	������[600]
'realFileErr	�r�b�g[2]
'realFilewritestep	1���[�h�����Ȃ�����
'realWriteFileName	������[40]
'realWriteSec	2���[�h�����Ȃ�����
'realWriteSecStr	������[20]
'realWriteStatstr	������[200]
'realWriteStepstr	������[300]
'realWriteStr	������[600]
'real�C���^�[�o��	�^�C�}
'���]�c��	1���[�h�����Ȃ�����
'-----------------------------------------------------------------------------------------------------------------------------
'�y ���������� �z
if CR2008 then '�d��ON������������
	wFilewritestep=0
	realFilewritestep=0
end if
'-----------------------------------------------------------------------------------------------------------------------------
if ldp(��������ErrStep>0 or OtherErrStep>0 or �v��ErrStep>0) then
	WriteStatstr="�G���[����"
	wFilewritestep=1

else if ldp(�O�����H��AutoRun) then
	WriteStatstr="���ĊJ�n"
	wFilewritestep=1

else if ldp(�O��������) then
	WriteStatstr="���Ċ���"
	wFilewritestep=1

else if ldp(IND_�z�Ē� and (�Z�Ѓ^���NA���j�b�g���� or �Z�Ѓ^���NB���j�b�g����) ) then
	WriteStatstr="�z�ĊJ�n"
	wFilewritestep=1

else if ldp(�z�ďI���t���O) then 
	WriteStatstr="�z�ďI��"
	wFilewritestep=1

else if ldp(IND_���ъ���) then
	WriteStatstr="���ъ���"
	wFilewritestep=1
end if

'-----------------------------------------------------------------------------------------------------------------------------
'���Y���t�@�C��������

	select case wFilewritestep
	'----------------------------------------------------------------------
	case 1
		MMKDIR("UserDoc",FileErr)
		INC(wFilewritestep)

	case 2
		if FileErr[0] then '����
			INC(wFilewritestep)
		end if
	
	case 3
		if FileErr[1] then '�ُ�I��
		end if
		INC(wFilewritestep)

	
	'----------------------------------------------------------------------
	case 4
		'-------------------------------
		'�^�]���
		'�C�x���g�ɂ��ݒ�ς�
		'-------------------------------
		'���Y���
		WriteStepstr="�A�C�e��"+","+EM4001.T+","
		WriteStepstr=WriteStepstr+"�z�đ���"+","+DASC(DM_�z�đ���.U,1)+","
		WriteStepstr=WriteStepstr+"�ݒ萅��"+","+DASC(DM_�ݒ萅�ʊ�l.U,1)+","
		WriteStepstr=WriteStepstr+"���ʕ␳�l"+","+DASC(DM_���ʕ␳�l,1)+"," '+/- ����
		WriteStepstr=WriteStepstr+"A�^���N���Đݒ�l" +","+ DASC(DM_A�^���N�ݒ�l.U,1)+","
		WriteStepstr=WriteStepstr+"A�^���N���Č��ݒl" +","+ DASC(DM_A�^���N���Č��ݒl.U,1)+","
		WriteStepstr=WriteStepstr+"B�^���N���Đݒ�l" +","+ DASC(DM_B�^���N�ݒ�l.U,1)+","
		WriteStepstr=WriteStepstr+"B�^���N���Č��ݒl" +","+ DASC(DM_B�^���N���Č��ݒl.U,1)+","
		WriteStepstr=WriteStepstr+"���]��"+","+DASC(DM_�r�o����.U,1)
		'----------------------------------------------------------------------
		'�t�@�C�������ݕ�����		
		WriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '���t
		WriteStr.T=WriteStr.T+WriteStatstr+"," '�^�]���
		WriteStr.T=WriteStr.T+WriteStepstr ''���Y���
		'-------------------------------
		WriteStr.T=WriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'�t�@�C��������
		WriteFileName.T="UserDoc\"+"���Y���"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" '�t�@�C����
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)

		INC(wFilewritestep)
	
	case 5
		if FileErr[0] then '����
			INC(wFilewritestep)
		end if
	
	case 6
		if FileErr[1] then '�ُ�I��
		end if
		INC(wFilewritestep)

	case 7
		
		wFilewritestep=0
		
	end select

'-----------------------------------------------------------------------------------------------------------------------------
'���ݏ��t�@�C�������� 

if 0 then 'SD�̑ϋv���ێ��̂��ߋx�~��
	tmr(CM703>=5 and CM703<12,real�C���^�[�o��,200) '5:00 ~ 11:59 �܂ŏ�����

	if ldp(real�C���^�[�o��.B) then
		res(real�C���^�[�o��)
		realFilewritestep=1
	end if
end if

	'---------------------------------------
	if ��������ErrStep>0 or OtherErrStep>0 or �v��ErrStep>0 then
		realWriteStatstr="�G���[������"+","
	else if EmgFlg then
		realWriteStatstr="����~��"+","	
	else
		realWriteStatstr="�G���[����"+","
	end if
	'---------------------------------------
	if �O�����H��AutoRun then
		realWriteStatstr=realWriteStatstr+"���Ē�"+","
	else
		realWriteStatstr=realWriteStatstr+"���Ē�~��"+","
	end if
	'---------------------------------------
	if ��������AutoRun then
		realWriteStatstr=realWriteStatstr+"�R���x�A�^�]��"+","
	else
		realWriteStatstr=realWriteStatstr+"�R���x�A��~��"+","
	end if	
	'---------------------------------------
	���]�c��=DM_�z�đ���-DM_�r�o����
	
	if �^�]������ then	
		realWriteStatstr=realWriteStatstr+"�^�]������"+","
	else if IND_�z�Ē� then
		realWriteStatstr=realWriteStatstr+"�z�Ē�"+","
	else if IND_���ђ� then
		realWriteStatstr=realWriteStatstr+"���ђ�"+","
	else if not(IND_�z�Ē�) and not(IND_���ђ�) and not(IND_���ъ���) and ���]�c��>0 then
		realWriteStatstr=realWriteStatstr+"���]������"+","
	else if IND_���ъ��� then
		realWriteStatstr=realWriteStatstr+"���ъ���"+","
	else
		realWriteStatstr=realWriteStatstr+"�H������"+","	
	end if
	'---------------------------------------
	if ��������AutoMode then
		realWriteStatstr=realWriteStatstr+"����"+","
	else
		realWriteStatstr=realWriteStatstr+"�蓮"+","
	end if
	'---------------------------------------
	if �e�X�g�^�] then
		realWriteStatstr=realWriteStatstr+"�e�X�g�^�]=ON
	else
		realWriteStatstr=realWriteStatstr+"�e�X�g�^�]=OFF"
	end if
	
	
	'----------------------------------------------------------------------
	select case realFilewritestep

	case 1
		MDEL("���A���^�C�����.CSV",realFileErr)
		INC(realFilewritestep)

	case 2
		if realFileErr[0] then '����
			INC(realFilewritestep)
		end if
	
	case 3
		if realFileErr[1] then '�ُ�I��
		end if
		INC(realFilewritestep)

	
	'----------------------------------------------------------------------
	case 4
		'-------------------------------
		'���Y���
		realWriteStepstr=realWriteStepstr+"�z�đ���"+","+DASC(DM_�z�đ���.U,1)+","
		realWriteStepstr=realWriteStepstr+"�ݒ萅��"+","+DASC(DM_�ݒ萅�ʊ�l.U,1)+","
		realWriteStepstr=realWriteStepstr+"���ʕ␳�l"+","+DASC(DM_���ʕ␳�l,1)+"," '+/- ����
		realWriteStepstr="A�^���N���Đݒ�l" +","+ DASC(DM_A�^���N�ݒ�l.U,1)+","
		realWriteStepstr=realWriteStepstr+"A�^���N���Č��ݒl" +","+ DASC(DM_A�^���N���Č��ݒl.U,1)+","
		realWriteStepstr=realWriteStepstr+"B�^���N���Đݒ�l" +","+ DASC(DM_B�^���N�ݒ�l.U,1)+","
		realWriteStepstr=realWriteStepstr+"B�^���N���Č��ݒl" +","+ DASC(DM_B�^���N���Č��ݒl.U,1)+","
		realWriteStepstr=realWriteStepstr+"���]��"+","+DASC(DM_�r�o����.U,1)
		'----------------------------------------------------------------------
		'�t�@�C�������ݕ�����		
		realWriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '���t
		realWriteStr.T=realWriteStr.T+realWriteStatstr+"," '�^�]���
		realWriteStr.T=realWriteStr.T+realWriteStepstr '���Y���
		'-------------------------------
		realWriteStr.T=realWriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'�t�@�C��������
		realWriteFileName.T="���A���^�C�����.CSV" '�t�@�C����
		MPRINT(realWriteFileName.T,realWriteStr.T,realFileErr)

		INC(realFilewritestep)
	
	case 5
		if realFileErr[0] then '����
			INC(realFilewritestep)
		end if
	
	case 6
		if realFileErr[1] then '�ُ�I��
		end if
		INC(realFilewritestep)

	case 7
		realFilewritestep=0	
	end select

'-----------------------------------------------------------------------------------------------------------------------------
