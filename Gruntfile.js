module.exports = function(grunt) {

  grunt.initConfig({
    markdownpdf: {
      options: {
        cssPath: 'tools/pdf.css',
        highlightCssPath: 'tools/highlight.css',
        paperFormat: 'A4',
        paperOrientation: 'portrait',
        paperBorder: '2cm'
      },
      files: {
        src: "./MDs/**/*.md",
        dest: "pdf"
      }
    }
  });

  grunt.loadNpmTasks('grunt-markdown-pdf');

  grunt.registerTask('default', ['markdownpdf']);
};
