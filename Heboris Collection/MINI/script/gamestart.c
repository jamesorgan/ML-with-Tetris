//������������������������������������������������������������������������������
//
//    HEBORIS [�w�{���X] 2001 Ver1.60��1 / 2000.11.05 (Sun) �` 2001.07.29 (Sun)
//
//                         (c) 1998-2001 Kenji Hoshimoto
//
//   Version 1.60 (02/03/31) ���ړ����C���A�t�B�[���h�̔w�i��������悤��
//                           �u���b�N���ˑR������o�O���C��
//   Version 1.51 (01/12/04) �����Ă��܂��o�O���C��
//   Version 1.50 (01/11/26) �����L���O�@�\�ǉ� (�C���^�[�l�b�g�����L���O�Ή�)
//                           ���v���C�E�|�[�X�ENEXT�B���@�\�ǉ� �f����ʒǉ�
//                           �S�����{�[�i�X�ǉ� �f�r�����[�h�����������ȒP��
//                           ���̑������ς�
//
//������������������������������������������������������������������������������
// TODO: �����ǂ����悤���ȁ`
/*
	�X�V������docs\changelog.txt�Ɉړ����܂����B
*/

//������������������������������������������������������������������������������
//   �O�����C�u�����̃C���|�[�g
//������������������������������������������������������������������������������
	import	"string.dll"				// �����񃉃C�u�����̃C���|�[�g
	import	"time.dll"					// ���ԃ��C�u�����̃C���|�[�g
	import	"ygs2kTCP.dll"				// �l�b�g���[�N�ʐM���C�u�����̃C���|�[�g

//������������������������������������������������������������������������������
//   �O���[�o���ϐ��̒�`
//������������������������������������������������������������������������������
int		saveBuf[150000];				// �Z�[�u�p�o�b�t�@
int		replayData[60 * 60 * 30 * 2];	// ���v���C�ۑ��p�f�[�^ (�ő�30���܂�) pl * 108000 + i

int		count;							// �O���[�o���J�E���^ (�t���[���P�ʁA65535�܂�)

int		disp_blkline[2];				// �u���b�N�̘g����\�����邩�ǂ����̃t���O

int		stat[2], statc[10*2];			// ���݂̃X�e�[�^�X�ƃp�����[�^ no + pl * 10

int		mp[2], mpc[2], mps[2 * 2];		// �O��̃p�b�h�̓��͓��e�Ǝ���
int		mp2[2], mpc2[2];				//hoge �O��̃p�b�h�̓��͓��e�Ǝ���(�㉺�L�[�o�[�W����)

int		tame1 = 25;						//hoge ���E�̓�����ςȂ��ō����ړ�����܂ł̎���
int		tame2 = 3;						//hoge �����ړ��̑���(���Ȃ��قǑ���)�B
int		tame3 = 25;						//hoge ���̏㉺��
int		tame4 = 3;						//hoge ���̏㉺��

int		flag;							// 1�ȏ�Ń^�C�g���ɖ߂�

int		pinch[2];						// �s���`���ǂ���

int		fast;							// ������t���O

int		playback = 0;					// ���v���C����?
int		demo = 0;						// �f�����[�h��?
int		replayauto = 0;					// ���v���C�������c�t���O�i0�ɂ���Ǝ蓮���c�j

int		pause[2];						// �|�[�Y���Ă邩�[��!?

int		effectspeed[2];					// �G�t�F�N�g�̃X�s�[�h

int		gameMode[2] = {-2, -2};			// ���݂̃��[�h
int		rots[2] = {-2, -2};				// ���݂̃��[��

int		lastmode = 0;					// �Ō�ɑI�񂾃��[�h
int		lastrots = 0;					// �Ō�ɑI�񂾃��[��

int		replayexist[40];				// ���v���C�f�[�^�����݂��邩�ǂ����̃t���O

int		blkshadow_direction[2];			// �u���b�N�̉e�̕���

int		maxPlay = 0;					// �����Ƀv���C�ł���l��

// �t�B�[���h�f�[�^
int		fld[20 * 42 * 2];				// �t�B�[���h�̏��  x + y * fldsizex + player * (fldsizex * fldsizey)
int		fldt[20 * 42 * 2];				// �t�B�[���h�^�C�}�[
int		fldo[20 * 42 * 2];				// �t�B�[���h����c�l
int		fldl[20 * 42 * 2];				// �t�B�[���h�̃u���b�N�̌q����
int		fldi[20 * 42 * 2];				// �t�B�[���h�A�C�e��

// �t�B�[���h�o�b�t�@�i�~���[�̉��o�Ɏg�p�j
int		fldbuf[20 * 42 * 2];			// �t�B�[���h�̏��  x + y * fldsizex + player * (fldsizex * fldsizey)
int		fldtbuf[20 * 42 * 2];			// �t�B�[���h�^�C�}�[
int		fldobuf[20 * 42 * 2];			// �t�B�[���h����c�l
int		fldlbuf[20 * 42 * 2];			// �t�B�[���h�̃u���b�N�̌q����
int		fldibuf[20 * 42 * 2];			// �t�B�[���h�A�C�e��

// �t�B�[���h�T�C�Y
int		fldsizex;						// �t�B�[���h�̕��i0�`20�j
int		fldsizey;						// �t�B�[���h�̍����i0�`42�j

// �t�B�[���h�g
int		framecolor[2];					// �t�B�[���h�g�̐F
int		frame_decoration[2];			// �t�B�[���h�g�ɏ����\��
int		field_spin[2];					// �t�B�[���h�g�̉�]�󋵁i-1�܂���20�F��]���ĂȂ��j

// ���݂̃u���b�N
int		blk[2];							// �������Ă���u���b�N
int		bx[2], by[2], rt[2];			// �u���b�N�̍��W�ƌ���
int		bs[2], bk[2];					// �u���b�N�̎��R�����Ƃ������̃^�C��

int		current_color[4 * 2];			// ���݂̃u���b�N�̐F�i�Œ��j
int		current_color_m[4 * 2];			// ���݂̃u���b�N�̐F�i�ړ����j
int		current_oblk[2];				// ���݂̃u���b�N������c�l���ǂ����ioblk��o��over1000�̈Ӗ��j
int		current_item[2];				// ���݂̃A�C�e��

int		last_command[2];				// �Ō�̑���i0=�ړ�/���� 1=�󒆂ŉ�] 2=�󒆂ŕǏR���]
										//             3=�ڒn��Ԃŉ�] 4=�ڒn��ԂŕǏR���]�j
int		rotcount[2];					// �ڒn��Ԃŉ�]������
int		movecount[2];					// �ڒn��Ԃňړ�������
int		kickc[2];						// �ǏR��J�E���^
int		kicktype[2];					// �ǏR��^�C�v

int		ghost[2];						// �S�[�X�gON/OFF

int		bdowncnt[2];					// �u���b�N��u������
int		brotcount[2];					// �u���b�N���񂵂���

int		bactivetime[2];					// �u���b�N�𑀍삵�Ă��鎞��

int		bfallflag[2];					// �u���b�N���i�����痎�����t���O
int		bfallcount[2];					// �u���b�N���i�����痎������

int		spawntype[2];					// �u���b�N�̏o���ʒu�i0=�g�� 1=�g�O�j

// NEXT�u���b�N
int		nextb[1400 * 2];				// ���̃u���b�N
int		nextc[2];						// ���ɍ~��u���b�N�J�E���^
int		nextc_max[2];					// nextc�̍ő�

int		next_color[6 * 4 * 2];			// ���̃u���b�N�̐F
int		next_oblk[6 * 2];				// ���̃u���b�N������c�l���ǂ���
int		next_item[6 * 2];				// ���̃u���b�N���A�C�e�����ǂ���

int		next_offset[7 * 2];				// NEXT�u���b�N��Y���W�ʒu�̃I�t�Z�b�g�iNEXT1�j
int		next_s_offset[7 * 2];			// NEXT�u���b�N��Y���W�ʒu�̃I�t�Z�b�g�iNEXT2�`�j
int		ndelay[2];						// NEXT�x���p

int		oblk_spawn[2];					// ����c�l�o��t���O
int		oblk_bg[2];						// ����c�l�o�ꒆ�̔w�i�i0=�Ȃ� 1=�� 2=���j

int		hnext[2];						// ��������NEXT�u���b�N�̐�

str		userNextBlockList = "0123456";	// �J�X�^���c�����X�g (0=I 1=L 2=O 3=Z 4=T 5=J 6=S)

int		multicolor_enable[2];			// �}���`�J���[�u���b�N�����ꍞ�ނ��ǂ���
int		multicolor_ratio[2];			// �}���`�J���[�u���b�N�����ꍞ�ފm��

// �z�[���h
int		hold[2];						// ���݃z�[���h�ɓ����Ă���u���b�N�i-1=�Ȃ��j
int		dhold[2];						// �z�[���h�����t���O
int		hold_count[2];					// �z�[���h��

int		hold_color[4 * 2];				// �z�[���h�u���b�N�̐F
int		hold_oblk[2];					// �z�[���h�u���b�N������c�l���ǂ���
int		hold_item[2];					// �z�[���h�u���b�N���A�C�e�����ǂ���

// �n�[�h�h���b�v�^�\�t�g�h���b�v
int		harddrop[2];					// �n�[�h�h���b�v�g�p�t���O
int		softdrop[2];					// �\�t�g�h���b�v�g�p�t���O
int		up_flag[2];						// �����g���܂킵�h�~�t���O
int		down_flag[2];					// ������g���܂킵�h�~�t���O
int		bk_D[2];						// DRS���\�t�g�h���b�v�p ������ɂ��Œ莞��
int		softd_dropflag[2];				// �\�t�g�h���b�v�Ńu���b�N����������1�ɂȂ�
int		softd_score[2];					// �\�t�g�h���b�v�œ���_��

// �A�C�e��
int		item_waiting[2];				// �����҂��^�������A�C�e��
int		enable_item_hold[2];			// �A�C�e�����z�[���h�\���ǂ���
int		item_name[2];					// �t�B�[���h�E��ɕ\������A�C�e����
int		item_coming[2];					// NEXT�̍Ōォ��o������A�C�e��

int		fldisno = 44;					// fldi�ɂ����ăX�N�E�F�A�p�̉摜������ꏊ(�ꏊ�̃J�E���g�́����30�Ԗ�)
int		fldigsno = 45;					// fldi�ɂ�����GOLDEN�X�N�E�F�A�p�̉摜������ꏊ
int		fldihardno = 43;				// fldi�ɂ����ăn�[�h�u���b�N�̉摜������ꏊ

// ���C������
int		erase[42 * 2];					// �������u���b�N
int		line_count[4 * 2];				// ���C��������
int		are_skipflag[2];				// �������Ԓ���ARE�X�L�b�v�g�p�t���O
int		show_all_break_effect[2];		// �S�Ẵu���b�N�̏����G�t�F�N�g��\�����邩�ǂ���
int		perase_show_bonus[2];			// �v���`�i�u���b�N��������+1��\�����邩�ǂ���

// ���x
int		wait1[2], wait2[2];				// �Œ聨���E���Ŏ��̑҂�����
int		wait3[2], waitt[2];				// �ݒu����Œ�܂ł̃^�C���E�����ߎ���
int		wait4[2];						// �ݒu����Œ�܂ł̃^�C���i�i��������j-1��wait3���g�p
int		wait5[2];						// ���Ŏ��̑҂����� -1��wait2���g�p
int		sp[2];							// ���݂̗����X�s�[�h
int		speedtype[2];					// �����X�s�[�h�̎��

// �R���{
int		enable_combo[2];				// �R���{���L�����ǂ���
int		combo[2];						// �R���{
int		combo2[2];						// 1���C�������ő����Ȃ��R���{
int		combo3[2];						// 1���C�������œr�؂��R���{
int		hebocombo[2];					// �w�{���X����̃R���{

// �X�R�A�v�Z
int		sdrop[2];						// �X�R�A�v�Z�p�i�n�[�h�h���b�v�j
int		qdrop[2];						// �X�R�A�v�Z�p�i�\�t�g�h���b�v�j
int		cmbpts[2];						// �X�R�A�v�Z�p�i�R���{�j
int		qput[2];						// �X�R�A�v�Z�p�i�����Ńu���b�N���Œ肳�������ǂ����j

// BIG���[�h
int		IsBig[2];						// �r�b�O���[�h���ǂ���
int		BigMove[2];						// �r�b�O���̉��ړ��P��

// READY��GO�̑҂�����
int		ready_start[2];					// ready�J�n
int		ready_end[2];					// ready�I��
int		go_start[2];					// go�J�n
int		go_end[2];						// go�I��

