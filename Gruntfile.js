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
    },
    watch: {
      scripts: {
        files: ["./MDs/**/*.md"],
      },
    },
  });

  // Watch event
  grunt.event.on('watch', function(action, filepath, target) {
    grunt.log.writeln(target + ': ' + filepath + ' has ' + action);
  });

  grunt.loadNpmTasks('grunt-markdown-pdf');
  grunt.loadNpmTasks('grunt-contrib-watch');

  grunt.registerTask('default', ['markdownpdf', 'watch']);
};
