""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" coding tytle                                       "
""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" 1.set tap problem
set tabstop=4
set shiftwidth=4
set expandtab


" 2.language UTF8 problem
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
set nu


" 3.ignore case and search word
set ic
set hlsearch


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"  Add plugin vim BEGIN()
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()


" NERdtses
" Plugin 'scrooloose/nerdtree'
" Plugin 'SrcExpl'
" Plugin 'Xuyuanp/nerdtree-git-plugin'"

" bookmark
Plugin 'MattesGroeger/vim-bookmarks'
Plugin 'MultipleSearch' " hight light key word
"Plugin 'vasconcelloslf/vim-interestingwords' " hight light key word
Plugin 'airblade/vim-gitgutter'

" Airline
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'

" Check your systastic and compler error
Plugin 'scrooloose/syntastic'

" fuzzy ctrlP
Plugin 'ctrlpvim/ctrlp.vim'   " documwnt
Plugin 'tacahiroy/ctrlp-funky' " function


" Another GDB
" Plugin 'vim-scripts/Conque-GDB'

"install ntatb control windows
" Plugin 'Trinity'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required

"""""""""""""""""""""""""""END() """""""""""""""""""""""""""""""""""""""



""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"                       Plugin Setup
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"
" 1.ConqueGDB
"
"Let g:ConqueTerm_Color = 2         " 1: strip color after 200 lines, 2: always with color
"Let g:ConqueTerm_CloseOnEnd = 1    " close conque when program ends running
"Let g:ConqueTerm_StartMessages = 0 " display warning messages if conqueTerm is configured


"
" 2.taglist
"
"let Tlist_Ctags_Cmd='ctags'
"let Tlist_Show_One_File=1               "不同时显示多个文件的tag只显示当前文件的
"let Tlist_WinWidt =28                   "设置taglist的宽度
"let Tlist_Exit_OnlyWindow=1             "如果taglist窗口是最后一个窗口则退出vim
""let Tlist_Use_Right_Window=1           "在右侧窗口中显示taglist窗口
"let Tlist_Use_Top_Windo =1             "在左侧窗口中显示taglist窗口:
"
"let g:tagbar_ctags_bin='ctags'          "ctags程序的路径
"let g:tagbar_width=50                   "窗口宽度的设置

"
" 3.airline set
"
set laststatus=2
" 使用powerline打過補丁的字體
let g:airline_powerline_fonts = 1
" 開啟tabline
let g:airline#extensions#tabline#enabled = 1
" tabline中當前buffer兩端的分隔字符
 let g:airline#extensions#tabline#left_sep = ' '
" tabline中未激活buffer兩端的分隔字符
let g:airline#extensions#tabline#left_alt_sep = '|'
" tabline中buffer顯示編號
let g:airline#extensions#tabline#buffer_nr_show = 1
" 映射切換buffer的鍵位
nmap .. :bn<CR>
nmap ,, :bp<CR>
"nmap q : bd<CR>


"
" 4.scrooloose/syntastic
"
let g:syntastic_error_symbol='>>'
let g:syntastic_warning_symbol='>'
let g:syntastic_check_on_open=1
let g:syntastic_check_on_wq=0
let g:syntastic_enable_highlighting=1
let g:syntastic_python_checkers=['pyflakes'] " 使用pyflakes,速度比pylint快
let g:syntastic_javascript_checkers = ['jsl', 'jshint']
let g:syntastic_html_checkers=['tidy', 'jshint']
" 修改高亮的背景色, 适应主题
highlight SyntasticErrorSign guifg=white guibg=black

" to see error location list
let g:syntastic_always_populate_loc_list = 0
let g:syntastic_auto_loc_list = 0
let g:syntastic_loc_list_height = 5
function! ToggleErrors()
    let old_last_winnr = winnr('$')
    lclose
    if old_last_winnr == winnr('$')
        " Nothing was closed, open syntastic error location panel
        Errors
    endif
endfunction
nnoremap <Leader>s :call ToggleErrors()<cr>
" nnoremap <Leader>sn :lnext<cr>
" nnoremap <Leader>sp :lprevious<cr>



"
" 5.cscope setting
"
" [S] Find this C symbol
cs add $CSCOPE_DB
nmap cs :cs find s

" [G] Find this definition
nmap cg :cs find g

" [C] Find functions calling this function
nmap cc :cs find c

" [T] Find this text string
nmap ct :cs find t

" [E] Find this egreo pattern
nmap ce :cs find e

nmap cf :cs find f

" [I] Find files #including this file
nmap ci :cs find i ^=expand("")$

" [D] Find functions called by this function
nmap cd :cs find d



"
" 6.bookmark
"
highlight BookmarkSign ctermbg=NONE ctermfg=160
highlight BookmarkLine ctermbg=20 ctermfg=NONE
let g:bookmark_no_default_key_mappings = 1
function! BookmarkMapKeys()
    nmap mm :BookmarkToggle<CR>
    nmap mi :BookmarkAnnotate<CR>
    nmap mn :BookmarkNext<CR>
    nmap mp :BookmarkPrev<CR>
    nmap ma :BookmarkShowAll<CR>
    nmap mc :BookmarkClear<CR>
    nmap mx :BookmarkClearAll<CR>
    nmap mkk :BookmarkMoveUp
    nmap mjj :BookmarkMoveDown