int		n_ready_start = 0;				// �f�t�H���g ready�J�n
int		n_ready_end = 50;				// �f�t�H���g ready�I��
int		n_go_start = 55;				// �f�t�H���g go�J�n
int		n_go_end = 100;					// �f�t�H���g go�I��

int		ready_count[2];					// READY��GO��\��������
int		nextskip[2];					// �c���X�L�b�v

// ����オ��
int		upLines[2];						// �㏸���Ă��܂����C����
int		fldu[20 * 42 * 2];				// ����オ��t�B�[���h�i����オ��u���b�N�̌`����L���j

// T-SPIN
int		tspin_type[2];					// T-SPIN�̎��
int		tspin_flag[2];					// T-SPIN�������ǂ���

// BACK TO BACK
int		b_to_b_type[2];					// BACK TO BACK�̎�ށi0=�Ȃ� 1=�ʏ� 2=�w�{���X�̂� 3=T-SPIN�̂݁j
int		b_to_b_count[2];				// BACK TO BACK�̘A����

// �^�C��
int		gameTimer[2], timeOn[2];		// �Q�[���J�n����̌o�ߎ��� (1/60�b�P��)�A�L��?
int		recTimer[2], onRecord[2];		// �Q�[���J�n����̖{���̌o�ߎ��ԁi���v���C�p�j�A�L��?
int		replay_timer[40];				// ���v���C�f�[�^�̃^�C��

// �G���f�B���O
int		ending[2];						// �G���f�B���O�����ǂ���
int		edrec[2];						// �G���f�B���O�o�ߎ���
int		fastroll[2];					// 1�̏ꍇ�͍������[��
int		ending_timeOn[2];				// �G���f�B���O�^�C�}�[���L�����ǂ���
int		staff_c[2];						// �X�^�b�t���[���J�E���^
int		endtime[2];						// �X�^�b�t���[���o�ߎ���
int		staff_type[2];					// �X�^�b�t���[���̉摜�̎�ށi0��1�j

// ����
int		randseed[2];					// �[�������V�[�h
int		firstseed[2];					// �ŏ��̗����V�[�h

// HIDDEN�p�ϐ�
int		hidden[2], hiddentm[2], hiddeny[2], hiddenti[2], hiddenc[2];
int		shadowtime[2];					// �u���b�N�������鎞�ԁiHIDDEN LV8�j

// �L�[�ݒ�
int		keyAssign[10 * 2];				// �L�[�{�[�h�̃{�^�����蓖��
int		joykeyAssign[10 * 2];			// �W���C�X�e�B�b�N�̃{�^�����蓖��
int		joykeyButtonNum = 16;			// �W���C�X�e�B�b�N�̃{�^����

int		pause_key[2];					// �|�[�Y�L�[
int		joy_pause_key[2];				// �|�[�Y�L�[�i�W���C�X�e�B�b�N�j
int		giveup_key[2];					// �̂ăQ�[�L�[
int		joy_giveup_key[2];				// �̂ăQ�[�L�[�i�W���C�X�e�B�b�N�j
int		ss_key[2];						// �X�N���[���V���b�g�L�[
int		joy_ss_key[2];					// �X�N���[���V���b�g�L�[�i�W���C�X�e�B�b�N�j
int		extra_key[2];					// EXTRA�L�[
int		joy_extra_key[2];				// EXTRA�L�[�i�W���C�X�e�B�b�N�j
int		fps_plus_key[2];				// FPS+1
int		joy_fps_plus_key[2];			// FPS+1�i�W���C�X�e�B�b�N�j
int		fps_minus_key[2];				// FPS-1
int		joy_fps_minus_key[2];			// FPS-1�i�W���C�X�e�B�b�N�j
int		retry_key[2];					// ���g���C�L�[
int		joy_retry_key[2];				// ���g���C�L�[�i�W���C�X�e�B�b�N�j

int		key_enter = 0x1C;				// ENTER�L�[�̃L�[�R�[�h
int		key_del = 0xD3;					// DELETE�L�[�̃L�[�R�[�h
int		key_bs = 0x0E;					// BACKSPACE�L�[�̃L�[�R�[�h

int		ssc = 0;						// �X�N���[���V���b�g�J�E���^
int		fps_plus_mpc[2];				// FPS+1�̉������ςȂ�����
int		fps_minus_mpc[2];				// FPS-1�̉������ςȂ�����

// ���o�p�ϐ�
int		obj[100], objx[100], objy[100], objv[100], objw[100], objj[100], objc[100], obja[100], objp[100];

// �w�i
int		backno = 0;						// ���݂̔w�i
int		bgfadesw = 0;					// �w�i�t�F�[�h�X�C�b�`
int		bgfadelv = 0;					// �w�i�t�F�[�h���x��
int		bgfadebg = 0;					// �w�i�t�F�[�h��ɐ؂�ւ���w�i
int		firstbackno = 0;				// �Q�[���X�^�[�g���̔w�i

// �w�i���[�r�[
int		back_acnt = 0;					// ���݂̃t���[��
int		back_mov_f[21];					// �ő�R�}���i0�ɂ���ƐÎ~��j
int		back_mov_inter[21];				// 1�R�}��\������t���[����

// �Q�[�����[���p
int		blockcolor[7 * 2];				// �u���b�N�̐F
int		blockgraphics[2];				// �u���b�N�̊G��
int		rot_reverse[2];					// ��]�������t�ɂ���

int		lockreset[2];					// �Œ莞�ԃ��Z�b�g�̗L��
int		rotlimit[2];					// �Œ莞�ԃ��Z�b�gON�̂Ƃ��A�ڒn��Ԃŉ�]�ł����
int		movelimit[2];					// �Œ莞�ԃ��Z�b�gON�̂Ƃ��A�ڒn��Ԃňړ��ł����

int		are[2];							// �o���҂����Ԃ̗L���i2=�X�L�b�v����j
int		lockflash[2];					// �u���b�N���Œ肳�����u�ԁA�u���b�N������t���[����

int		lock_up[2];						// ��ő��Œ�
int		lock_down[2];					// ���ő��Œ�

int		softspeed[2];					// ���ł̗������x�i0���珇��0.5�{�A1.0�{�A1.5�{�A2.0�{�A2.5�{�c�j

int		self_lock_sound[2];				// �����ŌŒ肳�����Ƃ���self_lock.wav��炷

int		max_waitt[2];					// �����ߍő�
int		RepeatDelay[2];					// RepeatDelay
int		repeatcount[2];					// counter for RepeatDelay
int		fastlrmove[2];					// ��s���ړ�

int		initial_rotate[2];				// ��s��]
int		initial_hold[2];				// ��s�z�[���h
int		enable_wallkick[2];				// �ǏR��L��?

int		block_init_x_pos[2];			// �o������X���W
int		block_init_y_pos[2];			// �o������Y���W
int		block_init_rt[2];				// �o�����̌���

int		blkDataX[7 * 4 * 4 * 2];		// ���j�b�g���\������u���b�N�̑��΂w�ʒu(7���/4�p�x/4�u���b�N/2�v���C���[)
int		blkDataY[7 * 4 * 4 * 2];		// ���j�b�g���\������u���b�N�̑��΂x�ʒu(7���/4�p�x/4�u���b�N/2�v���C���[)
int		blkDataL[7 * 4 * 4 * 2];		// �u���b�N�̌q����̃f�[�^

// �������͗p
str		RankString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.,- 0123456789<=>?!#$%&'()=pq";

// �~���[�p
int		isfmirror[2];					// �~���[�����t���O
int		fmirror_cnt[2];					// �~���[�p�J�E���^
int		stopmirror_flag[2];				// �~���[��~�t���O

// ���[�����[���p
int		current_rollroll[2];			// ���̃c�������[�����[�����ǂ���
int		rollroll_interval[2];			// �����I�ɉ�]����Ԋu

// CPU
int		cpu_fld[20 * 42];				// ���̒��̃t�B�[���h
int		cpu_best_x[2];					// �őP���X���W
int		cpu_best_y[2];					// �őP���Y���W
int		cpu_best_r[2];					// �őP��̃u���b�N�̕���
int		cpu_best_p[2];					// �őP��̕]���_
int		cpu_hold[2];					// HOLD���邩�ǂ���
int		cpu_ctrl[10 * 2];				// �R���s���[�^�̑�����e
int		cpu_flag[2];					// �R���s���[�^�����삷�邩�ǂ���
int		cpu_speed[2];					// �R���s���[�^�̒x��
int		cpu_frame[2];					// �R���s���[�^���s������܂ł̃t���[����

// �l�b�g�v���C�p
int		netplay = 0;					// �l�b�g�v���C����1
str		networkServerName[10];			// �l�b�g�v���C�̃T�[�o�[��
int		networkServerPort[10];			// �l�b�g�v���C�̃|�[�g�ԍ�
str		networkNickName = "";			// �j�b�N�l�[��
int		networkUseNick = 0;				// �j�b�N�l�[�����g�p���邩�ǂ���

// �O���t�B�b�N�E�T�E���h�ǂݍ��ݗp
str		skin_folder = "default";		// �X�L���̃t�H���_

int		graphics_count = 0;				// �ǂݍ��񂾃O���t�B�b�N�̑���
int		sound_count = 0;				// �ǂݍ��񂾌��ʉ��̑���

int		graphics_plane_type[512];		// �O���t�B�b�N�v���[���̎�ށi0=�Ȃ� 1=�V�X�e���摜 2=�w�i 3=�v���O�C���摜�j
int		sound_plane_type[512];			// �T�E���h�v���[���̎��
										//�i0=�Ȃ� 1=�V�X�e�����ʉ� 2=�V�X�e�����y 3=�v���O�C�����ʉ� 4=�v���O�C�����y�j

// �V�X�e���Ŏg���O���t�B�b�N�v���[���ԍ�
int		sg_blk_n;						// �u���b�N�̃O���t�B�b�N�i�ʏ�j
int		sg_blk_b;						// �u���b�N�̃O���t�B�b�N�i�r�b�O�j
int		sg_blk_s;						// �u���b�N�̃O���t�B�b�N�i�k���j
int		sg_iblk_n;						// ����u���b�N�̃O���t�B�b�N�i�ʏ�j
int		sg_iblk_b;						// ����u���b�N�̃O���t�B�b�N�i�r�b�O�j
int		sg_iblk_s;						// ����u���b�N�̃O���t�B�b�N�i�k���j
int		sg_blkshadow;					// �u���b�N�̉e
int		sg_guide;						// �i�r�Q�[�V�����u���b�N
int		sg_font_n;						// �t�H���g
int		sg_fld;							// �t�B�[���h�摜
int		sg_3d_fld[10];					// 3D�t�B�[���h�摜
int		sg_spr;							// �X�v���C�g
int		sg_title;						// �^�C�g���摜
int		sg_menu_back;					// ���j���[�̔w�i
int		sg_black;						// �^�����摜
int		sg_white;						// �^�����摜
int		sg_sssurface;					// �X�N���[���V���b�g�p�T�[�t�F�C�X
int		sg_2xwindow;					// 2�{�g��p�T�[�t�F�C�X
int		sg_background[21];				// �w�i�i20��back_vs.png�j
int		sg_gametext;					// �Q�[���Ŏg���傫������
int		sg_blkline;						// �u���b�N�̘g��
int		sg_smallfont;					// �������t�H���g
int		sg_topframe;					// ��ʏ㕔�̘g
int		sg_break[8];					// ���C�������G�t�F�N�g
int		sg_perase[7];					// �v���`�i�u���b�N�����G�t�F�N�g
int		sg_itemerase;					// �A�C�e�������G�t�F�N�g
int		sg_medal[2];					// ���_��
int		sg_shootingstar;				// ���ꐯ
int		sg_hanabi[7];					// �ԉ�
int		sg_numberfont;					// �����t�H���g�i��E���j
int		sg_alphabetfont;				// �A���t�@�x�b�g�t�H���g�i�������g�p�\�j
int		sg_bgfade;						// �w�i�t�F�[�h
int		sg_staffroll[2];				// �X�^�b�t���[��
int		sg_grade;						// �i��
int		sg_itemname;					// �A�C�e���̖��O
int		sg_line;						// �����L���O��ʂ̐�

// �V�X�e���Ŏg���T�E���h�v���[���ԍ�
int		se_shaki;
int		se_kon;
int		se_gon;
int		se_kachi;
int		se_rotate;
int		se_move;
int		se_gameover;
int		se_kettei;
int		se_erase[4];
int		se_ready;
int		se_go;
int		se_applause;
int		se_cheer;
int		se_levelup;
int		se_up;
int		se_blockse[7];
int		se_hold;
int		se_lvstop;
int		se_ttclear;
int		se_rankup;
int		se_hanabi;
int		se_pause;
int		se_pinch;
int		se_stgstar;
int		se_movefail;
int		se_rotfail;
int		se_cool;
int		se_regret;
int		se_tspin;
int		se_tserase;
int		se_platinaerase;
int		se_medal;
int		se_hurryup;
int		se_timeover;
int		se_self_lock;
int		se_warning;

