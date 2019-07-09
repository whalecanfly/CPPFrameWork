# 补充说明

progress_timer时间精度默认是2 在progress_timer中有定义

如果需要更加高的精度的话，则需要重写progress_timer，其中使用到的static_assert 需要保证精度N的范围在3-10

当前在windows上大于3以上已不存在实际意义。