endfunction
function! BookmarkUnmapKeys()
    unmap mm
    unmap mi
    unmap mn
    unmap mp
    unmap mc
    unmap ma
    unmap mx
    unmap mkk
    unmap mjj
endfunction
autocmd BufEnter * :call BookmarkMapKeys()
autocmd BufEnter NERD_tree_* :call BookmarkUnmapKeys()
let g:bookmark_manage_per_buffer = 1
let g:bookmark_save_per_working_dir = 1
let g:bookmark_auto_save = 1
let g:bookmark_highlight_lines = 1


"
" 7. fuzzy ctrl P
"
"   a.document and history document
" let g:ctrlp_map = '<leader>p'
let g:ctrlp_cmd = 'CtrlP'
map <leader>f :CtrlPMRU<CR>
let g:ctrlp_custom_ignore = {
    \ 'dir':  '\v[\/]\.(git|hg|svn|rvm)$',
    \ 'file': '\v\.(exe|so|dll|zip|tar|tar.gz|pyc)$',
    \ }
let g:ctrlp_working_path_mode=0
let g:ctrlp_match_window_bottom=1
let g:ctrlp_max_height=15
let g:ctrlp_match_window_reversed=0
let g:ctrlp_mruf_max=500
let g:ctrlp_follow_symlinks=1

"   b. function
map <F2> :CtrlPFunky<cr>
let g:ctrlp_extensions = ['funky']
let g:ctrlp_funky_syntax_highlight = 1

""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"  nmap other hot key                                    "
""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" remove remainder space
nmap rs :call setline(1,map(getline(1,"$"),'substitute(v:val,"\\s\\+$","","")'))<CR>
nmap nu :set nu<CR>
nmap nonu :set nonu<CR>


"
" 8.multiple Search
"

"" Thanks to Manuel Picaza for the following mapping to :Search the word under
"" the cursor.
"nnoremap <silent> <Leader>* :Search
"
"" Following Manuel's idea, adapt the former 'Super Star' tip from vim.org to work with
"" :Search on a visual selection.
"vnoremap <silent> <Leader>*:Search
"
"" Set the current search pattern to the next one in the list
"nnoremap <silent> <Leader>n:Search
"
"" Set the current search pattern to the previous one in the list
"nnoremap <silent> <Leader>N:Search
"vnoremap <silent> <Leader>* y:call Search(0,'\V'.substitute(escape(@@,"\\/\"'"),"\n",'\\n','ge'))<CR>
vnoremap <silent> <Leader>* y:execute ':Search \V<C-R>=substitute(escape(@@,"/\\"),"\n","\\\\n","ge")<CR>'<CR>



"let s:interestingWordsGUIColors = ['#aeee00', '#ff0000', '#0000ff', '#b88823', '#ffa724', '#ff2c4b']
"let s:interestingWordsTermColors = ['154', '121', '211', '137', '214', '222']

"  Specifes a maximum number of colors to use.
let g:MultipleSearchMaxColors = 8          " (Default: 8)

" (Default: "red,yellow,blue,green,magenta,cyan,gray,brown")
let g:MultipleSearchColorSequence =  "154,121,211,137,214,222,100,200"

" (Default: "white,black,white,black,white,black,black,white")
let g:MultipleSearchTextColorSequence = "black,black,black,black,black,black,black,black"



" paste
set paste

" auto completer () {} []
" 補齊括弧
" 語法
" inoremap  triger_char  mapping_str
" 映射指令     觸發字元     映射字串
"
" 註<LEFT> 為向右鍵字元

""inoremap ( ()<LEFT>
"""小括號補齊並將輸入游標左移一個字元
""
""inoremap [ []<LEFT>
"""中括號補齊並將輸入游標左移一個字元
""
""inoremap { {}<LEFT>
"""大括號補齊並將輸入游標左移一個字元
""
""inoremap ' ''<LEFT>
"""單引號補齊並將輸入游標左移一個字元
""
""inoremap " ""<LEFT>
"""雙引號補齊並將輸入游標左移一個字元




" 5.color display
syntax on
set t_Co=256       " Explicitly tell Vim that the terminal supports 256 colors


colorscheme slate
" colorscheme monokai

" High light unwanted spaces in end of line
highlight ExtraWhitespace ctermbg=darkred guibg=darkcyan
autocmd BufEnter * if &ft != 'help' | match ExtraWhitespace /\s\+$/ | endif
autocmd BufEnter * if &ft == 'help' | match none /\s\+$/ | endif

hi CursorLine   cterm=NONE ctermbg=237 ctermfg=NONE
hi CursorColumn   cterm=NONE ctermbg=242 ctermfg=NONE
set cursorcolumn
set cursorline


" define your region
highlight Foo ctermbg=16 guibg=#000000
syntax region Foo start=/^\s*#ifdef.*_DEBUG/ end=/^\s*#endif/

set nonu