// �t�B�[���h�ʒu
int		foffset[2];						// �t�B�[���h�̕\���ʒu�i���j
int		s_foffset = 112;				// SINGLE��p
int		d_foffset[2] = {16, 168};		// DUAL��p
int		v_foffset[2] = {16, 208};		// VERSUS�p

int		fyoffset[2];					// �t�B�[���h�̕\���ʒu�i�c�j
int		s_fyoffset = 0;					// SINGLE��p
int		d_fyoffset[2] = {0, 0};			// DUAL��p
int		v_fyoffset[2] = {0, 0};			// VERSUS�p

int		coffset;						// ����󋵂̕\���ʒu
int		s_coffset = 14;					// SINGLE��p
int		d_coffset = 176;				// DUAL��p

// �T�E���h�֘A
int		se_play[512];					// ���ʉ��Đ��\��t���O
int		sevolume = 0;					// ���ʉ��̉���
int		bgmvolume = 0;					// BGM�̉���
int		bgmtype = 0;					// BGM�̎�ށi0=�Ȃ� 1=WAV 2=MP3�j
int		fadesetting = 100;				// BGM�t�F�[�h�̑���

str		music_file_name[30];			// BGM�̃t�@�C�����iheboris.ini�Ŏw��j
int		bgm_loop_start[30];				// BGM�̃��[�v�J�n�n�_�i-1:�Ȃ��j
int		bgm_loop_end[30];				// BGM�̃��[�v�I���n�_�i�����ɗ�����start�̏��ɖ߂�j
int		bgm_auto_loop[30];				// BGM��ʏ탋�[�v�����邩�ǂ���

int		bgm_plane[30];					// BGM�̃v���[���ԍ�
int		bgmlv = 0;						// ���݂�BGM
int		fadelv = 0;						// BGM�t�F�[�h�A�E�g�p

// �f�o�b�O�֘A
int		debug_enable = 0;				// �f�o�b�O���[�h�t���O
str*	debug_log_system[40];			// �f�o�b�O���O�i�V�X�e���j
str*	debug_log_rule[40];				// �f�o�b�O���O�i���[���j
str*	debug_log_mode[40];				// �f�o�b�O���O�i���[�h�j

// �v���O�C���֘A
str*	plugin_name_rule[200];			// ���[����
str*	plugin_name_mode[200];			// ���[�h��
int		plugin_count_rule = 0;			// ���[���v���O�C���̐�
int		plugin_count_mode = 0;			// ���[�h�v���O�C���̐�

str*	replay_plugin_name_rule[40];	// ���[�����i���v���C�j
str*	replay_plugin_name_mode[40];	// ���[�h���i���v���C�j

// �ݒ�
int		screenMode = 1;					// ��ʃ��[�h
int		systemmem = 0;					// �V�X�e�����������g����?
int		screenColor = 16;				// ��ʂ̐F��
int		useHires = 0;					// 2�{�E�C���h�E���[�h�̎��ɍ��𑜓x�O���t�B�b�N���g�p���邩�ǂ���

int		nextblock = 9;					// NEXT�u���b�N�������@
int		nanameallow = 1;				// �΂ߓ��͖�����
int		fldtr = 32;						// �t�B�[���h�̔w�i�̔������x
int		dispnext = 3;					// NEXT�̐�
int		top_frame = 2;					// ��ʏ㕔��NEXT�g�̎��
int		breaktype = 1;					// ���C�������G�t�F�N�g�̎��
int		downtype = 1;					// �A������ꉺ���ꐧ���̎�ށi0=�Ȃ� 1=20G�݂̂��� 2=��ɂ���j
int		rotate_sound = 0;				// ��]���̗L��
int		move_sound = 0;					// �ړ����̗L��
int		showctrl = 0;					// ����󋵕\���̗L��
int		spawn_y_type = 0;				// �u���b�N�̏o���ʒu�i0=�g�� 1=�g�O�j
int		fonttype = 0;					// �����t�H���g�̎��
int		show_fps = 1;					// FPS�\���̗L���i0=�Ȃ� 1=���� 2=�^�C�g���o�[�j
int		normalfps = 60;					// �W��FPS
int		hide_back = 0;					// �w�i��\�����Ȃ�
int		hold_sound = 0;					// �z�[���h��
int		english = 0;					// �p�ꃂ�[�h
int		disable180 = 0;					// E�{�^�����t��]�{�^���ɂ���
int		enable_sysbgm = 1;				// �^�C�g����ʂƃZ���N�g��ʂ�BGM��L���ɂ���
int		beffect_speed = 0;				// �G�t�F�N�g�X�s�[�h
int		blockshadow = 0;				// �u���b�N�̉e�̗L���������i0=�Ȃ� 1=�� 2=�E�j
int		disable_hold = 0;				// HOLD������

int		dummy = 0;						// �_�~�[�ϐ�

// �o�[�W�����ԍ�
str		versionStr = "HEBORIS U.E. MINI V20 BETA8 (08/04/28)";
int		versionNo = 24;		// �o�[�W�����ԍ�
int		engineVer;			// �Q�[���G���W���ԍ�
int		c_engineVer = 14;	// ���݂̃Q�[���G���W���ԍ�

//������������������������������������������������������������������������������
//   �\�[�X�t�@�C���̃C���|�[�g
//������������������������������������������������������������������������������
	include "script/screencfg.c"	// SCREEN.SAV�̓ǂݏ���
	include "script/flexdraw.c"		// ���𑜓x�Ή��`��֐�
	include "script/loader.c"		// �e��ǂݍ��݊֐�
	include "script/lib.c"			// �Q�[���Ɋւ��邢�낢��Ȋ֐�
	include "script/randomizer.c"	// NEXT�u���b�N��������
	include "script/config.c"		// �ݒ���
	include "script/move.c"			// �ړ�
	include "script/effect.c"		// ���o
	include "script/sound.c"		// ����
	include "script/view.c"			// �\��
	include "script/cpu.c"			// CPU�֘A�̏���
	include "script/replay.c"		// ���v���C
	include "script/debug.c"		// �f�o�b�O�p�֐�

	include "plugins.def"			// �v���O�C��

//������������������������������������������������������������������������������
//   ���C��
//������������������������������������������������������������������������������
void main() {
	int i, bak[2];
	
	// �ݒ��ǂݍ���
	include "heboris.ini"
	include "network.ini"
	
	if(loadGeneralConfigData()) {
		saveGeneralConfigData();
	}
	
	// �O���t�B�b�N����ʉ���ǂݍ���
	initialize();
	
	// �L�[�ݒ��ǂݍ���
	if(loadKeyConfigData()) {
		initKeyConfigData();
		keyconfig_keyboard_setting(0, 1);
	}
	
	if(!english) debugLogSystem("�S��������������");
	else debugLogSystem("Completed all initialization.");
	
	loop {
		title();
		
		flag = 0;
		
		executePlugin(0, 41, &dummy);
		if(maxPlay) executePlugin(1, 41, &dummy);
		
		loop {
			spriteTime();
			KeyInput();
			
			// �w�i
			if(!hide_back) viewBack();
			
			// ���v���C������
			if(playback && !demo && replayauto) {
				playback = 0;
				bak[0] = cpu_flag[0];
				bak[1] = cpu_flag[1];
				cpu_flag[0] = 0;
				cpu_flag[1] = 0;
				
				if(getPushState(0, 4) || getPushState(1, 4)) fast = 5;
				if(!(getPressState(0, 4) || getPressState(1, 4))) fast = 0;
				if(!fast && (getPressState(0, 0) || getPressState(1, 0))) fast = 3;
				if(!fast && (getPressState(0, 1) || getPressState(1, 1))) fast = 1;
				if(getPushState(0, 5) || getPushState(1, 5)) flag = 1;
				if(getPushState(0, 7) || getPushState(1, 7)) {
					PlaySE(se_shaki);
					fast = 0;
					replayauto = 0;
				}
				
				cpu_flag[0] = bak[0];
				cpu_flag[1] = bak[1];
				playback = 1;
			}
			
			// �t�B�[���h�w�i
			viewFieldBackground();
			
			// �X�^�b�t���[��
			if(ending[0] || ending[1]) {
				for(i = 0; i < fast + 1; i++) {
					staffRoll(0);
					if(maxPlay) staffRoll(1);
				}
			}
			
			// �t�B�[���h�\��
			viewField();
			
			// �Q�[������
			for(i = 0; i < fast + 1; i++) {
				playerExecute();
				if(i > 0) objectExecute();
			}
			
			// NEXT��HOLD��\��
			for(i = 0; i <= maxPlay; i++) {
				if(stat[i] != 0) {
					viewNextBlock(i);
					viewHoldBlock(i);
				}
			}
			
			// �t�B�[���h�g��\��
			viewFieldFrame(0, 0);
			if(maxPlay) viewFieldFrame(1, 0);
			
			// ���o����
			objectExecute();
			
			// �X�R�A�\��
			viewScore();
			
			// �|�[�Y�E�̂ăQ�[�Ȃ�
			lastProc();
			
			// flag�ϐ���1��������^�C�g���ɖ߂�
			if(flag > 0) {
				ReleaseAllBGM();
				StopAllWave();
				if(playback) loadGeneralConfigData();
				for(i = 0; i < 64; i++) TextLayerOff(i);
				executePlugin(0, 37, &dummy);
				if(maxPlay) executePlugin(1, 37, &dummy);
				break;
			}
		}
	}
}

//������������������������������������������������������������������������������
//   �^�C�g��
//������������������������������������������������������������������������������
void title() {
	int		player, mode, game, i, democ;
	
	// �����ݒ�
	count = 0;
	democ = 0;
	mode = 0;
	game = 0;
	
	demo = 0;
	playback = 0;
	replayauto = 0;
	
	backno = 0;
	bgfadesw = 0;
	bgfadelv = 0;
	bgfadebg = 0;
	firstbackno = 0;
	
	gameAllInit();
	
	maxPlay = 0;
	setFieldPosition(0, 0);
	setFieldPosition(1, 2);
	
	resetSoundVolume();
	
	engineVer = c_engineVer;
	
	// �l�b�g�v���C����������ؒf
	if(netplay) {
		tcpCleanup();
		netplay = 0;
	}
	
	// FPS�����ɖ߂�
	if((normalfps != 0) && (GetFPS() != normalfps)) SetFPS(normalfps);
	
	// BGM�Đ�
	if(enable_sysbgm) {
		bgmlv = 11;
		PlayBGM();
	}
	
	SetConstParam("EnablePause", 1);	// ��������|�[�Y�L��
	
	// ���[�v�J�n
	loop {
		democ++;
		
		// �L�[����
		spriteTime();
		KeyInput();
		
		// �w�i��`��
		ExBltFast(sg_title, 0, 0);
		
		// ���쌠�\��
		printFontGrid(6, 28, "a 1998-2002 KENJI HOSHIMOTO", 0 );
		
		// �o�[�W�����\��
		printFontGrid(27, 14, "VERSION 1.60", 4 );
		printFontGrid(27, 15, "(2002/03/31)", 6 );
		
		sprintf(string[0], "%39s", versionStr);
		printFontGrid(0, 1, string[0], 4);
		
		// ���[�h0: �{�^�����͑҂�
		if(mode == 0) {
			// �X�^�[�g�{�^���������Ă�������
			if(count % 80 < 40) ExBltRect(sg_gametext, 53, 154, 0, 204, 213, 19);
			
			// �ǂ��炩�̃X�^�[�g�{�^���������ꂽ�烂�[�h1��
			for(player = 0; player <= maxPlay; player++) {
				if(getPushState(player, 4)) {
					democ = 0;
					PlaySE(se_kettei);
					mode = 1;
				}
			}
		}
		// ���[�h1: ���[�h�Z���N�g
		else if(mode == 1) {
			// ���[�h�ꗗ�\��
			printFontGrid(13, 18 + game * 2, "b", 2);
			
			printFontGrid(14, 18, "GAME START", 2 * (game == 0));
			printFontGrid(14, 20, "REPLAY",     2 * (game == 1));
			printFontGrid(14, 22, "CONFIG",     2 * (game == 2));
			
			// �ǂ��炩�̃W���C�X�e�B�b�N�Ń��[�h�Z���N�g
			for(player = 0; player <= maxPlay; player++) {
				// ���
				if(getPushState(player, 0)) {
					PlaySE(se_move);
					game--;
					if(game < 0) game = 2;
				}
				
				// ����
				if(getPushState(player, 1)) {
					PlaySE(se_move);
					game++;
					if(game > 2) game = 0;
				}
				
				// �L�����Z��
				if(getPushState(player, 5)) {
					democ = 0;
					mode = 0;
				}
				
				// ����
				if(getPushState(player, 4)) {
					StopAllBGM();
					PlaySE(se_kettei);
					mode = 0;
					
					// �Q�[���X�^�[�g
					if(game == 0) {
						if(selectRuleAndMode(0)) return;
					}
					// ���v���C
					if(game == 1) {
						if(selectReplay()) return;
					}
					// �R���t�B�O
					if(game == 2) {
						config_mainmenu();
					}
				}
			}
		}
		// ���[�h2: ���[�v���甲����
		else {
			break;
		}
	}
}

