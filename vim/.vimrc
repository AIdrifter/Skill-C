set nocompatible              " be iMproved, required
filetype off                  " required
set nu

" Default encoding
set fileencodings=utf-8,big5,gbk,latin1


set tabstop=4
set shiftwidth=4
set expandtab


if has('gui_running')
       colorscheme github
       " colorscheme slate
    else
       " colorscheme github
        " colorscheme grb256
         colorscheme desert
        " colorscheme koehler:
        "  colorscheme slate
endif
set cursorline

"set cursorcolumn
"set cursorline cursorcolumn
" set the runtime path to include Vundle and initialize
 set rtp+=~/.vim/bundle/Vundle.vim
 call vundle#begin()

 Plugin 'zenorocha/dracula-theme', {'rtp': 'vim/'}

"NerdTree
 Plugin 'scrooloose/nerdtree'
 let g:NERDTreeWinPos = "right"

 Plugin 'Xuyuanp/nerdtree-git-plugin'
 Plugin 'bling/vim-airline'

 "taglist
 Plugin 'taglist.vim'

"YouCompleteme
Plugin 'Valloric/YouCompleteMe'
let g:ycm_global_ycm_extra_conf = '~/.ycm_extra_conf.py'

Plugin'SirVer/ultisnips'
" 代码片段资源,需要学习
" Snppets are separated from the engine. Add this if you want them:
Plugin'honza/vim-snippets'
" 定义存放代码片段的文件夹
".vim/additional_snippets下，使用自定义和默认的，将会的到全局，有冲突的会提示
"let g:UltiSnipsSnippetDirectories=["additional_snippets", 'UltiSnips']
"set completeopt=menu,menuone

autocmd FileType * call UltiSnips#FileTypeChanged()
" 連續按下兩次i觸發代碼補全
imap <F3> <C-X><C-O>
"set shortmess=a
aunmenu Help.
aunmenu Window.
let no_buffers_menu=1



" All of your Plugins must be added before the following line
 call vundle#end()            " required
 filetype plugin indent on    " required

 syntax on
 set laststatus=2
 set t_Co=256       " Explicitly tell Vim that the terminal supports 256 colors

" airline設置
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


" highjt line
highlight TempKeyword1 cterm=underline,bold ctermbg=Blue ctermfg=White
highlight TempKeyword2 cterm=underline,bold ctermbg=Green ctermfg=White
highlight TempKeyword3 cterm=underline,bold ctermbg=Cyan ctermfg=White
highlight TempKeyword4 cterm=underline,bold ctermbg=Red ctermfg=White
highlight TempKeyword5 cterm=underline,bold ctermbg=Yellow ctermfg=White
highlight TempKeyword6 cterm=underline,bold ctermbg=White ctermfg=DarkYellow
highlight TempKeyword7 cterm=underline,bold ctermbg=White ctermfg=DarkRed
highlight TempKeyword8 cterm=underline,bold ctermbg=White ctermfg=DarkGreen
highlight TempKeyword9 cterm=underline,bold ctermbg=White ctermfg=DarkBlue
highlight TempKeyword0 cterm=underline,bold ctermbg=White ctermfg=DarkMagenta
nmap <leader>1 :call AddTempKeywords(1, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>2 :call AddTempKeywords(2, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>3 :call AddTempKeywords(3, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>4 :call AddTempKeywords(4, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>5 :call AddTempKeywords(5, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>6 :call AddTempKeywords(6, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>7 :call AddTempKeywords(7, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>8 :call AddTempKeywords(8, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>9 :call AddTempKeywords(9, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>0 :call AddTempKeywords(0, "<C-R>=expand("<cword>")<CR>")<CR>
nmap <leader>ca :call clearmatches()<CR>
nmap <leader>c1 :call DeleteTempKeywords(1)<CR>
nmap <leader>c2 :call DeleteTempKeywords(2)<CR>
nmap <leader>c3 :call DeleteTempKeywords(3)<CR>
nmap <leader>c4 :call DeleteTempKeywords(4)<CR>
nmap <leader>c5 :call DeleteTempKeywords(5)<CR>
nmap <leader>c6 :call DeleteTempKeywords(6)<CR>
nmap <leader>c7 :call DeleteTempKeywords(7)<CR>
nmap <leader>c8 :call DeleteTempKeywords(8)<CR>
nmap <leader>c9 :call DeleteTempKeywords(9)<CR>
nmap <leader>c0 :call DeleteTempKeywords(0)<CR>
function! AddTempKeywords(index, pattern)
    let list_name='g:TempKeywordList' . a:index
    let group_name='TempKeyword' . a:index
    if !exists(list_name)
        let {list_name}=[]
    endif
    let {list_name}=add({list_name}, matchadd(group_name, a:pattern))
    return len({list_name})
endfunction
function! DeleteTempKeywords(index)
    let list_name='g:TempKeywordList' . a:index
    if !exists(list_name)
        return -1
    endif
    for id in {list_name}
        if id != ''
            :call matchdelete(id)
        endif
    endfor
    let {list_name}=[]
    return 0
endfunction





nnoremap <TAB> :bn<CR>
nnoremap <C-TAB> :bn<CR>
nnoremap <silent> <F5> :NERDTree<CR>
nnoremap <silent> <F2> :TlistToggle<CR>

" High light unwanted spaces in end of line
highlight ExtraWhitespace ctermbg=darkred guibg=darkcyan
autocmd BufEnter * if &ft != 'help' | match ExtraWhitespace /\s\+$/ | endif
autocmd BufEnter * if &ft == 'help' | match none /\s\+$/ | endif
"i CursorLine term=bold cterm=bold guibg=Grey
"i CursorLine   cterm=NONE ctermbg=17 ctermfg=NONE
"hi CursorLine   cterm=NONE ctermbg=234 ctermfg=NONE
hi CursorLine   cterm=NONE ctermbg=17 ctermfg=NONE
map <C-K> viwy:!ydict <C-R>"<CR>


"set listchars=eol:↵,tab:»·,trail:╳,extends:»,precedes:«
"set list
