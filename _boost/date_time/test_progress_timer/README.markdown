# 补充说明

progress_timer时间精度默认是2 在progress_timer中有定义

如果需要更加高的精度的话，则需要重写progress_timer，其中使用到的static_assert 需要保证精度N的范围在3-10

当前在windows上大于3以上已不存在实际意义。


以下是定义代码：
class progress_timer : public timer, private noncopyable
{
  
 public:
  explicit progress_timer( std::ostream & os = std::cout )
     // os is hint; implementation may ignore, particularly in embedded systems
     : timer(), noncopyable(), m_os(os) {}
  ~progress_timer()
  {
  //  A) Throwing an exception from a destructor is a Bad Thing.
  //  B) The progress_timer destructor does output which may throw.
  //  C) A progress_timer is usually not critical to the application.
  //  Therefore, wrap the I/O in a try block, catch and ignore all exceptions.
    try
    {
      // use istream instead of ios_base to workaround GNU problem (Greg Chicares)
      std::istream::fmtflags old_flags = m_os.setf( std::istream::fixed,
                                                   std::istream::floatfield );
      # std::streamsize old_prec = m_os.precision( 2 );
      m_os << elapsed() << " s\n" // "s" is System International d'Unites std
                        << std::endl;
      m_os.flags( old_flags );
      m_os.precision( old_prec );
    }

    catch (...) {} // eat any exceptions
  } // ~progress_timer

 private:
  std::ostream & m_os;
};