//������������������������������������������������������������������������������
//   ���[���E���[�h�I��
//������������������������������������������������������������������������������
int selectRuleAndMode(int player) {
	int i, j, k, page, max, param;
	int crots, cmode;
	
	crots = lastrots;
	cmode = lastmode;
	if(crots >= plugin_count_rule) crots = 0;
	if(cmode >= plugin_count_mode) cmode = 0;
	page = 0;
	
	rots[0] = -2;
	rots[1] = -2;
	gameMode[0] = -2;
	gameMode[1] = -2;
	
	// BGM�Đ�
	if(enable_sysbgm) {
		bgmlv = 12;
		PlayBGM();
	}
	
	loop {
		spriteTime();
		KeyInput();
		ExBltFast(sg_menu_back, 0, 0);
		
		if(page == 0) {
			printFontGrid(1, 1, "SELECT 1P ROTATION RULE", 2);
			
			if(plugin_count_rule == 0) {
				printFontGrid(1, 3, "NO RULE PLUGIN FOUND", 2);
			} else {
				// ���j���[�\��
				max = plugin_count_rule;
				if(max > 20) max = 20;
				j = 0;
				k = (crots / 20) * 20;
				
				for(i = 0; i < max; i++) {
					sprintf(string[0], "%03d:", k + i + 1);
					printFontGrid(2, 3 + j, string[0], 7 * (crots == k + i));
					printFontGrid(6, 3 + j, plugin_name_rule[k + i], 7 * (crots == k + i));
					if(crots == k + i) printFontGrid(1, 3 + j, "b", 7);
					j++;
				}
			}
			
			// �J�[�\���ړ�
			padRepeat2(player);
			
			// ��
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
			if(getPressState(player, 0)) {
				PlaySE(se_move);
				crots--;
				if(crots < 0) crots = plugin_count_rule - 1;
			}
			
			// ��
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
			if(getPressState(player, 1)) {
				PlaySE(se_move);
				crots++;
				if(crots > plugin_count_rule - 1) crots = 0;
			}
			
			// �L�����Z��
			if(getPushState(player, 5)) {
				StopAllBGM();
				return 0;
			}
			// ����
			else if(getPushState(player, 4)) {
				if(plugin_count_rule > 0) {
					PlaySE(se_kettei);
					rots[player] = crots;
					
					param = 1;
					executePlugin(player, 16, &param);	// �v���O�C���Ăяo��
					
					if(param) page++;
				}
			}
		} else if(page == 1) {
			printFontGrid(1, 1, "SELECT GAME MODE", 4);
			
			if(plugin_count_mode == 0) {
				printFontGrid(1, 3, "NO MODE PLUGIN FOUND", 2);
			} else {
				// ���j���[�\��
				max = plugin_count_mode;
				if(max > 20) max = 20;
				j = 0;
				k = (cmode / 20) * 20;
				
				for(i = 0; i < max; i++) {
					sprintf(string[0], "%03d:", k + i + 1);
					printFontGrid(2, 3 + j, string[0], 7 * (cmode == k + i));
					printFontGrid(6, 3 + j, plugin_name_mode[k + i], 7 * (cmode == k + i));
					if(cmode == k + i) printFontGrid(1, 3 + j, "b", 7);
					j++;
				}
			}
			
			// �J�[�\���ړ�
			padRepeat2(player);
			
			// ��
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
			if(getPressState(player, 0)) {
				PlaySE(se_move);
				cmode--;
				if(cmode < 0) cmode = plugin_count_mode - 1;
			}
			
			// ��
			if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
			if(getPressState(player, 1)) {
				PlaySE(se_move);
				cmode++;
				if(cmode > plugin_count_mode - 1) cmode = 0;
			}
			
			// �L�����Z��
			if(getPushState(player, 5)) {
				PlaySE(se_move);
				
				param = 1;
				executePlugin(player, 16, &param);	// �v���O�C���Ăяo��
				
				if(!param) page--;
			}
			// ����
			else if(getPushState(player, 4)) {
				if(plugin_count_mode > 0) {
					PlaySE(se_kettei);
					gameMode[player] = cmode;
					
					maxPlay = 0;
					setFieldPosition(0, 0);
					setFieldPosition(1, 2);
					
					param = 1;
					executePlugin(player, 17, &param);	// �v���O�C���Ăяo��
					
					if(param) {
						StopAllBGM();
						
						lastrots = crots;
						lastmode = cmode;
						saveGeneralConfigData();
						
						gameAllInit();
						
						playerInitial(0);
						versusInit(0);
						if(stat[0] == 0) stat[0] = 3;
						
						if(maxPlay) {
							gameMode[1] = gameMode[0];
							playerInitial(1);
							versusInit(1);
							if(stat[1] == 0) stat[1] = 3;
						}
						
						if(!english) sprintf(string[0], "���[�� %s ���[�h %s �ŃQ�[���J�n", plugin_name_rule[crots], plugin_name_mode[cmode]);
						else sprintf(string[0], "Start new game (Rule:%s Mode:%s)", plugin_name_rule[crots], plugin_name_mode[cmode]);
						debugLogSystem(string[0]);
						
						return 1;
					}
				}
			}
		}
	}
}

//������������������������������������������������������������������������������
//   �Ō�ɂ�鏈��
//������������������������������������������������������������������������������
void lastProc() {
	int i, player;
	
	// ����󋵕\��
	if(onRecord[0] && !pause[0] && !maxPlay) {
		if( (showctrl == 1) || ((showctrl == 2) && (playback) && (replayauto)) )
			showControl();
	}
	
	for(player = 0; player <= maxPlay; player++) {
		// �|�[�Y
		if(IsPushKey(pause_key[player]) | getJoyPushState(player, joy_pause_key[player])) {
			if(onRecord[player] && !netplay) {
				pause[player] = !pause[player];
				
				if(pause[player]) {
					PlaySE(se_pause);
					StopSE(se_hurryup);
				}
				
				if(bgmtype == 3) {
					if(IsPlayMIDI())
						PauseMIDI();
					else
						ReplayMIDI();
				} else if(bgmtype != 0) {
					if(IsPlayWave(bgm_plane[bgmlv]))
						PauseWave(bgm_plane[bgmlv]);
					else
						ReplayWave(bgm_plane[bgmlv]);
				}
				
				if(maxPlay) pause[1 - player] = pause[player];
			}
		}
		
		// ���g���C
		if(!playback && !netplay) {
			if(IsPushKey(retry_key[player]) | getJoyPushState(player, joy_retry_key[player])) {
				retrygame(player);
			}
		}
		
		// �̂ăQ�[
		if(IsPushKey(giveup_key[player]) | getJoyPushState(player, joy_giveup_key[player])) {
			flag = 1;
		}
		
		// �f�o�b�O���j���[
		if(!playback && !netplay) {
			if(IsPushKey(extra_key[player]) | getJoyPushState(player, joy_extra_key[player])) {
				debugMenu(1);
			}
		}
		
		executePlugin(player, 35, &dummy);
	}
}

//������������������������������������������������������������������������������
//   ����������
//������������������������������������������������������������������������������
void gameAllInit() {
	back_acnt = 0;
	bgmlv = 0;
	fadelv = 0;
	fast = 0;
	count = 0;
	fldsizex = 10;
	fldsizey = 22;
	onRecord[0] = 0;
	onRecord[1] = 0;
	objectClear();
}

void playerInitial(int player) {
	int i, j;
	int param;
	
	param = 0;
	executePlugin(player, 2, &param);	// �v���O�C���Ăяo��
	if(param) return;
	
	GiziSRand(player);		// �����̃V�[�h����
	
	engineVer = c_engineVer;
	
	gameTimer[player] = 0;
	timeOn[player] = 0;
	recTimer[player] = 0;
	onRecord[player] = 0;
	
	nextc[player] = 0;
	pinch[player] = 0;
	pause[player] = 0;
	
	hidden[player] = 0;
	hiddenti[player] = 0;
	hiddentm[player] = 0;
	hiddeny[player] = fldsizey;
	hiddenti[player] = 0;
	hiddenc[player] = 0;
	
	if(engineVer >= 3) {
		wait1[player] = 25;
		wait2[player] = 40;
		wait3[player] = 30;
		waitt[player] = 16;
	} else {
		wait1[player] = 26;
		wait2[player] = 40;
		wait3[player] = 28;
		waitt[player] = 15;
	}
	wait4[player] = -1;
	wait5[player] = -1;
	
	sp[player] = 1;
	speedtype[player] = 0;
	
	enable_combo[player] = 0;
	combo[player] = 0;
	combo2[player] = 0;
	combo3[player] = 0;
	hebocombo[player] = 0;
	
	for(i = 0; i < 4; i++) line_count[player * 4 + i] = 0;
	
	stat[player] = 0;
	resetStatc(player);
	
	resetField(player);
	
	upLines[player] = 0;
	framecolor[player] = 1;
	frame_decoration[player] = 0;
	field_spin[player] = -1;
	
	for(i = 0; i < 7; i++) {
		blockcolor[player * 7 + i] = i + 1;
		next_offset[player * 7 + i] = 0;
		next_s_offset[player * 7 + i] = 0;
	}
	
	blockgraphics[player] = 0;
	
	for(i = 0; i < 4; i++) {
		current_color[i + player * 4] = 0;
		current_color_m[i + player * 4] = 0;
	}
	
	current_oblk[player] = 0;
	current_item[player] = 0;
	
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 4; j++) next_color[player * 24 + i * 4 + j] = 0;
		next_oblk[player * 6 + i] = 0;
		next_item[player * 6 + i] = 0;
	}
	
	block_init_x_pos[player] = 3;
	spawntype[player] = spawn_y_type;
	if(!spawntype[player]) {
		block_init_y_pos[player] = 1;
	} else {
		block_init_y_pos[player] = -1;
	}
	
	block_init_rt[player] = 0;
	
	last_command[player] = 0;
	
	hold[player] = -1;
	if(!disable_hold) dhold[player] = 0;
	else dhold[player] = 2;
	hold_count[player] = 0;
	
	for(i = 0; i < 4; i++) hold_color[i + player * 4] = 0;
	hold_oblk[player] = 0;
	hold_item[player] = 0;
	
	harddrop[player] = 0;
	softdrop[player] = 0;
	bk_D[player] = 0;
	softd_dropflag[player] = 0;
	softd_score[player] = 0;
	
	up_flag[player] = 0;
	down_flag[player] = 0;
	
	rot_reverse[player] = 0;
	lockreset[player] = 0;
	rotcount[player] = 0;
	movecount[player] = 0;
	rotlimit[player] = 0;
	movelimit[player] = 0;
	are[player] = 1;
	lockflash[player] = 2;
	lock_up[player] = 0;
	lock_down[player] = 1;
	softspeed[player] = 1;
	self_lock_sound[player] = 0;
	max_waitt[player] = 99;
	RepeatDelay[player] = 0;
	repeatcount[player] = 0;
	fastlrmove[player] = 0;
	initial_rotate[player] = 1;
	initial_hold[player] = 1;
	enable_wallkick[player] = 1;
	
	disp_blkline[player] = 1;
	
	ready_start[player] = n_ready_start;
	ready_end[player] = n_ready_end;
	go_start[player] = n_go_start;
	go_end[player] = n_go_end;
	
	ready_count[player] = 0;
	
	kickc[player] = 0;
	kicktype[player] = 0;
	
	ghost[player] = 1;
	
	ndelay[player] = 1;
	
	sdrop[player] = 0;
	qdrop[player] = 0;
	if(engineVer <= 5) cmbpts[player] = 0;
	else cmbpts[player] = 1;
	qput[player] = 0;
	
	oblk_spawn[player] = 0;
	oblk_bg[player] = 0;
	hnext[player] = dispnext;
	
	IsBig[player] = 0;
	BigMove[player] = 0;
	
	if(beffect_speed != 0) effectspeed[player] = beffect_speed;
	else effectspeed[player] = 1;
	
	are_skipflag[player] = 0;
	show_all_break_effect[player] = (breaktype != 2);
	perase_show_bonus[player] = 0;
	
	ending[player] = 0;
	edrec[player] = 0;
	fastroll[player] = 0;
	ending_timeOn[player] = 0;
	staff_c[player] = 0;
	endtime[player] = 0;
	staff_type[player] = Rand(2);
	
	shadowtime[player] = -1;
	
	nextskip[player] = 0;
	
	item_waiting[player] = 0;
	enable_item_hold[player] = 0;
	item_name[player] = 0;
	item_coming[player] = 0;
	
	bdowncnt[player] = 0;
	brotcount[player] = 0;
	bactivetime[player] = 0;
	bfallflag[player] = 0;
	bfallcount[player] = 0;
	
	tspin_type[player] = 0;
	tspin_flag[player] = 0;
	b_to_b_type[player] = 0;
	b_to_b_count[player] = 0;
	
	fadelv = 0;
	
	isfmirror[player] = 0;
	fmirror_cnt[player] = -20;
	stopmirror_flag[player] = 0;
	
	current_rollroll[player] = 0;
	rollroll_interval[player] = 30;
	
	cpu_best_x[player] = -3;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	cpu_best_p[player] = 0;
	cpu_hold[player] = 0;
	for(i = 0; i < 10; i++) cpu_ctrl[player * 10 + i] = 0;
	cpu_flag[player] = 0;
	cpu_speed[player] = 0;
	cpu_frame[player] = 0;
	
	blkshadow_direction[player] = blockshadow - 1;
	nextc_max[player] = 1400;
	
	multicolor_enable[player] = 0;
	multicolor_ratio[player] = 50;
	
	executePlugin(player, 18, &dummy);	// �v���O�C���Ăяo��
}

