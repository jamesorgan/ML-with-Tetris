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
LITE32.13 (07/07/04)
�y�ǉ��z
�Eheboris_user.ini�𕜊������Ă݂܂����B
�Eheboris.ini�Ɂudevil_doom_n_rise�v��ǉ����܂����B1�ɂ����DEVIL-DOOM�ł���オ��Ԋu�����ɂȂ�܂��B
�y�ύX�z
�EDEVIL-DOOM���[�h��LV300-400�̑��x��ACE-ANOTHER���[�h��ACE-ANOTHER2���[�h�̑��x��ύX���܂����B
�EMASTER-HARD�̔F�莎���Ō��݂̔F��i�ʂƎ����i�ʂ̍���5�ȓ��ɂȂ�悤�ɂ��܂����B�iMO�Ƃ��₽�獂���i�ʂ��o�Ȃ��悤�Ɂj
�EMASTER-HARD�̍~�i������2��ȏ�A���ŋN����Ȃ��悤�ɂ��܂����B
�E�����L�[�Ń��v���C��ۑ�����ƁA�ۑ��������b�Z�[�W�����̕����Ɣ�邱�Ƃ��������̂Ń��b�Z�[�W�����������܂����B
�y�o�O�C���z
�EDEVIL-HARD��DEVIL-DOOM�ŁA�i�ʂ�S10�`S13�̂Ƃ��Ɍ��ʉ�ʂ̒i�ʕ\�����t�B�[���h�g�ɔ��o�O���C�����܂����B
�ESOUND SETTING�́uBGM FADE TIME�v��0����BGM���؂�ւ��Ȃ��o�O���C�����܂����B
�E20G-EASY��Gm�����̔��肪�s���Ȃ��o�O���C�����܂����B

LITE32.12 (07/06/27)
�y�ǉ��z
�EDISPLAY SETTING�ɁuHIDDEN-B TYPE�v��ǉ����܂����BSPECIAL�ɂ����HIDDEN-B��ԂŃu���b�N��u���Ă��g�����o�Ȃ��Ȃ�܂��B
�EMISSION���[�h�ɐV�����~�b�V�����u���x�Œ�v��ǉ����܂����B�~�b�V�����̐ݒ�ő��x�����R�Ɏw��ł��郌�x���X�^�[�ł��B
�E���v���C�I����ʂ�PRACTICE�̃��v���C�̓��B���x����������悤�ɂ��܂����B
�EDISPLAY SETTING��REFRESH TIMING�����j���[�ł����f�����悤�ɂ��܂����B
�y�o�O�C���z
�E���v���C�I����ʂ�MASTER-EASY��20G-EASY�̃��v���C�Œi�ʕ\����GM�ł͂Ȃ�M1�ƕ\�������o�O���C�����܂����B
�E���v���C����B�{�^���������Ɛݒ��ʂŐݒ�l�̕ύX���ł��Ȃ��Ȃ鎖������o�O���C����������

LITE32.11 (07/06/18)
�y�ǉ��z
�EMASTER-EASY���[�h��ǉ����܂����B�i������MASTER-G1�j
�EDISPLAY SETTING�ɁuEFFECT SPEED�v��ǉ����܂����B���C�������G�t�F�N�g�̑�����5�i�K�ŕύX�ł��܂��B
�@AUTO�ɂ���ƒʏ��1�{���A�����ɂȂ��2�{���A�������ɂȂ��3�{���ɂȂ�܂��B
�@2�{���ȏ�ɂ���Ƒ����`����y���Ȃ�͂��c
�EOLD STYLE-ARCADE�̏����G�t�F�N�g��ύX���܂����B
�@�܂��ADISPLAY SETTING��BREAK EFFECT�ɁuOLD STYLE-ARCADE�v��ǉ����܂����B
�@�S�Ẵ��[�h��OLD STYLE-ARCADE�Ɠ����G�t�F�N�g���g���܂��B
�y�ύX�z
�EDEVIL-DOOM�̑��x�Ƃ���オ��y�[�X��ύX���܂����B
�EACE-ANOTHER���[�h��ACE-ANOTHER2���[�h�̑��x��ύX���܂����B�i���x�ω���LV13�őł��~�߁ADEVIL-DOOM LV300-400��Ɠ����j
�y�o�O�C���z
�E1�t���[����2��ȏ㉡���ߏ������s����o�O�����Ԃ񊮑S�ɏC�����܂����B
�EVERSUS���[�h��f����ʂȂǂ�CPU���܂Ƃ��ɓ��삵�Ă��Ȃ��o�O���C�����܂����B
�E�G���f�B���O�˓����A�u���b�N�������Ă�����ʂŉ����߂��ł��Ȃ��o�O���C�����܂����B
�EMISSION���[�h�̃��v���C�ő���󋵕\�������ɏo�Ă��܂��o�O���C�����܂����B

LITE32.10 (07/06/10)
�y�ǉ��z
�ESKIP LOCKFLASH�ɁuARCADE�v��ǉ����܂����B
�@�uOFF�v�����Z���āuON�v���������ł��B�Œ肵���u�Ԃ̊D�F�u���b�N�̕\�����Ԃ�2�t���[������܂��B
�EDISPLAY SETTING�ɁuREFRESH TIMING�v��ǉ����܂����B
�@��ʕ\�����X�V����^�C�~���O���u���������̌�v�Ɓu���������̑O�v�̂ǂ���ɂ��邩��I���ł��܂��B
�EWORLD SOFTLOCK�ɁuNONE�v��ǉ����܂����B���[���h���[���ŉ��������Â��Ă��i�{���Ɂj�����N����Ȃ��Ȃ�܂��B
�@����܂ł́uOFF�v�i�����ɑ����Œ莞�Ԃ��i�ށj�́uNORMAL�v�ɉ������܂����B
�y�o�O�C���z
�EINPUT SETTING��FUNCTION KEY��I������ƃt���[�Y����o�O���C�����܂����B
�ESKIP LOCKFLASH��OFF�ȊO�̏ꍇ�A�u���b�N���Œ肵���u�Ԃɉ����ߏ�����1�t���[����2��s����o�O���C�����܂����B
�ESETTYAKU��99�ɂ���ƃu���b�N����u�ŌŒ肳��Ă��܂��o�O���C�����܂����B
�EAFTERIMAGE��ON�ɂ��Ă��Ă��c�����\������Ȃ��o�O���C�����܂����B

LITE32.9�ȑO�̕ύX������changelog.txt�ɂ���܂��B
*/

//������������������������������������������������������������������������������
//   �O�����C�u�����̃C���|�[�g
//������������������������������������������������������������������������������
	import	"string.dll"		// �����񃉃C�u�����̃C���|�[�g

//������������������������������������������������������������������������������
//   �O���[�o���ϐ��̒�`
//������������������������������������������������������������������������������
int		count;						// �O���[�o���J�E���^ (�t���[���P�ʁA65535�܂�)
int		backno;						// ���݂̔w�i
int		background_compatibility;	// back13.png back14.png back15.png�𖳎�����

int		stat[2], statc[10*2];		// ���݂̃X�e�[�^�X�ƃp�����[�^ no + pl * 5
int		gameTimer[2], timeOn[2];	// �Q�[���J�n����̌o�ߎ��� (1/60�b�P��)�A�L��?

int		flag;						// 1�ɂ���ƃ^�C�g���ɖ߂�
int		overcount;					// 1P��2P���Q�[���I�[�o�[�ɂȂ����Ƃ��A�^�C�g���ɖ߂�Ƃ��Ɏg���J�E���^

int		pinch[2];					// �s���`���ǂ���

int		winr, winc, winu, wink;

int		noredraw, fast;
int		csr, cnt, category;

int		saveBuf[50000];				// �Z�[�u�p�o�b�t�@
int		setupBak[24];				// �Z�b�e�B���O���e�̃o�b�N�A�b�v�p
int		pause[2];					// �|�[�Y���Ă邩�[��!?
int		hnext[2];					// NEXT�B���Ă邩�[��!?
int		gameMode[2];				// ���݂̃Q�[�����[�h

int		rankingrule;

int		ssc = 0;					// �X�N���[���V���b�g�J�E���^

int		timeattack[2];				// �Q�[���^�C�v

int		bdowncnt[2];				// �u���b�N��u������
int		s_bdowncnt[2];				// �u���b�N��u�����񐔁i�j�Д���^�X�N�E�F�A�p�j

int		IsBig[2];					// ����BIG���ǂ���
int		BigMove[2];					// BIG���̉��ړ��P��
int		IsBigStart[2];				// BIG�Ŏn�߂����ǂ���
int		BigMoveStart[2];			// �X�^�[�g���̉��ړ��P��

int		first_setting;				// �ݒ�t�@�C���̓ǂݍ��݂Ɏ��s������-1�ɂȂ�
int		reload_graphics;			// �ēǂݍ��݃t���O
int		reload_background;
int		reload_se;
int		reload_bgm;

int		repversw;					// ���o�[�W�����̃��v���C���Đ����邽�߂̃X�C�b�`

int		randseed[2];				// �[�������V�[�h
int		firstseed[2];				// �ŏ��̗����V�[�h

int		dummy;						// heboris_user.ini�p

int		maxPlay = 0;				// �v���C�l�� 0=1�l 1=2�l
int		b_maxPlay = 0;				// �v���C�l���̃o�b�N�A�b�v

int		w_reverse = 1;				// 1�ɂ���ƃ��[���h���[���ŉ�]�������t�]������
int		r_irs = 1;					// 1�ɂ���ƐԂ�IRS���̏��R�薳��

int		fldtr = 64;					// �w�i�̔������x
int		skip_viewbg = 0;			// �w�i�Ȃ�

int		tls_view = 0;				// TLS 0=LV100�܂ŕ\�� 1=��ɕ\�� 2=��ɔ�\��

int		world_move_sound = 1;		// WORLD�Őڒn���ɉ��ړ��^��]�����Ƃ��ɐڒn����炷��

int		def_IsBig = 0;				// BIG���[�h
int		def_BigMove = 1;			// BIG���ړ�

int		show_fps = 0;				// FPS��\������
int		lvupbonus = 0;				// 3���C���ȏ�������Ƃ��̃��x���A�b�v�{�[�i�X 0=����(TI) 1=�Ȃ�(TGM/TAP)
int		showctrl = 0;				// ����󋵕\�� 0=���v���C�̂� 1=��ɕ\�� 2=��ɔ�\��
int		use_over1000_block = 1;		// []�̗L��
int		over1000_start = 1000;		// []�̊J�n���x��

int		keyAssign[10 * 2];			// �L�[�{�[�h���蓖��
int		pause_key[2];				// �|�[�Y
int		hnext_key[2];				// NEXT�B��
int		giveup_key;					// �̂ăQ�[
int		ss_key;						// �X�N���[���V���b�g
int		skip_key[2];				// �X�e�[�W�X�L�b�v
int		fps_plus_key;				// FPS+1
int		fps_minus_key;				// FPS-1

int		joykeyAssign[10 * 2];		// �W���C�X�e�B�b�N�{�^�����蓖��
int		joy_pause_key[2];			// �W���C�X�e�B�b�N �|�[�Y
int		joy_hnext_key[2];			// �W���C�X�e�B�b�N NEXT�B��
int		joy_giveup_key[2];			// �W���C�X�e�B�b�N �̂ăQ�[
int		joy_ss_key[2];				// �W���C�X�e�B�b�N �X�N���[���V���b�g
int		joy_skip_key[2];			// �W���C�X�e�B�b�N �X�e�[�W�X�L�b�v
int		joy_fps_plus_key[2];		// �W���C�X�e�B�b�N FPS+1
int		joy_fps_minus_key[2];		// �W���C�X�e�B�b�N FPS-1
int		joykeyButtonNum;			// �W���C�X�e�B�b�N�̃{�^����

int		fps_plus_mpc;				// FPS+1�̉������ςȂ�����
int		fps_minus_mpc;				// FPS-1�̉������ςȂ�����

int		rule_name = 1;				// ���[�����̎�ށi0�A1�A2��3��ށj
int		main_fps = 60;				// �Q�[���S�̂�FPS
int		dispnext = 6;				// NEXT�\����
int		spawn_y_type = 1;			// �u���b�N�̏o���ʒu 0=�g�� 1=�g�O
int		top_frame = 0;				// NEXT���̃O���t�B�b�N�̎��

int		empty_spin_field = 0;		// 1�ɂ���ƎQ���҂��v���C���[�̃t�B�[���h���O���O�����

int		w_lockdown = 1;				// ���[���h���[���̉�]�����̐ݒ�
									// 0=�����񐔈ȏ�񂹂邱�Ƃ����� 1=�����񐔃s�b�^���ŌŒ�

int		pause_visible;				// �|�[�Y���Ƀu���b�N�������邩�ǂ����̐ݒ�

int		screenColor = 16;			// ���݂̐F��

int		ready_count[2];				// READY��GO�̕\����

int		nextskip;					// �c���X�L�b�v�i0=TOMOYO�̂� 1=TOMOYO&FLASH 2=�S���[�h 3=�Ȃ��j

int		fldbgtype;					// �t�B�[���h�ɖԖڂ�\��

int		lastmode[2];				// �Ō�ɑI�񂾃��[�h
int		lasttype[2];				// �Ō�ɑI�񂾃Q�[���^�C�v

int		timer_font_type;			// �^�C���\���̃t�H���g�̎��

int		enable_irs;					// IRS�L���H

int		block_shadow;				// �u���b�N�̉e��\��
int		block_afterimage;			// �u���b�N�̎c����\��
int		ace_frame;					// ACE���[�h�Řg�ɏ����\��
int		disp_waits;					// ���݂̃X�s�[�h��\��

// �^�C�g�����[�r�[
int		title_acnt = 0;				// ���݂̃t���[��
int		title_mov_f = 30;			// �ő�R�}���i0�ɂ���ƐÎ~��j
int		mov_inter = 2;				// 1�R�}��\������t���[����

// �w�i���[�r�[
int		back_acnt = 0;				// ���݂̃t���[��
int		back_mov_f[16];				// �ő�R�}���i0�ɂ���ƐÎ~��j
int		back_mov_inter[16];			// 1�R�}��\������t���[����

int		wsoftlock = 0;				// 1�ɂ���ƃ��[���h���[���ŉ����ꂵ�Ă����Œ�\
int		rot180 = 2;					// 1�ɂ����C�{�^����180�x��] 2�ɂ���ƈꕔ�̃��[���̂�
int		english = 0;				// 0=Japanese 1=English

int		ace_irs;					// �VIRS���g�p���邩�ǂ���

int		always_over1000[2];			// ���[]���o�ꂷ��t���O

int		bgfadesw = 0;				// �w�i�t�F�[�h�X�C�b�`
int		bgfadelv = 0;				// �w�i�t�F�[�h���x��
int		enable_bgfade = 1;			// �w�i�t�F�[�h�� 0=�g��Ȃ� 1=�g��

int		skip_blocklockflash;		// �u���b�N��u�����Ƃ��̌��鉉�o�̎��Ԃ�Z�k
int		refresh_timing;				// ��ʍX�V�^�C�~���O

int		lackblock_grayout;			// 1�̏ꍇ�̓u���b�N�̔j�Ђ��D�F�ɂ���
int		squaremode[2];				// �����`�̗L��
int		squarenum[2];				// ����������`�̐�

/* �t�B�[���h�f�[�^ */
int		fld[10 * 22 * 2];			// �t�B�[���h�̏��  x + y * 10 + pl * 220
int		fldt[10 * 22 * 2];			// �t�B�[���h�^�C�}�[
int		fldi[10 * 22 * 2];			// �t�B�[���h�A�C�e��
int		fldo[10 * 22 * 2];			// �t�B�[���h�u���b�N[]�t���O�ifldo�́uo�v��over1000�̈Ӗ��j
int		flds[10 * 22 * 2];			// �t�B�[���h�u���b�N�ԍ��i�j�Ђ��D�F������Ƃ��Ɏg�p�j

int		fldbuf[10 * 22 * 2];		// �t�B�[���h�o�b�t�@(�~���[�̉��o�Ɏg�p)
int		fldtbuf[10 * 22 * 2];		// �t�B�[���h�^�C�}�[�o�b�t�@(�~���[�̉��o�Ɏg�p)
int		fldibuf[10 * 22 * 2];		// �t�B�[���h�A�C�e���o�b�t�@(�~���[�̉��o�Ɏg�p)
int		fldobuf[10 * 22 * 2];		// �t�B�[���h�u���b�N[]�t���O�o�b�t�@(�~���[�̉��o�Ɏg�p)
int		fldsbuf[10 * 22 * 2];		// �t�B�[���h�u���b�N�ԍ��o�b�t�@(�~���[�̉��o�Ɏg�p)

/* NEXT�u���b�N */
int		next[2];					// ���̃u���b�N
int		nextb[1400 * 2];			// ���̃u���b�N�̃��X�g
int		nextb_fake[1400 * 2];		// ���̃u���b�N�̃��X�g�iFAKE NEXT�p�j
int		nextc[2];					// ���ɍ~��u���b�N�J�E���^
int		nextb_max[2];				// NEXT�u���b�N�̃��[�v�Ԋu
int		nextwork[7 * 2];			// ���ɍ~���Ă���u���b�N�̃_�u���h�~�p

int		c_nblk[6 * 2];				// NEXT�~�m�̐F
int		item_nblk[6 * 2];			// NEXT�~�m�̃A�C�e���t���O
int		o_nblk[6 * 2];				// NEXT�~�m��[]�t���O
int		rt_nblk[6 * 2];				// NEXT�u���b�N�̌���

int		n_bx[2];					// ���̃u���b�N��X���W

int		ndelay[2];					// NEXT�u���b�N�̕\���̒x���p

str		nextb_list;					// TOMOYO���[�h�c�����X�g
str		nextdengen_list;			// �d���p�^�[���̃c�����X�g
str		nextdengen2_list;			// �d���p�^�[���̃c�����X�g2

/* ���쒆�̃u���b�N */
int		blk[2];						// �������Ă���u���b�N
int		bx[2], by[2], rt[2];		// �u���b�N�̍��W
int		c_cblk[2];					// ���쒆�e�g���~�m�̐F�i���쒆�j
int		c_cblk_r[2];				// ���쒆�e�g���~�m�̐F�i�u������j
int		item[2];					// ���݂̃A�C�e��
int		o_cblk[2];					// ���쒆�e�g���~�m��[]�t���O
int		kickc[2];					// ���R��J�E���^
int		kickc2[2];					// ARS�p���R��J�E���^
int		kickc3[2];					// ��]�J�E���^

/* HOLD�u���b�N */
int		hold[2];					// HOLD���̃~�m
int		dhold[2];					// HOLD�s��
int		dhold2[2];					// HOLD�s�i�u���b�N�I�[�_�[�p�j
int		hold_used[2];				// HOLD������
int		c_hblk[2];					// HOLD�~�m�̐F
int		item_hblk[2];				// HOLD�~�m�̃A�C�e���t���O
int		o_hblk[2];					// HOLD�~�m��[]�t���O

int		disable_hold;				// HOLD����
int		enable_item_hold;			// �A�C�e�����z�[���h�ł��邩
int		hold_sound;					// HOLD������^�C�~���O(0:�Ȃ� 1:IHS 2:��IHS 3:����)
int		holdframetype;				// HOLD����o�����u���b�N�̘g�̎�� 0:���� 1:�ׂ� 2:�Ȃ�

/* �������x�ƃ��x�� */
int		sp[2];						// �����X�s�[�h
int		wait1[2], wait2[2];			// �Œ聨���E���Ŏ��̑҂�����
int		wait3[2], waitt[2];			// �ݒu����Œ�܂ł̃^�C���E�����ߎ���
int		bs[2], bk[2];				// �u���b�N�̎��R�����Ƃ������̃^�C��
int		tc[2];						// ���݂̃��x��
int		tr[2];						// 10LV���Ƃ�1������i��ɑ��x�㏸�p�j
int		speedtype[2];				// �����X�s�[�h�̎��

int		b_wait1[2], b_wait2[2];		// [�o�b�N�A�b�v] �Œ聨���E���Ŏ��̑҂�����
int		b_wait3[2], b_waitt[2];		// [�o�b�N�A�b�v] �ݒu����Œ�܂ł̃^�C���E�����ߎ���
int		b_sp[2];					// [�o�b�N�A�b�v] �������x
int		b_speedtype[2];				// [�o�b�N�A�b�v] �����X�s�[�h�̎��

/* �X�R�A */
int		hide_score;					// �X�R�A��\��
int		sc[2];						// �X�R�A
int		sdrop[2];					// �X�R�A�v�Z�p�i�n�[�h�h���b�v�j
int		qdrop[2];					// �X�R�A�v�Z�p�i�\�t�g�h���b�v�j
int		cmbpts[2];					// �X�R�A�v�Z�p�i�R���{�j

/* ���C�� */
int		erase[22 * 2];				// �������u���b�N
int		li[2];						// ���C����
int		endlines[2];				// ���[�����ɏ�������
int		c_norm[2];					// �B���m���}
int		m_norm[2];					// �ڕW�m���}
int		line_count[4 * 2];			// ���C�������񐔁i�V���O���A�_�u���A�g���v���A�w�{���X�̏��j
int		skill[2];					// 4�i����������
int		lastblkline[2];				// �Ō�Ƀu���b�N��u�����Ƃ����������C����

int		enable_disp_lastline;		// ���C����������\�����邩�ǂ���
int		lastline[2];				// �Ō�̃��C���������̃��C����
int		lastline_frame[2];			// �\������c��t���[��

int		disp_lineinfo;				// ���C�������񐔂�\�����邩�ǂ���
int		d_disp_lineinfo;		// disp_lineinfo���f�t�H���g��ON���ǂ���

/* �R���{ */
int		combo[2], hebocombo[2];		// �R���{
int		combo2[2];					// 1���C���������J�E���g���Ȃ��R���{
int		tcombo[2];					// T-Spin�R���{
int		enable_combo;				// �R���{�{�[�i�X�̗L��
int		display_combo;				// �R���{�\���̗L��

/* BACK TO BACK */
int		b_to_b[2];					// BACK TO BACK�t���O
int		b_to_b_count[2];			// BACK TO BACK��
int		b_to_b_frame[2];			// BACK TO BACK�\���t���[��
int		enable_b_to_b = 0;			// BACK TO BACK���L�����ǂ���
int		bonus_btb = 0;				// BACK TO BACK�{�[�i�X�̗L��

/* T-SPIN */
int		IsTspin[2];					// T-SPIN�������ǂ���
int		last_command[2];			// �Ō�ɂ�������i0=���E�ړ� 1=�󒆂ŉ�] 2=�ڒn��Ԃŉ�] 3=�����j
int		tspin_frame[2];				// T-SPIN�\���t���[����
int		tspin_count[4 * 2];			// T-SPIN�񐔁i���C���Ȃ��A�V���O���A�_�u���A�g���v���̏��j
int		tspin_kick[2];				// 3-CORNER NO KICK��T-SPIN����p�iT-SPIN�����t���O�j
int		lasttspin[2];				// �Ō�ɂ���T-SPIN�̎��
int		tspin_type = 1;				// T-SPIN�̔�����@
int		bonus_tspin = 0;			// T-SPIN�{�[�i�X�̗L��

/* �L�[���� */
int		mp[2], mpc[2], mps[2 * 2];	// �O��̃p�b�h�̓��͓��e�Ǝ���
int		mp2[2], mpc2[2];			//hoge �O��̃p�b�h�̓��͓��e�Ǝ���(�㉺�L�[�o�[�W����)
int		down_flag[2];				// 0:�O�񁫂��g���ĂȂ�or���𗣂��� 1:�O�񁫂��g����
int		up_flag[2];					// 0:�O�񁪂��g���ĂȂ�or���𗣂��� 1:�O�񁪂��g����
int		harddrop[2];				// �n�[�h�h���b�v�g�p�t���O
int		softdrop[2];				// �\�t�g�h���b�v�g�p�t���O
int		downtype = 1;				// �����ꁕ�����ɐ�����݂��邩�ǂ����i2=20G���̂ݐ����j
int		last_mp_check[2];			// �Ō�ɉ����߂��`�F�b�N�����t���[��
									//�i1�t���[����2��ȏ㉡���ߏ������s����̂�h���j

/* DRS */
int		bk_D[2];					// DRS�p�����ꎞ��
int		drs_floorkick = 0;			// DRS��ARS�n�Ɠ������R�������
int		are_skipflag[2];			// �������Ԓ���ARE�X�L�b�v�g�p�t���O

/* �i�� */
int		grade[2];					// ���݂̒i��
int		gpoint[2];					// ���݂̒i�ʃ|�C���g
int		gtime[2];					// �i�ʃ|�C���g�����^�C�}�[
int		gflash[2];					// �i�ʂ��オ�������ɕ\�������点�鎞�Ɏg�p

int		gradetype[2];				// �i�ʃ^�C�v 0=NORMAL 1=HARD 2=EASY
int		hide_grade = 0;				// �i�ʔ�\��

int		min_sgrade = 4;				// ���̒i���痠�i�ʂ�\��

int		gskill[2];					// �i�ʂŎg��4�i������
int		gskbai[2];					// gskill�Ō��܂�i�ʏ㏸�{��

int		tc_20g[2];					// MASTER-HARD�ł�BGM�t�F�[�h�A�E�g�\�背�x���iCOOL���o���ƑO�|���j
int		regretcancel[2];			// REGRET���o�Ă����x���x���Ȃ�Ȃ��t���O�i1�Ȗځ�2�Ȗڂ̂Ƃ���1�ɂȂ�j

int		show_gpoint = 0;			// 1�ɂ���ƒi�ʃ|�C���g��������

int		time99[2];					// ���x���X�g�b�v����
int		timeN[2];					// �u���b�N�𑀍삵�Ă��鎞��(0-98)
int		ave_laptime3[2];			// �Z�N�V�����̕��ψړ�����
int		gup3rank[2];				// �����N0-2
int		gup3sp_adjust[2];			// �����N�ɂ��킹�ăX�s�[�h����(0:��蒼�� 1:�ʏ� 2:�X�L�b�v)
int		qualityflag[2];				// 2��ȏ�o�Ȃ��悤��
int		skillflag[2];
int		tr2[2];						// �ϑ����x��
int		tr_20g[2];					// 20G�ɂȂ����Ƃ���tr�̒l
int		border_rank[2];

int		gup_down[2];				// COOL��REGRET�̕\���Ɏg�p 0=�~�i 1=���i
int		gmflag1[2];					// Gm�����t���O1
int		gmflag2[2];					// Gm�����t���O2
int		gmflag1_e[2];				// gmflag1�̔�����������ǂ����̃t���O
int		gmflag2_e[2];				// gmflag2�̔�����������ǂ����̃t���O
int		gmflag_r[2];				// ���[���N���A��GM�ɂȂ錠���̂悤�Ȃ���

/* ���_�� */
int		medal_ac[2];				// AC���_��
int		medal_st[2];				// ST���_��
int		medal_sk[2];				// SK���_��
int		medal_co[2];				// CO���_��
int		medal_visible_ac[2];		// ���_���\���t���O
int		medal_visible_st[2];
int		medal_visible_sk[2];
int		medal_visible_co[2];

/* ���؂� */
int		timelimit[2 * 2];			// ���؂�^�C��
									// [0 + player * 2] = LV500�̑��؂�^�C��
									// [1 + player * 2] = LV1000�̑��؂�^�C��

int		timelimit_master[10];		// MASTER���[�h
int		timelimit_20G[10];			// 20G���[�h
int		timelimit_deviln[10];		// DEVIL-NORMAL���[�h
int		timelimit_devilh[10];		// DEVIL-HARD���[�h
int		timelimit_devild[10];		// DEVIL-DOOM���[�h

/* �G���f�B���O */
int		ending[2];					// �G���f�B���O�����ǂ���
int		edrec[2];					// �G���f�B���O�o�ߎ���
int		fastroll[2];				// 1�̏ꍇ�͍������[��
int		end_f[2];					// ���S�N���A�t���O
int		endingcnt[2];				// �G���f�B���O���̉ԉΔ�����
int		ending_timeOn[2];			// �G���f�B���O�^�C�}�[���L�����ǂ���
int		ending_timelimit = 60 * 60;	// �G���f�B���O�̎���
int		sound_ending_loop;			// �G���f�B���O�Ȃ����[�v�����邩�ǂ���
int		sound_beginner_ending_loop;	// BEGINNER�̃G���f�B���O�Ȃ����[�v�����邩�ǂ���
int		staff_c[2];					// �X�^�b�t���[���J�E���^
int		endtime[2];					// �X�^�b�t���[���o�ߎ���
int		staff_type[2];				// �X�^�b�t���[���̉摜�̎�ށi0��1�j

/* ����オ�� */
int		upLines[2];					// �㏸���Ă��܂����C����
int		hole;						// �ΐ�̂Ƃ��̌��̈ʒu
int		uplinetype[2];				// ����オ��^�C�v
int		r_bdowncnt[2];				// �u���b�N��u�����񐔁i����オ��p�j

int		r_enable[2];				// ����オ��L���^����
int		r_start[2];					// ����オ��J�n���x��
int		r_end[2];					// ����オ��I�����x��
int		r_inter[2];					// ����オ��Ԋu
int		def_rise_enable = 0;		// ����オ��f�t�H���g�l
int		def_rise_start  = 500;
int		def_rise_end    = 999;
int		def_rise_inter  = 20;

int		b_r_enable[2];				// ����オ��L���^�����̃o�b�N�A�b�v

int		ghole[2];					// GARBAGE�~�b�V�����̂Ƃ��̌��̈ʒu
int		upLineNo[2];				// ����オ�胉�C��No
int		upLineNoMax = 32;			// ����オ��t�B�[���h�̃��C������
int		upFld[256];					// ����オ��t�B�[���h�z��(����͍��̂Ƃ���128���C��)

int		risecount[2];				// ����オ�肪��������܂ł̃J�E���g

int		fldu[10 * 22 * 2];			// ����オ��t�B�[���h�i����オ��u���b�N�̌`����L���j

int		show_rise_num;				// 1�ɂ���Ƃ���オ�莞�ɂ���オ�郉�C������\��

int		devil_doom_n_rise = 0;		// 1�ɂ����DEVIL-DOOM�ł���オ��Ԋu�����ɂ���

/* �Z�N�V�����^�C�� */
int		sectionTimer[2];			// ���݂̃Z�N�V�����^�C���i�Z�N�V�������؂�ւ�邽�тɃ��Z�b�g�j
int		now_sttime[30 * 2];			// �Z�N�V�����^�C���L�^
int		show_section_time = 0;		// �Z�N�V�����^�C����\�����邩�ǂ���
int		section_time_offset = 0;	// �Z�N�V�����^�C���\���ʒu

/* HIDDEN */
int		hidden[2];
int		hidden_old[2], hiddentm[2], hiddeny[2], hiddenti[2], hiddenc[2];
int		b_hidden_old[2];
int		shadowtime[2];		// �u���b�N�������鎞��
int		b_shadowtime[2];	// ���̃o�b�N�A�b�v
int		hidden_b_type;		// 1����HIDDEN-B�Ńu���b�N��u�����u�Ԃ̘g����\�����Ȃ�

/* CPU�ƃi�r�Q�[�V�����V�X�e�� */
int		cpu_best_x[2];				// �őP���X���W
int		cpu_best_y[2];				// �őP���Y���W
int		cpu_best_r[2];				// �őP��̃u���b�N�̕���
int		cpu_best_p[2];				// �őP��̕]���_
int		cpu_ctrl[10 * 2];			// �R���s���[�^�̑�����e
int		cpu_flag[2];				// �R���s���[�^�����삷�邩�ǂ���
int		cpu_level[2];				// �R���s���[�^�̃��x��
int		b_cpu_flag[2];				// [�o�b�N�A�b�v] �R���s���[�^�����삷�邩�ǂ���
int		b_cpu_level[2];				// [�o�b�N�A�b�v] �R���s���[�^�̃��x��
int		cpu_hold[2];				// HOLD���邩�ǂ���
int		cpu_frame[2];				// CPU���Ō�ɑ��삵���t���[��

int		enable_navigation = 1;		// �i�r�Q�[�V�����V�X�e���̗L���^����
									// 0=���� 1=BEGINNER�̂ݗL�� 2=�S�Ẵ��[�h�ŗL��
int		limit_navigation = 100;		// ���̃��x�����߂���ƃi�r�Q�[�V�����I��

int		navigation_time[2];			// �i�r�Q�[�V�����^�C�}�[
int		limit_time_navigation = 60;	// �i�r�Q�[�V�����u���b�N�̕\������

int		cpu_enable_setting[2];		// VS���[�h�ȊO�ł̃R���s���[�^��ON/OFF
int		cpu_default_level[2];		// VS���[�h�ȊO�ł̃R���s���[�^�̃��x��

/* READY��GO�̑҂����� */
int		ready_start[2];				// ready�J�n
int		ready_end[2];				// ready�I��
int		go_start[2];				// go�J�n
int		go_end[2];					// go�I��

int		n_ready_start = 0;			// �ʏ� ready�J�n
int		n_ready_end = 50;			// �ʏ� ready�I��
int		n_go_start = 55;			// �ʏ� go�J�n
int		n_go_end = 100;				// �ʏ� go�I��

int		s_ready_start = 15;			// TOMOYO ready�J�n
int		s_ready_end = 30;			// TOMOYO ready�I��
int		s_go_start = 135;			// TOMOYO go�J�n
int		s_go_end = 150;				// TOMOYO go�I��

/* ���[�� */
int		rots[2];					// ���݂̃��[��

int		def_rule_rot[9]        = {0, 0, 1, 1, 0, 0, 1, 1, 2};			// ��]�@�� (0:ARS 1:SRS 2:DRS)
int		def_rule_hard_lock[9]  = {0, 0, 1, 1, 1, 0, 1, 0, 1};			// �n�[�h�h���b�v�ŌŒ�
int		def_rule_soft_lock[9]  = {1, 1, 0, 0, 0, 1, 0, 1, 2};			// �\�t�g�h���b�v�ŌŒ� (2��1G�ȏ�)
int		def_rule_soft_speed[9] = {1, 1, 1, 0, 0, 0, 0, 2, 2};			// �\�t�g�h���b�v�̑��x
int		def_rule_are[9]        = {1, 1, 1, 1, 1, 1, 0, 1, 2};			// ARE�̗L���i2�̓L�����Z���@�\�t���j
int		def_rule_color[9]      = {0, 0, 1, 1, 1, 1, 1, 1, 0};			// �u���b�N�̐F
int		def_rule_lock_reset[9] = {0, 0, 1, 1, 1, 1, 1, 1, 0};			// �ڒn���Ɉړ��܂��͉�]�ŌŒ莞�ԃ��Z�b�g
int		def_rule_lock_sound[9] = {0, 0, 0, 1, 1, 1, 1, 0, 0};			// �����ŌŒ肵���Ƃ��ɉ���炷
int		def_rule_ars_extrot[9] = {0, 1, 1, 1, 1, 1, 1, 1, 1};			// �ʂƖ_�����R�肷�邩�ǂ���(ARS�̏ꍇ)
int		def_rule_lock_limit[9] = {0, 0, 10, 128, 128, 128, 0, 24, 0};	// �ڒn��Ԃňړ��ł���� (0�Ŗ���)
int		def_rule_graphics[9]   = {0, 1, 2, 2, 1, 1, 3, 4, 7};			// �u���b�N�̖͗l
int		def_rule_rot_limit[9]  = {0, 0, 8, 128, 128, 128, 0, 12, 0};	// �ڒn��Ԃŉ�]�ł���� (0�Ŗ���)
int		def_rule_180rot[9]     = {0, 0, 0, 0, 0, 0, 0, 1, 1};			// 180�x��]
int		def_rule_max_waitt[9]  = {99, 99, 99, 99, 99, 99, 10, 99, 10};	// �����ߍő�i99�Ŗ������j
int		def_rule_oblk_bg[9]    = {0, 0, 0, 0, 0, 0, 1, 0, 0};			// []�̎��̔w�i�i0:�Ȃ� 1:�� 2:���j

int		rule_rot[10];				// ���̃��[�����e�iCUSTOM�ȊO�́�����R�s�[�����j
int		rule_hard_lock[10];
int		rule_soft_lock[10];
int		rule_soft_speed[10];
int		rule_are[10];
int		rule_color[10];
int		rule_lock_reset[10];
int		rule_lock_sound[10];
int		rule_ars_extrot[10];
int		rule_lock_limit[10];
int		rule_graphics[10];
int		rule_rot_limit[10];
int		rule_180rot[10];
int		rule_max_waitt[10];
int		rule_oblk_bg[10];

/* �t�B�[���h�ʒu */
int		foffset[2];					// �t�B�[���h�̕\���ʒu
int		boffset[2];					// �u���b�N�⃁�j���[�̕\���ʒu
int		soffset[2];					// �X�R�A�̕\���ʒu
int		toffset[2];					// �uT-SPIN�v�uBACK TO BACK�v�Ȃǂ̕\���ʒu
int		moffset;					// MISSION���[�h�̎w�ߕ\���̈ʒu

int		s_foffset = 112;			// SINGLE��p
int		s_boffset = 15;
int		s_soffset = 26;
int		s_toffset = 14;
int		s_moffset = 0;

int		d_foffset[2] = {16, 168};	// DUAL��p
int		d_boffset[2] = { 3,  22};
int		d_soffset[2] = {14,  33};
int		d_toffset[2] = { 2,  21};
int		d_moffset = 208;

int		v_foffset[2] = {16, 208};	// VERSUS���[�h�p
int		v_boffset[2] = { 3,  27};

int		b_foffset[2];				// VERSUS����o���Ƃ��A���̃t�B�[���h�ʒu�ɖ߂����p�̃o�b�N�A�b�v
int		b_boffset[2];

int		ofs_x[2];					// �t�B�[���h�����ɗh�炷�p
int		ofs_y[2];					// �t�B�[���h���c�ɗh�炷�p

int		coffset;					// ����󋵕\���̕\���ʒu
int		s_coffset = 14;				// SINGLE�p
int		d_coffset = 176;			// DUAL�p
int		s_m_coffset = 221;			// SINGLE(MISSION)�p
int		d_m_coffset = 115;			// DUAL(MISSION)�p

/* ���o */
int		obj[100], objx[100], objy[100], objv[100], objw[100], objj[100], objc[100];
int		obja[100], objp[100];

int		breakeffect = 2;			// �j��G�t�F�N�g 0=�Ȃ� 1=HEBORIS/TGM 2=TAP/TI(�V) 3=TAP/TI(��)
int		breakmax = 100;				// ��ʓ��ɕ\���\�ȃG�t�F�N�g�̐��i0�`100�j

int		breakgraphics = 1;			// breakeffect = 2�̂Ƃ��̊G�̎��
int		beginner_effect;			// BEGINNER���[�h�̏����G�t�F�N�g���uPOP OUT�v�ŌŒ�

int		beffect_speed;				// �j��G�t�F�N�g�̑��x 0=���� 1�ȏ�=�펞n�{��

/* �ԉ� */
int		hanabi_waiting[2];			// �����҂��ԉΐ�
int		hanabi_frame[2];			// ��������܂ł̃t���[����
int		hanabi_combo[2];			// HANABI�R���{�␳�p�L����
int		hanabi_int[2];				// BEGINNER���[�����̉ԉΑł��グ�Ԋu

/* �T�E���h */
int		bgmlv = 0;					// ���݂�BGM
int		fadelv = 0;					// �t�F�[�h�A�E�g�p
int		bgm_change = 0;				// BGM��؂�ւ�����
int		bgm = 0;					// BGM (0=�Ȃ� 1=MIDI 2=WAV 3=MP3 4=MIDI(MULTI))
int		se = 1;						// ���ʉ��̗L��
int		rotate_sound = 0;			// ��]���̗L��
int		move_sound = 0;				// �ړ����̗L��
int		sevolume = -100;			// ���ʉ��̉���
int		bgmvolume = 0;				// BGM�̉���
int		fadesetting;				// BGM�t�F�[�h�ɂ����鎞��

int		bgm_loop_start[21];			// BGM�̃��[�v�J�n�n�_�i-1:�Ȃ��j
int		bgm_loop_end[21];			// BGM�̃��[�v�I���n�_�i�����ɗ�����start�̏��ɖ߂�j

int		start_bgmlv[2];				// STANDARD�Ŏg����BGM���L�^
int		b_bgmlv;					// bgmlv�̃o�b�N�A�b�v

str		music_file_name[21];		// BGM�̃t�@�C�����iheboris.ini�Ŏw��j

int		se_play[60];				// ���ʉ��Đ��\��t���O

/* ���v���C */
int		replayData[60 * 60 * 20];		// ���v���C�ۑ��p�f�[�^ (�ő�20���܂�)
int		replayData2[60 * 60 * 20];		// 2P�p���v���C�ۑ��p�f�[�^
int		playback = 0;					// ���v���C����?
int		onRecord[2];					// ���v���C�L�^���t���O
int		time2[2];						// ���v���C�L�^�p�J�E���^
int		replayauto;						// ���v���C�������c�t���O�i0�ɂ���Ǝ蓮���c�j
int		show_endmenu;					// �Q�[���I�[�o�[��Ƀ��v���C�Z�[�u��ʂ��o��
int		replay_autosave;				// ���v���C�������Z�[�u
int		replayno;						// ���݌��Ă��郊�v���C�̔ԍ��i41=�����Z�[�u���ꂽ�Ō�̃v���C�j

int		enable[41];						// ���v���C�����݂��邩�ǂ���
int		replay_gamemode[41];			// ���v���C�I����ʗp
int		replay_score[41];
int		replay_time[41];
int		replay_level[41];
int		replay_rots[41];
int		replay_tt[41];
int		replay_other[41];

/* �f����� */
int		demo = 0;						// �f�����[�h��?
int		demotime;						// �f����ʌo�ߎ���
int		demokind = -1;					// �f���̎��

/* PRACTICE���[�h�֘A�̕ϐ� */
str*	waitname[20];				// �ݒ薼

int		syutugen[20],				// �u���b�N���Œ肳��Ă���A���̃u���b�N���o������܂ł̎���
		syoukyo[20],				// �u���b�N����񑵂����Ƃ��̏��ł̑҂�����
		settyaku[20],				// �u���b�N���n�ʂɓ��B���Ă���A�ڒ������܂ł̎��ԁB99�ɂ���Ɩ���
		yokotame[20],				// �����߂ɕK�v�Ȏ���
		speed[20],					// �������x
		fps[20],					// FPS
		pbgm[20],					// BGM
		waitkey[20];				// �V���[�g�J�b�g�L�[

int		p_setting = 0;				// ���݂̐ݒ�
int		p_def_setting = 0;			// �f�t�H���g�̐ݒ�

int		b_hidden[2];				// �e��M�~�b�NON/OFF�t���O�̃o�b�N�A�b�v
int		b_isfmirror[2];
int		b_isrollroll[2];
int		b_isxray[2];
int		b_iscolor[2];
int		b_isblind[2];
int		b_isthunder[2];
int		b_isUDLRreverse[2];
int		b_isRotateLock[2];
int		b_ishidenext[2];
int		b_heboGB[2];
int		b_squaremode[2];

int		p_backno = 0;				// PRACTICE���[�h�̔w�i
int		p_fps = 60;					// PRACTICE���[�h�p��FPS

int		vslevel[2];					// �J�[�\���ʒu

int		p_leveltype;				// ���x���A�b�v�̎��
int		p_timelimit;				// ��������
int		p_goal;						// �S�[��
int		p_staffroll;				// �X�^�b�t���[���̗L��

int		p_def_leveltype;			// ���x���A�b�v�̎�ނ̃f�t�H���g
int		p_def_timelimit;			// �������Ԃ̃f�t�H���g
int		p_def_goal;					// �S�[���̃f�t�H���g
int		p_def_staffroll;			// �X�^�b�t���[���̗L���̃f�t�H���g

int		p_replay_save_enable;		// ���v���C�Z�[�u�\�t���O

/* TOMOYO���[�h�^FLASH���[�h�֘A�̕ϐ� */
int		stage[2];					// �X�e�[�W�ԍ�
int		sclear[2];					// �X�e�[�W�N���A������
int		rest_pblock[2];				// �c��v���`�i�u���b�N��

int		stime[2];					// �X�e�[�W�^�C��
int		ltime[2];					// ���~�b�g�^�C���iACE���[�h�Ȃǂł��g�p�j

int		clearnum[2];				// �^�C���I�[�o�[�^�X�L�b�v�����ɃN���A�����X�e�[�W��
int		clearp[2];					// �N���A��

int		pass_flg[2];				// �c������t���O(�A�����͖h�~�p)

int		start_stage[2];				// �ǂ̃X�e�[�W����n�߂���
int		start_nextc[2];				// �X�^�[�g����nextc

int		laststage[2];				// TOMOYO���[�h�̍ŏI�X�e�[�W

int		stage_nextc[2];				// �X�e�[�W�J�n����nextc

int		stage_skip_frame[20 * 2];	// �X�e�[�W�X�L�b�v���g�����t���[��
int		stage_skip_used[2];			// �X�e�[�W�X�L�b�v���g������

int		stage_skip_mpc[2];			// �X�e�[�W�X�L�b�v�L�[�������Ă��鎞��
int		stage_skip_tame = 60;		// ���̃t���[���ȏ�X�e�[�W�X�L�b�v�L�[�������Â���ƃX�L�b�v����

int		flash_bonus_points[2];		// FLASH���[�h�̃{�[�i�X�_
int		flash_bonus_count[2];		// �{�[�i�X�_�����J�E���^
int		flash_continue[2];			// �R���e�B�j���[�g�p�t���O
int		flash_cont_stage[2];		// �R���e�B�j���[�����Ƃ��̕����n�_�i2��ȏ�A���Ŏ��s�����Ƃ��ɐ�ɐi�܂��Ȃ��j
int		flash_edit[2];				// FLASH-EDIT���ǂ���

int		tomoyo_waits[2];			// DEVIL500�M�~�b�NON/OFF
int		min_speed[2];				// TOMOYO���[�h�̍Œ�X�s�[�h
int		enable_minspeed = 0;		// TOMOYO���[�h�ŃX�s�[�h������L���ɂ��邩�ǂ���

int		tomoyo_rise_fld[10 * 20 * 2];	// TOMOYO�p����オ��t�B�[���h �ő�20�i
int		tomoyo_rise[2];					// ����オ��ON/OFF������オ��Ԋu
int		tomoyo_rise_t[2];				// ����オ��J�E���g
int		tomoyo_rise_edit[2];			// TOMOYO����オ��G�f�B�^�t���O

int		tomoyo_timebonus[2];		// TOMOYO �^�C�������̗L��
int		tomoyo_no_stage_time[2];	// 1�̏ꍇ�̓X�e�[�W�^�C������
int		tomoyo_bgm[2];				// TOMOYO��BGM

int		tomoyo_dual[2];				// TOMOYO EHEART���X�g�X�e�[�W�M�~�b�N
int		tomoyo_dual_enable[2];		// �����X�g�X�e�[�W�M�~�b�N���L�����ǂ���
int		tomoyo_ehfinal_c[2];		// TOMOYO EHEART���X�g�X�e�[�W�M�~�b�N�p�̃J�E���^

int		tomoyo_ltime_over[2];		// 1�̏ꍇ�̓��~�b�g�^�C�����؂�Ă��u���b�N��u���܂ł̓v���C���s

int		tomoyo_clear_erase;			// 1�̏ꍇ��TOMOYO���[�h�ŃX�e�[�W�N���A���Ƀu���b�N���������o���o��

int		platinaerase_cnt[2];		// �v���`�i�u���b�N�����T�E���h��炷��
int		ext_s[2];					// ���ԑ����̉��o�i�\���j�p
int		timeextend_snd_cnt[2];		// ���ԑ����̉��o�iSE�j�p

/* MISSION���[�h�̕ϐ� */
int		c_mission = 0;				// ���݂̃~�b�V�����ԍ�
int		mission_file = 0;			// �t�@�C���ԍ�
int		clear_mission = 0;			// �~�b�V�������N���A�����Ƃ��̏��������C����

int		mission_type[30];			// ���̎��
int		mission_norm[30];			// ���̃m���}
int		mission_time[30];			// ���̐�������
int		mission_end[30];			// �G���f�B���O�t���O
int		mission_lv[30];				// �������x���x��
int		mission_erase[30];			// �ォ��������郉�C����
int		mission_opt_1[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����P
int		mission_opt_2[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����Q
int		mission_opt_3[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����R
int		mission_bgm[30];			// BGM
int		mission_opt_4[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����S
int		mission_opt_5[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����T
int		mission_opt_6[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����U
int		mission_bg[30];				// �w�i
int		mission_opt_7[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����V
int		mission_opt_8[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����W
int		mission_opt_9[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����X
int		mission_opt_10[30];			// �~�b�V�����ɂ���ĈقȂ�ǉ����10
int		mission_hide_info;			// ��ʍ��̎w�߂�\�����Ȃ��t���O
int		mission_clear_anim;			// �I�[���N���A���ɏo�鉉�o�̎��

int		cycle[4];					// �T�C�N���p
int		target_cleared[1000];		// �^�[�Q�b�g�̃X�e�[�W�o���ς݃t���O�i�����ʂ��܂��o��̂�h���j

int		eraser_lines[4];			// �C���C�T�[�̃��C���ʒu
int		eraser_cleared[4];			// ���ɏ��������ǂ����̃t���O
int		eraser_now_lines;			// ���݉�ʓ��ɑ��݂��Ă���C���C�T�[�̃��C���̐�
int		eraser_now_pattern = 0;		// �C���C�T�[�̌��݂̃p�^�[��

int		start_mission = 0;			// �ǂ̃~�b�V��������n�߂���
int		mission_extra = 0;			// �~�b�V������EX�X�e�[�W�֍s������
int		mission_clear_flag = 0;		// �~�b�V�����N���A��̏����Ŏg�p

str		mission_course_name;		// �~�b�V�������[�h�̃R�[�X��

/* �A�C�e����M�~�b�N�̕ϐ� */
int		item_name[2];				// �t�B�[���h�E��ɕ\������A�C�e����
int		item_g[2];					// �A�C�e���Q�[�W
int		item_t[2];					// �A�C�e���̌��ʎ���
int		item_coming[2];				// �o���҂��A�C�e��
int		item_waiting[2];			// �����҂��A�C�e��
int		itemappear_c[2];			// �A�C�e���Q�[�W�����鉉�o�p
int		item_mode[2];				// �A�C�e��ON/OFF
int		b_item_mode[2];				// �A�C�e��ON/OFF�̃o�b�N�A�b�v
int		item_interval = 20;			// �A�C�e�����o������Ԋu
int		item_all[2];				// �o������\���̂���A�C�e���̎�ނ̐�
int		item_timer[2];				// �������A�C�e���̃^�C�}�[

int		isfmirror[2];				// ���݂̖ʂ��~���[��
int		fmirror_cnt[2];				// �~���[�p�J�E���^
int		p_fmirror_interval = 3;		// �t�B�[���h�~���[�Ԋu
int		p_fmirror_timer = 10;		// �t�B�[���h�~���[�^�C�}�[(�~���[���ɂ����鎞��) 
int		stopmirror_flag[2];			// �~���[��~�t���O
int		field_spin[2];				// �t�B�[���h�g�̉�]�󋵁i-1�܂���20�F��]���ĂȂ��j

int		rollroll_flag[2];			// ���݂̖ʂ����[�����[����
int		isrollroll[2];				// ���݂̃c�������[�����[����
int		p_rollroll_interval = 4;	// ���[�����[���Ԋu
int		p_rollroll_timer = 30;		// ���[�����[���^�C�}�[(��]����܂ł̎���) 

// X-RAY�p
int		xray_flag[2];				// ���݂̖ʂ�X-RAY��
int		isxray[2];					// ����X-RAY��Ԃ�
int		xray_counter[2];			// X-RAY�p�J�E���^
int		p_xray_interval = 2;		// X-RAY�Ԋu
int		p_xray_frame = 36;			// X-RAY�����t���[����

// COLOR�p
int		color_tbl[40] = {
	10, 10, 9, 9, 8, 8, 8, 7, 7, 7,
	6, 6, 6, 5, 5, 5, 4, 4, 4, 4,
	3, 3, 3, 3, 2, 2, 2, 2, 1, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0
};

int		color_flag[2];				// ���݂̖ʂ�COLOR��
int		iscolor[2];					// ����COLOR��Ԃ�
int		color_counter[2];			// COLOR�p�J�E���^

int		isblind[2];					// ��BLIND��Ԃ��ǂ���
int		blind_flag[2];				// ���̖ʂł�BLIND�̗L��

int		isRotateLock[2];			// ��]�s��

int		ishidenext[2];				// NEXT�s��
int		hnext_flag[2];				// HIDE NEXT�M�~�b�NON/OFF
int		hnext_timer[2];				// HIDE NEXT�p�^�C�}�[

int		ismagnetblock[2];			// MAGNET BLOCK
int		istimestop[2];				// TIME STOP
int		isholdlock[2];				// HOLD LOCK

int		isUDLRreverse[2];			// �㉺���E�t�]
int		isUDreverse[2];				// ���� REVERSE
int		isLRreverse[2];				// ���� REVERSE

int		isboost[2];					// BOOST FIRE
int		boostbak_sp[2];				// ���x�̃o�b�N�A�b�v(BOOST FIRE�p)
int		boostbak_settyaku[2];		// �ڒ����Ԃ̃o�b�N�A�b�v(BOOST FIRE�p)

int		isfever[2];					// FEVER!!
int		isremote[2];				// REMOTE CONTROL
int		isdark[2];					// DARK BLOCK
int		isUPdelfield[2];			// �� DEL FIELD
int		isDWdelfield[2];			// �� DEL FIELD
int		isdeleven[2];				// DEL EVEN
int		istrance[2];				// TRANCE FORM

int		dolaser[2];					// LASER
int		lasernum[2];				// ���[�U�[�̖{��
int		laserpos[4 * 2];			// ���[�U�[�ʒu
int		rapid_c[2];					// �{�^���A�Ő��i���[�U�[�̑����Ɏg�p�j

int		donega[2];					// NEGA FIELD

int		doshotgun[2];				// SHOT GUN!
int		shotgunpos[22 * 2];

int		doexchg[2];					// EXCHG FIELD

int		isbanana[2];				// SHUFFLE FIELD
int		banana_pos[10 * 2];
int		banana_c[2];

int		dorulet[2];					// RANDOM

int		isFreefall[2];				// FREE FALL
int		Ff_rerise[2];				// FREE FALL�Ă���オ�胉�C����
int		enable_ff_rerise;			// 1�̏ꍇ��FREE FALL��ɍĂ���オ��

int		isLmovfield[2];				// �� MOV FIELD
int		isRmovfield[2];				// �� MOV FIELD
int		do180field[2];				// 180�KFIELD

int		do16t[2];					// 16t
int		isreflect[2];				// REFLECT
int		isdouble[2];				// DOUBLE
int		isallclear[2];				// ALL CLEAR
int		ismiss[2];					// MISS
int		docopyfld[2];				// COPY FIELD
int		isfakenext[2];				// FAKE NEXT
int		item_monochrome[2];			// [] BLOCK

int		isthunder[2];				// THUNDER�M�~�b�N��ON/OFF
int		thunder_timer;

int		heboGB[2];					// �I�[���h�X�^�C��

int		item_num;					// �A�C�e���̑���
int		item_switch[39];			// ����̃A�C�e�����o�����邩�ǂ���

int		item_gauge_uptype;			// 1�̏ꍇ�̓��C���������ƃA�C�e���Q�[�W�㏸

int		itemhistory[2 * 5];			// �A�C�e���̗���

int		item_pro[50] = 				// �A�C�e���o����
{
	5,8,5,9,6,3,5,4,6,8,
	4,7,5,6,5,3,6,6,5,4,
	9,1,5,1,7,7,8,3,3,5,
	7,4,3,3,1,5,3,2,7,5,
	5,5,5,5,5,5,5,5,5,5
};

int		item_pronum;				// item_pro�̍��v�i�����v�Z�j

/* VERSUS���[�h�̕ϐ� */
int		vs_goal_level;				// VS���[�h�̃S�[�����x���i0:�Ȃ��j
int		vs_goal_type;				// VS���[�h�̃S�[����ށi0:���x�� 1:���C�� 2:�}���\���j
int		vs_timelimit;				// VS���[�h�̐������ԁi0:�Ȃ��j
int		vs_item;					// VS���[�h�̃A�C�e��ON/OFF
int		vs_rise;					// VS���[�h�̂���オ��ON/OFF

/* �����L���O�ϐ� */

// �ʏ�̃����L���O
// 3�� �~ 10���[�� �~ 40�J�e�S���i�J�e�S�������[�h�Ƃ������Ƃɒ��Ӂj
str*	rkname[3 * 10 * 40];			// ���O
int		rkdata1[3 * 10 * 40];			// ����v�f�P
int		rkdata2[3 * 10 * 40];			// ����v�f�Q
int		rktime[3 * 10 * 40];			// �^�C��
int		rkclear[3 * 10 * 40];			// 0=�r���Œ��� 1=���[�����s 2=���[���N���A
int		rkac[3 * 10 * 40];				// AC���_��
int		rkst[3 * 10 * 40];				// ST���_��
int		rksk[3 * 10 * 40];				// SK���_��
int		rkco[3 * 10 * 40];				// CO���_��

// STANDARD�����L���O
// 5�� �~ 10���[�� �~ 4�J�e�S���i�J�e�S�������[�h�Ƃ������Ƃɒ��Ӂj
str*	std_rkname[5 * 10 * 4];			// ���O
int		std_rkscore[5 * 10 * 4];		// �X�R�A
int		std_rklines[5 * 10 * 4];		// ���C��
int		std_rktime[5 * 10 * 4];			// �^�C��
int		std_wait1[5 * 10 * 4];			// wait1
int		std_wait2[5 * 10 * 4];			// wait2
int		std_wait3[5 * 10 * 4];			// wait3
int		std_waitt[5 * 10 * 4];			// waitt
int		std_speed[5 * 10 * 4];			// sp

// �Z�N�V�����^�C�������L���O
// 30�Z�N�V���� �~ 10���[�� �~ 40�J�e�S��
str*	stname[30 * 10 * 40];			// ���O
int		sttime[30 * 10 * 40];			// �^�C��
int		stend[30 * 10 * 40];			// 0=�r���Œ��� 1=���[�����s 2=���[���N���A

/* �v���C���[�f�[�^�֘A�̕ϐ� */
int		user_enable[2];						// �v���C���[�f�[�^���g�p���Ă��邩�ǂ���
str		user_name[2];						// ���݂̃v���C���[��

int		user_line_count[4 * 2];				// ���C��������
int		user_playcount[2];					// �v���C��

int		user_beginner_tamaya[2];			// BEGINNER-TAMAYA�̉ԉΑ���
int		user_beginner_novice[2];			// BEGINNER-NOVICE�̃X�R�A����

int		user_master_normal[2];				// MASTER-NORMAL�̍ō��i��

int		user_master_hard_admit[2];			// MASTER-HARD�̔F��i��
int		user_master_hard_provisional[2];	// MASTER-HARD�̍ō��b��i��
int		user_master_hard_grade_his[2 * 5];	// �i�ʗ���
int		user_master_hard_grade_pasttime[2];	// �Ō�̎�������ǂꂾ���o�������H

int		user_devil_normal[2];				// DEVIL-NORMAL�̍ō����x��
int		user_devil_hard[2];					// DEVIL-HARD�̍ō��i��
int		user_devil_doom[2];					// DEVIL-DOOM�̍ō��i��

int		user_tomoyo_normal[2];				// TOMOYO-NORMAL�̍ō��X�e�[�W
int		user_tomoyo_eheart[2];				// TOMOYO-EHEART�̍ō��X�e�[�W
int		user_tomoyo_target[2];				// TOMOYO-TARGET�̍ō��X�e�[�W
int		user_tomoyo_flash[2];				// TOMOYO-FLASH�̍ō��X�e�[�W

int		user_ace[5 * 2];					// ACE���[�h�̃x�X�g�^�C��

/* �i�ʎ��� */
int		examination[2];						// �������H 0:�Ȃ� 1:���i���� 2:�~�i����
int		exam_grade[2];						// �����i��
int		purupuru[2];						// �t�B�[���h�̃v���v��

/* ROT. RELAY�p�ϐ� */
int		start_rots[2];						// �X�^�[�g���̃��[��
int		rot_used_flag[10 * 2];				// ���[���g�p�ς݃t���O
int		rot_relay_record[3 * 2];			// �e���[���̃X�R�A

/* �萔�� */

// BGM�t�F�[�h�A�E�g�e�[�u���iheboris.ini�Őݒ肳����̂ł��̒l�͂قږ��Ӗ��j
int		bgmfadestart[10 * 6] = {
	 185, 10000, 10000, 10000, 10000, 10000,	// BEGINNER-TAMAYA
	 485,   685, 10000, 10000, 10000, 10000,	// MASTER-NORMAL
	  -1,   485, 10000, 10000, 10000, 10000,	// 20G-NORMAL
	  -1,    -1,   485,   685,   985, 10000,	// DEVIL-DOOM
	 490, 10000, 10000, 10000, 10000, 10000,	// HEBO+
	  -1,   280,   480, 10000, 10000, 10000,	// DEVIL-NORMAL
	 280, 10000, 10000, 10000, 10000, 10000,	// BEGINNER-NOVICE
	  -1,    -1,   485,   685,   985, 10000,	// DEVIL-HARD
	 490, 10000, 10000, 10000, 10000, 10000,	// MASTER-EASY
	  -1, 10000, 10000, 10000, 10000, 10000,	// 20G-EASY
};

// ACE���[�hBGM�t�F�[�h�A�E�g�e�[�u���iheboris.ini�Őݒ肳����̂ł��̒l�͂قږ��Ӗ��j
int		ace_bgmfadestart[4 * 5] = {
	   45,    95,   145, 10000,		// NORMAL
	   45,    95,   145, 10000,		// HI-SPEED1
	   45,    95,   145, 10000,		// HI-SPEED2
	   35,    95,   145, 10000,		// ANOTHER
	  145, 10000, 10000, 10000,		// ANOTHER2
};

// ACE���[�hBGM�؂�ւ��p�iheboris.ini�Őݒ肳����̂ł��̒l�͂قږ��Ӗ��j
int		ace_bgmlist[3 * 5] = {
	15, 1, 2,	// NORMAL��
	0, 2, 5,	// HI-SPEED1��
	2, 5, 3,	// HI-SPEED2��
	5, 3, 4,	// ANOTHER��
	4, 4, 4		// ANOTHER2��
};

// ACE200���[�hBGM�t�F�[�h�A�E�g�e�[�u���iheboris.ini�Őݒ肳����̂ł��̒l�͂قږ��Ӗ��j
int		ace200_bgmfadestart[4 * 4] = {
	  45,   145,   195, 10000,		// BASIC
	  45,   145,   195, 10000,		// HELL
	  45,   145,   195, 10000,		// HELL-X
	 195, 10000, 10000, 10000,		// VOID
};

// ACE200���[�hBGM�؂�ւ��p�iheboris.ini�Őݒ肳����̂ł��̒l�͂قږ��Ӗ��j
int		ace200_bgmlist[3 * 4] = {
	 0,  1,  2,		// BASIC
	19, 18, 16,		// HELL
	 3,  4, 17,		// HELL-X
	 5,  5,  5,		// VOID
};

int		flash_bgmlist[4];	// FLASH���[�h��BGM���X�g
int		final_bgm;			// FINAL���[�h��BGM
int		marathon_bgm[3];	// MARATHON���[�h��BGM

// NORMAL�i�ʂŒi�ʃ|�C���g��1����܂ł̎���
int		glimit[31] = 
{
	100, 80, 80, 60, 50, 50, 40, 40, 40,	//  0�` 8
	 30, 30, 25, 25, 20, 20, 20, 15, 15,	//  9�`17
	 10,  8,  5,  5,  5,  5,  5,  5,  4,	// 18�`26
	  5,  5,  4,  3							// 27
};

// HARD�i�ʂŃ����N���Ƃ̊�^�C��
int		border_time[20] = 
{
	17, 15, 14, 13, 10, 10, 12, 13, 13,		//  0�` 8
	13, 13, 13, 13, 13, 13, 12, 12, 11,		//  9�`17
	11, 10									// 18�`20
};

// HARD�i�ʂŃ����N���Ƃ̊�^�C�� (repversw <= 6)
int		border_time6[20] = 
{
	17, 15, 14, 13, 10, 10, 11, 12, 12,		//  0�` 8
	12, 12, 12, 12, 12, 11, 11, 10, 10,		//  9�`17
	 9,  9									// 18�`20
};

// MASTER-EASY�̊�X�R�A
int		master_easy_score_table[18] = 
{
	   400,   800,  1400,  2000,  3500,  5500,  8000,  12000,			// 8�`1
	 16000, 22000, 30000, 40000, 52000, 66000, 82000, 100000, 120000,	// S1�`S9
	126000																// GM
};

// DEVIL-HARD���[�h��REGRET��^�C��
int		devil_hard_regret_border[13] = 
{
//	 0**,  1**,  2**,  3**,  4**,  5**,  6**,  7**,  8**,  9**, 10**, 11**, 12**
	5400, 5400, 5400, 5400, 5400, 3600, 3600, 3600, 3600, 3600, 3300, 3300, 3300
};

// DEVIL-DOOM���[�h��REGRET��^�C��
int		devil_doom_regret_border[13] = 
{
//	 0**,  1**,  2**,  3**,  4**,  5**,  6**,  7**,  8**,  9**, 10**, 11**, 12**
	3600, 3600, 3600, 3600, 3600, 3300, 3300, 3300, 3300, 3300, 3000, 3000, 3000
};

int		fontc[10]  = {9,1,2,3,8,4,2,6,7,5};	// �莚�̐F 0:�� 1:�� 2:�� 3:�� 4:�� 5:�� 6:�� 7:�� 8:�� 9:��
int		digitc[10] = {5,5,7,7,5,5,7,7,5,7};	// �����̐F

int		modecolor[19] = {4,1,5,2,1,5,3,0,0,0,6,2,0,4,2,3,2,1,0};			// ���[�h���\���p
int		field_frame_color[19] = {0,1,1,2,1,3,4,5,5,7,6,2,5,0,2,4,2,3,5};	// �t�B�[���h�g�̐F

int		modecolor2[12] = {4,1,2,3,0,0,2,0,1,1,0,5};

int		tame1 = 25,	//hoge ���E�̓�����ςȂ��ō����ړ�����܂ł̎���
		tame2 = 3,	//hoge �����ړ��̑���(���Ȃ��قǑ���)�B
		tame3 = 25,	//hoge ���̏㉺��
		tame4 = 3;	//hoge ���̏㉺��

int		fldisno = 44;		// fldi�ɂ����ăX�N�E�F�A�p�̉摜������ꏊ(�ꏊ�̃J�E���g�́����30�Ԗ�)
int		fldigsno = 45;		// fldi�ɂ�����GOLDEN�X�N�E�F�A�p�̉摜������ꏊ
int		fldihardno = 43;	// fldi�ɂ����ăn�[�h�u���b�N�̉摜������ꏊ

str		RankString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.,- 0123456789<=>?!#$%&'()=pq";

int		key_enter = 0x1C;	// ENTER�L�[�̃L�[�R�[�h
int		key_del = 0xD3;		// DELETE�L�[�̃L�[�R�[�h
int		key_bs = 0x0E;		// BACKSPACE�L�[�̃L�[�R�[�h

int		loopFlag = 1;		// 0�ɂȂ�ƑS�Ẵ��[�v�𖳏����Ŕ�����

int		c_repver = 8;		// ���v���C�o�[�W����
str		version = "LITE32.13EX (07/07/04)";

//������������������������������������������������������������������������������
//   �ݒ�t�@�C���̃C���|�[�g
//������������������������������������������������������������������������������
	include "option.def"				// Setting.exe�̐ݒ�
	include "script/speed.def"			// ���x�ݒ�
	include "script/block.def"			// �u���b�N�f�[�^
	include "script/message.def"		// ���b�Z�[�W�f�[�^
	include "script/mission_info.def"	// MISSION���[�h�̃��b�Z�[�W�f�[�^

//������������������������������������������������������������������������������
//   �\�[�X�t�@�C���̃C���|�[�g
//������������������������������������������������������������������������������
	include "script/flexdraw.c"		// ���𑜓x�Ή��`��֐�
	include "script/screencfg.c"	// SCREEN.SAV�֘A�̊֐�
	include "script/move.c"			// �u���b�N�̑���
	include "script/ranking.c"		// �����L���O
	include "script/stdranking.c"	// SIMPLE���[�h�̃����L���O
	include "script/view.c"			// �\��
	include "script/effect.c"		// ���o
	include "script/sound.c"		// ���y
	include "script/favorites.c"	// FAVORITES
	include "script/practice.c"		// PRACTICE���[�h
	include "script/tomoyo.c"		// TOMOYO���[�h
	include "script/replay.c"		// ���v���C
	include "script/config.c"		// �ݒ���
	include "script/sectime.c"		// �Z�N�V�����^�C�������L���O
	include "script/mission.c"		// MISSION���[�h
	include "script/cpu.c"			// �R���s���[�^�̎v�l���[�`��
	include "script/grade.c"		// �i�ʏ㏸����
	include "script/item.c"			// �A�C�e��
	include "script/user.c"			// �v���C���[�f�[�^

//������������������������������������������������������������������������������
//   ���C��
//������������������������������������������������������������������������������
void main() {
	int i;
	
	// �ݒ�t�@�C���ǂݍ���
	include "heboris.ini"
	include "heboris_user.ini"
	
	// �O���t�B�b�N�E�T�E���h�ǂݍ���
	initialize();
	
	// FPS�ݒ� #LITE23
	SetFPS(main_fps);
	
	// �ݒ�t�@�C�������݂��Ȃ��ꍇ�̓L�[�{�[�h�̏����ݒ��ʂ� #LITE24
	if(first_setting) {
		config_make_default();
		config_input_keyboard(0, 1);
		config_lang();
		config_save();
	}
	
	// ���C�����[�v
	while(loopFlag) {
		// ���ʉ��EBGM��~
		StopAllWaves();
		StopAllBGM();
		
		// �^�C�g�����
		title();
		
		// �Q�[�����C������
		flag = 0;
		
		while(loopFlag) {
			if(refresh_timing) spriteTime();
			KeyInput();
			
			// �O���[�o���J�E���^����
			count = ( count + 1 ) % 65536;
			
			// �w�i����
			if((demo) && (!demokind)) viewDarkTitle();
			else if(!skip_viewbg) viewBack();
			
			noredraw = 0;
			
			// ���v���C
			if(playback && !demo && replayauto) {
				playback = 0;
				
				// ������
				if((getPushState(0, 4) && !cpu_flag[0]) || (getPushState(1, 4) && !cpu_flag[1]))
					fast = 5;
				
				if( !((getPressState(0, 4) && !cpu_flag[0]) || (getPressState(1, 4) && !cpu_flag[1])) )
					fast = 0;
				
				if( (!fast) && ((getPressState(0, 0) && !cpu_flag[0]) || (getPressState(1, 0) && !cpu_flag[1])) )
					fast = 3;
				
				if( (!fast) && ((getPressState(0, 1) && !cpu_flag[0]) || (getPressState(1, 1) && !cpu_flag[1])) )
					fast = 1;
				
				// B�{�^���Ń^�C�g���ɖ߂�
				if((getPushState(0, 5) && !cpu_flag[0]) || (getPushState(1, 5) && !cpu_flag[1]))
					flag = 1;
				
				// HOLD�{�^���Ŏ蓮����
				if((getPushState(0, 7) && !cpu_flag[0]) || (getPushState(1, 7) && !cpu_flag[1])) {
					PlaySE(0);
					fast = 0;
					replayauto = 0;
				}
				
				playback = 1;
			}
			
			// �t�B�[���h�w�i��\��
			viewFieldBackground(0);
			if(maxPlay) viewFieldBackground(1);
			
			// �X�^�b�t���[�� #LITE10
			if(ending[0] || ending[1]) {
				for(i = 0; i < fast + 1; i++) {
					staffRoll(0);
					if(maxPlay) staffRoll(1);
				}
			}
			
			// �t�B�[���h�\��
			viewField(0);
			if(maxPlay) viewField(1);
			
			// �Q�[������
			for(i = 0; i < fast + 1; i++) {
				playerExecute();
				
				if(spawn_y_type) {
					viewFieldFrame(0, 0);
					if(maxPlay) viewFieldFrame(1, 0);
				}
				
				if( i > 0 ) objectExecute();
				noredraw = 1;
			}
			
			// �~�b�V�������[�h�̘g
			if(gameMode[0] == 8) viewMissionFrame();
			
			// �X�R�A�\��
			if((!demo) || (demokind)) viewScore();
			
			// �`���[�g���A���\��
			if((demo) && (!demokind)) viewHowToPlay();
			
			// ���o����
			objectExecute();
			
			// �|�[�Y�ENEXT�B���Ȃ�
			lastProc();
			
			// flag�ϐ���1��������^�C�g���ɖ߂�
			if(flag > 0) {
				if(gameMode[0] == 4) leaveVersusMode();
				for(i = 0; i < 10; i++) TextLayerOff(i);
				if(playback || demo) restoreSetups();
				isUDLRreverse[0] = 0;
				isUDLRreverse[1] = 0;
				playback = 0;
				demo = 0;
				bgfadesw = 0;
				onRecord[0] = 0;
				onRecord[1] = 0;
				break;
			}
			
			if(!refresh_timing) spriteTime();
		}
	}
}

//������������������������������������������������������������������������������
//   �^�C�g��
//������������������������������������������������������������������������������
void title() {
	int		player, pl, mode, game, i, democ;
	
	// �����ݒ�
	count = 0;
	democ = 0;
	mode = 0;
	game = 0;
	
	demo = 0;
	playback = 0;
	replayauto = 0;
	replayno = 0;
	
	cpu_flag[0] = 0;
	cpu_flag[1] = 0;
	
	user_enable[0] = 0;
	user_enable[1] = 0;
	
	// �^�C�g��BGM�Đ�
	if(bgm == 1) {
		if( !IsPlayMIDI() ) ReplayMIDI();
	} else if(bgm >= 2) {
		bgmlv = 11;
		changeBGM();
	}
	
	// �v���C�l�����o�b�N�A�b�v
	b_maxPlay = maxPlay;
	setFieldPosition(maxPlay);
	
	// �ݒ���e���o�b�N�A�b�v
	backupSetups();
	
	// ���[�v�J�n
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();

		count++;

		// �^�C�g���摜��`��
		if(!title_mov_f) {	// �Î~��
			ExBltFast(8,0,0);
		} else {
			ExBltFastRect(8, 0, 0, (title_acnt / 10) * 320, (title_acnt % 10) * 240, 320, 240);
			
			if(count % mov_inter == 0)
				title_acnt++;
			if(title_acnt > title_mov_f -1)
				title_acnt = 0;
			
			ExBlt(7, 0, 0);
		}
		
		// ���쌠�\��
		printFont( 6, 28, "a 1998-2002 KENJI HOSHIMOTO", 0 );

		// �o�[�W�����\��
		printFont( 27, 14, "VERSION 1.60", 4 );
		printFont( 27, 15, "(2002/03/31)", 6 );
		
		sprintf(string[0], "%39s", version);
		printFont(0, 16, string[0], 1);
		
		// ���[�h0: �{�^�����͑҂�
		if(mode == 0) {
			// �X�^�[�g�{�^���������Ă�������
			if(count % 80 < 40) {
				ExBltRect(49,53,154,0,204,213,19);
			}
			
			// �f�����
			democ++;
			if(democ > 900) {
				doDemoMode();
				mode = 2;
			}
			
			// �ǂ��炩�̃X�^�[�g�{�^���������ꂽ�烂�[�h1��
			for(player = 0; player <= maxPlay; player++) {
				if(getPushState(player, 4)) {
					democ = 0;
					PlaySE(10);
					mode = 1;
				}
				
				if(getPushState(player, 7)) {
					democ = 901;
				}
			}
		}
		// ���[�h1: ���[�h�Z���N�g
		else if(mode == 1)
		{
			// ���[�h�ꗗ�\��
			printFont(13, 18 + game * 2, "b", fontc[rots[0]]);
			
			printFont(14, 18, "GAME START",           (fontc[rots[0]]) * (game == 0));
			printFont(14, 20, "REPLAY",               (fontc[rots[0]]) * (game == 1));
			printFont(14, 22, "NORMAL RANKING",       (fontc[rots[0]]) * (game == 2));
			printFont(14, 24, "SECTION TIME RANKING", (fontc[rots[0]]) * (game == 3));
			printFont(14, 26, "CONFIG",               (fontc[rots[0]]) * (game == 4));
			
			// �ǂ��炩�̃W���C�X�e�B�b�N�Ń��[�h�Z���N�g
			for(player = 0; player <= maxPlay; player++) {
				padRepeat2(player);
				
				// ���
				if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				if(getPressState(player, 0)) {
					PlaySE(5);
					game--;
					if(game < 0) game = 4;
				}

				// ����
				if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
				if(getPressState(player, 1)) {
					PlaySE(5);
					game++;
					if(game > 4) game = 0;
				}

				// �L�����Z��
				if(getPushState(player, 5)) {
					democ = 0;
					mode = 0;
				}

				// ����
				if(getPushState(player, 4)) {
					PlaySE(10);
					mode = 2;

					// �X�^�[�g
					if( game == 0 )
					{
						enterSoloMode(player);
						break;
					}
					// ���v���C
					else if( game == 1 )
					{
						mode = ReplaySelectProc();
						if(!mode) restoreSetups();
					}
					// �����L���O
					else if( game == 2 )
					{
						RankingProc2();
						mode = 0;
					}
					// �Z�N�V�����^�C�������L���O
					else if( game == 3 )
					{
						ST_RankingView();
						mode = 0;
					}
					// �ݒ�
					else if( game == 4 )
					{
						StopAllBGM();
						config_menu();	// config.c
						mode = 0;
					}
				}
			}
		}
		else
		// ���[�h2: ���[�v�𔲂��ăQ�[����ʂ�
		{
			break;
		}
		
		if(!refresh_timing) spriteTime();
	}
	
	// BGM��~
	StopAllBGM();
}

// ���[�h�Z���N�g�ɓ���
void enterSoloMode(int player) {
	int i;
	
	gameMode[0] = 0;
	gameMode[1] = 0;
	
	versusInit(0);
	if(maxPlay) versusInit(1);
	gameAllInit();
	
	stat[player] = 2;					// ���[�h�Z���N�g
	for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	
	hnext[0] = dispnext;
	hnext[1] = dispnext;
}

// VERSUS MODE�ɓ���
void enterVersusMode() {
	int player;
	
	StopAllBGM();
	
	gameAllInit();			// ����������
	
	gameMode[0] = 4;		// VS���[�h
	gameMode[1] = 4;
	
	versusInit(0);
	versusInit(1);
	setNextBlockColors(0, 1);
	setNextBlockColors(1, 1);
	
	item_mode[0] = vs_item;
	item_mode[1] = vs_item;
	r_enable[0] = vs_rise;
	r_enable[1] = vs_rise;
	
	setVersusField();
	
	for(player = 0; player < 2; player++) {
		stat[player] = 1;				// �u���b�N�V���b�^�[���s
		statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 9;		// �V���b�^�[��̓X�e�[�^�XNo.9
		hnext[player] = dispnext;
	}
}

// VERSUS���[�h�p�̃t�B�[���h�ʒu��ݒ�
void setVersusField() {
	int player;
	
	b_maxPlay = maxPlay;	// �v���C�l�����o�b�N�A�b�v
	maxPlay = 1;			// �ꎞ�I��DUAL��ɂ���
	
	backno = 15;			// back_vs.png
	
	for(player = 0; player < 2; player++) {
		// �t�B�[���h�̕\���ʒu���o�b�N�A�b�v
		b_foffset[player] = foffset[player];
		b_boffset[player] = boffset[player];
		
		// �t�B�[���h�̕\���ʒu��ύX
		foffset[player] = v_foffset[player];
		boffset[player] = v_boffset[player];
	}
}

// VERSUS���[�h����o��
void leaveVersusMode() {
	int i;
	
	maxPlay = b_maxPlay;				// �v���C�l�����o�b�N�A�b�v����߂�
	
	for(i = 0; i < 2; i++) {
		gameMode[i] = 0;				// ���[�h�ԍ�������
		playerInitial(i);				// ���낢�돉����
		foffset[i] = b_foffset[i];		// �t�B�[���h�ʒu���o�b�N�A�b�v����߂�
		boffset[i] = b_boffset[i];
	}
	
	backno = 0;
}

// PRACTICE MODE�ɓ���
void enterPracticeMode() {
	StopAllBGM();
	
	gameMode[0] = 5;
	gameMode[1] = 5;
	
	stat[0] = 1;					// �u���b�N�V���b�^�[���s
	statc[0 * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
	statc[0 * 10 + 1] = 16;			// �V���b�^�[��̓X�e�[�^�XNo.16
	
	p_setting = p_def_setting;
	p_leveltype = p_def_leveltype;
	p_timelimit = p_def_timelimit;
	p_goal = p_def_goal;
	p_staffroll = p_def_staffroll;
	
	loadWait(0, p_setting);			// wait�ݒ��ǂݍ���
	
	backno = p_backno;
}

// MISSION MODE�ɓ���
void enterMissionMode() {
	StopAllBGM();
	
	gameMode[0] = 8;
	gameMode[1] = 8;
	
	stat[0] = 1;					// �u���b�N�V���b�^�[���s
	statc[0 * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
	statc[0 * 10 + 1] = 22;			// �V���b�^�[��̓X�e�[�^�XNo.22
	
	c_mission = 0;
	start_mission = 0;
	mission_file = 0;
}

// �f����ʏ���
void doDemoMode() {
	int tmp, player;
	
	gameAllInit();
	demo = 1;
	demotime = 0;
	bgmlv = -1;
	
	demokind++;
	if(demokind > 1) demokind = 0;
	
	if(demokind == 0) {
		// �`���[�g���A��
		b_maxPlay = maxPlay;
		maxPlay = 1;				// �ꎞ�I��DUAL��ɂ���
		setFieldPosition(maxPlay);
		foffset[0] = v_foffset[0];
		boffset[0] = v_boffset[0];
		foffset[1] = v_foffset[1];
		boffset[1] = v_boffset[1];
		coffset = 110;
		
		playback = 1;
		replayauto = 1;
		loadReplayData(0, -1);
		
		nextc[0] = 0;
		next[0] = nextb[0];
		setNextBlockColors(0, 1);
		
		setStartLevel(0);
		
		hnext[0] = dispnext;
		hnext[1] = 0;
		
		stat[0] = 4;
		stat[1] = 35;
		
		timeOn[0] = 1;
		onRecord[0] = 1;
		gameMode[1] = 1;
	} else {
		// �f���v���C
		backno = Rand(15);
		
		for(player = 0; player <= maxPlay; player++) {
			rots[player] = Rand(10);
			
			versusInit(player);
			setNextBlockColors(player, 1);
			
			tmp = Rand(7);
			
			// BEGINNER-TAMAYA
			if(tmp == 0) {
				gameMode[player] = 0;
				timeattack[player] = 1;
			}
			// MASTER
			if(tmp == 1) {
				gameMode[player] = 1;
				timeattack[player] = 1;
				gradetype[player] = Rand(3);
			}
			// ACE-NORMAL
			if(tmp == 2) {
				gameMode[player] = 7;
				timeattack[player] = 0;
			}
			// HEBO+
			if(tmp == 3) {
				gameMode[player] = 10;
				timeattack[player] = 1;
			}
			// BEGINNER-NOVICE
			if(tmp == 4) {
				gameMode[player] = 13;
				timeattack[player] = 1;
			}
			// SIMPLE-40LINES
			if(tmp == 5) {
				gameMode[player] = 17;
				timeattack[player] = 0;
				
				wait1[player] = wait1_Beginner;
				wait2[player] = wait2_Beginner;
				wait3[player] = wait3_Beginner;
				waitt[player] = waitt_Beginner;
				sp[player] = 1;
			}
			// SIMPLE-ULTRA
			if(tmp == 6) {
				gameMode[player] = 17;
				timeattack[player] = 1;
				
				wait1[player] = wait1_Beginner;
				wait2[player] = wait2_Beginner;
				wait3[player] = wait3_Beginner;
				waitt[player] = waitt_Beginner;
				sp[player] = 1;
			}
			
			cpu_flag[player] = 1;
			
			if(maxPlay) cpu_level[player] = Rand(5);
			else cpu_level[player] = 4;
			
			hnext[player] = dispnext;
			setStartLevel(player);
			stat[player] = 3;
		}
	}
}

//������������������������������������������������������������������������������
//   �Ō�ɂ�鏈��
//������������������������������������������������������������������������������
void lastProc() {
	int		i, j, player;
	
	if(!demo) {
		for(player = 0; player <= maxPlay; player++) {
			// �|�[�Y
			if(IsPushKey(pause_key[player]) || getJoyPushState(player, joy_pause_key[player])) {
				if(onRecord[player]) {
					pause[player] = !pause[player];
					if(gameMode[player] == 4) pause[1 - player] = !pause[1 - player];
					
					if(pause[player]) PlaySE(36);
					
					StopWave(38);
					
					// BGM�|�[�Y
					if(bgm == 4) {
						// MIDI
						if(pause[player]) {
							PauseMIDI();
						} else {
							ReplayMIDI();
						}
					} else if(bgm >= 2) {
						// WAVE & MP3
						if(pause[player]) {
							PauseWave(60 + bgmlv);
						} else {
							ReplayWave(60 + bgmlv);
						}
					}
				}
			}
			
			// NEXT�؂�ւ�
			if(IsPushKey(hnext_key[player]) || getJoyPushState(player, joy_hnext_key[player])) {
				hnext[player]++;
				if(hnext[player] > 6) hnext[player] = 0;
			}
			
			// ���C�������񐔕\���؂�ւ�
			if((pause[player]) && (player == 0)) {
				if(IsPushKey(skip_key[0]) || getJoyPushState(0, joy_skip_key[0]))
					disp_lineinfo = !disp_lineinfo;
			}
		}
		
		// ����󋵕\��
		if( (showctrl != 2) && ((!showctrl && playback) || (showctrl == 1)) ) {
			if((gameMode[0] != 4) && (!tomoyo_dual_enable[0]) && (onRecord[0]) && (!pause[0]))
				showControl();
		}
	}
	
	// �f�����
	if(demo) {
		demotime++;
		
		if(demokind) {
			if(count % 80 < 40) ExBltRect(49,53,154,0,204,213,19);
			if(maxPlay) ExBltRect(3, 98, 100 + (count % 40 > 20), 0, 160, 123, 31);
		} else {
			showControl();
		}
		
		if(demokind) {
			cpu_flag[0] = 0;
			cpu_flag[1] = 0;
		} else {
			replayauto = 0;
		}
		
		if(getPushState(0,4) || getPushState(0,5) || getPushState(1,4) || getPushState(1,5) || (stat[0] == 11) || (stat[1] == 11))
			flag = 1;
		
		if((demokind) && (demotime >= 3600 * 3))
			flag = 1;
		
		if(flag && !demokind) {
			maxPlay = b_maxPlay;
			setFieldPosition(maxPlay);
		}
		
		if(demokind) {
			cpu_flag[0] = 1;
			cpu_flag[1] = 1;
		} else {
			replayauto = 1;
		}
	}
	
	// THUNDER�M�~�b�N
	if(thunder_timer) {
		SetSecondaryOffset(-10 + Rand(30), -10 + Rand(30));
		thunder_timer--;
	} else {
		SetSecondaryOffset(0, 0);
	}
}

//������������������������������������������������������������������������������
//   NEXT��������
//������������������������������������������������������������������������������
void versusInit(int player) {
	int		i, j, temp, mae, shu;
	
	mae = -1;
	nextc[player] = 0;
	nextb_max[player] = 1400;
	
	if((gameMode[0] == 4) && (player == 1)) {
		// �ΐ�ł́A1P�̃u���b�N��2P�ɃR�s�[
		nextb_max[1] = nextb_max[0];
		for(i = 0; i < nextb_max[1]; i++) nextb[i + 1400] = nextb[i];
		next[1] = next[0];
	} else if(nextblock == 8) {
		// TGM
		tgmNextInit(player, 0);
	} else if(nextblock == 9) {
		// TAP
		tgmNextInit(player, 1);
	} else if(nextblock == 10) {
		// �K�C�h���C���Q�[��
		guidelineNextInit(player);
	} else if(nextblock == 11) {
		// TOMOYO
		tomoyoNextInit(player, 0);
	} else if(nextblock == 12) {
		// �d���p�^�[��
		tomoyoNextInit(player, 1);
	} else if(nextblock == 13) {
		// �d���p�^�[��2
		tomoyoNextInit(player, 2);
	} else if(nextblock == 0) {
		// ���S�����_��
		do {
			nextb[0 + player * 1400] = Rand(7);
		} while((nextb[0 + player * 1400] == 2) || (nextb[0 + player * 1400] == 3) || (nextb[0 + player * 1400] == 6));
		
		for(i = 1; i < 1400; i++) nextb[i + player * 1400] = Rand(7);
	} else {
		// HEBORIS�p�^�[��
		for(i = 0; i < 1400 / nextblock + 1; i++) {
			for(j = 0; j < 7; j++) nextwork[j] = 0;
			
			for(j = 0; j < nextblock; j++) {
				do {
					if(i * nextblock + j == 0) {
						do {
							temp = Rand(7);
						} while((temp == 2) || (temp == 3) || (temp == 6));
					} else {
						temp = Rand(7);
					}
				} while((nextwork[temp] != 0) || (mae == temp));
				
				if(i * nextblock + j < 1400) nextb[i * nextblock + j + player * 1400] = temp;
				
				nextwork[temp] = 1;
				mae = temp;
			}
		}
	}
	
	next[player] = nextb[nextc[player] + player * 1400];
	
	for(i = 0; i < 1400; i++) nextb_fake[i + player * 1400] = Rand(7);
}

// TGM����NEXT��������
void tgmNextInit(int player, int type) {
	int i, j;
	int history[4];
	int block;

	if(type) {
		// Z S Z S�Ŗ��߂�
		history[0] = 3;
		history[1] = 6;
		history[2] = 3;
		history[3] = 6;
	} else {
		// ������΂Ŗ��߂�
		for(i = 0; i < 4; i++) history[i] = 3;
	}

	// ���萶��
	do {
		nextb[0 + player * 1400] = Rand(7);
	} while((nextb[0 + player * 1400] == 2) || (nextb[0 + player * 1400] == 3) || (nextb[0 + player * 1400] == 6));

	// ���������炷
	for(j = 0; j < 3; j++) {
		history[3 - j] = history[3 - (j + 1)];
	}

	// �����ɐV�����u���b�N������
	history[0] = nextb[0 + player * 1400];

	// �c��̃c���𐶐�
	for(i = 1; i < 1400; i++) {
		// �c��������
		block = Rand(7);
		
		// �������c���������ɂ�������ő�4��(TAP/TI�ł�6��)��������
		if((block == history[0]) || (block == history[1]) || (block == history[2]) || (block == history[3])) {
			for(j = 0; j < 4 + (type * 2); j++) {
				block = Rand(7);
				
				// 4�̗����ɖ��������炻�̏�Ŕ�����
				if((block != history[0]) && (block != history[1]) && (block != history[2]) && (block != history[3]))
					break;
			}
		}

		// ���������炷
		for(j = 0; j < 3; j++) {
			history[3 - j] = history[3 - (j + 1)];
		}

		// �����ɐV�����u���b�N������
		history[0] = block;

		// nextb�ɓ����
		nextb[i + player * 1400] = block;
	}
}

// �K�C�h���C���Ή��Q�[������NEXT��������
void guidelineNextInit(int player) {
	int i, j;
	int tmp;
	int first;
	int block[7];	// �u���b�N���o�����ǂ����̃t���O
	
	first = 1;
	
	for(i = 0; i < 200; i++) {
		// ������
		for(j = 0; j < 7; j++) block[j] = 0;
		
		// �c���쐬
		for(j = 0; j < 7; j++) {
			do {
				tmp = Rand(7);	// �c��������
			} while( (block[tmp] == 1) || ( (first == 1) && ((tmp == 2)||(tmp == 3)||(tmp == 6)) ) );
			
			// �u���b�N���o���t���OON
			block[tmp] = 1;
			
			// nextb�ɓ����
			nextb[i * 7 + j + player * 1400] = tmp;
			
			first = 0;
		}
	}
}

// �c�����X�g����NEXT��ǂݍ���
// type�F0����TOMOYO�A1���Ɠd���p�^�[��1�A2���Ɠd���p�^�[��2
void tomoyoNextInit(int player, int type) {
	int		i, j, temp, len;
	
	// �����𒲂ׂ�
	if(type == 1) len = StrLen(nextdengen_list);
	else if(type == 2) len = StrLen(nextdengen2_list);
	else len = StrLen(nextb_list);
	
	// �ǂݍ���
	if(len > 0) {
		nextb_max[player] = len;
		
		for(i = 0; i < len; i++) {
			j = i % len;
			
			if(type == 1) MidStr(nextdengen_list, j + 1, 1, string[0]);
			else if(type == 2) MidStr(nextdengen2_list, j + 1, 1, string[0]);
			else MidStr(nextb_list, j + 1, 1, string[0]);
			
			temp = ValLong(string[0]);
			if((temp >= 0) && (temp <= 6)) nextb[i + player * 1400] = temp;
		}
	}
	
	next[player] = nextb[nextc[player] + player * 1400];
}

//������������������������������������������������������������������������������
//   ����������
//������������������������������������������������������������������������������
void gameAllInit() {
	backno = 0;
	fast = 0;
	count = 0;
	overcount = 0;
	disp_lineinfo = d_disp_lineinfo;

	playerInitial(0);
	playerInitial(1);

	objectClear();
}

void playerInitial(int player) {
	int		i, j;

	repversw = c_repver;
	item_num = 39;

	item_pronum = 0;
	for(i = 0; i < item_num; i++) item_pronum = item_pronum + item_pro[i];

	GiziSRand(player);		// �����̃V�[�h����

	sc[player] = 0;
	sp[player] = 1;
	gameTimer[player] = 0;
	timeOn[player] = 0;
	next[player] = nextb[0 + player * 1400];
	hidden[player] = 0;

	wait1[player] = 26;
	wait2[player] = 40;
	wait3[player] = 28;
	waitt[player] = 15;

	combo[player] = 0;
	pinch[player] = 0;

	stat[player] = 0;

	for(i = 0; i < 10; i++) statc[i + player * 10] = 0;

	for(i = 0; i < 10; i++)
		for(j = 0; j < 22; j++) {
			fld[i + j * 10 + player * 220] = 0;
			fldt[i + j * 10 + player * 220] = 0;
			fldu[i + j * 10 + player * 220] = 0;
			fldi[i + j * 10 + player * 220] = 0;
			fldo[i + j * 10 + player * 220] = 0;
			flds[i + j * 10 + player * 220] = 0;
		}

	for(i = 0; i < 22; i++) erase[i + player * 22] = 0;

	// #LITE07
	hold[player] = -1;
	dhold[player] = 0;
	dhold2[player] = 0;
	hold_used[player] = 0;
	tc[player] = -1;
	tr[player] = 0;
	kickc[player] = 0;
	kickc2[player] = 0;
	onRecord[player] = 0;
	time2[player] = 0;
	timeattack[player] = 0;
	ending[player] = 0;
	edrec[player] = 0;
	end_f[player] = 0;
	uplinetype[player] = 0;
	
	c_cblk[player] = 0;
	c_cblk_r[player] = 0;
	c_nblk[0 + player * 6] = 0;
	c_nblk[1 + player * 6] = 0;
	c_nblk[2 + player * 6] = 0;
	c_nblk[3 + player * 6] = 0;
	c_nblk[4 + player * 6] = 0;
	c_nblk[5 + player * 6] = 0;
	c_hblk[player] = 0;
	
	// #LITE08
	endingcnt[player] = 0;
	
	// #LITE10
	bdowncnt[player] = 0;
	r_bdowncnt[player] = 0;
	r_enable[player] = def_rise_enable;
	r_start[player]  = def_rise_start;
	r_end[player]    = def_rise_end;
	r_inter[player]  = def_rise_inter;
	
	staff_c[player] = 0;
	endtime[player] = 0;
	
	sdrop[player] = 0;
	qdrop[player] = 0;
	cmbpts[player] = 0;
	
	// #LITE11
	IsBig[player] = def_IsBig;
	BigMove[player] = def_BigMove;
	IsBigStart[player] = def_IsBig;
	BigMoveStart[player] = def_BigMove;
	
	// #LITE12
	hebocombo[player] = 0;
	nextc[player] = 0;
	
	// #LITE13
	vslevel[player] = 0;
	
	stage[player] = 0;			// �X�e�[�W�ԍ�
	rest_pblock[player] = 0;	// �c��v���`�i�u���b�N��
	sclear[player] = 0;			// �X�e�[�W�N���A�t���O
	stime[player] = 0;			// �X�e�[�W�^�C��
	ltime[player] = 0;			// ���~�b�g�^�C��
	sectionTimer[player] = 0;			// �N���A�^�C��
	clearnum[player] = 0;		// �N���A�X�e�[�W��
	clearp[player] = 0;			// �N���A��
	pass_flg[player] = 0;		// �c������t���O
	
	// #LITE14
	start_stage[player] = 0;
	start_nextc[player] = 0;
	
	// #LITE15
	laststage[player] = 26;
	
	isfmirror[player] = 0;
	fmirror_cnt[player] = -20;
	
	rollroll_flag[player] = 0;
	isrollroll[player] = 0;
	
	// #LITE16
	stage_nextc[player] = 0;
	
	xray_flag[player] = 0;
	isxray[player] = 0;
	xray_counter[player] = 0;
	
	color_flag[player] = 0;
	iscolor[player] = 0;
	color_counter[player] = 0;
	
	// #LITE17
	c_norm[player] = 0;
	m_norm[player] = 0;
	
	// #LITE18
	grade[player] = 0;
	gpoint[player] = 0;
	gtime[player] = 0;
	gflash[player] = 0;
	
	// #LITE19
	hanabi_waiting[player] = 0;
	hanabi_frame[player] = 0;
	hanabi_combo[player] = 0;
	combo2[player] = 0;
	
	// #LITE20
	timelimit[0 + player * 2] = 0;
	timelimit[1 + player * 2] = 0;
	
	// #LITE22
	platinaerase_cnt[player] = 0;
	ext_s[player] = 0;
	timeextend_snd_cnt[player] = 0;
	
	// #LITE23
	last_command[player] = 0;
	tspin_frame[player] = 0;
	
	// #LITE27
	field_spin[player] = -1;
	
	// #LITE28
	gup_down[player] = 0;
	gmflag1[player] = 0;
	gmflag2[player] = 0;
	gmflag1_e[player] = 0;
	gmflag2_e[player] = 0;
	gmflag_r[player] = 0;
	
	// #LITE29
	for(i = 0; i < 30; i++) now_sttime[i + player * 30] = 0;
	medal_st[player] = 0;
	medal_ac[player] = 0;
	medal_co[player] = 0;
	medal_sk[player] = 0;
	skill[player] = 0;
	
	// #LITE30.6
	IsTspin[player] = 0;
	gskill[player] = 0;
	gskbai[player] = 0;
	endlines[player] = 0;
	isblind[player] = 0;
	blind_flag[player] = 0;
	
	// #LITE30.8
	isUDLRreverse[player] = 0;
	isRotateLock[player] = 0;
	ishidenext[player] = 0;
	heboGB[player] = 0;
	c_mission = 0;
	clear_mission = 0;
	
	// #LITE30.9
	min_speed[player] = 0;
	mission_extra = 0;
	
	// #LITE30.12
	for(i = 0; i < 20; i++) stage_skip_frame[i + player * 20] = 0;
	stage_skip_used[player] = 0;
	stage_skip_mpc[player] = 0;
	
	// #LITE30.13
	isthunder[player] = 0;
	thunder_timer = 0;
	
	// #LITE30.14
	cpu_best_x[player] = 0;
	cpu_best_y[player] = 0;
	cpu_best_r[player] = 0;
	for(i = 0; i < 10; i++) cpu_ctrl[i + player * 10] = 0;
	cpu_flag[player] = cpu_enable_setting[player];
	cpu_level[player] = cpu_default_level[player];
	//cpu_climb[player] = 0;
	
	// #LITE30.15
	b_to_b[player] = 0;
	b_to_b_count[player] = 0;
	b_to_b_frame[player] = 0;
	ndelay[player] = 1;
	
	// #LITE30.16
	ghole[player] = 0;
	
	// #LITE30.18
	tomoyo_rise[player] = 0;
	tomoyo_rise_t[player] = 0;
	tomoyo_waits[player] = 0;
	upLineNo[player] = 0;
	tomoyo_rise_edit[player] = 0;
	hnext_flag[player] = 0;
	hnext_timer[player] = 0;
	navigation_time[player] = 0;
	
	// #LITE30.20
	item[player] = 0;
	item_name[player] = 0;
	item_g[player] = 0;
	item_t[player] = 0;
	item_hblk[player] = 0;
	item_coming[player] = 0;
	item_waiting[player] = 0;
	itemappear_c[player] = 0;
	item_mode[player] = 0;
	for(i = 0; i < 6; i++) item_nblk[i + player * 6] = 0;
	
	// #LITE30.22
	for(i = 0; i < 6; i++) rt_nblk[i + player * 6] = 0;
	
	// #LITE30.24
	ending_timeOn[player] = 0;
	always_over1000[player] = 0;
	
	// #LITE30.25
	time99[player] = 0;
	timeN[player] = 0;
	ave_laptime3[player] = 0;
	gup3rank[player] = 0;
	gup3sp_adjust[player] = 0;
	qualityflag[player] = 0;
	skillflag[player] = 0;
	tr2[player] = 0;
	border_rank[player] = 0;
	gradetype[player] = 0;
	
	// #LITE30.26
	harddrop[player] = 0;
	
	// #LITE30.27
	for(i = 0; i < 4; i++) {
		line_count[i + player * 4] = 0;
		tspin_count[i + player * 4] = 0;
	}
	tspin_kick[player] = 0;
	
	// #LITE30.29
	softdrop[player] = 0;
	
	// #LITE30.30
	tc_20g[player] = 485;
	regretcancel[player] = 0;
	
	// #LITE30.31
	medal_visible_ac[player] = 0;
	medal_visible_st[player] = 0;
	medal_visible_sk[player] = 0;
	medal_visible_co[player] = 0;
	are_skipflag[player] = 0;
	hanabi_int[player] = 20;
	
	// #LITE30.33
	kickc3[player] = 0;
	
	// #LITE30.34
	pause[player] = 0;
	
	// #LITE31
	risecount[player] = 0;
	
	// #LITE31.1
	o_cblk[player] = 0;
	o_nblk[0 + player * 6] = 0;
	o_nblk[1 + player * 6] = 0;
	o_nblk[2 + player * 6] = 0;
	o_nblk[3 + player * 6] = 0;
	o_nblk[4 + player * 6] = 0;
	o_nblk[5 + player * 6] = 0;
	o_hblk[player] = 0;
	
	// #LITE31.4
	hidden_old[player] = 0;
	hiddentm[player] = 0;
	hiddeny[player] = 22;
	hiddenti[player] = 0;
	hiddenc[player] = 0;
	
	// #LITE31.5
	item_timer[player] = 0;
	ismagnetblock[player] = 0;
	istimestop[player] = 0;
	isholdlock[player] = 0;
	isLRreverse[player] = 0;
	isboost[player] = 0;
	boostbak_sp[player] = 0;
	boostbak_settyaku[player] = 0;
	isfever[player] = 0;
	isUDreverse[player] = 0;
	isremote[player] = 0;
	isdark[player] = 0;
	isUPdelfield[player] = 0;
	isDWdelfield[player] = 0;
	isdeleven[player] = 0;
	istrance[player] = 0;
	dolaser[player] = 0;
	lasernum[player] = 0;
	for(i = 0; i < 4; i++) laserpos[i + player * 4] = -1;
	rapid_c[player] = 0;
	donega[player] = 0;
	doshotgun[player] = 0;
	for(i = 0; i < 22; i++) shotgunpos[i + player * 22] = 0;
	doexchg[player] = 0;
	isbanana[player] = 0;
	for(i = 0; i < 10; i++) banana_pos[i + player * 10] = 0;
	banana_c[player] = 0;
	dorulet[player] = 0;
	isFreefall[player] = 0;
	isLmovfield[player] = 0;
	isRmovfield[player] = 0;
	do180field[player] = 0;
	
	ofs_x[player] = 0;
	ofs_y[player] = 0;
	
	stopmirror_flag[player] = 0;
	
	// #LITE31.8
	Ff_rerise[player] = 0;
	tomoyo_dual[player] = 0;
	tomoyo_timebonus[player] = 0;
	tomoyo_no_stage_time[player] = 0;
	tomoyo_bgm[player] = 0;
	
	// #LITE31.10
	tomoyo_ehfinal_c[player] = 0;
	tomoyo_dual_enable[player] = 0;
	
	// #LITE31.11
	flash_bonus_points[player] = 0;
	flash_bonus_count[player] = 0;
	flash_continue[player] = 0;
	flash_cont_stage[player] = 0;
	li[player] = 0;
	
	// #LITE31.13
	item_all[player] = 0;
	
	for(i = 0; i < 39; i++) {
		if(item_switch[i] != 0) item_all[player]++;
	}
	
	tr_20g[player] = 0;
	
	// #LITE31.14
	cpu_best_p[player] = 0;
	cpu_hold[player] = 0;
	
	// #LITE31.16
	fastroll[player] = 0;
	
	// #LITE31.17
	shadowtime[player] = 300;
	squaremode[player] = 0;
	
	// #LITE31.19
	start_bgmlv[player] = 0;
	
	// #LITE31.22
	s_bdowncnt[player] = 0;
	
	// #LITE31.23
	n_bx[player] = 3;
	
	// #LITE31.27
	ready_count[player] = 0;
	lastblkline[player] = 0;
	speedtype[player] = 0;
	
	// #LITE31.30
	lastline[player] = 0;
	lastline_frame[player] = 0;
	
	// #LITE31.31
	examination[player] = 0;
	exam_grade[player] = 0;
	purupuru[player] = 0;
	
	// #LITE31.32
	tomoyo_ltime_over[player] = 0;
	
	// #LITE31.36
	staff_type[player] = Rand(2);
	
	// #LITE32
	do16t[player] = 0;
	isreflect[player] = 0;
	isdouble[player] = 0;
	isallclear[player] = 0;
	ismiss[player] = 0;
	docopyfld[player] = 0;
	isfakenext[player] = 0;
	item_monochrome[player] = 0;
	for(i = 0; i < 5; i++) itemhistory[i + player * 5] = 0;
	
	// #LITE32.1
	squarenum[player] = 0;
	
	// #LITE32.3
	tcombo[player] = 0;
	start_rots[player] = 0;
	for(i = 0; i < 10; i++) rot_used_flag[i + player * 10] = 0;
	for(i = 0; i < 3; i++) rot_relay_record[i + player * 3] = 0;
	
	// #LITE32.6
	flash_edit[player] = 0;
	lasttspin[player] = 0;
	
	// #LITE32.7
	cpu_frame[player] = -1;
	
	// #LITE32.11
	last_mp_check[player] = -1;
	
	// �u���b�N�̐F��ݒ�
	setNextBlockColors(player, 1);
}

// NEXT�̈���̃u���b�N�̐F��ݒ�
// ��]�@����ύX������NEXT�֌W�̕ϐ���M�����肷��x�ɌĂяo���K�v����
void setNextBlockColors(int player, int first) {
	int i, tmp;
	
	if( first ) {
		// �����ݒ�
		for(i = 0; i < 6; i++) {
			c_nblk[i + player * 6] = getNextBlock(player, nextc[player] + i);
			item_nblk[i + player * 6] = 0;
		}
		
		// �F��ϊ�����
		if(!rule_color[rots[player]]) {
			// �N���V�b�N
			for(i = 0; i < 6; i++) c_nblk[i + player * 6] = ccol[c_nblk[i + player * 6]];
		} else {
			// ���[���h
			for(i = 0; i < 6; i++) c_nblk[i + player * 6] = wcol[c_nblk[i + player * 6]];
		}
		
		// ����[]
		if(always_over1000[player] || item_monochrome[player]) {
			for(i = 0; i < 6; i++) o_nblk[i + player * 6] = 1;
		} else {
			for(i = 0; i < 6; i++) o_nblk[i + player * 6] = 0;
		}
	} else {
		// NEXT�̈���̃u���b�N�̐F�����炷
		for(i = 0; i < 5; i++) {
			c_nblk[i + player * 6] = c_nblk[(i + 1) + player * 6];
			item_nblk[i + player * 6] = item_nblk[(i + 1) + player * 6];
			rt_nblk[i + player * 6] = rt_nblk[(i + 1) + player * 6];
			o_nblk[i + player * 6] = o_nblk[(i + 1) + player * 6];
		}
		
		// NEXT�̈�̍Ō�̃u���b�N�̐F��ݒ�
		if( (use_over1000_block == 1) && 
		    ((tc[player] >= over1000_start) || (always_over1000[player]) || (item_monochrome[player])) ) {
			// []
			tmp = hnext[player] - 1;
			if(tmp < 0) tmp = 0;
			
			o_nblk[tmp + player * 6] = 1;
		}
		
		// �u���b�N�̎�ނ��擾
		c_nblk[5 + player * 6] = getNextBlock(player, nextc[player] + 5);
		
		// �F��ϊ�����
		if(!rule_color[rots[player]])
			c_nblk[5 + player * 6] = ccol[c_nblk[5 + player * 6]];
		else
			c_nblk[5 + player * 6] = wcol[c_nblk[5 + player * 6]];
		
		// NEXT�̈�̍Ō�̃A�C�e����ݒ�
		item_nblk[2 + player * 6] = item_coming[player];
		
		// NEXT�̈�̍Ō�̃u���b�N�̌�����ݒ�
		if(isRotateLock[player])
			rt_nblk[i + player * 6] = GiziRand(player, 4);
		else
			rt_nblk[i + player * 6] = 0;
	}
}

// NEXT�u���b�N���擾
int getNextBlock(int player, int count) {
	// �ʏ펞
	if(count >= nextb_max[player]) {
		count = count - nextb_max[player];
	}
	
	if(player == 0) {
		return nextb[count];
	} else {
		return nextb[count + 1400];
	}
}

// �X�^�b�t���[���`��
void staffRoll(int player) {
	if((ending[player] == 2) && (onRecord[player]) && (!pause[player])) {
		// �X�^�b�t���[���o�ߎ��Ԃ𑝉�������
		endtime[player] = endtime[player] + 1 + fastroll[player];
		
		// �`�悷��
		ExBltRect(81 + staff_type[player], foffset[player] + 8, 40, 0, staff_c[player] / 2, 80, 160);
		
		// �ړ�
		if((endtime[player] % 2 == 0) && (endtime[player] < 3100)) staff_c[player]++;
	}
}

//������������������������������������������������������������������������������
//   �v���C���[�̃X�e�[�^�X�ɉ����Ċe���������s
//������������������������������������������������������������������������������
void playerExecute() {
	int		i, player, j, temp;
	
	// �̂ăQ�[����
	if(doGiveup()) {
		return;
	}
	
	// �s���`��
	if( (pinch[0] && onRecord[0]) || (pinch[1] && onRecord[1]) ) {
		if( !IsPlayWave(32) ) PlaySE(32);
	} else {
		StopWave(32);
	}
	
	for(i = 0; i <= maxPlay; i++) {
		player = i;
		
		if(pause[player]) {
			if(!getPressState(player, 6)) {
				if(count % 60 > 10) printFont(boffset[player] + 2, 15, "PAUSE!", fontc[rots[player]]);
				
				// A+B�ŋ����I�� #LITE30.6
				if(playback && replayauto) {
					printFont(boffset[player],     19, "PRESS D", digitc[rots[player]]);
					printFont(boffset[player] + 3, 20, "TO PLAY", digitc[rots[player]]);
					
					printFont(boffset[player],     22, "PRESS B", digitc[rots[player]]);
					printFont(boffset[player] + 3, 23, "TO EXIT", digitc[rots[player]]);
				} else {
					printFont(boffset[player],     22, "PRESS A+B", digitc[rots[player]]);
					printFont(boffset[player] + 1, 23, "TO GIVEUP", digitc[rots[player]]);
				}
			}
			
			// PRACTICE�ł�C�������Ȃ��獶�E�ŃA�C�e���I��
			if((gameMode[player] == 5) && (item_mode[player])) {
				printFont(boffset[player] - 1, 25, "C+<L R>:ITEM", count % 9);
				
				if(getPressState(player, 6)) {
					// ��
					if(getPushState(player, 2)) {
						PlaySE(5);
						item_nblk[0 + player * 6]--;
						if(item_nblk[0 + player * 6] < 0) item_nblk[0 + player * 6] = item_num;
						item_name[player] = item_nblk[0 + player * 6];
						p_replay_save_enable = 0;
					}
					// ��
					if(getPushState(player, 3)) {
						PlaySE(5);
						item_nblk[0 + player * 6]++;
						if(item_nblk[0 + player * 6] > item_num) item_nblk[0 + player * 6] = 0;
						item_name[player] = item_nblk[0 + player * 6];
						p_replay_save_enable = 0;
					}
				}
			}
			
			goto skip;
		}

		// TIME STOP
		if(istimestop[player]) {
			getTime(item_timer[player]);
			printFont(boffset[player] + 1, 18, string[0], (count % 4 / 2) * fontc[rots[player]]);
			
			if(item_timer[player] <= 0) istimestop[player] = 0;
			
			goto next;
		}

		// TOMOYO���[�h�̃X�e�[�W�X�L�b�v�@�\
		if((gameMode[player] == 6) && (stage[player] < 19) && (ltime[player] > 1800) && (timeOn[player])) {
			tomoyoStageSkip(player);
		}

		// 15���ȏ�v���C����ƒ������iTOMOYO�AMISSION�ȊO�j
		if((gameTimer[player] >= 54000) && (timeOn[player]) && 
		   (gameMode[player] != 5) && (gameMode[player] != 6) && (gameMode[player] != 8) && (gameMode[player] != 15))
		{
			sp[player] = speed_limit15;
			wait1[player] = wait1_limit15;
			wait2[player] = wait2_limit15;
			wait3[player] = wait3_limit15;
			speedtype[player] = 0;
		}

		// VERSUS���s���
		if(flag == -1) {
			if(!player) winner();
			goto next;
		}

		jump(stat[i],l00,l01,l02,l03,l04,l05,l06,l07,l08,l09,l10,l11,l12,l13,l14,l15,l16,l17,l18,l19,l20,l21,l22,l23,l24,l25,l26,l27,l28,l29,l30,l31,l32,l33,l34,l35,l36,l37,l38,l39,l40,l41,l42);
		
		/*
		switch(stat[i]) {
			case  0: goto l00;
			case  1: goto l01;
			case  2: goto l02;
			case  3: goto l03;
			case  4: goto l04;
			case  5: goto l05;
			case  6: goto l06;
			case  7: goto l07;
			case  8: goto l08;
			case  9: goto l09;
			case 10: goto l10;
			case 11: goto l11;
			case 12: goto l12;
			case 13: goto l13;
			case 14: goto l14;
			case 15: goto l15;
			case 16: goto l16;
			case 17: goto l17;
			case 18: goto l18;
			case 19: goto l19;
			case 20: goto l20;
			case 21: goto l21;
			case 22: goto l22;
			case 23: goto l23;
			case 24: goto l24;
			case 25: goto l25;
			case 26: goto l26;
			case 27: goto l27;
			case 28: goto l28;
			case 29: goto l29;
			case 30: goto l30;
			case 31: goto l31;
			case 32: goto l32;
			case 33: goto l33;
			case 34: goto l34;
			case 35: goto l35;
			case 36: goto l36;
			case 37: goto l37;
			case 38: goto l38;
			case 39: goto l39;
			case 40: goto l40;
			case 41: goto l41;
			case 42: goto l42;
		}
		*/
		
		l00: statJoinwait(player);				// 00 -> �r���Q���҂����
				goto next;
		l01: statBlockSutter(player);			// 01 -> �u���b�N�V���b�^�[
				goto next;
		l02: statSelectMode(player);			// 02 -> ���[�h�Z���N�g���
				goto next;
		l03: statReady(player);					// 03 -> Ready!?
				goto next;
		l04: statBlock(player);					// 04 -> �u���b�N��������
				goto next;
		l05: statMove(player);					// 05 -> �u���b�N�ړ��� (move.c)
				goto next;
		l06: statErase(player);					// 06 -> ���ԉ҂�
				goto next;
		l07: statGameOver(player);				// 07 -> �Q�[���I�[�o�[���o
				goto next;
		l08: statEraseBlock(player);			// 08 -> �u���b�N����
				goto next;
		l09: statSelectLevel(player);			// 09 -> VS���[�h���x���Z���N�g���
				goto next;
		l10: statVersusWait(player);			// 10 -> ���܂������������
				goto next;
		l11: statNameEntry(player);				// 11 -> �l�[���G���g���[
				goto next;
		l12: statResult(player);				// 12 -> ���ʕ\��
				goto next;
		l13: statGameOver2(player);				// 13 -> �Q�[���I�[�o�[�\��
				goto next;
		l14: statEnding(player);				// 14 -> �G���f�B���O
				goto next;
		l15: statRiseLine(player);				// 15 -> ����オ��
				goto next;
		l16: statPracticeSelect(player);		// 16 -> PRACTICE���[�h�ݒ��� (practice.c)
				goto next;
		l17: statFieldEditor(player);			// 17 -> �t�B�[���h�G�f�B�^
				goto next;
		l18: statTomoyoNextStage(player);		// 18 -> TOMOYO���[�h �X�e�[�W�N���A�^�^�C���I�[�o�[ (tomoyo.c)
				goto next;
		l19: statTomoyoContinue(player);		// 19 -> TOMOYO���[�h �R���e�B�j���[ (tomoyo.c)
				goto next;
		l20: statTomoyoEditor(player);			// 20 -> TOMOYO���[�h �X�e�[�W�G�f�B�^ (tomoyo.c)
				goto next;
		l21: statDelField(player);				// 21 -> ���C���������� (item.c)
				goto next;
		l22: statMissionSelect(player);			// 22 -> �~�b�V�������[�h�Z���N�g���
				goto next;
		l23: statMissionEditor(player);			// 23 -> �~�b�V�������[�h�G�f�B�b�g���
				goto next;
		l24: statReplaySave(player);			// 24 -> ���v���C�ۑ����
				goto next;
		l25: statNothing(player);				// 25 -> ��莞�ԉ������Ȃ�
				goto next;
		l26: statExtraErase(player);			// 26 -> �u���b�N���ォ��w�肵�����C������������
				goto next;
		l27: statLaser(player);					// 27 -> ���[�U�[ (item.c)
				goto next;
		l28: statNegafield(player);				// 28 -> �l�K�t�B�[���h (item.c)
				goto next;
		l29: statShotgun(player);				// 29 -> �V���b�g�K�� (item.c)
				goto next;
		l30: statExchangeField(player);			// 30 -> �t�B�[���h���� (item.c)
				goto next;
		l31: statItemRulet(player);				// 31 -> �A�C�e�����[���b�g (item.c)
				goto next;
		l32: statFreefall(player);				// 32 -> �t���[�t�H�[�� (item.c)
				goto next;
		l33: statMovfield(player);				// 33 -> �u���b�N��[�Ɋ񂹂� (item.c)
				goto next;
		l34: stat180field(player);				// 34 -> �t�B�[���h��̃u���b�N���Ђ�����Ԃ� (item.c)
				goto next;
		l35:									// 35 -> �������Ȃ�
				goto next;
		l36: statFlashSelectFirstStage(player);	// 36 -> FLASH���[�h�X�e�[�W�Z���N�g�i����j
				goto next;
		l37: statFlashSelectNextStage(player);	// 37 -> FLASH���[�h�X�e�[�W�Z���N�g�i2��ڈȍ~�j
				goto next;
		l38: statStandardSelect(player);		// 38 -> STANDARD���[�h�Z���N�g���
				goto next;
		l39: statMissionCourseName(player);		// 39 -> �~�b�V�������[�h�R�[�X�����͉��
				goto next;
		l40: statExamination(player);			// 40 -> �i�ʔF�莎��
				goto next;
		l41: statCopyField(player);				// 41 -> �t�B�[���h�R�s�[
				goto next;
		l42: statRotRelaySelectRule(player);	// 42 -> ROT. RELAY�̎��̃��[���I��
				goto next;
		
		next:
		increment_time(player);
		
		skip:
	}

	// BGM�t�F�[�h�A�E�g����
	if(bgm >= 2) bgmFadeout();

	// ���҃Q�[���I�[�o�[�Ȃ��莞�Ԍo�ߌ�^�C�g����
	if((stat[0] == 0) && (stat[1] == 0)) {
		if(!overcount) {
			hold[0] = -1;
			hold[1] = -1;
			versusInit(0);
			versusInit(1);
			setNextBlockColors(0, 1);
			setNextBlockColors(1, 1);
			backno = 0;
			back_acnt = 0;
		}
		
		if(playback) {
			// ���v���C�ł͑��^�C�g��
			flag = 1;
		}
		
		overcount++;
		
		if(overcount > 120) {
			RankingProc(gameMode[0]);
			flag = 1;
		}
	} else {
		overcount = 0;
	}
}

// �̂ăQ�[���鏈��
// �̂ăQ�[�����ꍇ�̖߂�l��1
int doGiveup() {
	int player, bak, tmp, i;
	
	tmp = (IsPushKey(giveup_key) || getJoyPushState(0, joy_giveup_key[0]) || getJoyPushState(1, joy_giveup_key[1]));
	tmp = ((tmp) || (getPressState(0, 4) && getPressState(0, 5) && pause[0]));	// �|�[�Y����A+B (1P)
	tmp = ((tmp) || (getPressState(1, 4) && getPressState(1, 5) && pause[1]));	// �|�[�Y����A+B (2P)
	
	if(tmp) {
		versusInit(0);				// NEXT������
		versusInit(1);
		
		objectClear();				// �S�I�u�W�F�N�g����
		
		// ���ʉ���BGM�S��~
		StopAllWaves();
		StopAllBGM();
		
		// �w�i��߂�
		backno = 0;
		back_acnt = 0;
		
		for(i = 0; i < 10; i++) TextLayerOff(i);
		
		// DUAL�M�~�b�N����
		endTomoyoDualGimmick(0);
		
		if(playback || demo) {
			// ���v���C
			flag = 1;
		} else if(gameMode[0] == 5) {
			// PRACTICE���[�h�p
			flag = 0;
			pause[0] = 0;
			PracticeOver();
		} else if(gameMode[0] == 8) {
			// MISSION���[�h�p
			flag = 0;
			pause[0] = 0;
			playerInitial(0);
			stat[0] = 1;
			statc[0 * 10] = 0;
			statc[0 * 10 + 1] = 22;
		} else {
			flag = 0;
			
			for(player = 0; player <= maxPlay; player++) {
				pause[player] = 0;				// �|�[�Y����
				bak = stat[player];				// �X�e�[�^�X���o�b�N�A�b�v
				
				playerInitial(player);			// ������
				stat[player] = 1;				// �u���b�N�V���b�^�[���s
				statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
				
				if(gameMode[player] == 4) {
					resetVersusMode();
					backno = 15;	// back_vs.png
				}
				
				// �V���b�^�[���
				if(bak == 0) {
					statc[player * 10 + 1] = 0;		// �Q���҂�
				} else if(gameMode[player] == 4) {
					statc[player * 10 + 1] = 9;		// VS���[�h���x���Z���N�g
				} else {
					statc[player * 10 + 1] = 2;		// ���[�h�Z���N�g
				}
			}
		}
		
		return 1;
	}
	
	return 0;
}

// �^�C���𑝉�������
void increment_time(int player) {
	int temp, i, j, k, tmp;
	
	// SHUFFLE FIELD
	if(isbanana[player]) bananaProc(player);
	
	// ���v���C�L�^
	if(onRecord[player]) {
		if((!replayauto) && (time2[player] < 60 * 60 * 20)) {
			temp = 0;
			for(j = 0; j < 8; j++) {
				temp = temp | (getPressState(player, j) << j) | (getPushState(player, j) << (j + 8));
			}
			
			if(!player) {
				replayData[time2[player]] = temp;
			} else {
				replayData2[time2[player]] = temp;
			}
		}
		
		time2[player]++;	// ���v���C�p�J�E���^��1/60�b�v���X
	}
	
	// �^�C�}�[�����삵�Ă���Ύ��Ԃ�1/60�b�v���X
	if( timeOn[player] ) {
		gameTimer[player]++;
		sectionTimer[player]++;	// �Z�N�V�����^�C������
	}
	
	// �G���f�B���O���Ȃ�΃G���f�B���O�o�ߎ��Ԃ�1/60�b�v���X
	if((ending_timeOn[player]) && (onRecord[player])) {
		edrec[player] = edrec[player] + 1 + fastroll[player];
	}
	
	// ���[���N���A
	if((ending[player] == 2) && (edrec[player] > ending_timelimit) && (onRecord[player])) {
		ending_timeOn[player] = 0;
		stat[player] = 14;
		for(i=0; i<10; i++) statc[player * 10 + i] = 0;
		
		if(hidden[player]) {
			hidden[player] = 0;			// �t�B�[���h�^�C�}�[������
			disableShadowTimer(player);
		}
		
		// ���[���N���A�Œi�ʏ㏸
		if( (gameMode[player] == 1) || (gameMode[player] == 2) ) {
			// ���݂̒i�ʂ��o�b�N�A�b�v�iCOOL/REGRET���o�p�j
			temp = grade[player];
			
			// NORMAL
			if(gradetype[player] == 0) {
				// �������[�����ɏ������񐔂ŏ��ior�~�i
				if(gmflag_r[player]) {
					if(endlines[player] >= 20) grade[player]++;		// ���v+3
					if(endlines[player] >= 13) grade[player]++;		// ���v+2
					if(endlines[player] >=  7) grade[player]++;		// ���v+1
					if(endlines[player] <=  2) grade[player]--;		// 2���C���ȉ��ō~�i
				} else {
					grade[player]++;								// �������[���ł�+1
				}
			}
			
			// HARD
			if(gradetype[player] == 1) {
				if(gmflag_r[player]) {
					if(endlines[player] >= 3) {
						// �������[����3��ȏ�����ƒi�ʏ㏸
						grade[player] = grade[player] + endlines[player] / 4;
						
						if(grade[player] >= 30) {
							if(tr[player] > 185)
								grade[player] = 30;		// MO
							else
								grade[player] = 29;		// MV
						}
					} else {
						// 2���C���ȉ���������~�i
						grade[player]--;
					}
				} else {
					// �������[���ł�10���C�����Ƃɒi�ʏ㏸
					grade[player] = grade[player] + endlines[player] / 10;
					if(grade[player] > 28) grade[player] = 28;
				}
			}
			
			// GM����ɂ͏オ��Ȃ�
			if(grade[player] > 32) grade[player] = 32;
			if(grade[player] <  0) grade[player] = 0;
			
			// ���o
			if(grade[player] > temp) {
				// COOL!!
				if(gradetype[player] == 1)
					PlaySE(48);
				else
					PlaySE(31);
				
				gup_down[player] = 1;
				gflash[player] = 120;
			} else if(grade[player] < temp) {
				// REGRET
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
			}
		}
		
		// DEVIL-DOOM�i��
		if((gameMode[player] == 3) && (grade[player] == 13)) {
			// CLASSIC�n���5:00�ȓ��AWORLD�n���5:20�ȓ���GOD���i
			if( ((!isWRule(player)) && (gameTimer[player] <= 18000)) || ((isWRule(player)) && (gameTimer[player] <= 19200)) ) {
				grade[player] = 14;
				gflash[player] = 120;
			}
		}
		// DEVIL-HARD�i��
		if((gameMode[player] == 16) && (grade[player] == 13)) {
			// CLASSIC�n���5:20�ȓ��AWORLD�n���5:50�ȓ���GM���i
			if( ((!isWRule(player)) && (gameTimer[player] <= 19200)) || ((isWRule(player)) && (gameTimer[player] <= 21000)) ) {
				grade[player] = 14;
				gflash[player] = 120;
			}
		}
		
		if(gameMode[player] == 0) sc[player] = sc[player] + 30;
		
		if(gameMode[player] == 15) sc[player] = sc[player] + 100000 + ltime[player];
		
		ending[player] = 3;
		if((gameMode[player] != 0) && (gameMode[player] != 13)) end_f[player] = 2;
		
		onRecord[player] = 0;	// �G���f�B���O���[���I���Ɠ����Ƀ��v���C�L�^�I��
		PlaySE(30);
		
		// DEVIL-�̑��؂�
		if((gameMode[player] == 11) && (tc[player] < 999)) {
			end_f[player] = 0;
			ending[player] = 5;
		}
	}
	
	// TOMOYO���[�h�̐������Ԃ��J�E���g�_�E�� #LITE13
	if( (timeOn[player]) && (gameMode[player] == 6) ) {
		ltime[player]--;	// ���~�b�g�^�C������
		
		if((ltime[player] <= 0) && (!tomoyo_ltime_over[player])) {
			// ���~�b�g�^�C����0�ɂȂ�����Q�[���I�[�o�[
			PlaySE(39);
			ltime[player] = 0;
			setGameOver(player);
		} else {
			// �܂����~�b�g�^�C����0�ɂȂ��Ă��Ȃ�
			if((!tomoyo_no_stage_time[player]) && (stime[player] > 0)) {
				stime[player]--;	// �X�e�[�W�^�C������
				
				// �x����
				if(stime[player] == 10 * 60) PlaySE(38);
				if(stime[player] == 0) PlaySE(39);
			}
			
			// ���~�b�g�^�C���x����
			if(ltime[player] == 10 * 60) PlaySE(38);
		}
	}
	
	// ACE���[�h�̐������Ԃ��J�E���g�_�E�� #LITE17
	if((timeOn[player]) && (isAceModeOrMission(player)) && (gameMode[player] != 4) && (gameMode[player] != 5)) {
		ltime[player]--;	// ���~�b�g�^�C������
		
		// �ϋv�~�b�V�����p
		if((gameMode[player] == 8) && (mission_type[c_mission] == 23)) {
			if( ((mission_opt_3[c_mission] == 0) && ((kickc[player] > 10) || (kickc3[player] > 10))) || 
			    ((mission_opt_3[c_mission] > 0) && (mission_opt_3[c_mission] < 99) && 
			     ((kickc[player] > mission_opt_3[c_mission]) || (kickc3[player] > mission_opt_3[c_mission]))) )
			{
				ltime[player]++;
				StopWave(38);
			}
		}
		
		if((gameMode[player] != 8) || (mission_time[c_mission] > 0)) {
			if(ltime[player] <= 0) {
				// ���~�b�g�^�C����0�ɂȂ�����Q�[���I�[�o�[
				ltime[player] = 0;
				
				if((isAceMode(player)) || (mission_type[c_mission] != 23)) {
					PlaySE(39);
					setGameOver(player);
				}
			} else {
				// �x����
				if(ltime[player] == 10 * 60) PlaySE(38);
			}
		}
	}
	
	// VERSUS���[�h�̐������Ԃ��J�E���g�_�E��
	if((timeOn[player]) && (gameMode[player] == 4) && (vs_timelimit > 0) && (player == 0)) {
		ltime[player]--;	// ���~�b�g�^�C������
		
		if(ltime[player] <= 0) {
			// ���~�b�g�^�C����0�ɂȂ����烌�x�����傫�����̏���
			ltime[player] = 0;
			PlaySE(39);
			
			if(!vs_goal_type) {
				i = tc[0];
				j = tc[1];
			} else {
				i = c_norm[0];
				j = c_norm[1];
			}
			
			if(i > j) {
				// 1P WIN
				setGameOver(1);
			} else if(i < j) {
				// 2P WIN
				setGameOver(0);
			} else {
				// DRAW
				setGameOver(0);
				setGameOver(1);
			}
		} else {
			// �x����
			if(ltime[player] == 10 * 60) PlaySE(38);
		}
	}
	
	// �t�B�[���h�^�C�}�[�̃J�E���g�_�E��
	if(hidden[player] == 1) {
		for(j = 0; j < 22; j++)
			for(k = 0; k < 10; k++) 
				if(fldt[k + j * 10 + player * 220] > 0)
					fldt[k + j * 10 + player * 220]--;
	} else if(hidden[player] == 2) {
		for(j = 0; j < 22; j++)
			for(k = 0; k < 10; k++) 
				if(fldt[k + j * 10 + player * 220] < 0)
					fldt[k + j * 10 + player * 220] = fldt[k + j * 10 + player * 220] + 10;
	}
	
	// X-RAY�p�J�E���g
	if(isxray[player]) xray_counter[player]++;
	
	// COLOR�p�J�E���g
	if(iscolor[player]) color_counter[player]++;
	
	// �i�ʃ|�C���g���� #LITE18
	if( (gameMode[player] == 1) || (gameMode[player] == 2) ) {
		if( ((stat[player] == 3)||(stat[player] == 5)) && (combo[player] <= 1) && (!ending[player]) && (gradetype[player] == 0) ) {
			gtime[player]++;
			
			if( (grade[player] <= 29) && (gtime[player] >= glimit[grade[player]]) ) {
				gpoint[player]--;
				gtime[player] = 0;
				
				// �i��9�̂Ƃ��͒i�ʃ|�C���g��0��菬�����Ȃ�Ȃ�
				if( (grade[player] == 0) && (gpoint[player] < 0) ) {
					gpoint[player] = 0;
				}
				
				// �~�i
				if(gpoint[player] < -50) {
					PlaySE(44);
					grade[player]--;
					gpoint[player] = 0;
					gup_down[player] = 0;
					gflash[player] = 120;
				}
			}
		}
	}
	
	// �i�ʏ㏸�A�j�����Ԍ���
	if( (gflash[player] > 0) && (!tspin_frame[player]) ) gflash[player]--;
	
	// BEGINNER���[���ԉ�
	if((gameMode[player] == 0) && (ending[player] == 2)) {
		if(edrec[player] % hanabi_int[player] == 0) {
			sc[player]++;
			hanabi_waiting[player]++;
		}
	}
	
	// �ԉΔ��� #LITE19
	if( (hanabi_waiting[player] > 0) && (onRecord[player] == 1) ) {
		hanabi_frame[player] = hanabi_frame[player] + 1 + (hanabi_waiting[player] > 60);
		
		if(hanabi_frame[player] >= 10) {
			hanabi_waiting[player]--;
			objectCreate(player, 3, -40 + Rand(80) + foffset[player],
			             16 + Rand(20) + 116 * ((checkFieldTop(player) < 12) && (by[player] < 12)), 0, 0, Rand(7), 0);
			hanabi_frame[player] = 0;
		}
	}
	
	if(hanabi_waiting[player] == 0) hanabi_frame[player] = 10;
	
	// �v���`�i�u���b�N������ #LITE22
	if( (platinaerase_cnt[player] > 0) && (count % 10 == 0) ) {
		PlaySE(40);
		platinaerase_cnt[player]--;
	}
	
	// T-SPIN�\���t���[��������
	if(tspin_frame[player]) tspin_frame[player]--;
	
	// BACK TO BACK�\���t���[��������
	if(b_to_b_frame[player]) b_to_b_frame[player]--;
	
	// HIDE NEXT�M�~�b�N
	if(hnext_flag[player] && timeOn[player]) {
		hnext_timer[player]++;
		if(hnext_timer[player] > 720) hnext_timer[player] = 0;
		
		if(((hnext_timer[player] > 540) && (hnext_timer[player] <= 660)) || (( ((hnext_timer[player] > 480) && (hnext_timer[player] <= 540)) || (hnext_timer[player] > 660) ) && (hnext_timer[player] % 2 == 0)))
			ishidenext[player] = 1;
		else
			ishidenext[player] = 0;
	}
	
	// ���x���X�g�b�v���Ԃ��J�E���g
	if( (timeOn[player]) && ((tc[player] % 100 == 99) || (tc[player] == 998)) ) {
		time99[player]++;
	}
	
	// �������A�C�e���̌��ʎ��Ԍ���
	if(item_timer[player] > 0) {
		item_timer[player]--;
		if(item_timer[player] <= 0) endTimerItem(player);
	}
	
	// TOMOYO DUAL��
	if(tomoyo_dual_enable[player]) {
		if(timeOn[player]) {
			// �J�E���^����
			tomoyo_ehfinal_c[player]++;
			if(tomoyo_ehfinal_c[player] > 480) tomoyo_ehfinal_c[player] = 0;
			
			// �t�B�[���h�ʒu������
			if((tomoyo_ehfinal_c[player] >= 220) && (tomoyo_ehfinal_c[player] <= 240)) {
				temp = foffset[0];
				foffset[0] = foffset[1];
				foffset[1] = temp;
				
				temp = boffset[0];
				boffset[0] = boffset[1];
				boffset[1] = temp;
			}
		}
		
		// �g���Ă��Ȃ��ق��̃t�B�[���h��h��Ԃ�
		if((tomoyo_ehfinal_c[player] < 220) || (tomoyo_ehfinal_c[player] > 240)) {
			if(foffset[0] == v_foffset[0])
				ExBltFastRect(84, foffset[1] + ofs_x[0] + 8, 40 + ofs_y[0], 0, 0, 80, 160);
			else
				ExBltFastRect(24, foffset[1] + ofs_x[0] + 8, 40 + ofs_y[0], 0, 0, 80, 160);
		}
	}
	
	// FLASH���[�h �{�[�i�X����
	if((gameMode[player] == 15) && (flash_bonus_points[player] > 0) && (timeOn[player]) && 
	   (stat[player] != 6) && (stat[player] != 8))
	{
		flash_bonus_count[player]--;
		
		if(flash_bonus_count[player] <= 0) {
			flash_bonus_count[player] = 4;
			flash_bonus_points[player]--;
		}
	}
	
	// FLASH-18MIN���[�h ���~�b�g�^�C������
	if((gameMode[player] == 15) && (timeattack[player])) {
		CountDownLimitTime(player);
	}
	
	// SIMPLE-ULTRA���[�h ���~�b�g�^�C������
	if((gameMode[player] == 17) && ((timeattack[player] == 1) || (timeattack[player] == 3)) && (timeOn[player])) {
		ltime[player]--;
		
		if(ltime[player] <= 0) {
			// ���~�b�g�^�C����0�ɂȂ�����N���A
			ltime[player] = 0;
			timeOn[player] = 0;
			
			// �x������~
			pinch[player] = 0;
			StopWave(38);
			
			// ���v���C�L�^�I��
			if((timeattack[player] == 1) && (repversw <= 4)) onRecord[player] = 0;
			
			if(!IsPlayWave(29)) PlaySE(29);
			ending[player] = 1;
			stat[player] = 14;
			for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		} else {
			// �x����
			if(ltime[player] == 10 * 60) PlaySE(38);
		}
	}
	
	// PRACTICE���[�h���~�b�g�^�C������
	if((gameMode[player] == 5) && (p_timelimit > 0)) {
		CountDownLimitTime(player);
	}
	
	// ���C�������\���t���[������
	if(lastline_frame[player] > 0) lastline_frame[player]--;
	
	// �v���v��
	if(purupuru[player]) {
		if(purupuru[player] == 1) {
			purupuru[player] = 2;
			tmp = Rand(2) + 1;
		} else {
			purupuru[player] = 1;
			tmp = Rand(2) + 1 * -1;
		}
		ofs_x[player] = tmp;
	}
}

// ���~�b�g�^�C�������炷
// ���~�b�g�^�C����0�ɂȂ�����Q�[���I�[�o�[
void CountDownLimitTime(int player) {
	if((ltime[player] > 0) && (timeOn[player])) {
		ltime[player]--;
		
		if(ltime[player] <= 0) {
			// ���~�b�g�^�C����0�ɂȂ�����Q�[���I�[�o�[
			ltime[player] = 0;
			PlaySE(39);
			setGameOver(player);
		} else {
			// �x����
			if(ltime[player] == 10 * 60) PlaySE(38);
		}
	}
}

// ���݂̃��[�������[���h�n���ǂ�������
int isWRule(int player) {
	return (rule_rot[rots[player]] == 1);
}

// ���݂̃��[����DRS���ǂ�������
int isDRule(int player) {
	return (rule_rot[rots[player]] == 2);
}

// ��]�@����ύX
int changeRule(int player, int rule) {
	rots[player] = rule;
	if(rots[player] < 0) rots[player] = 9;
	if(rots[player] > 9) rots[player] = 0;
	setNextBlockColors(player, 1);
}

// �ʏ�̃��[�h���ǂ�������iBEGINNER�܂܂Ȃ��j
int isNormalMode(int player) {
	int mode;
	mode = gameMode[player];
	return (((mode >= 1) && (mode <= 3)) || ((mode == 5) && (!p_leveltype)) || (mode == 10) || (mode == 11) || (mode == 13) || (mode == 14) || (mode == 16));
}

// �ʏ�̃��[�h���ǂ�������iBEGINNER�܂ށj
int isNormalOrBeginnerMode(int player) {
	int mode;
	mode = gameMode[player];
	return ((mode <= 3) || ((mode == 5) && (!p_leveltype)) || (mode == 10) || (mode == 11) || (mode == 13) || (mode == 14) || (mode == 16));
}

// ACE�n�̃��[�h���ǂ�������iMISSION�܂܂Ȃ��j
int isAceMode(int player) {
	int mode;
	mode = gameMode[player];
	return ((mode == 7) || (mode == 12) || ((mode == 4) && (vs_goal_type == 1)) || ((mode == 5) && (p_leveltype == 1)));
}

// ACE�n�̃��[�h���ǂ�������iMISSION�܂ށj
int isAceModeOrMission(int player) {
	int mode;
	mode = gameMode[player];
	return ((mode == 7) || (mode == 8) || (mode == 12) || ((mode == 4) && (vs_goal_type == 1)) || ((mode == 5) && (p_leveltype == 1)));
}

// MARATHON���[�h���ǂ�������
int isMarathonMode(int player) {
	int mode;
	mode = gameMode[player];
	return ((mode == 18) || ((mode == 4) && (vs_goal_type == 2)) || ((mode == 5) && (p_leveltype == 2)));
}

// TOMOYO���[�h�̃X�e�[�W�X�L�b�v�@�\
void tomoyoStageSkip(int player) {
	if(!playback) {
		if(IsPressKey(skip_key[player]) || getJoyPressState(player, joy_skip_key[player]))
			stage_skip_mpc[player]++;
		else
			stage_skip_mpc[player] = 0;
	}
	
	if( ((!playback) && (stage_skip_mpc[player] >= stage_skip_tame)) || 
	    ((playback) && (time2[player] == stage_skip_frame[stage_skip_used[player] + player * 20])) )
	{
		timeOn[player] = 0;						// �^�C�}�[��~
		ltime[player] = ltime[player] - 1800;	// -30�b
		sclear[player] = 0;						// �X�L�b�v
		
		// �X�e�[�W�X�L�b�v���g�����t���[�����L�^
		if(!playback) {
			stage_skip_frame[stage_skip_used[player] + player * 20] = time2[player];
		}
		
		stage_skip_used[player]++;				// �g�p��+1
		
		stat[player] = 18;						// �X�e�[�W�I��
		statc[player * 10] = 0;					// �J�E���^������
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.00 - �r���Q���҂����
//������������������������������������������������������������������������������
void statJoinwait(int player) {
	if((count % 5 == 0) && (empty_spin_field)) {
		field_spin[player]++;
		if(field_spin[player] > 19) field_spin[player] = 0;
	}
	
	if(playback) return;
	
	if((player == 1) && (gameMode[0] == 5)) return;
	if((player == 1) && (gameMode[0] == 8)) return;
	
	padRepeat(player);
	
	// PUSH nP START BUTTON
	if(count % 60 > 10) {
		ExBltRect(49, foffset[player] - 2, 85, 100 * player, 50, 100, 65);
	}
	
	if(getPushState(player, 4)) {
		PlaySE(10);
		
		if(bgm == 1) {
			if( !IsPlayMIDI() ) {
				ReplayMIDI();
				StopWave(8);
			}
		}
		
		playerInitial(player);
		
		stat[player] = 1;					// �u���b�N�V���b�^�[���s
		statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 2;			// �V���b�^�[��̓X�e�[�^�XNo.2
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.01 - �u���b�N�V���b�^�[
//������������������������������������������������������������������������������
void statBlockSutter(int player) {
	int		i;
	
	stat[player] = statc[player * 10 + 1];	// ���̃X�e�[�^�X�փW�����v
	
	// �J�E���^�͂��Ƃ����Â�
	for(i = 0; i < 10; i++) {
		statc[player * 10 + i] = 0;
	}
	
	// �t�B�[���h������
	for(i = 0; i < 220; i++) {
		fld[i + player * 220] = 0;
		fldt[i + player * 220] = 0;
		fldu[i + player * 220] = 0;
		fldi[i + player * 220] = 0;
		fldo[i + player * 220] = 0;
		flds[i + player * 220] = 0;
	}
	
	upLines[player] = 0;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.02 - ���[�h�Z���N�g���
//������������������������������������������������������������������������������
// statc[player * 10 + 0] : �������ς݃t���O
// statc[player * 10 + 1] : �I�����Ă��郂�[�h
// statc[player * 10 + 2] : �Q�[���^�C�v
// statc[player * 10 + 3] : ���݂̉��
// statc[player * 10 + 4] : �I�v�V������ʂ̃J�[�\���ʒu
// statc[player * 10 + 5] : �v���C���[�f�[�^�I����ʂőI�����Ă��镶��

void statSelectMode(int player) {
	int i, j, color, color2, move, len;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	color2 = (count % 4 / 2) * fontc[rots[player]];
	padRepeat(player);
	padRepeat2(player);
	
	// ���[�h�Z���N�gBGM�Đ�
	if((!onRecord[1 - player]) && (statc[player * 10 + 0] == 0)) {
		bgmlv = 12;
		changeBGM();
		
		statc[player * 10 + 1] = lastmode[player];
		statc[player * 10 + 2] = lasttype[player];
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		statc[player * 10 + 5] = 0;
		setFieldPosition(maxPlay);
		
		statc[player * 10 + 0] = 1;
	}
	
	printScoreFont(soffset[player], 4 + top_frame, "A: OK", fontc[rots[player]]);
	printScoreFont(soffset[player], 5 + top_frame, "B: BACK", fontc[rots[player]]);
	
	// �v���C���[�f�[�^�Z���N�g
	if(statc[player * 10 + 3] == 0) {
		printFont(boffset[player], 12, "ENTER NAME", 4);
		
		len = StrLen(user_name[player]);	// ���͍ςݕ�����
		
		// ���ړ�
		move = getPressState(player, 3) - getPressState(player, 2);
		if(move)
			if((mpc[player] == 1) || (mpc[player] >= 15) || getPressState(player, 6)) {
				if(mpc[player] >= 15) mpc[player] = 12;
				statc[player * 10 + 5] = statc[player * 10 + 5] + move;
				PlaySE(5);
			}
		
		// �����̃��[�v
		if(statc[player * 10 + 5] > 54)
			statc[player * 10 + 5] = (len == 3) * 53;
		if(statc[player * 10 + 5] < (len == 3) * 53)
			statc[player * 10 + 5] = 54;
		
		// �I�����Ă��镶���Ɠ��͍ςݕ�����\��
		MidStr(RankString, statc[player * 10 + 5] + 1, 1, string[4]);
		printFont(boffset[player] + 3 + len, 14, string[4], 2 * (count % 20 > 10));
		printFont(boffset[player] + 3, 14, user_name[player], 0);
		
		printFont(boffset[player], 16, "PRESS D TO", 1);
		printFont(boffset[player], 17, "GUEST MODE", 1);
		
		if((statc[player * 10 + 5] == 54) && (len != 0) && (!onRecord[1 - player])) {
			printScoreFont(soffset[player], 7 + top_frame, "C+A:", fontc[rots[player]]);
			printScoreFont(soffset[player], 8 + top_frame, "RECORDS", fontc[rots[player]]);
		}
		
		// B�{�^���Ŗ߂�
		if(getPushState(player, 5)) {
			stat[player] = 0;
			if(stat[1 - player] == 0) flag = 1;
			return;
		}
		
		// A�{�^���œ���
		if(getPushState(player, 4)) {
			PlaySE(10);
			
			if(statc[player * 10 + 5] == 53) {
				// RB
				if(len) {
					MidStr(user_name[player], 1, len - 1, user_name[player]);
				}
			} else if(statc[player * 10 + 5] == 54) {
				// ED
				PlaySE(18);
				
				if(!len) {
					// ���O�����͂���Ă��Ȃ��ꍇ�̓v���C���[�f�[�^���g�p
					user_enable[player] = 0;
				} else {
					user_enable[player] = 1;
					
					// ���O�̌��ɃX�y�[�X��}���i���O��1�`2���������Ȃ��ꍇ�A�]���������X�y�[�X�ɂ���j
					sprintf(user_name[player], "%s   ", user_name[player]);
					
					// ������4�����ڈȍ~���폜
					LeftStr(user_name[player], 3, user_name[player]);
					
					// �ǂݍ���
					if(user_load(player) != 0) {
						user_init(player);
					}
					
					// C�������Ă���ꍇ�͋L�^��\��
					if(getPressState(player, 6) && !onRecord[1 - player]) {
						user_view(player);
					}
				}
				
				statc[player * 10 + 3]++;
				return;
			} else {
				// ��������
				StrCat(user_name[player], string[4]);
			}
		}
		
		// D�{�^���Ńv���C���[�f�[�^���g�p
		if(getPushState(player, 7)) {
			user_enable[player] = 0;
			statc[player * 10 + 3]++;
			return;
		}
	}
	// ���[���Z���N�g
	else if(statc[player * 10 + 3] == 1) {
		printScoreFont(soffset[player], 20, "PAUSE:", fontc[rots[player]]);
		printScoreFont(soffset[player], 21, "HELP", fontc[rots[player]]);
		
		// ���[���ꗗ�\��
		printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
		printFont(boffset[player] + 1, 7, "ROT. RULE", fontc[rots[player]]);
		
		printFont(boffset[player], 9 + rots[player], "b", color2);
		
		for(i = 0; i < 10; i++) {
			getRuleNameEx(i, 0);
			printFont(boffset[player] + 1, 9 + i, string[0], (rots[player] == i) * color2);
		}
		
		// �L�[����
		// ��
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 0)) {
			PlaySE(5);
			changeRule(player, rots[player] - 1);
		}
		
		// ��
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 1)) {
			PlaySE(5);
			changeRule(player, rots[player] + 1);
		}
		
		// B�{�^��
		if(getPushState(player, 5)) {
			statc[player * 10 + 3]--;
			return;
		}
		
		// A�{�^��
		if(getPushState(player, 4)) {
			PlaySE(10);
			statc[player * 10 + 3]++;
			return;
		}
		
		// �|�[�Y�{�^���Ńw���v
		if(IsPushKey(pause_key[player]) || getJoyPushState(0, joy_pause_key[player])) {
			PlaySE(0);
			showHelpString(player, help_rule[rots[player] + english * 10]);
			statc[player * 10 + 3] = 4;
			return;
		}
	}
	// ���[�h�Z���N�g
	else if(statc[player * 10 + 3] == 2) {
		printScoreFont(soffset[player], 20, "PAUSE:", fontc[rots[player]]);
		printScoreFont(soffset[player], 21, "HELP", fontc[rots[player]]);
		
		if(statc[player * 10 + 1] <= 7) {
			printScoreFont(soffset[player], 7 + top_frame, "C+A:", fontc[rots[player]]);
			printScoreFont(soffset[player], 8 + top_frame, "OPTIONS", fontc[rots[player]]);
		}
		
		// ���[�h�ꗗ�\��
		printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
		printFont(boffset[player] + 1, 7, "GAME MODE", fontc[rots[player]]);
		
		printFont(boffset[player], 9 + statc[player * 10 + 1], "b", color2);
		
		for(i = 0; i < 9; i++) {
			printFont(boffset[player] + 1, 9 + i, mode_select_name[i], modecolor2[i]);
		}
		
		if(stat[1] == 0) {
			for(i = 9; i < 12; i++) {
				printFont(boffset[player] + 1, 9 + i, mode_select_name[i], modecolor2[i]);
			}
		}
		
		// �Q�[���^�C�v�\��
		// BEGINNER
		if(statc[player * 10 + 1] == 0) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  TAMAYA  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  NOVICE  >");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if(timeattack[player]) printFont(boffset[player] + 1, 24, "ENDLESS", 0);
			
			printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
			printScoreFont(soffset[player], 11 + top_frame, "ENDLESS", fontc[rots[player]]);
		}
		// MASTER
		else if(statc[player * 10 + 1] == 1) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<   EASY   >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<   HARD   >");
			if(statc[player * 10 + 2] == 3) sprintf(string[0], "< 20G-EASY >");
			if(statc[player * 10 + 2] == 4) sprintf(string[0], "<20G-NORMAL>");
			if(statc[player * 10 + 2] == 5) sprintf(string[0], "< 20G-HARD >");
			if(statc[player * 10 + 2] == 6) sprintf(string[0], "<   HEBO+  >");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if(timeattack[player]) printFont(boffset[player] + 1, 24, "ENDLESS", 0);
			
			printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
			printScoreFont(soffset[player], 11 + top_frame, "ENDLESS", fontc[rots[player]]);
		}
		// DEVIL
		else if(statc[player * 10 + 1] == 2) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<   HARD   >");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<   DOOM   >");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if(timeattack[player]) printFont(boffset[player] + 1, 24, "ENDLESS", 0);
			
			printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
			printScoreFont(soffset[player], 11 + top_frame, "ENDLESS", fontc[rots[player]]);
		}
		// TOMOYO
		else if(statc[player * 10 + 1] == 3) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  EHEART  >");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<  TARGET  >");
			if(statc[player * 10 + 2] == 3) sprintf(string[0], "<  FLASH   >");
			if(statc[player * 10 + 2] == 4) sprintf(string[0], "<   EDIT   >");
			if(statc[player * 10 + 2] == 5) sprintf(string[0], "<FLASH-EDIT>");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if((timeattack[player]) && (statc[player * 10 + 2] != 3) && (statc[player * 10 + 2] != 5))
				printFont(boffset[player] + 1, 24, "RANDOM", 0);
			
			if((statc[player * 10 + 2] != 3) && (statc[player * 10 + 2] != 5)) {
				printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
				printScoreFont(soffset[player], 11 + top_frame, "RANDOM", fontc[rots[player]]);
			}
		}
		// ACE
		else if(statc[player * 10 + 1] == 4) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<HI-SPEED 1>");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<HI-SPEED 2>");
			if(statc[player * 10 + 2] == 3) sprintf(string[0], "< ANOTHER  >");
			if(statc[player * 10 + 2] == 4) sprintf(string[0], "< ANOTHER2 >");
			if(statc[player * 10 + 2] == 5) sprintf(string[0], "<  BASIC   >");
			if(statc[player * 10 + 2] == 6) sprintf(string[0], "<   HELL   >");
			if(statc[player * 10 + 2] == 7) sprintf(string[0], "<  HELL-X  >");
			if(statc[player * 10 + 2] == 8) sprintf(string[0], "<   VOID   >");
			printFont(boffset[player] - 1, 23, string[0], color);
		}
		// OLD STYLE
		else if(statc[player * 10 + 1] == 5) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "< HANDHELD >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  ARCADE  >");
			printFont(boffset[player] - 1, 23, string[0], color);
		}
		// FINAL
		else if(statc[player * 10 + 1] == 6) {
			if(timeattack[player]) printFont(boffset[player] + 1, 24, "ENDLESS", 0);
			printScoreFont(soffset[player], 10 + top_frame, "D:", fontc[rots[player]]);
			printScoreFont(soffset[player], 11 + top_frame, "ENDLESS", fontc[rots[player]]);
		}
		// MARATHON
		else if(statc[player * 10 + 1] == 7) {
			if(statc[player * 10 + 2] == 0) sprintf(string[0], "<  NORMAL  >");
			if(statc[player * 10 + 2] == 1) sprintf(string[0], "<  SQUARE  >");
			if(statc[player * 10 + 2] == 2) sprintf(string[0], "<   ONI    >");
			printFont(boffset[player] - 1, 23, string[0], color);
		}
		// SIMPLE
		else if(statc[player * 10 + 1] == 8) {
			if((statc[player * 10 + 2] == 0) || (statc[player * 10 + 2] == 2)) sprintf(string[0], "< 40LINES  >");
			if((statc[player * 10 + 2] == 1) || (statc[player * 10 + 2] == 3)) sprintf(string[0], "<  ULTRA   >");
			printFont(boffset[player] - 1, 23, string[0], color);
			
			if(statc[player * 10 + 2] >= 2) {
				printFont(boffset[player], 24, "ROT. RELAY", 0);
			}
		}
		
		// �L�[����
		// ��
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 0)) {
			PlaySE(5);
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 8 + (stat[1] == 0) * 3;
			
			statc[player * 10 + 2] = 0;
			timeattack[player] = 0;
		}
		
		// ��
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 1)) {
			PlaySE(5);
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 8 + (stat[1] == 0) * 3) statc[player * 10 + 1] = 0;
			
			statc[player * 10 + 2] = 0;
			timeattack[player] = 0;
		}
		
		if((stat[1] != 0) && (statc[player * 10 + 1] > 8)) {
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			timeattack[player] = 0;
		}
		
		// ��
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
		if(getPressState(player, 2)) {
			PlaySE(3);
			statc[player * 10 + 2]--;
			
			if((statc[player * 10 + 1] == 0) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 1;
			if((statc[player * 10 + 1] == 1) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 6;
			if((statc[player * 10 + 1] == 2) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 2;
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 5;
			if((statc[player * 10 + 1] == 4) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 8;
			if((statc[player * 10 + 1] == 5) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 1;
			if((statc[player * 10 + 1] == 6) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 7) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 2;
			if((statc[player * 10 + 1] == 8) && (statc[player * 10 + 2] < 0)) statc[player * 10 + 2] = 3;
		}
		
		// ��
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
		if(getPressState(player, 3)) {
			PlaySE(3);
			statc[player * 10 + 2]++;
			
			if((statc[player * 10 + 1] == 0) && (statc[player * 10 + 2] > 1)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 1) && (statc[player * 10 + 2] > 6)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 2) && (statc[player * 10 + 2] > 2)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 2] > 5)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 4) && (statc[player * 10 + 2] > 8)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 5) && (statc[player * 10 + 2] > 1)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 6) && (statc[player * 10 + 2] > 0)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 7) && (statc[player * 10 + 2] > 2)) statc[player * 10 + 2] = 0;
			if((statc[player * 10 + 1] == 8) && (statc[player * 10 + 2] > 3)) statc[player * 10 + 2] = 0;
		}
		
		// D�{�^��
		if(getPushState(player, 7)) {
			PlaySE(5);
			timeattack[player] = !timeattack[player];
		}
		
		// B�{�^��
		if(getPushState(player, 5)) {
			PlaySE(5);
			statc[player * 10 + 3]--;
			return;
		}
		
		// C+A�{�^��
		if(getPressState(player, 6) && getPressState(player, 4) && (statc[player * 10 + 1] <= 7)) {
			PlaySE(10);
			statc[player * 10 + 3] = 3;
			return;
		}
		
		// A�{�^��
		if(getPushState(player, 4)) {
			PlaySE(10);
			startGame(player, statc[player * 10 + 1], statc[player * 10 + 2], 0);
			return;
		}
		
		// �|�[�Y�{�^���Ńw���v
		if(IsPushKey(pause_key[player]) || getJoyPushState(0, joy_pause_key[player])) {
			PlaySE(0);
			showHelpString(player, help_mode[statc[player * 10 + 1] + english * 12]);
			statc[player * 10 + 3] = 5;
			return;
		}
	}
	// �I�v�V�������
	else if(statc[player * 10 + 3] == 3) {
		// �I�v�V�����ꗗ�\��
		printFont(boffset[player], 6, "SELECT", fontc[rots[player]]);
		printFont(boffset[player] + 3, 7, "OPTIONS", fontc[rots[player]]);
		
		printFont(boffset[player], 10 + statc[player * 10 + 4] * 2, "b", color);
		
		if(statc[player * 10 + 1] == 3) {
			printFont(boffset[player], 9, "STAGE", fontc[rots[player]]);
			sprintf(string[0], "%d", start_stage[player] + 1);
			printFont(boffset[player] + 1, 10, string[0], (statc[player * 10 + 4] == 0) * color);
			
			printFont(boffset[player], 11, "EDIT MODE", fontc[rots[player]]);
			printFont(boffset[player] + 1, 12, "PRESS A", (statc[player * 10 + 4] == 1) * color);
			
			printFont(boffset[player], 13, "FLASH EDIT", fontc[rots[player]]);
			printFont(boffset[player] + 1, 14, "PRESS A", (statc[player * 10 + 4] == 2) * color);
		} else {
			printFont(boffset[player], 9, "BIG ON/OFF", fontc[rots[player]]);
			if(!IsBigStart[player]) sprintf(string[0], "e");
			else sprintf(string[0], "c");
			printFont(boffset[player] + 1, 10, string[0], (statc[player * 10 + 4] == 0) * color);
			
			printFont(boffset[player], 11, "BIG MOVE", fontc[rots[player]]);
			sprintf(string[0], "%d", BigMoveStart[player] + 1);
			printFont(boffset[player] + 1, 12, string[0], (statc[player * 10 + 4] == 1) * color);
			
			printFont(boffset[player], 13, "ITEM", fontc[rots[player]]);
			if(!item_mode[player]) sprintf(string[0], "e");
			else sprintf(string[0], "c");
			printFont(boffset[player] + 1, 14, string[0], (statc[player * 10 + 4] == 2) * color);
		}
		
		// �L�[����
		// ��
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 0)) {
			PlaySE(5);
			statc[player * 10 + 4]--;
			
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 4] < 0)) statc[player * 10 + 4] = 2;
			if((statc[player * 10 + 1] != 3) && (statc[player * 10 + 4] < 0)) statc[player * 10 + 4] = 2;
		}
		
		// ��
		if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
		if(getPressState(player, 1)) {
			PlaySE(5);
			statc[player * 10 + 4]++;
			
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 4] > 2)) statc[player * 10 + 4] = 0;
			if((statc[player * 10 + 1] != 3) && (statc[player * 10 + 4] > 2)) statc[player * 10 + 4] = 0;
		}
		
		// ��
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
		if(getPressState(player, 2)) {
			PlaySE(3);
			
			if(statc[player * 10 + 1] == 3) {
				if(statc[player * 10 + 4] == 0) {
					start_stage[player]--;
					if(start_stage[player] < 0) start_stage[player] = 999;
					stage[player] = start_stage[player];
				}
			} else {
				if(statc[player * 10 + 4] == 0) IsBigStart[player] = !IsBigStart[player];
				if(statc[player * 10 + 4] == 1) BigMoveStart[player] = !BigMoveStart[player];
				if(statc[player * 10 + 4] == 2) item_mode[player] = !item_mode[player];
			}
		}
		
		// ��
		if((mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6))
		if(getPressState(player, 3)) {
			PlaySE(3);
			
			if(statc[player * 10 + 1] == 3) {
				if(statc[player * 10 + 4] == 0) {
					start_stage[player]++;
					if(start_stage[player] > 999) start_stage[player] = 0;
					stage[player] = start_stage[player];
				}
			} else {
				if(statc[player * 10 + 4] == 0) IsBigStart[player] = !IsBigStart[player];
				if(statc[player * 10 + 4] == 1) BigMoveStart[player] = !BigMoveStart[player];
				if(statc[player * 10 + 4] == 2) item_mode[player] = !item_mode[player];
			}
		}
		
		// B�{�^��
		if(getPushState(player, 5)) {
			PlaySE(5);
			statc[player * 10 + 3]--;
			return;
		}
		
		// A�{�^��
		if(getPushState(player, 4)) {
			PlaySE(10);
			
			if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 4] == 1)) {
				// TOMOYO�G�f�B�b�g
				if(!onRecord[1 - player]) StopAllBGM();
				
				gameMode[player] = 6;
				stat[player] = 20;
				for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
				
				stage[player] = start_stage[player];
				loadTomoyoStage(player, stage[player], 0);
			} else if((statc[player * 10 + 1] == 3) && (statc[player * 10 + 4] == 2)) {
				// FLASH�G�f�B�b�g
				if(!onRecord[1 - player]) StopAllBGM();
				
				gameMode[player] = 15;
				stat[player] = 20;
				for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
				
				stage[player] = start_stage[player];
				loadTomoyoStage(player, stage[player], 2);
			} else {
				startGame(player, statc[player * 10 + 1], statc[player * 10 + 2], 1);
			}
			
			return;
		}
	}
	// �w���v�i���[���j
	else if(statc[player * 10 + 3] == 4) {
		getRuleNameEx(rots[player], 0);
		printFont(boffset[player], 6, string[0], fontc[rots[player]]);
		
		if(getPushState(player, 4) || getPushState(player, 5)) {
			TextLayerOff(player);
			statc[player * 10 + 3] = 1;
			return;
		}
	}
	// �w���v�i���[�h�j
	else if(statc[player * 10 + 3] == 5) {
		printFont(boffset[player], 6, mode_select_name[statc[player * 10 + 1]], modecolor2[statc[player * 10 + 1]]);
		
		if(getPushState(player, 4) || getPushState(player, 5)) {
			TextLayerOff(player);
			statc[player * 10 + 3] = 2;
			return;
		}
	}
}

// ��������\��
void showHelpString(int player, str *helpStr) {
	int i, j, draw_rate;
	
	// �������s
	sprintf(string[0], "");
	j = 0;
	for(i = 0; i < StrLen(helpStr); i++) {
		MidStr(helpStr, i + 1, 1, string[1]);
		StrCat(string[0], string[1]);
		
		// 16�o�C�g���Ƃɉ��s
		if(j >= 15) {
			StrCat(string[0], "\n");
			j = 0;
		} else {
			j++;
		}
	}
	
	// �\��
	TextLayerOff(player);
	
	if(screenMode >= 2) draw_rate = 2;
	else draw_rate = 1;
	
	TextSize(player, 10 * draw_rate);
	TextColor(player, 255, 255, 255);
	TextBackColorDisable(player);
	TextOut(player, string[0]);
	TextLayerOn(player, (foffset[player] + 8) * draw_rate, 56 * draw_rate);
}

// �i�ʎ����ɓ��邩�ǂ�������
void admitGradeCheck(int player) {
	int i, j, temp1, temp2, grade_his_buf[5];
	int grade_his[5], admit_grade, grade_pasttime;
	
	// ����
	examination[player] = 0;
	
	admit_grade = user_master_hard_admit[player];
	grade_pasttime = user_master_hard_grade_pasttime[player];
	for(i = 0; i < 5; i++) {
		grade_his[i] = user_master_hard_grade_his[player * 5 + i];
		if((grade_his[i] < 0) || (grade_his[i] > 32)) return;
	}
	
	if(admit_grade >= 32) return;	// �F��i�ʂ�GM�������牽�����Ȃ�
	
	// ���i�`�F�b�N
	if(admit_grade < 32) {
		temp2 = 5 - grade_pasttime; // ��������o�ߎ���
		if(temp2 < 1) temp2 = 1; // 0�ɂ͂��Ȃ�
		if((grade_his[0] == grade_his[1]) && (abs(admit_grade - grade_his[0]) > temp2)) {
			exam_grade[player] = grade_his[0];
			
			// ���݂̔F��i�ʂƎ����i�ʂ̍����傫���Ȃ肷���Ȃ��悤�ɂ���
			if(exam_grade[player] - admit_grade > 5) exam_grade[player] = admit_grade + 5;
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] > admit_grade)) {
				examination[player] = 1;
				return;
			}
		}
		
		temp1 = grade_his[0] + grade_his[1] + grade_his[2] / 3;
		temp2 = 4 - grade_pasttime;
		if(temp2 < 1) temp2 = 1;
		if((temp1 % 3 == 0) && (abs(admit_grade - grade_his[0]) > temp2)) {
			exam_grade[player] = temp1;
			
			// ���݂̔F��i�ʂƎ����i�ʂ̍����傫���Ȃ肷���Ȃ��悤�ɂ���
			if(exam_grade[player] - admit_grade > 5) exam_grade[player] = admit_grade + 5;
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] > admit_grade)) {
				examination[player] = 1;
				return;
			}
		}
		
		temp1 = grade_his[0] + grade_his[1] + grade_his[2] + grade_his[3] / 3;
		temp2 = 3 - grade_pasttime;
		if(temp2 < 1) temp2 = 1;
		if((grade_pasttime >= 2) && (temp1 == 0) && (abs(admit_grade - temp1) > temp2)) {
			exam_grade[player] = temp1;
			
			// ���݂̔F��i�ʂƎ����i�ʂ̍����傫���Ȃ肷���Ȃ��悤�ɂ���
			if(exam_grade[player] - admit_grade > 5) exam_grade[player] = admit_grade + 5;
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] > admit_grade)) {
				examination[player] = 1;
				return;
			}
		}
	}
	
	// �~�i�`�F�b�N
	// �F��i�ʂ������Ȃ�Ɨ����₷���Ȃ�
	// �F��i�ʂ�S3�ȏ�ōŌ�̎�������2�Q�[���ȏ�o�߂��Ă���Ɣ�������\������
	
	// m8�ȏ�
	if((admit_grade > 24) && (grade_pasttime >= 2)) {
		if((grade_his[0] + grade_his[1]) / 2 < admit_grade - 3) {
			exam_grade[player] = grade_his[0];
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] < admit_grade)) {
				examination[player] = 2;
				return;
			}
		}
	}
	
	// m2�ȏ�
	if((admit_grade > 18) && (grade_pasttime >= 2)) {
		if((grade_his[0] + grade_his[1] + grade_his[2]) / 3 < admit_grade - 4) {
			exam_grade[player] = grade_his[0];
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] < admit_grade)) {
				examination[player] = 2;
				return;
			}
		}
	}
	
	// S3�ȏ�
	if((admit_grade > 10) && (grade_pasttime >= 2)) {
		// ������בւ����
		// �o�b�t�@�ɓ����
		for(i = 0; i < 5; i++) grade_his_buf[i] = grade_his[i];
		
		// �o�u���\�[�g
		for(i = 0; i < 4; i++) {
			for(j = 4; j > i; j--) {
				// �O�̗v�f�̕����傫���������������
				if(grade_his_buf[j - 1] > grade_his_buf[j]) {
					temp1 = grade_his_buf[j];
					grade_his_buf[j] = grade_his_buf[j - 1];
					grade_his_buf[j - 1] = temp1;
				}
			}
		}
		
		// �傫���ق�����3�̕��ς����݂��5��
		if((grade_his[0] + grade_his[1] + grade_his[2] + grade_his[3] + grade_his[4]) / 3 < admit_grade - 5) {
			exam_grade[player] = grade_his_buf[0];
			
			if((exam_grade[player] >= 1) && (exam_grade[player] <= 32) && (exam_grade[player] < admit_grade)) {
				examination[player] = 2;
				return;
			}
		}
	}
}

// �Q�[���J�n����
void startGame(int player, int mode, int type, int opt) {
	int i;
	
	// �Ō�ɑI�񂾃Q�[�����[�h���L��
	lastmode[player] = mode;
	lasttype[player] = type;
	
	// �Q�[�����[�h��ݒ�
	// BEGINNER
	if(mode == 0) {
		// TAMAYA
		if(type == 0) gameMode[player] = 0;
		// NOVICE
		if(type == 1) gameMode[player] = 13;
		
		timeattack[player] = !timeattack[player];
	}
	// MASTER
	else if(mode == 1) {
		// EASY
		if(type == 0) {
			gameMode[player] = 1;
			gradetype[player] = 2;
		}
		// NORMAL
		if(type == 1) {
			gameMode[player] = 1;
			gradetype[player] = 0;
		}
		// HARD
		if(type == 2) {
			gameMode[player] = 1;
			gradetype[player] = 1;
		}
		// 20G-EASY
		if(type == 3) {
			gameMode[player] = 2;
			gradetype[player] = 2;
		}
		// 20G-NORMAL
		if(type == 4) {
			gameMode[player] = 2;
			gradetype[player] = 0;
		}
		// 20G-HARD
		if(type == 5) {
			gameMode[player] = 2;
			gradetype[player] = 1;
		}
		// HEBO+
		if(type == 6) {
			gameMode[player] = 10;
		}
		
		timeattack[player] = !timeattack[player];
	}
	// DEVIL
	else if(mode == 2) {
		// NORMAL
		if(type == 0) {
			gameMode[player] = 11;
		}
		// HARD
		if(type == 1) {
			gameMode[player] = 16;
			r_enable[player] = 1;
		}
		// DOOM
		if(type == 2) {
			gameMode[player] = 3;
			r_enable[player] = 1;
		}
		
		timeattack[player] = !timeattack[player];
	}
	// TOMOYO
	else if(mode == 3) {
		// NORMAL
		if(type == 0) {
			gameMode[player] = 6;
			if(!opt) start_stage[player] = 0;
		}
		// EHEART
		if(type == 1) {
			gameMode[player] = 6;
			if(!opt) start_stage[player] = 27;
		}
		// TARGET
		if(type == 2) {
			gameMode[player] = 6;
			if(!opt) start_stage[player] = 45;
		}
		// FLASH
		if(type == 3) {
			gameMode[player] = 15;
			start_stage[player] = 0;
			timeattack[player] = 0;
		}
		// EDIT
		if(type == 4) {
			gameMode[player] = 6;
			if(!opt) start_stage[player] = 72;
		}
		// FLASH-EDIT
		if(type == 5) {
			gameMode[player] = 15;
			start_stage[player] = 0;
			timeattack[player] = 0;
			flash_edit[player] = 1;
		}
		
		stage[player] = start_stage[player];
		
		// NEXT������
		if((!timeattack[player]) && (type != 3) && (type != 5)) {
			tomoyoNextInit(player, 0);
			setNextBlockColors(player, 1);
		}
	}
	// ACE
	else if(mode == 4) {
		if(type <= 4) {
			// NORMAL�`ANOTHER2
			gameMode[player] = 7;
			timeattack[player] = type;
		} else {
			// BASIC�`VOID
			gameMode[player] = 12;
			timeattack[player] = type - 5;
		}
	}
	// OLD STYLE
	else if(mode == 5) {
		gameMode[player] = 9;
		timeattack[player] = type;
	}
	// FINAL
	else if(mode == 6) {
		gameMode[player] = 14;
		timeattack[player] = !timeattack[player];
	}
	// MARATHON
	else if(mode == 7) {
		gameMode[player] = 18;
		timeattack[player] = type;
	}
	// SIMPLE
	else if(mode == 8) {
		gameMode[player] = 17;
		timeattack[player] = type;
	}
	// VERSUS
	else if(mode == 9) {
		enterVersusMode();
		return;
	}
	// MISSION
	else if(mode == 10) {
		enterMissionMode();
		return;
	}
	// PRACTICE
	else if(mode == 11) {
		enterPracticeMode();
		return;
	}
	
	// BIG�ݒ�
	IsBig[player] = IsBigStart[player];
	BigMove[player] = BigMoveStart[player];
	
	// BGM��~
	if(stat[1 - player] == 0) StopAllBGM();
	
	// �J�n�X�s�[�h�ݒ�
	setStartLevel(player);
	
	// �J�nBGM�ݒ�
	setstartBGM(player);
	
	for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
	stat[player] = 1;				// �u���b�N�V���b�^�[���s
	statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
	statc[player * 10 + 1] = 3;		// �V���b�^�[��̓X�e�[�^�XNo.3
	
	if(gameMode[player] == 15) statc[player * 10 + 1] = 36;	// FLASH�p�Z���N�g���
	if(gameMode[player] == 17) statc[player * 10 + 1] = 38;	// SIMPLE�p�Z���N�g���
	
	// MASTER-HARD�i�ʎ���
	if((gameMode[player] == 1) && (gradetype[player] == 1) && (user_enable[player])) {
		admitGradeCheck(player);
		if(examination[player]) statc[player * 10 + 1] = 40;
	}
}

// �J�n�X�s�[�h�Ȃǂ�ݒ�
void setStartLevel(int player) {
	jump(gameMode[player],lbeg,lmas,l20g,ldvl,lvs,lpra,ltmo,lace,lmis,lold,lhep,ldvm,lace200,lbeg,lfinal,ltmo,ledvl,lstd,lmar);
	
	/*
	switch(gameMode[player]) {
		case  0: goto lbeg;
		case  1: goto lmas;
		case  2: goto l20g;
		case  3: goto ldvl;
		case  4: goto lvs;
		case  5: goto lpra;
		case  6: goto ltmo;
		case  7: goto lace;
		case  8: goto lmis;
		case  9: goto lold;
		case 10: goto lhep;
		case 11: goto ldvm;
		case 12: goto lace200;
		case 13: goto lbeg;
		case 14: goto lfinal;
		case 15: goto ltmo;
		case 16: goto ledvl;
		case 17: goto lstd;
		case 18: goto lmar;
	}
	*/
	
	lbeg:	// BEGINNER-TAMAYA
		sp[player] = lvTableBeg[0];
		wait1[player] = wait1_Beginner;
		wait2[player] = wait2_Beginner;
		wait3[player] = wait3_Beginner;
		waitt[player] = waitt_Beginner;
		return;
	
	lmas:	// MASTER
		sp[player]    = lvTableTgm[0];
		wait1[player] = wait1_master_half;
		wait2[player] = wait2_master_half;
		wait3[player] = wait3_master_half;
		waitt[player] = waitt_master_half;
		
		// ���؂�^�C���ݒ� #LITE20
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_master[rots[player]];
		}
		return;
	
	l20g:	// 20G
		sp[player]    = 1200;
		wait1[player] = wait1_20G_half;
		wait2[player] = wait2_20G_half;
		wait3[player] = wait3_20G_half;
		waitt[player] = waitt_20G_half;
		
		// ���؂�^�C���ݒ� #LITE20
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_20G[rots[player]];
		}
		return;
	
	ldvl:	// DEVIL-DOOM
		sp[player]    = 1200;
		
		if(repversw <= 6) {
			wait1[player] = wait1_devil_tbl6[0];
			wait2[player] = wait2_devil_tbl6[0];
			wait3[player] = wait3_devil_tbl6[0];
			waitt[player] = waitt_devil_tbl6[0];
		} else if(repversw <= 7) {
			wait1[player] = wait1_devil_tbl7[0];
			wait2[player] = wait2_devil_tbl7[0];
			wait3[player] = wait3_devil_tbl7[0];
			waitt[player] = waitt_devil_tbl7[0];
		} else {
			wait1[player] = wait1_devil_tbl[0];
			wait2[player] = wait2_devil_tbl[0];
			wait3[player] = wait3_devil_tbl[0];
			waitt[player] = waitt_devil_tbl[0];
		}
		
		// ���؂�^�C���ݒ� #LITE20
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_devild[rots[player]];
			timelimit[1 + player * 2] = timelimit[0 + player * 2] * 2;
		}
		return;
	
	lvs:	// VERSUS
		return;
	
	lpra:	// PRACTICE
		return;
	
	ltmo:	// TOMOYO
		sp[player]    = lvTabletomoyo[0];
		wait1[player] = wait1_tomoyo;
		wait2[player] = wait2_tomoyo;
		wait3[player] = wait3_tomoyo;
		waitt[player] = waitt_tomoyo;
		return;
	
	lace:	// ACE (NORMAL�`ANOTHER2�j
		if(timeattack[player] == 0) {
			// NORMAL
			if(repversw >= 2) sp[player] = lvTableAce[0];
			else if(repversw == 1) sp[player] = lvTableAce1[0];
			else sp[player] = lvTableAceOld[0];
			wait1[player] = wait1_Ace;
			wait2[player] = wait2_Ace;
			wait3[player] = wait3_Ace;
			waitt[player] = waitt_Ace;
			ltime[player] = timeLimitAceNormal[0];
		} else if(timeattack[player] == 1) {
			// HI-SPEED1
			sp[player] = lvTableHiSpeed1[0];
			wait1[player] = wait1_HiSpeed1;
			wait2[player] = wait2_HiSpeed1;
			wait3[player] = wait3_HiSpeed1;
			waitt[player] = waitt_HiSpeed1;
			ltime[player] = timeLimitAcea[0];
		} else if(timeattack[player] == 2) {
			// HI-SPEED2
			sp[player] = 1200;
			wait1[player] = wait1_HiSpeed2;
			wait2[player] = wait2_HiSpeed2;
			wait3[player] = wait3_HiSpeed2;
			waitt[player] = waitt_HiSpeed2;
			ltime[player] = timeLimitAcea[0];
		} else if(timeattack[player] == 3) {
			// ANOTHER
			sp[player] = 1200;
			
			if(repversw <= 6) {
				wait1[player] = wait1_Acea_tbl6[0];
				wait2[player] = wait2_Acea_tbl6[0];
				wait3[player] = wait3_Acea_tbl6[0];
				waitt[player] = waitt_Acea_tbl6[0];
			} else if(repversw <= 7) {
				wait1[player] = wait1_Acea_tbl7[0];
				wait2[player] = wait2_Acea_tbl7[0];
				wait3[player] = wait3_Acea_tbl7[0];
				waitt[player] = waitt_Acea_tbl7[0];
			} else {
				wait1[player] = wait1_Acea_tbl[0];
				wait2[player] = wait2_Acea_tbl[0];
				wait3[player] = wait3_Acea_tbl[0];
				waitt[player] = waitt_Acea_tbl[0];
			}
			
			ltime[player] = timeLimitAcea[0];
		} else if(timeattack[player] == 4) {
			// ANOTHER2
			sp[player] = 1200;
			
			if(repversw <= 6) {
				wait1[player] = wait1_Acea_tbl6[14];
				wait2[player] = wait2_Acea_tbl6[14];
				wait3[player] = wait3_Acea_tbl6[14];
				waitt[player] = waitt_Acea_tbl6[14];
			} else if(repversw <= 7) {
				wait1[player] = wait1_Acea_tbl7[14];
				wait2[player] = wait2_Acea_tbl7[14];
				wait3[player] = wait3_Acea_tbl7[14];
				waitt[player] = waitt_Acea_tbl7[14];
			} else {
				wait1[player] = wait1_Acea_tbl[14];
				wait2[player] = wait2_Acea_tbl[14];
				wait3[player] = wait3_Acea_tbl[14];
				waitt[player] = waitt_Acea_tbl[14];
			}
			
			ltime[player] = timeLimitAcea[0];
		}
		
		m_norm[player] = 10;
		tc[player] = 0;
		return;
	
	lmis:	// MISSION
		return;
	
	lold:	// OLD STYLE
		if(timeattack[player] == 0) {
			sp[player] = lvTableHeboGB[0];
			wait1[player] = wait1_HeboGB;
			wait2[player] = wait2_HeboGB;
			wait3[player] = wait3_HeboGB_tbl[0];
			waitt[player] = waitt_HeboGB_tbl[0];
			heboGB[player] = 1;
			m_norm[player] = 10;
		} else {
			sp[player] = lvTableHeboAC[0];
			wait1[player] = wait1_HeboAC;
			wait2[player] = wait2_HeboAC;
			wait3[player] = wait3_HeboAC;
			waitt[player] = waitt_HeboAC;
			speedtype[player] = 1;
			heboGB[player] = 2;
		}
		
		tc[player] = 0;
		return;
	
	lhep:	// HEBO+
		sp[player]    = lvTableTgm[0];
		wait1[player] = wait1_master_half;
		wait2[player] = wait2_master_half;
		wait3[player] = wait3_master_half;
		waitt[player] = waitt_master_half;
		
		// ����オ��p
		uplinetype[player] = 1;
		r_inter[player] = 13;
		return;
	
	ldvm:	// DEVIL-NORMAL
		sp[player] = 1200;
		
		if(repversw <= 6) {
			wait1[player] = wait1_devil_m_tbl6[0];
			wait2[player] = wait2_devil_m_tbl6[0];
			wait3[player] = wait3_devil_m_tbl6[0];
			waitt[player] = waitt_devil_m_tbl6[0];
		} else {
			wait1[player] = wait1_devil_m_tbl[0];
			wait2[player] = wait2_devil_m_tbl[0];
			wait3[player] = wait3_devil_m_tbl[0];
			waitt[player] = waitt_devil_m_tbl[0];
		}
		
		// ���؂�^�C���ݒ�
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_deviln[rots[player]];
		}
		return;
	
	lace200:	// ACE (BASIC�`VOID�j
		if(timeattack[player] == 0) {
			// BASIC
			sp[player] = lvTableAce200Basic[0];
			wait1[player] = wait1_Ace200Basic_tbl[0];
			wait2[player] = wait2_Ace200Basic_tbl[0];
			wait3[player] = wait3_Ace200Basic_tbl[0];
			waitt[player] = waitt_Ace200Basic_tbl[0];
			ltime[player] = timeLimitAce200Basic[0];
		} else if(timeattack[player] == 1) {
			// HELL
			sp[player] = lvTableAce200Basic[19];
			wait1[player] = wait1_Ace200Basic_tbl[19];
			wait2[player] = wait2_Ace200Basic_tbl[19];
			wait3[player] = wait3_Ace200Basic_tbl[19];
			waitt[player] = waitt_Ace200Basic_tbl[19];
			ltime[player] = timeLimitAce200Hell[0];
			
			isblind[player] = 1;
		} else if(timeattack[player] == 2) {
			// HELL-X
			sp[player] = lvTableAce200Basic[19];
			wait1[player] = wait1_Ace200Basic_tbl[19];
			wait2[player] = wait2_Ace200Basic_tbl[19];
			wait3[player] = wait3_Ace200Basic_tbl[19];
			waitt[player] = waitt_Ace200Basic_tbl[19];
			ltime[player] = timeLimitAce200Hell[0];
			
			always_over1000[player] = 1;
			o_nblk[0 + player * 6] = 1;
			o_nblk[1 + player * 6] = 1;
			o_nblk[2 + player * 6] = 1;
			o_nblk[3 + player * 6] = 1;
			o_nblk[4 + player * 6] = 1;
			o_nblk[5 + player * 6] = 1;
		} else if(timeattack[player] == 3) {
			// VOID
			sp[player] = lvTableAce200Basic[19];
			wait1[player] = wait1_Ace200Void_tbl[0];
			wait2[player] = wait2_Ace200Void_tbl[0];
			wait3[player] = wait3_Ace200Void_tbl[0];
			waitt[player] = waitt_Ace200Void_tbl[0];
			ltime[player] = timeLimitAce200Void[0];
			
			always_over1000[player] = 1;
			o_nblk[0 + player * 6] = 1;
			o_nblk[1 + player * 6] = 1;
			o_nblk[2 + player * 6] = 1;
			o_nblk[3 + player * 6] = 1;
			o_nblk[4 + player * 6] = 1;
			o_nblk[5 + player * 6] = 1;
		}
		
		m_norm[player] = 10;
		tc[player] = 0;
		return;
	
	lfinal:		// FINAL
		sp[player]    = 1200;
		
		if(repversw <= 4) {
			wait1[player] = wait1_final4[0];
			wait2[player] = wait2_final4[0];
			wait3[player] = wait3_final4[0];
			waitt[player] = waitt_final4[0];
		} else {
			if(rule_lock_reset[rots[player]]) {
				wait1[player] = wait1_final_srs[0];
				wait2[player] = wait2_final_srs[0];
				wait3[player] = wait3_final_srs[0];
				waitt[player] = waitt_final_srs[0];
			} else {
				wait1[player] = wait1_final_ars[0];
				wait2[player] = wait2_final_ars[0];
				wait3[player] = wait3_final_ars[0];
				waitt[player] = waitt_final_ars[0];
			}
		}
		
		always_over1000[player] = 1;
		o_nblk[0 + player * 6] = 1;
		o_nblk[1 + player * 6] = 1;
		o_nblk[2 + player * 6] = 1;
		o_nblk[3 + player * 6] = 1;
		o_nblk[4 + player * 6] = 1;
		o_nblk[5 + player * 6] = 1;
		
		return;
	
	ledvl:		// DEVIL-HARD
		sp[player]    = 1200;
		wait1[player] = wait1_devil_tbl32[0];
		wait2[player] = wait2_devil_tbl32[0];
		wait3[player] = wait3_devil_tbl32[0];
		waitt[player] = waitt_devil_tbl32[0];
		
		// ���؂�^�C���ݒ�
		if(!playback) {
			timelimit[0 + player * 2] = timelimit_devilh[rots[player]];
			timelimit[1 + player * 2] = timelimit[0 + player * 2] * 2;
		}
		return;
	
	lstd:		// SIMPLE
		tc[player] = 0;
		if((timeattack[player] == 0) || (timeattack[player] == 2)) m_norm[player] = 40;
		if((timeattack[player] == 1) || (timeattack[player] == 3)) ltime[player] = 7200;
		return;
	
	lmar:		// MARATHON
		tc[player] = 0;
		m_norm[player] = 5;
		
		if(timeattack[player] == 2) {
			// �S
			sp[player] = 1200;
			wait1[player] = wait1_Marathon_Oni[0];
			wait2[player] = wait2_Marathon_Oni[0];
			wait3[player] = wait3_Marathon_Oni[0];
			waitt[player] = waitt_Marathon_Oni[0];
		} else {
			// �ʏ�
			sp[player] = lvTableMarathon[0];
			wait1[player] = wait1_Ace;
			wait2[player] = wait2_Ace;
			wait3[player] = wait3_Ace;
			waitt[player] = waitt_Ace;
			speedtype[player] = 1;
		}
		
		// �X�N�E�F�A
		if(timeattack[player] == 1) {
			squaremode[player] = 1;
		}
		return;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.03 - Ready !?
//������������������������������������������������������������������������������
void statReady(int player) {
	int i, tmp;
	
	// CPU�̑���
	if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
		if(!statc[player * 10]) cpu_setBestSpot(player, next[player], 0, getNextBlock(player, nextc[player] + 1), 0);
		
		cpu_setCtrl(player);
	}
	
	padRepeat(player);
	
	if(statc[player * 10] == 0) {
		ready_count[player]++;
	}
	
	// �v���C��+1 (�v���C���[�f�[�^�g�p��)
	if((statc[player * 10] == 0) && (ready_count[player] == 1) && (user_enable[player])) {
		user_playcount[player]++;
	}
	
	// READY��GO�̎��Ԃ�ݒ�
	if( (!playback) && (statc[player * 10] == 0) ) {
		if( ((nextskip == 0) && (gameMode[player] == 6)) || 
		    ((nextskip == 1) && ((gameMode[player] == 6) || (gameMode[player] == 15))) || 
		    (nextskip == 2) )
		{
			// TOMOYO
			ready_start[player] = s_ready_start;
			ready_end[player]   = s_ready_end;
			go_start[player]    = s_go_start;
			go_end[player]      = s_go_end;
		} else {
			// �ʏ�
			ready_start[player] = n_ready_start;
			ready_end[player]   = n_ready_end;
			go_start[player]    = n_go_start;
			go_end[player]      = n_go_end;
		}
	}
	
	if( (gameMode[player] == 6) && (statc[player * 10] == 0) ) {
		// TOMOYO���[�h�̃X�e�[�W�ǂݍ���
		loadTomoyoStage(player, stage[player], 0);
		
		// �v���`�i�u���b�N���𐔂���
		rest_pblock[player] = getPlatinumBlock(player);
		
		// �v���`�i�u���b�N��1���Ȃ��ꍇ�̓G���f�B���O
		if(!rest_pblock[player]) {
			StopAllBGM();						// BGM��~
			onRecord[player] = 0;				// ���v���C�L�^�I��
			stage[player]--;
			ending[player] = 3;
			stat[player] = 14;
			statc[player * 10] = 0;
			return;
		}
		
		// �X�e�[�W�J�n����nextc���L��
		stage_nextc[player] = nextc[player];
		
		// BGM�ݒ�
		if((bgmlv != tomoyo_bgm[player]) && (!onRecord[1 - player])) {
			fadelv = 1;
			bgmlv = tomoyo_bgm[player];
		}
		
		// �X�s�[�h�ݒ�
		if((enable_minspeed) && (sp[player] < min_speed[player]))
			sp[player] = min_speed[player];
		
		// DEVIL500�M�~�b�N
		if(tomoyo_waits[player] && enable_minspeed) {
			if(repversw <= 6) {
				wait1[player] = wait1_devil_tbl6[5];
				wait2[player] = wait2_devil_tbl6[5];
				wait3[player] = wait3_devil_tbl6[5];
				waitt[player] = waitt_devil_tbl6[5];
			} else if(repversw <= 7) {
				wait1[player] = wait1_devil_tbl7[5];
				wait2[player] = wait2_devil_tbl7[5];
				wait3[player] = wait3_devil_tbl7[5];
				waitt[player] = waitt_devil_tbl7[5];
			} else {
				wait1[player] = wait1_devil_tbl[5];
				wait2[player] = wait2_devil_tbl[5];
				wait3[player] = wait3_devil_tbl[5];
				waitt[player] = waitt_devil_tbl[5];
			}
		}
		
		// DUAL�M�~�b�N
		if(tomoyo_dual[player]) {
			tomoyo_dual_enable[player] = !maxPlay;
		} else {
			tomoyo_dual_enable[player] = 0;
		}
		
		if(tomoyo_dual_enable[player]) {
			b_maxPlay = maxPlay;	// �v���C�l�����o�b�N�A�b�v
			maxPlay = 1;			// �ꎞ�I��DUAL��ɂ���
			
			backno = 15;			// back_vs.png
			
			for(i = 0; i < 2; i++) {
				// �t�B�[���h�̕\���ʒu���o�b�N�A�b�v
				b_foffset[i] = foffset[i];
				b_boffset[i] = boffset[i];
				
				// �t�B�[���h�̕\���ʒu��ύX
				foffset[i] = v_foffset[i];
				boffset[i] = v_boffset[i];
			}
			
			// 2P����������
			gameMode[1] = 6;
			playerInitial(1);
			tomoyo_dual[1] = 1;
			tomoyo_dual_enable[1] = 1;
			stat[1] = 35;
		}
		
		// �M�~�b�N�x��
		if(isfmirror[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 0, 0);
		} else if(rollroll_flag[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 1, 0);
		} else if(IsBig[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 2, 0);
		} else if(xray_flag[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 3, 0);
		} else if(color_flag[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 4, 0);
		} else if(hnext_flag[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, 6, 0);
		} else if(tomoyo_waits[player]) {
			if(enable_minspeed) objectCreate(player, 8, 0, 0, 0, 0, 11, 0);
		} else if(blind_flag[player] || isthunder[player] || tomoyo_rise[player]) {
			objectCreate(player, 8, 0, 0, 0, 0, -1, 0);
		}
		
		// ����オ��^�C�v�ݒ�
		uplinetype[player] = 2;
	}
	
	// FLASH���[�h
	if((gameMode[player] == 15) && (statc[player * 10] == 0)) {
		// ���v���C�p�����ݒ�
		if((playback) && (start_stage[player] == stage[player])) {
			loadTomoyoStage(player, stage[player], 1 + flash_edit[player]);
			flash_bonus_points[player] = 1000 * ((stage[player] / 4) + 1);
			flash_bonus_count[player] = 0;
		}
		
		// �v���`�i�u���b�N�̐��𐔂���
		rest_pblock[player] = getPlatinumBlock(player);
		
		// �������Ԃ��Z�b�g
		if((start_stage[player] == stage[player]) && (timeattack[player])) ltime[player] = 64800;
		
		// BGM�؂�ւ�
		tmp = bgmlv;
		setstartBGM(player);
		if(bgmlv != tmp) fadelv = 1;
		
		scanItem(player);
	}
	
	// STAGE�̕\��(TOMOYO)
	if((gameMode[player] == 6) && (statc[player * 10] >= ready_start[player])) {
		printFont(boffset[player] + 1, 9, "STAGE", fontc[rots[player]]);
		getTomoyoStageNo(stage[player], 0, 1);
		printFont(boffset[player] + 7, 9, string[0], fontc[rots[player]]);
	}
	
	// STAGE�̕\��(FLASH)
	if((gameMode[player] == 15) && (statc[player * 10] >= ready_start[player])) {
		printFont(boffset[player] + 1, 9, "STAGE", fontc[rots[player]]);
		sprintf(string[0], "%2d", stage[player] + 1);
		printFont(boffset[player] + 7, 9, string[0], fontc[rots[player]]);
	}
	
	// �~�b�V�������[�h�p
	if((gameMode[player] == 8) && (statc[player * 10] == 0) && (c_mission == start_mission) && (!c_norm[0])) {
		// �����ݒ�
		missionSetStatus();
		
		// �w�i��ݒ�
		if(mission_bg[c_mission]) backno = mission_bg[c_mission] - 1;
		
		// �^�[�Q�b�g�̃X�e�[�W�ǂݍ���
		if(mission_type[c_mission] == 6) loadTargetStage();
		
		// �s���`���ǂ����`�F�b�N
		pinchCheck(player);
	}
	
	// VERSUS���[�h�̐������Ԃ�ݒ�
	if((gameMode[player] == 4) && (vs_timelimit > 0) && (statc[player * 10] == 0)) {
		ltime[player] = vs_timelimit;
	}
	// VERSUS�̂���オ��^�C�v�ݒ�
	if((gameMode[player] == 4) && (statc[player * 10] == 0)) {
		uplinetype[player] = 3;
	}
	
	// �VIRS
	if(ace_irs) {
		if(statc[player * 10]) {
			doNewIRS(player, 0);
		} else {
			onRecord[player] = 1;
			doNewIRS(player, 0);
		}
	}
	
	// �u���b�N�̏o���ʒu��ݒ�
	if(statc[player * 10] == 0) {
		setBlockSpawnPosition(player);
	}
	
	// �X�^�[�g����nextc���L�^
	if((statc[player * 10] == 0) && (ready_count[player] == 1)) {
		start_nextc[player] = nextc[player];
	}
	
	// HYPER����s�ړ�
	if(fastlrmove == 3) {
		if(statc[player * 10]) {
			HyperLRMove(player);
		} else {
			onRecord[player] = 1;
			HyperLRMove(player);
		}
	}
	
	// �ŏ��̃t���[���̉����߂��L�^�^�Č�
	if((ready_count[player] == 1) && (onRecord[player]) && (statc[player * 10] == 0)) {
		if(playback) {
			mp [player] = mps[player * 2    ];
			mpc[player] = mps[player * 2 + 1];
		} else {
			mps[player * 2    ] = mp [player];
			mps[player * 2 + 1] = mpc[player];
		}
	}
	
	if( (statc[player * 10] >= ready_start[player]) && (statc[player * 10] < ready_end[player]) ) {
		// READY
		ExBltRect(49, foffset[player] - 2, 91, 200,  0, 100, 50);
	} else if( (statc[player * 10] >= go_start[player]) && (statc[player * 10] < go_end[player]) ) {
		// GO
		ExBltRect(49, foffset[player] - 2, 92, 200, 50, 100, 50);
	}
	
	if(statc[player * 10] == ready_start[player]) {
		if(!IsPlayWave(15)) PlaySE(15);
	}
	if(statc[player * 10] == go_start[player]) {
		if(!IsPlayWave(16)) PlaySE(16);
	}
	
	// �Q�[���X�^�[�g
	if( statc[player * 10] >= go_end[player] ) {
		stat[player] = 4;					// �u���b�N�����J�n��
		statc[player * 10 + 1] = 1;			// 
		statc[player * 10] = 0;				// ���Ƃ����Â�
		
		// �X�^�[�g���̉����߂��L�^�^�Č�
		if((ready_count[player] == 1) && (!onRecord[player])) {
			if(playback) {
				mp [player] = mps[player * 2    ];
				mpc[player] = mps[player * 2 + 1];
			} else {
				mps[player * 2    ] = mp [player];
				mps[player * 2 + 1] = mpc[player];
			}
		}
		
		// �X�^�[�g���̃��[����ݒ�
		if(ready_count[player] == 1) {
			start_rots[player] = rots[player];
		}
		
		timeOn[player] = 1;					// �^�C�}�[�J�n
		onRecord[player] = 1;				// ���v���C�L�^�J�n
		
		// COLOR #LITE16
		if(color_flag[player]) iscolor[player] = 1;
		
		// BGM�Đ�
		if(!onRecord[1 - player]) {
			if( ((bgm == 4) && !IsPlayMIDI()) || ((bgm >= 2) && (bgm != 4) && !IsPlayWave(60 + bgmlv)) )
				changeBGM();
		}
	} else if( ((nextskip == 0) && (gameMode[player] == 6)) || 
	           ((nextskip == 1) && ((gameMode[player] == 6) || (gameMode[player] == 15))) || 
	           (nextskip == 2) )
	{
		// ���v���C�L�^�J�n
		onRecord[player] = 1;
		
		// �c������@�\ #LITE13
		if( !pass_flg[player] && getPressState(player, 7) ) {
			hold_used[player]++;
			
			if((hold_sound == 1) || (hold_sound == 3)) PlaySE(9);	// hold.wav
			
			hold[player] = next[player];
			dhold[player] = 0;
			dhold2[player] = 0;
			
			// HOLD�u���b�N�̐F��ݒ�
			if(!rule_color[rots[player]])
				c_hblk[player] = ccol[next[player]];
			else
				c_hblk[player] = wcol[next[player]];
			
			// NEXT��i�߂�
			nextc[player] = (nextc[player] + 1) % nextb_max[player];
			next[player] = getNextBlock(player, nextc[player]);
			
			// ��]��Ԃ�o���ʒu�����Z�b�g
			rt_nblk[player * 6] = 0;
			setBlockSpawnPosition(player);
			
			// NEXT�u���b�N�̐F��ݒ�
			setNextBlockColors(player, 0);
		}
		
		pass_flg[player] = getPressState(player, 7);
	}
	
	// �����ꐧ��������
	down_flag[player] = 0;
	up_flag[player] = 0;
	
	// �J�E���^����
	statc[player * 10]++;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.04 - �u���b�N�����J�n
//������������������������������������������������������������������������������
void statBlock(int player) {
	int i;
	
	// �A�C�e������
	if(goItemStat(player, stat[player])) return;
	
	// TGMLV�㏸
	if( (!ending[player]) && (!isAceModeOrMission(player)) && (!isMarathonMode(player)) && 
	    (gameMode[player] != 9) && (gameMode[player] != 17) )
	{
		if((gameMode[player] == 0) || (gameMode[player] == 3) || (gameMode[player] == 16))
			i = 99;
		else if(gameMode[player] == 13)
			i = 99 * (tc[player] >= 200);
		else
			i = 99 - ((tc[player] > 900) && (timeattack[player]));
		
		if((tc[player] % 100 != i) || (i == 0)) {
			tc[player]++;
			if((tc[player] % 100 == i) && (i != 0)) PlaySE(28);
		}
		
		// TOMOYO���[�h�ł�998�ŃX�g�b�v
		if((gameMode[player] == 6) && (tc[player] > 998)) tc[player] = 998;
		
		if( (bgm >= 2) && (fadelv == 0) ) checkFadeout(player);	// BGM�t�F�[�h�A�E�g�`�F�b�N
	}

	// TOMOYO����オ��
	if( ((gameMode[player] == 6) || ((gameMode[player] == 8) && (mission_type[c_mission] == 6))) && 
	    (tomoyo_rise[player] != 0) )
	{
		tomoyo_rise_t[player]++;
		
		if(tomoyo_rise_t[player] % tomoyo_rise[player] == 0) {
			upLines[player] = 1;
		}
	}

	// ACE���[�h�̃^�C�}�[�ĊJ
	if(isAceMode(player) && !ending[player])
		timeOn[player] = 1;

	// �A�C�e����ݒ�
	item[player] = item_nblk[0 + player * 6];

	// �A�C�e���֘A
	if(item_mode[player]) setItemStatus(player);

	// �t�B�[�o�[���͖_�����o��
	if(isfever[player]) {
		next[player] = 0;
		
		if(rule_color[rots[player]])
			c_nblk[0 + player * 6] = wcol[0];
		else
			c_nblk[0 + player * 6] = ccol[0];
	}

	// CPU�̑���
	if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
		cpu_setCtrl(player);
	}

	// �i�r�Q�[�V�����V�X�e�����ǂ�
	if( (tc[player] < limit_navigation) && 
	    ( (enable_navigation == 2) || ((enable_navigation == 1) && (gameMode[player] == 0)) ) && 
	    (!IsBig[player]) && (!cpu_flag[player]) )
	{
		cpu_setBestSpot(player, next[player], 0, getNextBlock(player, nextc[player] + 1), 1);
		navigation_time[player] = 0;
	}

	padRepeat(player);

	blk[player] = next[player];

	nextc[player] = (nextc[player] + 1) % nextb_max[player];
	next[player] = getNextBlock(player, nextc[player]);
	
	// blockse��炷
	if( (hnext[player] > 0) && (!ishidenext[player]) && (!heboGB[player]) ) {
		if(isfakenext[player]) PlaySE(21 + Rand(7));
		else PlaySE(21 + next[player]);
	}
	
	// �u���b�N�̐F��ݒ�
	c_cblk[player] = c_nblk[0 + player * 6];
	c_cblk_r[player] = c_nblk[0 + player * 6];
	
	o_cblk[player] = o_nblk[0 + player * 6];
	
	// ������ݒ�
	rt[player] = rt_nblk[player * 6];
	
	// ���ʒu��ݒ�
	bx[player] = n_bx[player];
	
	// NEXT�u���b�N�̐F��ݒ�
	setNextBlockColors(player, 0);
	
	// �o���ʒu�ݒ�
	setBlockSpawnPosition(player);
	
	bs[player] = 0;
	bk[player] = 0;
	bk_D[player] = 0;
	
	dhold[player] = 0;
	dhold2[player] = 0;
	kickc[player] = 0;
	kickc2[player] = 0;
	kickc3[player] = 0;
	
	// �X�R�A�ϐ�������
	sdrop[player] = 0;
	qdrop[player] = 0;
	
	// ��HIDDEN����
	hiddenProc(player);
	
	// �Ō�̑���������� #LITE23
	last_command[player] = 0;
	
	// T-SPIN�t���O������
	IsTspin[player] = 0;
	
	// �n�[�h�h���b�v�g�p�t���O������
	harddrop[player] = 0;
	softdrop[player] = 0;
	
	// T-SPIN�����t���O������
	tspin_kick[player] = 0;
	
	// �t�B�[���h�ʒu������
	ofs_x[player] = 0;
	ofs_y[player] = 0;
	
	// MASTER-HARD��1�Ȗڂ�BGM���t�F�[�h�A�E�g�����ꍇ��REGRET���Ă����x�𗎂Ƃ��Ȃ�
	if((gradetype[player] == 1) && (tc[player] >= tc_20g[player]) && (tr2[player] < 51)) {
		regretcancel[player] = 1;
	}
	
	// ���𗣂��Ă���ꍇ�A�����ꐧ������
	if( !getPressState(player, 1) ) down_flag[player] = 0;
	if( !getPressState(player, 0) ) up_flag[player] = 0;
	
	if((spawn_y_type) && (!heboGB[player]) && (rule_are[rots[player]] != 0)) {
		if( ((sp[player] < 60) && (!speedtype[player])) || ((sp[player] > 1) && (speedtype[player])) )
			ndelay[player] = 0;
	}
	
	stat[player] = 5;
	statc[player * 10 + 2] = 0;
	statc[player * 10 + 3] = 0;
	
	// �������̐�s�ړ�
	statc[player * 10 + 4] = (fastlrmove != 1);
	
	// IHS
	doHold(player, 1);
	
	// IRS
	if(!ace_irs) doClassicIRS(player);
	
	// �Q�[���I�[�o�[�`�F�b�N
	if(checkGameOver(player)) return;
	
	// �u���b�N�ړ�����
	if(repversw >= 5) statMove(player);
}

// (I.R.S.) Initial Rotation System  (c)1998 AR��KA(^^;
void doClassicIRS(int player) {
	int bak;
	
	if(isRotateLock[player] || heboGB[player] || !enable_irs) return;
	
	if( getPressState(player, 4) || getPressState(player, 5) || getPressState(player, 6) ) {
		PlaySE(0);
		
		// ��]������������߂�
		if( !getPressState(player, 5) ) {
			// A�܂���C
			if(isWRule(player) && w_reverse)
				bak = 1;	// WORLD �E��]
			else
				bak = 3;	// CLASSIC ����]
		} else {
			// B
			if(isWRule(player) && w_reverse)
				bak = 3;	// WORLD ����]
			else
				bak = 1;	// CLASSIC �E��]
		}
		
		// 180�x��]
		if( ((rot180 == 1) || ((rot180 == 2) && (rule_180rot[rots[player]] != 0))) && getPressState(player, 6) ) {
			bak = 2;
		}
		
		// ��]�ł��邩�`�F�b�N
		if( judgeBlock(player, bx[player], by[player], blk[player], bak) == 0 ) {
			// ��]�\
			if(rotate_sound) PlaySE(4);
			rt[player] = bak;
		} else if(!blk[player] && !r_irs) {
			// �ԐF�u���b�N�ŉ�]���Ȃ������Ƃ���1�}�X��ɂ��点�邩����
			if( judgeBlock(player, bx[player], by[player] - 1, blk[player], bak) == 0 ) {
				if(rotate_sound) PlaySE(4);
				rt[player] = bak;
				by[player]--;
			}
		} else {
			// ���Ȃ�����
			if( !IsPlayWave(35) ) PlaySE(35);
		}
	}
}

// �VIRS
// type��1�ɂ���Ɖ������ςȂ��ł���]
void doNewIRS(int player, int type) {
	int bak, bak2, result;
	
	if(isRotateLock[player] || heboGB[player] || !enable_irs) return;
	
	if( ((!type) && (getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6))) || 
	    ((type) && (getPressState(player, 4) || getPressState(player, 5) || getPressState(player, 6))) )
	{
		// ��]������������߂�
		if( (!type && !getPushState(player, 5)) || (type && !getPressState(player, 5)) ) {
			// A�܂���C
			if(isWRule(player) && w_reverse)
				bak = 1;	// WORLD �E��]
			else
				bak = -1;	// CLASSIC ����]
		} else {
			// B
			if(isWRule(player) && w_reverse)
				bak = -1;	// WORLD ����]
			else
				bak = 1;	// CLASSIC �E��]
		}
		
		// 180�x��]
		if( ((rot180 == 1) || ((rot180 == 2) && (rule_180rot[rots[player]] != 0))) && 
		    ((!type && getPushState(player, 6)) || (type && getPressState(player, 6))) )
		{
			bak = 2;
		}
		
		bak2 = rt_nblk[player * 6] + bak;
		if(bak2 < 0) bak2 = bak2 + 4;
		if(bak2 > 3) bak2 = bak2 - 4;
		
		if(judgeBlock(player, n_bx[player], -2, next[player], bak2) == 0) {
			// �ǂɓ�����Ȃ��ꍇ
			result = 1;
		} else if(judgeBlock(player, n_bx[player] + 1, -2, next[player], bak2) == 0) {
			// �E1�}�X�ǏR��
			n_bx[player] = n_bx[player] + 1;
			result = 1;
		} else if(judgeBlock(player, n_bx[player] + 2, -2, next[player], bak2) == 0) {
			// �E2�}�X�ǏR��
			n_bx[player] = n_bx[player] + 2;
			result = 1;
		} else if(judgeBlock(player, n_bx[player] - 1, -2, next[player], bak2) == 0) {
			// ��1�}�X�ǏR��
			n_bx[player] = n_bx[player] - 1;
			result = 1;
		} else if(judgeBlock(player, n_bx[player] - 2, -2, next[player], bak2) == 0) {
			// ��2�}�X�ǏR��
			n_bx[player] = n_bx[player] - 2;
			result = 1;
		} else {
			// ���s
			result = 0;
		}
		
		// ��]������
		if(result) {
			PlaySE(0);
			rt_nblk[player * 6] = bak2;
		} else {
			PlaySE(35);
		}
	}
}

// HYPER����s�ړ�
void HyperLRMove(int player) {
	int move, tmp;
	
	// �L�[���͂��擾���Ĉړ�������ݒ�
	move = getPressState(player, 3) - getPressState(player, 2);
	
	// 2�}�X�P�ʂ�BIG�ł͈ړ��ʂ�2�{�ɂ���
	if(IsBig[player] && BigMove[player]) move = move * 2;
	
	// �����ߐݒ�
	if(rule_max_waitt[rots[player]] < waitt[player]) tmp = rule_max_waitt[rots[player]];
	else tmp = waitt[player];
	
	if( (move != 0) && ((mpc[player] == 1) || (mpc[player] >= tmp)) )
		if(judgeBlock(player, n_bx[player] + move, -2, next[player], rt_nblk[player * 6]) == 0) {
			// �u���b�N���ړ�������
			n_bx[player] = n_bx[player] + move;
			if(move_sound) PlaySE(5);
		} else {
			// �ړ��ł��Ȃ�����
			if(!IsPlayWave(34)) PlaySE(34);
		}
}

// �Q�[���I�[�o�[�ɂȂ邩�`�F�b�N
int checkGameOver(int player) {
	if(judgeBlock(player, bx[player], by[player], blk[player], rt[player]) != 0) {
		// �u���b�N���߂荞��ł�����Q�[���I�[�o�[
		setBlock(player, bx[player], by[player], blk[player], rt[player]);
		setGameOver(player);
		return 1;
	} else if(judgeBlock(player, bx[player], by[player] + 1, blk[player], rt[player]) != 0) {
		// 1�}�X���Ƀu���b�N������ꍇ�͐ڒn����炷
		PlaySE(1);
	}
	
	return 0;
}

// �Q�[���I�[�o�[�ɂ�����
void setGameOver(int player) {
	int i;
	
	// �������[���ł͍s��Ȃ�����
	if(!fastroll[player]) {
		if(!onRecord[1 - player]) StopAllBGM();	// ���y��~
		onRecord[player] = 0;		// ���v���C�L�^��~
		ending_timeOn[player] = 0;	// �G���f�B���O�^�C�}�[��~
	}
	
	isxray[player] = 0;		// X-RAY���~�߂�
	iscolor[player] = 0;	// COLOR���~�߂�
	isblind[player] = 0;	// BLIND���~�߂�
	isdark[player] = 0;		// DARK���~�߂�
	
	ofs_x[player] = 0;
	ofs_y[player] = 0;
	
	timeOn[player] = 0;			// �^�C�}�[��~
	stat[player] = 7;			// �Q�[���I�[�o�[������
	
	// �x�������~�߂�
	pinch[player] = 0;
	StopWave(38);
	
	// �J�E���^������
	for(i=0; i<10; i++) statc[player * 10 + i] = 0;
	
	// �������[�����Ɏ��񂾂�i��+1
	if((gmflag_r[player]) && (gradetype[player] == 0)) {
		if(grade[player] < 31) {
			grade[player]++;
			gflash[player] = 120;
			gup_down[player] = 1;
			PlaySE(31);
		}
	}
	
	// HARD�̂Ƃ��̎��S�i�ʏ㏸
	if((gradetype[player] == 1) && (tc[player] - ((tc[player] / 100) * 100) > 50)) {
		grade[player] = grade[player] + gup3rank[player];
		if(grade[player] > 31) grade[player] = 31;
	}
	
	// DUAL�M�~�b�N����
	endTomoyoDualGimmick(0);
	
	// ROT. RELAY�p
	if((gameMode[player] == 17) && (timeattack[player] >= 2)) {
		rots[player] = start_rots[player];
		setNextBlockColors(player, 1);
	}
}

// ���i�ʔ���
int checkSecretGrade(int player) {
	int i, j, uhole, umode, count;
	
	uhole = 0;		// ���̈ʒu���������i�ŏ��͍��[�j
	umode = 0;		// 1���ƉE���獶�֌����ړ�
	count = -1;		// ���݂̗��i�ʂ�������
	
	// 9�`S9�܂ł̔���
	for(i = 21; i > 3; i--) {
		for(j = 0; j < 10; j++) {
			// ���܂��Ă���ׂ��ꏊ�����܂��ĂȂ��Ȃ�I��
			if((fld[j + i * 10 + player * 220] == 0) && (j != uhole)) return count;
		}
		
		// ���̌��̈ʒu�����߂�
		if(!umode) {
			uhole++;
			
			if(uhole > 9) {
				uhole = 8;
				umode = 1;
			}
		} else {
			uhole--;
		}
		
		// ���i�ʏ㏸
		count++;
	}
	
	// GM����
	// ����(X:0 Y:1)�����܂��Ă�����GM
	if(fld[0 + 1 * 10 + player * 220] != 0) {
		count++;
	}
	
	return count;
}

// �u���b�N�o���ʒu��ݒ�
void setBlockSpawnPosition(int player) {
	int move;
	
	if((spawn_y_type) && (!heboGB[player])) {
		// �g�O
		if(IsBig[player]) {
			// BIG
			n_bx[player] = 2;
			
			if(isWRule(player)) {
				by[player] = (blk[player] == 0) * -1;
			} else if(isDRule(player)) {
				by[player] = -1 - (blk[player] != 0) - (2 * (blk[player] == 0));
			} else {
				by[player] = -1 - (blk[player] != 0);
			}
		} else {
			// �ʏ�
			n_bx[player] = 3;
			
			if(isWRule(player)) {
				by[player] = 0;
			} else if(isDRule(player)) {
				by[player] = -1;
			} else {
				by[player] = (blk[player] != 0) * -1;
			}
		}
	} else {
		// �g��
		if(IsBig[player]) {
			// BIG
			n_bx[player] = 2;
			
			if(isWRule(player)) {
				by[player] = (blk[player] != 0) * 2;
			} else if(isDRule(player)) {
				by[player] = (blk[player] == 0) * -2;
			} else {
				by[player] = 0;
			}
		} else {
			// �ʏ�
			n_bx[player] = 3;
			
			if(isWRule(player)) {
				by[player] = 1 + (blk[player] != 0);
			} else if(isDRule(player)) {
				by[player] = 1 * (blk[player] != 0);
			} else {
				by[player] = 1;
			}
		}
	}
	
	// SUPER����s�ړ�
	if(fastlrmove == 2) {
		// �L�[���͂��擾���Ĉړ�������ݒ�
		move = getPressState(player, 3) - getPressState(player, 2);
		
		// 2�}�X�P�ʂ�BIG�ł͈ړ��ʂ�2�{�ɂ���
		if(IsBig[player] && BigMove[player]) move = move * 2;
		
		// �ړ�
		if(judgeBlock(player, n_bx[player] + move, by[player], blk[player], rt[player]) == 0) {
			n_bx[player] = n_bx[player] + move;
		}
	}
}

// HOLD���鏈�� #LITE07
void doHold(int player, int ihs) {
	int tmp, first;
	
	if(dhold[player] || heboGB[player] || disable_hold || isholdlock[player]) return;
	
	if(getPressState(player, 7)) {
		// hold.wav
		if( ((hold_sound == 1) && (ihs)) || ((hold_sound == 2) && (!ihs)) || (hold_sound == 3) )
			PlaySE(9);
		
		first = (hold[player] == -1);
		
		if(first) {
			// ����
			hold[player] = blk[player];
			blk[player] = next[player];
			nextc[player] = (nextc[player] + 1) % nextb_max[player];
			next[player] = getNextBlock(player, nextc[player]);
			
			// �u���b�N�̐F��ݒ�
			c_hblk[player] = c_cblk_r[player];
			
			c_cblk[player] = c_nblk[0 + player * 6];
			c_cblk_r[player] = c_nblk[0 + player * 6];
			
			o_hblk[player] = o_cblk[player];
			o_cblk[player] = o_nblk[0 + player * 6];
			
			// �A�C�e����ݒ�
			
			// ���ׂ�OFF
			if(enable_item_hold == 0) {
				item_hblk[player] = 0;
				item[player] = 0;
			}
			// ���ׂ�ON
			if(enable_item_hold == 1) {
				item_hblk[player] = item[player];
				item[player] = item_nblk[0 + player * 6];
			}
			// IHS��OFF�A����ȊOON
			if(enable_item_hold == 2) {
				if(ihs) {
					item_hblk[player] = 0;
					item[player] = 0;
				} else {
					item_hblk[player] = item[player];
					item[player] = item_nblk[0 + player * 6];
				}
			}
			// IHS��ON�A����ȊOOFF
			if(enable_item_hold == 3) {
				if(ihs) {
					item_hblk[player] = item[player];
					item[player] = item_nblk[0 + player * 6];
				} else {
					item_hblk[player] = 0;
					item[player] = 0;
				}
			}
			
			item_coming[player] = 0;
			
			if(ace_irs >= 2) tmp = rt[player];
			
			// NEXT�u���b�N�̐F��ݒ�
			setNextBlockColors(player, 0);
			
			if(ace_irs >= 2) rt[player] = tmp;
			scanItem(player);
		} else {
			// 2��ڈȍ~
			tmp = blk[player];
			blk[player] = hold[player];
			hold[player] = tmp;
			
			// �u���b�N�̐F��ݒ�
			tmp = c_cblk_r[player];
			
			c_cblk[player] = c_hblk[player];
			c_cblk_r[player] = c_hblk[player];
			c_hblk[player] = tmp;
			
			tmp = o_hblk[player];
			o_hblk[player] = o_cblk[player];
			o_cblk[player] = tmp;
			
			// �A�C�e����ݒ�
			
			// ���ׂ�OFF
			if(enable_item_hold == 0) {
				item[player] = 0;
				item_hblk[player] = 0;
			}
			// ���ׂ�ON
			if(enable_item_hold == 1) {
				tmp = item_hblk[player];
				item_hblk[player] = item[player];
				item[player] = tmp;
			}
			// IHS��OFF�A����ȊOON
			if(enable_item_hold == 2) {
				if(ihs) {
					item[player] = 0;
					item_hblk[player] = 0;
				} else {
					tmp = item_hblk[player];
					item_hblk[player] = item[player];
					item[player] = tmp;
				}
			}
			// IHS��ON�A����ȊOOFF
			if(enable_item_hold == 3) {
				if(ihs) {
					tmp = item_hblk[player];
					item_hblk[player] = item[player];
					item[player] = tmp;
				} else {
					item[player] = 0;
					item_hblk[player] = 0;
				}
			}
			
			scanItem(player);
		}
		
		dhold[player] = 1;
		dhold2[player] = 1;
		hold_used[player]++;
		
		kickc[player] = 0;
		kickc2[player] = 0;
		kickc3[player] = 0;
		
		// �o���ʒu�ݒ�
		setBlockSpawnPosition(player);
		bx[player] = n_bx[player];
		
		// �u���b�N�̌��������Z�b�g
		if(ace_irs < 2) rt[player] = 0;
		
		bs[player] = 0;
		bk[player] = 0;
		bk_D[player] = 0;
		
		// CPU�̑���
		if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
			cpu_setBestSpot(player, blk[player], 0, next[player], 0);
			cpu_setCtrl(player);
		}
		
		// �i�r�Q�[�V�����V�X�e�����ǂ�
		if( (tc[player] < limit_navigation) && 
		    ( (enable_navigation == 2) || ((enable_navigation == 1) && (gameMode[player] == 0)) ) && 
		    (!IsBig[player]) && (!cpu_flag[player]) )
		{
			cpu_setBestSpot(player, blk[player], 0, next[player], 1);
			navigation_time[player] = 0;
		}
		
		// IHS�łȂ��ꍇ
		if(!ihs) {
			// IRS
			if(ace_irs != 1) doClassicIRS(player);
			
			// blockse��炷
			if( (hnext[player] > 0) && (!ishidenext[player]) && (!heboGB[player]) ) {
				if(isfakenext[player]) PlaySE(21 + Rand(7));
				else PlaySE(21 + next[player]);
			}
			
			// �������̐�s�ړ��𖳌��ɂ���
			statc[player * 10 + 4] = (fastlrmove != 1);
		}
		
		// �u���b�N���߂荞��ł�����Q�[���I�[�o�[
		checkGameOver(player);
	}
}

// T-SPIN�����郂�[�h���ǂ�������
int isTSpinEnableMode(int player) {
	int result;
	result = isNormalOrBeginnerMode(player);
	result = result || isMarathonMode(player);
	result = result || (gameMode[player] == 17);
	result = result || ((gameMode[player] == 8) && ((mission_type[c_mission] == 16) || (mission_type[c_mission] == 37)));
	return result;
}

// 3-CORNER�^�C�v��T-SPIN����
int isTSpin3Corner(int player) {
	int i, count, tx[4], ty[4];
	int tmp_x, tmp_y;
	
	if((tspin_type != 3) && (tspin_type != 4)) return 0;
	if((tspin_type == 4) && (tspin_kick[player] > 0)) return 0;
	
	// ����p���΍��W��ݒ�
	if(IsBig[player]) {
		tx[0] = 1;
		ty[0] = 1;
		tx[1] = 4;
		ty[1] = 1;
		tx[2] = 1;
		ty[2] = 4;
		tx[3] = 4;
		ty[3] = 4;
	} else {
		tx[0] = 0;
		ty[0] = 0;
		tx[1] = 2;
		ty[1] = 0;
		tx[2] = 0;
		ty[2] = 2;
		tx[3] = 2;
		ty[3] = 2;
	}
	
	// ���菈��
	count = 0;
	
	for(i = 0; i < 4; i++) {
		tmp_x = bx[player] + tx[i];
		tmp_y = by[player] + ty[i];
		
		// ARS��T��������̏ꍇ
		// ���@��
		// �@��
		// ������
		// ����Ȕ��肾�����̂��C��
		if((isWRule(player) == 0) && (rt[player] == 2))
			tmp_y = tmp_y + 1 + (IsBig[player]);
		
		if(tmp_y >= 0) {
			if( (tmp_x < 0) || (tmp_x > 9) || (tmp_y > 21) || (fld[tmp_x + tmp_y * 10 + player * 220]) ) {
				count++;
				
				if(count >= 3) return 1;
			}
		}
	}
	
	return 0;
}

// IMMOBILE�^�C�v��T-SPIN����
int isTSpinImmobile(int player) {
	if(tspin_type != 2) return 0;
	
	if( (judgeBlock(player, bx[player] - 1, by[player], blk[player], rt[player]) != 0) &&
		(judgeBlock(player, bx[player] + 1, by[player], blk[player], rt[player]) != 0) &&
		(judgeBlock(player, bx[player], by[player] - 1, blk[player], rt[player]) != 0) )
	{
		return 1;
	}
	
	return 0;
}

// �u���b�N��������
// �߂�l�͏�������郉�C���� #LITE07
int blockEraseJudge(int player) {
	int		i, j, sr;
	int		result;
	int		by2, k;
	int		data[2];
	
	if(gameMode[player] == 4) {
		// �ΐ�ł̓u���b�N����������Ԃ̂܂܎c��o�O������̂ŁA�S�����ׂ�
		result = blockAllEraseJudge(player);
	} else {
		// �ΐ�ȊO�ł͒u�������������ׂ�
		result = 0;
		
		for(i = 0; i < 4; i++) {
			// �u�����u���b�N��Y���W���擾
			getBlockData(player, 0, 0, blk[player], rt[player], i, &data);
			by2 = by[player] + (data[1] * (IsBig[player] + 1));
			
			// ��������iBIG�ł�2���C�����ׂ�j
			for(k = 0; k < 1 + IsBig[player]; k++) {
				if((by2 + k >= 0) && (!erase[(by2 + k) + player * 22])) {
					sr = 1;
					
					for(j = 0 ; j < 10; j++) {
						if(!fld[j + (by2 + k) * 10 + player * 220]) {
							sr = 0;
							break;
						}
					}
					
					if(sr) {
						erase[(by2 + k) + player * 22] = 1;
						result++;
					}
				}
			}
		}
	}
	
	// �ΐ탂�[�h�̂���オ�菈��
	if((result >= 2) && (uplinetype[player] == 3) && (upLines[1 - player] <= 21) && (r_enable[player]) && (!ismiss[player])) {
		// �ꎞ�I�ɍ��u�����u���b�N�������i�������Ȃ��Ƒ�������Ԃł���オ��j
		removeBlock(player, bx[player], by[player], blk[player], rt[player]);
		
		// ���������C���̌`����R�s�[
		for(k = 0; k <= isdouble[1 - player]; k++) {
			for(i = 0; i < 22; i++) {
				if(erase[(21 - i) + player * 22]) {
					for(j = 0; j < 10; j++) {
						fldu[j + upLines[1 - player] * 10 + (1 - player) * 220] = fld[j + (21 - i) * 10 + player * 220];
					}
					
					upLines[1 - player]++;
					if(upLines[1 - player] > 21) break;
				}
			}
		}
		
		// �u���b�N��������x�ݒu����
		setBlock(player, bx[player], by[player], blk[player], rt[player]);
	}
	
	return result;
}

// FREE FALL�p�u���b�N��������i�S�Ă̗�𒲂ׂ�j
int blockAllEraseJudge(int player) {
	int		i, j, sr;
	int		result;
	
	result = 0;
	
	for(i = 0; i < 22; i++) {
		sr = 1;
		
		for(j = 0; j < 10; j++)
			if(!fld[j + i * 10 + player * 220]) {
				sr = 0;
				break;
			}
		
		erase[i + player * 22] = sr;
		result = result + sr;
	}
	
	return result;
}

// �u���b�N�㏸����?
void UpLineBlockJudge(int player) {
	// ����オ�胉�C�����c���Ă���Ƃ��͂���グ��
	if(upLines[player] > 0) {
		PlaySE(20);
		UpLineBlock(player);
	}
}

// �t�B�[���h����ɂ��炷
void UpLinePush(int player) {
	int		i, j;
	
	for(i = 1 + (!spawn_y_type); i < 22; i++) {
		for(j = 0; j < 10; j++) {
			fld[j + (i - 1) * 10 + player * 220] = fld[j + i * 10 + player * 220];
			fldt[j + (i - 1) * 10 + player * 220] = fldt[j + i * 10 + player * 220];
			fldi[j + (i - 1) * 10 + player * 220] = fldi[j + i * 10 + player * 220];
			fldo[j + (i - 1) * 10 + player * 220] = fldo[j + i * 10 + player * 220];
			flds[j + (i - 1) * 10 + player * 220] = flds[j + i * 10 + player * 220];
		}
		
		erase[(i - 1) + player * 22] = erase[i + player * 22];
	}
}

// �u���b�N�㏸
void UpLineBlock(int player) {
	int		i, j, newhole;
	
	// �t�B�[���h����ɂ��炷
	UpLinePush(player);
	
	if(uplinetype[player] == 0) {
		// SHIRASE��
		// ���C�����R�s�[����
		for(j = 0; j < 10; j++) {
			fld[j + 21 * 10 + player * 220] = (fld[j + 20 * 10 + player * 220] != 0);
			fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
		}
	} else if(uplinetype[player] == 1) {
		// TGM+��
		
		// ����オ��t�B�[���h�̓ǂݍ���
		fld[0 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] / 10000 % 10;
		fld[1 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] / 1000 % 10;
		fld[2 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] / 100 % 10;
		fld[3 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] / 10 % 10;
		fld[4 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2] % 10;
		fld[5 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] / 10000 % 10;
		fld[6 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] / 1000 % 10;
		fld[7 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] / 100 % 10;
		fld[8 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] / 10 % 10;
		fld[9 + 10 * 21 + player * 220] = upFld[upLineNo[player] * 2 + 1] % 10;
		
		// �u���b�N��������悤�ɂ���
		for(i = 0; i < 10; i++) {
			fldt[i + 10 * 21 + player * 220] = (fld[i + 10 * 21 + player * 220] != 0) * -1;
		}
		
		// ���̃p�^�[����
		if(upLineNo[player] + 1 < upLineNoMax)
			upLineNo[player]++;
		else
			upLineNo[player] = 0;
	} else if(uplinetype[player] == 2) {
		// TOMOYO����オ��
		// ����オ��t�B�[���h�̓ǂݍ���
		for(i = 0; i < 10; i++) {
			fld[i + 10 * 21 + player * 220] = tomoyo_rise_fld[i + (upLineNo[player] * 10) + player * 200];
			fldt[i + 10 * 21 + player * 220] = (fld[i + 10 * 21 + player * 220] != 0) * -1;
		}
		
		upLineNo[player]++;
		
		// ����オ��I������
		if(upLineNo[player] > 20) {
			tomoyo_rise[player] = 0;
		} else {
			j = 0;
			
			for(i = 0; i < 10; i++) {
				if(tomoyo_rise_fld[i + (upLineNo[player] * 10) + player * 200] != 0) break;
				j++;
			}
			
			if(j == 10) tomoyo_rise[player] = 0;
		}
	} else if(uplinetype[player] == 3) {
		// �ΐ�p�i�V���j
		// ����オ��t�B�[���h�̈�ԏ�̃��C�����R�s�[
		for(j = 0; j < 10; j++) {
			fld[j + 21 * 10 + player * 220] = fldu[j + 0 * 10 + player * 220];
			fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
		}
		
		// ����オ��t�B�[���h�����炷
		for(i = 1; i < 22; i++) {
			for(j = 0; j < 10; j++) {
				fldu[j + ( i - 1 ) * 10 + player * 220] = fldu[j + i * 10 + player * 220];
			}
		}
	} else if(uplinetype[player] == 4) {
		// �~�b�V��������オ��
		for(j = 0; j < 10; j++) {
			fld[j + 21 * 10 + player * 220] = (j != ghole[player]);
			fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
		}
		
		// 8���̊m���Ō��̈ʒu��ς���
		if(GiziRand(player, 10) > 2) {
			do {
				newhole = GiziRand(player, 10);
			} while(newhole == ghole[player]);
			ghole[player] = newhole;
		}
	} else if(uplinetype[player] == 5) {
		// �~�b�V�������Œ肹��オ��
		for(j = 0; j < 10; j++) {
			fld[j + 21 * 10 + player * 220] = (j != ghole[player]);
			fldt[j + 21 * 10 + player * 220] = (fld[j + 21 * 10 + player * 220] != 0) * -1;
		}
	}
	
	// �ŉ��i�̃A�C�e��������
	for(j = 0; j < 10; j++) {
		fldi[j + 21 * 10 + player * 220] = 0;
		fldo[j + 21 * 10 + player * 220] = 0;
	}
	
	erase[21 + player * 22] = 0;
	
	upLines[player]--;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.06 - ���ԉ҂� & ���x���A�b�v����
//������������������������������������������������������������������������������
void statErase(int player) {
	int i, j, allowskip;
	
	if(repversw <= 6) {
		if(statc[player * 10] == wait1[player]) statc[player * 10 + 1] = 0;
		else statc[player * 10 + 1] = 1;
	}
	
	// HOLD�g�p�\��
	dhold[player] = 0;
	
	// CPU�̑���
	if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
		if(!statc[player * 10 + 1]) cpu_setBestSpot(player, next[player], 0, getNextBlock(player, nextc[player] + 1), 0);
		
		cpu_setCtrl(player);
	}
	
	padRepeat(player);
	
	// ��HIDDEN����
	hiddenProc(player);
	
	// HARD�̂Ƃ��̒i�ʏ㏸
	if(gradetype[player] == 1) GradeUp3(player);
	
	// �VIRS
	if(ace_irs) doNewIRS(player, 0);
	
	// HYPER����s�ړ�
	if(fastlrmove == 3) HyperLRMove(player);
	
	// ���𗣂��Ă���ꍇ�A�����ꐧ������
	if( !getPressState(player, 1) ) down_flag[player] = 0;
	if( !getPressState(player, 0) ) up_flag[player] = 0;
	
	if(!statc[player * 10 + 1]) {
		// �ϋv�~�b�V�����N���A
		if((gameMode[0] == 8) && (timeOn[player]) && (mission_type[c_mission] == 23) && (ltime[0] <= 0))
			missionNormUp(0);
		
		// OOBAKA�~�b�V�����p
		if((gameMode[0] == 8) && (timeOn[player]) && (mission_type[c_mission] == 29))
			missionNormUp(0);
		
		// �~�b�V�����N���A���̃��C�������^����オ�蔭��
		if((gameMode[0] == 8) && (c_norm[0] >= m_norm[0]) && (mission_clear_flag == 1) && (!ending[0])) {
			mission_clear_flag = 2;
			j = mission_erase[c_mission];
			
			// �G���f�B���O�ɂȂ�ꍇ�̓��C�������������Ȃ�
			if(
			   (mission_end[c_mission] == 1) || 
			   ((mission_end[c_mission] >= 4) && (mission_end[c_mission] <= 9)) || 
			   (((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) && (!mission_extra))
			  )
			{
				j = 0;
			}
			
			if(j > 0) {
				if(mission_end[c_mission] == 3) {
					// EXTRA+
					stat[0] = 26;
					statc[0] = -wait1[0];
					statc[1] = 6;
					statc[2] = j;
					statc[3] = 0;
				} else {
					// ���ʂɏ���
					for(i = checkFieldTop(0); i < 22; i++) {
						erase[i] = 1;
						j--;
						if(j <= 0) break;
					}
					
					stat[0] = 21;
					statc[0] = 0;
					statc[1] = 6;
					statc[2] = 0;
				}
				return;
			} else if(j < -20) {
				// ����������オ�蔭��
				ghole[0] = GiziRand(0, 10);
				uplinetype[0] = 5;
				upLines[0] = abs(j + 20);
				statc[0] = 6;
				statc[1] = 1;
				statRiseLine(0);
				return;
			} else if(j < 0) {
				// ���o���o������オ�蔭��
				ghole[0] = GiziRand(0, 10);
				uplinetype[0] = 4;
				upLines[0] = abs(j);
				statc[0] = 6;
				statc[1] = 1;
				statRiseLine(0);
				return;
			}
		}
	}
	
	if( ((gameMode[player] == 6) || (gameMode[player] == 15)) && (!ending[player]) ) {
		// TOMOYO���[�h�܂���FLASH���[�h�Ńv���`�i�u���b�N��0�Ȃ�X�e�[�W�N���A
		if(rest_pblock[player] <= 0) {
			// �x�������~�߂�
			pinch[player] = 0;
			StopWave(38);
			StopWave(39);
			
			thunder_timer = 0;
			
			PlaySE(37);			// stageclear.wav
			clearnum[player]++;		// �N���A��+1
			timeOn[player] = 0;		// �^�C�}�[��~
			sclear[player] = 1;
			
			if(tomoyo_clear_erase) {
				stat[player] = 26;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 18;
				statc[player * 10 + 2] = 21;
				statc[player * 10 + 3] = 0;
			} else {
				stat[player] = 18;
				statc[player * 10] = 0;
			}
			return;
		}
		// ���~�b�g�^�C����0�ɂȂ��Ă�����Q�[���I�[�o�[
		else if((ltime[player] <= 0) && (tomoyo_ltime_over[player])) {
			PlaySE(39);
			ltime[player] = 0;
			setGameOver(player);
			return;
		}
		// �X�e�[�W�^�C����0�ɂȂ��Ă�����^�C���I�[�o�[
		else if((!tomoyo_no_stage_time[player]) && (stime[player] == 0) && (gameMode[player] == 6)) {
			timeOn[player] = 0;		// �^�C�}�[��~
			sclear[player] = 0;
			stat[player] = 18;
			statc[player * 10] = 0;
			return;
		}
	}
	
	// TOMOYO����オ��
	if( ((gameMode[player] == 6) || ((gameMode[player] == 8) && (mission_type[c_mission] == 6))) && 
	    (!statc[player * 10 + 1]) && (upLines[player]) )
		UpLineBlockJudge(player);
	
	// THUNDER����
	if((isthunder[player]) && (!statc[player * 10 + 1])) {
		PlaySE(47);	// thunder.wav
		thunder_timer = 30;
	}
	
	// ARE�X�L�b�v���\�����߂�iSKIP LOCKFLASH��SUPER����ARE�ɓ����čŏ���1�t���[���̏ꍇ�̓X�L�b�v�s�j
	if((skip_blocklockflash == 3) && (repversw >= 7)) {
		allowskip = statc[player * 10 + 1];
	} else if(skip_blocklockflash != 2) {
		allowskip = 1;
	} else {
		allowskip = statc[player * 10 + 1];
	}
	
	statc[player * 10]--;
	statc[player * 10 + 1] = 1;
	
	// ARE�X�L�b�v
	if((rule_are[rots[player]] == 2) && (harddrop[player]) && (allowskip)) {
		if( getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || getPushState(player, 3) || 
		    getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) )
		{
			statc[player * 10] = -1;
		}
	}
	if((rule_are[rots[player]] == 2) && (are_skipflag[player]) && (allowskip)) {
		if( getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || getPushState(player, 3) || 
		    getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) )
		{
			statc[player * 10] = -1;
			are_skipflag[player] = 0;
		}
	}
	
	if((statc[player * 10] < 0) || (!rule_are[rots[player]])) {
		// �X�e�[�^�X�J�E���^������
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		
		// �^�[�Q�b�g�~�b�V������1�X�e�[�W�N���A�����Ƃ��̏���
		if( (gameMode[0] == 8) && (player == 0) && 
		    (mission_type[c_mission] == 6) && (getPlatinumBlock(0) == 0) && (!ending[0]) )
		{
			StopWave(38);			// �^�C���x�������~�߂�
			stat[player] = 3;		// Ready
			
			if(c_norm[0] < m_norm[0]) {
				// ���̃X�e�[�W�ǂݍ���
				loadTargetStage();
				
				// �s���`���ǂ����`�F�b�N
				pinchCheck(player);
				
				return;
			}
		}
		
		// �~�b�V�����N���A
		if( (gameMode[0] == 8) && (player == 0) && (c_norm[0] >= m_norm[0]) && (!ending[0]) ) {
			if( (mission_end[c_mission] == 0) || (mission_end[c_mission] == 10) || 
			    ((mission_extra) && ((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3))) )
			{
				// �g�p����EX�X�e�[�W����������
				if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) mission_extra = 0;
				
				c_mission++;			// ���̃~�b�V������
				if(c_mission > 29) c_mission = 0;
				viewMissionText();		// �����\�����X�V
				
				// �w�i�؂�ւ�
				bgfadesw = 1;
				
				// �m���}������
				c_norm[0] = 0;
				
				// BGM�؂�ւ�
				if((bgmlv != mission_bgm[c_mission]) && (fadelv == 0)) fadelv = 1;
				
				// ���̃~�b�V�����̏����ݒ�
				missionSetStatus();
				
				// �^�[�Q�b�g�̃X�e�[�W�ǂݍ���
				if(mission_type[c_mission] == 6) {
					loadTargetStage();
				}
				
				// �s���`���ǂ����`�F�b�N
				pinchCheck(player);
				
				stat[player] = 25;		// �����҂�
				statc[player * 10 + 0] = wait1[player];
				statc[player * 10 + 1] = 3;
			} else {
				StopAllBGM();			// BGM��~
				if(!IsPlayWave(29)) PlaySE(29);
				
				if(mission_end[c_mission] == 1) {
					onRecord[player] = 0;	// ���v���C�L�^�I��
					ending[player] = 1;		// �G���f�B���O
				} else if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) {
					onRecord[player] = 0;	// ���v���C�L�^�I��
					ending[player] = 4;		// ���؂�
				} else if(mission_end[c_mission] == 4) {
					ending[player] = 1;		// �m�[�}�����[��
				} else if(mission_end[c_mission] == 5) {
					hidden[player] = 2;
					ending[player] = 1;		// �������[��
				} else if(mission_end[c_mission] == 6) {
					hidden[player] = 2;
					IsBig[player] = 1;
					ending[player] = 1;		// �����r�b�O���[��
					n_bx[player] = 2;
				} else if(mission_end[c_mission] == 7) {
					IsBig[player] = 1;
					ending[player] = 1;		// �r�b�O���[��
					n_bx[player] = 2;
				} else if(mission_end[c_mission] == 8) {
					hidden[player] = 1;
					ending[player] = 1;		// �������[��
				} else if(mission_end[c_mission] == 9) {
					hidden[player] = 1;
					IsBig[player] = 1;
					ending[player] = 1;		// �����r�b�O���[��
					n_bx[player] = 2;
				}
				
				stat[player] = 14;		// �G���f�B���O�˓�
			}
			
			return;
		}
		
		if( (ending[player] == 1) || (ending[player] == 4) ) {
			stat[player] = 14;	// �G���f�B���O�˓�
		} else {
			// �A�C�e������
			if(goItemStat(player, stat[player])) return;
			
			// ���x���A�b�v����
			if(!lastblkline[player]) LevelUp(player);
			
			if(gameMode[player] == 6) {
				// ���[�����[�������f
				if( (rollroll_flag[player]) && ((bdowncnt[player] + 1) % p_rollroll_interval == 0) )
					isrollroll[player] = 1;
				else
					isrollroll[player] = 0;
				
				// X-RAY�����f
				isxray[player] = 0;
				if( (xray_flag[player]) && ((bdowncnt[player] + 1) % p_xray_interval == 0) ) {
					isxray[player] = 1;
					xray_counter[player] = 0;
				}
			}
			
			// �t�B�[���h�~���[����
			if(fldMirrorProc(player)) return;
			
			// ����オ�蔻�� #LITE10
			upLines[player] = upLines[player] + checkRiseUp(player);
			
			// ����オ��
			if(upLines[player] > 0) {
				statc[0 + player * 10] = 4;
				statc[1 + player * 10] = 1;
				statRiseLine(player);
				return;
			}
			
			// �����J�n
			statBlock(player);
		}
	}
}

/* �t�B�[���h�~���[ */
int fldMirrorProc(int player) {
	int		i, j;
	
	// ������~
	if((stopmirror_flag[player]) && (fmirror_cnt[player] == -20)) {
		isfmirror[player] = 0;
		stopmirror_flag[player] = 0;
		return 0;
	}
	
	p_fmirror_timer = 20;
	
	if( (isfmirror[player]) && ((bdowncnt[player] % p_fmirror_interval == 0) || (gameMode[player] == 8) || (item_mode[player])) ) {
		if(fmirror_cnt[player] <= p_fmirror_timer) {
			if(fmirror_cnt[player] == -20) {
				// �t�B�[���h���o�b�t�@�Ɋm��
				for(i = 0; i < 22; i++) {
					for(j = 0; j < 10; j++) {
						fldbuf[j + i * 10 + player * 220] = fld[j + i * 10 + player * 220];
						fldtbuf[j + i * 10 + player * 220] = fldt[j + i * 10 + player * 220];
						fldibuf[j + i * 10 + player * 220] = fldi[j + i * 10 + player * 220];
						fldobuf[j + i * 10 + player * 220] = fldo[j + i * 10 + player * 220];
						fldsbuf[j + i * 10 + player * 220] = flds[j + i * 10 + player * 220];
						
						// �u���b�N������
						fld[j + i * 10 + player * 220] = 0;
						fldt[j + i * 10 + player * 220] = 0;
						fldi[j + i * 10 + player * 220] = 0;
						fldo[j + i * 10 + player * 220] = 0;
						flds[j + i * 10 + player * 220] = 0;
					}
				}
			} else {
				// ���]
				if( (fmirror_cnt[player] > 0) && (fmirror_cnt[player] % (p_fmirror_timer / 10) == 0) ) {
					for(i = 0; i < 22; i++) {
						j = fmirror_cnt[player] / (p_fmirror_timer / 10) - 1;
						fld[(10 - j - 1) + i * 10 + player * 220] = fldbuf[j + i * 10 + player * 220];
						fldt[(10 - j - 1) + i * 10 + player * 220] = fldtbuf[j + i * 10 + player * 220];
						fldi[(10 - j - 1) + i * 10 + player * 220] = fldibuf[j + i * 10 + player * 220];
						fldo[(10 - j - 1) + i * 10 + player * 220] = fldobuf[j + i * 10 + player * 220];
						flds[(10 - j - 1) + i * 10 + player * 220] = fldsbuf[j + i * 10 + player * 220];
					}
					
					ExBltFast(17, 8 + ((10 - j - 1) * 8) + foffset[player], 40);
				}
			}
			fmirror_cnt[player]++;
			field_spin[player]++;
			return 1;
		} else if(fmirror_cnt[player] <= p_fmirror_timer + 4) {
			// 4�t���[���̑҂�����
			fmirror_cnt[player]++;
			field_spin[player]++;
			return 1;
		}
		fmirror_cnt[player] = -20;
		field_spin[player] = -1;
		
		// CPU�̑���
		if( (cpu_flag[player]) && ((!replayauto) || (repversw <= 3)) ) {
			cpu_setBestSpot(player, next[player], 0, getNextBlock(player, nextc[player] + 1), 0);
			cpu_setCtrl(player);
		}
	}
	return 0;
}

/* ���x���A�b�v���� */
void LevelUp(int player) {
	int tmp, tmp2;
	
	if(ending[player]) return;
	
	if((!isAceModeOrMission(player)) && (gameMode[player] != 9) && (!isMarathonMode(player))) {
		if(tc[player] / 10 <= tr[player]) return;
		tr[player]++;
		tr2[player]++;
	}
	
	jump(gameMode[player],lbeg,lmas,l20g,ldvl,lvs,lpra,ltmo,lace,lmis,lold,lhep,ldvm,lace200,lbegp,lfinal,ltmo,ledvl,lstd,lmar);
	
	/*
	switch(gameMode[player]) {
		case  0: goto lbeg;
		case  1: goto lmas;
		case  2: goto l20g;
		case  3: goto ldvl;
		case  4: goto lvs;
		case  5: goto lpra;
		case  6: goto ltmo;
		case  7: goto lace;
		case  8: goto lmis;
		case  9: goto lold;
		case 10: goto lhep;
		case 11: goto ldvm;
		case 12: goto lace200;
		case 13: goto lbegp;
		case 14: goto lfinal;
		case 15: goto ltmo;
		case 16: goto ledvl;
		case 17: goto lstd;
		case 18: goto lmar;
	}
	*/
	
	// �r�M�i�[���[�h�̃��x���A�b�v����
	lbeg:
		if(tr[player] < 101) {
			sp[player] = lvTableBeg[tr[player]];
		}
		
		if(tr[player] % 10 == 0) {
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 2) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// �}�X�^�[���[�h�̃��x���A�b�v����
	lmas:
		if((gradetype[player] == 1) && (tr[player] % 10 == 0)) {
			isregret(player);	// REGRET����
			
			if(gup3sp_adjust[player] == 2)		// skip
				tr2[player] = tr2[player] + 10;
			
			if(gup3sp_adjust[player] == 0)		// ��蒼��
				tr2[player] = tr2[player] - 10;
		}
		
		if(tr2[player] < 51) {
			sp[player] = lvTableTgm[tr2[player]];
		}
		
		if(tr[player] % 10 == 0) {
			if((tr2[player] >= 50) && (tr2[player] <= 200) && (gradetype[player] != 2)) {
				sp[player] = 1200;
				wait1[player] = wait1_master_tbl[(tr2[player] - 50) / 10 * 2];
				wait2[player] = wait2_master_tbl[(tr2[player] - 50) / 10 * 2];
				wait3[player] = wait3_master_tbl[(tr2[player] - 50) / 10 * 2];
				waitt[player] = waitt_master_tbl[(tr2[player] - 50) / 10 * 2];
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				if(bgmlv == 0) tr_20g[player] = tr[player];
				bgmlv++;
				changeBGM();
			}
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
			
			if(gradetype[player] == 1) reset_gradeup3(player);	// gradeup3�Ɏg���ϐ�����C�Ƀ��Z�b�g
			
			// MASTER-EASY Gm������������
			if(gradetype[player] == 2) {
				// gmflag1��������iLV300�ɂȂ����Ƃ��ɒi�ʂ�1�ȏ�j
				if((tc[player] >= 300) && (!gmflag1_e[player])) {
					if(grade[player] >= 8) {
						gmflag1[player] = 1;
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					}
					gmflag1_e[player] = 1;
				}
				
				// gmflag2��������iLV500�ɂȂ����Ƃ��ɒi�ʂ�S4�ȏ�j
				if((tc[player] >= 500) && (!gmflag2_e[player])) {
					if(grade[player] >= 12) {
						gmflag2[player] = 1;
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					}
					gmflag2_e[player] = 1;
				}
			}
		}
		
		return;
	
	// 20G���[�h�̃��x���A�b�v����
	l20g:
		if((gradetype[player] == 1) && (tr[player] % 10 == 0)) {
			isregret(player);	// REGRET����
			
			if(gup3sp_adjust[player] == 2)		// skip
				tr2[player] = tr2[player] + 10;
			
			if(gup3sp_adjust[player] == 0)		// ��蒼��
				tr2[player] = tr2[player] - 10;
		}
		
		if(tr[player] % 10 == 0) {
			if((tr2[player] >= 50) && (tr2[player] <= 100) && (gradetype[player] != 2)) {
				wait1[player] = wait1_master_tbl[(tr2[player] - 50) / 10 * 2];
				wait2[player] = wait2_master_tbl[(tr2[player] - 50) / 10 * 2];
				wait3[player] = wait3_master_tbl[(tr2[player] - 50) / 10 * 2];
				waitt[player] = waitt_master_tbl[(tr2[player] - 50) / 10 * 2];
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
			
			if(gradetype[player] == 1) reset_gradeup3(player);	// gradeup3�Ɏg���ϐ�����C�Ƀ��Z�b�g
			
			// 20G-EASY Gm������������
			if((gradetype[player] == 2) && (repversw >= 8)) {
				// gmflag1��������iLV300�ɂȂ����Ƃ��ɒi�ʂ�1�ȏ�j
				if((tc[player] >= 300) && (!gmflag1_e[player])) {
					if(grade[player] >= 8) {
						gmflag1[player] = 1;
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					}
					gmflag1_e[player] = 1;
				}
				
				// gmflag2��������iLV500�ɂȂ����Ƃ��ɒi�ʂ�S4�ȏ�j
				if((tc[player] >= 500) && (!gmflag2_e[player])) {
					if(grade[player] >= 12) {
						gmflag2[player] = 1;
						objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
					}
					gmflag2_e[player] = 1;
				}
			}
		}
		return;
	
	// �f�r��(DOOM)���[�h�̃��x���A�b�v����
	ldvl:
		if(tr[player] % 10 == 0) {
			if(tr[player] <= 120) {
				if(repversw <= 6) {
					wait1[player] = wait1_devil_tbl6[tr[player] / 10];
					wait2[player] = wait2_devil_tbl6[tr[player] / 10];
					wait3[player] = wait3_devil_tbl6[tr[player] / 10];
					waitt[player] = waitt_devil_tbl6[tr[player] / 10];
				} else if(repversw <= 7) {
					wait1[player] = wait1_devil_tbl7[tr[player] / 10];
					wait2[player] = wait2_devil_tbl7[tr[player] / 10];
					wait3[player] = wait3_devil_tbl7[tr[player] / 10];
					waitt[player] = waitt_devil_tbl7[tr[player] / 10];
				} else {
					wait1[player] = wait1_devil_tbl[tr[player] / 10];
					wait2[player] = wait2_devil_tbl[tr[player] / 10];
					wait3[player] = wait3_devil_tbl[tr[player] / 10];
					waitt[player] = waitt_devil_tbl[tr[player] / 10];
				}
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// �Z�N�V�����^�C����REGRET��𒴂��ĂȂ���Βi�ʏ㏸
			if((repversw <= 2) || (sectionTimer[player] < devil_doom_regret_border[(tr[player] / 10) - 1])) {
				grade[player]++;
				gup_down[player] = 1;
				gflash[player] = 120;
				if(grade[player] > 13) grade[player] = 13;
			} else {
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
			}
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 13) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
			
			// ����オ��J�E���g�ݒ�
			if(repversw <= 6) {
				tmp = devil_rise_min6[tr[player] / 10];
				tmp2 = devil_rise_max6[tr[player] / 10];
			} else {
				tmp = devil_rise_min[tr[player] / 10];
				tmp2 = devil_rise_max[tr[player] / 10];
			}
			
			if((risecount[player] <= 0) && (tmp > 0) && (tmp2 > 0) && (r_enable[player])) {
				do {
					risecount[player] = GiziRand(player, tmp2 + 1);
				} while(risecount[player] < tmp);
			}
		}
		return;
	
	// VERSUS
	lvs:
		if((tr[player] % 10 == 0) && (!vs_goal_type)) {
			PlaySE(19);
		}
		return;
	
	// PRACTICE
	lpra:
		if(!p_leveltype) {
			if(tr[player] % 10 == 0) {
				PlaySE(19);
				
				// �Z�N�V�����^�C���L�^
				if(tr[player] / 10 <= 13) {
					now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
					sectionTimer[player] = 0;
				}
			}
		} else {
			if(c_norm[player] >= m_norm[player]) {
				PlaySE(31);
				
				tc[player]++;
				ltime[player] = p_timelimit;
				
				if(p_leveltype == 1) {
					m_norm[player] = m_norm[player] + 10;
					timeOn[player] = 0;
				} else {
					c_norm[player] = 0;
					m_norm[player] = (tc[player] + 1) * 5;
				}
				
				// �Z�N�V�����^�C���L�^
				now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// �x������~
				StopWave(38);
			}
		}
		return;
	
	// TOMOYO
	ltmo:
		if(tr[player] < 31) {
			if((!enable_minspeed) || (lvTabletomoyo[tr[player]] > min_speed[player]))
				sp[player] = lvTabletomoyo[tr[player]];
		}
		
		if(tr[player] % 10 == 0) {
			PlaySE(19);
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
		}
		return;
	
	// ACE
	lace:
		if(c_norm[player] >= m_norm[player]) {
			PlaySE(31);
			
			timeOn[player] = 0;
			
			tc[player]++;
			
			if(timeattack[player] == 0) {
				// NORMAL
				if(repversw >= 2) sp[player] = lvTableAce[tc[player]];
				else if(repversw == 1) sp[player] = lvTableAce1[tc[player]];
				else sp[player] = lvTableAceOld[tc[player]];
				ltime[player] = timeLimitAceNormal[tc[player]];
			} else if(timeattack[player] == 1) {
				// HI-SPEED1
				sp[player] = lvTableHiSpeed1[tc[player]];
				ltime[player] = timeLimitAcea[tc[player]];
			} else if(timeattack[player] == 2) {
				// HI-SPEED2
				ltime[player] = timeLimitAcea[tc[player]];
			} else if(timeattack[player] == 3) {
				// ANOTHER
				if(repversw <= 6) {
					wait1[player] = wait1_Acea_tbl6[tc[player]];
					wait2[player] = wait2_Acea_tbl6[tc[player]];
					wait3[player] = wait3_Acea_tbl6[tc[player]];
					waitt[player] = waitt_Acea_tbl6[tc[player]];
				} else if(repversw <= 7) {
					wait1[player] = wait1_Acea_tbl7[tc[player]];
					wait2[player] = wait2_Acea_tbl7[tc[player]];
					wait3[player] = wait3_Acea_tbl7[tc[player]];
					waitt[player] = waitt_Acea_tbl7[tc[player]];
				} else {
					wait1[player] = wait1_Acea_tbl[tc[player]];
					wait2[player] = wait2_Acea_tbl[tc[player]];
					wait3[player] = wait3_Acea_tbl[tc[player]];
					waitt[player] = waitt_Acea_tbl[tc[player]];
				}
				ltime[player] = timeLimitAcea[tc[player]];
			} else if(timeattack[player] == 4) {
				// ANOTHER2
				ltime[player] = timeLimitAcea[tc[player]];
			}
			
			m_norm[player] = m_norm[player] + 10;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
			sectionTimer[player] = 0;
			
			if(backno < tc[player]) bgfadesw = 1;
			
			// BGM�؂�ւ�
			if(fadelv != 0) {
				bgm_change++;
				bgmlv = ace_bgmlist[bgm_change + timeattack[player] * 3];
				changeBGM();
			}
			
			// �x������~
			StopWave(38);
		}
		
		return;
	
	// MISSION
	lmis:
		return;
	
	// OLD STYLE
	lold:
		if(timeattack[player] == 0) {
			// HANDHELD
			if(c_norm[player] >= m_norm[player]) {
				PlaySE(19);
				tc[player]++;
				
				if(tc[player] < 15) {
					sp[player] = lvTableHeboGB[tc[player]];
					wait3[player] = wait3_HeboGB_tbl[tc[player]];
					waitt[player] = waitt_HeboGB_tbl[tc[player]];
				}
				
				m_norm[player] = m_norm[player] + 10;
				
				// �Z�N�V�����^�C���L�^
				if(tc[player] <= 15) {
					now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
					sectionTimer[player] = 0;
				}
				
				if(backno < tc[player]) bgfadesw = 1;
			}
		} else {
			// ARCADE
			tmp = tc[player];
			if(tmp > 15) tmp = 15;
			
			if((c_norm[player] >= 4) || ((sectionTimer[player] >= lvTimerHeboAC[tmp] * 256) && (!lastblkline[player]))) {
				PlaySE(19);
				tc[player]++;
				
				if(tc[player] < 16) {
					sp[player] = lvTableHeboAC[tc[player]];
				}
				
				c_norm[player] = 0;
				
				// �Z�N�V�����^�C���L�^
				if(tc[player] <= 16) {
					now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
				}
				sectionTimer[player] = 0;
				
				if((backno < tc[player]) && (backno < 14)) bgfadesw = 1;
			}
		}
		
		return;
	
	// HEBO+
	lhep:
		if(tr[player] < 51) {
			sp[player] = lvTableTgm[tr[player]];
		}
		
		if(tr[player] % 10 == 0) {
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			if(r_inter[player] > 1) r_inter[player]--;	// ����オ��Ԋu-1
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// DEVIL-NORMAL
	ldvm:
		if(tr[player] % 10 == 0) {
			if(tr[player] <= 50) {
				if(repversw <= 6) {
					wait1[player] = wait1_devil_m_tbl6[tr[player] / 10];
					wait2[player] = wait2_devil_m_tbl6[tr[player] / 10];
					wait3[player] = wait3_devil_m_tbl6[tr[player] / 10];
					waitt[player] = waitt_devil_m_tbl6[tr[player] / 10];
				} else {
					wait1[player] = wait1_devil_m_tbl[tr[player] / 10];
					wait2[player] = wait2_devil_m_tbl[tr[player] / 10];
					wait3[player] = wait3_devil_m_tbl[tr[player] / 10];
					waitt[player] = waitt_devil_m_tbl[tr[player] / 10];
				}
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// ACE (BASIC�`VOID�j
	lace200:
		if(c_norm[player] >= m_norm[player]) {
			PlaySE(31);
			
			timeOn[player] = 0;
			
			tc[player]++;
			
			if(timeattack[player] == 0) {
				// BASIC
				sp[player] = lvTableAce200Basic[tc[player]];
				wait1[player] = wait1_Ace200Basic_tbl[tc[player]];
				wait2[player] = wait2_Ace200Basic_tbl[tc[player]];
				wait3[player] = wait3_Ace200Basic_tbl[tc[player]];
				waitt[player] = waitt_Ace200Basic_tbl[tc[player]];
				ltime[player] = timeLimitAce200Basic[tc[player]];
			} else if(timeattack[player] == 1) {
				// HELL
				ltime[player] = timeLimitAce200Hell[tc[player]];
				
				if((tc[player] >= 5) && (tc[player] <= 6)) {
					hidden_old[player] = 4;			// ���x��6�`7
				} else if((tc[player] >= 7) && (tc[player] <= 14)) {
					hidden_old[player] = 5;			// ���x��8�`15
				} else if(tc[player] >= 15) {
					hidden_old[player] = 0;
					always_over1000[player] = 1;	// ���x��16�ȍ~��[]
				}
			} else if(timeattack[player] == 2) {
				// HELL-X
				ltime[player] = timeLimitAce200Hell[tc[player]];
				
				if((tc[player] >= 5) && (tc[player] <= 14)) {
					hidden[player] = 1;
					shadowtime[player] = 150;
				} else if((tc[player] >= 15) && (tc[player] <= 18)) {
					shadowtime[player] = 120;
				} else if(tc[player] >= 19) {
					shadowtime[player] = 60;
				}
			} else if(timeattack[player] == 3) {
				// VOID
				wait1[player] = wait1_Ace200Void_tbl[tc[player]];
				wait2[player] = wait2_Ace200Void_tbl[tc[player]];
				wait3[player] = wait3_Ace200Void_tbl[tc[player]];
				waitt[player] = waitt_Ace200Void_tbl[tc[player]];
				ltime[player] = timeLimitAce200Void[tc[player]];
			}
			
			m_norm[player] = m_norm[player] + 10;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
			sectionTimer[player] = 0;
			
			if((tc[player] >= 10) || (tc[player] % 2 == 0)) {
				if(backno < tc[player]) bgfadesw = 1;
			}
			
			// BGM�؂�ւ�
			if(fadelv != 0) {
				bgm_change++;
				bgmlv = ace200_bgmlist[bgm_change + timeattack[player] * 3];
				changeBGM();
			}
			
			// �x������~
			StopWave(38);
		}
		return;
	
	// BEGINNER-NOVICE
	lbegp:
		if(tr[player] < 101) {
			sp[player] = lvTableBeg[tr[player]];
		}
		
		if(tr[player] % 10 == 0) {
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// �A�C�e���o��
			if((tc[player] >= 100) && (tc[player] < 200)) {
				PlaySE(28);
				item_nblk[2 + player * 6] = 28;	// FREE FALL
				item_name[player] = item_nblk[2 + player * 6];
			} else if((tc[player] >= 200) && (tc[player] < 300)) {
				PlaySE(28);
				item_nblk[2 + player * 6] = 19;	// DEL EVEN
				item_name[player] = item_nblk[2 + player * 6];
			}
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 3) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// FINAL
	lfinal:
		if(tr[player] % 10 == 0) {
			if(tr[player] <= 90) {
				if(repversw <= 4) {
					wait1[player] = wait1_final4[tr[player] / 10];
					wait2[player] = wait2_final4[tr[player] / 10];
					wait3[player] = wait3_final4[tr[player] / 10];
					waitt[player] = waitt_final4[tr[player] / 10];
				} else {
					if(rule_lock_reset[rots[player]]) {
						wait1[player] = wait1_final_srs[tr[player] / 10];
						wait2[player] = wait2_final_srs[tr[player] / 10];
						wait3[player] = wait3_final_srs[tr[player] / 10];
						waitt[player] = waitt_final_srs[tr[player] / 10];
					} else {
						wait1[player] = wait1_final_ars[tr[player] / 10];
						wait2[player] = wait2_final_ars[tr[player] / 10];
						wait3[player] = wait3_final_ars[tr[player] / 10];
						waitt[player] = waitt_final_ars[tr[player] / 10];
					}
				}
			}
			
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 10) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// DEVIL-HARD
	ledvl:
		if(tr[player] % 10 == 0) {
			if(tr[player] <= 120) {
				wait1[player] = wait1_devil_tbl32[tr[player] / 10];
				wait2[player] = wait2_devil_tbl32[tr[player] / 10];
				wait3[player] = wait3_devil_tbl32[tr[player] / 10];
				waitt[player] = waitt_devil_tbl32[tr[player] / 10];
			}
			PlaySE(19);
			
			if((backno < tr[player] / 10) && (backno < 9)) bgfadesw = 1;
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			// �Z�N�V�����^�C����REGRET��𒴂��ĂȂ���Βi�ʏ㏸
			if((repversw <= 2) || (sectionTimer[player] < devil_hard_regret_border[(tr[player] / 10) - 1])) {
				grade[player]++;
				gup_down[player] = 1;
				gflash[player] = 120;
				if(grade[player] > 13) grade[player] = 13;
			} else {
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
			}
			
			// �Z�N�V�����^�C���L�^
			if(tr[player] / 10 <= 13) {
				now_sttime[((tr[player] / 10) - 1) + player * 30] = sectionTimer[player];
				sectionTimer[player] = 0;
				
				// ST���_���l��
				getSTMedal(player, ((tr[player] / 10) - 1));
			}
		}
		return;
	
	// STANDARD
	lstd:
		return;
	
	// MARATHON
	lmar:
		if((c_norm[player] >= m_norm[player]) && (tc[player] < 14)) {
			PlaySE(31);
			
			// ���x���A�b�v
			tc[player]++;
			
			if(timeattack[player] == 2) {
				wait1[player] = wait1_Marathon_Oni[tc[player]];
				wait2[player] = wait2_Marathon_Oni[tc[player]];
				wait3[player] = wait3_Marathon_Oni[tc[player]];
				waitt[player] = waitt_Marathon_Oni[tc[player]];
				if(tc[player] >= 9) always_over1000[player] = 1;
			} else {
				sp[player] = lvTableMarathon[tc[player]];
				if(tc[player] >= 11) speedtype[player] = 0;
			}
			
			// �Z�N�V�����^�C���L�^
			now_sttime[(tc[player] - 1) + player * 30] = sectionTimer[player];
			sectionTimer[player] = 0;
			
			// �w�i�ύX
			if(backno < tc[player]) bgfadesw = 1;
			
			c_norm[player] = 0;
			m_norm[player] = (tc[player] + 1) * 5;
		}
		return;
}

// ����オ�蔻��
int checkRiseUp(int player) {
	int tmp, tmp2;
	
	if((gameMode[player] == 3) && (!devil_doom_n_rise)) {
		// DEVIL
		if(repversw <= 6) {
			tmp = devil_rise_min6[tr[player] / 10];
			tmp2 = devil_rise_max6[tr[player] / 10];
		} else {
			tmp = devil_rise_min[tr[player] / 10];
			tmp2 = devil_rise_max[tr[player] / 10];
		}
		
		if((risecount[player] <= 0) && (tmp > 0) && (tmp2 > 0) && (r_enable[player])) {
			do {
				risecount[player] = GiziRand(player, tmp2 + 1);
			} while(risecount[player] < tmp);
			
			return 1;
		}
	} else if(gameMode[player] == 8) {
		// MISSION
		if(r_enable[player]) {
			// DEVIL 800
			if(mission_type[c_mission] == 19) {
				if(mission_opt_2[c_mission]) {
					// RANDOM����
					if(repversw <= 6) {
						tmp = devil_rise_min6[8];
						tmp2 = devil_rise_max6[8];
					} else {
						tmp = devil_rise_min[8];
						tmp2 = devil_rise_max[8];
					}
					
					if((risecount[player] <= 0) && (tmp > 0) && (tmp2 > 0)) {
						do {
							risecount[player] = GiziRand(player, tmp2 + 1);
						} while(risecount[player] < tmp);
						return 1;
					}
				} else {
					// RANDOM�Ȃ�
					if((r_bdowncnt[player] > 0) && (r_bdowncnt[player] % r_inter[player] == 0)) {
						return 1;
					}
				}
			}
		}
	} else if(gameMode[player] == 10) {
		// HEBO+
		if(r_bdowncnt[player] >= r_inter[player]) {
			r_bdowncnt[player] = 0;
			return 1;
		}
	} else {
		// �ʏ�
		if((r_enable[player]) && (tc[player] >= r_start[player]) && (tc[player] <= r_end[player])) {
			if((r_bdowncnt[player] > 0) && (r_bdowncnt[player] % r_inter[player] == 0)) {
				return 1;
			}
		}
	}
	
	return 0;
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.07 - �Q�[���I�[�o�[
//������������������������������������������������������������������������������
void statGameOver(int player) {
	int		i, j, block, c, tmp, draw_rate;

	// VERSUS��p���S����
	if(gameMode[player] == 4) {
		if(flag == 0) {
			StopAllBGM();
			winr = 0;
			winc = 0;
			winu = -24;
			wink = 0;
			flag = -1;
		}
		return;
	}

	if(hidden[player]) {
		hidden[player] = 0;			// �t�B�[���h�^�C�}�[������
		disableShadowTimer(player);
		statc[player * 10 + 5] = 1;
	}

	hidden_old[player] = 0;
	hiddeny[player] = 22;

	// ���v���C�Z�[�u
	ReplaySaveCheck(player, 3);

	if(statc[player * 10 + 3]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 3]);
		printFont(boffset[player], 26, string[0], 5);
	}

	statc[player * 10 + 1]++;
	
	// �v���C���[�f�[�^�X�V
	if(!statc[player * 10 + 4] && !IsBigStart[player] && !item_mode[player] && user_enable[player]) {
		if(gameMode[player] == 0) {
			// BEGINNER-TAMAYA
			user_beginner_tamaya[player] = user_beginner_tamaya[player] + sc[player];
		} else if(gameMode[player] == 1) {
			if(gradetype[player] == 0) {
				// MASTER-NORMAL
				if(grade[player] > user_master_normal[player])
					user_master_normal[player] = grade[player];
			} else if(gradetype[player] == 1) {
				// MASTER-HARD
				if(grade[player] > user_master_hard_provisional[player])
					user_master_hard_provisional[player] = grade[player];
				
				// ���������炷
				user_master_hard_grade_his[player * 5 + 4] = user_master_hard_grade_his[player * 5 + 3];
				user_master_hard_grade_his[player * 5 + 3] = user_master_hard_grade_his[player * 5 + 2];
				user_master_hard_grade_his[player * 5 + 2] = user_master_hard_grade_his[player * 5 + 1];
				user_master_hard_grade_his[player * 5 + 1] = user_master_hard_grade_his[player * 5 + 0];
				
				// �����ɍ���̎b��i�ʂ�����
				user_master_hard_grade_his[player * 5 + 0] = grade[player];
				
				// �Ō�̎�������̌o�ߎ���+1
				if(!examination[player]) user_master_hard_grade_pasttime[player]++;
			}
		} else if(gameMode[player] == 3) {
			// DEVIL-DOOM
			if(grade[player] > user_devil_doom[player])
				user_devil_doom[player] = grade[player];
		} else if(gameMode[player] == 6) {
			// TOMOYO
			if(start_stage[player] == 0) {
				if(stage[player] > user_tomoyo_normal[player]) user_tomoyo_normal[player] = stage[player];
			} else if(start_stage[player] == 27) {
				if(stage[player] > user_tomoyo_eheart[player]) user_tomoyo_eheart[player] = stage[player];
			} else if(start_stage[player] == 45) {
				if(stage[player] > user_tomoyo_target[player]) user_tomoyo_target[player] = stage[player];
			}
		} else if(gameMode[player] == 7) {
			// ACE-NORMAL�`ACE-ANOTHER2
			if(end_f[player]) {
				if((!user_ace[player * 5 + timeattack[player]]) || (gameTimer[player] < user_ace[player * 5 + timeattack[player]]))
					user_ace[player * 5 + timeattack[player]] = gameTimer[player];
			}
		} else if(gameMode[player] == 11) {
			// DEVIL-NORMAL
			if(tc[player] > user_devil_normal[player])
				user_devil_normal[player] = tc[player];
		} else if(gameMode[player] == 13) {
			// BEGINNER-NOVICE
			user_beginner_novice[player] = user_beginner_novice[player] + sc[player];
		} else if(gameMode[player] == 15) {
			// TOMOYO-FLASH
			if(stage[player] > user_tomoyo_flash[player]) user_tomoyo_flash[player] = stage[player];
		} else if(gameMode[player] == 16) {
			// DEVIL-HARD
			if(grade[player] > user_devil_hard[player])
				user_devil_hard[player] = grade[player];
		}
		
		statc[player * 10 + 4] = 1;
	}
	
	if(statc[player * 10 + 2] == 0) {
		statc[player * 10] = 21;
		statc[player * 10 + 2] = 1;
	}
	
	// �t�B�[���h�Ƀu���b�N�������ꍇ�̓u���b�N�������鉉�o���ȗ�
	if(isBravo(player)) {
		statc[player * 10] = -2;
	}
	
	if(statc[player * 10] == -2) {
		tmp = 60;
		
		// �i�ʕ\��
		if(((gameMode[player] == 1) || (gameMode[player] == 2) || (gameMode[player] == 3) || (gameMode[player] == 16)) && 
		   (!examination[player]) && (!demo || demokind) && (gradetype[player] != 2))
		{
			tmp = 300;
			
			// �u���Ȃ��̒i�ʂ́v�̕���
			if(statc[player * 10 + 1] == 1) {
				if(screenMode >= 2) draw_rate = 2;
				else draw_rate = 1;
				
				TextSize(player, 10 * draw_rate);
				TextColor(player, 255, 255, 255);
				TextBackColorDisable(player);
				
				if((gameMode[player] == 1) && (gradetype[player] == 1)) {
					TextOut(player, yourgrade[english + 2]);
					TextLayerOn(player, (foffset[player] + 3) * draw_rate, 92 * draw_rate);
				} else {
					TextOut(player, yourgrade[english]);
					TextLayerOn(player, (foffset[player] + 13) * draw_rate, 92 * draw_rate);
				}
			}
			
			if((gameMode[player] == 1) || (gameMode[player] == 2)) {
				drawGradeImage(foffset[player] + 2, 108, grade[player], 0);
			} else if(gameMode[player] == 16) {
				drawGradeImage(foffset[player] + 2, 108, grade[player], 1);
			} else {
				drawGradeImage(foffset[player] + 2, 108, grade[player], 2);
			}
			
			// �{�^���ŃX�L�b�v
			if(getPushState(player, 4)) {
				tmp = 60;
			}
		}
		
		if(statc[player * 10 + 1] >= tmp) {
			// �u���Ȃ��̒i�ʂ́v�\��������
			if((gameMode[player] == 1) || (gameMode[player] == 2) || (gameMode[player] == 3) || (gameMode[player] == 16))
				TextLayerOff(player);
			
			if((fastroll[player]) && (ending[player] == 2)) {
				// �������[���Œ��������ꍇ�̓G���f�B���O�I���܂ő҂�
				stat[player] = 1;
				statc[player * 10 + 1] = 35;
			} else if(examination[player]) {
				// �������ʂ�
				stat[player] = 40;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 1;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 0;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
			} else {
				// �l�[���G���g���[��
				stat[player] = 11;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
				statc[player * 10 + 2] = 0;
				statc[player * 10 + 3] = 0;
				statc[player * 10 + 4] = 0;
				statc[player * 10 + 5] = 0;
			}
		}
		return;
	}

	if(statc[player * 10 + 1] > 4 + statc[player * 10 + 5] * 116) {
		block = statc[player * 10];
		
		statc[player * 10 + 1] = 0;
		
		for(j = 0; j < 10; j++) {
			// �X�[�b�Ə����Ă������o
			if(block >= 0) {
				c = fldt[j + block * 10 + player * 220];
				if(c == -1) c = 8;
				fldt[j + block * 10 + player * 220] = c - 4;
			}
			
			if(block <= 20) {
				c = fldt[j + (block + 1) * 10 + player * 220];
				fldt[j + (block + 1) * 10 + player * 220] = c - 4;
			}
		}
		
		statc[player * 10 + 5] = 0;
		statc[player * 10]--;
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.08 - �u���b�N����
//������������������������������������������������������������������������������
void statEraseBlock(int player) {
	int		i, j, k, l, x, y, lines, all, hardblock, itemerase, allowskip, squares, squarecount;
	
	padRepeat(player);
	
	// �VIRS
	if(ace_irs) doNewIRS(player, 0);
	
	// HYPER����s�ړ�
	if(fastlrmove == 3) HyperLRMove(player);
	
	// ���𗣂��Ă���ꍇ�A�����ꐧ������
	if( !getPressState(player, 1) ) down_flag[player] = 0;
	if( !getPressState(player, 0) ) up_flag[player] = 0;
	
	// ��HIDDEN����
	hiddenProc(player);
	
	// ARE�X�L�b�v���\�����߂�iSKIP LOCKFLASH��SUPER�������G�t�F�N�g�ɓ����čŏ���1�t���[���̏ꍇ�̓X�L�b�v�s�j
	if((skip_blocklockflash == 3) && (repversw >= 7)) {
		allowskip = (statc[player * 10] != 0);
	} else if(skip_blocklockflash != 2) {
		allowskip = 1;
	} else {
		allowskip = (statc[player * 10] != 0);
	}
	
	if(statc[player * 10] < 1) {
		lines = 0;
		itemerase = 0;		// �A�C�e�������t���O
		squares = 0;		// �����`�����t���O�i���̐����`�͋�̂Q���j
		
		if((item[player]) && (repversw >= 3)) {
			itemerase = 1;
			item_waiting[player] = item[player];
		}
		
		for(i = 0; i < 22; i++) {
			if(erase[i + player * 22]) {
				lines++;
				squarecount = 0;	// �����`����J�E���^�i�����`��������������4�u���b�N�������~�j
				
				for(x = 0; x < 10; x++) {
					hardblock = 0;	// �n�[�h�u���b�N�����t���O
					
					if((breakeffect > 0) && (fldo[x + i * 10 + player * 220] == 0)) {
						if( (breakeffect == 1) || ((gameMode[player] == 0) && (beginner_effect)) || 
						    (heboGB[player]) || (breakeffect >= 4) || 
						    (fld[x + i * 10 + player * 220] >= 11) || 
						    ((lines & 1 != 0) && (x & 1 == 1)) || ((lines & 1 == 0) && (x & 1 == 0)) )
						{
							objectCreate(player, 1, (x + boffset[player]) * 8, (i + 3) * 8, (x - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + lines * 250, fld[x + i * 10 + player * 220] - 1, 100);
						}
					}
					
					// ������u���b�N���v���`�i�u���b�N�Ȃ�
					if(fld[x + i * 10 + player * 220] >= 11) {
						// ���~�b�g�^�C������
						if((tomoyo_timebonus[player]) && (gameMode[player] == 6)) {
							ltime[player] = ltime[player] + 60;
							StopWave(38);
						}
						
						// �v���`�i�u���b�N��-1
						rest_pblock[player]--;
						
						// �����Đ�
						platinaerase_cnt[player]++;
					}
					
					// ������u���b�N���A�C�e��
					if(fldi[x + i * 10 + player * 220]) {
						if(fldi[x + i * 10 + player * 220] == fldisno) {
							// ��X�N�E�F�A
							if(!squarecount) {
								squares++;
								squarecount = 4;
							} else {
								squarecount--;
							}
						} else if(fldi[x + i * 10 + player * 220] == fldigsno) {
							// ���X�N�E�F�A
							if(!squarecount) {
								squares = squares + 2;
								squarecount = 4;
							} else {
								squarecount--;
							}
						} else if(fldi[x + i * 10 + player * 220] == fldihardno) {
							// �n�[�h�u���b�N
							hardblock = 1;
							erase[i + player * 22] = 0;
							fldi[x + i * 10 + player * 220] = 0;
							squarecount = 0;
						} else if(fldi[x + i * 10 + player * 220] < fldihardno) {
							// �A�C�e��
							itemerase = 1;
							if(breakeffect) objectCreate(player, 9, (x + boffset[player]) * 8, (i + 3) * 8, 0, 0, 0, 0);
							if(!item_waiting[player]) item_waiting[player] = fldi[x + i * 10 + player * 220];
							squarecount = 0;
						}
					} else {
						squarecount = 0;
					}
					
					if(!hardblock) {
						fld[x + i * 10 + player * 220] = 0;
						fldt[x + i * 10 + player * 220] = 0;
						fldi[x + i * 10 + player * 220] = 0;
						fldo[x + i * 10 + player * 220] = 0;
						grayoutLackedBlock(player, flds[x + i * 10 + player * 220]);
						flds[x + i * 10 + player * 220] = 0;
					}
				}
			}
		}
		
		statc[player * 10]++;
		
		// �S�����`�F�b�N
		all = isBravo(player);
		
		// BIG�ł�0.5���C��������0���C�������ɂ���
		if((IsBig[player]) && (lines == 1)) lines = 0;
		
		// BIG�̏ꍇ�̓��C������2�Ŋ���
		if((IsBig[player]) && (lines >= 2)) lines = lines / 2;
		
		lastblkline[player] = lines;
		
		lastline[player] = lines;
		if(enable_disp_lastline) lastline_frame[player] = 60;
		
		if(IsTspin[player]) lasttspin[player] = lines;
		
		if(lines) {
			i = lines;
			if(i > 4) i = 4;
			
			PlaySE(10 + i);
			
			if(i >= 4) PlaySE(17);
			if(hebocombo[player]) PlaySE(18);
		} else {
			PlaySE(11);
		}
		
		if(enable_combo) {
			combo[player]++;
			if(lines >= 2) combo2[player]++;
			cmbpts[player] = cmbpts[player] + (lines * 2 - 2);
			
			if(IsTspin[player]) tcombo[player]++;
			else tcombo[player] = 0;
		} else {
			combo[player] = 0;
			cmbpts[player] = 0;
			combo2[player] = 0;
			tcombo[player] = 0;
		}
		
		// �ԉΌv�Z #LITE19
		if((gameMode[player] == 0) && (!itemerase)) {
			if(!enable_combo) hanabi_combo[player] = 0;
			
			if( (lines >= 2) || ((IsTspin[player]) && (lines >= 1)) ) {
				// T-SPIN�{�[�i�X
				if((IsTspin[player]) && (bonus_tspin))
					hanabi_combo[player] = ((hanabi_combo[player] + lines) * 5) / 2;
				
				i = lines + hanabi_combo[player] + combo2[player];
				hanabi_combo[player] = i;		// �O�ɑł��グ�������o���Ă����i������LV150�ȍ~�̔{���͏����j
				
				if(ending[player] == 2)    i = i * 2;			// ���[������2�{
				else if(tc[player] >= 150) i = i + (i / 2);		// LV150�ȍ~��1.5�{
			} else {
				// T-SPIN�Ȃ��̈������̓R���{���ł��ꔭ
				i = 1;
			}
			
			// �S������4�{
			if(all) i = i * 4;
			
			sc[player] = sc[player] + i;
			hanabi_waiting[player] = hanabi_waiting[player] + i;
			hanabi_frame[player] = 0;
		}
		
		// ���[�����ɏ������񐔑���
		if(ending[player] == 2) {
			endlines[player] = endlines[player] + lines;
		}
		
		// BACK TO BACK
		if( (enable_b_to_b != 0) && ((lines >= 4) || (IsTspin[player])) && (isTSpinEnableMode(player)) ) {
			b_to_b[player] = 1;
			b_to_b_count[player]++;
			if(b_to_b_count[player] >= 2) b_to_b_frame[player] = 120;
		} else {
			b_to_b[player] = 0;
			b_to_b_count[player] = 0;
		}
		
		// ���C�������񐔑���
		line_count[(lines - 1) + player * 4]++;
		if(user_enable[player]) user_line_count[(lines - 1) + player * 4]++;
		
		// T-SPIN�񐔑���
		if(IsTspin[player]) tspin_count[lines + player * 4]++;
		
		// �X�R�A�v�Z
		if(!ending[player] && !ismiss[player]) {
			calcScore(player, lines, all, itemerase, squares);
		}
	}
	
	if(statc[player * 10] >= wait2[player]) {
		// ��ɂ������u���b�N�����܂ŉ��낷
		lines = downFloatingBlocks(player);
		
		// BIG�ł�0.5���C��������0���C�������ɂ���
		if((IsBig[player]) && (lines == 1)) lines = 0;
		
		// BIG�̏ꍇ�̓��C������2�Ŋ���
		if((IsBig[player]) && (lines >= 2)) lines = lines / 2;
		
		PlaySE(2);
		
		if((lines >= 4) && (enable_combo)) hebocombo[player]++;
		
		// �w�{���X3�A���ŋUCOOL
		if((gameMode[player] == 1) && (gradetype[player] == 1) && (hebocombo[player] == 3)) {
			PlaySE(48);
			gup_down[player] = 1;
			gflash[player] = 180;
		}
		
		// T-SPIN2�A���ŋUCOOL
		if((gameMode[player] == 1) && (gradetype[player] == 1) && (tcombo[player] == 2)) {
			PlaySE(48);
			gup_down[player] = 1;
			gflash[player] = 180;
		}
		
		// ���ԉ҂���
		stat[player] = 6;
		statc[player * 10] = wait1[player];
		statc[player * 10 + 1] = 0;
		
		// �G���f�B���O�˓���
		if( ((ending[player] == 1) || (ending[player] == 4)) && (!IsPlayWave(29)) ) PlaySE(29);
		
		pinchCheck(player);
		
		// �A�C�e������
		if(item_waiting[player]) {
			eraseItem(player, item_waiting[player]);
		}
	} else {
		// ARE�X�L�b�v
		if((rule_are[rots[player]] == 2) && (harddrop[player]) && (allowskip)) {
			if(getPushState(player, 0) || getPushState(player, 1) || getPushState(player, 2) || getPushState(player, 3) ||
			   getPushState(player, 4) || getPushState(player, 5) || getPushState(player, 6) )
			{
				statc[player * 10] = wait2[player];
				are_skipflag[player] = 1;
			}
		}
		
		statc[player * 10]++;
	}
}

// ��ɂ������u���b�N�����܂ŉ��낷
int downFloatingBlocks(int player) {
	int		i, k, l, y, lines;
	
	y = 21;
	lines = 0;
	
	for(i = 0; i < 22; i++) {
		if(erase[y + player * 22]) {
			for(k = y; k > 0; k--) {
				for(l = 0; l < 10; l++) {
					fld[l + k * 10 + player * 220] = fld[l + (k - 1) * 10 + player * 220];
					fldt[l + k * 10 + player * 220] = fldt[l + (k - 1) * 10 + player * 220];
					fldi[l + k * 10 + player * 220] = fldi[l + (k - 1) * 10 + player * 220];
					fldo[l + k * 10 + player * 220] = fldo[l + (k - 1) * 10 + player * 220];
					flds[l + k * 10 + player * 220] = flds[l + (k - 1) * 10 + player * 220];
				}
				erase[k + player * 22] = erase[(k - 1) + player * 22];
			}
			
			// ��ԏ���󔒂ɂ���
			for(l = 0; l < 10; l++) {
				fld[l + player * 220] = 0;
				fldt[l + player * 220] = 0;
				fldi[l + player * 220] = 0;
				fldo[l + player * 220] = 0;
				flds[l + player * 220] = 0;
			}
			erase[player * 22] = 0;
			
			lines++;
		} else {
			y--;
		}
	}
	
	return lines;
}

// �j�Ѓu���b�N����
void grayoutLackedBlock(int player, int no) {
	int i, j;
	
	if(no <= 0) return;
	
	for(j = 0; j < 22; j++) {
		for(i = 0; i < 10; i++) {
			if((fld[i + j * 10 + player * 220] >= 1) && (flds[i + j * 10 + player * 220] == no)) {
				flds[i + j * 10 + player * 220] = 0;	// �j�Ђɂ���
				if(lackblock_grayout) fld[i + j * 10 + player * 220] = 1;	// �D�F�u���b�N�ɂ���
			}
		}
	}
}

// �����`���ł��邩�`�F�b�N
// player�F�v���C���[�ԍ� x:�n�_��X���W y:�n�_��Y���W gold:1�̏ꍇ�͈��ނ̃u���b�N�݂̂Ő����`���ł���
int checkSquare(int player, int x, int y, int gold) {
	int i, j, color;
	
	// �n�_�̐F���擾
	color = getFieldBlock(player, x, y);
	
	// �󔒂������玸�s
	if(color <= 0) return 0;
	
	// ������܃u���b�N�⏉���z�u��������A�j�Ђ�������A���ɐ����`�������玸�s
	if(getFieldBlockS(player, x, y) <= 0) return 0;
	
	// �F��2��ވȏ�Ȃ玸�s�igold != 0�̂Ƃ��̂݁j
	if(gold) {
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 4; j++) {
				if(getFieldBlock(player, x + i, y + j) != color) return 0;
			}
		}
	}
	
	// �j�Ђ�����Ύ��s
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			if(getFieldBlockS(player, x + i, y + j) <= 0) return 0;
		}
	}
	
	// �n�_����Ƀu���b�N���q�����Ă��玸�s
	for(i = 0; i < 4; i++) {
		if(getFieldBlockS(player, x + i, y    ) == getFieldBlockS(player, x + i, y - 1)) return 0;
	}
	
	// �����`�̒��艺�Ƀu���b�N���q�����Ă��玸�s
	for(i = 0; i < 4; i++) {
		if(getFieldBlockS(player, x + i, y + 3) == getFieldBlockS(player, x + i, y + 4)) return 0;
	}
	
	// �n�_��荶�Ƀu���b�N���q�����Ă��玸�s
	for(j = 0; j < 4; j++) {
		if(getFieldBlockS(player, x    , y + j) == getFieldBlockS(player, x - 1, y + j)) return 0;
	}
	
	// �����`�̒[���E�Ƀu���b�N���q�����Ă��玸�s
	for(j = 0; j < 4; j++) {
		if(getFieldBlockS(player, x + 3, y + j) == getFieldBlockS(player, x + 4, y + j)) return 0;
	}
	
	// ����
	return 1;
}

// �����`�����
int makeSquare(int player) {
	int i, j, k, l, result;
	result = 0;
	
	for(i = 0; i < 22 - 3; i++) {
		for(j = 0; j < 10 - 3; j++) {
			if(checkSquare(player, j, i, 1)) {
				// ���F
				if(result < 2) result = 2;
				PlaySE(18);
				squarenum[player] = squarenum[player] + 2;
				
				// �}�[�N��t����
				for(k = 0; k < 4; k++) {
					for(l = 0; l < 4; l++) {
						fldi[(k + j) + (l + i) * 10 + player * 220] = fldigsno;
						flds[(k + j) + (l + i) * 10 + player * 220] = -1;
					}
				}
			} else if(checkSquare(player, j, i, 0)) {
				// ��F
				if(result < 1) result = 1;
				PlaySE(17);
				squarenum[player]++;
				
				// �}�[�N��t����
				for(k = 0; k < 4; k++) {
					for(l = 0; l < 4; l++) {
						fldi[(k + j) + (l + i) * 10 + player * 220] = fldisno;
						flds[(k + j) + (l + i) * 10 + player * 220] = -1;
					}
				}
			}
		} /* for(j = 0; j < 6; j++) */
	} /* for(i = 0; i < 18; i++) */
	
	return result;
}

// �S�����`�F�b�N
int isBravo(int player) {
	int all, i, j;
	
	all = 1;
	
	for(j = 0; j < 22; j++) {
		for(i = 0; i < 10; i++) {
			if(fld[i + j * 10 + player * 220] != 0) {
				all = 0;
				break;
			}
		}
	}
	
	return all;
}

// �X�R�A�v�Z
void calcScore(int player, int lines, int all, int itemerase, int squares) {
	int bo, bai, i, j, tcbuf;
	
	if(all) {
		// �S�������o
		objectCreate(player, 2, player, 30, 0, 0, 0, 0);
		
		if(isAceModeOrMission(player)) PlaySE(19);
	}
	
	if(gameMode[player] == 8) {
		// MISSION���[�h
		if((mission_type[c_mission] != 26) || (all)) missionNormUp(lines);
	} else if(gameMode[player] == 9) {
		// OLD STYLE���[�h
		c_norm[player] = c_norm[player] + lines;
		
		if(timeattack[player] == 0) {
			if(lines == 1) bo = 40;
			if(lines == 2) bo = 100;
			if(lines == 3) bo = 300;
			if(lines == 4) bo = 1200;
			bai = tc[player] + 1;
		} else {
			if(lines == 1) bo = 100;
			if(lines == 2) bo = 400;
			if(lines == 3) bo = 900;
			if(lines == 4) bo = 2000;
			
			if(tc[player] >= 8) {
				bai = 5;
			} else {
				bai = (tc[player] / 2) + 1;
			}
			
			if(all) bai = bai * 10;
		}
		
		sc[player] = sc[player] + bo * bai;
	} else if((gameMode[player] == 17) || (isMarathonMode(player))) {
		// SIMPLE/MARATHON/PRACTICE(10 LINES/MARATHON)���[�h
		if(bonus_tspin && IsTspin[player]) {
			// T-SPIN
			if(lines == 1) {
				if(!tspin_kick[player]) bo = 8;
				else bo = 2;
			}
			if(lines >= 2) bo = 12;
		} else {
			// ���ʂ̃��C������
			if(lines == 1) bo = 1;
			if(lines == 2) bo = 3;
			if(lines == 3) bo = 5;
			if(lines == 4) bo = 8;
		}
		
		// �X�N�E�F�A�{�[�i�X
		if(squares) bo = bo + squares * 5;
		
		bai = 1;
		
		// Back to Back
		if((bonus_btb) && (b_to_b_count[player] >= 2)) bai = (b_to_b_count[player] / 2);
		
		// �X�R�A���Z
		sc[player] = sc[player] + (bo * bai * 100 * (tc[player] + 1));
		if(gameMode[player] != 17) c_norm[player] = c_norm[player] + (bo * bai);
		
		// �R���{�{�[�i�X
		if(combo[player] >= 2) {
			sc[player] = sc[player] + (combo[player] - 1) * 50 * (tc[player] + 1);
			if(gameMode[player] != 17) c_norm[player] = c_norm[player] + ((combo[player] - 1) / 2);
		}
		
		// SIMPLE���[�h�̃��C����
		if(gameMode[player] == 17) {
			c_norm[player] = c_norm[player] + lines;
		}
		
		// VS���[�h�ł͋K��|�C���g�ɓ��B����Ə���
		if((gameMode[player] == 4) && (vs_goal_level > 0) && (c_norm[player] >= vs_goal_level * 5)) {
			c_norm[player] = vs_goal_level * 5;
			setGameOver(1 - player);
		}
	} else if(isAceMode(player)) {
		// ACE���[�h
		c_norm[player] = c_norm[player] + lines;
		if(fadelv == 0) checkFadeout(player);
		
		// VS���[�h�ł͋K�胉�C���ɓ��B����Ə���
		if((gameMode[player] == 4) && (vs_goal_level > 0) && (c_norm[player] >= vs_goal_level * 10)) {
			c_norm[player] = vs_goal_level * 10;
			setGameOver(1 - player);
		}
	} else {
		// �ʏ탂�[�h�Ȃ�X�R�A�v�Z
		if(isNormalMode(player)) {
			// �������x�̒x�����[���ł̓h���b�v�{�[�i�X����
			if(rule_soft_speed[rots[player]] == 0) qdrop[player] = qdrop[player] / 2;
			
			// �������x�̑������[���ł̓h���b�v�{�[�i�X1.5�{
			if(rule_soft_speed[rots[player]] == 2) qdrop[player] = qdrop[player] + (qdrop[player] / 2);
			
			// �������x��2�{�̃��[���ł̓h���b�v�{�[�i�X2�{
			if(rule_soft_speed[rots[player]] == 3) qdrop[player] = qdrop[player] * 2;
			
			bo = (tc[player] + lines) / 4 + sdrop[player] + qdrop[player];
			
			if((gameMode[player] >= 1) && (gameMode[player] <= 2) && (gradetype[player] == 2)) {
				// MASTER-EASY
				if(combo[player] >= 2) j = combo[player] - 1 + (2 * lines - 1);
				else j = 1;
				bai = lines * j;
			} else {
				// ���̑�
				bai = (lines * 2 - 1 + cmbpts[player] - (lines * 2 - 2)) * lines;
			}
			
			// �S��������ƃX�R�A4�{
			if(all) bai = bai * 4;
			
			// T-SPIN��4�{
			if(bonus_tspin && IsTspin[player]) bai = bai * 4;
			
			// BACK TO BACK��1.5�{
			if((bonus_btb) && (b_to_b_count[player] >= 2)) bai = bai + (bai / 2);
			
			// BEGINNER+�ł͏펞6�{
			if(gameMode[player] == 13) bai = bai * 6;
			
			// �X�R�A���Z
			if(!itemerase) sc[player] = sc[player] + bo * bai;
		}
		
		// HARD�p
		if(gradetype[player] == 1) {
			if(lines == 4) gskill[player]++;					// 4�i�����{�[�i�X
			
			if(bonus_tspin)
				gskill[player] = gskill[player] + IsTspin[player];	// T-SPIN�{�[�i�X
		}
		
		// �i�� #LITE18
		if( (gameMode[player] == 1) || (gameMode[player] == 2) ) {
			if(gradetype[player] == 0)
				GradeUp(player, lines);
			else if(gradetype[player] == 1)
				GradeUp3(player);
			else if(gradetype[player] == 2)
				GradeUpEasy(player);
		}
		
		// PRACTICE�̍��v���C��������
		if(gameMode[player] == 5) c_norm[player] = c_norm[player] + lines;
		
		// 4�i�����񐔑���
		if( (lines == 4) && (isNormalOrBeginnerMode(player)) ) {
			skill[player]++;
			
			// SK���_���l��
			if( (skill[player] == 15) || (skill[player] == 25) || (skill[player] == 40) ) {
				PlaySE(45);
				medal_sk[player]++;
				medal_visible_sk[player] = 0;
				objectCreate(player, 7, soffset[player] * 8 + 2 + 16, 129, 2, 0, 0, medal_sk[player]);
			}
		}
		
		// �S���������AC���_���l��
		if( (all) && (isNormalOrBeginnerMode(player)) ) {
			if(medal_ac[player] < 3) {
				PlaySE(45);
				medal_ac[player]++;
				medal_visible_ac[player] = 0;
				objectCreate(player, 7, soffset[player] * 8 + 2 + 16, 116, 0, 0, 0, medal_ac[player]);
			}
		}
		
		// CO���_���l��
		if(isNormalOrBeginnerMode(player)) {
			if( ((medal_co[player] == 0) && (combo2[player] == 4)) ||
				((medal_co[player] == 1) && (combo2[player] == 5)) ||
				((medal_co[player] == 2) && (combo2[player] == 7)) )
			{
				PlaySE(45);
				medal_co[player]++;
				medal_visible_co[player] = 0;
				objectCreate(player, 7, soffset[player] * 8 + 2, 129, 3, 0, 0, medal_co[player]);
			}
		}
		
		// BLIND
		if( (gameMode[player] == 6) && (blind_flag[player]) )
			isblind[player] = !isblind[player];
		
		// TGMLV�㏸
		if(gameMode[player] != 17) {
			tcbuf = tc[player];
			if(!lvupbonus)
				tc[player] = tc[player] + lines + ((lines >= 3) * (lines - 2));
			else
				tc[player] = tc[player] + lines;
			
			// lvstop.wav��炷
			if((gameMode[player] == 0) || (gameMode[player] == 3) || (gameMode[player] == 16))
				i = 99;
			else if(gameMode[player] == 13)
				i = 99 * (tc[player] >= 200);
			else
				i = 99 - ((tc[player] >= 900) && (timeattack[player]));
			
			if((tc[player] % 100 == i) && (i != 0)) PlaySE(28);
			
			// TOMOYO���[�h�ł�998�ŃX�g�b�v
			if((gameMode[player] == 6) && (tc[player] > 998)) tc[player] = 998;
			
			// VS���[�h�ł͋K�背�x���ɓ��B����Ə���
			if((gameMode[player] == 4) && (vs_goal_level > 0) && (tc[player] >= vs_goal_level * 100)) {
				tc[player] = vs_goal_level * 100;
				setGameOver(1 - player);
			}
		}
	}
	
	// ���C�������ŃA�C�e���Q�[�W�㏸
	if((item_gauge_uptype >= 1) && (item_mode[player]) && (!ismiss[player])) {
		item_g[player] = item_g[player] + lines;
		
		if(item_gauge_uptype == 1) {
			if(item_g[player] > item_interval) item_g[player] = item_interval;
		} else {
			if(item_g[player] > item_interval + 1) item_g[player] = item_interval + 1;
		}
	}
	
	li[player] = li[player] + lines;						// ���C��������
	
	if( (bgm >= 2) && (fadelv == 0) ) checkFadeout(player);	// BGM�t�F�[�h�A�E�g�`�F�b�N
	
	// HIDDEN�ŉB���ꂽ�i��������悤�ɂ���
	hiddenti[player] = hiddenti[player] + lines;
	
	while(hiddenti[player] > 0) {
		hiddenti[player]--;
		hiddeny[player]++;
		if(hiddeny[player] > 22) {
			hiddeny[player] = 22;
			hiddentm[player] = 0;
		}
	}
	
	// �X�N�E�F�A���[�h�ł�T-SPIN�t���[�t�H�[��
	// �{����T-SPIN�V���O���̏ꍇ�̓��C�����������Ƃ��납�牺�����t���[�t�H�[������񂾂���
	// �u���b�N�̈��������蔻�肪���G�Ȃ�ō��̏��͑S�����Ƃ�
	if((squaremode[player]) && (IsTspin[player]) && (repversw >= 1)) {
		isFreefall[player] = 1;
	}
	
	// �G���f�B���O�˓��`�F�b�N
	checkEnding(player, tcbuf);
	
	// ���x���A�b�v����
	LevelUp(player);
}

// �G���f�B���O�ɓ˓����邩�`�F�b�N
void checkEnding(int player, int tcbuf) {
	int i, tmp;
	
	jump(gameMode[player],lbeg,lmas,lmas,ldvl,ldummy,lpra,ldummy,lace,ldummy,ldummy,lhep,ldvm,lace200,lbegp,lfinal,ldummy,ldvl,lstd,lmar);
	
	/*
	switch(gameMode[player]) {
		case  0: goto lbeg;
		case  1: goto lmas;
		case  2: goto lmas;
		case  3: goto ldvl;
		case  4: goto ldummy;
		case  5: goto lpra;
		case  6: goto ldummy;
		case  7: goto lace;
		case  8: goto ldummy;
		case  9: goto ldummy;
		case 10: goto lhep;
		case 11: goto ldvm;
		case 12: goto lace200;
		case 13: goto lbegp;
		case 14: goto lfinal;
		case 15: goto ldummy;
		case 16: goto ldvl;
		case 17: goto lstd;
		case 18: goto lmar;
	}
	*/
	
	lbeg:
		// BEGINNER�Ȃ�200�ŏI��
		if((tc[player] >= 200) && (timeattack[player])) {
			tc[player] = 200;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// ���[�����̉ԉΊԊu������
			if(sc[player] >= 400) {
				hanabi_int[player] = 12;	// 400���ȏ�ŕb��5��
			} else if(sc[player] >= 200) {
				hanabi_int[player] = 15;	// 200�`399���ŕb��4��
			} else {
				hanabi_int[player] = 20;	// 199�ȉ��ŕb��3��
			}
			
			// �X�^�b�t���[���pwait�l�Z�b�g
			sp[player] = speed_beginner_roll;
			wait1[player] = wait1_beginner_roll;
			wait2[player] = wait2_beginner_roll;
			wait3[player] = wait3_beginner_roll;
			waitt[player] = waitt_beginner_roll;
			
			PlaySE(19);
			//backno++;
			if(backno < 2) bgfadesw = 1;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[1 + player * 30] = sectionTimer[player];
			
			// ST���_���l��
			getSTMedal(player, 1);
		}
		return;
	
	lmas:
		// MASTER��20G�ł�999�ŏI��
		if((tc[player] >= 999) && (timeattack[player])) {
			tc[player] = 999;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// �X�^�b�t���[���pwait�l�Z�b�g
			sp[player] = speed_master_roll;
			
			if(gradetype[player] == 1) {
				// HARD
				wait1[player] = wait1_master_rollG4;
				wait2[player] = wait2_master_rollG4;
				wait3[player] = wait3_master_rollG4;
				waitt[player] = waitt_master_rollG4;
			} else if(gradetype[player] == 0) {
				// NORMAL
				wait1[player] = wait1_master_roll;
				wait2[player] = wait2_master_roll;
				wait3[player] = wait3_master_roll;
				waitt[player] = waitt_master_roll;
			}
			
			// Gm������S�Ė������Ă��邩�`�F�b�N
			tmp = 0;
			
			if(gradetype[player] == 0) {
				// NORMAL
				// M�ȏ��8��45�b�ȓ�
				if((grade[player] >= 27) && (gameTimer[player] <= 525 * 60) && (gmflag1[player]) && (gmflag2[player]))
				{
					tmp = 1;
				}
			} else if(gradetype[player] == 1) {
				// HARD
				// m5�ȏ��6��30�b�ȓ�
				// LV400�ɂȂ����Ƃ���tr2�ϐ���80�ȏ�AREGRET�������o�Ȃ�
				if( (grade[player] >= 22) && (gameTimer[player] <= 390 * 60) && 
				    (gup3rank[player] == 2) && (gmflag1[player]) && (!gmflag2[player]) )
				{
					tmp = 1;
				}
			} else if(gradetype[player] == 2) {
				// EASY
				// S9��13:30:00�ȓ��Agmflag1��gmflag2�_���ς݁A�X�R�A126000�_�ȏ�
				if((grade[player] >= 17) && (gameTimer[player] <= 48600) && 
				   (sc[player] >= master_easy_score_table[17]) && (gmflag1[player]) && (gmflag2[player]))
				{
					tmp = 1;
				}
			}
			
			if(tmp) {
				gmflag_r[player] = 1;	// GM�ɂȂ錠�����^�����A�������[���˓�
				objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
			}
			
			// MASTER-EASY
			if(gradetype[player] == 2) {
				// Gm�����𖞂����Ă���ꍇ
				if(gmflag_r[player]) {
					if(!IsPlayWave(29)) PlaySE(29);
					ending[player] = 2;
					ending_timeOn[player] = 1;
					end_f[player] = 2;
					
					grade[player] = 18;
					gup_down[player] = 1;
					gflash[player] = 120;
					
					// BGM�؂�ւ�
					if(bgm >= 2) {
						bgmlv = 7;
						changeBGM();
					}
				}
				// �������Ă��Ȃ��ꍇ
				else {
					ending[player] = 4;
				}
			}
			
			// �Z�N�V�����^�C���L�^
			now_sttime[9 + player * 30] = sectionTimer[player];
			
			// ST���_���l��
			getSTMedal(player, 9);
		}
		
		// LV500�̑��؂� #LITE20
		if( (tc[player] >= 500) && (tcbuf < 500) && (gradetype[player] != 2) && 
			(gameTimer[player] >= timelimit[0 + player * 2]) && (timelimit[0 + player * 2] > 0) )
		{
			tc[player] = 500;
			timeOn[player] = 0;
			if(repversw <= 4) onRecord[player] = 0;
			ending[player] = 4;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[4 + player * 30] = sectionTimer[player];
			
			// ���G���f�B���O
			stat[player] = 14;
			for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		}
		return;
	
	ldvl:
		// DEVIL(HARD/DOOM)�ł�1300�ŏI��
		if((tc[player] >= 1300) && (timeattack[player])) {
			tc[player] = 1300;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// �X�^�b�t���[���pwait�l�Z�b�g
			sp[player] = speed_devil_roll;
			if((repversw >= 4) && (gameMode[player] == 3)) {
				wait1[player] = wait1_devil_roll;
				wait2[player] = wait2_devil_roll;
				wait3[player] = wait3_devil_roll;
				waitt[player] = waitt_devil_roll;
			} else {
				wait1[player] = wait1_devil_roll3;
				wait2[player] = wait2_devil_roll3;
				wait3[player] = wait3_devil_roll3;
				waitt[player] = waitt_devil_roll3;
			}
			
			// �Z�N�V�����^�C������𒴂��Ă��Ȃ��ꍇ�͒i�ʏ㏸
			if(gameMode[player] == 16) tmp = devil_hard_regret_border[12];
			else tmp = devil_doom_regret_border[12];
			
			if((repversw <= 2) || (sectionTimer[player] < tmp)) {
				grade[player]++;
				gflash[player] = 120;
				if(grade[player] > 13) grade[player] = 13;
			} else {
				PlaySE(44);
				gup_down[player] = 0;
				gflash[player] = 120;
			}
			
			// �Z�N�V�����^�C���L�^
			now_sttime[12 + player * 30] = sectionTimer[player];
			
			// ST���_���l��
			getSTMedal(player, 12);
			
			// GOD�����𖞂����Ă���ꍇ�͗��ꐯ�o��
			if(grade[player] == 13) {
				if(isWRule(player)) {
					if(gameMode[player] == 16) tmp = 21000;
					else tmp = 19200;
				} else {
					if(gameMode[player] == 16) tmp = 19200;
					else tmp = 18000;
				}
				
				if(gameTimer[player] <= tmp) {
					objectCreate(player, 4, Rand(20) + foffset[player] + 68, 20 + Rand(10), 0, 0, 0, 0);
				}
			}
		}
		
		// LV500�̑��؂� #LITE20
		if( (tc[player] >= 500) && (tcbuf < 500) && 
			(gameTimer[player] >= timelimit[0 + player * 2]) && (timelimit[0 + player * 2] > 0) )
		{
			tc[player] = 500;
			timeOn[player] = 0;
			if(repversw <= 4) onRecord[player] = 0;
			ending[player] = 4;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[4 + player * 30] = sectionTimer[player];
			
			// ���G���f�B���O
			stat[player] = 14;
			for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		}
		
		// LV1000�̑��؂� #LITE20
		if( (tc[player] >= 1000) && (tcbuf < 1000) && 
			(gameTimer[player] >= timelimit[1 + player * 2]) && (timelimit[1 + player * 2] > 0) )
		{
			tc[player] = 1000;
			timeOn[player] = 0;
			if(repversw <= 4) onRecord[player] = 0;
			ending[player] = 4;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[9 + player * 30] = sectionTimer[player];
			
			// ���G���f�B���O
			stat[player] = 14;
			for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		}
		
		return;
	
	ldummy:
		// �G���f�B���O�Ȃ�
		return;
	
	lpra:
		// PRACTICE
		if(p_goal > 0) {
			tmp = 0;
			
			if((p_leveltype == 0) && (tc[player] >= p_goal * 100))
				tmp = 1;
			if((p_leveltype == 1) && (c_norm[player] >= p_goal * 10))
				tmp = 1;
			if((p_leveltype == 2) && (c_norm[player] >= p_goal * 5))
				tmp = 1;
			
			if(tmp) {
				if(p_leveltype == 0) tc[player] = p_goal * 100;
				if(p_leveltype == 1) c_norm[player] = p_goal * 10;
				if(p_leveltype == 2) c_norm[player] = p_goal * 5;
				
				timeOn[player] = 0;
				ending[player] = 1;
				end_f[player] = 1;
				
				// �Z�N�V�����^�C���L�^
				now_sttime[(tr[player] / 10) + player * 30] = sectionTimer[player];
				
				// �������[��
				if(p_staffroll == 2) {
					if(!IsPlayWave(29)) PlaySE(29);
					ending[player] = 2;
					fastroll[player] = 1;
					ending_timeOn[player] = 1;
				}
			}
		}
		return;
	
	lace:
		// ACE�ł�150���C���ŏI��
		if(c_norm[player] >= 150) {
			PlaySE(31);
			c_norm[player] = 150;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 2;
			
			// �x������~
			pinch[player] = 0;
			StopWave(38);
			
			// ���v���C�L�^�I��
			if(repversw <= 4) onRecord[player] = 0;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[14 + player * 30] = sectionTimer[player];
		}
		return;
	
	lhep:
		// HEBO+
		if((tc[player] >= 999) && (timeattack[player])) {
			tc[player] = 999;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[9 + player * 30] = sectionTimer[player];
		}
		return;
	
	ldvm:
		// DEVIL-
		if((tc[player] >= 999) && (timeattack[player])) {
			if(!IsPlayWave(29)) PlaySE(29);
			tc[player] = 999;
			timeOn[player] = 0;
			ending[player] = 2;
			end_f[player] = 1;
			ending_timeOn[player] = 1;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[9 + player * 30] = sectionTimer[player];
			
			fastroll[player] = 1;	// �������[��
		}
		
		// LV500�̑��؂�
		if( (tc[player] >= 500) && (tcbuf < 500) && 
			(gameTimer[player] >= timelimit[0 + player * 2]) && (timelimit[0 + player * 2] > 0) )
		{
			if(!IsPlayWave(29)) PlaySE(29);
			tc[player] = 500;
			timeOn[player] = 0;
			ending[player] = 2;
			
			// BGM�؂�ւ�
			if( (bgm >= 2) && (fadelv != 0) ) {
				bgmlv++;
				changeBGM();
			}
			
			ending_timeOn[player] = 1;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[4 + player * 30] = sectionTimer[player];
			
			fastroll[player] = 1;	// �������[��
		}
		return;
	
	// ACE200
	lace200:
		// ACE200�ł�200���C���ŏI��
		if(c_norm[player] >= 200) {
			c_norm[player] = 200;
			timeOn[player] = 0;
			ending[player] = 1;
			hidden_old[player] = 0;
			
			if(timeattack[player] >= 2) {
				end_f[player] = 1;
			} else {
				end_f[player] = 2;
				
				// ���v���C�L�^�I��
				if(repversw <= 4) onRecord[player] = 0;
			}
			
			// �x������~
			pinch[player] = 0;
			StopWave(38);
			
			// �Z�N�V�����^�C���L�^
			now_sttime[19 + player * 30] = sectionTimer[player];
		}
		return;
	
	// BEGINNER+
	lbegp:
		if((tc[player] >= 300) && (timeattack[player])) {
			if(!IsPlayWave(29)) PlaySE(29);
			tc[player] = 300;
			timeOn[player] = 0;
			ending[player] = 2;
			end_f[player] = 1;
			ending_timeOn[player] = 1;
			
			// �X�^�b�t���[���pwait�l�Z�b�g
			sp[player] = speed_beginner_roll;
			wait1[player] = wait1_beginner_roll;
			wait2[player] = wait2_beginner_roll;
			wait3[player] = wait3_beginner_roll;
			waitt[player] = waitt_beginner_roll;
			
			if(backno < 3) bgfadesw = 1;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[2 + player * 30] = sectionTimer[player];
			
			// ST���_���l��
			getSTMedal(player, 2);
			
			// �^�C���{�[�i�X
			if(gameTimer[player] < 18000) {
				tmp = 1253 * (300 - (gameTimer[player] / 60));
				if(tmp > 0) sc[player] = sc[player] + tmp;
			}
			
			// BGM�Đ�
			if(!onRecord[1 - player]) {
				bgmlv = 1;
				changeBGM();
			}
			
			fastroll[player] = 1;	// �������[��
		}
		return;
	
	// FINAL
	lfinal:
		if((tc[player] >= 999) && (timeattack[player])) {
			tc[player] = 999;
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 1;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[9 + player * 30] = sectionTimer[player];
		}
		return;
	
	// SIMPLE
	lstd:
		// 40LINES
		if((timeattack[player] == 0) || (timeattack[player] == 2)) {
			if(c_norm[player] >= m_norm[player]) {
				c_norm[player] = m_norm[player];
				timeOn[player] = 0;
				ending[player] = 1;
				
				// �x������~
				pinch[player] = 0;
				StopWave(38);
				
				// ���v���C�L�^�I��
				if((timeattack[player] == 0) && (repversw <= 4)) onRecord[player] = 0;
			}
		}
		return;
	
	// MARATHON
	lmar:
		if((c_norm[player] >= m_norm[player]) && (tc[player] >= 14) && (timeattack[player] != 2)) {
			PlaySE(31);
			c_norm[player] = m_norm[player];
			timeOn[player] = 0;
			ending[player] = 1;
			end_f[player] = 2;
			
			// �Z�N�V�����^�C���L�^
			now_sttime[14 + player * 30] = sectionTimer[player];
			
			// �x������~
			pinch[player] = 0;
			StopWave(38);
			
			// ���v���C�L�^�I��
			if(repversw <= 4) onRecord[player] = 0;
		}
		return;
}

// ST���_���l������
void getSTMedal(int player, int section) {
	int tmp;
	
	tmp = ST_RankingCheck(player, section);
	
	if(tmp > medal_st[player]) {
		PlaySE(45);
		medal_st[player] = tmp;
		medal_visible_st[player] = 0;
		objectCreate(player, 7, soffset[player] * 8 + 2, 116, 1, 0, 0, medal_st[player]);
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.09 - �ΐ탂�[�h���x���Z���N�g
//������������������������������������������������������������������������������
void statSelectLevel(int player) {
	int color, i;
	
	// �f�t�H���g�ݒ��ǂݍ���
	if(!statc[player * 10 + 2]) {
		loadWait(player, p_def_setting);
		statc[player * 10 + 1] = p_def_setting;
		statc[player * 10 + 2] = 1;
	}
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	// ���j���[�\��
	printFont(boffset[player],  5, "ROT. RULE", fontc[rots[player]]);
	getRuleName(player);
	printFont(boffset[player],  6, string[0], (statc[player * 10] == 0) * color);
	
	printFont(boffset[player],  8, "GAME SPEED", fontc[rots[player]]);
	sprintf(string[0], "%s%2d", delayname[0 + english * 4], wait1[player]);
	printFont(boffset[player],  9, string[0], (statc[player * 10] == 1) * color);
	sprintf(string[0], "%s%2d", delayname[1 + english * 4], wait2[player]);
	printFont(boffset[player], 10, string[0], (statc[player * 10] == 2) * color);
	sprintf(string[0], "%s%2d", delayname[2 + english * 4], wait3[player]);
	printFont(boffset[player], 11, string[0], (statc[player * 10] == 3) * color);
	sprintf(string[0], "%s%2d", delayname[3 + english * 4], waitt[player]);
	printFont(boffset[player], 12, string[0], (statc[player * 10] == 4) * color);
	sprintf(string[0], "SPEED %4d", sp[player]);
	printFont(boffset[player], 13, string[0], (statc[player * 10] == 5) * color);
	
	printFont(boffset[player], 15, "FAVORITES", fontc[rots[player]]);
	printFont(boffset[player], 16, waitname[statc[player * 10 + 1]], (statc[player * 10] == 6) * color);
	
	printFont(boffset[player], 18, "CPU PLAYER", fontc[rots[player]]);
	
	if(cpu_flag[player] == 0) sprintf(string[0], "CPU    OFF");
	else sprintf(string[0], "CPU     ON");
	printFont(boffset[player], 19, string[0], (statc[player * 10] == 7) * color);
	
	sprintf(string[0], "LEVEL   %2d", cpu_level[player] + 1);
	printFont(boffset[player], 20, string[0], (statc[player * 10] == 8) * color);
	
	printFont(boffset[player], 22, "ATTACK", fontc[rots[player]]);
	
	if(!item_mode[player]) sprintf(string[0], "ITEM   OFF");
	else sprintf(string[0], "ITEM    ON");
	printFont(boffset[player], 23, string[0], (statc[player * 10] == 9) * color);
	
	if(!r_enable[player]) sprintf(string[0], "RISE   OFF");
	else sprintf(string[0], "RISE    ON");
	printFont(boffset[player], 24, string[0], (statc[player * 10] == 10) * color);
	
	padRepeat(player);
	padRepeat2(player);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10]--;
		if(statc[player * 10] < 0) statc[player * 10] = 10;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10]++;
		if(statc[player * 10] > 10) statc[player * 10] = 0;
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		PlaySE(3);
		
		// ROT. RULE
		if(statc[player * 10] == 0) {
			changeRule(player, rots[player] - 1);
		}
		// SYUTUGEN
		if(statc[player * 10] == 1) {
			wait1[player]--;
			if(wait1[player] < 0) wait1[player] = 99;
		}
		// SYOUKYO
		if(statc[player * 10] == 2) {
			wait2[player]--;
			if(wait2[player] < 0) wait2[player] = 99;
		}
		// SETTYAKU
		if(statc[player * 10] == 3) {
			wait3[player]--;
			if(wait3[player] < 0) wait3[player] = 99;
		}
		// YOKOTAME
		if(statc[player * 10] == 4) {
			waitt[player]--;
			if(waitt[player] < 0) waitt[player] = 99;
		}
		// SPEED
		if(statc[player * 10] == 5) {
			sp[player]--;
			if(sp[player] < 0) sp[player] = 1200;
		}
		// FAVORITES
		if(statc[player * 10] == 6) {
			i = 0;
			
			do {
				statc[player * 10 + 1]--;
				if(statc[player * 10 + 1] < 0) {
					if(i == 0) {
						statc[player * 10 + 1] = 19;
						i = 1;
					} else {
						statc[player * 10 + 1] = 0;
						break;
					}
				}
			} while(favorites_isempty(statc[player * 10 + 1]));
		}
		// CPU
		if(statc[player * 10] == 7) {
			cpu_flag[player] = !cpu_flag[player];
		}
		// CPU LEVEL
		if(statc[player * 10] == 8) {
			cpu_level[player]--;
			if(cpu_level[player] < 0) cpu_level[player] = 4;
		}
		// ITEM
		if(statc[player * 10] == 9) {
			item_mode[player] = !item_mode[player];
			item_mode[1 - player] = item_mode[player];
		}
		// RISE
		if(statc[player * 10] == 10) {
			r_enable[player] = !r_enable[player];
			r_enable[1 - player] = r_enable[player];
		}
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		PlaySE(3);
		
		// ROT. RULE
		if(statc[player * 10] == 0) {
			changeRule(player, rots[player] + 1);
		}
		// SYUTUGEN
		if(statc[player * 10] == 1) {
			wait1[player]++;
			if(wait1[player] > 99) wait1[player] = 0;
		}
		// SYOUKYO
		if(statc[player * 10] == 2) {
			wait2[player]++;
			if(wait2[player] > 99) wait2[player] = 0;
		}
		// SETTYAKU
		if(statc[player * 10] == 3) {
			wait3[player]++;
			if(wait3[player] > 99) wait3[player] = 0;
		}
		// YOKOTAME
		if(statc[player * 10] == 4) {
			waitt[player]++;
			if(waitt[player] > 99) waitt[player] = 0;
		}
		// SPEED
		if(statc[player * 10] == 5) {
			sp[player]++;
			if(sp[player] > 1200) sp[player] = 0;
		}
		// FAVORITES
		if(statc[player * 10] == 6) {
			i = 0;
			
			do {
				statc[player * 10 + 1]++;
				if(statc[player * 10 + 1] > 19) {
					if(i == 0) {
						statc[player * 10 + 1] = 0;
						i = 1;
					} else {
						statc[player * 10 + 1] = 0;
						break;
					}
				}
			} while(favorites_isempty(statc[player * 10 + 1]));
		}
		// CPU
		if(statc[player * 10] == 7) {
			cpu_flag[player] = !cpu_flag[player];
		}
		// CPU LEVEL
		if(statc[player * 10] == 8) {
			cpu_level[player]++;
			if(cpu_level[player] > 4) cpu_level[player] = 0;
		}
		// ITEM
		if(statc[player * 10] == 9) {
			item_mode[player] = !item_mode[player];
			item_mode[1 - player] = item_mode[player];
		}
		// RISE
		if(statc[player * 10] == 10) {
			r_enable[player] = !r_enable[player];
			r_enable[1 - player] = r_enable[player];
		}
	}
	
	// �V���[�g�J�b�g�L�[�������ꂽ��Ή�����ݒ��ǂݍ���
	for(i = 0; i < 20; i++) {
		if( IsPushKey(waitkey[i]) ) {
			PlaySE(3);
			loadWait(player, i);
		}
	}
	
	// A�{�^��
	if( getPushState(player, 4) ) {
		if(statc[player * 10] == 6) {
			// ���x�ǂݍ���
			PlaySE(3);
			loadWait(player, statc[player * 10 + 1]);
		} else {
			// �Q�[���X�^�[�g
			PlaySE(10);
			
			// ���x���o�b�N�A�b�v
			b_sp[player]    = sp[player];
			b_wait1[player] = wait1[player];
			b_wait2[player] = wait2[player];
			b_wait3[player] = wait3[player];
			b_waitt[player] = waitt[player];
			
			// CPU�ݒ���o�b�N�A�b�v
			b_cpu_flag[player] = cpu_flag[player];
			b_cpu_level[player] = cpu_level[player];
			
			// �A�C�e���ݒ���o�b�N�A�b�v
			b_item_mode[player] = item_mode[player];
			b_r_enable[player] = r_enable[player];
			
			stat[player] = 1;					// �u���b�N�V���b�^�[���s
			statc[player * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 10;		// �V���b�^�[��̓X�e�[�^�XNo.10
			return;
		}
	}
	
	// B�{�^��
	if( getPushState(player, 5) ) {
		PlaySE(5);
		
		leaveVersusMode();
		
		// �Z���N�g��ʂɖ߂�
		if(!maxPlay) {
			stat[0] = 2;
			stat[1] = 0;
		} else {
			stat[player] = 2;
			stat[1 - player] = 0;
		}
		return;
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.10 - �ΐ탂�[�h���茈��҂�
//������������������������������������������������������������������������������
void statVersusWait(int player) {
	if(count % 60 > 30) {
		// WAIT
		ExBltRect(49, foffset[player] - 2, 91, 100, 0, 100, 50);
	}

	if((stat[1] == 10) && (player == 0)) {
		bgmlv = 10;
		stat[0] = 3;
		stat[1] = 3;
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.11 - �l�[���G���g���[
//������������������������������������������������������������������������������
void statNameEntry(int player) {
	int		move, len;
	
	// PRACTICE��p���S����
	if(gameMode[player] == 5) {
		PracticeDeath();
		return;
	}
	
	// ���v���C�Z�[�u
	ReplaySaveCheck(player, 4);
	
	if(statc[player * 10 + 4]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 4]);
		printFont(boffset[player], 26, string[0], 5);
	}
	
	// ������
	if(statc[player * 10 + 1] == 0) {
		// ���O��ݒ�
		if(!user_enable[player]) StrCpy(string[player + 2], "");
		else StrCpy(string[player + 2], user_name[player]);
		
		// ���ʂ��擾
		if(gameMode[player] == 17) {
			statc[player * 10 + 3] = stdRankingCheck(player);
		} else {
			statc[player * 10 + 3] = RankingCheck(player);
		}
		
		// �Z�N�V�����^�C���X�V���`�F�b�N
		statc[player * 10 + 5] = ST_RankingCheckAll(player);
		
		// �����N�O
		if((statc[player * 10 + 3] == -1) && (statc[player * 10 + 5] == 0)) {
			// �v���C���[�f�[�^�ۑ�
			if(user_enable[player]) user_save(player);
			
			// GAME OVER
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
			statc[player * 10 + 3] = 0;
			statc[player * 10 + 4] = 0;
			statc[player * 10 + 5] = 0;
			stat[player] = 12;
			return;
		}
		
		// BGM�Đ�
		if((!onRecord[1 - player]) && (bgmlv != 13)) {
			bgmlv = 13;
			changeBGM();
		}
		
		// �v���C���[�f�[�^�g�p���͕\�����ԒZ�k
		if(user_enable[player]) statc[player * 10 + 1] = 35 * 60;
	}
	
	len = StrLen(string[player + 2]);	// ���͍ςݕ�����
	
	// ���ʂɓ��������\��
	if(statc[player * 10 + 3] != -1) {
		sprintf(string[0], "RANK %d", statc[player * 10 + 3] + 1);
		printFont(boffset[player] + 2, 7, string[0], 5);
	}
	
	// �Z�N�V�����^�C���X�V
	if(statc[player * 10 + 5]) {
		printFont(boffset[player]    ,  9, "NEW ST", 3);
		printFont(boffset[player] + 1, 10, "RECORD(S)", 3);
	}
	
	if(!user_enable[player]) {
		printFont(boffset[player], 12, "ENTER NAME", 4);

		padRepeat(player);

		// ���ړ�
		move = getPressState(player, 3) - getPressState(player, 2);
		if(move)
			if((mpc[player] == 1) || (mpc[player] >= 15) || getPressState(player, 6)) {
				if(mpc[player] >= 15) mpc[player] = 12;
				statc[player * 10 + 2] = statc[player * 10 + 2] + move;
				PlaySE(5);
			}

		// �����̃��[�v
		if(statc[player * 10 + 2] > 54)
			statc[player * 10 + 2] = (len == 3) * 53;
		if(statc[player * 10 + 2] < (len == 3) * 53)
			statc[player * 10 + 2] = 54;

		// �I�����Ă��镶���Ɠ��͍ςݕ�����\��
		MidStr(RankString, statc[player * 10 + 2] + 1, 1, string[4]);
		printFont(boffset[player] + 3 + len, 14, string[4], 2 * (count % 20 > 10));
		printFont(boffset[player] + 3, 14, string[player + 2], 0);

		// �c�莞�Ԃ�\��
		statc[player * 10 + 1]++;
		printFont(boffset[player] + 3, 16, "TIME", 6);
		sprintf(string[0], "%2d", 45 - (statc[player * 10 + 1] / 60));
		printFont(boffset[player] + 4, 17, string[0], 0);

		// B�{�^����1�����폜
		if(getPushState(player, 5)) {
			if(len) {
				PlaySE(5);
				MidStr(string[player + 2], 1, len - 1, string[player + 2]);
			}
		}

		// A�{�^���œ���
		if(getPushState(player, 4)) {
			PlaySE(10);
			
			if(statc[player * 10 + 2] == 53) {
				// RB
				if(len) {
					MidStr(string[player + 2], 1, len - 1, string[player + 2]);
				}
			} else if(statc[player * 10 + 2] == 54) {
				// ED
				PlaySE(18);
				statc[player * 10 + 1] = 45 * 60;
			} else {
				// ��������
				StrCat(string[player + 2], string[4]);
			}
		}
	} else {
		printFont(boffset[player] + 2, 12, "PLAYER", 4);
		printFont(boffset[player] + 3, 14, string[player + 2], 0);
		
		statc[player * 10 + 1]++;
		
		if(getPushState(player, 4)) {
			statc[player * 10 + 1] = 45 * 60;
		}
	}
	
	// �l�[���G���g���[�I��
	if(statc[player * 10 + 1] >= 45 * 60) {
		// ���O�����͂���Ă��Ȃ��ꍇ��NOP�Ƃ��ēo�^
		if(!len) StrCpy(string[player + 2], "NOP");
		
		// ���O�̌��ɃX�y�[�X��}���i���O��1�`2���������Ȃ��ꍇ�A�]���������X�y�[�X�ɂ���j
		sprintf(string[player + 2], "%s   ", string[player + 2]);
		
		// ������4�����ڈȍ~���폜
		LeftStr(string[player + 2], 3, string[player + 2]);
		
		// �����L���O�ɓo�^���ۑ�
		if(statc[player * 10 + 3] != -1) {
			if(gameMode[player] == 17) {
				stdRankingRegist(player, statc[player * 10 + 3], string[player + 2]);
				stdRankingSave();
			} else {
				RankingRegist(player, statc[player * 10 + 3], string[player + 2]);
				RankingSave();
			}
		}
		
		// �Z�N�V�����^�C�������L���O�ɓo�^���ۑ�
		if(statc[player * 10 + 5]) {
			ST_RankingUpdate(player, string[player + 2]);
			ST_RankingSave();
		}
		
		// �v���C���[�f�[�^�ۑ�
		if(user_enable[player]) user_save(player);
		
		statc[player * 10 + 1] = 0;
		statc[player * 10 + 2] = 0;
		statc[player * 10 + 3] = 0;
		statc[player * 10 + 4] = 0;
		stat[player] = 12;
	}
}

//������������������������������������������������������������������������������
//   �X�e�[�^�XNo.12 - ���ʕ\��
//������������������������������������������������������������������������������
void statResult(int player) {
	int i, tmp;
	
	// BGM�Đ�
	if((!onRecord[1 - player]) && (bgmlv != 13) && (statc[player * 10 + 1] == 0)) {
		bgmlv = 13;
		changeBGM();
	}
	
	// ���v���C�Z�[�u
	ReplaySaveCheck(player, 3);
	
	if(statc[player * 10 + 3]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 3]);
		printFont(boffset[player], 26, string[0], 5);
	}
	
	statc[player * 10 + 1]++;
	
	printFont(boffset[player], 6, "PLAY DATA", 4);
	
	if(gameMode[player] == 4) {
		// VERSUS���[�h
		if(!vs_goal_type) {
			// LEVEL
			printFont(boffset[player], 8, "LEVEL", fontc[rots[player]]);
			sprintf(string[0], "%4d", tc[player]);
			printFont(boffset[player] + 6, 9, string[0], 0);
		} else {
			// NORM
			printFont(boffset[player], 8, "NORM", fontc[rots[player]]);
			sprintf(string[0], "%4d", c_norm[player]);
			printFont(boffset[player] + 6, 9, string[0], 0);
		}
		
		// TIME
		printFont(boffset[player], 11, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 12, string[0], 0);
	} else if(gameMode[player] == 6) {
		// TOMOYO���[�h
		// STAGE
		printFont(boffset[player], 8, "STAGE", fontc[rots[player]]);
		getTomoyoStageNo(stage[player], 0, 2);
		printFont(boffset[player] + 7, 9, string[0], 0);
		
		// CLEAR
		if(stage[player] <= 26) {
			printFont(boffset[player], 11, "CLEAR", fontc[rots[player]]);
			sprintf(string[0], "%3d%%", clearp[player]);
			printFont(boffset[player] + 6, 12, string[0], 0);
		}
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	} else if(isAceMode(player)) {
		// ACE���[�h
		// LINES
		printFont(boffset[player], 8, "LINES", fontc[rots[player]]);
		sprintf(string[0], "%3d", c_norm[player]);
		printFont(boffset[player] + 7, 9, string[0], 0);
		
		// LEVEL
		printFont(boffset[player], 11, "LEVEL", fontc[rots[player]]);
		sprintf(string[0], "%4d", tc[player] + 1);
		printFont(boffset[player] + 6, 12, string[0], 0);
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	} else if(gameMode[player] == 8) {
		// MISSION���[�h
		// MISSION
		printFont(boffset[player], 8, "MISSION", fontc[rots[player]]);
		sprintf(string[0], "%3d", c_mission + 1);
		printFont(boffset[player] + 7, 9, string[0], 0);
		
		// TIME
		printFont(boffset[player], 11, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 12, string[0], 0);
	} else if(gameMode[player] == 15) {
		// TOMOYO-FLASH���[�h
		// SCORE
		printFont(boffset[player], 8, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%7d", sc[player]);
		printFont(boffset[player] + 3, 9, string[0], 0);
		
		// STAGE
		printFont(boffset[player], 11, "STAGE", fontc[rots[player]]);
		sprintf(string[0], "%3d", stage[player] + 1);
		printFont(boffset[player] + 7, 12, string[0], 0);
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	} else if(gameMode[player] == 17) {
		// SIMPLE���[�h
		if(timeattack[player] >= 2) {
			tmp = 0;
			
			for(i = 0; i < 3; i++) {
				sprintf(string[0], "TRY %d:", i + 1);
				printFont(boffset[player], 8 + i * 3, string[0], fontc[rots[player]]);
				
				if(timeattack[player] == 2) {
					getTime(rot_relay_record[i + player * 3]);
				} else {
					sprintf(string[0], "%d", rot_relay_record[i + player * 3]);
				}
				tmp = tmp + rot_relay_record[i + player * 3];
				printFont(boffset[player] + 2, 9 + i * 3, string[0], 0);
			}
			
			printFont(boffset[player], 17, "TOTAL:", fontc[rots[player]]);
			if(timeattack[player] == 2) {
				getTime(tmp);
			} else {
				sprintf(string[0], "%d", tmp);
			}
			printFont(boffset[player] + 2, 18, string[0], 0);
		} else {
			printFont(boffset[player], 8 + timeattack[player] * 3, "LINES", fontc[rots[player]]);
			sprintf(string[0], "%3d", c_norm[player]);
			printFont(boffset[player] + 7, 9 + timeattack[player] * 3, string[0], 0);
			
			printFont(boffset[player], 11 - timeattack[player] * 3, "SCORE", fontc[rots[player]]);
			sprintf(string[0], "%7d", sc[player]);
			printFont(boffset[player] + 3, 12 - timeattack[player] * 3, string[0], 0);
			
			// TIME
			printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
			getTime(gameTimer[player]);
			printFont(boffset[player] + 2, 15, string[0], 0);
		}
	} else if(gameMode[player] == 18) {
		// MARATHON���[�h
		// SCORE
		printFont(boffset[player], 8, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%7d", sc[player]);
		printFont(boffset[player] + 3, 9, string[0], 0);
		
		if(timeattack[player] == 1) {
			// SQUARE
			printFont(boffset[player], 11, "SQUARE", fontc[rots[player]]);
			sprintf(string[0], "%3d", squarenum[player]);
			printFont(boffset[player] + 7, 12, string[0], 0);
		} else {
			// LINES
			printFont(boffset[player], 11, "LINES", fontc[rots[player]]);
			sprintf(string[0], "%3d", li[player]);
			printFont(boffset[player] + 7, 12, string[0], 0);
		}
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	} else if((gameMode[player] == 1) || (gameMode[player] == 2) || (gameMode[player] == 3) || (gameMode[player] == 16)) {
		// MASTER & 20G & DEVIL-DOOM & DEVIL-HARD
		// SCORE
		printFont(boffset[player], 8, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%7d", sc[player]);
		printFont(boffset[player] + 3, 9, string[0], 0);
		
		// LEVEL
		printFont(boffset[player], 11, "LEVEL", fontc[rots[player]]);
		sprintf(string[0], "%4d", tc[player]);
		printFont(boffset[player] + 6, 12, string[0], 0);
		
		// GRADE
		printFont(boffset[player], 14, "GRADE", fontc[rots[player]]);
		
		if(gameMode[player] == 3)
			getGradeString(grade[player], 2, 1);
		else if(gameMode[player] == 16)
			getGradeString(grade[player], 1, 1);
		else if(gradetype[player] == 2)
			getGradeString(grade[player], 3, 1);
		else
			getGradeString(grade[player], 0, 1);
		
		sprintf(string[0], "%3s", string[1]);
		printFont(boffset[player] + 7, 15, string[0], 0);
		
		// TIME
		printFont(boffset[player], 17, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 18, string[0], 0);
	} else {
		// ����ȊO�̃��[�h
		// SCORE
		printFont(boffset[player], 8, "SCORE", fontc[rots[player]]);
		sprintf(string[0], "%7d", sc[player]);
		printFont(boffset[player] + 3, 9, string[0], 0);
		
		// LEVEL
		printFont(boffset[player], 11, "LEVEL", fontc[rots[player]]);
		sprintf(string[0], "%4d", tc[player]);
		printFont(boffset[player] + 6, 12, string[0], 0);
		
		// TIME
		printFont(boffset[player], 14, "TIME", fontc[rots[player]]);
		getTime(gameTimer[player]);
		printFont(boffset[player] + 2, 15, string[0], 0);
	}
	
	// S-GRADE
	if(statc[player * 10 + 1] == 1) {
		statc[player * 10 + 2] = checkSecretGrade(player);
	}
	if(statc[player * 10 + 2] >= min_sgrade) {
		printFont(boffset[player], 23, "S-GRADE", fontc[rots[player]]);
		getGradeString(statc[player * 10 + 2], 3, 1);
		sprintf(string[0], "%2s", string[1]);
		printFont(boffset[player] + 8, 24, string[0], 0);
	}

	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4)) {
		statc[player * 10 + 1] = 500;
	}

	// �I��
	if(statc[player * 10 + 1] >= 500) {
		if(gameMode[player] == 4) {
			// VERSUS���[�h�ł̓��v���C�Z�[�u��ʂ�
			StopAllBGM();
			
			if((replayauto) && (replayno != 41)) {
				flag = 1;
			} else {
				for(i = 0; i < 2; i++) stat[i] = 24;
				for(i = 0; i < 20; i++) statc[i] = 0;
			}
		} else {
			if( ((gameMode[player] == 6) || (gameMode[player] == 15)) && (!ending[player]) && (!playback) )
				stat[player] = 19;	// TOMOYO���[�h�ł̓R���e�B�j���[��ʂ�
			else
				stat[player] = 13;
			
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.13 - �Q�[���I�[�o�[�\��
//������������������������������������������������������������������������������
void statGameOver2(int player) {
	int i;
	
	// ���v���C�Z�[�u
	ReplaySaveCheck(player, 3);
	
	if(statc[player * 10 + 3]) {
		sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 3]);
		printFont(boffset[player], 26, string[0], 5);
	}
	
	// �J�E���^����
	statc[player * 10]++;
	
	if(statc[player * 10] == 1) {
		// �Q�[���I�[�o�[��
		PlaySE(8);
		
		// �SBGM��~
		if(!onRecord[1 - player]) StopAllBGM();
	}
	
	// GAME OVER
	ExBltRect(49, foffset[player] - 2, 95, 0, 0, 100, 50);
	
	// �{�^���ŃX�L�b�v
	if(getPushState(player, 4)) {
		statc[player * 10] = 480;
	}
	
	// �I��
	if(statc[player * 10] >= 480) {
		// ���̉��
		if( ((!replayauto) || (replayno == 41)) && (!demo) && (show_endmenu) ) stat[player] = 24;
		else stat[player] = 0;
		
		for(i=0; i<10; i++) statc[player * 10 + i] = 0;
		
		if(!show_endmenu) {
			if(!onRecord[1 - player]) {
				backno = 0;
				back_acnt = 0;
			}
			
			// MISSION���[�h�p
			if( (gameMode[0] == 8) && (player == 0) && (!playback) ) {
				playerInitial(0);
				stat[0] = 1;
				statc[0 * 10] = 0;
				statc[0 * 10 + 1] = 22;
			}
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.14 - �G���f�B���O�E���[��
//������������������������������������������������������������������������������
void statEnding(int player) {
	int i, j, k;
	
	if(onRecord[player]) {
		// ������
		if(repversw >= 7) padRepeat(player);
		
		// �VIRS
		if(ace_irs) doNewIRS(player, 0);
		
		// HYPER����s�ړ�
		if(fastlrmove == 3) HyperLRMove(player);
	}
	
	jump(ending[player] - 1, lerase, lstart, lclear, lerase, lretry);
	
	/*
	switch(ending[player]) {
		case 1: goto lerase;
		case 2: goto lstart;
		case 3: goto lclear;
		case 4: goto lerase;
		case 5: goto lretry;
	}
	*/
	
	// �G���f�B���O1��4 �u���b�N����
	lerase:
		if(statc[player * 10] == 0) {
			// BGM��~
			if(!onRecord[1 - player]) StopAllBGM();
			
			// �x������~
			pinch[player] = 0;
			StopWave(38);
			
			statc[player * 10 + 1] = 0;
			if(ending[player] == 4) statc[player * 10 + 1] = checkFieldTop(player) * 6;
		}
		
		// �u���b�N������
		if(statc[player * 10 + 1] % 6 == 0) {
			if(ending[player] == 4) {
				j = statc[player * 10 + 1] / 6;
			} else {
				j = 22 - statc[player * 10 + 1] / 6;
			}
			
			if((j >= 0) && (j < 22)) {
				for(i = 0; i < 10; i++) {
					if(fld[i + j * 10 + player * 220]) {
						if(fldo[i + j * 10 + player * 220] == 0) {
							objectCreate(player, 1, (i + boffset[player]) * 8, (j + 3) * 8, (i - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, fld[i + j * 10 + player * 220] - 1, 100);
						}
						fld[i + j * 10 + player * 220] = 0;
						fldt[i + j * 10 + player * 220] = 0;
						fldi[i + j * 10 + player * 220] = 0;
						fldo[i + j * 10 + player * 220] = 0;
						flds[i + j * 10 + player * 220] = 0;
					}
				}
			}
		}
		
		// �A�j���I��
		if(statc[player * 10] == 129) {
			if(gameMode[player] == 5) {
				// PRACTICE
				if(!p_staffroll) {
					// ��EXCELLENT
					ending[player] = 3;
				} else {
					// �X�^�b�t���[��
					ending[player] = 2;
					
					// BGM�Đ�
					if(!onRecord[1 - player]) {
						bgmlv = 6;
						changeBGM();
					}
				}
			} else if(gameMode[player] == 6) {
				// TOMOYO
				if(stage[player] == 44) {
					// EHeart�ł̓X�^�b�t���[��
					ending[player] = 2;
					
					// BGM�Đ�
					if(!onRecord[1 - player]) {
						bgmlv = 6;
						changeBGM();
					}
				} else {
					// ��EXCELLENT���
					ending[player] = 3;
				}
			} else if(gameMode[player] == 7) {
				// ACE
				ending[player] = 3;
			} else if(gameMode[player] == 8) {
				// MISSION���[�h
				if((mission_end[c_mission] >= 4) && (mission_end[c_mission] <= 9)) {
					// �X�^�b�t���[���J�n
					ending[player] = 2;
					
					// BGM�Đ�
					bgmlv = 6;
					changeBGM();
				} else if((mission_end[c_mission] == 2) || (mission_end[c_mission] == 3)) {
					// ���؂�
					ending[player] = 5;
				} else {
					// �ʏ�
					ending[player] = 3;
				}
			} else if(gameMode[player] == 12) {
				// ACE200
				if(timeattack[player] >= 2) {
					ending[player] = 2;
					hidden[player] = 2;
					
					// BGM�Đ�
					if(!onRecord[1 - player]) {
						bgmlv = 6;
						changeBGM();
					}
				} else {
					ending[player] = 3;
				}
			} else if(gameMode[player] == 17) {
				// SIMPLE
				if(timeattack[player] >= 2) {
					// ROT. RELAY
					if(timeattack[player] == 2) {
						rot_relay_record[tc[player] + player * 3] = gameTimer[player];
						gameTimer[player] = 0;
					} else {
						rot_relay_record[tc[player] + player * 3] = sc[player];
						sc[player] = 0;
					}
					
					if(tc[player] >= 2) {
						ending[player] = 3;
						onRecord[player] = 0;
						
						for(i = 0; i < 3; i++) {
							if(timeattack[player] == 2) {
								gameTimer[player] = gameTimer[player] + rot_relay_record[i + player * 3];
							} else {
								sc[player] = sc[player] + rot_relay_record[i + player * 3];
							}
						}
					} else {
						ending[player] = 0;
						tc[player]++;
						bgfadesw = 1;
						hold[player] = -1;
						dhold[player] = 0;
						
						if(timeattack[player] == 2) {
							c_norm[player] = 0;
						} else {
							ltime[player] = 7200;
						}
						
						stat[player] = 42;
					}
				} else {
					// �ʏ�
					ending[player] = 3;
				}
			} else if(gameMode[player] == 18) {
				// MARATHON
				ending[player] = 3;
			} else if(ending[player] == 1) {
				// �X�^�b�t���[���J�n
				ending[player] = 2;
				
				// MASTER��20G�ł̓t�B�[���h�^�C�}�[����
				if( (gameMode[player] == 1) || (gameMode[player] == 2) ) {
					if(gmflag_r[player]) {
						// �������[��
						hidden[player] = 2;
					} else {
						// �������[��
						hidden[player] = 1;
						
						// HARD�ōD���т̏ꍇ�͌����鎞�Ԕ���
						if((gradetype[player] == 1) && (grade[player] >= 23))
							shadowtime[player] = 150;
					}
				}
				
				// DEVIL�ł͋���BIG #LITE11
				if((gameMode[player] == 3) || (gameMode[player] == 16)) {
					IsBig[player] = 1;
					BigMove[player] = 1;
					n_bx[player] = 2;
				}
				
				// FINAL�ł͏������[��
				if(gameMode[player] == 14) {
					hidden[player] = 2;
				}
				
				// FLASH�ł̓G���f�B���O�p�X�e�[�W�ǂݍ���
				if(gameMode[player] == 15) {
					loadTomoyoStage(player, 100, 1 + flash_edit[player]);
				}
				
				// BGM�Đ�
				if(!onRecord[1 - player]) {
					bgmlv = 6 + (gameMode[player] == 0);
					changeBGM();
				}
			} else {
				// ���؂�
				ending[player] = 5;
			}
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
		} else {
			statc[player * 10]++;
			statc[player * 10 + 1]++;
		}
		return;
	
	// �G���f�B���O2 �X�^�b�t���[���J�n
	lstart:
		ending_timeOn[player] = 1;
		stat[player] = 6;
		statc[player * 10] = 0;
		statc[player * 10 + 1] = 0;
		return;
	
	// �G���f�B���O3 EXCELLENT���
	lclear:
		statc[player * 10]++;
		onRecord[player] = 0;
		
		// ���v���C�Z�[�u
		ReplaySaveCheck(player, 1);
		
		if(statc[player * 10 + 1]) {
			sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 1]);
			printFont(boffset[player], 26, string[0], 5);
		}
		
		// �ԉ�
		if( (statc[player * 10] % 10 == 0) && (endingcnt[player] < 30) ) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
			endingcnt[player]++;
		}
		
		// �t�B�[���h�ʒu��߂�
		fmirror_cnt[player] = -20;
		ofs_x[player] = 0;
		ofs_y[player] = 0;
		
		if((gameMode[player] == 8) && (mission_clear_anim == 0)) {
			// CLEAR!!
			ExBltRect(3, foffset[player] - 7, 96, 195, 230, 109, 20);
			
			if((gameMode[player] == 8) && (!statc[player * 10 + 2])) {
				PlaySE(7);	// missionclr.wav
				statc[player * 10 + 2] = 1;
			}
		} else if( (((gameMode[player] == 1) || (gameMode[player] == 2)) && (grade[player] >= 32)) || 
		           (((gameMode[player] == 1) || (gameMode[player] == 2)) && (gradetype[player] == 2)) || 
		           ((gameMode[player] == 8) && (mission_clear_anim == 1)) || 
		           ((gameMode[player] == 12) && (timeattack[player] == 2)) || 
		           ((gameMode[player] == 16) && (grade[player] >= 14)) )
		{
			// YOU ARE GRAND MASTER!!
			if(statc[player * 10] < 64) {
				k = 128 - statc[player * 10];
				i = (80 * k / 64 - 80) / 2;
				j = (36 * k / 64 - 36) / 2;
				k = 65536 * k / 64;
				ExBltRectR(3, foffset[player] + 8 - i, 102 - j, 208, 126, 80, 36, k, k);
			} else {
				ExBltRect(3, foffset[player] + 8, 102, 208, 126, 80, 36);
			}
		} else if( ((gameMode[player] == 3) && (grade[player] >= 14)) || 
		           ((gameMode[player] == 8) && (mission_clear_anim == 2)) || 
		           ((gameMode[player] == 12) && (timeattack[player] == 3)) || 
		           (gameMode[player] == 14) )
		{
			// YOU ARE GOD
			if(statc[player * 10] < 64) {
				k = 128 - statc[player * 10];
				i = (112 * k / 64 - 112) / 2;
				j = (66 * k / 64 - 66) / 2;
				k = 65536 * k / 64;
				ExBltRectR(3, foffset[player] - 7 - i, 70 - j, 191, 163, 112, 66, k, k);
			} else {
				ExBltRect(3, foffset[player] - 7, 70, 191, 163, 112, 66);
			}
		} else if(gameMode[player] == 15) {
			// FLASH���[�h
			printFont(boffset[player] - 3, 10, "CONGRATULATIONS!", 7);
			
			printFont(boffset[player] + 2, 13, "GIVE UP", 2);
			printFont(boffset[player] + 2, 16, "YOU ARE", 2);
			printFont(boffset[player] + 3, 18, "CHAMP!", 2);
			
			printFont(boffset[player], 20, "SPECIAL", 3);
			printFont(boffset[player] + 5, 21, "BONUS", 3);
			
			sprintf(string[0], "%d PTS", 100000 + ltime[player]);
			printFont(boffset[player], 23, string[0], 3);
		} else if(gameMode[player] == 17) {
			// SIMPLE���[�h
			if(timeattack[player] >= 2) {
				rots[player] = start_rots[player];
				setNextBlockColors(player, 1);
			}
			statc[player * 10] = 600;
		} else {
			// EXCELLENT
			if(statc[player * 10] <= 5){
				k = 10 - statc[player * 10];
				i = (75 * k / 5 - 75) / 2;
				j = (9 * k / 5 - 9) / 2;
				k = 65536 * k / 5;
				ExBltRectR(3, foffset[player] + 10 - i, 96 - j, 212, 73, 75, 9, k, k);
			} else {
				ExBltRect(3, foffset[player] + 10, 96, 212, 73, 75, 9);
			}
			
			if(gameMode[player] != 8) {
				getModeName(player);
				printFont(boffset[player], 14, string[0], 0);
				printFont(boffset[player] + 6, 15, "MODE", 0);
				printFont(boffset[player], 16, "ALL CLEAR", 0);
			}
		}
		
		if(statc[player * 10] >= 600) {
			if(!onRecord[1 - player]) StopAllBGM();
			stat[player] = 7;
			statc[player * 10] = 0;
			statc[player * 10 + 1] = 0;
			statc[player * 10 + 2] = 0;
		}
		return;
	
	// �G���f�B���O5 ���؂�
	lretry:
		statc[player * 10]++;
		onRecord[player] = 0;
		
		// ���v���C�Z�[�u
		ReplaySaveCheck(player, 1);
		
		if(statc[player * 10 + 1]) {
			sprintf(string[0], "SAVED:  %02d", statc[player * 10 + 1]);
			printFont(boffset[player], 26, string[0], 5);
		}
		
		// �t�B�[���h�ʒu��߂�
		fmirror_cnt[player] = -20;
		ofs_x[player] = 0;
		ofs_y[player] = 0;
		
		if(gameMode[player] == 8) {
			// CLEAR
			ExBltRect(3, foffset[player] - 7, 96, 195, 250, 109, 20);
		} else {
			// EXCELLENT
			if(statc[player * 10] <= 5){
				k = 10 - statc[player * 10];
				i = (75 * k / 5 - 75) / 2;
				j = (9 * k / 5 - 9) / 2;
				k = 65536 * k / 5;
				ExBltRectR(3, foffset[player] + 10 - i, 96 - j, 212, 73, 75, 9, k, k);
			} else {
				ExBltRect(3, foffset[player] + 10, 96, 212, 73, 75, 9);
			}
		}
		
		if(statc[player * 10] < 220) {
			// �ԉ�
			if((statc[player * 10] % 40 == 0) && (endingcnt[player] < 4)) {
				objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
				endingcnt[player]++;
			}
			
			// �{�^���ŃX�L�b�v
			if(getPushState(player, 4)) {
				statc[player * 10] = 220;
			}
		} else {
			if((statc[player * 10] == 220) || (statc[player * 10] == 221))
				objectClearPl(player);	// �ԉ΂�����
			
			if(gameMode[player] == 8) {
				printFont(boffset[player] + 1, 15, "BUT...", 0);
				printFont(boffset[player] + 1, 16, "LAST", 0);
				printFont(boffset[player] + 1, 17, "ERASE", 0);
				printFont(boffset[player] + 1, 18, "2 LINES", 0);
			} else if( ((gameMode[player] == 1) || (gameMode[player] == 2)) && (gradetype[player] == 2) ) {
				printFont(boffset[player] + 1, 15, "TRY AGAIN", 0);
				printFont(boffset[player] + 2, 16, "TO BE A", 0);
				printFont(boffset[player] - 1, 17, "GRAND MASTER", 0);
			} else {
				printFont(boffset[player] + 1, 14, "BUT...", 0);
				printFont(boffset[player] + 1, 15, "LET'S GO", 0);
				printFont(boffset[player] + 1, 16, "BETTER", 0);
				printFont(boffset[player] + 1, 17, "NEXT TIME", 0);
			}
			
			// �{�^���ŃX�L�b�v
			if(getPushState(player, 4)) {
				statc[player * 10] = 600;
			}
			
			if(statc[player * 10] >= 600) {
				if(!onRecord[1 - player]) StopAllBGM();
				stat[player] = 7;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
			}
		}
		return;
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.15 - ���肠����
//������������������������������������������������������������������������������
// statc[0 + player * 10]�F�I����Ɉړ�����X�e�[�^�X
// statc[1 + player * 10]�F�ŏ��̃t���[�����ǂ���
void statRiseLine(int player) {
	if((repversw >= 7) && (!statc[1 + player * 10])) {
		// ������
		padRepeat(player);
		
		// �VIRS
		if(ace_irs) doNewIRS(player, 0);
		
		// HYPER����s�ړ�
		if(fastlrmove == 3) HyperLRMove(player);
	}
	
	statc[1 + player * 10] = 0;
	
	if(upLines[player] <= 0) {
		stat[player] = statc[0 + player * 10];
		statc[0 + player * 10] = 0;
	} else {
		UpLineBlockJudge(player);
		pinchCheck(player);
		
		if(upLines[player] <= 0) {
			stat[player] = statc[0 + player * 10];
			statc[0 + player * 10] = 0;
		} else {
			stat[player] = 15;
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.17 - �t�B�[���h�G�f�B�^
//������������������������������������������������������������������������������
// statc[0 + player * 10]�FB�{�^�����������Ƃ��ɖ߂�X�e�[�^�X
// statc[1 + player * 10]�F�I�����Ă���u���b�N
// statc[2 + player * 10]�F�z�u�s�t���O�i��ʂ��؂�ւ�����u�Ԃ����Ȃ�u���b�N��u���Ă��܂��̂�h���j
// statc[3 + player * 10]�F�J�[�\��X���W
// statc[4 + player * 10]�F�J�[�\��Y���W
void statFieldEditor(int player) {
	int i;
	int bx1, by1;
	
	padRepeat(player);
	padRepeat2(player);
	
	// �J�[�\���g�`��
	if(count % 16 < 8)
		ExBltFastRect(30, (statc[3 + player * 10] + boffset[player]) * 8 - 1, (statc[4 + player * 10] + 3) * 8 - 1, 20, 0, 10, 10);
	else
		ExBltFastRect(30, (statc[3 + player * 10] + boffset[player]) * 8 - 1, (statc[4 + player * 10] + 3) * 8 - 1, 10, 0, 10, 10);
	
	// �J�[�\���u���b�N�`��
	drawSingleBlock(player, (statc[3 + player * 10] + boffset[player]) * 8, (statc[4 + player * 10] + 3) * 8,
					0, statc[1 + player * 10], 0, 0, 0, 0, 0);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[4 + player * 10]--;
		if(statc[4 + player * 10] < 1 + tomoyo_rise_edit[player]) statc[4 + player * 10] = 21;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[4 + player * 10]++;
		if(statc[4 + player * 10] > 21) statc[4 + player * 10] = 1 + tomoyo_rise_edit[player];
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
	if( getPressState(player, 2) ) {
		PlaySE(5);
		
		if( getPressState(player, 6) ) {
			// �I���u���b�N�ύX
			statc[1 + player * 10]--;
			if(statc[1 + player * 10] < 0) statc[1 + player * 10] = 16;
		} else {
			// �ړ�
			statc[3 + player * 10]--;
			if(statc[3 + player * 10] < 0) statc[3 + player * 10] = 9;
		}
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) )
	if( getPressState(player, 3) ) {
		PlaySE(5);
		
		if( getPressState(player, 6) ) {
			// �I���u���b�N�ύX
			statc[1 + player * 10]++;
			if(statc[1 + player * 10] > 16) statc[1 + player * 10] = 0;
		} else {
			// �ړ�
			statc[3 + player * 10]++;
			if(statc[3 + player * 10] > 9) statc[3 + player * 10] = 0;
		}
	}
	
	bx1 = statc[3 + player * 10];
	by1 = statc[4 + player * 10];
	
	// �t�B�[���h�G�f�B�b�g
	if(!tomoyo_rise_edit[player]) {
		// A�{�^��
		if( getPressState(player, 4) && !statc[2 + player * 10] ) {
			if( fld[bx1 + by1 * 10 + player * 220] != statc[1 + player * 10] + 1) {
				PlaySE(3);
				fld[bx1 + by1 * 10 + player * 220] = statc[1 + player * 10] + 1;
				fldt[bx1 + by1 * 10 + player * 220] = -1;
				fldi[bx1 + by1 * 10 + player * 220] = 0;
				fldo[bx1 + by1 * 10 + player * 220] = 0;
				flds[bx1 + by1 * 10 + player * 220] = 0;
			}
		}
		
		// HOLD�{�^��
		if( getPressState(player, 7) && !statc[2 + player * 10] ) {
			if( fld[bx1 + by1 * 10 + player * 220] != 0 ) {
				PlaySE(3);
				fld[bx1 + by1 * 10 + player * 220] = 0;
				fldt[bx1 + by1 * 10 + player * 220] = 0;
				fldi[bx1 + by1 * 10 + player * 220] = 0;
				fldo[bx1 + by1 * 10 + player * 220] = 0;
				flds[bx1 + by1 * 10 + player * 220] = 0;
			}
		}
	}
	
	// ����オ��G�f�B�b�g
	if(tomoyo_rise_edit[player]) {
		// A�{�^��
		if( getPressState(player, 4) && !statc[2 + player * 10] ) {
			if( tomoyo_rise_fld[bx1 + (by1 - 2) * 10 + player * 200] != statc[1 + player * 10] + 1) {
				PlaySE(3);
				tomoyo_rise_fld[bx1 + (by1 - 2) * 10 + player * 200] = statc[1 + player * 10] + 1;
			}
		}
		
		// HOLD�{�^��
		if( getPressState(player, 7) && !statc[2 + player * 10] ) {
			if( tomoyo_rise_fld[bx1 + (by1 - 2) * 10 + player * 200] != 0 ) {
				PlaySE(3);
				tomoyo_rise_fld[bx1 + (by1 - 2) * 10 + player * 200] = 0;
			}
		}
	}
	
	// �z�u�s�t���O����
	if( !getPressState(player, 4) && !getPressState(player, 7) ) {
		statc[2 + player * 10] = 0;
	}
	
	// B�{�^��
	if( getPushState(player, 5) ) {
		stat[player] = statc[0 + player * 10];
		for(i = 0; i < 10; i++) statc[i + player * 10] = 0;
		tomoyo_rise_edit[player] = 0;
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.24 - ���v���C�ۑ����
//������������������������������������������������������������������������������
void statReplaySave(int player) {
	int i, color;
	
	color = (count % 4 / 2) * digitc[rots[player]];
	
	if(!statc[player * 10 + 2]) {
		// �����Z�[�u
		if((replay_autosave) && (time2[player] <= 72000) && (!replayauto) && (replayno != 41)) {
			if(gameMode[player] == 4) {
				if(player == 0) {
					saveReplayData(0, 41);
					saveReplayData(1, 41);
				}
			} else {
				saveReplayData(player, 41);
			}
		}
		
		if((replayno == 41) && (playback)) {
			fast = 0;
			replayauto = 0;
		}
		
		// ���v���C�̑��݂𒲂ׂ�
		checkReplayExist();
		
		statc[player * 10 + 2] = 1;
	}
	
	// �J�[�\��
	printFont(boffset[player] + 1, 12 + statc[player * 10] * 2, "b", color);
	
	// ���j���[
	sprintf(string[0], "SAVE %d", statc[player * 10 + 1] + 1);
	printFont(boffset[player] + 2, 12, string[0], (statc[player * 10] == 0) * (time2[player] <= 72000) * color);
	
	if(enable[statc[player * 10 + 1]] != 0) {
		printFont(boffset[player] + 4, 13, "(USED)", (statc[player * 10] == 0) * (time2[player] <= 72000) * color);
	}
	
	if(!playback) printFont(boffset[player] + 2, 14, "RETRY", (statc[player * 10] == 1) * color);
	
	printFont(boffset[player] + 2, 16, "END", (statc[player * 10] == 2) * color);
	
	if(enable[statc[player * 10 + 1]] != 0) {
		sprintf(string[0], "REPLAY %d", statc[player * 10 + 1] + 1);
		printFont(boffset[player], 20, string[0], fontc[rots[player]]);
		
		getModeNameEx(replay_gamemode[statc[player * 10 + 1]], 0);
		printFont(boffset[player] + 1, 21, string[0], modecolor[replay_gamemode[statc[player * 10 + 1]]]);
		
		getRuleNameEx(replay_rots[statc[player * 10 + 1]], 0);
		printFont(boffset[player] + 1, 22, string[0], fontc[replay_rots[statc[player * 10 + 1]]]);
		
		getTimeEx(replay_time[statc[player * 10 + 1]], 0, 0);
		printFont(boffset[player] + 1, 23, string[0], 0);
	}
	
	// �L�[����
	padRepeat(player);
	padRepeat2(player);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10]--;
		if((statc[player * 10] == 1) && (playback)) statc[player * 10] = 0;
		if(statc[player * 10] < 0) statc[player * 10] = 2;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10]++;
		if((statc[player * 10] == 1) && (playback)) statc[player * 10] = 2;
		if(statc[player * 10] > 2) statc[player * 10] = 0;
	}
	
	// ��
	if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		if(statc[player * 10] == 0) {
			PlaySE(3);
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 39;
		}
	}
	
	// ��
	if( (mpc[player] == 1) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		if(statc[player * 10] == 0) {
			PlaySE(3);
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 39) statc[player * 10 + 1] = 0;
		}
	}
	
	// A�{�^��
	if( getPushState(player, 4) ) {
		if(statc[player * 10] == 0) {
			// SAVE
			if(time2[player] <= 72000) {
				PlaySE(10);
				
				if(gameMode[player] == 4) {
					saveReplayData(0, statc[player * 10 + 1] + 1);
					saveReplayData(1, statc[player * 10 + 1] + 1);
				} else {
					saveReplayData(player, statc[player * 10 + 1] + 1);
				}
				
				checkReplayExist();
			}
		} else if(statc[player * 10] == 1) {
			// RETRY
			PlaySE(10);
			
			if(gameMode[player] == 5) {
				// PRACITCE
				PracticeOver();
			} else {
				// ����ȊO
				if(!onRecord[1 - player]) {
					backno = 0;
					back_acnt = 0;
				}
				
				versusInit(player);
				playerInitial(player);
				
				if(gameMode[player] == 4) {
					// VERSUS
					versusInit(1 - player);
					playerInitial(1 - player);
					
					for(i = 0; i < 2; i++) {
						stat[i] = 9;
						statc[i * 10] = 0;
						statc[i * 10 + 1] = 0;
						statc[i * 10 + 2] = 0;
					}
					
					backno = 15;
					resetVersusMode();
				} else if(gameMode[player] == 8) {
					// MISSION
					stat[player] = 22;
					statc[player * 10] = 0;
					statc[player * 10 + 1] = 0;
					statc[player * 10 + 2] = 0;
				} else {
					// ����ȊO
					stat[player] = 2;
					statc[player * 10] = 0;
					statc[player * 10 + 1] = 0;
					statc[player * 10 + 2] = 0;
					
					// BIG�Ƃ����ێ�����Ȃ��̂ł܂��R�����g�A�E�g���
					//startGame(player, lastmode[player], lasttype[player], 0);
				}
			}
		} else if(statc[player * 10] == 2) {
			// END
			if(!onRecord[1 - player]) {
				RankingProc(gameMode[player]);
				flag = 1;
			} else {
				PlaySE(10);
				stat[player] = 0;
				statc[player * 10] = 0;
				statc[player * 10 + 1] = 0;
				statc[player * 10 + 2] = 0;
			}
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.25 - ��莞�ԉ������Ȃ�
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�҂�����
// statc[player * 10 + 1]�F�҂����ԏI����Ɉړ�����X�e�[�^�X
void statNothing(int player) {
	int i;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	statc[player * 10 + 2]++;
	
	if(statc[player * 10 + 2] >= statc[player * 10 + 0]) {
		stat[player] = statc[player * 10 + 1];
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.26 - �u���b�N���ォ��w�肵�����C������������
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F�I����Ɉړ�����X�e�[�^�X
// statc[player * 10 + 2]�F�������C����
// statc[player * 10 + 3]�F���ɏ����������C����
void statExtraErase(int player) {
	int i, j, k;
	
	padRepeat(player);
	if(ace_irs) doNewIRS(player, 0);
	if(fastlrmove == 3) HyperLRMove(player);
	
	if((statc[player * 10] > -100 + wait1[player]) && (statc[player * 10] < 0) && (gameMode[player] != 6)) {
		statc[player * 10]++;
		return;
	}
	
	if(statc[player * 10] == 0) {
		// �ǂ�������������߂�
		statc[player * 10] = checkFieldTop(player) * 6;
		return;
	}
	
	// �u���b�N������
	if(statc[player * 10] % 6 == 0) {
		j = statc[player * 10] / 6;
		
		if((j >= 0) && (j < 22)) {
			for(i = 0; i < 10; i++) {
				if(fld[i + j * 10 + player * 220]) {
					if(fldo[i + j * 10 + player * 220] == 0) {
						objectCreate(player, 1, (i + boffset[player]) * 8, (j + 3) * 8, (i - 5) * 120 + 20 - Rand(40), -1900 + Rand(150) + 1 * 250, fld[i + j * 10 + player * 220] - 1, 100);
					}
					fld[i + j * 10 + player * 220] = 0;
					fldt[i + j * 10 + player * 220] = 0;
					fldi[i + j * 10 + player * 220] = 0;
					fldo[i + j * 10 + player * 220] = 0;
					flds[i + j * 10 + player * 220] = 0;
				}
			}
		}
		
		statc[player * 10 + 3]++;	// ���������C����+1
	}
	
	// �A�j���I������
	if((statc[player * 10] >= 0) && ((statc[player * 10 + 3] >= statc[player * 10 + 2]) || (statc[player * 10] / 6 >= 22)))
		statc[player * 10] = -160;
	
	if((gameMode[player] == 6) && (statc[player * 10] >= 129)) statc[player * 10] = -100;
	
	// �A�j���I������
	if(statc[player * 10] == -100) {
		pinchCheck(player);
		stat[player] = statc[player * 10 + 1];
		for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
		return;
	}
	
	statc[player * 10]++;
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.38 - STANDARD���[�h�Z���N�g���
//������������������������������������������������������������������������������
void statStandardSelect(int player) {
	int i;
	
	// �f�t�H���g�ݒ��ǂݍ���
	if(!statc[player * 10 + 2]) {
		loadWait(player, p_def_setting);
		statc[player * 10 + 1] = p_def_setting;
		statc[player * 10 + 2] = 1;
	}
	
	// ��ʕ\��
	printFont(boffset[player], 5, "SETUP", fontc[rots[player]]);
	
	sprintf(string[0], "%s%2d", delayname[0 + english * 4], wait1[player]);
	printFont(boffset[player],  6, string[0], count % 9 * (statc[player * 10] == 0));
	sprintf(string[0], "%s%2d", delayname[1 + english * 4], wait2[player]);
	printFont(boffset[player],  7, string[0], count % 9 * (statc[player * 10] == 1));
	sprintf(string[0], "%s%2d", delayname[2 + english * 4], wait3[player]);
	printFont(boffset[player],  8, string[0], count % 9 * (statc[player * 10] == 2));
	sprintf(string[0], "%s%2d", delayname[3 + english * 4], waitt[player]);
	printFont(boffset[player],  9, string[0], count % 9 * (statc[player * 10] == 3));
	sprintf(string[0], "SPEED %4d", sp[player]);
	printFont(boffset[player], 10, string[0], count % 9 * (statc[player * 10] == 4));
	sprintf(string[0], "BGM     %2d", bgmlv + 1);
	printFont(boffset[player], 11, string[0], count % 9 * (statc[player * 10] == 5));
	
	printFont(boffset[player], 13, "FAVORITES", fontc[rots[player]]);
	printFont(boffset[player], 14, waitname[statc[player * 10 + 1]], count % 9 * (statc[player * 10] == 6));
	
	if(statc[player * 10] == 6) {
		printFont(boffset[player], 22, "PRESS A TO", fontc[rots[player]]);
		printFont(boffset[player], 23, "LOAD SETUP", fontc[rots[player]]);
	} else {
		printFont(boffset[player], 22, "PRESS A TO", fontc[rots[player]]);
		printFont(boffset[player], 23, "START GAME", fontc[rots[player]]);
	}
	
	// �L�[����
	padRepeat(player);
	padRepeat2(player);
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 0) ) {
		PlaySE(5);
		statc[player * 10]--;
		if(statc[player * 10] < 0) statc[player * 10] = 6;
	}
	
	// ��
	if( (mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 1) ) {
		PlaySE(5);
		statc[player * 10]++;
		if(statc[player * 10] > 6) statc[player * 10] = 0;
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 2) ) {
		PlaySE(3);
		
		// SYUTUGEN
		if(statc[player * 10] == 0) {
			wait1[player]--;
			if(wait1[player] < 0) wait1[player] = 99;
		}
		// SYOUKYO
		if(statc[player * 10] == 1) {
			wait2[player]--;
			if(wait2[player] < 0) wait2[player] = 99;
		}
		// SETTYAKU
		if(statc[player * 10] == 2) {
			wait3[player]--;
			if(wait3[player] < 0) wait3[player] = 99;
		}
		// YOKOTAME
		if(statc[player * 10] == 3) {
			waitt[player]--;
			if(waitt[player] < 0) waitt[player] = 99;
		}
		// SPEED
		if(statc[player * 10] == 4) {
			sp[player]--;
			if(sp[player] < 0) sp[player] = 1200;
		}
		// BGM
		if(statc[player * 10] == 5) {
			bgmlv--;
			if(bgmlv < 0) bgmlv = 20;
		}
		// FAVORITES
		if(statc[player * 10] == 6) {
			i = 0;	// �������[�v�h�~�p
			
			do {
				statc[player * 10 + 1]--;
				
				if(statc[player * 10 + 1] < 0) {
					if(i == 0) {
						statc[player * 10 + 1] = 19;
						i = 1;
					} else {
						statc[player * 10 + 1] = 0;
						break;
					}
				}
			} while(favorites_isempty(statc[player * 10 + 1]));
		}
	}
	
	// ��
	if( (mpc[player] == 1 ) || ((mpc[player] > tame1) && (mpc[player] % tame2 == 0)) || getPressState(player, 6) )
	if( getPressState(player, 3) ) {
		PlaySE(3);
		
		// SYUTUGEN
		if(statc[player * 10] == 0) {
			wait1[player]++;
			if(wait1[player] > 99) wait1[player] = 0;
		}
		// SYOUKYO
		if(statc[player * 10] == 1) {
			wait2[player]++;
			if(wait2[player] > 99) wait2[player] = 0;
		}
		// SETTYAKU
		if(statc[player * 10] == 2) {
			wait3[player]++;
			if(wait3[player] > 99) wait3[player] = 0;
		}
		// YOKOTAME
		if(statc[player * 10] == 3) {
			waitt[player]++;
			if(waitt[player] > 99) waitt[player] = 0;
		}
		// SPEED
		if(statc[player * 10] == 4) {
			sp[player]++;
			if(sp[player] > 1200) sp[player] = 0;
		}
		// BGM
		if(statc[player * 10] == 5) {
			bgmlv++;
			if(bgmlv > 20) bgmlv = 0;
		}
		// FAVORITES
		if(statc[player * 10] == 6) {
			i = 0;	// �������[�v�h�~�p
			
			do {
				statc[player * 10 + 1]++;
				
				if(statc[player * 10 + 1] > 19) {
					if(i == 0) {
						statc[player * 10 + 1] = 0;
						i = 1;
					} else {
						statc[player * 10 + 1] = 0;
						break;
					}
				}
			} while(favorites_isempty(statc[player * 10 + 1]));
		}
	}
	
	// �V���[�g�J�b�g�L�[�������ꂽ��Ή�����ݒ��ǂݍ���
	for(i = 0; i < 20; i++) {
		if( IsPushKey(waitkey[i]) ) {
			PlaySE(3);
			loadWait(player, i);
		}
	}
	
	// B�{�^��
	if( getPushState(player, 5) ) {
		tc[player] = -1;
		stat[player] = 1;				// �u���b�N�V���b�^�[���s
		statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 2;		// �V���b�^�[��̓X�e�[�^�XNo.2
		return;
	}
	
	// A�{�^��
	if( getPushState(player, 4) ) {
		if(statc[player * 10] == 6) {
			PlaySE(3);
			loadWait(player, statc[player * 10 + 1]);
		} else {
			PlaySE(10);
			start_bgmlv[player] = bgmlv;
			stat[player] = 1;				// �u���b�N�V���b�^�[���s
			statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
			statc[player * 10 + 1] = 3;		// �V���b�^�[��̓X�e�[�^�XNo.3
			return;
		}
	}
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.40 - �i�ʔF�莎��
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�J�E���^
// statc[player * 10 + 1]�F0�Ȃ�J�n�錾�A1�Ȃ猋�ʔ��\�A����ȊO�Ȃ�b��i�ʕ\��
// statc[player * 10 + 2]�F�ԉ΂��オ������
void statExamination(int player) {
	int i, k, tmp, draw_rate;
	
	// �J�n�錾
	if(statc[player * 10 + 1] == 0) {
		// �v���v���J�n
		if(statc[player * 10 + 0] == 0) {
			if(examination[player] == 1) PlaySE(14);
			else PlaySE(49);
			purupuru[player] = 1;
		}
		// �v���v�������
		else if(statc[player * 10 + 0] == 110) {
			PlaySE(45);
			ofs_x[player] = 0;
			purupuru[player] = 0;
		}
		// �����w��
		else if(statc[player * 10 + 0] > 110) {
			// A PROMOTIONAL EXAM
			if(statc[player * 10 + 0] < 170) {
				ExBltRectR(49, foffset[player] - 2 - ((100 * 22 / 12 - 100) / 2), 80, 200, 100 + 25 * (count % 4 / 2), 100, 25, 65536 * 22 / 12, 65536 * 22 / 12);
			} else if(statc[player * 10 + 0] < 192) {
				k = 192 - statc[player * 10 + 0];
				i = (100 * k / 12 - 100) / 2;
				k = 65536 * k / 12;
				if(k < 65536) {
					k = 65536;
					i = 0;
				}
				
				ExBltRectR(49, foffset[player] - 2 - i, 48 + 192 - statc[player * 10 + 0] , 200, 100 + 25 * (count % 4 / 2), 100, 25, k, k);
			} else {
				ExBltRect(49, foffset[player] - 2, 48, 200, 100 + 25 * (count % 4 / 2), 100, 25);
			}
			
			// �ڕW�i�ʂ̕\��
			if(statc[player * 10 + 0] > 210) {
				if(!english) ExBltRect(49, foffset[player] - 2, 74, 200, 180, 100, 20);
				else printFont(boffset[player], 10, "EXAM GRADE", 0);
				
				drawGradeImage(foffset[player] + 2, 100, exam_grade[player], 0);
			}
		}
		
		// �Q�[���J�n
		if(statc[player * 10 + 0] > 360) {
			timelimit[0 + player * 2] = 0;	// ���؂薳��
			stat[player] = 3;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
			return;
		}
	}
	// ���ʔ��\
	else if(statc[player * 10 + 1] == 1) {
		// �v���v���J�n
		if(statc[player * 10 + 0] == 0) {
			purupuru[player] = 1;
		}
		// �v���v�������
		else if(statc[player * 10 + 0] == 60) {
			PlaySE(45);
			ofs_x[player] = 0;
			purupuru[player] = 0;
		}
		// ���ʔ��\
		else if(statc[player * 10 + 0] > 60) {
			if(!english) ExBltRect(49, foffset[player] - 2, 48, 200, 150, 100, 30);
			else printFont(boffset[player] + 2, 6, "RESULT", 0);
			
			// �ڕW�i�ʂ̕\��
			if(statc[player * 10 + 0] > 90) {
				if(!english) ExBltRect(49, foffset[player] - 2, 74, 200, 180, 100, 20);
				else printFont(boffset[player], 10, "EXAM GRADE", 0);
				
				drawGradeImage(foffset[player] + 2, 100, exam_grade[player], 0);
			}
			
			// �����傫����΃��[���b�g���o���Ƃ΂�
			if(statc[player * 10 + 0] == 150) {
				if((abs(exam_grade[player] - grade[player]) > 3) || (grade[player] == 32))
					statc[player * 10 + 0] = 350;
			}
			
			// ���[���b�g
			if((statc[player * 10 + 0] > 150) && (statc[player * 10 + 0] < 350)) {
				if((statc[player * 10 + 0] % 5 == 0) && (statc[player * 10 + 0] < 320))
					PlaySE(5);
				
				if((statc[player * 10 + 0] % 10 < 5) || (statc[player * 10 + 0] >= 320)) {
					// �s���i
					if(!english) ExBltRect(49, foffset[player] + 13, 162, 215, 250, 70, 25);
					else printFont(boffset[player] + 2, 20, "FAILED", 0);
				} else {
					// ���i
					if(!english) ExBltRect(49, foffset[player] + 13, 162, 215, 200, 70, 25);
					else printFont(boffset[player] + 1, 20, "SUCCESS!", 0);
				}
			}
			
			// �m�肵���u��
			if(statc[player * 10 + 0] == 350) {
				// ���i
				if(grade[player] >= exam_grade[player]) {
					PlaySE(18);
					
					if(examination[player] == 1) {
						PlaySE(31);
						user_master_hard_admit[player] = exam_grade[player];
					}
				}
				// �s���i
				else {
					PlaySE(44);
					
					if(examination[player] == 2) {
						user_master_hard_admit[player] = exam_grade[player];
					}
				}
			}
			
			// �m���
			if(statc[player * 10 + 0] >= 350) {
				// ���i
				if(grade[player] >= exam_grade[player]) {
					if(!english) ExBltRect(49, foffset[player] + 13, 162, 215, 200 + 25 * (count % 4 / 2), 70, 25);
					else printFont(boffset[player] + 1, 20, "SUCCESS!", 7 * (count % 4 / 2));
					
					// �ԉΔ���
					if((statc[player * 10 + 0] % 10 == 0) && (statc[player * 10 + 2] < 20)) {
						objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
						statc[player * 10 + 2]++;
					}
				}
				// �s���i
				else {
					if(!english) ExBltRect(49, foffset[player] + 13, 162, 215, 250 + 25 * (count % 4 / 2), 70, 25);
					else printFont(boffset[player] + 2, 20, "FAILED", 2 * (count % 4 / 2));
				}
			}
			
			// �b��i�ʂ̉�ʂ�
			if(statc[player * 10 + 0] >= 720) {
				statc[player * 10 + 0] = 0;
				statc[player * 10 + 1] = 2;
				statc[player * 10 + 2] = 0;
				return;
			}
		}
	}
	// �b��i�ʕ\��
	else {
		tmp = 300;
		
		// ���Ȃ��̎b��i�ʂ�
		if(statc[player * 10 + 0] == 0) {
			if(screenMode >= 2) draw_rate = 2;
			else draw_rate = 1;
			
			TextSize(player, 10 * draw_rate);
			TextColor(player, 255, 255, 255);
			TextBackColorDisable(player);
			TextOut(player, yourgrade[english + 2]);
			TextLayerOn(player, (foffset[player] + 3) * draw_rate, 92 * draw_rate);
		}
		
		drawGradeImage(foffset[player] + 2, 108, grade[player], 0);
		
		// �{�^���ŃX�L�b�v
		if(getPushState(player, 4)) {
			tmp = 60;
		}
		
		// �I��
		if(statc[player * 10 + 0] >= tmp) {
			TextLayerOff(player);
			user_master_hard_grade_pasttime[player] = 0;	// �O�̎�������̌o�ߎ��Ԃ����Z�b�g
			stat[player] = 11;
			for(i = 0; i < 10; i++) statc[player * 10 + i] = 0;
			return;
		}
	}
	
	statc[player * 10 + 0]++;
}

//������������������������������������������������������������������������������
//  �X�e�[�^�XNo.42 - ROT. RELAY�̎��̃��[���I��
//������������������������������������������������������������������������������
// statc[player * 10 + 0]�F�������ς݃t���O
// statc[player * 10 + 1]�F�J�[�\���ʒu
// statc[player * 10 + 2]�F�^�C��
void statRotRelaySelectRule(int player) {
	int i, color2;
	
	// ������
	if(repversw >= 7) padRepeat(player);
	
	// ������
	if(statc[player * 10 + 0] == 0) {
		statc[player * 10 + 0] = 1;
		
		// ���[���g�p�ς݃t���OON
		rot_used_flag[rots[player] + player * 10] = 1;
		
		// �J�[�\���ʒu�ݒ�
		statc[player * 10 + 1] = rots[player];
		while(rot_used_flag[statc[player * 10 + 1] + player * 10]) {
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 9) statc[player * 10 + 1] = 0;
		}
		
		statc[player * 10 + 2] = 600;
	}
	
	color2 = (count % 4 / 2) * fontc[statc[player * 10 + 1]];
	padRepeat2(player);
	
	// ���[���ꗗ�\��
	printFont(boffset[player], 6, "SELECT", fontc[statc[player * 10 + 1]]);
	printFont(boffset[player] + 1, 7, "ROT. RULE", fontc[statc[player * 10 + 1]]);
	
	printFont(boffset[player], 9 + statc[player * 10 + 1], "b", color2);
	
	for(i = 0; i < 10; i++) {
		if(!rot_used_flag[i + player * 10]) {
			getRuleNameEx(i, 0);
			printFont(boffset[player] + 1, 9 + i, string[0], (statc[player * 10 + 1] == i) * color2);
		}
	}
	
	printFont(boffset[player] + 1, 22, "TIME", fontc[statc[player * 10 + 1]]);
	statc[player * 10 + 2]--;
	sprintf(string[0], "%d", (statc[player * 10 + 2] / 60));
	printFont(boffset[player] + 8, 22, string[0], 0);
	
	// �L�[����
	// ��
	if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
	if(getPressState(player, 0)) {
		PlaySE(5);
		
		do {
			statc[player * 10 + 1]--;
			if(statc[player * 10 + 1] < 0) statc[player * 10 + 1] = 9;
		} while(rot_used_flag[statc[player * 10 + 1] + player * 10]);
	}
	
	// ��
	if((mpc2[player] == 1) || ((mpc2[player] > tame3) && (mpc2[player] % tame4 == 0)) || getPressState(player, 6))
	if(getPressState(player, 1)) {
		PlaySE(5);
		
		do {
			statc[player * 10 + 1]++;
			if(statc[player * 10 + 1] > 9) statc[player * 10 + 1] = 0;
		} while(rot_used_flag[statc[player * 10 + 1] + player * 10]);
	}
	
	// ����
	if(getPushState(player, 4) || (statc[player * 10 + 2] <= 0)) {
		PlaySE(10);
		rots[player] = statc[player * 10 + 1];
		setNextBlockColors(player, 1);
		stat[player] = 1;				// �u���b�N�V���b�^�[���s
		statc[player * 10] = 0;			// �X�e�[�^�X�J�E���^��0��
		statc[player * 10 + 1] = 3;		// �V���b�^�[��̓X�e�[�^�XNo.3
	}
}

//������������������������������������������������������������������������������
//   ���s����
//������������������������������������������������������������������������������
void winner() {
	int		player, i, j, block, win, obj, c;

	timeOn[0] = 0;
	timeOn[1] = 0;
	onRecord[0] = 0;
	onRecord[1] = 0;
	
	gameTimer[1] = gameTimer[0];
	
	ofs_x[0] = 0;
	ofs_y[0] = 0;
	ofs_x[1] = 0;
	ofs_y[1] = 0;
	
	winc++;
	wink++;
	winu = winu + wink / 4;
	
	StopWave(32);	// �s���`����~
	
	if(winu > 140) {
		winu = 140;
		wink = -20;
	}

	win = (stat[1] == 7) + ((stat[0] == 7) && (stat[1] == 7));

	for(player = 0; player < 2; player++) {
		if(win == player)
			obj = 1;
		else if(win != 2)
			obj = 0;
		else
			obj = 2;
		
		ExBltRect(3, foffset[player] + 6, winu, 96, obj * 25, 86, 24);
		
		// �ԉ�
		if((winc % 10 == 0) && (endingcnt[player] < 10) && (win != player) && (obj != 2)) {
			objectCreate(player, 3, -40 + Rand(80) + foffset[player], 16 + Rand(20), 0, 0, Rand(7), 0);
			endingcnt[player]++;
		}
		
		if( (getPushState(player, 4) && (winr > 20)) || (winc > 60 * 5) ) {
			for(i = 0; i < 2; i++) {
				stat[i] = 1;					// �u���b�N�V���b�^�[���s
				statc[i * 10] = 0;				// �X�e�[�^�X�J�E���^��0��
				statc[i * 10 + 1] = 12;			// �V���b�^�[��̓X�e�[�^�XNo.12
			}
			flag = 0;
			return;
		}
	}
	
	if(winr <= 20) winr++;
}

// VERSUS���[�h�Ŋe��ݒ���o�b�N�A�b�v����߂�
void resetVersusMode() {
	int player;
	
	for(player = 0; player < 2; player++) {
		// ���x���o�b�N�A�b�v����߂�
		sp[player]    = b_sp[player];
		wait1[player] = b_wait1[player];
		wait2[player] = b_wait2[player];
		wait3[player] = b_wait3[player];
		waitt[player] = b_waitt[player];
		
		// CPU�ݒ���o�b�N�A�b�v����߂�
		cpu_flag[player] = b_cpu_flag[player];
		cpu_level[player] = b_cpu_level[player];
		
		// �A�C�e���ݒ���o�b�N�A�b�v����߂�
		item_mode[player] = b_item_mode[player];
		r_enable[player] = b_r_enable[player];
	}
}

//������������������������������������������������������������������������������
//   �s���`���ǂ����`�F�b�N
//������������������������������������������������������������������������������
void pinchCheck(int player) {
	int		i, j;

	pinch[player] = 0;
	
	for(i = 0; i <= 7; i++)
		for(j = 2; j <= 7; j++)
			if(fld[j + i * 7 + player * 220]) {
				pinch[player] = 1;
				break;
			}
}

//������������������������������������������������������������������������������
//   �p�b�h���s�[�g���͏���
//������������������������������������������������������������������������������
void padRepeat(int player) {
	// �Q�[������1�t���[����2��ȏ���s���Ȃ�
	if(onRecord[player]) {
		if((last_mp_check[player] == time2[player]) && (repversw >= 7)) {
			return;
		} else {
			last_mp_check[player] = time2[player];
		}
	}
	
	if(getPressState(player, 2) && getPressState(player, 3)) {
		mp[player] = 0;
		mpc[player] = 0;
	} else if(getPressState(player, 2)) {
		if(mp[player] != 2) {
			mp[player] = 2;
			mpc[player] = 0;
		}
		mpc[player]++;
	} else if(getPressState(player, 3)) {
		if(mp[player] != 3) {
			mp[player] = 3;
			mpc[player] = 0;
		}
		mpc[player]++;
	} else {
		mp[player] = 0;
		mpc[player] = 0;
	}
}

// hoge �㉺���̓o�[�W����
void padRepeat2(int player) {
	if(getPressState(player, 0) && getPressState(player, 1)) {
		mp2[player] = 0;
		mpc2[player] = 0;
	} else if(getPressState(player, 0)) {
		if(mp2[player] != 1) {
			mp2[player] = 1;
			mpc2[player] = 0;
		}
		mpc2[player]++;
	} else if(getPressState(player, 1)) {
		if(mp2[player] != 2) {
			mp2[player] = 2;
			mpc2[player] = 0;
		}
		mpc2[player]++;
	} else {
		mp2[player] = 0;
		mpc2[player] = 0;
	}
}

//������������������������������������������������������������������������������
//   �L�[��Ԃ̎擾
//������������������������������������������������������������������������������
int getPressState(int pl, int key) {
	int player;
	
	if(!maxPlay && pl) return 0;
	
	// �N�����삷�邩���߂�
	if(isremote[pl]) {
		player = !pl;	// �����R��
	} else {
		player = pl;	// �ʏ�
	}
	
	if(!replayauto && onRecord[player]) {
		if(isUDLRreverse[player]) {
			if(key == 0)
				key = 1;
			else if(key == 1)
				key = 0;
			else if(key == 2)
				key = 3;
			else if(key == 3)
				key = 2;
		} else if(isLRreverse[player]) {
			if(key == 2)
				key = 3;
			else if(key == 3)
				key = 2;
		} else if(isUDreverse[player]) {
			if(key == 0)
				key = 1;
			else if(key == 1)
				key = 0;
		}
	}
	
	if(playback && replayauto) {
		// ���v���C
		if(onRecord[player]) {
			if(!player)
				return (replayData[time2[player]] & (1 << key)) / (1 << key);
			else
				return (replayData2[time2[player]] & (1 << key)) / (1 << key);
		}
		
		return 0;
	} else if( (cpu_flag[player]) && (!pause[player]) && ((onRecord[player]) || (stat[player] == 3)) ) {
		// �R���s���[�^
		return cpu_ctrl[key + player * 10];
	} else {
		// �ʏ�
		SelectJoyStick(player);
		
		if(!keyAssign[key + player * 10])
			return IsPressJoyKey(joykeyAssign[key + player * 10]);
		else
			return IsPressJoyKey(joykeyAssign[key + player * 10]) | IsPressKey(keyAssign[key + player * 10]);
	}
}

int getPushState(int pl, int key) {
	int player;
	
	if(!maxPlay && pl) return 0;
	
	// �N�����삷�邩���߂�
	if(isremote[pl]) {
		player = !pl;	// �����R��
	} else {
		player = pl;	// �ʏ�
	}
	
	if(!replayauto && onRecord[player]) {
		if(isUDLRreverse[player]) {
			if(key == 0)
				key = 1;
			else if(key == 1)
				key = 0;
			else if(key == 2)
				key = 3;
			else if(key == 3)
				key = 2;
		} else if(isLRreverse[player]) {
			if(key == 2)
				key = 3;
			else if(key == 3)
				key = 2;
		} else if(isUDreverse[player]) {
			if(key == 0)
				key = 1;
			else if(key == 1)
				key = 0;
		}
	}
	
	if(playback && replayauto) {
		// ���v���C
		if(onRecord[player]) {
			if(!player)
				return (replayData[time2[player]] & (1 << (key + 8))) / (1 << (key + 8));
			else
				return (replayData2[time2[player]] & (1 << (key + 8))) / (1 << (key + 8));
		}
		
		return 0;
	} else if( (cpu_flag[player]) && (!pause[player]) && ((onRecord[player]) || (stat[player] == 3)) ) {
		// �R���s���[�^
		return cpu_ctrl[key + player * 10];
	} else {
		// �ʏ�
		SelectJoyStick(player);
		
		return IsPushJoyKey(joykeyAssign[key + player * 10]) | IsPushKey(keyAssign[key + player * 10]);
	}
}

// ����̃v���C���[�̃W���C�X�e�B�b�N���͂����o����֐��c�̂��� #LITE25
// �����Ɠ������͕s��
int getJoyPressState(int pl, int key) {
	if(!maxPlay && pl) return 0;
	SelectJoyStick(pl);
	return IsPressJoyKey(key);
}

int getJoyPushState(int pl, int key) {
	if(!maxPlay && pl) return 0;
	SelectJoyStick(pl);
	return IsPushJoyKey(key);
}

//������������������������������������������������������������������������������
//   �����ݒ�
//������������������������������������������������������������������������������
void initialize() {
	int i;
	
	SetConstParam("Caption", "HEBORIS LITE - Loading...");
	
	loadScreenConfig();	// SCREEN.SAV�ǂݍ���(screencfg.c)
	
	// �`�悷��𑜓x��ݒ�
	if(screenMode <= 1)
		setDrawRate(1);
	else
		setDrawRate(2);
	
	// �o�[�W�����\��
	TextLayerOn(1, 10, 220);
	TextSize(1, 12);
	TextColor(1, 255, 255, 255);
	TextBackColorDisable(1);
	TextOut(1, version);
	halt;
	
	// CUSTOM�ȊO�̃��[���ݒ�
	setRuleSettingToDefault();
	
	// CONFIG.SAV��ǂݍ���
	first_setting = config_load();
	
	// �O���t�B�b�N��ǂݍ���
	TextMove(1, 10, 10);
	TextOut(1, "Graphics Loading");
	halt;
	
	loadGraphics();
	
	// �t�B�[���h�̕\���ʒu��ݒ�
	setFieldPosition(maxPlay);
	
	// �w�i��ǂݍ���
	if(!skip_viewbg) loadBackground();
	
	// ���ʉ���ǂݍ���
	if(se) {
		TextMove(1, 10, 22);
		TextOut(1, "Sound Effect Loading");
		halt;
		
		loadWaves();
	}
	
	for(i = 0; i < 60; i++) se_play[i] = 0;
	
	// BGM��ǂݍ���
	if((bgm >= 1) && (bgm <= 3)) {
		TextMove(1, 10, 34);
		TextOut(1, "BGM Loading");
		halt;
		
		if(bgm == 1) {
			LoadMIDI("bgm/bgm.mid");
			PlayMIDI();
		} else {
			loadBGM();
		}
	}
	
	// ���ʐݒ�
	resetVolume();
	
	TextLayerOff(1);
	
	// �����L���O�ǂݍ���
	RankingAlloc();
	if( RankingLoad() ) {
		RankingInit();
	}
	
	// �Z�N�V�����^�C�������L���O�ǂݍ���
	ST_RankingAlloc();
	if( ST_RankingLoad() ) {
		ST_RankingInit();
	}
	
	// STANDARD���[�h�p�����L���O�ǂݍ���
	stdRankingAlloc();
	if( stdRankingLoad() ) {
		stdRankingInit();
	}
	
	mission_course_name = new(17);	// 15 + NULL
	StrCpy(mission_course_name, "");
	
	user_name[0] = new(4);
	user_name[1] = new(4);
	StrCpy(user_name[0], "");
	StrCpy(user_name[1], "");
	
	// FAVORITES�ǂݍ���
	favorites_init();
	if( favorites_load() ) {
		favorites_set_default();
	}
	
	// �W���C�X�e�B�b�N�̃{�^����3�ȏ�g���܂���[
	SetJoystickButtonSetting();
	
	SetConstParam("Caption", "HEBORIS LITE");
	SetConstParam("EnablePause", 1);	// ��������|�[�Y�L��
}

// �W���C�X�e�B�b�N�̃{�^�����ݒ�𔽉f������
void SetJoystickButtonSetting() {
	int i;
	
	for(i = 0; i < 2; i++) {
		SelectJoyStick(i);
		SetJoyButtonMax(joykeyButtonNum);
	}
}

// �r�b�g�}�b�v��ǂݍ���
void ExLoadBitmap(str *nameStr, int plane, int unknown) {
	/*
	sprintf(string[0], "graphics/%s", nameStr);
	LoadBitmap(string[0], plane, unknown);
	*/
	
	if(getDrawRate() == 1)
		sprintf(string[0], "graphics/%s", nameStr);
	else
		sprintf(string[0], "graphicshi/%s", nameStr);
	
	LoadBitmap(string[0], plane, unknown);
}

// �w�i�r�b�g�}�b�v��ǂݍ���
void ExLoadBackground(str *nameStr, int plane, int unknown) {
	/*
	sprintf(string[0], "back/%s", nameStr);
	LoadBitmap(string[0], plane, unknown);
	*/
	
	if(getDrawRate() == 1)
		sprintf(string[0], "back/%s", nameStr);
	else
		sprintf(string[0], "backhi/%s", nameStr);
	
	LoadBitmap(string[0], plane, unknown);
}

// �A�j���[�V��������^�C�g���摜��ǂݍ���
void ExLoadTitleAnim() {
	/*
	LoadBitmap("title_mov/logo_low.png", 7, 0);
	LoadBitmap("title_mov/tmov_low.png", 8, 0);
	SetColorKeyRGB(7,0,0,0);
	*/
	
	if(getDrawRate() == 1) {
		LoadBitmap("title_mov/logo_low.png", 7, 0);
		LoadBitmap("title_mov/tmov_low.png", 8, 0);
	} else {
		LoadBitmap("title_mov/logo_hi.png", 7, 0);
		LoadBitmap("title_mov/tmov_hi.png", 8, 0);
	}
	
	SetColorKeyRGB(7,0,0,0);
}

// �O���t�B�b�N�ǂݍ���
void loadGraphics() {
	int i, j, k, tr;
	
	/* �v���[��0�Ƀ��_���G��ǂݍ��� */
	ExLoadBitmap("medal.png", 0, 0);
	
	/* �v���[��1�Ƀt�H���g��ǂݍ��� */
	ExLoadBitmap("hebofont.png", 1, 0);
	SetColorKeyPos(1, 0, 0);
	
	/* �v���[��2�Ƀt�B�[���h��ǂݍ��� */
	ExLoadBitmap("hebofld.png", 2, 0);
	SetColorKeyPos(2, 20, 20);
	
	/* �v���[��3�Ɋe��X�v���C�g��ǂݍ��� */
	ExLoadBitmap("hebospr.png", 3, 0);
	SetColorKeyPos(3, 0, 0);
	EnableBlendColorKey(3, 1);
	
	/* �v���[��4�`5�Ƀ~�b�V�������[�h�p�摜��ǂݍ��� */
	ExLoadBitmap("heboris_road.png", 4, 0);
	ExLoadBitmap("del_field.bmp", 5, 0);
	SetColorKeyRGB(5, 255, 0, 255);
	
	/* �v���[��6�ɃI�[���h�X�^�C���p�摜��ǂݍ��� */
	ExLoadBitmap("heboblk_old.bmp", 6, 0);
	
	/* �v���[��7�`8�Ƀ^�C�g���摜��ǂݍ��� */
	if(!title_mov_f) {	// �Î~��
		ExLoadBitmap("title.png", 8, 0);
	} else {
		ExLoadTitleAnim();
	}
	
	/* �v���[��9��2�{�g��p�T�[�t�F�X */
	//if(screenMode >= 2) CreateSurface(9, 640, 480);
	
	/* �v���[��10�`16�Ƀv���`�i�u���b�N�����G�t�F�N�g��ǂݍ��� */
	ExLoadBitmap("perase1.png", 10, 0);
	ExLoadBitmap("perase2.png", 11, 0);
	ExLoadBitmap("perase3.png", 12, 0);
	ExLoadBitmap("perase4.png", 13, 0);
	ExLoadBitmap("perase5.png", 14, 0);
	ExLoadBitmap("perase6.png", 15, 0);
	ExLoadBitmap("perase7.png", 16, 0);
	
	/* �v���[��17�`19�Ƀ~���[���o�p�摜��ǂݍ��� */
	ExLoadBitmap("mirror_effect.bmp", 17, 0);
	ExLoadBitmap("fldmirror.png", 18, 0);
	ExLoadBitmap("fldmirror2.png", 19, 0);
	
	/* �v���[��20�ɗ��ꐯ��ǂݍ��� */
	ExLoadBitmap("shootingstar.png", 20, 0);
	
	/* �v���[��21�ɒi�ʕ\���p�̉摜��ǂݍ��� */
	ExLoadBitmap("grade.png", 21, 0);
	
	/* �v���[��22�ɑ傫���t�H���g��ǂݍ��� */
	ExLoadBitmap("hebofont3.png", 22, 0);
	
	/* �v���[��23�ɃX�i�b�v�V���b�g�p�v���[�����쐬 */
	//if(screenMode <= 1) CreateSurface(23, 320, 240);
	ExCreateSurface(23, 320, 240);
	
	/* �v���[��24�ɐ^�����t�B�[���h�w�i��ǂݍ��� */
	if(!fldbgtype)
		ExLoadBitmap("heboflb0.bmp", 24, 0);
	else
		ExLoadBitmap("heboflb1.bmp", 24, 0);
	
	/* �v���[��25�`27�Ƀu���b�N�G��ǂݍ��� */
	ExLoadBitmap("heboblk_normal.png", 25, 0);	// ����
	ExLoadBitmap("heboblk_big.png", 26, 0);		// �r�b�O
	ExLoadBitmap("heboblk_small.bmp", 27, 0);	// �k��
	
	/* �v���[��28�Ƀ��[�U�[�p�̉摜��ǂݍ��� */
	ExLoadBitmap("laser.bmp", 28, 0);
	
	/* �v���[��29�ɃA�C�e�������G�t�F�N�g��ǂݍ��� */
	ExLoadBitmap("itemerase.png", 29, 0);
	
	/* �v���[��30�Ƀu���b�N�̘g����ǂݍ��� */
	ExLoadBitmap("heboblkframe.bmp", 30, 0);
	SetColorKeyRGB(30, 0, 0, 0);
	
	/* �v���[��31�`38�Ƀu���b�N�����G�t�F�N�g��ǂݍ��� */
	if(breakeffect == 3) {
		ExLoadBitmap("old_break_effect.png", 31, 0);
	} else if((breakgraphics) && (breakeffect == 2)) {
		ExLoadBitmap("break0.png", 31, 0);
		ExLoadBitmap("break1.png", 32, 0);
		ExLoadBitmap("break2.png", 33, 0);
		ExLoadBitmap("break3.png", 34, 0);
		ExLoadBitmap("break4.png", 35, 0);
		ExLoadBitmap("break5.png", 36, 0);
		ExLoadBitmap("break6.png", 37, 0);
		ExLoadBitmap("break7.png", 38, 0);
		SetColorKeyRGB(31, 0, 0, 0);
		SetColorKeyRGB(32, 0, 0, 0);
		SetColorKeyRGB(33, 0, 0, 0);
		SetColorKeyRGB(34, 0, 0, 0);
		SetColorKeyRGB(35, 0, 0, 0);
		SetColorKeyRGB(36, 0, 0, 0);
		SetColorKeyRGB(37, 0, 0, 0);
		SetColorKeyRGB(38, 0, 0, 0);
	} else if((!breakgraphics) && (breakeffect == 2)) {
		ExLoadBitmap("break0_tap.png", 31, 0);
		ExLoadBitmap("break1_tap.png", 32, 0);
		ExLoadBitmap("break2_tap.png", 33, 0);
		ExLoadBitmap("break3_tap.png", 34, 0);
		ExLoadBitmap("break4_tap.png", 35, 0);
		ExLoadBitmap("break5_tap.png", 36, 0);
		ExLoadBitmap("break6_tap.png", 37, 0);
		ExLoadBitmap("break7_tap.png", 38, 0);
		SetColorKeyRGB(31, 255, 0, 255);
		SetColorKeyRGB(32, 255, 0, 255);
		SetColorKeyRGB(33, 255, 0, 255);
		SetColorKeyRGB(34, 255, 0, 255);
		SetColorKeyRGB(35, 255, 0, 255);
		SetColorKeyRGB(36, 255, 0, 255);
		SetColorKeyRGB(37, 255, 0, 255);
		SetColorKeyRGB(38, 255, 0, 255);
	}
	
	/* �v���[��39�`45�ɉԉ΂�ǂݍ��� */
	ExLoadBitmap("hanabi_red.png",       39, 0);
	ExLoadBitmap("hanabi_orange.png",    40, 0);
	ExLoadBitmap("hanabi_yellow.png",    41, 0);
	ExLoadBitmap("hanabi_green.png",     42, 0);
	ExLoadBitmap("hanabi_waterblue.png", 43, 0);
	ExLoadBitmap("hanabi_blue.png",      44, 0);
	ExLoadBitmap("hanabi_purple.png",    45, 0);
	
	/* �v���[��46�`48�ɓ���u���b�N�̊G��ǂݍ��� */
	ExLoadBitmap("heboblk_sp.png", 46, 0);			// ����
	ExLoadBitmap("heboblk_sp_big.png", 47, 0);		// �r�b�O
	ExLoadBitmap("heboblk_sp_small.bmp", 48, 0);		// �k��
	
	/* �v���[��49�ɕ����摜��ǂݍ��� */
	ExLoadBitmap("text2.png", 49, 0);
	
	/* �v���[��50�ɔw�i�t�F�[�h�p�摜��ǂݍ��� */
	ExLoadBitmap("fade.bmp", 50, 0);
	SetColorKeyRGB(50, 255, 255, 255);
	
	/* �v���[��51�ɈÂ��^�C�g���摜��ǂݍ��� #LITE30.2 */
	ExLoadBitmap("title_dark.png", 51, 0);
	
	/* �v���[��52�ɃI�[���h�X�^�C���r�b�O�摜��ǂݍ��� */
	ExLoadBitmap("heboblk_old_big.bmp", 52, 0);
	
	/* �v���[��53��SHUFFLE FIELD�p�摜��ǂݍ��� */
	ExLoadBitmap("shuffle_field_effect.bmp", 53, 0);
	
	/* �v���[��60�`75�͔w�i */
	
	/* �v���[��76�Ƀi�r�Q�[�V�����u���b�N�G��ǂݍ��� */
	ExLoadBitmap("guide.bmp", 76, 0);
	SetColorKeyRGB(76, 0, 0, 0);
	
	/* �v���[��77�`79�ɑΐ탂�[�h�p�摜��ǂݍ��� */
	ExLoadBitmap("fldmirror3.png", 77, 0);
	ExLoadBitmap("item_guage.bmp", 78, 0);
	SetColorKeyRGB(78, 255, 0, 255);
	ExLoadBitmap("item_name.png", 79, 0);
	SetColorKeyRGB(79, 255, 0, 255);
	
	/* �v���[��80�Ƀ~���[���o�p�摜��ǂݍ��� */
	ExLoadBitmap("fldmirror4.png", 80, 0);
	
	/* �v���[��81�`82�ɃX�^�b�t���[���摜��ǂݍ��� */
	ExLoadBitmap("staffroll.png", 81, 0);
	ExLoadBitmap("staffroll2.png", 82, 0);
	
	/* �v���[��83�Ƀu���b�N�̉e��ǂݍ��� */
	ExLoadBitmap("heboblk_shadow.png", 83, 0);
	
	/* �v���[��84�ɐ^�����摜��ǂݍ��� */
	ExLoadBitmap("heboflb2.bmp", 84, 0);
}

// �w�i�ǂݍ���
void loadBackground() {
	int i, j, k, tr;
	int movframe, max, tmp1, tmp2, tmptr;
	int players, tmp_offset;
	
	/* �v���[��60�`75�Ƀo�b�N��ǂݍ��� */
	ExLoadBackground("back01.png",  60, 0);
	ExLoadBackground("back02.png",  61, 0);
	ExLoadBackground("back03.png",  62, 0);
	ExLoadBackground("back04.png",  63, 0);
	ExLoadBackground("back05.png",  64, 0);
	ExLoadBackground("back06.png",  65, 0);
	ExLoadBackground("back07.png",  66, 0);
	ExLoadBackground("back08.png",  67, 0);
	ExLoadBackground("back09.png",  68, 0);
	ExLoadBackground("back10.png",  69, 0);
	ExLoadBackground("back11.png",  70, 0);
	ExLoadBackground("back12.png",  71, 0);
	if(!background_compatibility) {
		ExLoadBackground("back13.png",  72, 0);
		ExLoadBackground("back14.png",  73, 0);
		ExLoadBackground("back15.png",  74, 0);
	}
	ExLoadBackground("back_vs.png", 75, 0);
	
	/* �w�i���������� */
	tmptr = 256 - fldtr;
	for(i = 60; i <= 75; i++) {
		if((i < 72) || (i > 74) || (!background_compatibility)) {
			SwapToSecondary(i);
			
			if(back_mov_f[i - 60] == 0)
				max = 1;
			else
				max = back_mov_f[i - 60];
			
			for(movframe = 0; movframe < max; movframe++) {
				tmp1 = ((movframe / 10) * 320);
				tmp2 = ((movframe % 10) * 240);
				
				// �v���C���[�������߂�
				if(i == 75) players = 1;
				else players = maxPlay;
				
				for(j = 0; j <= players; j++) {
					// �\���ʒu�����߂�
					if(i == 75) {
						// VERSUS
						tmp_offset = v_foffset[j];
					} else {
						// �ʏ�
						tmp_offset = foffset[j];
					}
					
					
					BlendExBltRect(24, (tmp_offset + 8) + tmp1, 40 + tmp2, 0, 0, 80, 160, tmptr, tmptr, tmptr, fldtr, fldtr, fldtr);
					
					if(top_frame) {
						BlendExBltRect(3, (tmp_offset - 15) + tmp1, tmp2, 127, 268, 126, 35, tmptr, tmptr, tmptr, fldtr, fldtr, fldtr);
					} else {
						// �O���f�[�V�����������Ȃ߂炩��#1.60c7p9ex
						BlendExBltRect(3, tmp_offset + tmp1, tmp2, 101, 128, 100 - 20, 32, tmptr, tmptr, tmptr, fldtr, fldtr, fldtr);
						for(k = 0; k < 20; k++) {
							tr = tmptr * (19 - k) / 20;
							tr = 256 - tr;
							BlendExBltRect(3, tmp_offset + (80 + k) + tmp1, tmp2, 101 + (80 + k), 128, 1, 32, 256 - tr, 256 - tr, 256 - tr, tr, tr, tr);
						}
					}
				}
			}
			SwapToSecondary(i);
		}
	}
}

// ���ʉ��ǂݍ���
void loadWaves() {
	int i;
	
	ReleaseWaveAll();
	
	LoadWave("se/shaki.wav", 0);
	LoadWave("se/kon.wav", 1);
	LoadWave("se/gon.wav", 2);
	LoadWave("se/kachi.wav", 3);
	LoadWave("se/rotate.wav", 4);
	LoadWave("se/move.wav", 5);
	LoadWave("se/missionclr.wav", 7);
	LoadWave("se/gameover.wav", 8);
	LoadWave("se/hold.wav", 9);
	LoadWave("se/kettei.wav", 10);
	LoadWave("se/erase1.wav", 11);
	LoadWave("se/erase2.wav", 12);
	LoadWave("se/erase3.wav", 13);
	LoadWave("se/erase4.wav", 14);
	LoadWave("voice/ready.wav", 15);
	LoadWave("voice/go.wav", 16);
	LoadWave("se/applause.wav", 17);
	LoadWave("se/cheer.wav", 18);
	LoadWave("se/levelup.wav", 19);
	LoadWave("se/up.wav", 20);
	LoadWave("blockse/block1.wav", 21);
	LoadWave("blockse/block2.wav", 22);
	LoadWave("blockse/block3.wav", 23);
	LoadWave("blockse/block4.wav", 24);
	LoadWave("blockse/block5.wav", 25);
	LoadWave("blockse/block6.wav", 26);
	LoadWave("blockse/block7.wav", 27);
	LoadWave("se/lvstop.wav", 28);
	LoadWave("se/ttclear.wav", 29);
	LoadWave("se/gm.wav", 30);
	LoadWave("se/rankup.wav", 31);
	
	LoadWave("se/pinch.wav", 32);
	SetLoopModeWave(32,1);
	
	LoadWave("se/hanabi.wav", 33);
	LoadWave("se/movefail.wav", 34);
	LoadWave("se/rotfail.wav", 35);
	LoadWave("se/pause.wav", 36);
	LoadWave("se/stageclear.wav", 37);
	LoadWave("se/hurryup.wav", 38);
	LoadWave("se/timeover.wav", 39);
	LoadWave("se/platinaerase.wav", 40);
	LoadWave("se/timeextend.wav", 41);
	LoadWave("se/tspin.wav", 42);
	LoadWave("se/ace_sonic_lock.wav",43);
	LoadWave("se/regret.wav", 44);
	LoadWave("se/medal.wav", 45);
	LoadWave("se/stgstar.wav", 46);
	LoadWave("se/thunder.wav", 47);
	LoadWave("se/cool.wav", 48);
	LoadWave("se/warning.wav", 49);
	LoadWave("se/tserase.wav", 50);
	LoadWave("se/timestop.wav", 51);
}

// BGM��ǂݍ���
void loadBGM() {
	int i;
	
	for(i = 0; i <= 20; i++) {
		// �t�@�C���������߂�
		StrCpy(string[0], music_file_name[i]);
		
		// �g���q�����߂�
		if(bgm == 3) StrCat(string[0], ".mp3");
		else StrCat(string[0], ".wav");
		
		// �ǂݍ���
		LoadWave(string[0], 60 + i);
		
		// ���[�vON
		SetLoopModeWave(60 + i, 1);
	}
	
	// �G���f�B���O�Ȃ����[�v�����邩�͐ݒ�Ō��߂�
	SetLoopModeWave(66, sound_ending_loop);
	SetLoopModeWave(67, sound_beginner_ending_loop);
}

// �ݒ���e���o�b�N�A�b�v
void backupSetups() {
	setupBak[ 0] = smooth;
	setupBak[ 1] = nanameallow;
	setupBak[ 2] = sonicdrop;
	setupBak[ 3] = fastlrmove;
	setupBak[ 4] = w_reverse;
	setupBak[ 5] = r_irs;
	setupBak[ 6] = rots[0];
	setupBak[ 7] = rots[1];
	setupBak[ 8] = lvupbonus;
	setupBak[ 9] = spawn_y_type;
	setupBak[10] = w_lockdown;
	setupBak[11] = wsoftlock;
	setupBak[12] = rot180;
	setupBak[13] = tspin_type;
	setupBak[14] = enable_minspeed;
	setupBak[15] = disable_hold;
	setupBak[16] = bonus_tspin;
	setupBak[17] = bonus_btb;
	setupBak[18] = ace_irs;
	setupBak[19] = ending_timelimit;
	setupBak[20] = skip_blocklockflash;
	setupBak[21] = drs_floorkick;
	setupBak[22] = item_interval;
	setupBak[23] = devil_doom_n_rise;
}

// �ݒ���e��߂�
void restoreSetups() {
	smooth              = setupBak[ 0];
	nanameallow         = setupBak[ 1];
	sonicdrop           = setupBak[ 2];
	fastlrmove          = setupBak[ 3];
	w_reverse           = setupBak[ 4];
	r_irs               = setupBak[ 5];
	rots[0]             = setupBak[ 6];
	rots[1]             = setupBak[ 7];
	lvupbonus           = setupBak[ 8];
	spawn_y_type        = setupBak[ 9];
	w_lockdown          = setupBak[10];
	wsoftlock           = setupBak[11];
	rot180              = setupBak[12];
	tspin_type          = setupBak[13];
	enable_minspeed     = setupBak[14];
	disable_hold        = setupBak[15];
	bonus_tspin         = setupBak[16];
	bonus_btb           = setupBak[17];
	ace_irs             = setupBak[18];
	ending_timelimit    = setupBak[19];
	skip_blocklockflash = setupBak[20];
	drs_floorkick       = setupBak[21];
	item_interval       = setupBak[22];
	devil_doom_n_rise   = setupBak[23];
	
	config_load();				// �ݒ���ēǂݍ���
	setRuleSettingToDefault();	// CUSTOM�ȊO�̊e���[���̐ݒ���f�t�H���g�ɖ߂�
}

// �t�B�[���h�̕\���ʒu��ݒ�
void setFieldPosition(int players) {
	int i;
	
	// �t�B�[���h�̕\���ʒu��ݒ�
	if(players) {
		// DUAL
		for(i = 0; i <= maxPlay; i++) {
			foffset[i] = d_foffset[i];
			boffset[i] = d_boffset[i];
			soffset[i] = d_soffset[i];
			toffset[i] = d_toffset[i];
		}
		moffset = d_moffset;
		coffset = d_coffset;
	} else {
		// SINGLE
		foffset[0] = s_foffset;
		boffset[0] = s_boffset;
		soffset[0] = s_soffset;
		toffset[0] = s_toffset;
		moffset = s_moffset;
		coffset = s_coffset;
	}
}

// CUSTOM�ȊO�̊e���[���̐ݒ���f�t�H���g�ɖ߂�
void setRuleSettingToDefault() {
	int i;
	
	for(i = 0; i < 9; i++) {
		rule_rot[i]        = def_rule_rot[i];
		rule_hard_lock[i]  = def_rule_hard_lock[i];
		rule_soft_lock[i]  = def_rule_soft_lock[i];
		rule_soft_speed[i] = def_rule_soft_speed[i];
		rule_are[i]        = def_rule_are[i];
		rule_color[i]      = def_rule_color[i];
		rule_lock_reset[i] = def_rule_lock_reset[i];
		rule_lock_sound[i] = def_rule_lock_sound[i];
		rule_ars_extrot[i] = def_rule_ars_extrot[i];
		rule_lock_limit[i] = def_rule_lock_limit[i];
		rule_rot_limit[i]  = def_rule_rot_limit[i];
		rule_graphics[i]   = def_rule_graphics[i];
		rule_180rot[i]     = def_rule_180rot[i];
		rule_max_waitt[i]  = def_rule_max_waitt[i];
		rule_oblk_bg[i]    = def_rule_oblk_bg[i];
	}
}

//������������������������������������������������������������������������������
//   �u���b�N�̂����蔻��
//������������������������������������������������������������������������������
int judgeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		data[2];
	
	// BIG�̏ꍇ�͐�p����
	if(IsBig[player]) {
		return judgeBigBlock(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if((by2 < 2) && (heboGB[player] == 2)) {
			return -1;
		}
		
		if( (bx2 < 0) || (bx2 > 9) || (by2 > 21) ) {
			return -1;
		} else if( (fld[bx2 + by2 * 10 + player * 220] != 0) && (by2 >= 0) ) {
			return -1;
		}
	}

	return 0;
}

// BIG�p
int judgeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	int		data[2];
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4�u���b�N�����ׂ� */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if((by3 < 2) && (heboGB[player] == 2)) {
				return -1;
			}
			
			if( (bx3 < 0) || (bx3 > 9) || (by3 > 21) ) {
				return -1;
			} else if( (fld[bx3 + by3 * 10 + player * 220] != 0) && (by3 >= 0) ) {
				return -1;
			}
		}
	}

	return 0;
}

// ARS�n�ŕǏR��ł��邩����
int judgeBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	
	// BIG�̏ꍇ�͐�p����
	if(IsBig[player]) {
		return judgeBigBlockRotate(player, bx1, by1, kind, rotate);
	}
	
	for(i = 0 ; i < 4 ; i++) {
		// �����̗�ȊO���d�Ȃ��Ă���ꍇ�͕ǏR��\
		if( blkDataX[ kind * 16 + rotate * 4 + i ] != 1 ) {
			bx2 = ( bx1 + blkDataX[ kind * 16 + rotate * 4 + i ] );
			by2 = ( by1 + blkDataY[ kind * 16 + rotate * 4 + i ] );
			
			if( (bx2 < 0) || (bx2 > 9) || (by2 > 21) ) {
				return -1;
			} else if( (fld[bx2 + by2 * 10 + player * 220] != 0) && (by2 >= 0) ) {
				return -1;
			}
		}
	}
	
	return 0;
}

// ARS�n�ŕǏR��ł��邩����
// BIG�p
int judgeBigBlockRotate(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	
	for(i = 0 ; i < 4 ; i++) {
		// �����̗�ȊO���d�Ȃ��Ă���ꍇ�͕ǏR��\
		if( blkDataX[ kind * 16 + rotate * 4 + i ] != 1 ) {
			bx2 = (bx1 + blkDataX[ kind * 16 + rotate * 4 + i ] * 2);
			by2 = (by1 + blkDataY[ kind * 16 + rotate * 4 + i ] * 2);
			
			/* 4�u���b�N�����ׂ� */
			for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
				bx3 = bx2 + k;
				by3 = by2 + l;
				
				if( (bx3 < 0) || (bx3 > 9) || (by3 > 21) ) {
					return -1;
				} else if( (fld[bx3 + by3 * 10 + player * 220] != 0) && (by3 >= 0) ) {
					return -1;
				}
			}
		}
	}
	
	return 0;
}

//������������������������������������������������������������������������������
//   �u���b�N��ݒu����
//������������������������������������������������������������������������������
void setBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2, puted;
	int		data[2];
	
	// BIG�̏ꍇ�͐�p����
	if(IsBig[player]) {
		setBigBlock(player, bx1, by1, kind, rotate);
		return;
	}
	
	puted = 0;
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if((bx2 >= 0) && (bx2 <= 9) && (by2 >= (!spawn_y_type)) && (by2 < 22)) {
			if(by2 >= 2) puted++;
			
			fld[bx2 + by2 * 10 + player * 220] = c_cblk_r[player] + 1;
			
			if(hidden[player] == 1)
				fldt[bx2 + by2 * 10 + player * 220] = shadowtime[player];
			else if(hidden[player] == 2)
				fldt[bx2 + by2 * 10 + player * 220] = -60;
			else
				fldt[bx2 + by2 * 10 + player * 220] = -1;
			
			fldi[bx2 + by2 * 10 + player * 220] = item[player];
			fldo[bx2 + by2 * 10 + player * 220] = o_cblk[player];
			flds[bx2 + by2 * 10 + player * 220] = s_bdowncnt[player] + 1;
		}
	}
	
	// �u���b�N��1���u���Ȃ�������Q�[���I�[�o�[
	if((!puted) && (spawn_y_type)) setGameOver(player);
}

// BIG�p
void setBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2, puted;
	int		k, l, bx3, by3;
	int		data[2];
	
	puted = 0;
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4�u���b�N���ݒu���� */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if((bx3 >= 0) && (bx3 <= 9) && (by3 >= (!spawn_y_type)) && (by3 < 22)) {
				if(by2 >= 2) puted++;
				
				fld[bx3 + by3 * 10 + player * 220] = c_cblk_r[player] + 1;
				
				if(hidden[player] == 1)
					fldt[bx3 + by3 * 10 + player * 220] = shadowtime[player];
				else if(hidden[player] == 2)
					fldt[bx3 + by3 * 10 + player * 220] = -60;
				else
					fldt[bx3 + by3 * 10 + player * 220] = -1;
				
				fldi[bx3 + by3 * 10 + player * 220] = item[player];
				fldo[bx3 + by3 * 10 + player * 220] = o_cblk[player];
				flds[bx3 + by3 * 10 + player * 220] = s_bdowncnt[player] + 1;
			}
		}
	}
	
	// �u���b�N��1���u���Ȃ�������Q�[���I�[�o�[
	if((!puted) && (spawn_y_type)) setGameOver(player);
}

//������������������������������������������������������������������������������
//   �u���b�N����������
//������������������������������������������������������������������������������
void removeBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		data[2];
	
	// BIG�̏ꍇ�͐�p����
	if(IsBig[player]) {
		removeBigBlock(player, bx1, by1, kind, rotate);
		return;
	}
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, bx1, by1, kind, rotate, i, &data);
		bx2 = data[0];
		by2 = data[1];
		
		if( ( bx2 >= 0 ) && ( bx2 <= 9 ) && ( by2 >= 0 ) && ( by2 < 22 ) ) {
			fld[bx2 + by2 * 10 + player * 220] = 0;
			fldt[bx2 + by2 * 10 + player * 220] = 0;
		}
	}
}

// BIG�p
void removeBigBlock(int player, int bx1, int by1, int kind, int rotate) {
	int		i, bx2, by2;
	int		k, l, bx3, by3;
	int		data[2];
	
	for(i = 0 ; i < 4 ; i++) {
		getBlockData(player, 0, 0, kind, rotate, i, &data);
		bx2 = bx1 + (data[0] * 2);
		by2 = by1 + (data[1] * 2);
		
		/* 4�u���b�N������ */
		for(k = 0; k < 2; k++)for(l = 0; l < 2; l++) {
			bx3 = bx2 + k;
			by3 = by2 + l;
			
			if( ( bx3 >= 0 ) && ( bx3 <= 9 ) && ( by3 >= 0 ) && ( by3 < 22 ) ) {
				fld[bx3 + by3 * 10 + player * 220] = 0;
				fldt[bx3 + by3 * 10 + player * 220] = 0;
			}
		}
	}
}

// �u���b�N�̑��΂w���W���x���W���擾
void getBlockData(int player, int bx1, int by1, int kind, int rotate, int index, int *data) {
	// ARS
	if(rule_rot[rots[player]] == 0) {
		data[0] = bx1 +  blkDataX[kind * 16 + rotate * 4 + index];
		data[1] = by1 +  blkDataY[kind * 16 + rotate * 4 + index];
	}
	// SRS
	if(rule_rot[rots[player]] == 1) {
		data[0] = bx1 + blkWDataX[kind * 16 + rotate * 4 + index];
		data[1] = by1 + blkWDataY[kind * 16 + rotate * 4 + index];
	}
	// DRS
	if(rule_rot[rots[player]] == 2) {
		data[0] = bx1 + blkDDataX[kind * 16 + rotate * 4 + index];
		data[1] = by1 + blkDDataY[kind * 16 + rotate * 4 + index];
	}
}

// ����̍��W�ɂǂ�ȃu���b�N�����݂��邩���ׂ�
// �t�B�[���h�O��-1
// �t�B�[���h�����-2
int getFieldBlock(int player, int bx1, int by1) {
	if((bx1 < 0) || (bx1 > 9) || (by1 > 21)) return -1;
	if(by1 < 0) return -2;
	
	return fld[bx1 + by1 * 10 + player * 220];
}

// TOMOYO����オ��G�f�B�^�p
int getFieldBlockTomoyoRiseEditor(int player, int bx1, int by1) {
	if((bx1 < 0) || (bx1 > 9) || (by1 > 21)) return -1;
	if(by1 < 0) return -2;
	
	return tomoyo_rise_fld[bx1 + by1 * 10 + player * 200];
}

// �����`�p
int getFieldBlockS(int player, int bx1, int by1) {
	if((bx1 < 0) || (bx1 > 9) || (by1 < 0) || (by1 > 21)) return 0;
	
	return flds[bx1 + by1 * 10 + player * 220];
}

// �t�B�[���h�̍ŏ�i��Ԃ�
int checkFieldTop(int player) {
	int i, j;
	
	for(i = 0; i < 22; i++)
		for(j = 0; j < 10; j++) 
			if(fld[j + i * 10 + player * 220])
				return i;
	
	// ����ۂ̏ꍇ
	return 22;
}

// �t�B�[���h�̍ŏ�i��Ԃ��iX���W���w��ł���o�[�W�����j
int checkFieldTopEx(int player, int j) {
	int i;
	
	for(i = 0; i < 22; i++)
		if(fld[j + i * 10 + player * 220])
			return i;
	
	// ����ۂ̏ꍇ
	return 22;
}

//������������������������������������������������������������������������������
//  �[������
//������������������������������������������������������������������������������
// �V�[�h����
void GiziSRand(int player) {
	randseed[player] = Rand(65536);
	firstseed[player] = randseed[player];
}

// ��������
int GiziRand(int player, int max) {
	if(max == 0) return 0;
	randseed[player] = ((randseed[player] * 673 + 994) / 10) % 100000;
	return abs(randseed[player]) % max;
}

// ��Βl�����߂�iC++�łł͍폜�����j
int abs(int i) {
	if(i < 0) return -i;
	return i;
}

//������������������������������������������������������������������������������
//   �r�b�g���Z
//������������������������������������������������������������������������������
// �ϐ�value��bit�ڂ̃r�b�g�̏�Ԃ𒲂ׂ�
int BitTest(int value, int bit) {
	return (value) & (1 << (bit));
}

// �ϐ�value��bit�ڂ̃r�b�g�̏�Ԃ�ς���
int BitSet(int value, int bit, int status) {
	if(status) {
		value = (value) | (1 << (bit));
	} else {
		value = (value) & (~(1 << (bit)));
	}
	return value;
}

//������������������������������������������������������������������������������
//   value��0�Ȃ瓮���~
//������������������������������������������������������������������������������
void debug_assert(int value, str *errMsg) {
	int frame;
	
	if(value) return;
	
	frame = 0;
	
	while(loopFlag) {
		if(refresh_timing) spriteTime();
		KeyInput();
		
		printFont(1, 1, "ASSERTION FAILED", 2);
		printFont(1, 3, errMsg, 0);
		
		sprintf(string[0], "STAT 1P: %d", stat[0]);
		printFont(1, 5, string[0], 0);
		sprintf(string[0], "STAT 2P: %d", stat[1]);
		printFont(1, 6, string[0], 0);
		
		frame++;
		
		if(frame > 60) {
			printFont(1, 27, "A: CONTINUE", 3);
			printFont(1, 28, "B: QUIT", 3);
			
			if(getPushState(0, 4)) {
				return;
			}
			if(getPushState(0, 5)) {
				Quit();
			}
		}
		
		if(!refresh_timing) spriteTime();
	}
}

//������������������������������������������������������������������������������
//   halt;
//������������������������������������������������������������������������������
void spriteTime() {
	// FPS�����L�[
	if(IsPressKey(fps_plus_key) || getJoyPressState(0, joy_fps_plus_key[0]) || getJoyPressState(1, joy_fps_plus_key[1])) {
		fps_plus_mpc++;
		
		if((fps_plus_mpc == 1) || (fps_plus_mpc > tame1)) {
			if(GetFPS() < 99) SetFPS(GetFPS() + 1);
		}
	} else {
		fps_plus_mpc = 0;
	}
	
	// FPS�����L�[
	if(IsPressKey(fps_minus_key) || getJoyPressState(0, joy_fps_minus_key[0]) || getJoyPressState(1, joy_fps_minus_key[1])) {
		fps_minus_mpc++;
		
		if((fps_minus_mpc == 1) || (fps_minus_mpc > tame1)) {
			if(GetFPS() > 1) SetFPS(GetFPS() - 1);
		}
	} else {
		fps_minus_mpc = 0;
	}
	
	// FPS�̕\��
	if(show_fps == 1) {
		sprintf(string[0], "%3d/%2dFPS", GetRealFPS(), GetFPS());
		printFont(15, 29, string[0], digitc[rots[0]]);
	}
	if(show_fps == 2) {
		sprintf(string[0], "HEBORIS LITE - %02d/%02dFPS", GetRealFPS(), GetFPS());
		SetConstParam("Caption", string[0]);
	}
	
	// 2�{�E�C���h�E���[�h�̎��̏���
	/*
	if(screenMode >= 2) {
		SwapToSecondary(9);		// �Z�J���_���v���[�����A�_�~�[�Ńv���[��9�Ɠ���ւ���
		ExBltFastRectR(9, 0, 0, 0, 0, 320, 240, 65536 * 2, 65536 * 2);
		SwapToSecondary(9);
		ExBltFast(9, 0, 0);
	}
	*/
	
	// ESC�L�[�������ꂽ�瑦���I��
	if( IsPushEscKey() ) {
		if(!playback) {
			maxPlay = b_maxPlay;	// �v���C�l�����o�b�N�A�b�v����߂�
			config_save_rots();		// �Ō�Ɏg���Ă������[�����Z�[�u����
		}
		Quit();
	}
	
	// �`��
	halt;
	
	// ���ʉ��Đ�
	PlayAllSE();
	
	// �X�N���[���V���b�g
	if( IsPushKey(ss_key) || getJoyPushState(0, joy_ss_key[0]) || getJoyPushState(1, joy_ss_key[1]) ) {
		sprintf(string[0], "ss\\ss_%04d.bmp", ssc);
		
		SwapToSecondary(23);
		ExSaveBitmap(string[0], 23, 0, 0, 320, 240);
		SwapToSecondary(23);
		
		/*
		if(screenMode <= 1) {
			SwapToSecondary(23);
			SaveBitmap(string[0], 23, 0, 0, 320, 240);
			SwapToSecondary(23);
		} else {
			SaveBitmap(string[0], 9, 0, 0, 640, 480);
		}
		*/
		
		ssc++;
	}
	
	ClearSecondary();
}