// NEXT�u���b�N�𐶐�
void versusInit(int player) {
	int param;
	
	param = 0;
	executePlugin(player, 3, &param);	// �v���O�C���Ăяo��
	
	if(!param) {
		if(nextblock <= 7) heboNextInit(player);
		else if(nextblock == 8) tgmNextInit(player, 0);
		else if(nextblock == 9) tgmNextInit(player, 1);
		else if(nextblock == 10) guidelineNextInit(player);
		else if(nextblock == 11) userNextInit(player);
		else if(nextblock == 12) icheatNextInit(player);
		else eightBagNextInit(player);
	}
	
	setNextBlockColor(player, 1);	// NEXT�u���b�N�̐F��ݒ�
}

//������������������������������������������������������������������������������
//   �v���C���[�̃X�e�[�^�X�ɉ����Ċe���������s
//������������������������������������������������������������������������������
void playerExecute() {
	int i, j, player, temp;
	int param;
	
	// �s���`��
	if((pinch[0] && onRecord[0]) || (pinch[1] && onRecord[1] && maxPlay)) {
		if(!IsPlayWave(se_pinch)) PlaySE(se_pinch);
	} else {
		StopSE(se_pinch);
	}
	
	for(i = 0; i <= maxPlay; i++) {
		player = i;
		
		for(j = 0; j < 10; j++) cpu_ctrl[player * 10 + j] = 0;
		
		param = 0;
		executePlugin(player, 4, &param);	// �v���O�C���Ăяo��
		if(param) goto skip;
		
		if(pause[player]) {
			if(!getPressState(player, 6)) {
				if(count % 60 > 10) printTinyFont(foffset[player] + 35, fyoffset[player] + 120, "PAUSE");
				
				if(playback && replayauto) {
					if(count % 120 > 60)
						printTinyFont(foffset[player] + 10, fyoffset[player] + 201, "PRESS B TO EXIT");
					else
						printTinyFont(foffset[player] + 10, fyoffset[player] + 201, "PRESS D TO PLAY");
				} else {
					if((count % 120 > 60) && (!playback))
						printTinyFont(foffset[player], fyoffset[player] + 201, "PRESS E+F TO RETRY");
					else
						printTinyFont(foffset[player], fyoffset[player] + 201, "PRESS A+B TO GIVEUP");
				}
			}
			// E+F
			if(getPressState(player, 8) && getPressState(player, 9) && !playback) {
				retrygame(player);
			}
			// A+B
			if(getPressState(player, 4) && getPressState(player, 5)) {
				flag = 1;
			}
			goto skip;
		}
		
		padRepeat(player);	// ������
		
		jump(stat[i],l00,l01,l02,l03,l04,l05,l06,l07,l08,l09,l10,l11);
		
		l00: 								// 00 -> �^�C�g���ɖ߂�
				goto next;
		l01: 								// 01 -> �������Ȃ�
				goto next;
		l02: statCustom(player);			// 02 -> ���[�h�v���O�C���p�X�e�[�^�X
				goto next;
		l03: statReady(player);				// 03 -> Ready!?
				goto next;
		l04: statMove(player);				// 04 -> �u���b�N�ړ���
				goto next;
		l05: statErase(player);				// 05 -> �҂����ԏ���
				goto next;
		l06: statEraseBlock(player);		// 06 -> �u���b�N����
				goto next;
		l07: statGameOver(player);			// 07 -> �Q�[���I�[�o�[���o
				goto next;
		l08: statResult(player);			// 08 -> ���ʕ\��
				goto next;
		l09: statGameOver2(player);			// 09 -> �Q�[���I�[�o�[�\��
				goto next;
		l10: statEnding(player);			// 10 -> �G���f�B���O
				goto next;
		l11: statReplaySave(player);		// 11 -> ���v���C�ۑ����
				goto next;
		
		next:
		increment_time(player);
		
		skip:
	}
	
	// BGM�t�F�[�h�A�E�g����
	if(bgmtype != 0) bgmFadeout();
	
	// ���҃Q�[���I�[�o�[�Ȃ�^�C�g����
	if( (stat[0] == 0) && ((stat[1] == 0) || (!maxPlay)) ) flag = 1;
}

// �^�C���𑝉�������
void increment_time(int player) {
	int i, j, temp, param;
	
	param = 0;
	executePlugin(player, 27, &param);
	if(param) return;
	
	// ���v���C�L�^
	if(onRecord[player]) {
		if(recTimer[player] < 60 * 60 * 30) {
			temp = 0;
			
			for(j = 0; j < 10; j++) {
				temp = BitSet(temp, j, getPressState(player, j));
				temp = BitSet(temp, j + 10, getPushState(player, j));
			}
			
			replayData[player * 108000 + recTimer[player]] = temp;
		}
		
		recTimer[player]++;	// ���v���C�p�J�E���^��1/60�b�v���X
	}
	
	// �^�C�}�[�����삵�Ă���Ύ��Ԃ�1/60�b�v���X
	if(timeOn[player]) {
		gameTimer[player]++;
	}
	
	// �G���f�B���O���Ȃ�΃G���f�B���O�o�ߎ��Ԃ�1/60�b�v���X
	if((ending_timeOn[player]) && (ending[player] == 2) && (onRecord[player])) {
		if(fastroll[player] == 1)
			edrec[player] = edrec[player] + 2;
		else
			edrec[player]++;
	}
	
	// �t�B�[���h�^�C�}�[�̃J�E���g�_�E��
	if(hidden[player] == 8) {
		for(i = 0; i < fldsizey; i++)
			for(j = 0; j < fldsizex; j++)
				if(getFieldBlockT(player, j, i) > 0)
					setFieldBlockT(player, j, i, getFieldBlockT(player, j, i) - 1);
	} else if(hidden[player] == 9) {
		for(i = 0; i < fldsizey; i++)
			for(j = 0; j < fldsizex; j++)
				if(getFieldBlockT(player, j, i) < 0)
					setFieldBlockT(player, j, i, getFieldBlockT(player, j, i) + 10);
	}
	
	// �G�t�F�N�g�X�s�[�h��������
	if(!beffect_speed) {
		if((wait1[player] / 2) + wait2[player] <= 0)
			effectspeed[player] = 5;
		else if((wait1[player] / 2) + wait2[player] <= 3)
			effectspeed[player] = 4;
		else if((wait1[player] / 2) + wait2[player] <= 5)
			effectspeed[player] = 3;
		else if((wait1[player] / 2) + wait2[player] <= 10)
			effectspeed[player] = 2;
		else
			effectspeed[player] = 1;
	}
	
	executePlugin(player, 28, &dummy);
}

// �X�^�b�t���[���`��
void staffRoll(int player) {
	int param;
	
	if((ending_timeOn[player]) && (ending[player] == 2) && (onRecord[player]) && (!pause[player])) {
		param = 0;
		executePlugin(player, 36, &param);
		
		if(!param) {
			// �X�^�b�t���[���o�ߎ��Ԃ𑝉�������
			if(fastroll[player] == 1)
				endtime[player] = endtime[player] + 2;
			else
				endtime[player]++;
			
			// �`�悷��
			ExBltRect(sg_staffroll[staff_type[player]], foffset[player] + 8, 40, 0, staff_c[player] / 2, 80, 160);
			
			// �ړ�
			if((endtime[player] % 2 == 0) && (endtime[player] < 3100)) staff_c[player]++;
		}
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.02 - ���[�h�v���O�C���p�X�e�[�^�X
//������������������������������������������������������������������������������
void statCustom(int player) {
	executePlugin(player, 68, &dummy);
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.03 - Ready!?
//������������������������������������������������������������������������������
void statReady(int player) {
	int i, param;
	
	param = 0;
	executePlugin(player, 5, &param);	// �v���O�C���Ăяo��
	if(param) return;
	
	// READY�񐔁{�P
	if(!statc[player * 10]) ready_count[player]++;
	
	// �ŏ��̃t���[���̉����߂��L�^�^�Č�
	if((ready_count[player] == 1) && (onRecord[player]) && (statc[player * 10] == 0)) {
		if(playback) {
			mp[player]  = mps[player * 2    ];
			mpc[player] = mps[player * 2 + 1];
		} else {
			mps[player * 2    ] =  mp[player];
			mps[player * 2 + 1] = mpc[player];
		}
	}
	
	// �ŏ��̔w�i���o���Ă���
	if((ready_count[player] == 1) && (statc[player * 10] == 0)) firstbackno = backno;
	
	// READY��GO��\��
	if((statc[player * 10] >= ready_start[player]) && (statc[player * 10] < ready_end[player])) {
		ExBltRect(sg_gametext, foffset[player] - 2, fyoffset[player] + 91, 200,  0, 100, 50);	// READY
	} else if((statc[player * 10] >= go_start[player]) && (statc[player * 10] < go_end[player])) {
		ExBltRect(sg_gametext, foffset[player] - 2, fyoffset[player] + 92, 200, 50, 100, 50);	// GO
	}
	if(statc[player * 10] == ready_start[player]) {
		if(!IsPlayWave(se_ready)) PlaySE(se_ready);
	}
	if(statc[player * 10] == go_start[player]) {
		if(!IsPlayWave(se_go)) PlaySE(se_go);
	}
	
	// �Q�[���X�^�[�g
	if(statc[player * 10] >= go_end[player]) {
		// �X�^�[�g���̉����߂��L�^�^�Č�
		if((ready_count[player] == 1) && (!onRecord[player])) {
			if(playback) {
				mp[player]  = mps[player * 2    ];
				mpc[player] = mps[player * 2 + 1];
			} else {
				mps[player * 2    ] =  mp[player];
				mps[player * 2 + 1] = mpc[player];
			}
		}
		
		// �^�C�}�[ON
		timeOn[player] = 1;
		onRecord[player] = 1;
		
		executePlugin(player, 38, &dummy);
		
		// �u���b�N�ړ�������
		stat[player] = 4;
		resetStatc(player);
		return;
	} else if(nextskip[player]) {
		// �c���X�L�b�v
		onRecord[player] = 1;	// ���v���C�L�^�J�n
		
		if(getPushState(player, 7)) {
			PlaySE(se_hold);
			
			hold[player] = getNextBlock(player, 0);
			for(i = 0; i < 4; i++) hold_color[i + player * 4] = next_color[player * 24 + i];
			hold_oblk[player] = next_oblk[player * 6];
			
			nextc[player] = (nextc[player] + 1) % nextc_max[player];
			setNextBlockColor(player, 0);
			
			hold_count[player]++;
			dhold[player] = 0;
		}
	}
	
	// �J�E���^����
	statc[player * 10]++;
}

// �u���b�N��������
int blockEraseJudge(int player) {
	int		i, j, sr, lines;
	lines = 0;

	for(i = 0; i < fldsizey; i++) {
		sr = 1;
		
		for(j = 0; j < fldsizex; j++)
			if(getFieldBlock(player, j, i) == 0) {
				sr = 0;
				break;
			}
		
		erase[i + player * fldsizey] = sr;
		lines = lines + sr;
	}

	return lines;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.05 - ���ԉ҂� & ���x���A�b�v����
//������������������������������������������������������������������������������
void statErase(int player) {
	int i;
	int param;
	
	param = 0;
	executePlugin(player, 10, &param);	// �v���O�C���Ăяo��
	if(param) return;
	
	// ����ꐧ���������ꐧ������
	if(engineVer >= 3) {
		if( !getPressState(player, 0) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
			up_flag[player] = 0;
		if( !getPressState(player, 1) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
			down_flag[player] = 0;
	} else {
		if(!getPressState(player, 0) || (!downtype) || ((downtype == 1) && (sp[player] < 1200))) up_flag[player] = 0;
		if(!getPressState(player, 1) || (!downtype) || ((downtype == 1) && (sp[player] < 1200))) down_flag[player] = 0;
	}
	
	// ����オ��
	if(upLines[player]) {
		PlaySE(se_up);
		upLineProc(player);
		upLines[player]--;
		return;
	}
	
	statc[player * 10]--;
	
	// ARE�X�L�b�v
	if((are[player] == 2) && (harddrop[player])) {
		if(getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || getPushState(player, 3) || 
		   getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) || getPushState(player, 8))
		{
			statc[player * 10] = -1;
		}
	}
	if((are[player] == 2) && (are_skipflag[player])) {
		if(getPressState(player, 0) || getPressState(player, 1) || getPressState(player, 2) || getPressState(player, 3) || 
		   getPressState(player, 4) || getPressState(player, 5) || getPressState(player, 6) || getPressState(player, 8))
		{
			statc[player * 10] = -1;
			are_skipflag[player] = 0;
		}
	}
	
	if((ending[player] == 1) || (ending[player] == 4)) {
		// �G���f�B���O�˓�
		stat[player] = 10;
		resetStatc(player);
		statEnding(player);
	} else if((statc[player * 10] < 0) || (!are[player])) {
		// �~���[
		if(fldMirrorProc(player)) return;
		
		stat[player] = 4;	// �u���b�N�ړ�������
		resetStatc(player);
		statMove(player);
	} else {
		hiddenProc(player);
	}
}

// ����オ�菈��
void upLineProc(int player) {
	int i, j;
	int param;
	
	param = 0;
	executePlugin(player, 69, &param);	// �v���O�C���Ăяo��
	if(param) return;
	
	// �t�B�[���h����ɂ��炷
	for(i = 0; i < fldsizey - 1; i++) {
		for(j = 0; j < fldsizex; j++) {
			setFieldBlock(player, j, i, getFieldBlock(player, j, i + 1));
			setFieldBlockT(player, j, i, getFieldBlockT(player, j, i + 1));
			setFieldBlockO(player, j, i, getFieldBlockO(player, j, i + 1));
			setFieldBlockL(player, j, i, getFieldBlockL(player, j, i + 1));
			setFieldBlockI(player, j, i, getFieldBlockI(player, j, i + 1));
		}
	}
	
	// �g���o���̏ꍇ�͈�ԏ���󔒂ɂ���
	if(!spawntype[player]) {
		for(j = 0; j < fldsizex; j++) {
			setFieldBlock(player, j, 0, 0);
			setFieldBlockT(player, j, 0, 0);
			setFieldBlockO(player, j, 0, 0);
			setFieldBlockL(player, j, 0, 0);
			setFieldBlockI(player, j, 0, 0);
		}
	}
	
	// ��ԉ��ɂ���オ��u���b�N�����
	for(j = 0; j < fldsizex; j++) {
		setFieldBlock(player, j, fldsizey - 1, fldu[j + player * (fldsizex * fldsizey)]);
		setFieldBlockT(player, j, fldsizey - 1, shadowtime[player]);
		setFieldBlockO(player, j, fldsizey - 1, oblk_spawn[player]);
		setFieldBlockL(player, j, fldsizey - 1, 0);
		setFieldBlockI(player, j, fldsizey - 1, 0);
	}
	
	// ����オ��t�B�[���h����ɂ��炷
	for(i = 0; i < fldsizey - 1; i++) {
		for(j = 0; j < fldsizex; j++) {
			fldu[j + i * fldsizex + player * (fldsizex * fldsizey)] = fldu[j + (i + 1) * fldsizex + player * (fldsizex * fldsizey)];
		}
	}
	
	// ����オ��t�B�[���h�̈�ԉ����󔒂ɂ���
	for(j = 0; j < fldsizex; j++) {
		fldu[j + (fldsizey - 1) * fldsizex + player * (fldsizex * fldsizey)] = 0;
	}
}

// �~���[����
int fldMirrorProc(int player) {
	int i, j;
	
	// ������~
	if((stopmirror_flag[player]) && (fmirror_cnt[player] == -20)) {
		isfmirror[player] = 0;
		stopmirror_flag[player] = 0;
		field_spin[player] = -1;
		return 0;
	}
	
	if(isfmirror[player]) {
		if(fmirror_cnt[player] <= 20) {
			if(fmirror_cnt[player] == -20) {
				// �t�B�[���h���o�b�t�@�Ɋm��
				for(i = 0; i < fldsizey; i++) {
					for(j = 0; j < fldsizex; j++) {
						// �o�b�t�@�ɃR�s�[
						fldbuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlock(player, j, i);
						fldtbuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlockT(player, j, i);
						fldobuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlockO(player, j, i);
						fldlbuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlockL(player, j, i);
						fldibuf[j + i * fldsizex + player * (fldsizex * fldsizey)] = getFieldBlockI(player, j, i);
						
						// �u���b�N������
						setFieldBlock(player, j, i, 0);
						setFieldBlockT(player, j, i, 0);
						setFieldBlockO(player, j, i, 0);
						setFieldBlockL(player, j, i, 0);
						setFieldBlockI(player, j, i, 0);
					}
				}
			} else {
				// ���]
				if((fmirror_cnt[player] > 0) && (fmirror_cnt[player] % 2 == 0)) {
					j = fmirror_cnt[player] / 2 - 1;
					
					for(i = 0; i < fldsizey; i++) {
						setFieldBlock(player, fldsizex - j - 1, i, fldbuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
						setFieldBlockT(player, fldsizex - j - 1, i, fldtbuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
						setFieldBlockO(player, fldsizex - j - 1, i, fldobuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
						setFieldBlockL(player, fldsizex - j - 1, i, fldlbuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
						setFieldBlockI(player, fldsizex - j - 1, i, fldibuf[j + i * fldsizex + player * (fldsizex * fldsizey)]);
					}
					
					ExBltFastRect(sg_spr, foffset[player] + 8 + ((fldsizex - j - 1) * 8), fyoffset[player] + 40, 0, 165, 8, 160);
				}
			}
			fmirror_cnt[player]++;
			field_spin[player]++;
			return 1;
		} else if(fmirror_cnt[player] <= 24) {
			// 4�t���[���̑҂�����
			fmirror_cnt[player]++;
			field_spin[player]++;
			return 1;
		} else {
			// �I��
			fmirror_cnt[player] = -20;
			field_spin[player] = -1;
			isfmirror[player] = 0;
		}
	}
	
	return 0;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.06 - �u���b�N����
//������������������������������������������������������������������������������
void statEraseBlock(int player) {
	int i, j, k, l, x, y, lines, temp;
	int hardblock, itemerase;
	int param[2];
	
	param[0] = 0;
	executePlugin(player, 11, &param);	// �v���O�C���Ăяo��
	if(param[0]) return;
	
	if(statc[player * 10] != 0) {
		hiddenProc(player);
	}
	
	// ����ꐧ���������ꐧ������
	if(engineVer >= 3) {
		if( !getPressState(player, 0) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
			up_flag[player] = 0;
		if( !getPressState(player, 1) || (!downtype) || ((downtype == 1) && (!is20G(player)) && (are[player] != 0)) )
			down_flag[player] = 0;
	} else {
		if(!getPressState(player, 0) || (!downtype) || ((downtype == 1) && (sp[player] < 1200))) up_flag[player] = 0;
		if(!getPressState(player, 1) || (!downtype) || ((downtype == 1) && (sp[player] < 1200))) down_flag[player] = 0;
	}
	
	if(statc[player * 10] == 0) {
		lines = 0;
		itemerase = 0;	// �A�C�e�������t���O
		
		if(current_item[player]) {
			itemerase = 1;
			item_waiting[player] = current_item[player];
			objectCreate(player, 5, foffset[player] + 8 + (bx[player] * 8), fyoffset[player] + 24 + (by[player] * 8), 0, 0, 0, 0);
		}
		
		// �u���b�N������
		for(i = 0; i < fldsizey; i++) {
			if(erase[i + player * fldsizey]) {
				lines++;
				
				for(x = 0; x < fldsizex; x++) {
					hardblock = 0;	// �n�[�h�u���b�N�����t���O
					
					// �����G�t�F�N�g��\��
					temp = (show_all_break_effect[player] != 0);
					temp = (temp) || (getFieldBlock(player, x, i) >= 10);
					temp = (temp) || ((lines & 1 != 0) && (x & 1 == 1)) || ((lines & 1 == 0) && (x & 1 == 0));
					
					if((temp != 0) && (breaktype != 0) && (!getFieldBlockO(player, x, i))) {
						objectCreate(player, 1, foffset[player] + 8 + (x * 8), fyoffset[player] + (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + lines * 250, getFieldBlock(player, x, i) - 1, 100);
					}
					
					// �v���O�C�����Ă�
					param[0] = x;
					param[1] = i;
					executePlugin(player, 53, &param);
					
					// ������u���b�N���A�C�e��
					if(getFieldBlockI(player, x, i) != 0) {
						if(getFieldBlockI(player, x, i) == fldihardno) {
							// �n�[�h�u���b�N
							hardblock = 1;
							erase[i + player * fldsizey] = 0;
							setFieldBlockO(player, x, i, 0);
						} else if((!itemerase) && (getFieldBlockI(player, x, i) < fldihardno)) {
							// �A�C�e��
							itemerase = 1;
							item_waiting[player] = getFieldBlockI(player, x, i);
							objectCreate(player, 5, foffset[player] + 8 + (x * 8), fyoffset[player] + (i + 3) * 8, 0, 0, 0, 0);
						}
					}
					
					// �u���b�N������
					if(!hardblock) {
						setFieldBlock(player, x, i, 0);
						setFieldBlockT(player, x, i, 0);
						setFieldBlockO(player, x, i, 0);
						setFieldBlockL(player, x, i, 0);
						setFieldBlockI(player, x, i, 0);
					}
				}
			}
		}
		
		// �r�b�O���̓��C��������
		if(IsBig[player]) lines = lines / 2;
		
		// ���C���������ʉ���炷
		if((lines >= 1) && (lines <= 4)) PlaySE(se_erase[lines - 1]);
		else PlaySE(se_erase[0]);
		
		// ����
		if(hebocombo[player]) PlaySE(se_cheer);
		else if(lines >= 4) PlaySE(se_applause);
		
		// ���C�������񐔑���
		if((lines >= 1) && (lines <= 4)) line_count[player * 4 + (lines - 1)]++;
		
		// �R���{�񐔑���
		if(enable_combo[player]) {
			if(lines >= 4) hebocombo[player]++;
			combo[player]++;
			cmbpts[player] = cmbpts[player] + (lines * 2 - 2);
			
			if(lines >= 2) {
				combo2[player]++;
				combo3[player]++;
			} else {
				combo3[player] = 0;
			}
		}
		
		// BACK TO BACK
		if(b_to_b_type[player]) {
			if( ((b_to_b_type[player] != 3) && (lines >= 4)) || ((b_to_b_type[player] != 2) && (tspin_flag[player])) )
				b_to_b_count[player]++;
			else
				b_to_b_count[player] = 0;
		}
		
		statc[player * 10]++;
		
		param[0] = lines;
		param[1] = itemerase;
		executePlugin(player, 12, &param);	// �v���O�C���Ăяo��
	}
	
	if(statc[player * 10] >= wait2[player]) {
		// ��ɂ������u���b�N�����܂ŉ��낷
		lines = downFloatingBlocks(player);
		pinchCheck(player);
		
		// �r�b�O���̓��C��������
		if(IsBig[player]) lines = lines / 2;
		
		PlaySE(se_gon);
		
		// HIDDEN�Ō����Ȃ��Ȃ������C�������ɖ߂�
		hiddenti[player] = hiddenti[player] + lines;
		
		while(hiddenti[player] > 0) {
			hiddenti[player]--;
			hiddeny[player]++;
			
			if(hiddeny[player] > fldsizey) {
				hiddeny[player] = fldsizey;
				hiddentm[player] = 0;
			}
		}
		
		// �A�C�e�����݂̃`�F�b�N
		scanItem(player);
		
		// �҂����ԏ�����
		stat[player] = 5;
		if(wait5[player] == -1) statc[player * 10] = wait1[player];
		else statc[player * 10] = wait5[player];
		
		executePlugin(player, 13, &lines);	// �v���O�C���Ăяo��
	} else {
		// �J�E���^����
		statc[player * 10]++;
		
		// ARE�X�L�b�v
		if((are[player] == 2) && (harddrop[player])) {
			if(getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || 
			   getPushState(player, 3) || getPushState(player, 4) || getPushState(player, 5) || 
			   getPushState(player, 6) || getPushState(player, 8))
			{
				statc[player * 10] = wait2[player];
				are_skipflag[player] = 1;
			}
		}
	}
}

// ��ɂ������u���b�N�����܂ŉ��낷
int downFloatingBlocks(int player) {
	int i, k, l, y, lines;
	
	y = fldsizey - 1;
	lines = 0;
	
	for(i = 0; i < fldsizey; i++) {
		if(erase[y + player * fldsizey]) {
			// �u���b�N��1�i�ォ��R�s�[
			for(k = y; k > 0; k--) {
				for(l = 0; l < fldsizex; l++) {
					setFieldBlock(player, l, k, getFieldBlock(player, l, k - 1));
					setFieldBlockT(player, l, k, getFieldBlockT(player, l, k - 1));
					setFieldBlockO(player, l, k, getFieldBlockO(player, l, k - 1));
					setFieldBlockL(player, l, k, getFieldBlockL(player, l, k - 1));
					setFieldBlockI(player, l, k, getFieldBlockI(player, l, k - 1));
				}
				erase[k + player * fldsizey] = erase[(k - 1) + player * fldsizey];
			}
			
			// ��ԏ���󔒂ɂ���
			for(l = 0; l < fldsizex; l++) {
				setFieldBlock(player, l, 0, 0);
				setFieldBlockT(player, l, 0, 0);
				setFieldBlockO(player, l, 0, 0);
				setFieldBlockL(player, l, 0, 0);
				setFieldBlockI(player, l, 0, 0);
			}
			erase[0 + player * fldsizey] = 0;
			
			lines++;
		} else {
			y--;
		}
	}
	
	return lines;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.07 - �Q�[���I�[�o�[
//������������������������������������������������������������������������������
void statGameOver(int player) {
	int i, j, block, c, tmp;
	int param;
	
	param = 0;
	executePlugin(player, 20, &param);
	if(param) return;
	
	// �ŏ��̃t���[���̏���
	if(statc[player * 10 + 2] == 0) {
		timeOn[player] = 0;
		pinch[player] = 0;
		disp_blkline[player] = 0;
		StopSE(se_hurryup);
		hiddeny[player] = fldsizey;
		
		if(hidden[player]) {
			hidden[player] = 0;
			disableShadowTimer(player);
			statc[player * 10 + 3] = 1;	// HIDDEN���̓u���b�N�������鉉�o�J�n�܂ŊԂ�u��
		}
		
		if(!fastroll[player]) {
			onRecord[player] = 0;
			StopAllBGM();
		}
		
		statc[player * 10] = fldsizey - 1;
		
		// �t�B�[���h�ɉ����Ȃ��ꍇ�̓u���b�N�������鉉�o���ȗ�
		if(isBravo(player)) statc[player * 10] = -2;
		
		statc[player * 10 + 2] = 1;
	}
	
	// ���o�I��
	if(statc[player * 10] <= -2) {
		// ���̃X�e�[�^�X��
		if((ending[player] == 2) && (fastroll[player] != 0)) {
			stat[player] = 1;	// �������[���Ŏ��񂾏ꍇ�̓��[���I���܂ő҂�
			
			// �t�B�[���h������
			resetField(player);
		} else {
			stat[player] = 8;	// ���ʉ��
		}
		resetStatc(player);
		return;
	}
	
	// �J�E���^����
	statc[player * 10 + 1]++;
	
	// �X�[�b�Ə����Ă������o
	if(statc[player * 10 + 1] > 4 + statc[player * 10 + 3] * 116) {
		block = statc[player * 10];
		
		statc[player * 10 + 1] = 0;
		
		for(j = 0; j < fldsizex; j++) {
			if(block >= 0) {
				c = getFieldBlockT(player, j, block);
				if(c == -1) c = 8;
				setFieldBlockT(player, j, block, c - 4);
			}
			
			if(block < fldsizey - 1) {
				setFieldBlockT(player, j, block + 1, getFieldBlockT(player, j, block + 1) - 4);
			}
		}
		
		statc[player * 10 + 3] = 0;
		statc[player * 10]--;
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.08 - ���ʕ\��
//������������������������������������������������������������������������������
void statResult(int player) {
	int i, param;
	
	param = 0;
	executePlugin(player, 21, &param);
	if(param) return;
	
	statc[player * 10]++;
	
	// BGM�Đ�
	if(statc[player * 10] == 1) {
		if((bgmtype != 0) && (!fast)) {
			if(!enable_sysbgm) loadBGM(13);
			bgmlv = 13;
			PlayBGM();
		}
	}
	
	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4)) {
		statc[player * 10] = 500;
	}
	
	// ���̉�ʂ�
	if(statc[player * 10] >= 500) {
		stat[player] = 9;
		resetStatc(player);
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.09 - �Q�[���I�[�o�[�\��
//������������������������������������������������������������������������������
void statGameOver2(int player) {
	int i, param;
	
	param = 0;
	executePlugin(player, 22, &param);
	if(param) return;
	
	// �J�E���^����
	statc[player * 10]++;
	
	// �Q�[���I�[�o�[��
	if(statc[player * 10] == 1) {
		PlaySE(se_gameover);
		StopAllBGM();
	}
	
	// GAME OVER
	ExBltRect(sg_gametext, foffset[player] - 2, 95, 0, 0, 100, 50);
	
	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4)) {
		statc[player * 10] = 480;
	}
	
	// �I��
	if(statc[player * 10] >= 480) {
		if(playback && replayauto) stat[player] = 0;
		else stat[player] = 11;
		resetStatc(player);
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.10 - �G���f�B���O
//������������������������������������������������������������������������������
void statEnding(int player) {
	int i, j, k, param;
	
	param = 0;
	executePlugin(player, 23, &param);
	if(param) return;
	
	jump(ending[player] - 1, lerase, lstart, lclear, lerase);
	
	// �G���f�B���O1��4 �u���b�N����
	lerase:
		if(statc[player * 10] == 0) {
			PlaySE(se_ttclear);
			StopAllBGM();
			statc[player * 10 + 1] = 0;
			if(ending[player] == 4) statc[player * 10 + 1] = checkFieldTop(player) * 6;
		}
		
		// �u���b�N������
		if(statc[player * 10 + 1] % 6 == 0) {
			if(ending[player] == 4) {
				j = statc[player * 10 + 1] / 6;
			} else {
				j = fldsizey - statc[player * 10 + 1] / 6;
			}
			
			if((j >= 0) && (j < fldsizey)) {
				for(i = 0; i < fldsizex; i++) {
					if(getFieldBlock(player, i, j)) {
						if(getFieldBlockO(player, i, j) == 0) {
							objectCreate(player, 1, foffset[player] + 8 + (i * 8), fyoffset[player] + (j + 3) * 8, (i - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, getFieldBlock(player, i, j) - 1, 100);
						}
						setFieldBlock(player, i, j, 0);
						setFieldBlockT(player, i, j, 0);
						setFieldBlockO(player, i, j, 0);
						setFieldBlockL(player, i, j, 0);
						setFieldBlockI(player, i, j, 0);
					}
				}
			}
		}
		
		if(statc[player * 10] >= 129) {
			// �A�j���I���A���̏�����
			executePlugin(player, 24, &dummy);
		} else {
			// �J�E���^����
			statc[player * 10]++;
			statc[player * 10 + 1]++;
		}
		return;
	
	// �G���f�B���O2 �X�^�b�t���[��
	lstart:
		stat[player] = 4;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	
	// �G���f�B���O3 EXCELLENT���
	lclear:
		param = 0;
		executePlugin(player, 25, &param);
		if(param == -1) return;
		
		statc[player * 10]++;
		
		// �ԉ�
		/*
		if((statc[player * 10] % 10 == 0) && (statc[player * 10 + 1] < 30)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], fyoffset[player] + 16 + Rand(20), 0, 0, Rand(7), 0);
			statc[player * 10 + 1]++;
		}
		*/
		
		if(param == 0) {
			// EXCELLENT
			if(statc[player * 10] < 6) {
				k = 10 - statc[player * 10];
				i = (76 * k / 5 - 76) / 2;
				j = (10 * k / 5 - 10) / 2;
				k = 65536 * k / 5;
				ExBltRectR(sg_spr, foffset[player] + 10 - i, fyoffset[player] + 96 - j, 0, 31, 76, 10, k, k);
			} else {
				ExBltRect(sg_spr, foffset[player] + 10, fyoffset[player] + 96, 0, 31, 76, 10);
			}
		} else if(param == 1) {
			// YOU ARE GRAND MASTER!!
			if(statc[player * 10] < 64) {
				k = 128 - statc[player * 10];
				i = (80 * k / 64 - 80) / 2;
				j = (36 * k / 64 - 36) / 2;
				k = 65536 * k / 64;
				ExBltRectR(sg_spr, foffset[player] + 8 - i, fyoffset[player] + 102 - j, 0, 41, 80, 36, k, k);
			} else {
				ExBltRect(sg_spr, foffset[player] + 8, fyoffset[player] + 102, 0, 41, 80, 36);
			}
		} else if(param == 2) {
			// YOU ARE GOD
			if(statc[player * 10] < 64) {
				k = 128 - statc[player * 10];
				i = (105 * k / 64 - 105) / 2;
				j = (67 * k / 64 - 67) / 2;
				k = 65536 * k / 64;
				ExBltRectR(sg_spr, foffset[player] - 7 - i, fyoffset[player] + 70 - j, 88, 357, 105, 67, k, k);
			} else {
				ExBltRect(sg_spr, foffset[player] - 7, fyoffset[player] + 70, 88, 357, 105, 67);
			}
		} else if(param == 3) {
			// CLEAR!!
			ExBltRect(sg_spr, foffset[player] + 2, fyoffset[player] + 78, 0, 97, 92, 17);
		} else if(param == 4) {
			// CLEAR
			ExBltRect(sg_spr, foffset[player] + 3, fyoffset[player] + 78, 0, 116, 92, 17);
		} else if(param == 5) {
			// �����\�������I���
			statc[player * 10] = 600;
		}
		
		// �I��
		if(statc[player * 10] >= 600) {
			fastroll[player] = 0;
			stat[player] = 7;
			resetStatc(player);
		}
		
		executePlugin(player, 26, &dummy);
		return;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.11 - ���v���C�ۑ����
//������������������������������������������������������������������������������
void statReplaySave(int player) {
	int color, number;
	color = (count % 4 / 2) * 7;
	number = statc[player * 10 + 1];
	
	// �ŏ��̃t���[���̏���
	if(!statc[player * 10 + 2]) {
		checkAllReplayExist();
		statc[player * 10 + 2] = 1;
	}
	
	// ���j���[�\��
	printFont(foffset[player] + 16, fyoffset[player] + 96 + statc[player * 10] * 16, "b", color);
	
	sprintf(string[0], "SAVE %d", number + 1);
	printFont(foffset[player] + 24, fyoffset[player] + 96, string[0], (statc[player * 10] == 0) * color);
	
	if(replayexist[number]) {
		printFont(foffset[player] + 32, fyoffset[player] + 104, "(USED)", (statc[player * 10] == 0) * color);
	}
	
	if(!playback) {
		printFont(foffset[player] + 24, fyoffset[player] + 112, "RETRY", (statc[player * 10] == 1) * color);
	}
	printFont(foffset[player] + 24, fyoffset[player] + 128, "END", (statc[player * 10] == 2) * color);
	
	// ���v���C���e�\��
	if(replayexist[number]) {
		sprintf(string[0], "REPLAY %d", number + 1);
		printFont(foffset[player] + 8, fyoffset[player] + 160, string[0], 4);
		
		LeftStr(replay_plugin_name_mode[number], 10, string[0]);
		printFont(foffset[player] + 8, fyoffset[player] + 168, string[0], 0);
		
		LeftStr(replay_plugin_name_rule[number], 10, string[0]);
		printFont(foffset[player] + 8, fyoffset[player] + 176, string[0], 0);
		
		getTime(replay_timer[number]);
		printFont(foffset[player] + 8, fyoffset[player] + 184, string[0], 0);
	}
	
	// �L�[����
	padRepeat2(player);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if(getPressState(player, 0)) {
		PlaySE(se_move);
		statc[player * 10]--;
		if((playback) && (statc[player * 10] == 1)) statc[player * 10] = 0;
		if(statc[player * 10] < 0) statc[player * 10] = 2;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if(getPressState(player, 1)) {
		PlaySE(se_move);
		statc[player * 10]++;
		if((playback) && (statc[player * 10] == 1)) statc[player * 10] = 2;
		if(statc[player * 10] > 2) statc[player * 10] = 0;
	}
	
	// ��
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
	if(getPressState(player, 2)) {
		if(statc[player * 10] == 0) {
			PlaySE(se_kachi);
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 39;
		}
	}
	
	// ��
	if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
	if(getPressState(player, 3)) {
		if(statc[player * 10] == 0) {
			PlaySE(se_kachi);
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 39) statc[player * 10 + 1] = 0;
		}
	}
	
	// A�{�^��
	if(getPushState(player, 4)) {
		if(statc[player * 10] == 0) {
			// SAVE
			if(recTimer[player] <= 108000) {
				PlaySE(se_kettei);
				if(maxPlay) {
					saveReplayData(0, statc[player * 10 + 1]);
					saveReplayData(1, statc[player * 10 + 1]);
				} else {
					saveReplayData(player, statc[player * 10 + 1]);
				}
				checkAllReplayExist();
			}
		} else if(statc[player * 10] == 1) {
			// RETRY
			PlaySE(se_kettei);
			retrygame();
		} else if(statc[player * 10] == 2) {
			// END
			flag = 1;
		}
	}
}

// ���g���C����
void retrygame(int player) {
	int param;
	
	StopAllBGM();
	resetSoundVolume();
	
	param = 0;
	executePlugin(player, 70, &param);
	
	if(!param) {
		gameAllInit();
		playerInitial(player);
		versusInit(player);
		
		if(backno != firstbackno) {
			bgfadesw = 1;
			bgfadelv = 0;
			bgfadebg = firstbackno;
		}
		stat[player] = 3;
	}
	
	if(!english) debugLogSystem("�ăX�^�[�g");
	else debugLogSystem("Game restart");
}

//������������������������������������������������������������������������������
//   �N�����̓ǂݍ��ݏ���
//������������������������������������������������������������������������������
void initialize() {
	int i, cfg[4];
	
	SetConstParam("Caption", "HEBORIS U.E. MINI - Now Loading...");
	
	// SCREEN.SAV�ǂݍ���(screencfg.c)
	cfg[0] = screenMode;
	cfg[1] = systemmem;
	cfg[2] = screenColor;
	cfg[3] = useHires;
	loadScreenConfig(&cfg);
	screenMode = cfg[0];
	systemmem = cfg[1];
	screenColor = cfg[2];
	useHires = cfg[3];
	
	// ��ʉ𑜓x�ݒ�
	if((screenMode >= 2) && (useHires)) setDrawRate(2);
	else setDrawRate(1);
	
	// �o�[�W�����\��
	ExTextLayerOn(0, 8, 8);
	ExTextSize(0, 12);
	TextColor(0, 0, 255, 0);
	TextBackColorDisable(0);
	TextOut(0, versionStr);
	halt;
	
	// ������
	for(i = 0; i < 512; i++) {
		graphics_plane_type[i] = 0;
		sound_plane_type[i] = 0;
		se_play[i] = 0;
	}
	for(i = 0; i < 30; i++) {
		bgm_plane[i] = -1;
	}
	
	// ������ϐ��̃��������m��
	for(i = 0; i < 200; i++) {
		plugin_name_rule[i] = new(32);
		plugin_name_mode[i] = new(32);
		StrCpy(plugin_name_rule[i], "");
		StrCpy(plugin_name_mode[i], "");
	}
	
	for(i = 0; i < 40; i++) {
		replay_plugin_name_rule[i] = new(32);
		replay_plugin_name_mode[i] = new(32);
	}
	
	if(debug_enable) {
		for(i = 0; i < 40; i++) {
			debug_log_system[i] = new(256);
			debug_log_rule[i] = new(256);
			debug_log_mode[i] = new(256);
			StrCpy(debug_log_system[i], "");
			StrCpy(debug_log_rule[i], "");
			StrCpy(debug_log_mode[i], "");
		}
		
		if(!english) debugLogSystem("�f�o�b�O���O�J�n");
		else debugLogSystem("Debug log start.");
	}
	
	// �V�X�e���O���t�B�b�N��ǂݍ���
	TextColor(0, 255, 255, 255);
	ExTextMove(0, 8, 20);
	TextOut(0, "Graphics Loading");
	halt;
	loadAllSystemGraphics();
	
	// �V�X�e�����ʉ���ǂݍ���
	ExTextMove(0, 8, 32);
	TextOut(0, "Sound Effect Loading");
	halt;
	loadSystemSE();
	
	// �V�X�e�����y��ǂݍ���
	if(enable_sysbgm) {
		ExTextMove(0, 8, 44);
		TextOut(0, "System BGM Loading");
		halt;
		loadSystemBGM();
	}
	
	TextLayerOff(0);
	
	fps_plus_mpc[0] = 0;
	fps_plus_mpc[1] = 0;
	fps_minus_mpc[0] = 0;
	fps_minus_mpc[1] = 0;
	
	SetConstParam("Caption", "HEBORIS U.E. MINI");
	
	executePlugin(0, 0, &dummy);	// �v���O�C���Ăяo��
}

// �t�B�[���h�\���ʒu�ݒ�
void setFieldPosition(int player, int max) {
	int i;
	
	if(max == 0) {
		// SINGLE
		foffset[player] = s_foffset;
		fyoffset[player] = s_fyoffset;
		coffset = s_coffset;
	} else if(max == 1) {
		// DUAL
		foffset[player] = d_foffset[player];
		fyoffset[player] = d_fyoffset[player];
		//coffset = d_coffset;
	} else {
		// VERSUS
		foffset[player] = v_foffset[player];
		fyoffset[player] = v_fyoffset[player];
		//coffset = d_coffset;
	}
}

//������������������������������������������������������������������������������
//   �v���O�C���Ǘ�
//������������������������������������������������������������������������������
// ���[���ǉ�
int addRulePlugin(str *name) {
	int len;
	
	// ����200�o�^����Ă���Ȃ�G���[
	if(plugin_count_rule >= 200) {
		if(!english) sprintf(string[0], "���[�� %s �̓o�^�Ɏ��s(����200�����E)", name);
		else sprintf(string[0], "Failed to add rule %s (There are 200 plugins)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	// ���O�������A�܂��͒�������ꍇ�̓G���[
	len = StrLen(name);
	if((len < 1) || (len > 31)) {
		if(!english) sprintf(string[0], "���[�� %s �̓o�^�Ɏ��s(���O�̒������K��O)", name);
		else sprintf(string[0], "Failed to add rule %s (Name is too long or short)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	// �����̃��[���̓o�^�������
	if(findRulePlugin(name) != -1) {
		if(!english) sprintf(string[0], "���[�� %s �̓o�^�Ɏ��s(���d�o�^)", name);
		else sprintf(string[0], "Failed to add rule %s (Multiple registration)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	StrCpy(plugin_name_rule[plugin_count_rule], name);
	plugin_count_rule++;
	
	if(!english) sprintf(string[0], "���[�� %s ��o�^���܂���", name);
	else sprintf(string[0], "Rule %s added", name);
	debugLogSystem(string[0]);
	
	return plugin_count_rule - 1;
}

// ���[�h�ǉ�
int addModePlugin(str *name) {
	int len;
	
	// ����200�o�^����Ă���Ȃ�G���[
	if(plugin_count_mode >= 200) {
		if(!english) sprintf(string[0], "���[�h %s �̓o�^�Ɏ��s(����200�����E)", name);
		else sprintf(string[0], "Failed to add mode %s (There are 200 plugins)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	// ���O�������A�܂��͒�������ꍇ�̓G���[
	len = StrLen(name);
	if((len < 1) || (len > 31)) {
		if(!english) sprintf(string[0], "���[�h %s �̓o�^�Ɏ��s(���O�̒������K��O)", name);
		else sprintf(string[0], "Failed to add mode %s (Name is too long or short)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	// �����̃��[�h�̓o�^�������
	if(findModePlugin(name) != -1) {
		if(!english) sprintf(string[0], "���[�h %s �̓o�^�Ɏ��s(���d�o�^)", name);
		else sprintf(string[0], "Failed to add mode %s (Multiple registration)", name);
		debugLogSystem(string[0]);
		return -1;
	}
	
	StrCpy(plugin_name_mode[plugin_count_mode], name);
	plugin_count_mode++;
	
	if(!english) sprintf(string[0], "���[�h %s ��o�^���܂���", name);
	else sprintf(string[0], "Mode %s added", name);
	debugLogSystem(string[0]);
	
	return plugin_count_mode - 1;
}

// ���[���v���O�C��������
int findRulePlugin(str *name) {
	int i;
	
	for(i = 0; i < plugin_count_rule; i++) {
		if(StrCmp(plugin_name_rule[i], name) == 0) return i;
	}
	
	return -1;
}

// ���[�h�v���O�C��������
int findModePlugin(str *name) {
	int i;
	
	for(i = 0; i < plugin_count_mode; i++) {
		if(StrCmp(plugin_name_mode[i], name) == 0) return i;
	}
	
	return -1;
}

//������������������������������������������������������������������������������
//   halt;
//������������������������������������������������������������������������������
void spriteTime() {
	int player;
	
	count = (count + 1) % 65536;	// �O���[�o���J�E���^����
	
	if(!netplay) {
		for(player = 0; player <= maxPlay; player++) {
			// FPS+1
			if(IsPressKey(fps_plus_key[player]) || getJoyPressState(player, joy_fps_plus_key[player])) {
				fps_plus_mpc[player]++;
				
				if((fps_plus_mpc[player] == 1) || (fps_plus_mpc[player] > tame1)) {
					if(GetFPS() < 180) SetFPS(GetFPS() + 1);
				}
			} else {
				fps_plus_mpc[player] = 0;
			}
			
			// FPS-1
			if(IsPressKey(fps_minus_key[player]) || getJoyPressState(player, joy_fps_minus_key[player])) {
				fps_minus_mpc[player]++;
				
				if((fps_minus_mpc[player] == 1) || (fps_minus_mpc[player] > tame1)) {
					if(GetFPS() > 1) SetFPS(GetFPS() - 1);
				}
			} else {
				fps_minus_mpc[player] = 0;
			}
		}
	}
	
	// FPS�\���i��ʁj
	if(show_fps == 1) {
		sprintf(string[0], "%3d/%3dFPS", GetRealFPS(), GetFPS());
		printTinyFont(132, 233, string[0]);
	}
	
	// FPS�\���i�^�C�g���o�[�j
	if(show_fps == 2) {
		sprintf(string[0], "HEBORIS U.E. MINI - %d/%dFPS", GetRealFPS(), GetFPS());
		SetConstParam("Caption", string[0]);
	}
	
	// �l�b�g�v���C���̕\��
	if(netplay) {
		printTinyFont(0, 233, "NETPLAY");
	}
	// ���v���C���̕\��
	else if(playback) {
		if(replayauto) printTinyFont(0, 233, "REPLAY");
		else printTinyFont(0, 233, "RERECORD");
	}
	
	executePlugin(0, 1, &dummy);	// �v���O�C���Ăяo��
	
	// ESC�L�[�������ꂽ�瑦���I��
	if(IsPushEscKey()) {
		// �l�b�g�v���C����������ؒf
		if(netplay) {
			tcpCleanup();
			netplay = 0;
		}
		
		Quit();
	}
	
	// 2�{�E�C���h�E���[�h�̎��̏���
	if((screenMode >= 2) && (!useHires)) {
		SwapToSecondary(sg_2xwindow);		// �Z�J���_���v���[�����A�_�~�[�Ńv���[��sg_2xwindow�Ɠ���ւ���
		BltFastRectR(sg_2xwindow, 0, 0, 0, 0, 320, 240, 65536 * 2, 65536 * 2);
		SwapToSecondary(sg_2xwindow);
		BltFast(sg_2xwindow, 0, 0);
	}
	
	// �`��
	halt;
	
	// ���ʉ��Đ�
	PlayAllSE();
	
	// �X�N���[���V���b�g
	if(IsPushKey(ss_key[0]) || IsPushKey(ss_key[1]) || 
	   getJoyPressState(0, joy_ss_key[0]) || getJoyPressState(1, joy_ss_key[1]))
	{
		sprintf(string[0], "ss/ss_%04d.bmp", ssc);
		
		SwapToSecondary(sg_sssurface);
		ExSaveBitmap(string[0], sg_sssurface, 0, 0, 320, 240);
		SwapToSecondary(sg_sssurface);
		
		ssc++;
	}
	
	ClearSecondary();
}
